#include <math.h>
#include "libsat.h"

#define LEFT_VORONOI_REGION -1
#define MIDDLE_VORONOI_REGION 0
#define RIGHT_VORONOI_REGION 1

namespace SAT {
    static Response T_RESPONSE;
    static Polygon UNIT_SQUARE = Box(Vector(), 1, 1).toPolygon();

    Response::Response() {
        a = NULL;
        b = NULL;
        clear();
    }

    void Response::clear() {
        aInB = true;
        bInA = true;
        overlap = 2e10;
    }

    static void flattenPointsOn(std::vector<Vector> points, Vector normal, float& min, float& max) {
        min = 2e10;
        max = -2e10;
        int len = points.size();
        for (int i = 0; i < len; i++ ) {
          // The magnitude of the projection of the point onto the normal
          float dot = points[i].dot(normal);
          if (dot < min) { min = dot; }
          if (dot > max) { max = dot; }
        }
    }

    static bool isSeparatingAxis(Vector aPos, Vector bPos, std::vector<Vector>& aPoints, std::vector<Vector>& bPoints, Vector axis, Response& response) {
        float minA, minB, maxA, maxB;
        // The magnitude of the offset between the two polygons
        Vector offsetV = bPos - aPos;
        float projectedOffset = offsetV.dot(axis);
        // Project the polygons onto the axis.
        flattenPointsOn(aPoints, axis, minA, maxA);
        flattenPointsOn(bPoints, axis, minB, maxB);
        // Move B's range to its position relative to A.
        minB += projectedOffset;
        maxB += projectedOffset;
        // Check if there is a gap. If there is, this is a separating axis and we can stop
        if (minA > maxB || minB > maxA) {
            return true;
        }
        // This is not a separating axis. If we're calculating a response, calculate the overlap.

        float overlap = 0;
        // A starts further left than B
        if (minA < minB) {
            response.aInB = false;
            // A ends before B does. We have to pull A out of B
            if (maxA < maxB) {
                overlap = maxA - minB;
                response.bInA = false;
                // B is fully inside A.  Pick the shortest way out.
            } else {
                float option1 = maxA - minB;
                float option2 = maxB - minA;
                overlap = option1 < option2 ? option1 : -option2;
            }
        // B starts further left than A
        } else {
            response.bInA = false;
            // B ends before A ends. We have to push A out of B
            if (maxA > maxB) {
                overlap = minA - maxB;
                response.aInB = false;
                // A is fully inside B.  Pick the shortest way out.
            } else {
                float option1 = maxA - minB;
                float option2 = maxB - minA;
                overlap = option1 < option2 ? option1 : -option2;
            }
        }
        // If this is the smallest amount of overlap we've seen so far, set it as the minimum overlap.
        float absOverlap = fabs(overlap);
        if (absOverlap < response.overlap) {
            response.overlap = absOverlap;
            response.overlapN = axis;
            if (overlap < 0) {
                response.overlapN.reverse();
            }
        }

        return false;
    }

    static int voronoiRegion(Vector line, Vector point) {
        float len2 = line.length2();
        float dp = point.dot(line);
        // If the point is beyond the start of the line, it is in the
        // left voronoi region.
        if (dp < 0) { return LEFT_VORONOI_REGION; }
        // If the point is beyond the end of the line, it is in the
        // right voronoi region.
        else if (dp > len2) { return RIGHT_VORONOI_REGION; }
        // Otherwise, it's in the middle one.
        else { return MIDDLE_VORONOI_REGION; }
    }

    bool pointInCircle(Vector& p, Circle& c) {
        Vector differenceV = p - c.pos;
        float radiusSq = c.r * c.r;
        float distanceSq = differenceV.length2();
        // If the distance between is smaller than the radius then the point is inside the circle.
        return distanceSq <= radiusSq;
    }

    bool pointInPolygon(Vector& p, Polygon& poly) {
        UNIT_SQUARE.pos = p;
        T_RESPONSE.clear();
        bool result = testPolygonPolygon(UNIT_SQUARE, poly, T_RESPONSE);
        if (result) {
            result = T_RESPONSE.aInB;
        }
        return result;
    }

    bool testCircleCircle(Circle& a, Circle& b, Response& response) {
        // Check if the distance between the centers of the two
        // circles is greater than their combined radius.
        Vector differenceV = b.pos - a.pos;
        float totalRadius = a.r + b.r;
        float totalRadiusSq = totalRadius * totalRadius;
        float distanceSq = differenceV.length2();
        // If the distance is bigger than the combined radius, they don't intersect.
        if (distanceSq > totalRadiusSq) {
            return false;
        }
        // They intersect.  If we're calculating a response, calculate the overlap.
        float dist = sqrt(distanceSq);
        response.a = &a;
        response.b = &b;
        response.overlap = totalRadius - dist;
        differenceV.normalize();
        response.overlapN = differenceV;
        response.overlapV = differenceV * response.overlap;
        response.aInB = a.r <= b.r && dist <= b.r - a.r;
        response.bInA = b.r <= a.r && dist <= a.r - b.r;

        return true;
    }

    bool testPolygonCircle(Polygon& polygon, Circle& circle, Response& response) {
        // Get the position of the circle relative to the polygon.
        Vector circlePos = circle.pos - polygon.pos;
        float radius = circle.r;
        float radius2 = radius * radius;
        std::vector<Vector>& points = polygon.calcPoints;
        float len = points.size();
        Vector edge;
        Vector point;

        // For each edge in the polygon:
        for (int i = 0; i < len; i++) {
            int next = i == len - 1 ? 0 : i + 1;
            int prev = i == 0 ? len - 1 : i - 1;
            float overlap = 0;
            Vector overlapN;
            bool wrongRegion = true;

            // Get the edge.
            edge = polygon.edges[i];
            // Calculate the center of the circle relative to the starting point of the edge.
            point = circlePos - points[i];

            // If the distance between the center of the circle and the point
            // is bigger than the radius, the polygon is definitely not fully in
            // the circle.
            if (point.length2() > radius2) {
                response.aInB = false;
            }

            // Calculate which Voronoi region the center of the circle is in.
            int region = voronoiRegion(edge, point);
            // If it's the left region:
            if (region == LEFT_VORONOI_REGION) {
                // We need to make sure we're in the RIGHT_VORONOI_REGION of the previous edge.
                edge = polygon.edges[prev];
                // Calculate the center of the circle relative the starting point of the previous edge
                Vector point2 = circlePos - points[prev];
                region = voronoiRegion(edge, point2);
                if (region == RIGHT_VORONOI_REGION) {
                    // It's in the region we want.  Check if the circle intersects the point.
                    float dist = point.length();
                    if (dist > radius) {
                        // No intersection
                        return false;
                    } else {
                        // It intersects, calculate the overlap.
                        response.bInA = false;
                        point.normalize();
                        overlapN = point;
                        wrongRegion = false;
                        overlap = radius - dist;
                    }
                }
                // If it's the right region:
            } else if (region == RIGHT_VORONOI_REGION) {
                // We need to make sure we're in the left region on the next edge
                edge = polygon.edges[next];
                // Calculate the center of the circle relative to the starting point of the next edge.
                point = circlePos - points[next];
                region = voronoiRegion(edge, point);
                if (region == LEFT_VORONOI_REGION) {
                    // It's in the region we want.  Check if the circle intersects the point.
                    float dist = point.length();
                    if (dist > radius) {
                        // No intersection
                        return false;
                    } else {
                        // It intersects, calculate the overlap.
                        response.bInA = false;
                        point.normalize();
                        overlapN = point;
                        wrongRegion = false;
                        overlap = radius - dist;
                    }
                }
                // Otherwise, it's the middle region:
            } else {
                // Need to check if the circle is intersecting the edge,
                // Change the edge into its "edge normal".
                edge.perp();
                edge.normalize();
                Vector normal = edge;
                // Find the perpendicular distance between the center of the
                // circle and the edge.
                float dist = point.dot(normal);
                float distAbs = fabs(dist);
                // If the circle is on the outside of the edge, there is no intersection.
                if (dist > 0 && distAbs > radius) {
                    // No intersection
                    return false;
                } else {
                    // It intersects, calculate the overlap.
                    overlapN = normal;
                    wrongRegion = false;
                    overlap = radius - dist;
                    // If the center of the circle is on the outside of the edge, or part of the
                    // circle is on the outside, the circle is not fully inside the polygon.
                    if (dist >= 0 || overlap < 2 * radius) {
                        response.bInA = false;
                    }
                }
            }

            // If this is the smallest overlap we've seen, keep it.
            // (wrongRegion is true if the circle was in the wrong Voronoi region).
            if (!wrongRegion && fabs(overlap) < fabs(response.overlap)) {
                response.overlap = overlap;
                response.overlapN = overlapN;
            }
        }

        // Calculate the final overlap vector - based on the smallest overlap.
        response.a = &polygon;
        response.b = &circle;
        response.overlapV = response.overlapN * response.overlap;

        return true;
    }

    bool testCirclePolygon(Circle& circle, Polygon& polygon, Response& response) {
        // Test the polygon against the circle.
        bool result = SAT::testPolygonCircle(polygon, circle, response);
        if (result) {
            // Swap A and B in the response.
            Shape* a = response.a;
            bool aInB = response.aInB;
            response.overlapN.reverse();
            response.overlapV.reverse();
            response.a = response.b;
            response.b = a;
            response.aInB = response.bInA;
            response.bInA = aInB;
        }
        return result;
    }

    bool testPolygonPolygon(Polygon& a, Polygon& b, Response& response) {
        std::vector<Vector>& aPoints = a.calcPoints;
        int aLen = aPoints.size();
        std::vector<Vector>& bPoints = b.calcPoints;
        int bLen = bPoints.size();
        // If any of the edge normals of A is a separating axis, no intersection.
        for (int i = 0; i < aLen; i++) {
            if (isSeparatingAxis(a.pos, b.pos, aPoints, bPoints, a.normals[i], response)) {
                return false;
            }
        }
        // If any of the edge normals of B is a separating axis, no intersection.
        for (int i = 0;i < bLen; i++) {
            if (isSeparatingAxis(a.pos, b.pos, aPoints, bPoints, b.normals[i], response)) {
                return false;
            }
        }
        // Since none of the edge normals of A or B are a separating axis, there is an intersection
        // and we've already calculated the smallest overlap (in isSeparatingAxis).  Calculate the
        // final overlap vector.
        response.a = &a;
        response.b = &b;
        response.overlapV = response.overlapN * response.overlap;
        return true;
    }
}

#include "satpolygon.h"
#include "satbox.h"

namespace SAT {
    void Polygon::setPoints(std::vector<Vector>& fPoints) {
        if (fPoints.size() != points.size()) {
            for (int i = 0; i < fPoints.size(); i++) {
                calcPoints.push_back(Vector());
                edges.push_back(Vector());
                normals.push_back(Vector());
            }
        }
        points = fPoints;
        recalc();
    }

    void Polygon::setAngle(float fAngle) {
        angle = fAngle;
        recalc();
    }

    void Polygon::setOffset(Vector fOffset) {
        offset = fOffset;
        recalc();
    }

    void Polygon::rotate(float fAngle) {
        for (int i = 0; i < points.size(); i++) {
            points[i].rotate(fAngle);
        }
        recalc();
    }

    void Polygon::translate(float x, float y) {
        for (int i = 0; i < points.size(); i++) {
            points[i].x += x;
            points[i].y += y;
        }
        recalc();
    }

    Polygon Polygon::getAABB() {
        float xMin = calcPoints[0].x;
        float yMin = calcPoints[0].y;
        float xMax = calcPoints[0].x;
        float yMax = calcPoints[0].y;
        for (int i = 1; i < calcPoints.size(); i++) {
            Vector point = calcPoints[i];
            if (point.x < xMin) {
                xMin = point.x;
            }
            else if (point.x > xMax) {
                xMax = point.x;
            }
            if (point.y < yMin) {
                yMin = point.y;
            }
            else if (point.y > yMax) {
                yMax = point.y;
            }
        }
        Box box(pos + Vector(xMin, yMin), xMax - xMin, yMax - yMin);
        return box.toPolygon();
    }

    void Polygon::recalc() {
        int len = points.size();
        for (int i = 0; i < len; i++) {
            calcPoints[i] = points[i];
            Vector calcPoint = calcPoints[i];
            calcPoint.x += offset.x;
            calcPoint.y += offset.y;
            if (angle != 0) {
                calcPoint.rotate(angle);
            }
        }
        // Calculate the edges/normals
        for (int i = 0; i < len; i++) {
            Vector p1 = calcPoints[i];
            Vector p2 = i < len - 1 ? calcPoints[i + 1] : calcPoints[0];
            edges[i] = p2;
            edges[i] -= p1;
            Vector e = edges[i];
            normals[i] = e;
            normals[i].perp();
            normals[i].normalize();
        }
    }
}

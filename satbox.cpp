#include "satbox.h"

namespace SAT {
    Polygon Box::toPolygon() {
        std::vector<Vector> points;
        points.push_back(Vector(0, 0));
        points.push_back(Vector(w, 0));
        points.push_back(Vector(w, h));
        points.push_back(Vector(0, h));
        Polygon poly(pos, points);
        return poly;
    }
}

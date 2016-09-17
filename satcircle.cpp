#include "satcircle.h"
#include "satbox.h"

namespace SAT {
    Polygon Circle::getAABB() {
        Vector corner = pos - Vector(r, r);
        return Box(corner, r*2, r*2).toPolygon();
    }
}

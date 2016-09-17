#ifndef _SATCIRCLE_
#define _SATCIRCLE_

#include "satvector.h"
#include "satpolygon.h"
#include "satshape.h"

namespace SAT {

    class Circle : public Shape {
    public :
        Circle(Vector v, float radius) : Shape(v), r(radius) {
        }
        Polygon getAABB();

        float r;
    };

}

#endif

#ifndef _SATBOX_
#define _SATBOX_

#include "satvector.h"
#include "satpolygon.h"
#include "satshape.h"

namespace SAT {

    class Box : public Shape {
    public :
        Box(Vector fPos, float fW, float fH) : Shape(fPos), w(fW), h(fH) {}
        Polygon toPolygon();

        float w;
        float h;
    };

}

#endif

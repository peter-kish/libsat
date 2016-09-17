#ifndef _SATSHAPE_
#define _SATSHAPE_

#include "satvector.h"

namespace SAT {

    class Shape {
    public :
        Shape(Vector fPos) : pos(fPos){}

        Vector pos;
    };

}

#endif

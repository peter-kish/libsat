#include <cstddef>
#include "satvector.h"
#include "satcircle.h"
#include "satpolygon.h"
#include "satbox.h"
#include "satshape.h"

namespace SAT {

    class Response {
    public :
        Response();
        void clear();

        Shape* a;
        Shape* b;
        Vector overlapN;
        Vector overlapV;
        bool aInB;
        bool bInA;
        float overlap;
    };

    bool pointInCircle(Vector& p, Circle& c);
    bool pointInPolygon(Vector& p, Polygon& poly);
    bool testCircleCircle(Circle& a, Circle& b, Response& response);
    bool testPolygonCircle(Polygon& polygon, Circle& circle, Response& response);
    bool testCirclePolygon(Circle& circle, Polygon& polygon, Response& response);
    bool testPolygonPolygon(Polygon& a, Polygon& b, Response& response);
}

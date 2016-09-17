#ifndef _SATPOLYGON_
#define _SATPOLYGON_

#include <vector>
#include "satvector.h"
#include "satshape.h"

namespace SAT {

    class Polygon : public Shape {
    public :
        Polygon(Vector fPos, std::vector<Vector>& fPoints) : Shape(fPos), angle(0) {
            setPoints(fPoints);
        }
        void setPoints(std::vector<Vector>& fPoints);
        void setAngle(float fAngle);
        void setOffset(Vector fOffset);
        void rotate(float fAngle);
        void translate(float x, float y);
        Polygon getAABB();

        Vector offset;
        std::vector<Vector> points;
        float angle;
        std::vector<Vector> calcPoints;
        std::vector<Vector> edges;
        std::vector<Vector> normals;
    private:
        void recalc();
    };

}

#endif

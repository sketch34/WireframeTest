//
//  IndexedPlane.h
//  WireframeTest
//
//  Created by Jarrod Smith on 25/09/13.
//
//

#ifndef __WireframeTest__IndexedPlane__
#define __WireframeTest__IndexedPlane__

#include <iostream>
#include "ofMain.h"

class IndexedPlane {

public:
                IndexedPlane(int width, int height);
                ~IndexedPlane();

private:
    void        makeIndexedPlane(int width, int height, ofVec3f* vertices, uint16* indices);

public:
    ofVec3f*        m_planeVertices;
    uint16_t*       m_planeIndices;
    int             m_indexCount;
    int             m_vertexCount;
    int             m_indexSize;
    int             m_vertexSize;
};

#endif /* defined(__WireframeTest__IndexedPlane__) */

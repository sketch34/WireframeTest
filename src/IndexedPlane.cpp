//
//  IndexHelper.cpp
//  WireframeTest
//
//  Created by Jarrod Smith on 25/09/13.
//
//

#include "IndexedPlane.h"

IndexedPlane::IndexedPlane(int width, int height)
{
    int plane_width = width;    // amount of columns
    int plane_height = height;  // amount of rows
    
    m_vertexCount = (plane_width + 1) * (plane_height + 1);
    m_planeVertices = new ofVec3f[m_vertexCount];
    m_vertexSize = sizeof(ofVec3f);
    memset(m_planeVertices, 0, m_vertexSize * m_vertexCount);
    
    int numIndPerRow = plane_width * 2 + 2;
    int numIndDegensReq = (plane_height - 1) * 2;
    m_indexCount = numIndPerRow * plane_height + numIndDegensReq;
    
    m_planeIndices = new uint16[m_indexCount];
    m_indexSize = sizeof(uint16);
    
    makeIndexedPlane(plane_width, plane_height, m_planeVertices, m_planeIndices);
}

IndexedPlane::~IndexedPlane()
{
    delete m_planeVertices;
    delete m_planeIndices;
}

void IndexedPlane::makeIndexedPlane(int width, int height, ofVec3f* vertices, uint16* indices)
{
    width++;
    height++;
    
    int size = sizeof(ofVec3f);
    // Set up vertices
    for(int y = 0; y < height; y++)
    {
        int base = y * width;
        for(int x = 0; x < width; x++)
        {
            int index = base + x;
            ofVec3f *v = vertices + index;
            v->x = (float) x;
            v->y = (float) y;
            v->z = 0.f;
            printf("%d: %f, %f, %f\n", index, v->x, v->y, v->z);
        }
    }
    
    printf("-------------------------\n");
    
    // Set up indices
    int i = 0;
    height--;
    for(int y = 0; y < height; y++)
    {
        int base = y * width;
        
        //indices[i++] = (uint16)base;
        for(int x = 0; x < width; x++)
        {
            indices[i++] = (uint16)(base + x);
            indices[i++] = (uint16)(base + width + x);
        }
        // add a degenerate triangle (except in a last row)
        if(y < height - 1)
        {
            indices[i++] = (uint16)((y + 1) * width + (width - 1));
            indices[i++] = (uint16)((y + 1) * width);
        }
    }
    
    for(int ind=0; ind < i; ind++)
        printf("%d ", indices[ind]);
}

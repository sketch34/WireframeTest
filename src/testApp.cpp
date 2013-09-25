#include "testApp.h"

GLuint m_vboId;
GLuint m_indicesId;

//--------------------------------------------------------------
void testApp::setup(){
    m_plane = new IndexedPlane(80, 40);

    // Vertices.
    glGenBuffers(1, &m_vboId);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, m_plane->m_vertexCount * m_plane->m_vertexSize, m_plane->m_planeVertices, GL_DYNAMIC_DRAW);
    
    // Indices.
    glGenBuffers(1, &m_indicesId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_plane->m_indexCount * m_plane->m_indexSize, m_plane->m_planeIndices, GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void testApp::exit() {
    delete m_plane;
}

//--------------------------------------------------------------
void testApp::update(){
    float t = ofGetElapsedTimef();
    static float s_fRate = 5.f;
    static float s_fAmplitude = 2.f;
    static float s_fFrequency = .4f;
    for(int i = 0; i < m_plane->m_vertexCount; ++i)
    {
        ofVec3f* v = &m_plane->m_planeVertices[i];
        v->z = sin((t * s_fRate + v->x * v->y) * s_fFrequency) * s_fAmplitude;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0.2);
    glPushMatrix();
    glScalef(10.f, 10.f, 10.f);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, m_plane->m_vertexCount * m_plane->m_vertexSize, m_plane->m_planeVertices, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesId);
    glVertexPointer(3, GL_FLOAT, 0, (GLvoid*)0);
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glDrawElements(
                   GL_TRIANGLE_STRIP,      // mode
                   m_plane->m_indexCount,  // count
                   GL_UNSIGNED_SHORT,      // type
                   (void*)0                // element array buffer offset
                   );
    glPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

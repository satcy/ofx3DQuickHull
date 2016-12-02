//
//  ofx3DQuickHull.cpp
//  ofx3DQuickHull
//
//  Created by satcy on 2016/12/01.
//
//


#include "ofx3DQuickHull.h"

#define QUICKHULL_IMPLEMENTATION
#include "quickhull.h"
namespace ofx3DQuickHull {
    ofMesh quickhull3d(vector<ofVec3f> & _vertices) {
        unsigned int num = _vertices.size();
        qh_vertex_t * vertices = QH_MALLOC(qh_vertex_t, num);
        for ( int i=0; i<num; i++ ) {
            vertices[i].x = _vertices[i].x;
            vertices[i].y = _vertices[i].y;
            vertices[i].z = _vertices[i].z;
        }
        qh_mesh_t m = qh_quickhull3d(vertices, num);
        
        ofMesh mesh;
        for (int i = 0, j = 0; i < m.nindices; i += 3, j++) {
            if ( m.indices[i+0] < m.nvertices && m.indices[i+1] < m.nvertices && m.indices[i+2] < m.nvertices &&  m.normalindices[j] < m.nnormals ) {
                qh_vertex_t * v0 = m.vertices + m.indices[i+0];
                qh_vertex_t * v1 = m.vertices + m.indices[i+1];
                qh_vertex_t * v2 = m.vertices + m.indices[i+2];
                
                qh_vec3_t * n = m.normals + m.normalindices[j];
                
                mesh.addVertex(ofVec3f(v0->x, v0->y, v0->z));
                mesh.addVertex(ofVec3f(v1->x, v1->y, v1->z));
                mesh.addVertex(ofVec3f(v2->x, v2->y, v2->z));
                mesh.addNormal(ofVec3f(n->x, n->y, n->z));
                mesh.addNormal(ofVec3f(n->x, n->y, n->z));
                mesh.addNormal(ofVec3f(n->x, n->y, n->z));
            }
        }
        
        qh_free_mesh(m);
        QH_FREE(m.normals);
        QH_FREE(vertices);
        return mesh;
    }
}

#include "ofApp.h"

#include "ofx3DQuickHull.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    static int MAX_NUM = 2000;
    int num = ofGetFrameNum()%MAX_NUM;
    if ( num < 4 ) num = 4;
    vector<ofVec3f> verts(num);
    int i=0;
    float radius = 200;
    float noise = int(ofGetFrameNum()/MAX_NUM);
    origin.clear();
    for ( auto & pt : verts ) {
        pt.x = ofSignedNoise(i*0.57, 1, noise) * radius;
        pt.y = ofSignedNoise(i*0.43, 1.5, noise) * radius;
        pt.z = ofSignedNoise(i*0.35, 2.9, noise) * radius;
        origin.addVertex(pt);
        i++;
    }
    float t = ofGetElapsedTimef();
    mesh = ofx3DQuickHull::quickhull3d(verts);
    str.str("");
    str << "Process Time[num / sec]: " << num << " / " << ofGetElapsedTimef() - t << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofRotateY(ofGetElapsedTimef()*10.0);
    ofSetColor(255, 180);
    mesh.draw();
    ofSetColor(0, 255);
    mesh.drawWireframe();
    
    glPointSize(3);
    ofDisableDepthTest();
    ofSetColor(255, 0, 0, 155);
    origin.drawVertices();
    
    cam.end();
    ofSetColor(255);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 5, 10);
    ofDrawBitmapString(str.str(), 5, 25);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

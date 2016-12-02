#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetLineWidth(2);
    light.setDirectional();
    light.setOrientation(ofVec3f(ofRandomf()*180, ofRandomf()*180, ofRandomf()*180));
}

//--------------------------------------------------------------
void ofApp::update(){
    light.pan(-3);
    static int MAX_NUM = 2000;
    int num = ofGetFrameNum()%MAX_NUM;
    if ( num < 4 ) num = 4;
    vector<ofVec3f> verts(num);
    int i=0;
    float radius = 200;
    float noise = int(ofGetFrameNum()/MAX_NUM);
    origin.clear();
    for ( auto & pt : verts ) {
        pt.x = ofSignedNoise(i*0.057, 1, noise) * radius;
        pt.y = ofSignedNoise(i*0.043, 1.5, noise) * radius;
        pt.z = ofSignedNoise(i*0.035, 2.9, noise) * radius;
        origin.addVertex(pt);
        i++;
    }
    float t = ofGetElapsedTimef();
    mesh = ofx3DQuickHull::quickhull3d(verts);
    str.clear();
    str.str("");
    str << "Process Time[num / sec]: " << num << " / " << ofGetElapsedTimef() - t << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofRotateY(ofGetElapsedTimef()*10.0);
    ofSetColor(255, 255);
    light.enable();
    mesh.draw();
    light.disable();
    ofDisableLighting();
    ofSetColor(0, 255, 0, 255);
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

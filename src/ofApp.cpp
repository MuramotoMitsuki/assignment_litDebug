#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    ofSetCircleResolution(60);

}

//--------------------------------------------------------------
void ofApp::update(){
    dx = mouseX-ofGetWidth()/2;
    dy = mouseY-ofGetHeight()/2;
    r = sqrt((dx*dx)+(dy*dy));

}

//--------------------------------------------------------------
void ofApp::draw(){
    int a = 0;
    for (int i=0; i<ofGetWidth()/30; i++) {
        ofSetColor(100,100,100,100);
        ofSetLineWidth(1);
        ofDrawLine(a, 0, a, ofGetHeight());
        ofDrawLine(0, a, ofGetWidth(), a);
        a = i*34.14;
    }
    ofSetColor(100, 100, 100, 255);
    ofDrawLine(mouseX, 0, mouseX, ofGetHeight());
    ofDrawLine(0, mouseY, ofGetWidth(), mouseY);
    
    double radion = atan2(dy, dx);
    radion = radion *(180/PI);
    
    ofSetColor(ofColor::fromHsb(abs(radion), 255, 255));
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,r);
    ofDrawLine(mouseX, mouseY, ofGetWidth()/2, ofGetHeight()/2);
    ofFill();
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,r*0.3);
    
    if (n%2==1) {
        ofSetColor(100, 100, 100, 255);
        ofDrawBitmapString("radius: " + ofToString(r), mouseX+10, mouseY+10);
        ofDrawBitmapString("angle: " + ofToString(radion), mouseX+10, mouseY+30);
        
        ofSetColor(100, 100, 100, 100);
        ofBeginShape();
        ofVertex(mouseX,mouseY);
        ofVertex(ofGetWidth()/2, ofGetHeight()/2);
        ofVertex(ofGetWidth()/2+r, ofGetHeight()/2);
        ofEndShape();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            n++;
            break;
    }
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(0);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    
    string text = "Hello";
    ofxTextParticle textparticle;
    textparticle.setup(text, ofPoint(ofGetWidth()/2., ofGetHeight()/3.), "font/Arial Black.ttf", 140);
    textParticles.push_back(textparticle);
    
    text = "World";
    textparticle.setup(text, ofPoint(ofGetWidth()/2., ofGetHeight()*2/3.), "font/Arial Black.ttf", 140);
    textParticles.push_back(textparticle);
    
    bNoise = false;

}

//--------------------------------------------------------------
void ofApp::update(){

    for(int i=0;i<textParticles.size();i++)
        textParticles[i].update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
 
    for(int i=0;i<textParticles.size();i++){
        if(bNoise)
            textParticles[i].noiseDraw();
        else
            textParticles[i].draw();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    bNoise = !bNoise;
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

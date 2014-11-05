//
//  ofxTextParticle.h
//  FaceSubstitutionCamera
//
//  Created by Ryota Katoh on 2014/10/30.
//
//

#ifndef __FaceSubstitutionCamera__ofxTextParticle__
#define __FaceSubstitutionCamera__ofxTextParticle__

#include "ofMain.h"

class Particle{

public:
    
    void setup(ofPoint _center, float _radius, ofColor _color){
    
        center = _center;
        radius = _radius;
        color  = _color;
        
    }
    
    void setVel(ofVec2f _vel){
    
        vel = _vel;
        
    }
    
    void update(){}
    
    void draw(){
    
        ofPushStyle();
        
        ofSetColor(color);
        
        ofCircle(center, radius);
        
        ofPopStyle();
        
    }
    
    void noiseDraw(){
        ofPushStyle();
        
        ofSetColor(color);
        
        ofPoint noisedCenter = center + ofNoise(ofRandom(10), ofRandom(10))*5;

        ofCircle(noisedCenter, radius);
        
        ofPopStyle();
        
        
    }
    
    void setColor(ofColor _col){
    
        color = _col;
        
    }
    ofColor getColor(){
    
        return color;
        
    }
    
    void setCenter(ofPoint _center){
    
        center = _center;
        
    }
    ofPoint getCenter(){
    
        return center;
    }
    
    
    
private:
    ofPoint center;
    float   radius;
    ofColor color;
    
    ofVec2f vel;
    
};


class ofxTextParticle{
public:
    void setup(string _text, ofPoint _center, string _fontPath, int fontSize);
    void update();
    void draw();
    void noiseDraw();
    
    void setString(string _text);
    void setInterval(int _interval);
    
    ofVec2f getStringSize();
    
    vector<Particle>    particles;
    vector<int>         particleIndexByCharacter;
private:
    float diffPoints(ofPoint p1, ofPoint p2);
    
    ofPoint        center;
    
    ofTrueTypeFont myFont;
    string text;
    
    float           threshold;
    int     interval;
    
};

#endif /* defined(__FaceSubstitutionCamera__ofxTextParticle__) */

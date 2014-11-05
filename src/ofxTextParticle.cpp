//
//  ofxTextParticle.cpp
//  FaceSubstitutionCamera
//
//  Created by Ryota Katoh on 2014/10/30.
//
//

#include "ofxTextParticle.h"

void ofxTextParticle::setup(string _text, ofPoint _center,string _fontPath, int _fontSize){

    // this is setting for particle.
    float particleRadius = 1.;
    ofColor particleColor= ofColor::white;
    
    
    // this is setting for textParticle.
    myFont.loadFont(_fontPath, _fontSize, true, true, true, 0.3, 0);
    
    setString(_text);
    center = _center;
    threshold = 3.0;
    interval = 5;

    vector<ofTTFCharacter> str = myFont.getStringAsPoints(text);
    
    ofPoint textCenter = ofPoint(myFont.stringWidth(text)/2., -myFont.stringHeight(text)/2.);
    ofPoint shift = center - textCenter;
    
    particleIndexByCharacter.push_back(0);
    
    // this loop is for each string.
    for(int i=0;i<str.size();i++){
    
        // this loop is for each character's outlines.
        for(int j=0;j<str[i].getOutline().size();j++){
        
            ofPoint first, prev, prev2;
            
            // this loop is for each outline's points.
            for(int k=0;k<=str[i].getOutline()[j].size();k++){
            
                ofVec2f pos;
                
                if(k<str[i].getOutline()[j].size()){
                
                    pos = ofPoint(str[i].getOutline()[j].getVertices()[k]);
                    
                    
                }
                else{
                
                    pos = first;
                    
                }
                
                if(k == 0){
                
                    first = pos;
                    
                    prev  = pos;
                    
                    prev2 = pos;
                }
                else{
                
                    float length = diffPoints(pos, prev);
                    
                    
                    float addX = (pos.x - prev.x)*(particleRadius/length);
                    float addY = (pos.y - prev.y)*(particleRadius/length);
                    
                    for(int n=0;n<(length/particleRadius);n++){
                        
                        prev+=ofPoint(addX, addY);
                        
                        float diff = diffPoints(prev, prev2);
                        if(diff > threshold){
                            Particle tmpPartcle;
                            tmpPartcle.setup(shift+prev, particleRadius, particleColor);
                            particles.push_back(tmpPartcle);
                            prev2 = prev;
                        }
                        
                    }
                    
                    
                    
                    prev = pos;
                    
                }
                
                
            }
            
        }
        
        particleIndexByCharacter.push_back(particles.size()-1);
        
    }
}

void ofxTextParticle::update(){
    
    for(int i=0;i<particles.size();i++){
    
        
        
    }

}

void ofxTextParticle::draw(){
    
//    for(int i=0;i<particles.size();i++){
//    
//        particles[i].draw();
//        
//    }
    
    for(int i=0;i<particles.size();i++){
    
        if(ofRandom(1.0) < 0.2){
        
            ofPoint p1 = particles[i].getCenter();
            
            int rnd = ofRandom(interval);
            if(i + rnd < particles.size()){
                particles[i].draw();
                particles[i+rnd].draw();
                ofPoint p2 = particles[i+rnd].getCenter();
                
                ofLine(p1, p2);
            }
            
        }
        
    }

    
}

void ofxTextParticle::noiseDraw(){

    for(int i=0;i<particles.size();i++){
    
        particles[i].noiseDraw();
        
    }
    
}



void ofxTextParticle::setString(string _text){

    text = _text;
    
}

void ofxTextParticle::setInterval(int _interval){

    interval = _interval;
    
}

float ofxTextParticle::diffPoints(ofPoint p1, ofPoint p2){

    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    
}

ofVec2f ofxTextParticle::getStringSize(){

    ofVec2f retVal;
  
    float width = myFont.stringHeight(text);
    float height= myFont.stringHeight(text);
    retVal.set(width, height);
    
    return retVal;
    
    
}


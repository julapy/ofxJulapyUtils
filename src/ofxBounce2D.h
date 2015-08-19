//
//  ofxBounce2D.h
//  EPRApp
//
//  Created by Lukasz Karluk on 19/08/2015.
//
//

#pragma once

#include "ofxBounce.h"

class ofxBounce2D {
    
public:
    
    void update();
    
    void springconst(float value);
    float springconst();
    
    void inertia(float value);
    float inertia();
    
    void center(ofVec2f value);
    ofVec2f center();
    
    void position(ofVec2f value);
    ofVec2f position();
    
    void velocity(ofVec2f value);
    ofVec2f velocity();
    
    ofxBounce bounceX;
    ofxBounce bounceY;
    
};

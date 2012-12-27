/*
 *  ofxBounce.h
 *  julapy_sydfest
 *
 *  Created by lukasz karluk on 5/01/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

class ofxBounce {
    
public:
    
    ofxBounce() {
        k = 0.1;    // spring constant.
        i = 0.9;    // inertia.
        c = 0;      // center.
        p = 0;      // position.
        d = 0;      // difference = center - position.
        v = 0;      // velocity.
    };
    
    void update() {
        d = c - p;
        v = v * i + d * k;
        p += v;
    };
    
    void springconst(float value) {
        k = value;
    };
    
    float springconst() {
        return k;
    };
    
    void inertia(float value) {
        i = value;
    };
    
    float inertia() {
        return i;
    };
    
    void center(float value) {
        c = value;
    };
    
    float center() {
        return c;
    };
    
    void position(float value) {
        p = value;
    };
    
    float position() {
        return p;
    };
    
    void  velocity(float value) {
        v = value;
    };
    
    float velocity() {
        return v;
    };
    
private:
    
    float k;  // spring constant.
    float i;  // inertia.
    float c;  // center.
    float p;  // position.
    float d;  // difference = center - position.
    float v;  // velocity.
    
};

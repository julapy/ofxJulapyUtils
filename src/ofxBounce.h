/*
 *  ofxBounce.h
 *  Created by lukasz karluk on 5/01/10.
 */

#pragma once

//-----------------------------------------
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
    
    float springconst() const {
        return k;
    };
    
    void inertia(float value) {
        i = value;
    };
    
    float inertia() const {
        return i;
    };
    
    void center(float value) {
        c = value;
    };
    
    float center() const {
        return c;
    };
    
    void position(float value) {
        p = value;
    };
    
    float position() const {
        return p;
    };
    
    void  velocity(float value) {
        v = value;
    };
    
    float velocity() const {
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

//-----------------------------------------
class ofxBounce2D {
    
public:
    
    void update() {
        bounceX.update();
        bounceY.update();
    };
    
    void springconst(float value) {
        bounceX.springconst(value);
        bounceY.springconst(value);
    };
    
    float springconst() {
        return bounceX.springconst();
    };
    
    void inertia(float value) {
        bounceX.inertia(value);
        bounceY.inertia(value);
    };
    
    float inertia() {
        return bounceX.inertia();
    };
    
    void center(ofVec2f value) {
        bounceX.center(value.x);
        bounceY.center(value.y);
    };
    
    ofVec2f center() {
        return ofVec2f(bounceX.center(), bounceY.center());
    };
    
    void position(ofVec2f value) {
        bounceX.position(value.x);
        bounceY.position(value.y);
    };
    
    ofVec2f position() {
        return ofVec2f(bounceX.position(), bounceY.position());
    };
    
    void  velocity(ofVec2f value) {
        bounceX.velocity(value.x);
        bounceY.velocity(value.y);
    };
    
    ofVec2f velocity() {
        return ofVec2f(bounceX.velocity(), bounceY.velocity());
    };
    
    ofxBounce bounceX;
    ofxBounce bounceY;
    
};


//
//  ofxBounce.cpp
//  EPRApp
//
//  Created by Lukasz Karluk on 19/08/2015.
//
//

#include "ofxBounce.h"

ofxBounce::ofxBounce() {
    k = 0.1;    // spring constant.
    i = 0.9;    // inertia.
    c = 0;      // center.
    p = 0;      // position.
    d = 0;      // difference = center - position.
    v = 0;      // velocity.
};

void ofxBounce::update() {
    d = c - p;
    v = v * i + d * k;
    p += v;
};

void ofxBounce::springconst(float value) {
    k = value;
};

float ofxBounce::springconst() const {
    return k;
};

void ofxBounce::inertia(float value) {
    i = value;
};

float ofxBounce::inertia() const {
    return i;
};

void ofxBounce::center(float value) {
    c = value;
};

float ofxBounce::center() const {
    return c;
};

void ofxBounce::position(float value) {
    p = value;
};

float ofxBounce::position() const {
    return p;
};

void ofxBounce::velocity(float value) {
    v = value;
};

float ofxBounce::velocity() const {
    return v;
};


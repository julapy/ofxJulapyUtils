//
//  ofxBounce2D.cpp
//  EPRApp
//
//  Created by Lukasz Karluk on 19/08/2015.
//
//

#include "ofxBounce2D.h"

void ofxBounce2D::update() {
    bounceX.update();
    bounceY.update();
};

void ofxBounce2D::springconst(float value) {
    bounceX.springconst(value);
    bounceY.springconst(value);
};

float ofxBounce2D::springconst() {
    return bounceX.springconst();
};

void ofxBounce2D::inertia(float value) {
    bounceX.inertia(value);
    bounceY.inertia(value);
};

float ofxBounce2D::inertia() {
    return bounceX.inertia();
};

void ofxBounce2D::center(ofVec2f value) {
    bounceX.center(value.x);
    bounceY.center(value.y);
};

ofVec2f ofxBounce2D::center() {
    return ofVec2f(bounceX.center(), bounceY.center());
};

void ofxBounce2D::position(ofVec2f value) {
    bounceX.position(value.x);
    bounceY.position(value.y);
};

ofVec2f ofxBounce2D::position() {
    return ofVec2f(bounceX.position(), bounceY.position());
};

void ofxBounce2D::velocity(ofVec2f value) {
    bounceX.velocity(value.x);
    bounceY.velocity(value.y);
};

ofVec2f ofxBounce2D::velocity() {
    return ofVec2f(bounceX.velocity(), bounceY.velocity());
};

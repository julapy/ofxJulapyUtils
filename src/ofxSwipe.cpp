//
//  ofxSwipe.cpp
//  AWM-osx
//
//  Created by Lukasz Karluk on 18/07/2014.
//
//

#include "ofxSwipe.h"

ofxSwipe::ofxSwipe() {
    //
}

ofxSwipe::~ofxSwipe() {
    //
}

//----------------------------------------
void ofxSwipe::setup() {
    if(swipeArea.isEmpty() == true) {
        setSwipeArea(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
    }
}

void ofxSwipe::setSwipeArea(const ofRectangle & rect) {
    swipeArea = rect;
}

//----------------------------------------
void ofxSwipe::update() {
    bSwipeStarted = false;
    bSwipeChanged = false;
    bSwipeFinished = false;
    bSwipeCancelled = false;
}

//----------------------------------------
void ofxSwipe::touchDown(float x, float y) {
    bool bInsideSwipeArea = swipeArea.inside(x, y);
    if(bInsideSwipeArea == false) {
        return;
    }
    
    points.clear();
    points.push_back(ofxSwipePoint(x, y, ofGetElapsedTimef(), ofxSwipePointTypeDown));
    
    bSwiping = true;
    bSwipeStarted = true;
}

void ofxSwipe::touchMoved(float x, float y) {
    if(bSwiping == false) {
        return;
    }
    if(points.back().point.x == x && points.back().point.y == y) {
        points.pop_back();  // remove duplicate points.
    }
    points.push_back(ofxSwipePoint(x, y, ofGetElapsedTimef(), ofxSwipePointTypeMoved));
    
    bSwipeChanged = true;
}

void ofxSwipe::touchUp(float x, float y) {
    if(bSwiping == false) {
        return;
    }
    if(points.back().point.x == x && points.back().point.y == y) {
        points.pop_back(); // remove duplicate points.
    }
    points.push_back(ofxSwipePoint(x, y, ofGetElapsedTimef(), ofxSwipePointTypeUp));
    
    bSwiping = false;
    bSwipeFinished = true;
}

void ofxSwipe::touchCancel(float x, float y) {
    points.clear();
    
    bSwiping = false;
    bSwipeCancelled = true;
}

//----------------------------------------
ofVec2f ofxSwipe::getDirectionVector() {
    ofVec2f dir;
    if(points.size() < 2) {
        return dir;
    }
    
    const ofVec2f & p0 = points[0].point;                   // first point.
    const ofVec2f & p1 = points[points.size()-1].point;     // last point.
    dir = p1 - p0;
    return dir;
}

float ofxSwipe::getDirectionAngle() {
    ofVec2f dirVec = getDirectionVector();
    float angle = 180 - dirVec.angle(ofVec2f(0, 1));
    return angle;
}

ofxSwipeDirection ofxSwipe::getDirection() {
    ofxSwipeDirection dir;
    float angle = getDirectionAngle();
    if((angle > 315 && angle <= 360) || (angle >= 0 && angle <= 45)) {
        dir = OFX_SWIPE_DIRECTION_UP;
    } else if(angle > 45 && angle <= 135) {
        dir = OFX_SWIPE_DIRECTION_RIGHT;
    } else if(angle > 135 && angle <= 225) {
        dir = OFX_SWIPE_DIRECTION_DOWN;
    } else if(angle > 225 && angle <= 315) {
        dir = OFX_SWIPE_DIRECTION_LEFT;
    }
    return dir;
}

ofVec2f ofxSwipe::getVelocity() {
    ofVec2f vel;
    if(points.size() < 2) {
        return vel;
    }
    const ofxSwipePoint & sp0 = points[points.size()-2]; // second last.
    const ofxSwipePoint & sp1 = points[points.size()-1]; // last.
    const ofVec2f & p0 = sp0.point;
    const ofVec2f & p1 = sp1.point;
    float t0 = sp0.timeSec;
    float t1 = sp1.timeSec;
    
    vel = p1 - p0;
    vel /= (t1 - t0);
    return vel;
}

float ofxSwipe::getSpeed() {
    ofVec2f vel = getVelocity();
    return vel.length();
}

float ofxSwipe::getLength() {
    ofVec2f dir = getDirectionVector();
    return dir.length();
}

float ofxSwipe::getDurationInSeconds() {
    float durartion = 0;
    if(points.size() < 2) {
        return durartion;
    }
    
    const ofxSwipePoint & p0 = points[0];                   // first point.
    const ofxSwipePoint & p1 = points[points.size()-1];     // last point.
    durartion = p1.timeSec - p0.timeSec;
    return durartion;
}

//----------------------------------------
bool ofxSwipe::isSwiping() {
    return bSwiping;
}

bool ofxSwipe::isSwipeStartedOnThisFrame() {
    return bSwipeStarted;
}

bool ofxSwipe::isSwipeChangedOnThisFrame() {
    return bSwipeChanged;
}

bool ofxSwipe::isSwipeFinishedOnThisFrame() {
    return bSwipeFinished;
}

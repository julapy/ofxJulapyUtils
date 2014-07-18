//
//  ofxSwipe.h
//  Created by Lukasz Karluk on 24/03/2014.
//

#pragma once

#include "ofMain.h"

//--------------------------------------------------------------
enum ofxSwipeDirection {
    OFX_SWIPE_DIRECTION_UNDEFINED   = 0,
    OFX_SWIPE_DIRECTION_UP          = 1,
    OFX_SWIPE_DIRECTION_RIGHT       = 2,
    OFX_SWIPE_DIRECTION_DOWN        = 3,
    OFX_SWIPE_DIRECTION_LEFT        = 4
};

static const string ofxSwipePointTypeDown   = "down";
static const string ofxSwipePointTypeMoved  = "moved";
static const string ofxSwipePointTypeUp     = "up";

//--------------------------------------------------------------
class ofxSwipePoint {
public:
    ofxSwipePoint(float x, float y, float timeSec, string type) {
        point.set(x, y);
        this->timeSec = timeSec;
        this->type = type;
    }
    ofVec2f point;
    float timeSec = 0;
    string type = "";
};

//--------------------------------------------------------------
class ofxSwipe {
    
public:
    ofxSwipe();
    ~ofxSwipe();
    
    void setup();
    void setSwipeArea(const ofRectangle & rect);
    
    void update();
    
    void touchDown(float x, float y);
    void touchMoved(float x, float y);
    void touchUp(float x, float y);
    void touchCancel(float x, float y);
    
    ofVec2f getDirectionVector();
    float getDirectionAngle();
    ofxSwipeDirection getDirection();
    ofVec2f getVelocity();
    float getSpeed();
    float getLength();
    float getDurationInSeconds();
    
    bool isSwiping();
    bool isSwipeStartedOnThisFrame();
    bool isSwipeChangedOnThisFrame();
    bool isSwipeFinishedOnThisFrame();
    
    vector<ofxSwipePoint> points;
    ofRectangle swipeArea;
    
    bool bSwiping = false;
    bool bSwipeStarted = false;
    bool bSwipeChanged = false;
    bool bSwipeFinished = false;
    bool bSwipeCancelled = false;
};
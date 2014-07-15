//
//  ofxSwipe.h
//  Created by Lukasz Karluk on 24/03/2014.
//

#pragma once

#include "ofMain.h"

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

class ofxSwipe {
    
public:
    ofxSwipe() {}
    ~ofxSwipe() {}
    
    //----------------------------------------
    void touchDown(float x, float y) {
        points.clear();
        points.push_back(ofxSwipePoint(x, y, ofGetElapsedTimef(), ofxSwipePointTypeDown));

        bSwiping = true;
        bSwipeStarted = true;
    }
    
    void touchMoved(float x, float y) {
        if(bSwiping == false) {
            return;
        }
        if(points.back().point.x == x && points.back().point.y == y) {
            points.pop_back();  // remove duplicate points.
        }
        points.push_back(ofxSwipePoint(x, y, ofGetElapsedTimef(), ofxSwipePointTypeMoved));
        
        bSwipeChanged = true;
    }
    
    void touchUp(float x, float y) {
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
    
    void touchCancel(float x, float y) {
        points.clear();

        bSwiping = false;
        bSwipeCancelled = true;
    }
    
    //----------------------------------------
    void update() {
        bSwipeStarted = false;
        bSwipeChanged = false;
        bSwipeFinished = false;
        bSwipeCancelled = false;
    }
    
    //----------------------------------------
    ofVec2f getDirectionVector() {
        ofVec2f dir;
        if(points.size() < 2) {
            return dir;
        }
        
        const ofVec2f & p0 = points[0].point;                   // first point.
        const ofVec2f & p1 = points[points.size()-1].point;     // last point.
        dir = p1 - p0;
        return dir;
    }
    
    float getDirectionAngle() {
        ofVec2f dirVec = getDirectionVector();
        float angle = 180 - dirVec.angle(ofVec2f(0, 1));
        return angle;
    }
    
    ofxSwipeDirection getDirection() {
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
    
    ofVec2f getVelocity() {
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
    
    float getSpeed() {
        ofVec2f vel = getVelocity();
        return vel.length();
    }
    
    float getLength() {
        ofVec2f dir = getDirectionVector();
        return dir.length();
    }
    
    float getDurationInSeconds() {
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
    bool isSwiping() {
        return bSwiping;
    }
    
    bool isSwipeStartedOnThisFrame() {
        return bSwipeStarted;
    }
    
    bool isSwipeChangedOnThisFrame() {
        return bSwipeChanged;
    }
    
    bool isSwipeFinishedOnThisFrame() {
        return bSwipeFinished;
    }
    
    //----------------------------------------
    vector<ofxSwipePoint> points;
    bool bSwiping = false;
    bool bSwipeStarted = false;
    bool bSwipeChanged = false;
    bool bSwipeFinished = false;
    bool bSwipeCancelled = false;
};
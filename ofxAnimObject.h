//
//  ofxAnimObject.h
//  Created by lukasz karluk on 17/08/12.
//

#pragma once

#include "ofMain.h"

class ofxAnimObject {
    
public:
    
    ofxAnimObject() {
        timeStartMs = 0;
        timeTotalMs = 0;
        progress = 0;
        bAnimating = false;
        bAnimatingIn = false;
        bAnimatingOut = false;
        bAnimationComplete = false;
    }
    
    void animateIn(int timeTotalMs) {
        if(bAnimatingIn) {
            return;
        }
        
        initTimer(timeTotalMs);
        
        bAnimating = true;
        bAnimatingIn = true;
        bAnimatingOut = false;
        bAnimationComplete = false;
    }
    
    void animateOut(int timeTotalMs) {
        if(bAnimatingOut) {
            return;
        }
        
        initTimer(timeTotalMs);
        
        bAnimating = true;
        bAnimatingIn = false;
        bAnimatingOut = true;
        bAnimationComplete = false;
    }
    
    void initTimer(int timeTotalMs) {
        this->timeTotalMs = timeTotalMs;
        timeStartMs = ofGetElapsedTimeMillis();
        if(timeTotalMs) {
            progress = 1 - progress;
            timeStartMs -= timeTotalMs * progress;
        } else {
            progress = 0;
        }
    }
    
    void update() {
        if(bAnimating) {
            if(bAnimationComplete) {
                bAnimating = false;
                return;
            }
            
            int timeMs = ofGetElapsedTimeMillis();
            progress = (timeMs - timeStartMs) / (float)timeTotalMs;
            bAnimationComplete = progress >= 1.0;
            if(bAnimationComplete) {
                progress = 1.0;
            }
        }
    }
    
    bool isAnimating() {
        return bAnimating;
    }
    
    bool isAnimatingIn() {
        return bAnimatingIn;
    }

    bool isAnimatingOut() {
        return bAnimatingOut;
    }
    
    bool isAnimationComplete() {
        return bAnimationComplete;
    }
    
    float getProgress() {
        return progress;
    }
    
protected:
    
    int timeStartMs;
    int timeTotalMs;
    float progress;
    bool bAnimating;
    bool bAnimatingIn;
    bool bAnimatingOut;
    bool bAnimationComplete;
};
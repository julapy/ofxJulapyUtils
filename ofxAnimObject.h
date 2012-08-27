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
        bAnimationCompleteOnLastUpdate = false;
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
        bAnimationCompleteOnLastUpdate =false;
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
        bAnimationCompleteOnLastUpdate = false;
    }
    
    void update() {
        if(bAnimating) {
            if(bAnimationComplete) {
                bAnimating = false;
                bAnimationCompleteOnLastUpdate = false;
                return;
            }
            
            int timeMs = ofGetElapsedTimeMillis();
            progress = (timeMs - timeStartMs) / (float)timeTotalMs;
            bAnimationComplete = progress >= 1.0;
            if(bAnimationComplete) {
                progress = 1.0;
                bAnimationCompleteOnLastUpdate = true;
            }
        }
    }
    
    bool isAnimating() {
        return bAnimating;
    }
    
    bool isAnimatingIn() {
        return bAnimatingIn && !bAnimationComplete;
    }
    
    bool isAnimatingOut() {
        return bAnimatingOut && !bAnimationComplete;
    }
    
    bool isAnimationComplete() {
        return bAnimationComplete;
    }
    
    bool hasJustFinishedAnimatingIn() {
        return bAnimatingIn && bAnimationCompleteOnLastUpdate;
    }

    bool hasJustFinishedAnimatingOut() {
        return bAnimatingOut && bAnimationCompleteOnLastUpdate;
    }
    
    bool hasJustFinishedAnimating() {
        return bAnimationCompleteOnLastUpdate;
    }
    
    float getProgress() {
        if(bAnimatingIn) {
            return progress;
        }
        if(bAnimatingOut) {
            return 1 - progress;
        }
        return progress;
    }
    
protected:
    
    void initTimer(int timeTotalMs) {
        this->timeTotalMs = timeTotalMs;
        timeStartMs = ofGetElapsedTimeMillis();
        if(bAnimating) {
            progress = 1 - progress;
            timeStartMs -= timeTotalMs * progress;
        } else {
            progress = 0;
        }
    }
    
    int timeStartMs;
    int timeTotalMs;
    float progress;
    bool bAnimating;
    bool bAnimatingIn;
    bool bAnimatingOut;
    bool bAnimationComplete;
    bool bAnimationCompleteOnLastUpdate;
};
//
//  ofxAnimFlicker.h
//  Created by lukasz karluk on 21/08/12.
//

#pragma once

#include "ofMain.h"

class ofxAnimFlicker {
  
public:
    
    ofxAnimFlicker() {
        timeStartMs = 0;
        timeTotalMs = 0;
        timeIntervalMs = 0;
        timeFlickerMs = 0;
        bComplete = true;
        bFlickerOn = true;
    }
    
    void flicker(int timeIntervalMs, int timeTotalMs) {
        this->timeStartMs = ofGetElapsedTimeMillis();
        this->timeTotalMs = timeTotalMs;
        this->timeIntervalMs = timeIntervalMs;
        this->timeFlickerMs = timeStartMs;
        bComplete = false;
    }
    
    void update() {
        if(bComplete) {
            return;
        }
        
        int timeMs = ofGetElapsedTimeMillis();
        if(timeMs > timeStartMs + timeTotalMs) {
            bComplete = true;
            bFlickerOn = true;
            return;
        }
        
        int nextMs = timeFlickerMs + timeIntervalMs;
        if(timeMs >= nextMs){
            timeFlickerMs = nextMs;
            bFlickerOn = !bFlickerOn;
        }
    }
    
    bool isFlickerOn() {
        return bFlickerOn;
    }
    
    bool isAnimating() {
        return !bComplete;
    }
    
protected:
    
    int timeStartMs;
    int timeTotalMs;
    int timeIntervalMs;
    int timeFlickerMs;
    bool bFlickerOn;
    bool bComplete;
    
};
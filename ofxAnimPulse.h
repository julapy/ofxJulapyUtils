//
//  ofxAnimPulse.h
//  Created by lukasz karluk on 21/08/12.
//

#pragma once

#include "ofMain.h"

class ofxAnimPulse {

public:
    
    ofxAnimPulse() {
        pulseValue = 0;
        pulseDecay = 0;
        startTimeMs = 0;
        delayTimeMs = 0;
        bReady = false;
        bComplete = false;
    }
    
    void pulse(float pulseValue, float pulseDecay, int delayTimeMs=0) {
        this->pulseValue = pulseValue;
        this->pulseDecay = pulseDecay;
        this->startTimeMs = ofGetElapsedTimeMillis();
        this->delayTimeMs = delayTimeMs;
        bReady = false;
        bComplete = false;
    }
    
    void update() {
        if(bComplete) {
            return;
        }
        if(!bReady) {
            int timeMs = ofGetElapsedTimeMillis();
            if(timeMs >= startTimeMs + delayTimeMs) {
                bReady = true;
            } else {
                return;
            }
        }
        
        pulseValue *= (1 - pulseDecay);
        
        bComplete = pulseValue < 0.0001;
    }
    
    float getValue() {
        return pulseValue;
    }
    
    bool isAnimating() {
        return !bComplete;
    }
    
protected:
    
    float pulseValue;
    float pulseDecay;
    int startTimeMs;
    int delayTimeMs;
    bool bReady;
    bool bComplete;
    
};
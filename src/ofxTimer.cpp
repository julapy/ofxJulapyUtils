//
//  ofxTimer.cpp
//  EPRApp
//
//  Created by Lukasz Karluk on 10/10/2015.
//
//

#include "ofxTimer.h"

//--------------------------------------------------------------
double ofxTimerGetTimeElapsedSinceLastFrame() {
    float value = ofGetLastFrameTime();
    return value;
}

//--------------------------------------------------------------
ofxTimer::ofxTimer() {
    reset();
}

ofxTimer::~ofxTimer() {
    //
}

void ofxTimer::start(double _timeDurationInSeconds, double _optionalTimeOffsetInSeconds) {
    reset();
    
    bStarted = true;
    
    timeDurationInSeconds = _timeDurationInSeconds;
    if(timeDurationInSeconds <= 0.0) {
        
        // if timer duration is zero or less the zero,
        // the timer finishes straight away,
        // without update having to be called.
        
        timeDurationInSeconds = 0.0;
        progress = 1.0;
        bFinished = true;
        bFinishedOnLastUpdate = true;
        
        return;
    }

    timeRunningInSeconds = _optionalTimeOffsetInSeconds;
    if(timeRunningInSeconds < 0.0) {
        timeRunningInSeconds = 0.0;
    }
}

void ofxTimer::stop() {
    reset();
}

void ofxTimer::reset() {
    timeRunningInSeconds = 0.0;
    timeDurationInSeconds = 0.0;
    progress = 0;
    bStarted = false;
    bPaused = false;
    bFinished = false;
    bFinishedOnLastUpdate = false;
}

void ofxTimer::setPaused(bool value) {
    bPaused = value;
}

void ofxTimer::update(double _optionalTimeElapsedSinceLastUpdateInSeconds) {

    bFinishedOnLastUpdate = false;
    
    if(isRunning() == false) {
        return;
    }
    
    if(isPaused() == true) {
        return;
    }
    
    double timeElapsedSinceLastUpdateInSeconds = _optionalTimeElapsedSinceLastUpdateInSeconds;
    if(timeElapsedSinceLastUpdateInSeconds < 0.0) {
        timeElapsedSinceLastUpdateInSeconds = ofxTimerGetTimeElapsedSinceLastFrame();
    }
    
    timeRunningInSeconds += timeElapsedSinceLastUpdateInSeconds;
    if(timeRunningInSeconds > timeDurationInSeconds) {
        timeRunningInSeconds = timeDurationInSeconds;
    }
    
    progress = timeRunningInSeconds / timeDurationInSeconds;
    
    bool bFinishedNew = (progress >= 1.0);

    bFinishedOnLastUpdate = true;
    bFinishedOnLastUpdate = bFinishedOnLastUpdate && (bFinished == false);
    bFinishedOnLastUpdate = bFinishedOnLastUpdate && (bFinishedNew == true);
    
    bFinished = bFinishedNew;
}

bool ofxTimer::isRunning() const {
    bool bRunning = true;
    bRunning = bRunning && (bStarted == true);
    bRunning = bRunning && (bFinished == false);
    return bRunning;
}

bool ofxTimer::isPaused() const {
    return bPaused;
}

bool ofxTimer::hasStarted() const {
    return bStarted;
}

bool ofxTimer::hasFinished() const {
    return bFinished;
}

bool ofxTimer::hasFinishedOnLastUpdate() const {
    return bFinishedOnLastUpdate;
}

double ofxTimer::getTimeRunningInSeconds() const {
    return timeRunningInSeconds;
}

double ofxTimer::getTimeDurationInSeconds() const {
    return timeDurationInSeconds;
}

double ofxTimer::getProgress() const {
    return progress;
}

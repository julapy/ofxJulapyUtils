//
//  ofxTimer.cpp
//  EPRApp
//
//  Created by Lukasz Karluk on 10/10/2015.
//
//

#include "ofxTimer.h"

ofxTimer::ofxTimer() {
    reset();
}

ofxTimer::~ofxTimer() {
    //
}

void ofxTimer::start(double timeDurationInSeconds) {
    reset();
    
    this->timeDurationInSeconds = timeDurationInSeconds;
    bRunning = true;
}

void ofxTimer::stop() {
    reset();
}

void ofxTimer::reset() {
    timeRunningInSeconds = 0.0;
    timeDurationInSeconds = 0.0;
    progress = 0;
    bRunning = false;
    bPaused = false;
    bFinished = false;
    bFlagAsFinishedOnNextUpdate = false;
}

void ofxTimer::setPaused(bool value) {
    bPaused = value;
}

void ofxTimer::update(double optionalTimeElapsedSinceLastUpdateInSeconds) {

    if(bRunning == false) {
        return;
    }
    
    if(bPaused == true) {
        return;
    }
    
    if(bFlagAsFinishedOnNextUpdate == true) {
        bFlagAsFinishedOnNextUpdate = false;
        bFinished = true;
    }
    
    double timeElapsedSinceLastUpdateInSeconds = optionalTimeElapsedSinceLastUpdateInSeconds;
    if(timeElapsedSinceLastUpdateInSeconds < 0.0) {
        timeElapsedSinceLastUpdateInSeconds = ofGetLastFrameTime();
    }
    
    timeRunningInSeconds += timeElapsedSinceLastUpdateInSeconds;
    
    progress = timeRunningInSeconds/ timeDurationInSeconds;
    
    bool bFinishedNew = (progress >= 1.0);

    bFlagAsFinishedOnNextUpdate = true;
    bFlagAsFinishedOnNextUpdate = bFlagAsFinishedOnNextUpdate && (bFinished == false);
    bFlagAsFinishedOnNextUpdate = bFlagAsFinishedOnNextUpdate && (bFinishedNew == true);
}

bool ofxTimer::isRunning() {
    return bRunning;
}

bool ofxTimer::hasFinished() {
    return bFinished;
}

double ofxTimer::getTimeRunningInSeconds() {
    return timeRunningInSeconds;
}

double ofxTimer::getTimeRunningInSecondsCapped() {
    float value = timeRunningInSeconds;
    if(value > timeDurationInSeconds) {
        value = timeDurationInSeconds;
    }
    return value;
}

double ofxTimer::getTimeDurationInSeconds() {
    return timeDurationInSeconds;
}

double ofxTimer::getProgress() {
    return progress;
}

double ofxTimer::getProgressCapped() {
    float value = progress;
    if(value > 1.0) {
        value = 1.0;
    }
    return value;
}

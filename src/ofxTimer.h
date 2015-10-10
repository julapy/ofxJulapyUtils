//
//  ofxTimer.hpp
//  Created by Lukasz Karluk on 10/10/2015.
//  http://codeoncanvas.cc
//

#pragma once

#include "ofMain.h"

//--------------------------------------------------------------
double ofxTimerGetTimeElapsedSinceLastFrame();

//--------------------------------------------------------------
class ofxTimer {
    
public:
    
    ofxTimer();
    ~ofxTimer();
    
    void start(double timeDurationInSeconds);
    void stop();
    void reset();
    void setPaused(bool value);
    
    void update(double optionalTimeElapsedSinceLastUpdateInSeconds=-1);
    
    bool isRunning();
    bool hasFinished();

    double getTimeRunningInSeconds();
    double getTimeRunningInSecondsCapped();
    double getTimeDurationInSeconds();
    double getProgress();
    double getProgressCapped();
    
protected:
    
    double timeRunningInSeconds;
    double timeDurationInSeconds;
    float progress;
    bool bRunning;
    bool bPaused;
    bool bFinished;
    bool bFlagAsFinishedOnNextUpdate;
};

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
    
    void start(double timeDurationInSeconds, double optionalTimeOffsetInSeconds=-1);
    void stop();
    void reset();
    void setPaused(bool value);
    
    void update(double optionalTimeElapsedSinceLastUpdateInSeconds=-1);
    
    bool isRunning() const;
    bool isPaused() const;
    bool hasStarted() const;
    bool hasFinished() const;
    bool hasFinishedOnLastUpdate() const;

    double getTimeRunningInSeconds() const;
    double getTimeDurationInSeconds() const;
    double getProgress() const;
    
protected:
    
    double timeRunningInSeconds;
    double timeDurationInSeconds;
    float progress;
    bool bStarted;
    bool bPaused;
    bool bFinished;
    bool bFinishedOnLastUpdate;
};

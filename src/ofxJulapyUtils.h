//
//  ofxJulapyUtils.h
//  Created by Lukasz Karluk on 16/06/2014.
//

#pragma once

#include "ofMain.h"

enum ofDrawRectOutlineMode {
    ofDrawRectOutlineModeOuter = 1,
    ofDrawRectOutlineModeInner = 2,
    ofDrawRectOutlineModeMiddle = 3,
};

void ofDrawRectOutline(const ofRectangle & rect,
                       int thickness=1,
                       ofDrawRectOutlineMode mode=ofDrawRectOutlineModeOuter);

ofRectangle ofRectangleLerp(const ofRectangle & rectFrom,
                            const ofRectangle & rectTo,
                            float progress);

ofRectangle ofRectangleErode(const ofRectangle & rect, float amount);

ofRectangle ofRectangleDilate(const ofRectangle & rect, float amount);

ofRectangle ofRectangleTransform(const ofRectangle & rect, const ofMatrix4x4 & mat);

bool ofRectangleEase(ofRectangle & rect, const ofRectangle & targetRect, float easeAmount=0.1);
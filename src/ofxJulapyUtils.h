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
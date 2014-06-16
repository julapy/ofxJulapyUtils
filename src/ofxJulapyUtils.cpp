//
//  ofxJulapyUtils.cpp
//  Created by Lukasz Karluk on 16/06/2014.
//

#include "ofxJulapyUtils.h"

void ofDrawRectOutline(const ofRectangle & rect, int thickness, ofDrawRectOutlineMode mode) {
    
    float b0, b1;
    if(mode == ofDrawRectOutlineModeOuter) {
        b0 = thickness;
        b1 = 0;
    } else if(mode == ofDrawRectOutlineModeInner) {
        b0 = 0;
        b1 = thickness;
    } else if(mode == ofDrawRectOutlineModeMiddle) {
        b0 = thickness * 0.5;
        b1 = thickness * 0.5;
    }
    
    ofVec2f po0(rect.x - b0, rect.y - b0);
    ofVec2f po1(rect.x + rect.width + b0, rect.y - b0);
    ofVec2f po2(rect.x + rect.width + b0, rect.y + rect.height + b0);
    ofVec2f po3(rect.x - b0, rect.y + rect.height + b0);
    
    ofVec2f pi0(rect.x + b1, rect.y + b1);
    ofVec2f pi1(rect.x + rect.width - b1, rect.y + b1);
    ofVec2f pi2(rect.x + rect.width - b1, rect.y + rect.height - b1);
    ofVec2f pi3(rect.x + b1, rect.y + rect.height - b1);
    
    ofBeginShape();

    ofVertex(po0.x, po0.y);
    ofVertex(po1.x, po1.y);
    ofVertex(po2.x, po2.y);
    ofVertex(po3.x, po3.y);
    
    ofNextContour();
    
    ofVertex(pi0.x, pi0.y);
    ofVertex(pi1.x, pi1.y);
    ofVertex(pi2.x, pi2.y);
    ofVertex(pi3.x, pi3.y);
    
    ofEndShape(true);
}
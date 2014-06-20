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

ofRectangle ofRectangleLerp(const ofRectangle & rectFrom,
                            const ofRectangle & rectTo,
                            float progress) {
    
    ofVec3f r00 = rectFrom.getTopLeft();
    ofVec3f r01 = rectFrom.getTopRight();
    ofVec3f r02 = rectFrom.getBottomRight();
    ofVec3f r03 = rectFrom.getBottomLeft();

    ofVec3f r10 = rectTo.getTopLeft();
    ofVec3f r11 = rectTo.getTopRight();
    ofVec3f r12 = rectTo.getBottomRight();
    ofVec3f r13 = rectTo.getBottomLeft();
    
    ofVec3f r20 = r00.interpolate(r10, progress);
    ofVec3f r21 = r01.interpolate(r11, progress);
    ofVec3f r22 = r02.interpolate(r12, progress);
    ofVec3f r23 = r03.interpolate(r13, progress);
    
    ofRectangle rect;
    rect.set(r20, r22);
    
    return rect;
}

ofRectangle ofRectangleErode(const ofRectangle & rect, float amount) {
    
    ofRectangle r = rect;
    r.x += amount;
    r.y += amount;
    r.width -= amount * 2;
    r.height -= amount * 2;
    return r;
}

ofRectangle ofRectangleDilate(const ofRectangle & rect, float amount) {
    
    ofRectangle r = rect;
    r.x -= amount;
    r.y -= amount;
    r.width += amount * 2;
    r.height += amount * 2;
    return r;
}
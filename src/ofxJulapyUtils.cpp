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
    ofVec3f r01 = rectFrom.getBottomRight();

    ofVec3f r10 = rectTo.getTopLeft();
    ofVec3f r11 = rectTo.getBottomRight();
    
    ofVec3f r20 = r00.interpolate(r10, progress);
    ofVec3f r21 = r01.interpolate(r11, progress);
    
    ofRectangle rect;
    rect.set(r20, r21);
    
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

ofRectangle ofRectangleTransform(const ofRectangle & rect, const ofMatrix4x4 & mat) {
    ofVec3f tl = rect.getTopLeft();
    ofVec3f br = rect.getBottomRight();
    
    tl = mat.preMult(tl);
    br = mat.preMult(br);
    
    ofRectangle r;
    r.setPosition(tl);
    r.growToInclude(br);
    
    return r;
}

bool ofRectangleEase(ofRectangle & rect,
                     const ofRectangle & targetRect,
                     float easeAmount) {
    
    static float const kEasingStop = 0.01;
    
    bool bChanged = false;
    
    ofVec2f rectP0(rect.x, rect.y);
    ofVec2f rectP1(rect.x + rect.width, rect.y + rect.height);
    
    ofVec2f targetRectP0(targetRect.x, targetRect.y);
    ofVec2f targetRectP1(targetRect.x + targetRect.width, targetRect.y + targetRect.height);
    
    bool bRectsAreEqual = true;
    bRectsAreEqual = bRectsAreEqual && (rectP0.x == targetRectP0.x);
    bRectsAreEqual = bRectsAreEqual && (rectP0.y == targetRectP0.y);
    bRectsAreEqual = bRectsAreEqual && (rectP1.x == targetRectP1.x);
    bRectsAreEqual = bRectsAreEqual && (rectP1.y == targetRectP1.y);
    
    if(bRectsAreEqual == false) {
        rectP0 += (targetRectP0 - rectP0) * easeAmount;
        rectP1 += (targetRectP1 - rectP1) * easeAmount;
        
        if(ABS(targetRectP0.x - rectP0.x) < kEasingStop) {
            rectP0.x = targetRectP0.x;
        }
        
        if(ABS(targetRectP0.y - rectP0.y) < kEasingStop) {
            rectP0.y = targetRectP0.y;
        }
        
        if(ABS(targetRectP1.x - rectP1.x) < kEasingStop) {
            rectP1.x = targetRectP1.x;
        }
        
        if(ABS(targetRectP1.y - rectP1.y) < kEasingStop) {
            rectP1.y = targetRectP1.y;
        }
        
        rect.x = rectP0.x;
        rect.y = rectP0.y;
        rect.width = rectP1.x - rectP0.x;
        rect.height = rectP1.y - rectP0.y;
        
        bChanged = true;
    }
    
    return bChanged;
}

float ofAngle(const ofVec3f & vec) {
    ofVec2f v(vec);
    return ofAngle(v);
}

float ofAngle(const ofVec2f & vec) {
    float ang = vec.angle(ofVec2f(0, -1));
    ang -= 180;
    ang *= -1;
    return ang;
}

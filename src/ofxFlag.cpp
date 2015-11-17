//
//  ofxFlag.cpp
//  Created by Lukasz Karluk on 17/11/2015.
//  http://codeoncanvas.cc
//

#include "ofxFlag.h"

ofxFlag::ofxFlag() {
    bValue = false;
    bValueNew = false;
    bValueChanged = false;
    bDirty = false;
}

void ofxFlag::update() {
    bValueChanged = (bValue != bValueNew);
    bValue = bValueNew;
    bDirty = false;
}

void ofxFlag::operator = (const bool & value) {
    setValue(value);
}

bool ofxFlag::operator == (const bool & value) {
    return (getValue() == value);
}

void ofxFlag::setValue(bool value) {
    bValueNew = value;
    bDirty = true;
}

bool ofxFlag::getValue() {
    if(bDirty == true) {
        return bValueNew;
    }
    return bValue;
}

bool ofxFlag::hasChanged() {
    if(bDirty == true) {
        return (bValue != bValueNew);
    }
    return bValueChanged;
}

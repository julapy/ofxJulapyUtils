/*
 *  ofxScreenGrabUtil.cpp
 *  openFrameworks
 *
 *  Created by lukasz karluk on 3/07/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxScreenGrabUtil.h"

ofxScreenGrabUtil :: ofxScreenGrabUtil()
{
	//
}

ofxScreenGrabUtil :: ~ofxScreenGrabUtil()
{
	//
}

void ofxScreenGrabUtil :: setup()
{
	setup( "" );
}

void ofxScreenGrabUtil :: setup( string path )
{
	ofRectangle	rect;
	rect.x		= 0;
	rect.y		= 0;
	rect.width	= ofGetWidth();
	rect.height	= ofGetHeight();
	
	setup( path, rect );
}

void ofxScreenGrabUtil :: setup( string path, const ofRectangle& rect )
{
	fileName		= ofToDataPath( path );
	
	saveArea.x		= rect.x;
	saveArea.y		= rect.y;
	saveArea.width	= rect.width;
	saveArea.height	= rect.height;
	
	reset();
}

void ofxScreenGrabUtil :: setPause( bool value )
{
	recording = !value;
}

void ofxScreenGrabUtil :: togglePause()
{
	recording = !recording;
}

void ofxScreenGrabUtil :: save()
{
	if( !recording )
		return;
	
	image.grabScreen( saveArea.x, saveArea.y, saveArea.width, saveArea.height );
	
	string imageFileNameStr = fileName;
	char imageFileName[ 255 ];
	sprintf( imageFileName, "frame_%02d%02d%02d_%05d.png", ofGetYear() % 1000, ofGetMonth(), ofGetDay(), counter );
	imageFileNameStr.insert( imageFileNameStr.size(), imageFileName );

	image.saveImage( imageFileNameStr );
	
	counter++;
}

void ofxScreenGrabUtil :: reset ()
{
	recording	= false;
	counter		= 0;
}

bool ofxScreenGrabUtil :: isRecording()
{
	return recording;
}

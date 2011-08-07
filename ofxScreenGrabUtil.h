/*
 *  ofxScreenGrabUtil.h
 *  openFrameworks
 *
 *  Created by lukasz karluk on 3/07/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofMain.h"

class ofxScreenGrabUtil
{
public :
	
	 ofxScreenGrabUtil();
	~ofxScreenGrabUtil();
	
	void setup			();
	void setup			( string path );
	void setup			( string path, const ofRectangle& rect );

	void save			();
	void setPause		( bool value );
	void togglePause	();
	void reset			();
	bool isRecording	();
	
private :
	
	ofImage		image;
	ofRectangle saveArea;
	
	string		fileName;
	bool		recording;
	int			counter;
};
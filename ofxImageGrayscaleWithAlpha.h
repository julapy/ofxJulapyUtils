//
//  ofxImageGrayscaleWithAlpha.h
//  PYPEarth
//
//  Created by lukasz karluk on 17/01/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofImage.h"

class ofxImageGrayscaleWithAlpha : public ofImage
{
public:
    
    /**
     *  implemented based on the information in this link,
     *  http://stackoverflow.com/questions/4624998/convert-image-to-black-white-or-sepia-in-c-sharp
     */
    
    void convertToGreyscaleWithAlpha ()
    {
        if( type != OF_IMAGE_COLOR_ALPHA )
            setImageType( OF_IMAGE_COLOR_ALPHA );
        
        ofPixels &pixels = getPixelsRef();

        int t = width * height;
        for( int i=0; i<t; i++ )
        {
            int y = 0.299 * pixels[ i * 4 + 0 ] + 
                    0.587 * pixels[ i * 4 + 1 ] + 
                    0.114 * pixels[ i * 4 + 2 ];
            
            pixels[ i * 4 + 0 ] = y;
            pixels[ i * 4 + 1 ] = y;
            pixels[ i * 4 + 2 ] = y;
        }
        
        setFromPixels( pixels );
    }
};
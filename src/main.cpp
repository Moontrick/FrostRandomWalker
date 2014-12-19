
/*****************************************************
 **  randomWalker_Coolest
 **  main.cpp
 **
 **  Created by Marcus Novak on 8/29/13.
 **
 *****************************************************/


#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    
    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1440,900, OF_FULLSCREEN);
	ofRunApp( new testApp());
    
}

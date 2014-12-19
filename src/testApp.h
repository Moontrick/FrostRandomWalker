
/*****************************************************
 **  randomWalker_Coolest
 **  testApp.h
 **
 **  Created by Marcus Novak on 8/29/13.
 **
 **  Finishing Touches:
 **       1. Instead just spawning in the middle, I randomized
 **          the spawn position
 **       2. Created a "reset" function.  Pressing any key
 **          will now clear the FBO and respawn the walkers
 **          at a new random point.
 **       3. Generally refactored to make the code more readable
 *****************************************************/


#pragma once

#include "ofMain.h"
#include "Walker.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed( int key );
    void setFrostWalkers();
    
    Walker walker, walker2, walker3, walker4, walker5, walker6;
    vector <Walker> walkers;
    
    int count;
    bool resetFrostPos;
    
    ofFbo fbo;
    
};

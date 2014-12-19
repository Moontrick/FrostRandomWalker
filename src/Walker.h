
/*****************************************************
 **  randomWalker_Coolest
 **  Walker.h
 **
 **  Created by Marcus Novak on 8/29/13.
 **
 **  Finishing Touches:
 **       1. I am now not only keeping track of the Walkers
 **          current position but it's previous position as well
 **       2. Those 2 points are used to draw a line instead of
 **          drawing a circle as the previous versions have done.
 **       3. The app now checks to see if moving to the next randomly
 **          generated position would put it outside of the screen.
 **          If so the walker does not move and instead waits for
 **          the next random position until it gets a valid one.
 **       4. Added a subtle "speeding up" to the frosty effect
 **          as time passes with the "scale" variable.
 *****************************************************/


#include "ofMain.h"

#ifndef randomWalker_1_0_Walker_h
#define randomWalker_1_0_Walker_h

class Walker {
    
public:
    
    void setup( float _x, float _y );
    void update();
    void draw();
    void setColor( ofColor _color );
    
    float x, y, oldX, oldY;
    float scale;
    ofColor color;
    
};

#endif


/*****************************************************
 **  randomWalker_Coolest
 **  Walker.cpp
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


#include "Walker.h"


void Walker::setup( float _x, float _y ) {
    
    x = _x;
    y = _y;
    oldX = x;
    oldY = y;
    scale = 0.0f;
    
}


void Walker::update() {
    
    oldX = x;
    oldY = y;
    
    float randStepX = ofRandom( -( 2.5 + scale ), 2.5 + scale );
    float randStepY = ofRandom( -( 2.5 + scale ), 2.5 + scale );
    
    bool outOfBounds = ( x + randStepX < 0 ) || ( x + randStepX > ofGetWidth() ) ||
    ( y + randStepY < 0 ) || ( y + randStepY > ofGetHeight() );
    
    if ( !outOfBounds ){
        
        x += randStepX;
        y += randStepY;
        
    }
    
    scale += 0.0002f;
    
}


void Walker::draw() {
    
    ofEnableAlphaBlending();
    ofSetColor( color );
    ofLine( oldX, oldY, x, y );
    ofDisableAlphaBlending();
    
}


void Walker::setColor( ofColor _color ){
    
    color = _color;
    
}













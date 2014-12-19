
/*****************************************************
 **  randomWalker_Coolest
 **  testApp.cpp
 **
 **  Created by Marcus Novak on 8/29/13.
 **
 **  Finishing Touches:
 **       1. Instead of just spawning in the middle, I randomized
 **          the spawn position
 **       2. Created a "reset" function.  Pressing any key
 **          will now clear the FBO and respawn the walkers
 **          at a new random point.
 **       3. Generally refactored to make the code more readable
 *****************************************************/


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground( 0 );
    ofHideCursor();
    
    int numWalkers = 200;
    
    for ( int i = 0; i < numWalkers; i++ ) {
        
        Walker newWalker;
        walkers.push_back( newWalker );
        
    }
    
    ofColor darkBlue = ofColor( 35, 62, 236, 10 );
    ofColor lightBlue = ofColor( 141, 155, 245, 10 );
    ofColor greenBlue = ofColor( 78, 243, 238, 10 );
    
    ofPoint randPoint = ofPoint( ofRandom( 200, ofGetWidth() - 200 ), ofRandom( 200, ofGetHeight() - 200 ) );
    
    float randColor;
    vector <Walker> ::iterator it;
    for ( it = walkers.begin(); it != walkers.end(); ++it ) {
        
        float randPosX = ofRandom( randPoint.x - 50, randPoint.x + 50 );
        float randPosY = ofRandom( randPoint.y - 50, randPoint.y + 50 );
        
        it->setup( randPosX, randPosY );
        
        randColor = ofRandom( 1 );
        if ( ( randColor > 0.8 ) ) it->setColor( darkBlue );
        else if ( ( randColor > 0.45 ) ) it->setColor( lightBlue );
        else it->setColor( greenBlue );
        
    }
    
    fbo.allocate( ofGetWidth(), ofGetHeight() );
    fbo.begin();
    ofClear(0,0,0,0);
    fbo.end();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    vector <Walker> ::iterator it;
    for ( it = walkers.begin(); it != walkers.end(); ++it ) {
        
        it->update();
        
    }
    
    if ( resetFrostPos ) {
        
        ofPoint randPoint = ofPoint( ofRandom( 0, ofGetWidth() ), ofRandom( 0, ofGetHeight() ) );
        
        for ( it = walkers.begin(); it != walkers.end(); ++it ) {
            
            float randPosX = ofRandom( randPoint.x - 50, randPoint.x + 50 );
            float randPosY = ofRandom( randPoint.y - 50, randPoint.y + 50 );
            
            it->setup( randPosX, randPosY );
            
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    fbo.begin();
    
    vector <Walker> ::iterator it;
    for ( it = walkers.begin(); it != walkers.end(); ++it ) {
        
        it->draw();
        
    }
    
    if ( resetFrostPos ){
        
        ofClear( 0, 0, 0, 0 );
        resetFrostPos = false;
        
    }
    
    fbo.end();
    
    fbo.draw( 0, 0 );
    
    ofSetColor( 255 );
    int FPS = ofGetFrameRate();
    string msg = "FPS: " + ofToString( FPS );
    ofDrawBitmapString( msg, 30, 30 );
    
}


//--------------------------------------------------------------
void testApp::keyPressed( int key ){
    
    resetFrostPos = true;
    
}





















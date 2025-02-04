#pragma once

#include "ofMain.h"

#include "ofxPonk.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofxPonk ponk_1;
    ofxPonk ponk_2;
    ofxPonk ponk_3;
    ofPolyline poly_1;
    ofPolyline poly_2;
    ofPolyline poly_3;
    ofPolyline poly_4;
    
    vector<ofColor> poly_4_colors;

};

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ponk_1.setup("stream_1", 0);
    ponk_2.setup("stream_2", 1, "localhost", PONK_DATA_FORMAT_XYRGB_U16);
    ponk_3.setup("stream_3", 2);
}

//--------------------------------------------------------------
void ofApp::update(){
    ponk_1.newFrame();
    ponk_2.newFrame();
    ponk_3.newFrame();

    
    // draw polyline: width -1 to 1 and height -1 to 1
    poly_1.clear();
    poly_1.arc(glm::vec3(0,0,0), 0.5, 0.5, 0, 360, true, (ofGetFrameNum()/20)%15+3);
    
    poly_2.clear();
    poly_2.arc(glm::vec3(0,0,0), 0.6, 0.6, 0, 360, true, (ofGetFrameNum()/20)%5+3);
    
    poly_3.clear();
    poly_3.addVertex(glm::vec3(ofRandom(-.5, 0.5),ofRandom(-.5, 0.5), 0));
    
    poly_4.clear();
    poly_4_colors.clear();
    for(int i = 0; i < 10; i++){
        glm::vec3 point(ofSignedNoise(ofGetElapsedTimef(), 3*i), ofSignedNoise(ofGetElapsedTimef(), 45.4*i), 0);
        poly_4.addVertex(point);
        ofColor color(ofNoise(ofGetElapsedTimef(), 34.1*i) * 255,
                      ofNoise(ofGetElapsedTimef(), 22.2*i) * 255,
                      ofNoise(ofGetElapsedTimef(), 11.7*i) * 255);
        poly_4_colors.push_back(color);
    }
    
    ponk_1.add(poly_1, ofColor::orange);
    ponk_1.add(poly_2, ofColor::cyan, {{"MAXSPEED",2.f}});
    ponk_2.add(poly_3, ofColor::blueViolet, {{"SNGLPTIN",30.f}});
    ponk_3.add(poly_4, poly_4_colors);

    ponk_1.sendFrame();
    ponk_2.sendFrame();
    ponk_3.sendFrame();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofScale(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofSetColor(ofColor::orange);
    poly_1.draw();
    ofSetColor(ofColor::cyan);
    poly_2.draw();
    ofSetColor(ofColor::blueViolet);
    poly_3.draw();
    
    ofMesh poly_4_mesh;
    poly_4_mesh.setMode( OF_PRIMITIVE_LINE_STRIP);

    for(int i = 0; i < poly_4.size(); i++){
        poly_4_mesh.addVertex(poly_4.getVertices()[i]);
        poly_4_mesh.addColor(poly_4_colors[i]);
        poly_4_mesh.addIndex(i);
    }
    poly_4_mesh.draw();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

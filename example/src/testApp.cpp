#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    tex.loadImage("text.png");
    tex.setAnchorPercent(.5, .5);
}

//--------------------------------------------------------------
void testApp::update()
{
    
}

//--------------------------------------------------------------
void testApp::draw()
{
    
    float hue = sin(ofGetElapsedTimef()) * PI;
    
    ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);
    if(tex.bAllocated())
    {
        ofxHueShader::beginShader(hue);
//        hueShader.begin(hue);
                tex.draw(0, 0);
//        hueShader.end();
        ofxHueShader::endShader();
    }
    
    ofDrawBitmapStringHighlight("hue: " + ofToString(hue), 0, tex.getHeight()*-.55);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

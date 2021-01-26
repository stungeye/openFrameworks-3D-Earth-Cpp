#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableAlphaBlending(); // Is this actually required?
    ofEnableDepthTest();      // Our texture won't map properly without this. 
    ofDisableArbTex();        // Also required for proper texture binding.

    // Set the camera distance we are aren't zoomed out.
    cam.setDistance(50);

    // Enable a light source
    light.enable();
    light.setPosition(cam.getPosition());
    light.lookAt(ofVec3f(0, 0, 0));
    
    // Load the image texture and sphere resolution.
    ofLoadImage(texture, "earth_high.png");
    sphereResolution = sphere.getResolution();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f cameraPos = cam.getPosition();
    ofVec3f lightPos = light.getPosition();
    ofVec3f delta = cameraPos - lightPos;

    // The light source position should move to match the 
    // position of the camera. Lagged by a factor of 50.
    if (delta.length() > 5) {
        light.setPosition(lightPos + delta / 50);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Enable EasyCam for mouse zoom and rotation.
    cam.begin();

    // Rotate the planet a little bit every frame.
    ofRotateYDeg(ofGetFrameNum() / 9.0);

    // Bind the texture to the sphere and draw it.
    texture.bind();
    sphere.draw();
    texture.unbind();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Increase and decrease the sphere resolution using the 9 and 0 keys.
    if (key == '9' && sphereResolution > 2) {
        sphereResolution--;
        sphere.setResolution(sphereResolution);
    } else if (key == '0' && sphereResolution < 40) {
        sphereResolution++;
        sphere.setResolution(sphereResolution);
    }
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

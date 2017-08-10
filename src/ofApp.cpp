#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;

//		fingerMovie.load("movies/test.mp4");
fingerMovie.load("movies/hotlimit.mp4");
	fingerMovie.setLoopState(OF_LOOP_NORMAL);
	fingerMovie.play();

	myFbo.allocate(1280, 720);
	myGlitch.setup(&myFbo);

}

//--------------------------------------------------------------
void ofApp::update(){
	fingerMovie.update();

	myFbo.begin();
	ofSetHexColor(0xFFFFFF);
	fingerMovie.draw(0,0);
	ofSetHexColor(0x000000);
	myFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);

	myGlitch.generateFx();
	myFbo.draw(0, 0);

//	ofSetHexColor(0x000000);
//	ofDrawBitmapString("press f to change",20,320);
//	if(frameByframe) ofSetHexColor(0xCCCCCC);
//	ofDrawBitmapString("mouse speed position",20,340);
//	if(!frameByframe) ofSetHexColor(0xCCCCCC); else ofSetHexColor(0x000000);
//	ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
//	ofSetHexColor(0x000000);
//
/*	ofDrawBitmapString("frame: " + ofToString(fingerMovie.getCurrentFrame()) + "/"+ofToString(fingerMovie.getTotalNumFrames()),20,380);
	ofDrawBitmapString("duration: " + ofToString(fingerMovie.getPosition()*fingerMovie.getDuration(),2) + "/"+ofToString(fingerMovie.getDuration(),2),20,400);
	ofDrawBitmapString("speed: " + ofToString(fingerMovie.getSpeed(),2),20,420);

	if(fingerMovie.getIsMovieDone()){
		ofSetHexColor(0xFF0000);
		ofDrawBitmapString("end of movie",20,440);
	}
*/

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
/*	switch(key){
		case 'f':
		frameByframe=!frameByframe;
		fingerMovie.setPaused(frameByframe);
		break;
		case OF_KEY_LEFT:
		fingerMovie.previousFrame();
		break;
		case OF_KEY_RIGHT:
		fingerMovie.nextFrame();
		break;
		case '0':
		fingerMovie.firstFrame();
		break;
	}
*/

	if (key == 'a') fingerMovie.setSpeed(3.0);
	if (key == 'd') fingerMovie.setSpeed(0.4);
	if (key == 's') fingerMovie.setSpeed(1.0);


	int movie_pos=fingerMovie.getCurrentFrame();

	if (key == 'f') fingerMovie.setFrame(movie_pos+100);
	if (key == 'g')  fingerMovie.setFrame(movie_pos-100);

	if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
	if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
	if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
	if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
	if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
	if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
	if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
	if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
	if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
	if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);

	if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
	if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
	if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
	if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
	if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
	if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
	if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
	if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
	if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
	if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
	if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
	if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
	if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
	if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
	if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
	if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);

	if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
	if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
	if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
	if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
	if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
	if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
	if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);


//	else if (key == 's') fingerMovie.setSpeed(1.0);



}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//	if(!frameByframe){
//		int width = ofGetWidth();
//		float pct = (float)x / (float)width;
//		float speed = (2 * pct - 1) * 5.0f;
//		fingerMovie.setSpeed(speed);
//	}


}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//	if(!frameByframe){
//		int width = ofGetWidth();
//		float pct = (float)x / (float)width;
//		fingerMovie.setPosition(pct);
//	}


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//	if(!frameByframe){
//		fingerMovie.setPaused(true);
//	}

}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//	if(!frameByframe){
//		fingerMovie.setPaused(false);
//	}

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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	auto size = 15;	
	for (int i = 0; i < 6; i += 1) {

		if (i < 4) {

			ofRotateY(90);
			for (int x = -150; x < 150; x += size) {

				for (int y = -150; y < 150; y += size) {

					auto location = glm::vec3(x, y, 150);
					float angle = PI * 0.5 * i;
					auto rotation = glm::rotate(glm::mat4(), angle, glm::vec3(0, 1, 0));
					auto noise_location = glm::vec4(location, 0) * rotation;

					auto noise_value = ofNoise(noise_location.x * 0.005, noise_location.y * 0.005, noise_location.z * 0.005, ofGetFrameNum() * 0.008);
					if (noise_value > 0.5) {

						ofFill();
						ofSetColor(239);
						ofDrawRectangle(location, size - 1, size - 1);

						ofNoFill();
						ofSetColor(39);
						ofDrawRectangle(location, size, size);
					}
				}
			}
		}
		else {

			ofRotateX(i == 4 ? 90 : 180);
			for (int x = -150; x < 150; x += size) {

				for (int y = -150; y < 150; y += size) {

					auto location = glm::vec3(x, y, 150);
					float angle = i == 4 ? PI * 0.5 : PI * 0.5 * 3;
					auto rotation = glm::rotate(glm::mat4(), angle, glm::vec3(1, 0, 0));
					auto noise_location = glm::vec4(location, 0) * rotation;

					auto noise_value = ofNoise(noise_location.x * 0.005, noise_location.y * 0.005, noise_location.z * 0.005, ofGetFrameNum() * 0.008);
					if (noise_value > 0.5) {

						ofFill();
						ofSetColor(239);
						ofDrawRectangle(location, size - 1, size - 1);

						ofNoFill();
						ofSetColor(39);
						ofDrawRectangle(location, size, size);
					}
				}
			}

		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
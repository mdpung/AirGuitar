#include <MyoController.h>

#define WAVEOUT_PIN 7
#define FINGERSSPREAD_PIN 6
#define WAVEIN_PIN 5
#define FIST_PIN 4
#define DOUBLETAP_PIN 12
#define TRANSISTOR_ACTIVE HIGH
#define TRANSISTOR_INACTIVE LOW

MyoController myo = MyoController();

void setup() {
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  
  myo.initMyo();
}

void loop() {
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      digitalWrite(FIST_PIN,HIGH); 
      digitalWrite(WAVEIN_PIN,HIGH);
      digitalWrite(WAVEOUT_PIN,HIGH);
      digitalWrite(FINGERSSPREAD_PIN,HIGH);
      digitalWrite(DOUBLETAP_PIN,HIGH);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN,LOW);
      break;
    case fist:
      digitalWrite(FIST_PIN,LOW);
      break;
    case waveIn:
      digitalWrite(WAVEIN_PIN,LOW);
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,LOW);
      break;
   } 
   delay(1);
}

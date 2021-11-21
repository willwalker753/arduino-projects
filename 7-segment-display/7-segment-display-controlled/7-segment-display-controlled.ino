// pin numbers
const int ledA = 9;
const int ledB = 8;
const int ledC = 5;
const int ledD = 6;
const int ledE = 7;
const int ledF = 10;
const int ledG = 11;
const int ledDP = 4;
const int vrY = 0;

// mapping to display numbers
// A,B,C,D,E,F,G,DP
const int allPins[8] = {9,8,5,6,7,10,11,4};
int curPinMapIndex = 0;
const int pinMap[][8] = {
  {ledA, ledB, ledC, ledD, ledE, ledF, -1, -1}, // 0
  {-1, ledB, ledC, -1, -1, -1, -1, -1}, // 1
  {ledA, ledB, -1, ledD, ledE, -1, ledG, -1}, // 2
  {ledA, ledB, ledC, ledD, -1, -1, ledG, -1}, // 3
  {-1, ledB, ledC, -1, -1, ledF, ledG, -1}, // 4
  {ledA, -1, ledC, ledD, -1, ledF, ledG, -1}, // 5
  {ledA, -1, ledC, ledD, ledE, ledF, ledG, -1}, // 6
  {ledA, ledB, ledC, -1, -1, -1, -1, -1}, // 7
  {ledA, ledB, ledC, ledD, ledE, ledF, ledG, -1}, // 8
  {ledA, ledB, ledC, ledD, -1, ledF, ledG, -1}, // 9
};

void setup() {
  Serial.begin(9600);
  for(int i=0; i<8; i++) {
    pinMode(allPins[i], OUTPUT);
  }
  updateDisplay();
}

void updateDisplay() {
  if(curPinMapIndex < 0) {
    curPinMapIndex = 9;
  }
  else if(curPinMapIndex > 9) {
    curPinMapIndex = 0;
  }
  for(int b=0; b<8; b++) {
    delay(10);
    if(pinMap[curPinMapIndex][b] > -1) {
      digitalWrite(pinMap[curPinMapIndex][b], HIGH);
    } 
    else {
      digitalWrite(allPins[b], 0);
    }
  }
}

void loop() {
  const int vrYVal = analogRead(vrY);
  if(vrYVal > 550) {
    curPinMapIndex--;
  }
  else if(vrYVal < 450) {
    curPinMapIndex++;
  }
  updateDisplay();
  const int delayTime = 400-(abs(vrYVal-504)/2); // speeds up when joystick is moved further
  delay(delayTime);
}

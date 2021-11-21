// pin numbers
const int ledA = 9;
const int ledB = 8;
const int ledC = 5;
const int ledD = 6;
const int ledE = 7;
const int ledF = 10;
const int ledG = 11;
const int ledDP = 4;

// mapping to display numbers
// A,B,C,D,E,F,G,DP
const int allPins[8] = {9,8,5,6,7,10,11,4};
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
}

void loop() {
  for(int a=0; a<10; a++) {
    for(int b=0; b<8; b++) {
      delay(10);
      Serial.println(pinMap[a][b]);
      if(pinMap[a][b] > -1) {
        digitalWrite(pinMap[a][b], HIGH);
      } 
      else {
        digitalWrite(allPins[b], 0);
      }
    }
    delay(500);
  }
}

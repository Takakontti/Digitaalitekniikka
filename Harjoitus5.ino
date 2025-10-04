const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int speed=1000;

void OFF() {
  for(int i=0; i<8; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
  delay(100);
}

void H() {
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(8, HIGH);
  delay(speed);
}

void O() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(speed);
}

void N() {
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  delay(speed);
}

void T() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(speed);
}

void I() {
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(speed);
}

void kolmipiste() {
  for(int i=0; i<3; i++) {
    digitalWrite(9, HIGH);
    delay(400);
    digitalWrite(9, LOW);
    delay(100);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i<8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    Serial.print("Pin ");
    Serial.print(segmentPins[i]);
    Serial.println(" Ready");
  }
  for(int i=0; i<8; i++) {
    digitalWrite(segmentPins[i], HIGH);
    delay(100);
    digitalWrite(segmentPins[i], LOW);
  }
}

void loop() {
  for(int i=0; i<10; i++) {
    H();
    OFF();
    O();
    OFF();
    N();
    OFF();
    T();
    OFF();
    T();
    OFF();
    I();
    OFF();
    kolmipiste();
    delay(speed);
    //vähennetään viivettä 20%
    speed=(speed-(speed/5));
  }
  for(int i=0; i<8; i++) {
    digitalWrite(segmentPins[i], HIGH);
    delay(100);
    digitalWrite(segmentPins[i], LOW);
  }
  speed=1000;
}

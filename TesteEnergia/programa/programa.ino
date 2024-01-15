

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A2));
  delayMicroseconds(1000);
}
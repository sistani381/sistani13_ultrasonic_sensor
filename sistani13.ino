long duration;
int distance;
const int trig = 9;
const int echo = 10;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  distance = calculateDistance();
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
int calculateDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

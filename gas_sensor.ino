int buzzer = 10;
int smoke = A0;
// Your threshold value
int sensorThres = 400;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smoke, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smoke);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
  }
  else
  {
    noTone(buzzer);
  }
  delay(1000);
}

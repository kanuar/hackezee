int blue=4;

void setup () {
  pinMode (blue,OUTPUT);
  Serial.begin (9600);}
 
void loop() {
  // read the input on analog pin 0:
  int value = analogRead(A0);
  
  if (value > 500) {
    Serial.println("Very heavy Rain");
    tone(blue,2000);
    delay(2000);
    noTone(blue);}
  else if ((value > 300) && (value <= 500)) {
    Serial.println("AVERAGE Rain");
    tone(blue,1000);
    delay(2000);
    noTone(blue);}
    
    
  else{
    Serial.println("Dry Weather");
    delay(100);
  }
  }

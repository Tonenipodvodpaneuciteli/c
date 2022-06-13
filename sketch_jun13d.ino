void setup() {
  // nothing to do here
}
void loop() {
  int buzzer = 10;          // module connected to pin 10 of Arduino
  // play a melody to the KY-006 module
  
  tone(buzzer, 262, 250);   // play a tone
  delay(325);               // pause code
  noTone(buzzer);           // stop playing tone
  tone(buzzer, 196, 125);
  delay(162);
  noTone(buzzer);
  tone(buzzer, 196, 250);
  delay(325);
  noTone(buzzer);
  tone(buzzer, 220, 250);
  delay(325);
  noTone(buzzer);
  tone(buzzer, 196, 250);
  delay(325);
  noTone(buzzer);
  tone(buzzer, 0, 250);
  delay(325);
  noTone(buzzer);
  tone(buzzer, 247, 250);
  delay(325);
  noTone(buzzer);
  tone(buzzer, 262, 250);
  delay(325);
  noTone(buzzer);
  delay(1000);
}

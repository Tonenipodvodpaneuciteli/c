
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  }
void loop() {
if (digitalRead(3)== HIGH){
Serial.println("detekce magnetu");
     }
     if (digitalRead(3)== LOW){
     Serial.println("nedetekování magnetu");
     }}
  

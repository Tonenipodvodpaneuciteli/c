int x;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}
void loop() {
if (digitalRead(2)== HIGH){
x=analogRead(A0);
Serial.print("Magnet DETEKOVÁN, ");
 Serial.println(x);
 }
     if (digitalRead(2)== LOW){
      x=analogRead(A0);
    
     Serial.print("Magnet NE DETEKOVÁN, ");
  Serial.println(x);
 }
 delay(50);
}












     


  



  

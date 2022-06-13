//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#define trigPin 13      // Trigger Pin
#define echoPin 12      // Echo Pin
#define ledMin 11     // Červena LED na pinu 11
#define ledMax 10     // Zelena LED na pinu 10
int maximumRange = 200;       // maximální vzdálenost
int minimumRange = 0;       // minimální vzdálenost
long duration, distance;    // Vypočítání vzdálenosti
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin (9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(ledMin, OUTPUT);
  pinMode(ledMax, OUTPUT);

 
}


void loop()
{
  digitalWrite(13, LOW);
  delayMicroseconds(2);
  digitalWrite(13, HIGH);
  delayMicroseconds(10);
  digitalWrite(13, LOW);
  duration = pulseIn(12, HIGH);
  distance = (duration/2) / 29.1;   //vypočítání v cm
  
  // To je místo, kde LED rozsvítíme a zhasneme.
if (distance < 4) {         // rozsvítíme červenou LED, vzdálenost do 4cm 
  digitalWrite(ledMin,HIGH);    // Když rozsvítíme červenou, zelenou musíme zhasnout 
  digitalWrite(ledMax,LOW);
} else if (distance > 200) {        // rozsvítíme zelenou LED, vzdálenost > 200cm
      digitalWrite(ledMax,HIGH);    // Když rozsvítíme zelenou, červenou musíme zhasnout
  digitalWrite(ledMin,LOW);
}
  else {          // normální provoz, vzdálenost od 4 do 200cm, nesviti nic
    digitalWrite(ledMin,LOW);
    digitalWrite(ledMax,LOW);
  }
  if (distance >= maximumRange  || distance <= minimumRange){
  Serial.println("Mimo dosah");
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Vzdalenost:");
   lcd.setCursor(3,3);
  lcd.print("mimo dosah");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
      lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Vzdalenost:");
   lcd.setCursor(6,3);
  lcd.print(distance);
   lcd.setCursor(9,3);
  lcd.print("cm");
  }
  //počkání 500ms
  delay(500);
}

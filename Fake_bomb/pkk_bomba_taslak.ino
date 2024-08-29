#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int b;

#define buton 8
#define buzzer 9
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buton ,INPUT);

pinMode(buzzer, OUTPUT);
  lcd.begin();
}

void loop() {
int deger = digitalRead(buton);




 if(deger == HIGH){
  for(b=60; b>=0 ; b--){
    
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.print(" Patlamaya Son:");
  lcd.setCursor(7, 1);
  lcd.print(b);
  tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
 } 
 else if(b == 1){
    lcd.clear();
  lcd.backlight();
  lcd.print("patladı");
  delay(2000);
 }
 else{
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.print("Butona Basiniz");
 }
}

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int ledR = 7;
int bottone = 8;
int buzzer = 9;
int scelta = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(bottone, INPUT);
millis();
pinMode(buzzer,OUTPUT);
analogWrite(ledR, OUTPUT);
lcd.begin(16,2);
lcd.print("arduino Timer");}

void loop() {
  // put your main code here, to run repeatedly:
start();
riflessiConLed();
riflessiConBuzzer();


}

void start()
{
  lcd.setCursor(0,0);
  lcd.print("riflessi");
  lcd.setCursor(0,1);
  lcd.print("premi il bottone");
  lcd.setCursor(0,1);
  lcd.print("premi il bottone per iniziare");

  while (digitalRead(bottone) == LOW)
  {
    
  }
  lcd.setCursor(0,0);
  lcd.print("avvio del test");

}
void riflessiConLed()
{
  lcd.setCursor(0,0);
  lcd.print("Primo avvio");
  lcd.setCursor(0,1);
  lcd.print("test con led");
  delay(2000);
  
  lcd.setCursor(0,0);
  lcd.print("Schiaccia il bottone");
  lcd.setCursor(0,0);
  lcd.print("accensione del led");
  lcd.setCursor(0,1);
  lcd.print("led rosso");
  delay(1500);
  lcd.clear();
  int tempo = random(500,10000);
  delay (tempo);
  digitalWrite(ledR, HIGH);
  delay(2000);
  digitalWrite(ledR, LOW); 
  lcd.print("Tempo test");
  delay(3000);
}
void riflessiConBuzzer()
{
  lcd.setCursor(0,0);
  lcd.print("secondo avvio");
  lcd.setCursor(0,1);
  lcd.print("accensione del buzzer");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("Schiaccia il bottone");
  lcd.setCursor(0,1);
  lcd.print("bottone all'accensione");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("accensione del buzzer");
  lcd.setCursor(0,1);
  lcd.print("suono");
  delay(2000);
  int tempo = random(500,5000);
  delay (tempo);
  tone(buzzer,500,1500);
  lcd.print("Tempo test");  
  delay(3000);
  

}

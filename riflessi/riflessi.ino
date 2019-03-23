#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
const int ledR = 12;
const int bottone = 13;
const int buzzer = 11;

long tempoLed = 0;
long tempoBuzzer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(bottone, INPUT);
  //millis();
  pinMode(buzzer,OUTPUT);
  analogWrite(ledR, OUTPUT);
  lcd.begin(16,2);
  lcd.print("Arduino Timer");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(bottone) == LOW);
  start();
  riflessiConLed();
  riflessiConBuzzer();
  stampaMedia();
  riavvioRiflessi();
}

void start()
{
  lcd.setCursor(0,0);
  lcd.print("Riflessi"); 
  lcd.setCursor(0,1);
  lcd.print("premi il bottone");
  while (digitalRead(bottone) == LOW) {};
  lcd.setCursor(0,0);
  lcd.print("Avvio del test");

}
void riflessiConLed()
{
  lcd.setCursor(0,1);
  lcd.print("test con led");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Schiaccia il bottone");
  lcd.print("led rosso");
  delay(1500);
  lcd.clear();
  long tempo = random(500,1000);
  long tempoMillis = millis() + tempo;
  delay (tempo);
  digitalWrite(ledR, HIGH);
  delay(200);
  digitalWrite(ledR, LOW); 
  while (digitalRead(bottone) == LOW) {};
  tempoLed = millis() - tempoMillis;
  
  lcd.clear();
  lcd.print("Tempo test: ");
  lcd.print(tempoLed);
  delay(3000);
}

void riflessiConBuzzer()
{
  lcd.setCursor(0,1);
  lcd.print("test con led");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Schiaccia il bottone");
  lcd.print("led rosso");
  delay(1500);
  lcd.clear();
  long tempo = random(500,1000);
  long tempoMillis = millis() + tempo;
  delay (tempo);
  tone(buzzer,1000,300); 
  while (digitalRead(bottone) == LOW);
  tempoBuzzer = millis() - tempoMillis;
  lcd.clear();
  lcd.print("Tempo test: ");
  lcd.print(tempoBuzzer);
  delay(3000);
}

void stampaMedia()
{

  lcd.setCursor(0,0);
  lcd.print("Media :");
  long media = tempoBuzzer + tempoLed;
  media = media / 2.0;
  lcd.print(media);
  delay(3000);
  if(media > 250)
  {
  lcd.setCursor(0,1);
  lcd.print("Non hai passato il test");
  delay(3000);
  }
  if(media < 250)
  {
  lcd.setCursor(0,1);
  lcd.print(" Hai passato il test");
  delay(3000);
  }
}
void riavvioRiflessi()
{
    setup();
}

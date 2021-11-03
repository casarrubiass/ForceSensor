#include<LiquidCrystal.h>
int sensorPin=A1;
float Force=0;
float gms=0;
float N=0;
float R=0;
float Vout=0;
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(sensorPin,INPUT);

}
void loop()
{
  Force=analogRead(sensorPin);
  Vout=(Force*5)/1023;
  R=10000*((5/Vout)-1); 
  N=pow((R/5997.8),-1.428571);
  gms=N*102;
  lcd.setCursor(0,0);
  lcd.print("Fuerza: ");
  lcd.print(N);
  lcd.print(" N");
  lcd.setCursor(0,1);
  lcd.print("Peso: ");
  lcd.print(gms);
  lcd.print(" g");
}


#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#define rx 2
#define tx 3
#define tempSensor A0
#define pirSensor 4

SoftwareSerial mySerial(rx, tx);
LiquidCrystal lcd(13,12,11,10,9,8);

int c;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin(16,2);
  pinMode(pirSensor,INPUT);
  RecieveMessage();
}

void loop()
{
  if(tempCheck()>40)
  {
    SendMessage("Temperature Sensor", tempCheck(), "Fire Alart");
    lcd.clear();
    while(tempCheck()>40)
    {
      String a = "Temp is High: "+String(tempCheck())+"*C";
      String b = "PIR State: "+String(pirCheck());
      lcd.setCursor(0,0);
      lcd.print(a);
      lcd.setCursor(0,1);
      lcd.print(b);
      delay(100);
    }
    lcd.clear();
  }
    
  if(pirCheck()==1)
  {
    SendMessage("PIR Sensor", pirCheck(), "Theft Alart");
    while(pirCheck()==1)
    {
      String a = "Temp Value: "+String(tempCheck())+"*C";
      String b = "Theft Alart: "+String(pirCheck());
      lcd.setCursor(0,0);
      lcd.print(a);
      lcd.setCursor(0,1);
      lcd.print(b);
      delay(100);
    }
    lcd.clear();
  }
  c++;

  if(c>10)
  {
    String a = "TEMP: "+String(tempCheck())+"*C";
    String b = "PIR: "+String(pirCheck());
    Serial.println(a);
    Serial.println(b);
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.setCursor(0,1);
    lcd.print(b);
    c=0;
  }
  delay(100);
}

void SendMessage(String sensor, int value, String msg)
{
  String toSend = "Msg:-> Sensor: " + String(sensor) + ", Value = " + String(value) + ", Status: " + String(msg);
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917418569631\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println(toSend);// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void RecieveMessage()
{
  mySerial.println("AT+CMGF=1");
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
}

int tempCheck()
{
  int tempS = analogRead(tempSensor);
  tempS = (tempS*4.88);
  tempS = tempS/10;
  return tempS;
}

int pirCheck()
{
  return digitalRead(pirSensor);
}

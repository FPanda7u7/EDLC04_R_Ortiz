#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_AUTH_TOKEN            "LSQBvKDy5YJVXFbEQTuvXlC8HgurI2ip"
#define BLYNK_PRINT Serial

#include <SoftwareSerial.h>
SoftwareSerial SerialBLE(6, 7); // RX, TX
#include <BlynkSimpleSerialBLE.h>

char auth[] = BLYNK_AUTH_TOKEN;

#include <Servo.h>
Servo servo;
WidgetLCD lcd(V1);
int R_servo = 0;
int RA_servo = 0;

BLYNK_WRITE(V3)
{
  Rservo = param.asInt();
  if(RA_servo != R_servo)
  {
    lcd.clear();
    servo.write(R_servo); 
  }
  RA_servo = R_servo;
}

void setup()
{
  Serial.begin(9600);
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  
  servo.attach(9);
  lcd.clear();
  servo.write(0); 
  Serial.println("Waiting for connections...");
}

void loop()
{
  lcd.print(4, 0, String(R_servo));
  Blynk.run();
}

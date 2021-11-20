#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_AUTH_TOKEN            "LSQBvKDy5YJVXFbEQTuvXlC8HgurI2ip"
#define BLYNK_PRINT Serial

#include <SoftwareSerial.h>
SoftwareSerial SerialBLE(6, 7); // RX, TX
#include <BlynkSimpleSerialBLE.h>

char auth[] = BLYNK_AUTH_TOKEN;

int pinA = 9;
int pinB = 10;
int pinC = 11;

void setup()
{
  Serial.begin(9600);

  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth); 
  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();
}

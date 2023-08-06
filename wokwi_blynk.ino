/*
  Blynk example
  You should get Auth Token in the Blynk App.
  You need to write the right wifiCredentials.
*/

/* Comment this out to disable prints and save space */
#define BLYNK_TEMPLATE_ID "TMPL-j1Zuy7O"
#define BLYNK_DEVICE_NAME "ESP32 Kontrol LED"
#define BLYNK_AUTH_TOKEN "147o2t44KSmCmN9xruDISlDVQzHGZWBu"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Wokwi-GUEST"; 
char pass[] = ""; 

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == 1)
  {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}

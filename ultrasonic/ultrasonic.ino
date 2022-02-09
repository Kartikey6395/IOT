/* Interface the given Ultrasonic sensor module with ESP module and WAP for “Object 
counting application and distance calculation 
Output: 
a) Show the output on serial terminal
b) Show on the cloud dashboard
*/

#include "ThingSpeak.h"
#include "WiFi.h"

#define LED_PIN 15
char ssid[] = "Ktmobile";
char pass[] = "7017318604Kt";
const int trigger = 16;
const int echo = 2;
int Count =0;
long T;
float distanceCM;
WiFiClient client;
//thingspeak details
unsigned long myChannelField =1649427 ;
const int ChannelField1 = 1;
const int ChannelField2 = 2;
const char * myWriteAPIKey = "ZCGYFZWWKWT7FHDB";
void setup()
{
  pinMode(LED_PIN,OUTPUT);
  //pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);

}
void loop()
{
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("attepting to connect to ssid");
    Serial.println(ssid);
    while(WiFi.status()!= WL_CONNECTED)
    {
      WiFi.begin(ssid,pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nconnected");
  }

digitalWrite(trigger , LOW);
delay(1);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
//digitalWrite(echo , LOW);
digitalWrite(trigger , LOW);
//digitalWrite(echo, HIGH);
//delaymicrosecond(5);
T = pulseIn(echo, HIGH);
distanceCM = (T * 0.034)/2;
if(distanceCM<20)
{
  digitalWrite(LED_PIN, HIGH);
  Count++;
}
else
digitalWrite(LED_PIN, LOW);
Serial.print("distance in cm:");
Serial.println(distanceCM);
Serial.print("Count\n");
Serial.println(Count);

ThingSpeak.writeField(myChannelField,ChannelField1,distanceCM,myWriteAPIKey);
ThingSpeak.writeField(myChannelField,ChannelField2,Count,myWriteAPIKey);
//delay(1000);
}
#include <ThingSpeak.h>

#include "ThingSpeak.h"
#include "WiFi.h"
//#include <Wire.h>  //Include Library for HTU21D


//-------Enter your WiFi Details------//
char ssid[] = "Ktmobile";  //SSID
char pass[] = "7017318604Kt";  //Password
//-----------------------------------//
WiFiClient client;
unsigned long myChannelField = 1646218; //Channel ID
const int ChannelField1 = 1; //for led
const int ChannelField2 = 2; //for count
const char * myWriteAPIKey = "QVAFWTPZ5QLY3XYO"; //Your Write API Key
//-----------------------------------------------//
/*
 * PIR sensor tester
 */

int ledPin = 16; // choose the pin for the LED
int PIR = 2; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int count=0;
void setup() {
 pinMode(ledPin, OUTPUT); // declare LED as output
 pinMode(PIR, INPUT); // declare sensor as input

 Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop(){
 if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
  }
  while(WiFi.status()!= WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected.");
  //--------------------------------------------//
    
 val = digitalRead(PIR); // read input value
 if (val == HIGH) { // check if the input is HIGH
 digitalWrite(ledPin, HIGH); // turn LED ON
 if (pirState == LOW) {
 // we have just turned on
 Serial.println("Motion detected!");
 // We only want to print on the output change, not state
 pirState = HIGH;
 count++;
 }
 } else {
 digitalWrite(ledPin, LOW); // turn LED OFF
 if (pirState == HIGH){
 // we have just turned of
 Serial.println("Motion ended!");
 // We only want to print on the output change, not state
 pirState = LOW;
 
 }
 }
 ThingSpeak.writeField(myChannelField,ChannelField1, val, myWriteAPIKey);
 ThingSpeak.writeField(myChannelField,ChannelField2, count, myWriteAPIKey);
}

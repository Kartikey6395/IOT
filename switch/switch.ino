/*WAP to turn on the buzzer for 5 secs when the user button is pressed*/

#define LED_PIN_A 15
#define SW 22
bool val;
void setup() {

  // put your setup code here, to run once:
  pinMode(LED_PIN_A, OUTPUT);
  pinMode(SW, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(SW );
  if(val == 1)
  {
digitalWrite(LED_PIN_A,HIGH);
Serial.println("red_led_ON\n");
delay(5000);
  }
  else if(val== 0)
  {
  //digitalWrite(LED_PIN_B,LOW);


digitalWrite(LED_PIN_A,LOW);

Serial.println("red_led_OFF\n");
delay(500);

}
}

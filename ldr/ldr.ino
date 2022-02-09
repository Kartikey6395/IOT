#define LED_PIN_A 15
#define ADC_PIN 22
bool val;
void setup() {

  // put your setup code here, to run once:
  pinMode(LED_PIN_A, OUTPUT);
  pinMode(ADC_PIN, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(ADC_PIN );
  if(val == LOW)
  {
digitalWrite(LED_PIN_A,HIGH);
Serial.println("red_led_ON\n");
  }
  else if(val== HIGH)
  {
  //digitalWrite(LED_PIN_B,LOW);

//delay(1000);
digitalWrite(LED_PIN_A,LOW);

Serial.println("red_led_OFF\n");
//delay(1000);

}
}

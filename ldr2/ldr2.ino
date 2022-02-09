#define LED_PIN_A 15
#define ADC_PIN 22
int val;
void setup() {

  // put your setup code here, to run once:
  pinMode(LED_PIN_A, OUTPUT);
  pinMode(ADC_PIN, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(ADC_PIN );
  if(val >=2000)
  {
digitalWrite(LED_PIN_A,HIGH);
delay(1000);
Serial.println("red_led_ON \n",val);
  }
 
else
{

digitalWrite(LED_PIN_A,LOW);
delay(1000);
Serial.println("red_led_OFF\n",val);
}
}

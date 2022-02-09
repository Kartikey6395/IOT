//WAP to interface buzzer to ESP32

const int sw =16;
const int buzz =22;
int val;
void setup(){
  Serial.begin(9600);
pinMode(sw,INPUT);
pinMode(buzz,OUTPUT);
}
void loop(){
  val=digitalRead(sw);
  Serial.println(val);
  if(val==1){
    digitalWrite(buzz,1);
    Serial.println("switch pressed so led wil glow 5 sec\n");
    delay(5000);

  }
  else{
    digitalWrite(buzz,0);
    delay(200);
  }
}
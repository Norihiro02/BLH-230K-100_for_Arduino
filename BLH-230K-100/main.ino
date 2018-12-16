void setup() {
  Motor_init();
  byte rx_data[]={30,20};
  Serial.begin(9600);
  Serial.println(encode(rx_data));
}
void loop() {
 
  Motor_SetPose(0);
  delay(1000);
  for(int i;i<5;i++){
  Motor_SetPose((360/5)*i);
  delay(3000);
  Motor_SetPose(0);
  delay(3000);
  }
  
}

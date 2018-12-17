void setup() {
  Motor_init();
  Serial.begin(9600);
  //Motor_SetPose(0);
  //Serial.print(encode(rx_data));
}
void loop() {
 
  /*
  for (int i; i < 5; i++) {
    Motor_SetPose((360 / 5)*i);
    delay(3000);
    Motor_SetPose(0);
    delay(3000);
  }*/
  Motor_Rote(1);
  /*
  Motor_SetPose(wait_for_data());
  Motor_Stop();
  Serial.print(Motor_CurrentPose());
  Serial.print('\n');
*/
}

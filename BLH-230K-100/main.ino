void setup() {
  Motor_init();
  Serial.begin(9600);
  Motor_SetPose(0);
  //Serial.print(encode(rx_data));
}
void loop(){
  
  Motor_SetPose(wait_for_data());
  //Motor_Stop();
  Serial.print(Motor_CurrentPose());
  Serial.print('\n');
}

 #define RX_DATA_SIZE 4

int encode(byte data[])
{
  int output = 0;

  for (int i = 1; i <  RX_DATA_SIZE; i++) {
    output *= 10;
    output += data[i] - '0';
  }
  if (data[0] == '-') {
    output *= -1;
  }
  else if (data[0] == '+') {
  }
  return output;
}

int wait_for_data()
{
  byte rxData[RX_DATA_SIZE];
  int output = 0;
  while (RX_DATA_SIZE > Serial.available()); //4バイト受信するまで待機
  for (int i = 0; i < RX_DATA_SIZE; i++)
  {
    rxData[i] = Serial.read();
  }
  while(Serial.available()){
    Serial.read();
    }
  
 return encode(rxData);
}

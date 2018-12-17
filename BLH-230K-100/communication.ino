#define RX_DATA_SIZE 2

int encode(byte data[])
{
  int output = 0;
  for (int i = 0; i <  RX_DATA_SIZE; i++) {
    output = output << 8;
    output += data[i];
  }
  return output;
}
int wait_for_data()
{
  byte rxData[RX_DATA_SIZE];
  while (2 < Serial.available()) //2バイト受信するまで待機
  {
    for (int i; i < RX_DATA_SIZE; i++)
    {
      rxData[i]=Serial.read();
    }
  }
  return encode(rxData);
}

#define START_STOP_PIN 8
#define RUN_BRAKE_PIN 4
#define CW_CCW_PIN 5
#define INTVR_EXT 6
#define ALARM_RESET 7

#define SPEED
#define ALARM

volatile static long g_count = 0;
volatile static bool g_is_cw = true;
void Input_clock(void) {
  if (g_is_cw == true) {
    g_count++;
  } else {
    g_count--;
  }
}
//パルスカウントから角度(度)に変換
int Deg(long count) {
  //1周30パルス、ギヤ比1:100
  return (360 * count) / (30 * 100);
}
int Count(int deg) {
  return 30 * 100 * deg / 360;
}

//ピンの状態を変化させる時に10ms待てと指示があったので余裕をもって11ms待ってから他のピンを操作
void Motor_ControlPin(int pin, bool mode)
{
  digitalWrite(pin, mode);
  delay(11);
}
//モータの初期化
void Motor_init()
{
  pinMode(START_STOP_PIN, OUTPUT);
  Motor_ControlPin(START_STOP_PIN, LOW);
  pinMode(RUN_BRAKE_PIN, OUTPUT);
  Motor_ControlPin(RUN_BRAKE_PIN, LOW);
  pinMode(CW_CCW_PIN, OUTPUT);
  Motor_ControlPin(CW_CCW_PIN, LOW);
  pinMode(INTVR_EXT, OUTPUT);
  Motor_ControlPin(INTVR_EXT, LOW);
  pinMode(ALARM_RESET, OUTPUT);
  attachInterrupt(1, Input_clock, RISING);

}
//モータ回転
// spd:正の整数　cw,不の整数　ccw
void Motor_Rote(int spd)
{
  //回転方向を決定
  if (spd < 0)
  {
    g_is_cw=false;
    Motor_ControlPin(CW_CCW_PIN, HIGH);
  }
  else
  {
    g_is_cw=true;
    Motor_ControlPin(CW_CCW_PIN, LOW);
  }
  Motor_ControlPin(START_STOP_PIN, LOW);
}
//回転終了
void Motor_Stop()
{
  Motor_ControlPin(START_STOP_PIN, HIGH);
}
//指定角度に回す(絶対値)
int Motor_SetPose(int targetDeg) {
  int d_deg;
  int d_count;
  int targetCount;
  //現在の角度を取得
  int curentDeg = Deg(g_count);
  //回転方向を計算
  d_deg = targetDeg - curentDeg;

  if (0 > d_deg)//右回り
  {
    Rote(-1);
    while (targetDeg < Deg(g_count)){
      Serial.println(Deg(g_count));
      }
  } else //左周り
  {
    //
    Rote(1);
    while (targetDeg > Deg(g_count)){
      Serial.println(Deg(g_count));
      }
  }
  Stop();


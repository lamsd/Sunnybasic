#include <Suny.h>
Adafruit_NeoPixel Px(RGB_NUM,RGB_PIN,NEO_GRB + NEO_KHZ800);
PCF8574 _pinO(PCF8574_addr);
TCA9548A _pinI;
PCA9685 Pwm = PCA9685(PCA9685_addr);
TCA9548A tca(Sonar_Sensor_addr);
void Suny::Itit()
{
  _pinO.begin();
  _pinI.begin();
  Pwm.begin();
  Px.begin();
  Px.setBrightness(255);
//  this->SelectPortO(Port);
}
void Suny::SetLed(int a,String color)
{
 
  if(color == "R")    {Array_Color[0]=255,Array_Color[1]=0;Array_Color[2]=0;}
  else if(color=="G") {Array_Color[0]=0,Array_Color[1]=255;Array_Color[2]=0;}
  else if(color=="B") {Array_Color[0]=0,Array_Color[1]=0;Array_Color[2]=255;}
  else if(color == "Y") {Array_Color[0]=255,Array_Color[1]=255;Array_Color[2]=0;}
  else if(color == "W") {Array_Color[0]=255,Array_Color[1]=255;Array_Color[2]=255;}
  else if(color == "P") {Array_Color[0]=255,Array_Color[1]=0;Array_Color[2]=255;}
  else if(color == "Cy") {Array_Color[0]=0,Array_Color[1]=255;Array_Color[2]=255;}
  else if(color == "Or") {Array_Color[0]=255,Array_Color[1]=160;Array_Color[2]=16;}
  else if(color == "V") {Array_Color[0]=125,Array_Color[1]=0;Array_Color[2]=255;}
 Px.setPixelColor(a,Px.Color(Array_Color[0],Array_Color[1],Array_Color[2]));
 Px.show();
}
void Suny::SetAllLed(String color)
{
  for(int i=0 ;i<RGB_NUM;i++)
   {
      SetLed(i,color);
   }
}
void Suny::TurnOFF(int num)
{
 Array_Color[0] =0;
 Array_Color[1] =0;
 Array_Color[2] =0;
 Px.setPixelColor(num,Px.Color(Array_Color[0],Array_Color[1],Array_Color[2]));
 Px.show();
}
void Suny::TurnOFFALL(void)
{
  for(int i =0;i<RGB_NUM;i++)
  {
     Array_Color[0] =0;
     Array_Color[1] =0;
     Array_Color[2] =0;
     Px.setPixelColor(i,Px.Color(Array_Color[0],Array_Color[1],Array_Color[2]));
     Px.show();
  }
}
void  Suny::SelectPortI(uint8_t port)
{
  if (port > 7) return;
  Wire.beginTransmission(0x70);
  Wire.write(1 << port);
  Wire.endTransmission();
}
int  Suny::SelectPortO(int port)
{  
           if(port == 1)_pinO.pinMode(P0,OUTPUT);
      else if(port ==2) _pinO.pinMode(P1,OUTPUT);
      else if(port ==3) _pinO.pinMode(P2,OUTPUT);
      else if(port ==4) _pinO.pinMode(P3,OUTPUT);
      else if(port ==5) _pinO.pinMode(P4,OUTPUT);
      else if(port ==6) _pinO.pinMode(P5,OUTPUT);
      else if(port ==7) _pinO.pinMode(P6,OUTPUT);
      else if(port ==8) _pinO.pinMode(P7,OUTPUT);
return port;
}
int Suny::getSonarValue(int port)
{
  this->SelectPortI(port);
  return Sorna_val = this ->ReadValue(Sonar_Sensor_addr);
}
int Suny::getTouchLedValue(int port)
{
  this->SelectPortI(port);
  this->Sensor_Init(TouchLed_Sensor_addr);
//  return Touch_val =_pinI.readRegister();
}
int Suny::getLineValue(int port)
{
  this->SelectPortI(port);
  this->Sensor_Init(Line_SenSor_addr);
// return  Line_val =_pinI.readRegister();
}
int Suny::getDHT11Value(int port)
{
  this->SelectPortI(port);
  this->Sensor_Init(DHT11_SenSor);
// return  DHT_val =_pinI.readRegister();
}
int Suny::getTempertatureValue(int port)
{
  this->SelectPortI(port);
  this->Sensor_Init(Temperature_Sensor_addr);
 // return Temp_val =_pinI.readRegister();
}
void Suny::SetTouchLed(String odata)
{
  this->Sensor_Init(TouchLed_Sensor_addr);
   uint8_t data;
    if(odata == "R")    {Array_Color[0]=255,Array_Color[1]=0;Array_Color[2]=0;}
  else if(odata=="G") {Array_Color[0]=0,Array_Color[1]=255;Array_Color[2]=0;}
  else if(odata=="B") {Array_Color[0]=0,Array_Color[1]=0;Array_Color[2]=255;}
  else if(odata == "Y") {Array_Color[0]=255,Array_Color[1]=255;Array_Color[2]=0;}
  else if(odata == "W") {Array_Color[0]=255,Array_Color[1]=255;Array_Color[2]=255;}
  else if(odata == "P") {Array_Color[0]=255,Array_Color[1]=0;Array_Color[2]=255;}
  else if(odata == "Cy") {Array_Color[0]=0,Array_Color[1]=255;Array_Color[2]=255;}
  else if(odata == "Or") {Array_Color[0]=255,Array_Color[1]=160;Array_Color[2]=16;}
  else if(odata == "V") {Array_Color[0]=125,Array_Color[1]=0;Array_Color[2]=255;}
  data = Array_Color[0]+ Array_Color[1]+ Array_Color[2];
  _pinI.writeRegister(data);
}
void Suny::SetPort(int port ,bool odata)
{
  _pinO.digitalWrite(this->SelectPortO(port),odata);
}
void Suny::Mortor(int M1,int M2,int Vspeed1,int Vspeed2,int mode)
{
  if(M1 == M1F) {this->Mfor1(); this->ConvertPwm(Vspeed1);}
  else  {this->Mback1(); this->ConvertPwm(Vspeed1);}
  if(M2==M2F) {this ->Mfor2();this->ConvertPwm(Vspeed2);}
  else {this->Mback2(); this->ConvertPwm(Vspeed2);}
}
void Suny::Mortor(int opts,int vspeed,int mode)
{
   if(opts == f) {this->MForward();this->ConvertPwm(vspeed);}
   else if(opts == b) {this->Mback2();this->ConvertPwm(vspeed);}
   else if(opts == r) {this->MRight();this->ConvertPwm(vspeed);}
   else if(opts == l) {this->MLeft();this->ConvertPwm(vspeed);}
}
void Suny::MForward( )
{
  Pwm.setPWM(M_IN1,4096,0);
  Pwm.setPWM(M_IN2,0,4096);
  Pwm.setPWM(M_IN3,4096,0);
  Pwm.setPWM(M_IN4,0,4096);
}
void Suny::MBackward()
{
  Pwm.setPWM(M_IN1,0,4096);
  Pwm.setPWM(M_IN2,4096,0);
  Pwm.setPWM(M_IN3,0,4096);
  Pwm.setPWM(M_IN4,4096,0);
}
void Suny::MLeft()
{
 Pwm.setPWM(M_IN1,4096,0);
 Pwm.setPWM(M_IN2,0,4096);
 Pwm.setPWM(M_IN3,0,4096);
 Pwm.setPWM(M_IN4,4096,0);
}
void Suny::MRight()
{
 Pwm.setPWM(M_IN1,0,4096);
 Pwm.setPWM(M_IN2,4096,0);
 Pwm.setPWM(M_IN3,4096,0);
 Pwm.setPWM(M_IN4,0,4096);
}
void Suny::MStop()
{
   Pwm.setPWM(M_IN1,0,4096);
   Pwm.setPWM(M_IN2,0,4096);
   Pwm.setPWM(M_IN3,0,4096);
   Pwm.setPWM(M_IN4,0,4096);
}
void Suny::Mfor1()
{
   Pwm.setPWM(M_IN1,4096,0);
   Pwm.setPWM(M_IN2,0,4096);
}
void Suny::Mback1()
{
     Pwm.setPWM(M_IN1,0,4096);
     Pwm.setPWM(M_IN2,4096,0);
}
void Suny::Mstop1()
{
     Pwm.setPWM(M_IN1,0,4096);
     Pwm.setPWM(M_IN2,0,4096);
}
void Suny::Mfor2()
{
    Pwm.setPWM(M_IN3,4096,0);
    Pwm.setPWM(M_IN4,0,4096);
}
void Suny::Mback2()
{
  Pwm.setPWM(M_IN3,0,4096);
  Pwm.setPWM(M_IN4,4096,0);
}
void Suny::Mstop2()
{
  Pwm.setPWM(M_IN3,0,4096);
  Pwm.setPWM(M_IN4,0,4096);
}
void Suny::ConvertPwm(int speed)
{
  if(speed <=0) speed =0;
  else if(speed >=100) speed =100;
   speed = map(speed,0,100,0,4096);
}
void Suny::Sensor_Init(uint8_t addr)
{
//TCA9548A tca(addr);
}
int Suny::ReadValue(uint8_t addr)
{
  uint8_t buff = 0;
   Wire.requestFrom(addr, (uint8_t)1);

    if(Wire.available()>0)
       {
    buff = Wire.read();
       }
      // delay(30);
    return buff;
}

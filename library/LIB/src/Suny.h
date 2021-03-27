#ifndef Suny_H
#define Suny_H
#include <Arduino.h>
#include <RGB.h>
#include <PCF8574.h>
#include <TCA9548A.h>
#include <PCA9685.h>
#include <Arduino.h>
#include <Wire.h>
#define PCF8574_addr 0x20
#define TCA9548_addr 0x70
#define PCA9685_addr 0x40
#define RGB_PIN 32
#define RGB_NUM 8
#define Sonar_Sensor_addr 0x10
#define TouchLed_Sensor_addr 0xFE
#define Line_SenSor_addr 0xFD
#define Temperature_Sensor_addr 0xFC
#define DHT11_SenSor 0xFB
#define f 0
#define b 1
#define r 2
#define l 3

#define M_IN1 5
#define M_IN2 6
#define M_IN3 7
#define M_IN4 8
#define PWMA 9
#define PWWB 10
#define M1F 1
#define M1B 0
#define M2F 1
#define M2B 0
class Suny
{
  public :
     void Itit(void);
    void SelectPortI(uint8_t port);
     int SelectPortO(int port);
     void SetLed(int i,String color);
     void SetAllLed(String color);
     void TurnOFF(int num);
     void TurnOFFALL();
     void SetPort(int port,bool data);
     int getSonarValue(int port);
     int getTouchLedValue(int port);
     int getLineValue(int port);
     int getTempertatureValue(int por);
     int getDHT11Value(int port);
     void SetTouchLed(String odata);
     void Mortor(int M1,int M2,int VSpeed1,int VSpeed2,int mode);
     void Mortor(int opts,int Vspeed,int mode);
     void MForward();
     void MBackward();
     void MLeft();
     void MRight();
     void MStop();
     void Servo();
     void Mfor1();
     void Mback1();
     void Mstop1();
     void Mfor2();
     void Mback2();
     void Mstop2();
     void ConvertPwm(int speed);
     void SetPWM1();
     void SetPWM2();
     void Sensor_Init(uint8_t addr);
     int ReadValue(uint8_t addr);
  private:
  uint8_t Array_Color[3];
  int  ServoPin[8] = {1,2,3,4,9,10,11,12}; 
  uint8_t Sorna_val,Touch_val,Line_val,Temp_val,DHT_val;
    int Port;

 
};

#endif
//블루투스 통신 줄바꿈 알아보기
#include <stdio.h>
#include <stdlib.h>
#include <SoftwareSerial.h>
#define BT_TXD 53
#define BT_RXD 52
SoftwareSerial bluetooth(53,52);
const int analoglnPin = A0;
const int analoglnPin2 = A2;
const int analoglnPin3 = A4;
const int analoglnPin4 = A6;
const int analoglnPin5 = A8;
const int analoglnPin6 = A10;
const int analoglnPin7 = A12;
const int analoglnPin8 = A14;
int Pin_col[3] = {22,23,24};
int Pin_col2[3] = {25,26,27};
int Pin_col3[3] = {28,29,30};
int Pin_col4[3] = {31,32,33};
int Pin_col5[3] = {34,35,36};
int Pin_col6[3] = {37,38,39};
int Pin_col7[3] = {40,41,42};
int Pin_col8[3] = {43,44,45};
int sensor[8];
int sensor2[8];
int sensor3[8];
int sensor4[8];
int sensor5[8];
int sensor6[8];
int sensor7[8];
int sensor8[8];
int mfsr[8];
int mfsr2[8];
int mfsr3[8];
int mfsr4[8];
int mfsr5[8];
int mfsr6[8];
int mfsr7[8];
int mfsr8[8];
int anlogpwm[8][3] = {
  {0,0,0},
  {1,0,0},
  {0,1,0},
  {1,1,0},
  {0,0,1},
  {1,0,1},
  {0,1,1},
  {1,1,1}
};
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  for(int i = 0; i<3; i++){
    pinMode(Pin_col[i], OUTPUT);
    pinMode(Pin_col2[i], OUTPUT);
    pinMode(Pin_col3[i], OUTPUT);
    pinMode(Pin_col4[i], OUTPUT);
    pinMode(Pin_col5[i], OUTPUT);
    pinMode(Pin_col6[i], OUTPUT);
    pinMode(Pin_col7[i], OUTPUT);
    pinMode(Pin_col8[i], OUTPUT);
  }
}
 
void loop(){
  
  for(int i = 0; i < 8; i++){
    sensor[i] = readMux(i);
    mfsr[i] = map(sensor[i],0,1024,0,1000);
     if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
   if(Serial.available()) {
      bluetooth.print(mfsr[i]);
      if(i==7){
         bluetooth.print(","); 
         }
      else{
        bluetooth.print(","); 
      }
    }
  }
  
  for(int i = 0; i < 8; i++){
    sensor2[i] = readMux2(i);
    mfsr2[i] = map(sensor2[i],0,1024,0,1000);
     if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
   if(Serial.available()) {
      bluetooth.print(mfsr2[i]);
      if(i==7){
         bluetooth.print(","); 
         }
      else{
        bluetooth.print(","); 
      }
   }
  }
  
  
  for(int i = 0; i < 8; i++){
    sensor3[i] = readMux3(i);
    mfsr3[i] = map(sensor3[i],0,1024,0,1000);
     if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
   if(Serial.available()) {
      bluetooth.print(mfsr3[i]);
      if(i==7){
         bluetooth.print(","); 
         }
      else{
        bluetooth.print(","); 
      }
   }
  }

  
  for(int i = 0; i < 8; i++){
    sensor4[i] = readMux4(i);
    mfsr4[i] = map(sensor4[i],0,1024,0,1000);
     if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
   if(Serial.available()) {
      bluetooth.print(mfsr4[i]);
     if(i==7){
       bluetooth.print(","); 
       }
      else{
        bluetooth.print(","); 
      }
   }
  }

  
  for(int i = 0; i < 8; i++){
    sensor5[i] = readMux5(i);
    mfsr5[i] = map(sensor5[i],0,1024,0,1000);
     if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
   if(Serial.available()) {
      bluetooth.print(mfsr5[i]);
     if(i==7){
       bluetooth.print(","); 
       }
      else{
        bluetooth.print(","); 
      }
   }
  }

  
  for(int i = 0; i < 8; i++){
    sensor6[i] = readMux6(i);
    mfsr6[i] = map(sensor6[i],0,1024,0,1000);
     if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
     
   if(Serial.available()) {
      bluetooth.print(mfsr6[i]);
      if(i==7){
         bluetooth.print(","); 
         }
      else{
        bluetooth.print(","); 
      }
    }
  }

  
  
  for(int i = 0; i < 8; i++){
    sensor7[i] = readMux7(i);
    mfsr7[i] = map(sensor7[i],0,1024,0,1000);
    
    if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
   if(Serial.available()) {
      bluetooth.print(mfsr7[i]);
      if(i==7){
         bluetooth.print(","); 
         }
      else{
        bluetooth.print(","); 
      }
    }
  }

  
  for(int i = 0; i < 8; i++){
    sensor8[i] = readMux8(i);
    mfsr8[i] = map(sensor8[i],0,1024,0,1000);
     if (bluetooth.available()) {
     Serial.write(bluetooth.read());    
    }
    
   if(Serial.available()) {
      bluetooth.print(mfsr8[i]);
      if(i==7){
         bluetooth.print(","); 
         }
      else{
        bluetooth.print(","); 
      }
    }
  }  
   
    bluetooth.print("\n");        //이것만 수정하면됨    
     delay(1000);
}


  int readMux(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin);
  }

  int readMux2(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col2[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin2);
  } 

  int readMux3(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col3[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin3);
  }

  int readMux4(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col4[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin4);
  }

  int readMux5(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col5[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin5);
  }

  int readMux6(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col6[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin6);
  }
  
  int readMux7(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col7[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin7);
  }
  
  int readMux8(int _ch){
    for(int j= 0; j < 3; j++){
      digitalWrite(Pin_col8[j], anlogpwm[_ch][j]);
    }
    return analogRead(analoglnPin8);
  }

//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"
#include <string.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif




BluetoothSerial SerialBT;


//uint8_t arr[512] = {0};
int arr[512] = {0};
void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  pinMode(13, OUTPUT);
  

}

void loop() {

  bool sent = false;
//
//  if(Serial.available() > 0)
//  {
//    int i = 0;
//    while(Serial.available())
//    {
//      arr[i] = Serial.parseInt();
//      i++;   
//      
//    }
//    int bytesWritten = SerialBT.write(arr, (size_t)i * sizeof(int)); 
//    Serial.print(bytesWritten);
//  }

  if(Serial.available() > 0)
  {
    
    int numBytes = Serial.available();    
    Serial.readBytes(arr, numBytes);
    int bytesWritten = SerialBT.write(arr, numBytes);

    Serial.print(bytesWritten);
 }



}

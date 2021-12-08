#include "Nextion.h"
#include <SoftwareSerial.h>

SoftwareSerial HMISerial(0,1);

// b0 led on, b1 led off

NexDSButton b0 = NexDSButton(0,1,"b0");// sayfa, id, isim
NexDSButton b1 = NexDSButton(0,2,"b1");
NexText t0 = NexText(0,3,"t0");

// butonların durumları
uint32_t led_on = 0;
uint32_t led_off = 0;

const int led = 13;

void setup(){
  dbSerialPrintln("setup begin");
  nexInit();
  dbSerialPrintln("stup done");

  pinMode(led,OUTPUT);
}

void loop(){
  b0.getValue(&led_on);
  b1.getValue(&led_off);

  delay(200);
  if(led_on == 1){
    t0.setText("Led On");
    digitalWrite(led,HIGH);
  }
  if(led_off == 1){
    t0.setText("Led Off");
    digitalWrite(led, LOW);
  }
}

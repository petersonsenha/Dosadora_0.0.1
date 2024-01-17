/*
#include <ESP32Time.h>

ESP32Time rtc;
ESP32Time rtc(10800);  // offset in seconds GMT+1
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setupTime(){
  timeClient.begin();
  rtc.setTime(30, 24, 15, 17, 1, 2021);  // 17th Jan 2021 15:24:30
}
*/
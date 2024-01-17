
#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

// Configurações Wi-Fi
//const char* ssid = "everton";      // your network SSID (name of wifi network)
//const char* password = "@everton";  // your network password
// Configurações Wi-Fi
//const char* ssid = "CLARO_2G60BDDD";      // your network SSID (name of wifi network)
//const char* password = "05208656930";  // your network password

// Configurações Wi-Fi
const char* ssid = "UTFPRWEB";      // your network SSID (name of wifi network)
const char* password = "PeRaYv12";  // your network password
const int httpsPort = 443;
WiFiClientSecure client;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
//******************************************************************************************************************************
//URL : https://script.google.com/macros/s/AKfycbwvabCP14jaApvPVhN1DrqjZrurUu2J_Nst4HIWjFIlxgWVw61eYhj9r0MTUomgR4YTRQ/exec
char* server = "script.google.com";  // Server URL
//char* GScriptId = "AKfycbwvabCP14jaApvPVhN1DrqjZrurUu2J_Nst4HIWjFIlxgWVw61eYhj9r0MTUomgR4YTRQ";  //planilha teste
char* GScriptId = "AKfycbxOqCBqH1kZHcO-KzjKb7gAGRgIDmYPLMlkbDrXrqJXYD0C5ixxjF0V4yTFKG3TjYIWfw";
//******************************************************************************************************************************

#include <WiFi.h>
#include "time.h"
#include "sntp.h"

//const char* ssid       = "UTFPRWEB";
//const char* password   = "PeRaYv12";

const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
const long  gmtOffset_sec = -4*3600;
const int   daylightOffset_sec = 3600;

const char* time_zone = "BRST+3BRDT+2,M10.3.0,M2.3.0";  // TimeZone rule for Europe/Rome including daylight adjustment rules (optional)

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("No time available (yet)");
    //return;
  }
  //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.println(&timeinfo, "%d %Y %H:%M:%S");
  
  //Data = String(timeinfo.tm_mday)+"/" + String(timeinfo.tm_mon)+"/"+String(timeinfo.tm_mday)+" - "+String(timeinfo.tm_hour)+":"+String(timeinfo.tm_min)+":"+String(timeinfo.tm_sec);
  
  Data = timeinfo.tm_hour*3600+timeinfo.tm_min*60+timeinfo.tm_sec;
  DataDiff=Data-DataLast;
  DataLast=Data;
  DataCount++;
  Serial.println(Data);
}

// Callback function (get's called when time adjusts via NTP)
void timeavailable(struct timeval *t)
{
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
  pinoAcionamento=0;
  //enviarPulsoWIFI(1);
  hmi.beepHMI();
  //hmi.setPage(0);
}

void setupTime()
{
  //Serial.begin(115200);

  // set notification call-back function
  sntp_set_time_sync_notification_cb( timeavailable );

  /**
   * NTP server address could be aquired via DHCP,
   *
   * NOTE: This call should be made BEFORE esp32 aquires IP address via DHCP,
   * otherwise SNTP option 42 would be rejected by default.
   * NOTE: configTime() function call if made AFTER DHCP-client run
   * will OVERRIDE aquired NTP server address
   */
  sntp_servermode_dhcp(1);    // (optional)

  /**
   * This will set configured ntp servers and constant TimeZone/daylightOffset
   * should be OK if your time zone does not need to adjust daylightOffset twice a year,
   * in such a case time adjustment won't be handled automagicaly.
   */
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);

  /**
   * A more convenient approach to handle TimeZones with daylightOffset 
   * would be to specify a environmnet variable with TimeZone definition including daylight adjustmnet rules.
   * A list of rules for your zone could be obtained from https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h
   */
  //configTzTime(time_zone, ntpServer1, ntpServer2);

  //connect to WiFi
  //Serial.printf("Connecting to %s ", ssid);
  //WiFi.begin(ssid, password);
  //while (WiFi.status() != WL_CONNECTED) {
  //    delay(500);
  //    Serial.print(".");
  //}
  //Serial.println(" CONNECTED");

}

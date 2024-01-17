void connect_wifi(void)
{  
  Serial.print("Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  preferences.begin("my-wifi", false);
  String SSID_old = preferences.getString("SSID","UTFPRWEB");
  String PSWD_old = preferences.getString("PSWD","PeRaYv12");
  Serial.println("Wifi Original:");
  Serial.println(String(SSID_old));
  Serial.println(String(PSWD_old));
  preferences.end();
  WiFi.begin(SSID_old, PSWD_old);
  //WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(".");
    if(Serial.available()){
      String rx = Serial.readStringUntil('\r\n');
      treatSerial(rx);
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void enviarMedicao()
{
  HTTPClient http;

  tempoEnvio = millis() - tempoEnvio;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" + "value1=" + tensaoFinal + "&value2=" + String(correnteFinal, 2) + "&value3=" + tempoEnvio;
  tempoEnvio = millis();
  
  Serial.print("Making a request");
  http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  String payload;
  if (httpCode > 0) { //Check for the returning code
    payload = http.getString();

    Serial.println(httpCode);
    Serial.println(payload);
    //     testdrawstyles(payload);
    //if (httpCode == 200 or httpCode == 201) tempPing.Saida(0);
  }
  else {
    Serial.println("Error on HTTP request");
  }
  http.end();
}
void enviarPulsoWIFI(int pinoAcionamento, long _DataDiff)
{
  HTTPClient http;
  String Data;
  tempoEnvio = millis() - tempoEnvio;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" + "value1=" + pinoAcionamento + "&value2=" + _DataDiff + "&value3=" + tempoEnvio;
  tempoEnvio = millis();
  
  Serial.print("Envio de Pulso");
  http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  String payload;
  if (httpCode > 0) { //Check for the returning code
    payload = http.getString();

    Serial.println(httpCode);
    Serial.println(payload);
    //     testdrawstyles(payload);
    //if (httpCode == 200 or httpCode == 201) tempPing.Saida(0);
  }
  else {
    Serial.println("Error on HTTP request");
    envioFlag=false;
  }
  http.end();
  envioFlag=true;
  //return true;
}

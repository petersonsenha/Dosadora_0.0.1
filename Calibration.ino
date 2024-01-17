
void calibrarBomba(){
  //aplicar 30 segundos e verificar quanto dosou
  int tempoCalibracaoBomba=30000;
  long tempoAtual = 0;
  Bomba1.Acionar(true);
  delay(5000);
  Bomba1.Acionar(false);
}
long contAtual=0;
long countSensorNivel = 2500;
void calibrarValvula(){
  Serial.println("Calibrar Válvula de água");
  Valvula1.Acionar(true);
  contAtual=0;
  while(contAtual <= countSensorNivel){
    //contAtual += digitalRead(39);
    Serial.println(contAtual);
    contAtual += digitalRead(18);
  }
  Valvula1.Acionar(false);
}
void calibrarValvula2(){
  //hmi.setPage(12);
  
  contAtual=0;
  int contAtual=0;
  Valvula1.Acionar(true);
  while(contAtual <= countSensorNivel){
    contAtual += digitalRead(39);
    Serial.println(contAtual);
  }
  Valvula1.Acionar(false);
  //hmi.setVP(0x1023,contAtual);
}
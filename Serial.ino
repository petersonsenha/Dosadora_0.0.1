//***************************************************************************/
void receberSerial(){
  if(Serial.available()){
    String rx = Serial.readStringUntil('\r\n');
    if(rx=="R1"){
      verificarNivelMinimo();
      Serial.println("Receita 1 : ");
      //if (MNivel1.checar()) {
        //hmi.listen();
        //Bomba1.Dosar(1);
        //Valvula1.Dosar(1);
        
        //Display.mudarTela(TELA_DOSANDO);

        //void adicionarRegistro(int indice, int maquina, int codigo, int receita, int dia, int mes, int ano, int hora, int minuto, int segundo) {
        Funcionario.adicionarRegistro(indiceGeral, maquina, 9, 1, 30, 0x03, 23, 18, 24, 20);
        Funcionario.imprimirRegistro(indiceGeral);
        indiceGeral++; 
        EEPROM.write(0x01, indiceGeral);
      //}
    }
    if(rx=="R2"){
      Serial.println("Receita 2 : ");
      Bomba1.Dosar(2);
      Valvula1.Dosar(2);
    }
    if(rx=="R3"){
      Serial.println("Receita 3 : ");
      Bomba1.Dosar(3);
      Valvula1.Dosar(3);
    }
    if(rx=="R4"){
      Serial.println("Receita 4 : ");
      Bomba1.Dosar(4);
      Valvula1.Dosar(4);
    }
    if(rx=="R5"){
      Serial.println("Receita 5 : ");
      Bomba1.Dosar(5);
      Valvula1.Dosar(5);
    }
    if(rx=="R6"){
      Serial.println("Receita 6 : ");
      Bomba1.Dosar(6);
      Valvula1.Dosar(6);
    }
    if(rx=="RT"){
      for(int i=0;i<indiceGeral;i++){
        Funcionario.imprimirRegistro(i);
      }
    }
    if(rx=="T0"){
      Serial.println("Tela 0 : ");
      hmi.setPage(0);
    }
    if(rx=="T1"){
      Serial.println("Tela 1 : ");
      hmi.setPage(1);
    }
    if(rx=="B100"){
      Serial.println("Brilho 100% : ");
      hmi.setBrightness(100);
    }
    if(rx=="PURGAR"){
      Serial.println("Purgar 10seg : ");
      Bomba1.Purgar(5000);
      hmi.restartHMI();
    }
    if(rx=="CALIBRARA"){
      calibrarValvula();
      //hmi.setVP(0x1023, contAtual);
    }
    if(rx=="CALIBRARB"){
      calibrarBomba();
      //hmi.setVP(0x1023, contAtual);
    }  
  }
}
void blinkRele(int pin, int _delay){
  digitalWrite(pin, HIGH);
  delay(_delay);
  digitalWrite(pin, LOW);
  delay(_delay);
}
//***************************************************************************/
struct Receitas{
  String nomeReceita;
  int agua;               //EEPROM = 0x
  int produto;            //EEPROM = 0x
  int quantidade;         //EEPROM = 0x
  int tempoAgua;          //EEPROM = 0x
  int tempoProduto;       //EEPROM = 0x
  int tempoQuantidade;    //EEPROM = 0x
  int diluicaoPPM;
};
Receitas Receita;
Receitas Receita1;
Receitas Receita2;
Receitas Receita3;
Receitas Receita4;
Receitas Receita5;
Receitas Receita6;


void configurarReceita(int _receita, String _nomeReceita, int _agua, int _produto, int _quantidade, int _tempoAgua, int _tempoProduto, int _tempoQuantidade, int _diluicaoPPM){
  switch(_receita){
    case 1:
      Receita1.nomeReceita = _nomeReceita;
      Receita1.agua = _agua;
      Receita1.produto = _produto;            //EEPROM = 0x
      Receita1.quantidade = _quantidade;         //EEPROM = 0x
      Receita1.tempoAgua = _tempoAgua;          //EEPROM = 0x
      Receita1.tempoProduto = _tempoProduto;       //EEPROM = 0x
      Receita1.tempoQuantidade = _tempoQuantidade;    //EEPROM = 0x
      Receita1.diluicaoPPM = _diluicaoPPM;
      break;
    case 2:
      Receita2.nomeReceita = _nomeReceita;
      Receita2.agua = _agua;
      Receita2.produto = _produto;            //EEPROM = 0x
      Receita2.quantidade = _quantidade;         //EEPROM = 0x
      Receita2.tempoAgua = _tempoAgua;          //EEPROM = 0x
      Receita2.tempoProduto = _tempoProduto;       //EEPROM = 0x
      Receita2.tempoQuantidade = _tempoQuantidade;    //EEPROM = 0x
      Receita2.diluicaoPPM = _diluicaoPPM;
      break;
    case 3:
      Receita3.nomeReceita = _nomeReceita;
      Receita3.agua = _agua;
      Receita3.produto = _produto;            //EEPROM = 0x
      Receita3.quantidade = _quantidade;         //EEPROM = 0x
      Receita3.tempoAgua = _tempoAgua;          //EEPROM = 0x
      Receita3.tempoProduto = _tempoProduto;       //EEPROM = 0x
      Receita3.tempoQuantidade = _tempoQuantidade;    //EEPROM = 0x
      Receita3.diluicaoPPM = _diluicaoPPM;
      break;
    case 4:
      Receita4.nomeReceita = _nomeReceita;
      Receita4.agua = _agua;
      Receita4.produto = _produto;            //EEPROM = 0x
      Receita4.quantidade = _quantidade;         //EEPROM = 0x
      Receita4.tempoAgua = _tempoAgua;          //EEPROM = 0x
      Receita4.tempoProduto = _tempoProduto;       //EEPROM = 0x
      Receita4.tempoQuantidade = _tempoQuantidade;    //EEPROM = 0x
      Receita4.diluicaoPPM = _diluicaoPPM;
      break;
    case 5:
      Receita5.nomeReceita = _nomeReceita;
      Receita5.agua = _agua;
      Receita5.produto = _produto;            //EEPROM = 0x
      Receita5.quantidade = _quantidade;         //EEPROM = 0x
      Receita5.tempoAgua = _tempoAgua;          //EEPROM = 0x
      Receita5.tempoProduto = _tempoProduto;       //EEPROM = 0x
      Receita5.tempoQuantidade = _tempoQuantidade;    //EEPROM = 0x
      Receita5.diluicaoPPM = _diluicaoPPM;
      break;
    case 6:
      Receita6.nomeReceita = _nomeReceita;
      Receita6.agua = _agua;
      Receita6.produto = _produto;            //EEPROM = 0x
      Receita6.quantidade = _quantidade;         //EEPROM = 0x
      Receita6.tempoAgua = _tempoAgua;          //EEPROM = 0x
      Receita6.tempoProduto = _tempoProduto;       //EEPROM = 0x
      Receita6.tempoQuantidade = _tempoQuantidade;    //EEPROM = 0x
      Receita6.diluicaoPPM = _diluicaoPPM;
      break;
    
  
  }
}
// Funções de Receitas
bool Receita_1() {
  // Dosar para 1 Litro com 1% de Concentração
  //Receber dados da calibração da válvula
  //StaticJsonDocument<512> doc;
  /*
  int receitaLocal=1;
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("No time available (yet)");
    //return;
  }
  Serial.println( "Receita "                +String(receitaLocal)+
                  " : Agua -> "             +String(Receita1.agua)+
                  " | Produto -> "          +String(Receita1.produto)+
                  " | Quantidade -> "       +String(Receita1.quantidade)+
                  " | tempoAgua -> "        +String(Receita1.tempoAgua)+
                  " | tempoProduto -> "     +String(Receita1.tempoProduto)+
                  " | tempoQuantidade -> "  +String(Receita1.tempoQuantidade)+
                  " | diluicaoPPM -> "      +String(Receita1.diluicaoPPM));
  Serial.println("Maquina -> "+String(NUMERO_SERIE)+" | Código -> "+String(888)+" | Receita -> "+String(1)+" | "+String(timeinfo.tm_mday)+" / "+String(timeinfo.tm_mon)+" / "+String(timeinfo.tm_mday)+" -> "+String(timeinfo.tm_hour)+" : "+String(timeinfo.tm_min)+" : "+String(timeinfo.tm_sec));
  doc["maquina"] = NUMERO_SERIE;
  doc["codigo"] = 888;
  doc["receita"] = 1;
  doc["dia"] = timeinfo.tm_mday;
  doc["mes"] = timeinfo.tm_mon;
  doc["ano"] = timeinfo.tm_mday;
  doc["hora"] = timeinfo.tm_hour;
  doc["minuto"] = timeinfo.tm_min;
  doc["segundo"] = timeinfo.tm_sec;

  float tempo2ml = 1.2;
  float quantidade = 1000;//valor em ml
  //Valvula1.tempo[1] = 1000 * tempo2ml;
  //Bomba1.tempo[1] = 1000 * tempo2ml;
  //Bomba1.Dosar(1);
  //Valvula1.Dosar(1);
  //enviarDados();
  //imprimirReceita("Receita 1", 
  //                receitaLocal, 
    //              Receita1.diluicaoPPM, 
      //            Receita1diluicaoPorcentagem, 
        //          int _volumeTotal, 
          //        String _nomeFuncionario, 
            //      int _codigoFuncionario, 
              //    int _produtoCodigo, 
                //  int _codigoDosagem);
                */
}
bool Receita_2() {
  // Dosar para 1 Litro com 10% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[2] = 1000 * tempo2ml;
  Serial.println("Receita 2 : ");
  Bomba1.Dosar(2);
  Valvula1.Dosar(2);
}
bool Receita_3() {
  // Dosar para 1 Litro com 50% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[3] = 1000 * tempo2ml;
}
bool Receita_4() {
  // Dosar para 5 Litros com 1% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[4] = 1000 * tempo2ml;
}
bool Receita_5() {
  // Dosar para 5 Litros com 10% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[5] = 1000 * tempo2ml;
}
bool Receita_6() {
  // Dosar para 5 Litros com 50% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[6] = 1000 * tempo2ml;
}

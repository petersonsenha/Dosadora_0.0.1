//***************************************************************************/
struct Receitas{
  float agua;               //EEPROM = 0x
  float produto;            //EEPROM = 0x
  float quantidade;         //EEPROM = 0x
  float tempoAgua;          //EEPROM = 0x
  float tempoProduto;       //EEPROM = 0x
  float tempoQuantidade;    //EEPROM = 0x
};


// Funções de Receitas
bool Receita1() {
  // Dosar para 1 Litro com 1% de Concentração
  //Receber dados da calibração da válvula
  float tempo2ml = 1.2;
  float quantidade = 1000;//valor em ml
  Valvula1.tempo[1] = 1000 * tempo2ml;
  Bomba1.tempo[1] = 1000 * tempo2ml;
  Bomba1.Dosar(1);
  Valvula1.Dosar(1);
}
bool Receita2() {
  // Dosar para 1 Litro com 10% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[2] = 1000 * tempo2ml;
  Serial.println("Receita 2 : ");
  Bomba1.Dosar(2);
  Valvula1.Dosar(2);
}
bool Receita3() {
  // Dosar para 1 Litro com 50% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[3] = 1000 * tempo2ml;
}
bool Receita4() {
  // Dosar para 5 Litros com 1% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[4] = 1000 * tempo2ml;
}
bool Receita5() {
  // Dosar para 5 Litros com 10% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[5] = 1000 * tempo2ml;
}
bool Receita6() {
  // Dosar para 5 Litros com 50% de Concentração
  float tempo2ml = 1.2;
  Valvula1.tempo[6] = 1000 * tempo2ml;
}
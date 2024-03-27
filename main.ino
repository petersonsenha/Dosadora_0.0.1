//***************************************************************************/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  //Inicializa a Serial para Degub
  configAll();       //Configura Todos os Dispositivos
  //void adicionarRegistro(int indice, int maquina, int codigo, int receita, int dia, int mes, int ano, int hora, int minuto, int segundo) { 
}
//***************************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("oimoanoite");
  //receberSerial();
  hmi.listen();
  MEF();
  //Receita_1();
  //loopNFC();
  //leituraStandBy();
  //server.handleClient();
  //Bomba1.Dosar(10);
}
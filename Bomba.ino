class Rele {
  private:
    int action;
    int pino;

    bool mode;
    int memory;
  public:
    int tempo[7]={500,1000,2000,3000,4000,5000,6000};
    long pulso[7]={3000,6000,9000,12000,15000,18000};
    //25000 pulsos é igual a 800ml, então o pulso 
    float convert = 1;
    void begin(int _pin, int Rele) {
      Serial.println("Setou o pino da Valvula");
      pino = _pin;
      pinMode(_pin, OUTPUT);
      memory = 0x10 + Rele;
      action = EEPROM.read(memory);
    }
    void setMode(bool _mode) {
      mode = _mode;
    }
    bool getMode() {
      return mode;
    }
    void setAction(int _action) {
      action = _action;
    }
    int getAction() {
      return action;
    }
    bool Dosar(int receita) {
      //tempo[receita]=_tempo;

      if (mode == 0) {
        digitalWrite(pino, HIGH);
        delay(pulso[receita]);
        delay(1000);
        digitalWrite(pino, LOW);
      } else {
        //Condição de pulsos, aplicar depois
        contPulse = 0;
        digitalWrite(pino, HIGH);
        while (contPulse <= pulso[receita]) {
        }
        digitalWrite(pino, LOW);
        contPulse=0;
      }
      action++;
      EEPROM.write(memory, action);
      return 1;
    }
    void Acionar(bool enable){
      digitalWrite(pino, enable);
    }
    bool Calibrar() {
    }
    void Purgar(){
      
    }
};

class BombaPeristalticaDC {
  private:
    int Receita[3];
    int Receita1_agua;
    int Receita1_produto;
    int Receita1_Total;
    

  public:
    int tempo[8]={500,1000,2000,3000,4000,5000,6000,7000};
    int pinBomba=48;
    void begin(int pBomba) {
      pinBomba=pBomba;
      pinMode(pBomba, OUTPUT);
    }
    void sleep() {
    
    }
    void Dosar(int receita) {
      //Converter tempo em ml
      digitalWrite(pinBomba, HIGH);
      delay(tempo[receita]);
      digitalWrite(pinBomba, LOW);
    }
    void Purgar(long ms){
      digitalWrite(pinBomba, HIGH);
      delay(ms);
      digitalWrite(pinBomba, LOW);
    }
    void Acionar(bool enable){
      digitalWrite(pinBomba, enable);
    }
};
BombaPeristalticaDC Bomba1;
Rele Valvula1;

void setupValvulas(){
  Valvula1.begin(2, 1);
  Valvula1.setMode(0);
  Bomba1.begin(40);
  Valvula1.Dosar(1);
  Bomba1.Dosar(100);
  Serial.print("Acionamentos : ");
  Serial.println(Valvula1.getAction());
}
void setarAcoes(){
  Valvula1.setAction(0);
}
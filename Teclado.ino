class Teclado4X4 {
  private:
    bool habilitado;
    int teclaNumerica;
    int teclaComando;
    int teclaReceita;
    int p_l1;
    int p_l2;
    int p_l3;
    int p_l4;
    int p_c1;
    int p_c2;
    int p_c3;
    int p_c4;
    int p_Rec1;
    int p_Rec2;
    int p_Rec3;
    int p_Rec4;
    int p_Rec5;
    int p_Rec6;

  public:
    void begin(int _pinRec1, int _pinRec2, int _pinRec3, int _pinRec4, int _pinRec5, int _pinRec6){
      habilitado = true;
      p_Rec1 = _pinRec1;
      p_Rec2 = _pinRec2;
      p_Rec3 = _pinRec3;
      p_Rec4 = _pinRec4;
      p_Rec5 = _pinRec5;
      p_Rec6 = _pinRec6;
      pinMode(p_Rec1,INPUT_PULLUP);
      pinMode(p_Rec2,INPUT_PULLUP);
      pinMode(p_Rec3,INPUT_PULLUP);
      pinMode(p_Rec4,INPUT_PULLUP);
      pinMode(p_Rec5,INPUT_PULLUP);
      pinMode(p_Rec6,INPUT_PULLUP);
    }
    int teste() {
      habilitado = true;
    }
    bool calibrar() {
    }
    void desabilitar() {
      habilitado = false;
    }
    void lerReceita() {
      if (digitalRead(p_Rec1) && !digitalRead(p_Rec2) && !digitalRead(p_Rec3) && !digitalRead(p_Rec4) && !digitalRead(p_Rec5) && !digitalRead(p_Rec6)) {
        //Dosar Receita1

      } else if (!digitalRead(p_Rec1) && digitalRead(p_Rec2) && !digitalRead(p_Rec3) && !digitalRead(p_Rec4) && !digitalRead(p_Rec5) && digitalRead(p_Rec6)) {
        //Dosar Receita2
      }

      else if (!digitalRead(p_Rec1) && digitalRead(p_Rec2) && !digitalRead(p_Rec3) && !digitalRead(p_Rec4) && !digitalRead(p_Rec5) && digitalRead(p_Rec6)) {
        //Dosar Receita3
      }

      else if (!digitalRead(p_Rec1) && digitalRead(p_Rec2) && !digitalRead(p_Rec3) && !digitalRead(p_Rec4) && !digitalRead(p_Rec5) && digitalRead(p_Rec6)) {
        //Dosar Receita4
      }

      else if (!digitalRead(p_Rec1) && digitalRead(p_Rec2) && !digitalRead(p_Rec3) && !digitalRead(p_Rec4) && !digitalRead(p_Rec5) && digitalRead(p_Rec6)) {
        //Dosar Receita5
      }

      else if (!digitalRead(p_Rec1) && digitalRead(p_Rec2) && !digitalRead(p_Rec3) && !digitalRead(p_Rec4) && !digitalRead(p_Rec5) && digitalRead(p_Rec6)) {
        //Dosar Receita6
      }
    }
    int treatTecla(int _tecla){

    }
};
class TecladoADC {
private:
  int pinADC;
  int ADCValue;
  int limitValue=100;
  int value[6]={100,600,1200,2000,3000,4000};
  bool button[6]={0,0,0,0,0,0};
public:
  void begin(int _pinADC){
    pinADC = _pinADC;
    pinMode(pinADC, INPUT);
  }
  int ler(){
    ADCValue = analogRead(pinADC);
    return ADCValue;
  }
  int leitura(){
    ADCValue = analogRead(pinADC);
    for(int i=0;i<6;i++){button[i]=false;}
    for(int i=0;i<6;i++){
      if(ADCValue>=value[i]-limitValue && ADCValue<=value[i]+limitValue){
        //Botão i
        button[i]=true;
      }  
    }
  }
};
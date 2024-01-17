//***************************************************************************/
// Display DWIN
// 
#include <Arduino.h>
#include <DWIN.h>
/*
    void echoEnabled(bool enabled);
    void listen();                                                                                // Listen Touch Events & Messages from HMI
    double getHWVersion();                                                                        // Get Version
    void restartHMI();                                                                            // restart HMI
    void setPage(byte pageID);                                                                    // set Particular Page
    byte getPage();                                                                               // get Current Page ID
    void setBrightness(byte pConstrast);                                                          // set LCD Brightness
    byte getBrightness();                                                                         // set LCD Brightness
    void setText(long address, String textData);                                                  // set Data on VP Address
    void setVP(long address, byte data);                                                          // set Byte on VP Address
    void beepHMI();                                                                               // beep Buzzer for 1 sec
    typedef void (*hmiListener) (String address, int lastByte, String message, String response);  // Callback Function
    void hmiCallBack(hmiListener callBackFunction);                                               // CallBack Method
*/

#define ADDRESS_A     "1010"
#define ADDRESS_B     "1020"
#define DGUS_BAUD     115200

// If Using ESP 32
#if defined(ESP32)
  #define DGUS_SERIAL Serial2
  DWIN hmi(DGUS_SERIAL, 16, 17, DGUS_BAUD);

// If Using Arduino Uno / Mega
#else
  DWIN hmi(16, 17, DGUS_BAUD);
#endif

#define TELA_RESERVATORIO_VAZIO 3
#define TELA_INICIAR 2
#define TELA_DOSANDO 4
void setupDWIN(){
  Serial.println("DWIN HMI ~ Hello World");
  hmi.echoEnabled(true);
  hmi.hmiCallBack(onHMIEvent);
  hmi.setPage(0);
  Serial.println("Hardware Version : "+String(hmi.getHWVersion()));
  hmi.setBrightness(100);
  hmi.beepHMI();
  hmi.setRTC(23, 0x07, 21, 0x00, 40, 55);
}

/*class DWIN{
  private:
    #define Tela_00 0x50
    int recebidoInt;
    bool rpt=false;
    int telaAtual;
    int Buffer[20];
    int BufferEnvio[20];
    String recebido;
    int codigoStandby[10] = {0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49};
    int telas[10] = {0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59};
    int codigoReceitas[8] = {0x60,0x61,0x62,0x63,0x64,0x65,0x66};
    int videos[5] = {0x70,0x71,0x72,0x73,0x74};
    int variaveis[20] = {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99};

  public:
    void begin(){
      Serial3.begin(115200);
      while(!Serial3){delay(100);}
    }
    void restart(){
      Serial3.end();
      Serial3.begin(115200);
      while(!Serial3){delay(100);}

    }
    void mudarTela(int _tela){
      if(_tela!=telaAtual){telaAtual=_tela;Serial3.write(telas[_tela]);}
      else{Serial.println("Chamou a mesma tela");}
      enviarDados()
    }
    void receberReceita(int _receita){
      if(Serial3.available()){
        recebido = Serial3.readStringUntil("\r\n");
      }
      if(recebido == codigoReceitas[0]){
        //Chamar o código de receita 
      }
    }
    bool receberDados(){
      if(Serial3.available()){
        for(int i=0;i<=8;i++){
          Buffer[i]= Serial.read();
        }
        return true;
      }
      else{
        return false;
      }
    }
    void enviarDados(){
      BufferEnvio[0]=0x5A;
      for(int i=1;i<8;i++){
        
      }
    }
    bool receberStandby(){
      if(receberDados()){
        if      (Buffer[4] == codigoStandby[0]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[1]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[2]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[3]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[4]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[5]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[6]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[7]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[8]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[9]){return true;}//Iniciar
        else{return false;}//Não Fazer Nada
      }
    }
    bool receberBotoes(){
      if(receberDados()){
        if      (Buffer[4] == codigoStandby[0]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[1]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[2]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[3]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[4]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[5]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[6]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[7]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[8]){return true;}//Iniciar
        else if (Buffer[4] == codigoStandby[9]){return true;}//Iniciar
        else{return false;}//Não Fazer Nada
      }
    }
    void iniciarVideo(int _video){
      Serial3.write(videos[_video]);
    }
    void atualizarVariavel(int _variavel){
      Serial.write(variaveis[_variavel]);
    }
};
DWIN Display;
*/
// Receita A
//

bool leituraStandBy() {
  // Ler quando estiver em standBy
  hmi.listen();
}
byte lastPage=0;
bool changedPage(){
  byte page = hmi.getPage();
  if(page!=lastPage){
    lastPage = page;
    return true;
  }
  else{
    return false;
  }
}

#define ADDR_STATE           40
bool changedState = true;
bool firstState = true;
int state=0;
class State {
private:
public:
  int atual;
  bool trans = 0;
  void mudar(int _a, int _n) {
    if (_a == 1 && _n == 2)
      ;
    atual = _n;
    if (_a == 1 && _n == 3)
      ;
    atual = _n;
    if (_a == 1 && _n == 4)
      ;
    atual = _n;
    if (_a == 1 && _n == 5)
      ;
    atual = _n;
    if (_a == 1 && _n == 6)
      ;
    atual = _n;
    if (_a == 1 && _n == 7)
      ;
    atual = _n;
    if (_a == 1 && _n == 8)
      ;
    atual = _n;
    if (_a == 1 && _n == 9)
      ;
    atual = _n;
    if (_a == 2 && _n == 1)
      ;
    atual = _n;
    if (_a == 2 && _n == 3)
      ;
    atual = _n;
    if (_a == 2 && _n == 4)
      ;
    atual = _n;
    if (_a == 2 && _n == 5)
      ;
    atual = _n;
    if (_a == 2 && _n == 6)
      ;
    atual = _n;
    if (_a == 2 && _n == 7)
      ;
    atual = _n;
    if (_a == 2 && _n == 8)
      ;
    atual = _n;
    if (_a == 2 && _n == 9)
      ;
    atual = _n;
    if (_a == 3 && _n == 1)
      ;
    atual = _n;
    if (_a == 3 && _n == 2)
      ;
    atual = _n;
    if (_a == 3 && _n == 4)
      ;
    atual = _n;
    if (_a == 3 && _n == 5)
      ;
    atual = _n;
    if (_a == 3 && _n == 6)
      ;
    atual = _n;
    if (_a == 3 && _n == 7)
      ;
    atual = _n;
    if (_a == 3 && _n == 8)
      ;
    atual = _n;
    if (_a == 3 && _n == 9)
      ;
    atual = _n;
    if (_a == 4 && _n == 1)
      ;
    atual = _n;
    if (_a == 4 && _n == 2)
      ;
    atual = _n;
    if (_a == 4 && _n == 3)
      ;
    atual = _n;
    if (_a == 4 && _n == 5)
      ;
    atual = _n;
    if (_a == 4 && _n == 6)
      ;
    atual = _n;
    if (_a == 4 && _n == 7)
      ;
    atual = _n;
    if (_a == 4 && _n == 8)
      ;
    atual = _n;
    if (_a == 4 && _n == 9)
      ;
    atual = _n;
    if (_a == 5 && _n == 1)
      ;
    atual = _n;
    if (_a == 5 && _n == 2)
      ;
    atual = _n;
    if (_a == 5 && _n == 3)
      ;
    atual = _n;
    if (_a == 5 && _n == 4)
      ;
    atual = _n;
    if (_a == 5 && _n == 6)
      ;
    atual = _n;
    if (_a == 5 && _n == 7)
      ;
    atual = _n;
    if (_a == 5 && _n == 8)
      ;
    atual = _n;
    if (_a == 5 && _n == 9)
      ;
    atual = _n;
    if (_a == 6 && _n == 1)
      ;
    atual = _n;
    if (_a == 6 && _n == 2)
      ;
    atual = _n;
    if (_a == 6 && _n == 3)
      ;
    atual = _n;
    if (_a == 6 && _n == 4)
      ;
    atual = _n;
    if (_a == 6 && _n == 5)
      ;
    atual = _n;
    if (_a == 6 && _n == 7)
      ;
    atual = _n;
    if (_a == 6 && _n == 8)
      ;
    atual = _n;
    if (_a == 6 && _n == 9)
      ;
    atual = _n;
    if (_a == 7 && _n == 1)
      ;
    atual = _n;
    if (_a == 7 && _n == 2)
      ;
    atual = _n;
    if (_a == 7 && _n == 3)
      ;
    atual = _n;
    if (_a == 7 && _n == 4)
      ;
    atual = _n;
    if (_a == 7 && _n == 5)
      ;
    atual = _n;
    if (_a == 7 && _n == 6)
      ;
    atual = _n;
    if (_a == 7 && _n == 8)
      ;
    atual = _n;
    if (_a == 7 && _n == 9)
      ;
    atual = _n;
    if (_a == 8 && _n == 1)
      ;
    atual = _n;
    if (_a == 8 && _n == 2)
      ;
    atual = _n;
    if (_a == 8 && _n == 3)
      ;
    atual = _n;
    if (_a == 8 && _n == 4)
      ;
    atual = _n;
    if (_a == 8 && _n == 5)
      ;
    atual = _n;
    if (_a == 8 && _n == 6)
      ;
    atual = _n;
    if (_a == 8 && _n == 7)
      ;
    atual = _n;
    if (_a == 8 && _n == 9)
      ;
    atual = _n;
    if (_a == 9 && _n == 1)
      ;
    atual = _n;
    if (_a == 9 && _n == 2)
      ;
    atual = _n;
    if (_a == 9 && _n == 3)
      ;
    atual = _n;
    if (_a == 9 && _n == 4)
      ;
    atual = _n;
    if (_a == 9 && _n == 5)
      ;
    atual = _n;
    if (_a == 9 && _n == 6)
      ;
    atual = _n;
    if (_a == 9 && _n == 7)
      ;
    atual = _n;
    if (_a == 9 && _n == 8)
      ;
    atual = _n;
  }
};
State ST;

void MEF() {
  if(changedPage()){
    Serial.println("Mudou para :" + String(lastPage));
    if(lastPage==16){
      //Receita_1();
      hmi.beepHMI();
      hmi.setPage(3);
    }
    if(lastPage==17){
      //Receita_2();
      hmi.setPage(3);
    }
    if(lastPage==18){
      //Receita_3();
      hmi.setPage(3);
    }
    if(lastPage==19){
      //Receita_4();
      hmi.setPage(3);
    }
    if(lastPage==20){
      //Receita_5();
      hmi.setPage(3);
    }
    if(lastPage==21){
      //Receita_6();
      hmi.setPage(3);
    }    
  }
  if(firstState){
    ST.atual = EEPROM.read(ADDR_STATE);
    firstState=false;
  }
  if (changedState) {
    Serial.println("Estado : " + String(ST.atual));
    
    if (state == ST.atual) {
      changedState = 0;
    } else {
      changedState = 1;
      state = ST.atual;
    }
  }
  
  if (ST.atual == 0) {  //Inicializando
    //Ligando
    //Display.mudarTela(TELA_INICIAR); //Tela [ Iniciar ]
    //verificarNivelMinimo();    //Medir o nível
    //hmi.listen();
  }
  if (ST.atual == 1) {  //Inicializando
    //Ligando
    //Display.mudarTela(TELA_INICIAR); //Tela [ Iniciar ]
    verificarNivelMinimo();    //Medir o nível
  } else if (ST.atual == 2) {  // Esperando
    //
    //hmi.listen();
    verificarNivelMinimo();
    //if (MNivel1.medir() == 2){
    //Ao final será medido o nível para ver se não acabou o produto
    //verificarNivelMinimo();
    //}
  } else if (ST.atual == 3) {  // Dosando
    verificarNivelMinimo();
    //if (MNivel1.checar()) {
    //  //hmi.listen();
    //  Valvula1.Dosar(1);
    //  Bomba1.Dosar(10);
    //Display.mudarTela(TELA_DOSANDO);
    //}
    ST.trans = 1;
  } else if (ST.atual == 4) {  // Configurando
    //hmi.listen();
    // Tela [  ]
    //
  } else if (ST.atual == 5) {  // Registrando
    //Funcionario.adicionarRegistro(int indice, int maquina, int codigo, int receita, int dia, int mes, int ano, int hora, int minuto, int segundo);
    // Tela [  ]
    //
    hmi.setPage(4);

  } else if (ST.atual == 6) {  //Comunicando
    //Implementar no ESP32
    // Tela [  ]
  } else if (ST.atual == 7) {  //Calibrando
    verificarNivelMinimo();
    //hmi.listen();
    //Display.mudarTela(TELA_CALIBRANDO);
    //
    // Tela [  ]
  } else if (ST.atual == 8) {
    // Tela [  ]
  } else if (ST.atual == 9) {
    // Tela [  ]
  } else if (ST.atual == 10) {
    // Tela [  ]
  } else if (ST.atual == 11) {
    // Tela [  ]
  } else if (ST.atual == 12) {
    // Tela [  ]
  } else if (ST.atual == 13) {
    // Tela [  ]
  } else if (ST.atual == 14) {
    // Tela [  ]
  } else if (ST.atual == 15) {
    // Tela [  ]
  }
}

void configAll(){
  setupDWIN();
  //MEGA
  Valvula1.begin(46,1);
  Bomba1.begin(48);
  pinMode(18,INPUT);      //Sensor de Fluxo
  attachInterrupt(digitalPinToInterrupt(18), contarFluxo, CHANGE);
  Valvula1.setMode(0);
  hmi.setPage(2);
  hmi.setBrightness(50);
  //setupImpressora();
  //checkImprimir();
  //Fluxo1.begin(39);
  //ESP32
  //Valvula1.begin(25,1);
  //Bomba1.begin(26);
  //pinMode(39,INPUT);      //Sensor de Fluxo
  //attachInterrupt(digitalPinToInterrupt(39), contarFluxo, CHANGE);
  //Fluxo1.begin(39);
  //MNivel1.begin();
  //Impressora1.begin();
  
  setupNFC();
  //setupWiFiManager();
}
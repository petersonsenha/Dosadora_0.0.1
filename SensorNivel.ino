//***************************************************************************/
// Classe Medidor de Nível
//
// Tem como premissa medir o nível do galão do tanque e é um sensor digital
//
//***************************************************************************/
class MedidorNivel {
  private:
    bool teste;
    bool medindo;
    int nivel;
    int nivelAntigo;
    int p_N1;
    int pino1;
    int pino2;
    int pino3;
    int pino4;

  public:
    int begin(int numerosPinos, int pino1, int pino2, int pino3, int pino4) {
      if (numerosPinos == 4) {
        pinMode(pino1, INPUT);
        pinMode(pino2, INPUT);
        pinMode(pino3, INPUT);
        pinMode(pino4, INPUT);
      } else if (numerosPinos == 3) {
        pinMode(pino1, INPUT);
        pinMode(pino2, INPUT);
        pinMode(pino3, INPUT);
      } else if (numerosPinos == 2) {
        pinMode(pino1, INPUT);
        pinMode(pino2, INPUT);
      } else if (numerosPinos == 1) {
        pinMode(pino1, INPUT);
      }
    }

    bool checar() {
      //teste = digitalRead(pino1);
      return teste;
    }

    int medir() {
      if (nivelAntigo != nivel) {

        if (digitalRead(pino1) && digitalRead(pino2) && digitalRead(pino3) && digitalRead(pino4)) {
          nivel = 4;
          if (SerialDebug) { Serial.println("Cheio"); }
          if (nivelAntigo == 0 && nivel == 4) {
            if (SerialDebug) { Serial.println("Recarregamento Crítico na data de hoje"); }
            // Colocar a data e horário que foi recarregado
          }
        } else if (digitalRead(pino1) && digitalRead(pino2) && digitalRead(pino3) && !digitalRead(pino4)) {
          nivel = 3;
        } else if (digitalRead(pino1) && digitalRead(pino2) && !digitalRead(pino3) && !digitalRead(pino4)) {
          nivel = 2;
        } else if (digitalRead(pino1) && !digitalRead(pino2) && digitalRead(pino3) && !digitalRead(pino4)) {
          nivel = 1;
        } else {
          if (SerialDebug) { Serial.println("Sensor com Problema"); }
          //Acionar Assistência técnica
        }
      }
      nivelAntigo = nivel;
      return nivel;
    }
};

MedidorNivel MNivel1;
// Roda a Máquina de Estados
void verificarNivelMinimo(){
  while (MNivel1.medir() == 1) {
    Serial.println("Encher Reservatório");
    //Ir para Tela Encher Reservatório
    //Display.mudarTela(TELA_RESERVATORIO_VAZIO);
  }
}
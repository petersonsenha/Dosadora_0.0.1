
#include "USBPrinter.h"
#include "ESC_POS_Printer.h"

class PrinterOper : public USBPrinterAsyncOper {
public:
  uint8_t OnInit(USBPrinter *pPrinter);
};

uint8_t PrinterOper::OnInit(USBPrinter *pPrinter) {
  Serial.println(F("USB Printer OnInit"));
  Serial.print(F("Bidirectional="));
  Serial.println(pPrinter->isBidirectional());
  return 0;
}

USB myusb;
PrinterOper AsyncOper;
USBPrinter uprinter(&myusb, &AsyncOper);
ESC_POS_Printer printer(&uprinter);

void setupImpressora() {
  if (myusb.Init()) {
    Serial.println(F("USB host failed to initialize"));
    while (1) delay(1);
  }

  Serial.println(F("USB Host init OK"));
  myusb.Task();
  if (uprinter.isReady()) {
    printer.begin();
  }
  printer.set80mm();
  
}
void loopImpressora() {
  myusb.Task();
}

void imprimirReceita(String _nomeReceita, int _numeroReceita, int _diluicaoPPM, float _diluicaoPorcentagem, int _volumeTotal, String _nomeFuncionário, int _codigoFuncionario, ) {
  Serial.println(F("Init ESC POS printer"));
  //printer.setSize('L');   // L for large
  printer.println(F("Clean Health - DVH - Engenheiro Peterson Senha"));
  printer.println(F("PERACETIC FOOD"));
  printer.println(F("Receita -> 1"));
  printer.println(F("Diluicao ->  1 : 100 - 2.00%"));
  printer.println(F("Volume Total -> 1000 mL"));
  printer.println(F("Funcionario -> Filipe Richter"));
  printer.println(F("Codigo -> 7018"));
  printer.println(F("Data -> 26/08/2023"));
  printer.println(F("Horario -> 15:21"));
  printer.feedRows(255);
  printer.fullCutt();
}

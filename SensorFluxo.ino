class SensorFluxo {
  private:
  public:
    int pin;
    void begin(int _pino) {
      pin=_pino;
      pinMode(pin, INPUT);
    }

};
SensorFluxo Fluxo1;

void contarFluxo(){
  contPulse++;
}

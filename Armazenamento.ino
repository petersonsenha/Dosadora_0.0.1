// Adicionar as Bibliotecas utilizadas

#include "string.h"  //Conversão dos dados da Serial
#include <SPI.h>
#include <SD.h>
#include <RTClib.h>
#define RELE_01 0x01

int maquina = EEPROM.read(0x00);
int indiceGeral = EEPROM.read(0x01);

bool SerialDebug = true;

struct Registros {
  int maquina;
  int codigo;
  int receita;
  int dia;
  int mes;
  int ano;
  int hora;
  int minuto;
  int segundo;
};
class Armazenador {
  private:
    Registros Reg[200];
  public:
    Armazenador() {
      // construtor da classe
    }

    void adicionarRegistro(int indice, int maquina, int codigo, int receita, int dia, int mes, int ano, int hora, int minuto, int segundo) {
      Reg[indice].maquina = maquina;
      Reg[indice].codigo = codigo;
      Reg[indice].receita = receita;
      Reg[indice].ano = ano;
      Reg[indice].dia = dia;
      Reg[indice].mes = mes;
      Reg[indice].ano = ano;
      Reg[indice].hora = hora;
      Reg[indice].minuto = minuto;
      Reg[indice].segundo = segundo;
    }

    void imprimirRegistro(int indice) {
      Serial.print("Registro ");
      Serial.print(indice);
      Serial.print(" | Maquina : ");
      Serial.println(Reg[indice].maquina);
      Serial.print("Funcionario : ");
      Serial.print(Reg[indice].codigo);
      Serial.print(" | Receita : ");
      Serial.println(Reg[indice].receita);
      Serial.print("Data : ");
      Serial.print(Reg[indice].dia);
      Serial.print(" / ");
      Serial.print(Reg[indice].mes);
      Serial.print(" / ");
      Serial.println(Reg[indice].ano + 2000);
      Serial.print("Hora : ");
      Serial.print(Reg[indice].hora);
      Serial.print(" : ");
      Serial.print(Reg[indice].minuto);
      Serial.print(" : ");
      Serial.println(Reg[indice].segundo);
    }
};
class SDCARD {
  private:
    File myFile;
    bool initialized = false;

  public:
    bool begin(int chipSelectPin) {
      if (!SD.begin(chipSelectPin)) {
        Serial.println("Falha ao inicializar o cartão SD.");
        return false;
      }
      initialized = true;
      return true;
    }

    bool open(const char* filename) {
      if (!initialized) {
        Serial.println("Cartão SD não inicializado.");
        return false;
      }

      myFile = SD.open(filename);

      if (myFile) {
        Serial.print("Arquivo ");
        Serial.print(filename);
        Serial.println(" aberto com sucesso.");
        return true;
      } else {
        Serial.println("Erro ao abrir o arquivo.");
        return false;
      }
    }

    void read(char* data, int size) {
      if (!initialized) {
        Serial.println("Cartão SD não inicializado.");
        return;
      }

      if (myFile) {
        myFile.readBytes(data, size);
        Serial.print("Dados lidos: ");
        Serial.println(data);
      } else {
        Serial.println("Erro ao ler o arquivo.");
      }
    }

    void close() {
      if (!initialized) {
        Serial.println("Cartão SD não inicializado.");
        return;
      }

      if (myFile) {
        myFile.close();
        Serial.println("Arquivo fechado.");
      }
    }

    void writeDailyData(float data) {
      if (!initialized) {
        Serial.println("Cartão SD não inicializado.");
        return;
      }

      // Obtém a data e hora atuais
      RTC_DS1307 rtc;
      if (!rtc.begin()) {
        Serial.println("Falha ao inicializar o RTC.");
        return;
      }

      DateTime now = rtc.now();
      char filename[20];
      sprintf(filename, "%04d-%02d-%02d.txt", now.year(), now.month(), now.day());

      // Abre o arquivo correspondente ao dia atual
      open(filename);

      // Escreve os dados no arquivo
      char dataStr[10];
      dtostrf(data, 5, 2, dataStr);
      char line[30];
      sprintf(line, "%02d:%02d:%02d,%s", now.hour(), now.minute(), now.second(), dataStr);
      myFile.println(line);

      // Fecha o arquivo
      close();
    }

    bool readDailyData(float* dataList, int maxSize) {
      if (!initialized) {
        Serial.println("Cartão SD não inicializado.");
        return false;
      }

      // Obtém a data e hora atuais
      RTC_DS3231 rtc;
      if (!rtc.begin()) {
        Serial.println("Falha ao inicializar o RTC.");
        return false;
      }

      DateTime now = rtc.now();
      char filename[20];
      sprintf(filename, "%04d-%02d-%02d.txt", now.year(), now.month(), now.day());

      // Abre o arquivo correspondente ao dia atual
      myFile = SD.open(filename);

      if (myFile) {
        Serial.print("Arquivo ");
        Serial.print(filename);
        Serial.println(" encontrado.");

        // Lê os dados do arquivo e armazena no array
        int i = 0;
        while (myFile.available() && i < maxSize) {
          char line[30];
          myFile.readBytesUntil('\n', line, sizeof(line));
          char* dataStr = strtok(line, ",");
          dataList[i] = atof(dataStr);
          i++;
        }

        // Fecha o arquivo
        myFile.close();

        return true;
      } else {
        Serial.println("Arquivo não encontrado.");
        return false;
      }
    }
};
SDCARD SD1;
Armazenador Funcionario;
File Funcionarios[12];
File Relatorio;
// Exemplo de uso da classe SDCARD
//SDCARD sdcard;
void atualizarDataLogger() {
  //
  Funcionario.adicionarRegistro(0, maquina, 12, 1, 30, 03, 23, 18, 24, 20);
  Funcionario.adicionarRegistro(1, maquina, 12, 2, 30, 03, 23, 18, 24, 20);
  Funcionario.imprimirRegistro(0);  // imprime "Registro 0: 10/3/2022"
  Funcionario.imprimirRegistro(1);  // imprime "Registro 1: 20/7/2023"
}
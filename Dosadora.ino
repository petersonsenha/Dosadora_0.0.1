//Evolução do Código
/*
Peterson Senha - 18/03/2023
* Implementação da Classe Teclado 
* Implementação da Classe State
* Implementação da Classe MedidorNivel

* Implementando FreeRTOS - 22/08/2023
* Implementando Google Sheets - 09/09/2023
Release - 21/04/2023/
* Add DWIN Display 7"
//***************************************************************************/
#include <Arduino_FreeRTOS.h>
// define tasks
void TaskSerial( void *pvParameters );
void TaskButtonReceita( void *pvParameters );
void TaskDisplay( void *pvParameters );

void setupTasks(){
  xTaskCreate(
    TaskSerial
    ,  "Serial"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    TaskButtonReceita
    ,  "ButtonReceita"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

  xTaskCreate(
    TaskDisplay
    ,  "loopDisplay"
    ,  512  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
}
//***************************************************************************/
#include "EEPROM.h"  //Registrar dados dos equipamentos
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

long contPulse=0;
//***************************************************************************/
// Inicializar as classes

//Teclado T1;

//***************************************************************************/
// Funções Gerais do Sistema
void setupInicial(){
  EEPROM.write(0x00, 0x01);
  EEPROM.write(0x01, 0x03);
  EEPROM.write(0x11, 0x00);
  setarAcoes();
  delay(3000);
}


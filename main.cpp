#include "mbed.h"
#include "arm_book_lib.h"
#include "hal/gpio_api.h"
#include "platform/mbed_toolchain.h"
#include "gpio_object.h"

int main()
/**
 * @brief Configura el Pin D1 como entrada digital para conectar un detector de gas.
    Los comentarios en el código corresponden a la versión escrita en C++, 
    el código actual fue modificado para responder las consignas 3) y 4)
 */
{
    gpio_t gasDetector;
    gpio_init_in_ex(&gasDetector, D1,PullDown);

    //DigitalIn gasDetector(D2); /* Constructor de DigitalIn con parámetro pin D2*/
    gpio_t alarmLed;
    gpio_init_out(&alarmLed, LED2);
    
    //DigitalOut alarmLed(LED1);/* Constructor de DigitalOut con parámetro pin LED1*/

    //gasDetector.mode(PullDown);/* Método de DigitalIn para activar resistencia de pulldown*/
    //alarmLed = OFF; /*Asigna a alarmLED el valor OFF */
    gpio_write(&alarmLed, OFF);
    while (true) { //Ciclo infinito
    
        if ( gpio_read(&gasDetector) == ON ) { //Si se detectó gas
            gpio_write(&alarmLed, ON);         // Encender LED
        }
        
        if ( gpio_read(&gasDetector) == OFF ) { //Si no se detectó gas
            gpio_write(&alarmLed, OFF);         // Apagar LED
        }
    }
}

/*
1)¿Qué es Github?
Github es una empresa que provee servicio de Hosting web orientado al desarrollo
de Software colaborativo utilizando la herramienta de control de versiones Git.
5)
+--------------------+---------------------+------------------------+----------+
|   Especificación   |     Arduino Uno     |     NUCLEO-F459ZI      | Unidades |
+--------------------+---------------------+------------------------+----------+
| Largo palabra      | 8                   | 32                     | bits     |
| LED usuario        | 1                   | 1                      | -        |
| Frecuencia máx.    | 16                  | 180                    | MHz      |
| Alimentación       | 7-12                | 3.3,5,7-12             | V        |
| I2C,SPI,USART/UART | si(1,1,1)           | si(3,6,4)              | -        |
| Ethernet           | no                  | si(1)                  | -        |
| Boton usuario      | 0                   | 1                      | -        |
| LED usuario        | 1                   | 3                      | -        |
| ADC                | 1(6 bits)           | 3(12 bits)             | -        |
| DAC                | 1(6 bits)           | 2(12 bits)             | -        |
| Timers             | 3(2x8bits 1x16bits) | 14(12x16bits 2x32bits) | -        |
| RAM                | 2(SRAM)             | 260(SRAM)              | KB       |
| FLASH              | 32                  | 2048                   | KB       |
| EEPROM             | 1                   | -                      | KB       |
+--------------------+---------------------+------------------------+----------+

Fuentes:
https://www.st.com/en/evaluation-tools/nucleo-f429zi.html
https://www.st.com/en/microcontrollers-microprocessors/stm32f429zi.html
https://docs.arduino.cc/hardware/uno-rev3
*/
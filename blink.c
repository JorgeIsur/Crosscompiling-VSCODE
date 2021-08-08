/*
    Autor: Jorge Isur Balderas Ramírez
    Fecha: 7 de agosto de 2021
    Descripción: Manipula los pines GPIO para encender un led, compilado en una 
    computadora con arquitectura x86_64 para un dispositivo arm64 raspberry pi 3 model B+
*/
#include <stdio.h>
#include <pigpio.h>

//Definición del PIN de acuerdo al broadcom
#define LED 7

int main(void)
{
    printf("Hola samsung innovation campus!");
    gpioInitialise();
    gpioSetMode(LED, PI_OUTPUT);
    for (int i = 0; i < 10; i++)
    {
        gpioWrite(LED, 1); //on
        printf("Hola\n");
        gpioDelay(500);  //ms
        gpioWrite(LED,0);  //off
        printf("Adios\n");
        gpioDelay(500);
    }
    
    return 0;
}


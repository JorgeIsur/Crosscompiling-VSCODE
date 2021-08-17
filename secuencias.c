/*
    Autor:
    Fecha:
    Descripción:
    Ejercicio de aplicacion. Hacer un programa para encender 4 leds
    en secuencia exclusiva ascendente durante 5 segundos, encender en secuencia aditiva
    durante 5 segundos, enceder en secuencia descendente exclusiva durante 5 segundos,
    encender en secuencia descendente aditiva durante 5 segundos.
    Repetir en este orden durante durante 30 segundo y repetir en orden inverso durante
    90 segundos minutos. Que esto se realice solo 4 veces. Despues todos los leds se apagan.
    Las exclusivas las tienen que hacer con operadores incrementales o decrementales.
    Las aditivas las tienen que hacer con operadores bitwise.
    Mientras se envia por mqtt una suma incremental mas el valor en binario de la secuencia
    de los leds. Cada estado del led dura 0.2 segundos
    LEDS= 0000
    Secuencia ascendente exclusiva: 0000 1000 0100 0010 0001
    Secuencia aditiva esxclusiva: 0000 1000 1100 1110 1111
    Todo debe ser programado haciendo uso de las logicas no bloqueantes.
    GPIO4--->Pin7
    GPIO27-->Pin13
    GPIO22-->Pin15
    GPIO5--->Pin29
*/
#include <stdio.h>
#include <pigpio.h>
#include <time.h>
//definicion de leds
#define LED 4
#define LED2 27
#define LED3 22
#define LED4 5

int main()
{
    //int repeticiones;
    clock_t inicio, final,control;
    float seconds, control_s;
    clock_t tiempo;
    int opt;
    gpioInitialise();
    gpioSetMode(LED, PI_OUTPUT);
    gpioSetMode(LED2, PI_OUTPUT);
    gpioSetMode(LED3, PI_OUTPUT);
    gpioSetMode(LED4, PI_OUTPUT);
    if (gpioInitialise()<0) return 1; //significa que si no se inicializa, falló
    //printf("Ingresa el número de veces que se repetirá el programa:\t");
    //scanf("%i", &repeticiones);
    do
    {
        printf("Secuencia exclusiva ascendente--->1\n");
        printf("Secuencia aditiva ascendente----->2\n");
        printf("Secuencia exclusiva descendente-->3\n");
        printf("Secuencia aditiva descendente---->4\n");
        printf("Todas---------------------------->5\n");
        printf("Todas(Inverso)------------------->6\n");
        scanf("%i",&opt);
        switch (opt)
        {
        case 1:
            inicio = clock();
            do
            {
                gpioWrite(LED, 1);
                control = clock();
                control_s = (float)(control)/CLOCKS_PER_SEC;
                printf("tiempo:%.2f segundos\n",control_s);
                if (control_s>0.2 && control_s<0.4) {
                  gpioWrite(LED,0);
                  gpioWrite(LED2,1);
                }
                control_s = (float)(control)/CLOCKS_PER_SEC;
                printf("tiempo:%.2f segundos\n",control_s);
                if (control_s>0.4 && control_s<0.6) {
                  gpioWrite(LED2,0);
                  gpioWrite(LED3,1);
                }
                control_s = (float)(control)/CLOCKS_PER_SEC;
                printf("tiempo:%.2f segundos\n",control_s);
                if (control_s>0.6 && control_s<0.8) {
                  gpioWrite(LED3,0);
                  gpioWrite(LED4,1);
                }
                control = 0;
                control_s =0;
                final = clock();
                seconds = (float)(control-inicio)/CLOCKS_PER_SEC;
            }while (seconds<5);
              gpioWrite(LED,0);
              gpioWrite(LED4,0);
              printf("Proceso terminado en %.21f segundos\n", seconds);
              break;
        case 2:
            do
            {
              inicio=time(&inicio);
                gpioWrite(LED,1);
                if (inicio>0.2 && inicio<0.4)
                {
                    gpioWrite(LED2,1);
                }
                if (inicio>0.4 && inicio<0.6)
                {
                    gpioWrite(LED3,1);
                }
                if (inicio>0.6 && inicio<0.8)
                {
                    gpioWrite(LED4,1);
                }
                final=time(&final);
                seconds = difftime(inicio,final);
                printf("Proceso terminado en %.21f segundos\n", seconds);
            } while (seconds<5);
            break;
        case 3:
            tiempo= clock();
            do
            {
                gpioWrite(LED4, 1);
                if (tiempo>0.2 && tiempo<0.4)
                {
                    gpioWrite(LED4,0);
                    gpioWrite(LED3,1);
                }
                if (tiempo>0.4 && tiempo<0.6)
                {
                    gpioWrite(LED3,0);
                    gpioWrite(LED2,1);
                }
                if (tiempo>0.6 && tiempo<0.8)
                {
                    gpioWrite(LED2,0);
                    gpioWrite(LED,1);
                }
            } while (tiempo<5);
            gpioTerminate();
            break;
        case 4:
            tiempo=clock();
            do
            {
                gpioWrite(LED4,1);
                if (tiempo>0.2 && tiempo<0.4)
                {
                    gpioWrite(LED3,1);
                }
                if (tiempo>0.4 && tiempo<0.6)
                {
                    gpioWrite(LED2,1);
                }
                if (tiempo>0.6 && tiempo<0.8)
                {
                    gpioWrite(LED,1);
                }

            } while (tiempo<5);
            gpioTerminate();
            break;
        case 5:
            tiempo= clock();
            do
            {
              gpioWrite(LED, 1);
              if (tiempo>0.2 && tiempo<0.4)
              {
                gpioWrite(LED,0);
                gpioWrite(LED2,1);
              }
              if (tiempo>0.4 && tiempo<0.6)
              {
                gpioWrite(LED2,0);
                gpioWrite(LED3,1);
              }
              if (tiempo>0.6 && tiempo<0.8)
              {
                gpioWrite(LED3,0);
                gpioWrite(LED4,1);
              }
            } while (tiempo<5);
            tiempo=clock();
            do
            {
                gpioWrite(LED,1);
                if (tiempo>0.2 && tiempo<0.4)
                {
                    gpioWrite(LED2,1);
                }
                if (tiempo>0.4 && tiempo<0.6)
                {
                    gpioWrite(LED3,1);
                }
                if (tiempo>0.6 && tiempo<0.8)
                {
                    gpioWrite(LED4,1);
                }

            } while (tiempo<5);
            tiempo= clock();
            do
            {
                gpioWrite(LED4, 1);
                if (tiempo>0.2 && tiempo<0.4)
                {
                    gpioWrite(LED4,0);
                    gpioWrite(LED3,1);
                }
                if (tiempo>0.4 && tiempo<0.6)
                {
                    gpioWrite(LED3,0);
                    gpioWrite(LED2,1);
                }
                if (tiempo>0.6 && tiempo<0.8)
                {
                    gpioWrite(LED2,0);
                    gpioWrite(LED,1);
                }
            } while (tiempo<5);
            tiempo=clock();
            do
            {
                gpioWrite(LED4,1);
                if (tiempo>0.2 && tiempo<0.4)
                {
                    gpioWrite(LED3,1);
                }
                if (tiempo>0.4 && tiempo<0.6)
                {
                    gpioWrite(LED2,1);
                }
                if (tiempo>0.6 && tiempo<0.8)
                {
                    gpioWrite(LED,1);
                }

            } while (tiempo<5);
            gpioTerminate();
            break;
          }
    } while (opt!=0);
    gpioTerminate();
}

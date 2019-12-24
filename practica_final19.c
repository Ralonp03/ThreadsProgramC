/****************Adicion de las bicliotecas**********************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys.types.h>
#include <sys.wait.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <pthread.h>

/****************Declaracion de las variables globales**********************/

const int MAX_SOLICUTUDES=15;
const int ATENDEDORES_SOLICITUD=3;
const int ATENDEDORES_QR=1;
const int ATENDEDOR_PRO=1;
const int ANTEDEDORES_TOTALES=5;

/******Lista de 15 usuarios********/
struct usuarios{
	int id;
	int atendido;
	int tipo;
	pthread_t hiloUsuarios;
		};
struct usuarios atendidos[15];

/*******Lista de 4 usuarios en actividad social*****/


/************Fichero log**********/
FILE *fichero;
const char *FICHERO= "tsnumamiApp.log"; 


/****************Main**********************/
int main(int argc, char *argv[]){

/*******Imprimimos el menu por pantalla********/
printf("Menu:\n");
printf("Introduzca kill -10 PID para solicitud por invitacion\n");
printf("Introduzca kill -12 PID para solicutud por QR\n");
printf("Introduzca kill -2 PID para terminar el programa\n");



/****************SIGUSR1,solicitud por invitacion**********************/
sigaction(SIGUSR1,&e, NULL);

/****************SIGUSR2,solicitud por QR**********************/
sigaction(SIGUSR2,&e, NULL);

/****************SIGINT,terminar**********************/
sigaction(SIGINT,&e, NULL);

/***********Inicializar recursos******************/

/****************a.Semaforos**********************/
pthread_mutex_init( ,NULL);
pthread_mutex_init( ,NULL);

/****************b.Contador de Solicitudes**********************/
ContadorSolicitudes=0;

/****************c.Lista de solicitudes id 0, atendido 0, facturado 0**********************/
ContadorSolicitudes=0;


return 0;
}


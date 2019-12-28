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
const int ATENDEDORES_SOLICITUD=1;
const int ATENDEDORES_QR=1;
const int ATENDEDOR_PRO=1;
const int ANTEDEDORES_TOTALES=3;

/******Lista de 15 solicutudes********/
struct solicitudes{
	int id;
	int atendido;
	int tipo;
	int facturado;
	pthread_t hiloUsuarios;
		};
struct solicitudes atendidos[15];

/*******Lista de 3 trabajdadores*****/
struct atendedores{
int solicitudesHechas;
	 int idAtendedor;
	int ocupado;
	int tipoAtendedor;
pthread_t hiloAntededor;
}struct atendedores trabajadores[3];

/*******Lista de 4 usuarios*****/
struct usuario{
int idUsuario;
 int actividad;
 pthread_t listaUserActividad;
}struct usuario manifestantes[4];



/************Fichero log**********/
FILE *fichero;
const char *FICHERO= "registroTiempos.log";

/**********Semaforos*****************/

pthread_mutex_t semaforoFichero;

pthread_mutex_t semaforoColaSolicitud;

pthread_mutex_t semaforoColaSocial;

/******funciones*******************/

int calcularAleatorios(int min, int max);
void nuevaSolicitud(int sig);
void salirPrograma();
void writeLogMessage(char *id, char *msg)
void *trabajoAtendedor(void *idAtendedor);
void *trabajoCoordinador(void *arg);


/****************Main**********************/
int main(int argc, char *argv[]){

//fecha hora del sistema para calcularAleatorio
srand(time(NULL));

/*******Imprimimos el menu por pantalla********/
printf("*****BIENVENIDO AL TSUNAMI DEMOCRATICO*****\n);
printf("Menu:\n");
printf("Introduzca kill -10 PID para solicitud por invitacion\n");
printf("Introduzca kill -12 PID para solicutud por QR\n");
printf("Introduzca kill -2 PID para terminar el programa\n");
pritnf("Esperando...\n);


/*********Estructura sigaction*****/

struct sigaction e,s;
a.sa_handler=solicitud;
b.sa_handler=salirPrograma;

/****************SIGUSR1,solicitud por invitacion**********************/
sigaction(SIGUSR1,&a, NULL);

/****************SIGUSR2,solicitud por QR**********************/
sigaction(SIGUSR2,&a, NULL);

/****************SIGINT,terminar**********************/
sigaction(SIGINT,&b, NULL);

/***********Inicializar recursos******************/

/****************a.Semaforos**********************/

pthread_mutex_init(&semaforoFichero, NULL);
pthread_mutex_init(&semaforoColaSolicitud, NULL);
pthread_mutex_init(&semaforoColaSocial, NULL);

/****************b.Contador de Solicitudes**********************/
ContadorSolicitudes=0;

/****************c.Lista de solicitudes id 0, atendido 0, facturado 0**********************/
int j;
for(j=0; i< MAX_SOLICUTUDES ; j++){
	usuario[j].id=0;
	usuario[j].atendido=0;
	usuario[j].tipo=0;
	usuario[j].facturado=0;
	}
/*****e.Lista de solicitudes para actividades sociales******/


for(j=0; i< ATENDEDORES_SOLICITUD ; j++){
	atendedor[j].solicitudesHechas=0;
	atendedor[j].idAtendedor=j;
	atendedor[j].ocupado=0;
	}
	atendedor[0].tipoAtendedor=1;
	atendedor[0].tipoAtendedor=2;
	atendedor[0].tipoAtendedor=3;



/*****f.fichero de Log******/

fichero = fopen ( "registroTiempos.log", "w" );

char primeroLog[100];
char AplicacionTsunami[100];
sprintf(AplicacionTsunami, "Talleres Manolo");
sprintf(primeroLog, "Apertura");
writeLogMessage(AplicacionTsunami, primeroLog);

/***g.variables condicion***/


/****Creamos 3 hilos atendedor******/
int t;
	for(t=0;t<ANTEDEDORES_TOTALES;t++){
	pthread_create(&atendedores[t].hiloAntededor, NULL,trabajoAtendedor, (void *)[t]trabajadores.idAtendedor);
	}

pthread_create(&coordinador,NULL,trabajoCoordinador,NULL);

/*****Esperamos a la señal de forma infinita******/

	while(1){
		pause();
	}




}

/******funcion CalculaAleatorios******/
int calculaAleatorios(int min, int max) {
return rand() % (max-min+1) + min;
}

/*****funcion escribir en log****/

void writeLogMessage(char *id, char *msg) {
//controlamos el acceso por semaforo
pthread_mutex_lock(&semaforoFichero);
// Calculamos la hora actual
time_t now = time(0);
struct tm *tlocal = localtime(&now);
char stnow[19];
strftime(stnow, 19, "%d/%m/%y %H:%M:%S", tlocal);
// Escribimos en el log
logFile = fopen(logFileName, "a");
fprintf(logFile, "[%s] %s: %s\n", stnow, id, msg);
fclose(logFile);
//Controlamos por semaforos
pthread_mutex_unlock(&semaforoFichero);
}

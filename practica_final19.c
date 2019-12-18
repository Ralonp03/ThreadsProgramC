/*Añadimos bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys.types.h>
#include <sys.wait.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>


/*Declaracion de las variables globales*/
FILE *Fichero;
String colaSolicitudes[15];
String colaSocial=15;
String usuarios[15];
String contador_Solicitudes;
String id;
bool atndido;
String tipo;
String usuarios_Actividad[4];
bool Atendedores;
FILE *logFile;

int main(){
	String Invitacion;
	struct signal ss;
	switch (fork())
	{
		case -1:
			perror("fork");
			return 1;
		case 0:
			for(;;)
				pause();
		default:
			ss.sa_handler;
			if(-1==signal(SIGUSR1, &ss, NULL))

	}
		
	

}

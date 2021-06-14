/*
 ============================================================================
 Name        : abalone.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * main.c
 *
 *  Created on: 20 giu 2017
 *      Author: peppi
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "accesso_dati.h"
#include "funzioni.h"
#include "globali.h"


char matrice[20][20]={"ooooo","oooooo","++ooo++","++++++++","+++++++++","++++++++","++@@@++","@@@@@@","@@@@@",};


int i;
int scelta;
int p;
int g=0;
int inizio;

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int controllo=0;
int ritorno=0;

int main(){
	while(g!=5){
		p=0;
	while(p==0){
		g=0;
	printf("ABALONE\n\n\n");
	printf("1. Nuova Partita\n");
	printf("2. Carica Partita \n");
	printf("3. Modifica impostazioni\n");
	printf("4. Regole del Gioco\n");
	printf("5. Esci\n");
	printf("\n\nDigita il numero per avviare la tua scelta: ");
	scanf(" %d",&g);
	if(g==2 || g==3 || g==1 || g==4 || g==5){
	p=1;
	}
}
if(g==4){
	regole();
}
if(g==3){
	ritorno=impostazioni(inizio);
}
//printf("ritorno e %d", ritorno);
//getch();
if(g==2){
	carica(matrice);
}
if(g==1){
	if(ritorno==2){
		sposta1(matrice);
	}
	while(i!=1){
		system("CLS");
	visualizzamatrice();

	//	printf("controlla");
		//getch();
	getch();
	if(ritorno!=2){
	controllo=ai(matrice);
	if(controllo==6){
		printf("HAI VINTO");
		i=1;
		getch();
		break;
	}
	if(controllo==5){
		printf("HAI PERSO");
		i=1;
		getch();
		break;
	}
	}
	controllo=sposta(matrice);
	if(controllo==6){
		printf("HAI VINTO");
		i=1;
		getch();
		break;
	}
	if(controllo==5){
		printf("HAI PERSO");
		i=1;
		getch();
		break;
	}
	if(controllo==9){
		printf("ARRIVEDERCI");
		i=1;
		getch();
		break;
	}

	}
	system("PAUSE");
}
system("CLS");
	}

printf("ciao");
system("PAUSE");
return 0;
}



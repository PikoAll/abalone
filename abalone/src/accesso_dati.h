/*
 * accesso_dati.h
 *
 *  Created on: 14 ott 2019
 *      Author: peppi
 */


#ifndef ACCESSO_DATI_H_
#define ACCESSO_DATI_H_


char carica(char matrice[20][20]);
void regole();
int impostazioni(int inizio);
char carica(char matrice[20][20]);
char matrice[20][20];
void visualizzamatrice();
int nuovapartita(char matrice[20][20]);
int sposta(char matrice[20][20]);
int sposta1(char matrice[20][20]);
int salva(char matrice[20][20]);
void  GotoXY(int x, int  y);

#endif /* ACCESSO_DATI_H_ */




/*
 * accesso_dati.c
 *
 *  Created on: 14 ott 2019
 *      Author: peppi
 */


/*
 * accesso_dati.c
 *
 *  Created on: 20 giu 2017
 *      Author: peppi
 */


#include "accesso_dati.h"
#include "funzioni.h"
#include "globali.h"


#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int i;
int scelta;
int p;
int inizio;


void regole()
{

int MAX=80;
int riga;
/// vettore di caratteri TESTO[MAX]
char TESTO[MAX];
FILE *f;
f=fopen("regolamento.txt","r");
if (f==NULL) {printf("Errore apertura file");
return ;}

system("cls");

while (!feof(f)/* && riga<25*/)
{fgets(TESTO,MAX,f);
 riga++;
 printf("%s\n",TESTO);

}

fclose(f);

printf("\n\nPremi un tasto per continuare");
getch();

system("cls");
return ;
}


/** \fn int impostazioni (int inizio)
 *  Funzione impostazioni generali del gioco
 * \return 1 per giocare utente vs pc.
 * \return 2 per giocare utente vs utente.
 */
int impostazioni(int inizio)
{
	void setcolor(unsigned short color)
	  {
	 HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleTextAttribute(hCon,color);
	  }
	int p=0;
	int x;
	int g=0;
	while(p==0){
			system("CLS");
			printf("Abalone Impostazioni\n\n\n");
			printf("1. Impostazione colori\n");
			printf("2. Impostazione Numero Giocatori \n");
			printf("3. Esci\n");
			printf("\n\nDigita il numero per avviare la tua scelta: ");
			scanf("%d",&g);
			if(g==2 || g==3 || g==1){
			p=1;
			}
		}
	p=0;

	if(g==1){
	while(p==0){
		system("CLS");
		printf("ABALONE COLORI\n\n\n");
		printf("1. Verde Acqua\n");
		printf("2. Rosso \n");
		printf("3. Giallo\n");
		printf("4. Blu\n");
		printf("5. Marrone\n");
		printf("6. Esci\n");
		printf("\n\nDigita il numero per avviare la tua scelta: ");
		scanf("%d",&g);
		if(g==2 || g==3 || g==1 || g==4 || g==5 || g==6){
		p=1;
		}
	}
		if(g==1){
			setcolor(3);
		}
	if(g==2){
		setcolor(4);
	}
	if(g==3){
		setcolor(14);
	}
	if(g==4){
		setcolor(1);
	}
	if(g==5){
		setcolor(6);
	}
	g=0;}
	p=0;
	if(g==2){
		g=0;
		while(p==0){
				system("CLS");
				printf("Abalone Impostazione Numero Giocatori\n\n\n");
				printf("1. Utente vs Pc\n");
				printf("2. Utente vs Utente \n");
				printf("3. Esci\n");
				printf("\n\nDigita il numero per avviare la tua scelta: ");
				scanf("%d",&g);
				if(g==2 || g==3 || g==1){
				p=1;
				}
			}
		if(g==1){
			return 1;
		}
		if(g==2){
			return 2;
		}
	}
	system("CLS");
return 0;
}

/** \fn char carica (char matrice [20][20])
 *  Funzione carica ultimo salvataggio
 * \param matrice di caratteri vuota
 * \return -1 se la partita era gia finita.
 * \return matrice[20][20] con le posizioni delle pedine .
 */
char carica(char matrice[20][20])
{
	int MAX=401;
	/// variabile j utilizzata come contatore
	int j=0;
	/// variabile k utilizzata come contatore
	int k=0;
	int controllo=0;

	FILE *f;
	f=fopen("dati.txt","r");
	if (f==NULL) {
		printf("Errore apertura file");
		getch();
		return 0;}
	//system("cls");
	//printf("ciao\n");
	//getch();
	i=0;
	j=0;
	while (!feof(f)/* && riga<25*/)
	{//fgets(TESTO, 200, f);
		i=0;
		while(i<20){
			j=0;
			while(j<20){
		fscanf(f, "%c\n",&matrice[i][j]);
		j++;
		  }
			i++;
		}
	}
	fclose(f);
	printf("\n");
	while(i!=1){
	system("cls");
	visualizzamatrice();



	controllo=ai(matrice);
		if(controllo==6){
			printf("HAI VINTO");
			i=1;
			getch();
			return -1;
		}
		if(controllo==5){
			printf("HAI PERSO");
			i=1;
			getch();
			return -1;
		}
		controllo=sposta(matrice);
		if(controllo==6){
			printf("HAI VINTO");
			i=1;
			getch();
			return -1;
		}
		if(controllo==5){
			printf("HAI PERSO");
			i=1;
			getch();
			return -1;
		}
		if(controllo==9){
			printf("ARRIVEDERCI");
			i=1;
			getch();
			return -1;
		}
	}




	return matrice[i][j];
}



//*******************************************************************************************

///fn void visualizzamatrice()

void visualizzamatrice()
{
	/// variabile i utilizzata come contatore
int i=0;
/// variabile j utilizzata come contatore
int j;
	while(i<20){
			j=0;
			if(i==0){GotoXY(4,0);printf("I  ");}
			if(i==1){GotoXY(3,1);printf("H  ");}
			if(i==2){GotoXY(2,2);printf("G  ");}
			if(i==3){GotoXY(1,3);printf("F  ");}
			if(i==4){GotoXY(0,4);printf("E  ");}
			if(i==5){GotoXY(1,5);printf("D  ");}
			if(i==6){GotoXY(2,6);printf("C  ");}
			if(i==7){GotoXY(3,7);printf("B  ");}
			if(i==8){GotoXY(4,8);printf("A  ");}
			if(i==9){GotoXY(7,9);printf(" 1 2 3 4 5");}

			while(j<20){
				if(matrice[i][j]!=0){
					if(matrice[i][j]=='1'){
						printf("@ ");
					}else if(matrice[i][j]=='2'){
					printf("o ");
					}else{
				printf("%c ",matrice[i][j]);}
				}
				j++;
			}
			if(i==5){printf(" 9");}
			if(i==6){printf(" 8");}
			if(i==7){printf(" 7");}
			if(i==8){printf(" 6");}
			i++;
		}
	return ;
}

/** \fn int sposta (char matrice[20][20])
 *  Funzione che permette all'utente di spostare le pedine utente vs pc
 *  \param matrice piena di caratteri
 * \return 9 per salvare la partita.
 * \return 6 se l'utente ha vinto.
 * \return 0 se l'utente ha spostato le pedine.
 */

int sposta(char matrice [20][20])
{
	int confronto(char matrice[20][20], int m, int n, int lettera1, int numero1);
	int salva(char matrice[20][20]);
	int npds2;
		int lpds2;
		int lds2;
			int nds2;
	char c;
	int m;
	char continua;
	int n;
	/// variabile i utilizzata come contatore
	int i;
	/// variabile fl utilizzato come booleano
	int fl=0;
	/// variabile fl4 utilizzato come booleano
	int fl4=0;
	/// variabile fl5 utilizzato come booleano
	int fl5=0;
	int g;
	int p;
	int npds1;
	int lpds1;
	int lettera1;
	int numero1;
	/// variabile fl3 utilizzato come booleano
	int fl3;
	/// variabile fl1 utilizzato come booleano
	int fl1;
	int lds1;
	int nds1;
	int riga1;
	int colonna1;
	int mio;
	int mia;
	int colonna;
	int riga;
	/// variabile fl6 utilizzato come booleano
	int fl6;
	/// variabile fl7 utilizzato come booleano
	int fl7;
	int j;
	int hhh=0;
	int ritorna=0;
	int perdi=0;

	int a, l, s,e;
	GotoXY(0,11);
			i=0;
			while(i<3){
				GotoXY(0,11);
				fl7=0;
				while(fl7==0){
				fl6=0;
				while(fl6==0){
				fl5=0;
				while(fl5==0){
				fl4=0;
				while(fl4==0){
				fl3=0;
				while(fl3==0){
				fl1=0;
				while(fl1==0){
		fl=0;
			while(fl==0){
				if(i>0){
				p=0;
						hhh=0;
						GotoXY(0,11);
								if(i!=3){
								while(p<1){
								printf("sei sicuro di voler spostare un altra pedina? s/n \n");
								printf("oppure clicca w per salvare la  ed uscire dal gioco: ");
								scanf(" %c", &continua);
								if(continua=='s'){
									p++;
								}
								if(continua=='n'){
									hhh=1;
									p++;
									i=3;
								}
								if(continua=='w'){
									salva(matrice);
									//printf("hello ciao");
								//	getch();
												return 9;
											}
								}
								}
				}
				system("CLS");
				visualizzamatrice();
								if(hhh!=1){


				GotoXY(0,11);
				printf("utente 1\n");
					printf("inserisci cordinate lettera della %d* pedina da spostare: ",i+1);
								scanf(" %c",&c);
								if(c=='i'||c=='h'||c=='g'||c=='f'||c=='e'||c=='d'||c=='c'||c=='b'||c=='a'){
								if(c=='i'){m=0;}
								if(c=='h'){m=1;}
								if(c=='g'){m=2;}
								if(c=='f'){m=3;}
								if(c=='e'){m=4;}
								if(c=='d'){m=5;}
								if(c=='c'){m=6;}
								if(c=='b'){m=7;}
								if(c=='a'){m=8;}
								fl=1;
								}else{
									printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
									getch();
									system("CLS");
									visualizzamatrice();
									fl=0;
								}
								}
								if(hhh==1){
									fl=1;
								}

		}//fl
			if(hhh!=1){
			printf("inserisci coordinata numero della %d* pedina da spostare ",i+1);
			scanf(" %d", &n);

			n=n-1;
			if(matrice[m][n]!='@'){
				fl1=0;
				printf("errore coordinata premi un pulsante per riinserire coordinata");
				getch();
				system("CLS");
				visualizzamatrice();
			}else{
				fl1=1;
			}
			}
			if(hhh==1){
				fl1=1;
			}
		}//fl1
				if(hhh!=1){
			lettera1=m;
			numero1=n;
			printf("inserisci cordinate lettera della %d* pedina dove vuoi spostare: ",i+1);
											scanf(" %c",&c);
											if(c=='i'||c=='h'||c=='g'||c=='f'||c=='e'||c=='d'||c=='c'||c=='b'||c=='a'){
											if(c=='i'){m=0;}
											if(c=='h'){m=1;}
											if(c=='g'){m=2;}
											if(c=='f'){m=3;}
											if(c=='e'){m=4;}
											if(c=='d'){m=5;}
											if(c=='c'){m=6;}
											if(c=='b'){m=7;}
											if(c=='a'){m=8;}
											fl3=1;
											}else{
												printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
												getch();
												system("CLS");
												visualizzamatrice();
												fl3=0;
											}
				}
				if(hhh==1){
					fl3=1;
				}
				}//fl3
				if(hhh!=1){
				printf("inserisci coordinata numero della %d* pedina dove vuoi spostare ",i+1);
							scanf(" %d",&n);
							n=n-1;
							if(matrice[m][n]=='o'){
								//printf(" m e %d n e %d\n", m,n);
							//	getch();
								ritorna=confronto(matrice,m,n,lettera1,numero1);
							} else if(matrice[m][n]!='+'){

								fl4=0;
								printf("non puoi spostare li la pedina premi un tasto per riselezionarla");
								getch();
								system("CLS");
								visualizzamatrice();
							}else{
								fl4=1;
							}
				}
				if(hhh==1){
					fl4=1;
				}
				if(ritorna==1){
					fl4=1;
				}
				}//fl4
				if(ritorna==1){
						break;
								}
				if(hhh!=1){
			g=0;
			p=0;
			if(m==lettera1 || m-1==lettera1 || m+1==lettera1){
				g=1;
			}
			if(n==numero1 || n-1==numero1 || n+1==numero1){
				p=1;
			}
			//printf("g e %d p e %d", g,p);
			//getch();
	//QUESTO SOTTO COMMENTO DAVA FORSE PROBLEMI
			if(lettera1-1==m && numero1-1==n){
				g=0;
				p=0;
			}
		//	printf(" i e %d", i);
		//	getch();
//**********************************************
			if(i==0 && g==1 && p==1){
							matrice[lettera1][numero1]='+';
							matrice[m][n]='1';
							fl6=1;
							fl7=1;
							fl5=1;
						}
//****************************************
			if(g==1 && p==1){
				fl5=1;
			}else{
				printf("coordinate non adiacenti premi un tasto per riselezionare coordinate");
				getch();
				system("CLS");
				visualizzamatrice();
				fl5=0;
			}
			}
				if(hhh==1){
					fl5=1;
				}
				if(ritorna==1){
									fl5=1;
								}
				}//fl5
				if(ritorna==1){
										break;
												}
				if(hhh!=1){
// QUESTO SOTTO COMMENTO E STATO COPIATO SU RIGA 1454
			/*if(i==0 && g==1 && p==1){
				matrice[lettera1][numero1]='+';
				matrice[m][n]='1';
				fl6=1;
				fl7=1;
			}*/
			if(i==0){
				lpds1=lettera1;
				npds1=numero1;
				lds1=m;
				nds1=n;
				colonna=0;
				riga=0;
				if(m+1==lettera1){
					riga=2;
				}
				if(m-1==lettera1){
					riga=1;
				}
				if(m==lettera1){
					riga=0;
				}
				if(n+1==numero1){
					colonna=1;
				}
				if(n-1==numero1){
					colonna=2;
				}
				if(n==colonna1){
					colonna=0;
				}
			}
			if(i==1){
				lpds2=lettera1;
				npds2=numero1;
				lds2=m;
				nds2=n;
			}
			if(i==1 && g==1 && p==1){
				a=0;
				l=0;
				if(lettera1==lpds1 || lettera1+1==lpds1 || lettera1-1==lpds1){
					a=1;
				}
				if(numero1==npds1 || numero1+1==npds1 || numero1-1==npds1){
					l=1;
				}
			if(a==1 && l==1){
				s=0;
				e=0;
				if(m==lds1 || m+1==lds1 || m-1==lds1){
					s=1;
				}
				if(n==nds1 || n+1==nds1 || n-1==nds1){
					e=1;
				}
				if(s==1 && e==1){
					riga1=0;
					colonna1=0;
					if(m+1==lettera1){
										riga1=2;
									}
									if(m-1==lettera1){
										riga1=1;
									}
									if(m==lettera1){
										riga1=0;
									}
									if(n+1==numero1){
										colonna1=1;
									}
									if(n-1==numero1){
										colonna1=2;
									}
									if(n==numero1){
										colonna1=0;
									}
									mio=0;
									mia=0;
							if(riga==riga1){
								mio=1;
							}
							if(colonna==colonna1){
								mia=1;
							}
							if(mio==1 && mia==1){
								matrice[lettera1][numero1]='+';
								matrice [m][n]='1';
								fl6=1;

							}else{
								printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
								fl6=0;
								getch();
								system("CLS");
								visualizzamatrice();
							}
				}else{
					printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
													fl6=0;
													getch();
													system("CLS");
													visualizzamatrice();
				}
			}else{
				printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
											fl6=0;
											getch();
											system("CLS");
											visualizzamatrice();
			}
			}

			if(i==1){
				fl7=1;
			}
			if(i==2){
				fl6=1;
			}
				}
				if(hhh==1){
					fl6=1;
				}
				if(ritorna==1){
									fl6=1;
								}
			}//fl6
				if(ritorna==1){
										break;
												}
				if(hhh!=1){

				if(i==2 && g==1 && p==1){
								a=0;
								l=0;
								if((lettera1==lpds1 && lettera1==lpds2) || (lettera1+2==lpds1 && lettera1+1==lpds2) || (lettera1-2==lpds1 && lettera1-1==lpds2)){
									a=1;
								}
								if((numero1==npds1 && numero1==npds2) || (numero1+2==npds1 && numero1+1==npds2) ||( numero1-2==npds1 && numero1-1==npds2)){
									l=1;
									}
							if(a==1 && l==1){
								s=0;
								e=0;
								if((m==lds1 && m==lds2) || (m+2==lds1 && m+1==lds2) || (m-2==lds1 && m-1==lds2)){
									s=1;
								}
								if((n==nds1 && n==nds2) || (n+2==nds1 && n+1==nds2) || (n-2==nds1 && n-1==nds2)){
									e=1;
								}
								//printf("e e %d s e %d",e,s);
								//getch();
								if(s==1 && e==1){
									riga1=0;
									colonna1=0;
									if(m+1==lettera1){
														riga1=2;
													}
													if(m-1==lettera1){
														riga1=1;
													}
													if(m==lettera1){
														riga1=0;
													}
													if(n+1==numero1){
														colonna1=1;
													}
													if(n-1==numero1){
														colonna1=2;
													}
													if(n==colonna1){
														colonna1=0;
													}
													mio=0;
													mia=0;
											if(riga==riga1){
												mio=1;
											}
											if(colonna==colonna1){
												mia=1;
											}

											if(mio==1 && mia==1){
												matrice[lettera1][numero1]='+';
												matrice [m][n]='1';
												fl7=1;
											}else{
												printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
												fl7=0;
												getch();
												system("CLS");
												visualizzamatrice();
											}
								}else{
									printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																				fl7=0;
																				getch();
																				system("CLS");
																				visualizzamatrice();
								}

							}else{
								printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																			fl7=0;
																			getch();
																			system("CLS");
																			visualizzamatrice();

							}
				}
				}
				if(hhh==1){
					fl7=1;
				}
				if(ritorna==1){
									fl7=1;
								}
							}//fl7
				system("CLS");
				visualizzamatrice();
				GotoXY(0,11);
				/*p=0;
				g=0;
				if(i!=2){
				while(p<1){
				printf("vuoi spostare un altra pedina? s/n");
				scanf(" %c", &continua);
				if(continua=='s'){
					p++;
				}
				if(continua=='n'){
					g=1;
					p++;
				}
				}
				}
				if(g==1){
				break ;
				}*/
				if(ritorna==1){
									i=4;
								}
system("CLS");
visualizzamatrice();
i++;			}//i<3

i=0;
while(i<20){
	j=0;
	while(j<20){
		if(matrice[i][j]=='1'){
			matrice[i][j]='@';
		}
		j++;
	}
	i++;
}
i=0;
perdi=0;
while(i<20){
	j=0;
	while(j<20){
		if(matrice[i][j]=='@'){
			perdi=perdi+1;
		}
		j++;
	}
	i++;
}
if(perdi==8){
	return 5;
}

i=0;
perdi=0;
while(i<20){
	j=0;
	while(j<20){
		if(matrice[i][j]=='o'){
			perdi=perdi+1;
		}
		j++;
	}
	i++;
}
if(perdi==8){
	return 6;
}
return 0;
}//funzione sposta

/** \fn int salva (char matrice[20][20])
 *  Funzione salva partita
 *  \param matrice piene di caratteri.
 * \return 0 al salvataggio della matrice su un file
 */

int salva(char matrice[20][20])
{
	char dato;
	/// variabile j utilizzata come contatore
	int j=0;
	/// variabile i utilizzata come contatore
	int i=1;
	FILE *fd;
	fd=fopen("dati.txt","w");
	if (fd==NULL) {printf("Errore apertura file"); return 0;}

	//dato=n;
i=0;
	while (i<20){
		j=0;
		while(j<20){
			dato=matrice[i][j];
			fprintf(fd, "%c\n", dato);
	j++;	}
	i++;
	}

	fclose(fd);
	return 0;
}

/** \fn int sposta (char matrice[20][20])
 *  Funzione che permette all'utente di spostare le pedine utente vs utente
 *  \param matrice piena di caratteri
 * \return 9 per salvare la partita.
 * \return 6 se l'utente ha vinto.
 * \return 0 se l'utente ha spostato le pedine.
 */

int sposta1(char matrice [20][20])
{
	int confronto_cpu1(char matrice[20][20], int m, int n, int lettera1, int numero1);
	int salva(char matrice[20][20]);
	int npds2;
		int lpds2;
		int lds2;
			int nds2;
	char c;
	int m;
	char continua;
	int n;
	/// variabile i utilizzata come contatore
	int i;
	/// variabile fl utilizzato come booleano
	int fl=0;
	/// variabile fl4 utilizzato come booleano
	int fl4=0;
	/// variabile fl5 utilizzato come booleano
	int fl5=0;
	int g;
	int p;
	int k=0;
	int npds1;
	int lpds1;
	int lettera1;
	int numero1;
	/// variabile fl3 utilizzato come booleano
	int fl3;
	/// variabile fl1 utilizzato come booleano
	int fl1;
	int lds1;
	int nds1;
	int riga1;
	int colonna1;
	int mio;
	int mia;
	int colonna;
	int riga;
	/// variabile fl6 utilizzato come booleano
	int fl6;
	/// variabile fl7 utilizzato come booleano
	int fl7;
	/// variabile j utilizzata come contatore
	int j;
	int hhh=0;
	int ritorna=0;
	int perdi=0;

	int a, l, s,e;
	GotoXY(0,11);
			i=0;
			while(i<3){
				GotoXY(0,11);
				fl7=0;
				while(fl7==0){
				fl6=0;
				while(fl6==0){
				fl5=0;
				while(fl5==0){
				fl4=0;
				while(fl4==0){
				fl3=0;
				while(fl3==0){
				fl1=0;
				while(fl1==0){
		fl=0;

			while(fl==0){
				if(i>0){
				p=0;

						hhh=0;
						GotoXY(0,11);
								if(i!=3){
								while(p<1){
								printf("sei sicuro di voler spostare un altra pedina? s/n \n");
								printf("oppure clicca w per salvare la  ed uscire dal gioco: ");
								scanf(" %c", &continua);
								if(continua=='s'){
									p++;
								}
								if(continua=='n'){
									hhh=1;
									p++;
									i=3;
								}
								if(continua=='w'){
									salva(matrice);
									//printf("hello ciao");
									//getch();
												return 9;
											}
								}
								}
				}
				system("CLS");
				visualizzamatrice();
								if(hhh!=1){


				GotoXY(0,11);
				printf("utente 2\n");
					printf("inserisci cordinate lettera della %d* pedina da spostare: ",i+1);
								scanf(" %c",&c);
								if(c=='i'||c=='h'||c=='g'||c=='f'||c=='e'||c=='d'||c=='c'||c=='b'||c=='a'){
								if(c=='i'){m=0;}
								if(c=='h'){m=1;}
								if(c=='g'){m=2;}
								if(c=='f'){m=3;}
								if(c=='e'){m=4;}
								if(c=='d'){m=5;}
								if(c=='c'){m=6;}
								if(c=='b'){m=7;}
								if(c=='a'){m=8;}
								fl=1;
								}else{
									printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
									getch();
									system("CLS");
									visualizzamatrice();
									fl=0;
								}
								}
								if(hhh==1){
									fl=1;
								}

		}//fl
			if(hhh!=1){
			printf("inserisci coordinata numero della %d* pedina da spostare ",i+1);
			scanf(" %d", &n);

			n=n-1;
			if(matrice[m][n]!='o'){
				fl1=0;
				printf("errore coordinata premi un pulsante per riinserire coordinata");
				getch();
				system("CLS");
				visualizzamatrice();
			}else{
				fl1=1;
			}
			}
			if(hhh==1){
				fl1=1;
			}
		}//fl1
				if(hhh!=1){
			lettera1=m;
			numero1=n;
			printf("inserisci cordinate lettera della %d* pedina dove vuoi spostare: ",i+1);
											scanf(" %c",&c);
											if(c=='i'||c=='h'||c=='g'||c=='f'||c=='e'||c=='d'||c=='c'||c=='b'||c=='a'){
											if(c=='i'){m=0;}
											if(c=='h'){m=1;}
											if(c=='g'){m=2;}
											if(c=='f'){m=3;}
											if(c=='e'){m=4;}
											if(c=='d'){m=5;}
											if(c=='c'){m=6;}
											if(c=='b'){m=7;}
											if(c=='a'){m=8;}
											fl3=1;
											}else{
												printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
												getch();
												system("CLS");
												visualizzamatrice();
												fl3=0;
											}
				}
				if(hhh==1){
					fl3=1;
				}
				}//fl3
				if(hhh!=1){
				printf("inserisci coordinata numero della %d* pedina dove vuoi spostare ",i+1);
							scanf(" %d",&n);
							n=n-1;
							if(matrice[m][n]=='@'){
								//printf(" m e %d n e %d\n", m,n);
								//getch();
								ritorna=confronto_cpu1(matrice,m,n,lettera1,numero1);
							} else if(matrice[m][n]!='+'){

								fl4=0;
								printf("non puoi spostare li la pedina premi un tasto per riselezionarla");
								getch();
								system("CLS");
								visualizzamatrice();
							}else{
								fl4=1;
							}
				}
				if(hhh==1){
					fl4=1;
				}
				if(ritorna==1){
					fl4=1;
				}
				}//fl4
				if(ritorna==1){
						break;
								}
				if(hhh!=1){
			g=0;
			p=0;
			if(m==lettera1 || m-1==lettera1 || m+1==lettera1){
				g=1;
			}
			if(n==numero1 || n-1==numero1 || n+1==numero1){
				p=1;
			}
			//printf("g e %d p e %d", g,p);
			//getch();
	//QUESTO SOTTO COMMENTO DAVA FORSE PROBLEMI
			if(lettera1-1==m && numero1-1==n){
				g=0;
				p=0;
			}
			//printf(" i e %d", i);
			//getch();
//**********************************************
			if(i==0 && g==1 && p==1){
							matrice[lettera1][numero1]='+';
							matrice[m][n]='1';
							fl6=1;
							fl7=1;
							fl5=1;
						}
//****************************************
			if(g==1 && p==1){
				fl5=1;
			}else{
				printf("coordinate non adiacenti premi un tasto per riselezionare coordinate");
				getch();
				system("CLS");
				visualizzamatrice();
				fl5=0;
			}
			}
				if(hhh==1){
					fl5=1;
				}
				if(ritorna==1){
									fl5=1;
								}
				}//fl5
				if(ritorna==1){
										break;
												}
				if(hhh!=1){
// QUESTO SOTTO COMMENTO E STATO COPIATO SU RIGA 1454
			/*if(i==0 && g==1 && p==1){
				matrice[lettera1][numero1]='+';
				matrice[m][n]='1';
				fl6=1;
				fl7=1;
			}*/
			if(i==0){
				lpds1=lettera1;
				npds1=numero1;
				lds1=m;
				nds1=n;
				colonna=0;
				riga=0;
				if(m+1==lettera1){
					riga=2;
				}
				if(m-1==lettera1){
					riga=1;
				}
				if(m==lettera1){
					riga=0;
				}
				if(n+1==numero1){
					colonna=1;
				}
				if(n-1==numero1){
					colonna=2;
				}
				if(n==colonna1){
					colonna=0;
				}
			}
			if(i==1){
				lpds2=lettera1;
				npds2=numero1;
				lds2=m;
				nds2=n;
			}
			if(i==1 && g==1 && p==1){
				a=0;
				l=0;
				if(lettera1==lpds1 || lettera1+1==lpds1 || lettera1-1==lpds1){
					a=1;
				}
				if(numero1==npds1 || numero1+1==npds1 || numero1-1==npds1){
					l=1;
				}
			if(a==1 && l==1){
				s=0;
				e=0;
				if(m==lds1 || m+1==lds1 || m-1==lds1){
					s=1;
				}
				if(n==nds1 || n+1==nds1 || n-1==nds1){
					e=1;
				}
				if(s==1 && e==1){
					riga1=0;
					colonna1=0;
					if(m+1==lettera1){
										riga1=2;
									}
									if(m-1==lettera1){
										riga1=1;
									}
									if(m==lettera1){
										riga1=0;
									}
									if(n+1==numero1){
										colonna1=1;
									}
									if(n-1==numero1){
										colonna1=2;
									}
									if(n==numero1){
										colonna1=0;
									}
									mio=0;
									mia=0;
							if(riga==riga1){
								mio=1;
							}
							if(colonna==colonna1){
								mia=1;
							}
							if(mio==1 && mia==1){
								matrice[lettera1][numero1]='+';
								matrice [m][n]='1';
								fl6=1;

							}else{
								printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
								fl6=0;
								getch();
								system("CLS");
								visualizzamatrice();
							}
				}else{
					printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
													fl6=0;
													getch();
													system("CLS");
													visualizzamatrice();
				}
			}else{
				printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
											fl6=0;
											getch();
											system("CLS");
											visualizzamatrice();
			}
			}

			if(i==1){
				fl7=1;
			}
			if(i==2){
				fl6=1;
			}
				}
				if(hhh==1){
					fl6=1;
				}
				if(ritorna==1){
									fl6=1;
								}
			}//fl6
				if(ritorna==1){
										break;
												}
				if(hhh!=1){

				if(i==2 && g==1 && p==1){
								a=0;
								l=0;
								if((lettera1==lpds1 && lettera1==lpds2) || (lettera1+2==lpds1 && lettera1+1==lpds2) || (lettera1-2==lpds1 && lettera1-1==lpds2)){
									a=1;
								}
								if((numero1==npds1 && numero1==npds2) || (numero1+2==npds1 && numero1+1==npds2) ||( numero1-2==npds1 && numero1-1==npds2)){
									l=1;
									}
							if(a==1 && l==1){
								s=0;
								e=0;
								if((m==lds1 && m==lds2) || (m+2==lds1 && m+1==lds2) || (m-2==lds1 && m-1==lds2)){
									s=1;
								}
								if((n==nds1 && n==nds2) || (n+2==nds1 && n+1==nds2) || (n-2==nds1 && n-1==nds2)){
									e=1;
								}
								//printf("e e %d s e %d",e,s);
							//	getch();
								if(s==1 && e==1){
									riga1=0;
									colonna1=0;
									if(m+1==lettera1){
														riga1=2;
													}
													if(m-1==lettera1){
														riga1=1;
													}
													if(m==lettera1){
														riga1=0;
													}
													if(n+1==numero1){
														colonna1=1;
													}
													if(n-1==numero1){
														colonna1=2;
													}
													if(n==colonna1){
														colonna1=0;
													}
													mio=0;
													mia=0;
											if(riga==riga1){
												mio=1;
											}
											if(colonna==colonna1){
												mia=1;
											}

											if(mio==1 && mia==1){
												matrice[lettera1][numero1]='+';
												matrice [m][n]='1';
												fl7=1;
											}else{
												printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
												fl7=0;
												getch();
												system("CLS");
												visualizzamatrice();
											}
								}else{
									printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																				fl7=0;
																				getch();
																				system("CLS");
																				visualizzamatrice();
								}

							}else{
								printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																			fl7=0;
																			getch();
																			system("CLS");
																			visualizzamatrice();

							}
				}
				}
				if(hhh==1){
					fl7=1;
				}
				if(ritorna==1){
									fl7=1;
								}
							}//fl7
				system("CLS");
				visualizzamatrice();
				GotoXY(0,11);
				/*p=0;
				g=0;
				if(i!=2){
				while(p<1){
				printf("vuoi spostare un altra pedina? s/n");
				scanf(" %c", &continua);
				if(continua=='s'){
					p++;
				}
				if(continua=='n'){
					g=1;
					p++;
				}
				}
				}
				if(g==1){
				break ;
				}*/
				if(ritorna==1){
									i=4;
								}
system("CLS");
k=0;
while(k<20){
	j=0;
	while(j<20){
		if(matrice[k][j]=='1'){
			matrice[k][j]='o';
		}
		j++;
	}
	k++;
}
visualizzamatrice();
i++;			}//i<3


i=0;
perdi=0;
while(i<20){
	j=0;
	while(j<20){
		if(matrice[i][j]=='@'){
			perdi=perdi+1;
		}
		j++;
	}
	i++;
}
if(perdi==8){
	return 5;
}

i=0;
perdi=0;
while(i<20){
	j=0;
	while(j<20){
		if(matrice[i][j]=='o'){
			perdi=perdi+1;
		}
		j++;
	}
	i++;
}
if(perdi==8){
	return 6;
}
return 0;
}//funzione sposta

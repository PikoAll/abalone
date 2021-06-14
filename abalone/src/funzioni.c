/*
 * funzioni.c
 *
 *  Created on: 14 ott 2019
 *      Author: peppi
 */


/*
 * funzioni.c
 *
 *  Created on: 20 giu 2017
 *      Author: peppi
 */


#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "accesso_dati.h"
#include "funzioni.h"
#include "globali.h"

/** \fn int ai (char matrice[20][20])
 *  Funzione intelligenza artificiale
 *  \param matrice piena di caratteri
 * \return 0 se il pc ha spostato le pedine.
 */
int ai(char matrice[20][20]){
int difesa_pedina(int riga22, int colonna22);
int cpu(char matrice [20][20]);
/// variabile i utilizzata come contatore
	int i=0;
	/// variabile fl utilizzato come booleano
	int fl=3;
	/// variabile fl1 utilizzato come booleano
	int fl1=0;
	/// variabile fl3 utilizzato come booleano
	int fl3=0;
	int ret=0;
	/// variabile bo utilizzato come booleano
	int bo=0;
	/// variabile bo1 utilizzato come booleano
	int bo1;
	/// variabile j utilizzata come contatore
	int j=0;
	int riga22=0;
	int colonna22=0;
	int perdi=0;

	GotoXY(0,11);
//******************DIFESA PEDINA
	i=0;
	while(i<20){
		j=0;
		while(j<20){
			bo=0;
			bo1=0;
			if(matrice[i][j]=='o'){
			if(matrice[i+1][j]=='@' || matrice[i-1][j]=='@' || matrice[i][j+1]=='@' || matrice[i][j-1]=='@' || matrice[i+1][j+1]=='@' || matrice[i-1][j-1]=='@' || matrice[i+1][j-1]=='@' || matrice[i-1][j+1]=='@'){
				bo=1;
			}
			}

if(bo==1){
	if(i==0 && (j==0 && (matrice[0][1]=='@' || matrice[1][1]=='@') || j==1 && matrice[0][2]=='@'|| j==3 && matrice[0][2]=='@'|| j==4 && (matrice[0][3]=='@' || matrice[1][4]=='@'))){
		bo1=1;
	}
if(i==1 && (j==0 && (matrice[1][1]=='@' || matrice[2][1]=='@') || j==1 && matrice[1][2]=='@'|| j==4 && matrice[1][3]=='@' || j==5 && (matrice[1][4]=='@' || matrice[2][5]=='@'))){
	bo1=1;
}
if(i==2 && (j==0 && (matrice[2][1]=='@' || matrice[3][1]=='@')|| j==1 && matrice[2][2]=='@' || j==5 && matrice[2][4]=='@' || j==6 && (matrice[2][5]=='@'|| matrice[3][6]=='@'))){
	bo1=1;
}
if(i==3 && (j==0 && (matrice[3][1]=='@' || matrice[4][1]=='@') || j==1 && matrice[3][2]=='@' || j==6 && matrice[3][5]=='@' || j==7 && (matrice[3][6]=='@' || matrice[4][7]=='@'))){
	bo1=1;
}
if(i==4 && (j==0 && (matrice[4][1]=='@' || matrice[5][1]=='@') || j==1 && matrice[4][2]=='@' || j==7 && matrice[4][6]=='@' || j==8 && (matrice[4][7]=='@'|| matrice[5][8]=='@'))){
	bo1=1;
}
if(i==5 && (j==0 && (matrice[5][1]=='@' || matrice[4][1]=='@' ) || j==1 && matrice[5][2]=='@' || j==6 && matrice[5][5]=='@' || j==7 && (matrice[5][6]=='@'|| matrice[4][7]=='@'))){
	bo1=1;
}
if(i==6 && (j==0 && (matrice[6][1]=='@' || matrice[5][1]=='@') || j==1 && matrice[6][2]=='@' || j==5 && matrice[6][4]=='@' || j==6 && (matrice[6][5]=='@'  || matrice[5][6]=='@'))){
	bo1=1;
}
if(i==7 && (j==0 &&( matrice[7][1]=='@' || matrice[6][1]=='@' ) || j==1 && matrice[7][2]=='@' || j==4 && matrice[7][3]=='@' || j==5 && ( matrice[7][4]=='@' || matrice[6][5]=='@'))){
	bo1=1;
}
if(i==8 && (j==0 && (matrice[8][1]=='@' || matrice[7][1]=='@' ) || j==1 && matrice[8][2]=='@' || j==3 && matrice[8][2]=='@' || j==4 && (matrice[8][3]=='@' || matrice[7][4]=='@'))){
	bo1=1;
}



if(bo1==1){
	 riga22=i;
		 colonna22=j;
		// printf("%d %d",i,j);
		// getch();
		ret=difesa_pedina(riga22,colonna22);
		//printf("\nret e %d", ret);
		//getch();
		fl=1;
		if(ret==0){
			j=20;
			i=20;
			fl=1;
			fl3=1;
		}


}
}
j++;
	}
	i++;
	}
//printf("fl3 e %d",fl3);
//if(ret==1){
	//fl=0;
	//}

if(fl==0){
	//printf("allora si entra in cpu");
	//getch();
	//****************************************************
	cpu(matrice);
	fl3=1;

}//else{
	//difesa_pedina(riga22,colonna22);
//}
if(fl3==0){
//printf("ciao bello");
//getch();
//printf("attacco");
//getch();
//*********************ATTACCO PEDINA
i=0;
while(i<20){
	j=0;
	while(j<20){
		if(matrice[i][j]=='@' && (matrice[i+1][j]==0 || matrice[i-1][j]==0 || matrice[i][j+1]==0 || matrice[i][j-1]==0 )){
			if((matrice[i+1][j]=='o' || matrice[i-1][j]=='o') || (matrice[i][j+1]=='o' || matrice[i][j-1]=='o') && (matrice[i+2][j]=='o' || matrice[i-2][j]=='o' || matrice[i][j+2]=='o' || matrice[i][j-2]=='o' || matrice[i-1][j+1]=='o' || matrice[i-1][j-1]=='o') ){
				fl1=1;}
				while(fl1==1){
	//			printf("unululu");
		//		printf( "i e %d j e %d", i ,j);
			//	getch();

        if(fl1==1){
				if(matrice[i+2][j]=='o' && matrice[i+1][j]=='o'){
					matrice[i+2][j]='+';
					fl1=2;
				//	printf("1");
					//getch();
				}
        }
        if(fl1==1){
				if(matrice[i-2][j]=='o' && matrice[i-1][j]=='o' && i>=4 ){
				   matrice[i-2][j]='+';
					fl1=2;
					//printf("2");
					//getch();
								}
        }
        if(fl1==1){
				if(matrice[i-2][j-1]=='o' && matrice[i-1][j]=='o'){
								   matrice[i-2][j-1]='+';
									fl1=2;
						//			printf("5");
							//		getch();
												}
        }
        if(fl1==1){
				if(matrice[i+2][j+2]=='o' && matrice[i+1][j+1]=='o'){
											   matrice[i+2][j+2]='+';
												fl1=2;
								//				printf("6");
									//			getch();
															}
        }
        if(fl1==1){
				if(matrice[i-2][j-2]=='o' && matrice[i-1][j-1]=='o' && i>=5){
															   matrice[i-2][j-2]='+';
																fl1=2;
										//						printf("8");
											//					getch();
																			}
        }
        if(fl1==1){
				if(matrice[i-2][j+2]=='o' && matrice[i-1][j-1]=='o' ){
															   matrice[i-2][j+2]='+';
																fl1=2;
												//				printf("7");
													//			getch();
																			}
				if(matrice[i+2][j+1]=='o' && matrice[i+1][j+1]=='o' ){
																		   matrice[i+2][j+1]='+';
																			fl1=2;
														//					printf("9");
															//				getch();
																						}
        }
        if(fl1==1){
				if(matrice[i][j+2]=='o' && matrice[i][j+1]=='o'){
					matrice[i][j+2]='+';
					fl1=2;
				//	printf("3");
					//getch();
								}
        }
        if(fl1==1){
				if(matrice[i][j-2]=='o' && matrice[i][j-1]=='o'){
					matrice[i][j-2]='+';
							fl1=2;
			//			printf("4");
				//		getch();
					}
        }
if(fl1==2){
	matrice[i][j]='o';
}
if(fl1==1){
	break;
}
}
		break;}
if(fl1==2){
	j=20;
	i=20;
}
		j++;}
//printf("i e %d",i);
//getch();
//system("cls");
//visualizzamatrice();
i++;}
system("CLS");
	visualizzamatrice();
	//printf("attendi999999");
	//getch();

if(fl1!=2){
	//printf("allora si entra in cpu");
		//getch();
		//****************************************************
	system("CLS");
	visualizzamatrice();
	//printf("attendi5555");
	//getch();
	cpu(matrice);

}
}
//printf("\nciao garusso");
//getch();
//system("cls");
//visualizzamatrice();
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
}//funzione
//***************************************************************************

/** \fn difesa_pedina (int riga22, int colonna22)
 *  Funzione difesa dell'intelligenza artificiale
 *  \param riga22 numero della riga della pedina
 *  \param colonna22 numero della colonna della pedina
 * \return 0 se la pedina non puo essere spostata.
 * \ return 1 se la pedina viene spostata
 */


int difesa_pedina(int riga22, int colonna22){
	int npds2;
			int lpds2;
			int lds2;
				int nds2;
		int c;
		int m;
		int continua=0;
		int continua2=0;
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
		int fine;
		/// variabile fl17 utilizzato come booleano
		int fl17=0;
	int massimo;
	int j;
		int a, l, s,e;
		GotoXY(0,11);
		printf("attendi");
				i=0;
				while(i<3){
					srand(time(NULL));
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
					GotoXY(0,11);
					if(i>=0 || i<3){
					 continua=0+rand()%9;
					continua2=0+rand()%9;
					}
					if(continua==1 && continua2==1){
						//getch();
						fine=1;
						i=3;
					}


	if(i!=0){
		massimo=riga22+1;
	}


	if(massimo==1){
			c=1+rand()%2;
	}
						if(massimo==2){
							c=1+rand()%2;
						}
						if(massimo==3){
												c=1+rand()%3;
											}
						if(massimo==4){
												c=1+rand()%4;
											}
						if(massimo==5){
												c=1+rand()%5;
											}
						if(massimo==6){
												c=1+rand()%6;
											}
						if(massimo==7){
												c=1+rand()%7;
											}
						if(massimo==8){
												c=1+rand()%8;
											}
						if(massimo==9){
												c=1+rand()%9;
											}
						if(i==0){
							c=riga22+1;
						}
						//printf("c e %d",c);
					//	getch();
									if(c==1||c==2||c==3||c==4||c==5||c==6||c==7||c==8||c==9){
									if(c==1){m=0;}
									if(c==2){m=1;}
									if(c==3){m=2;}
									if(c==4){m=3;}
									if(c==5){m=4;}
									if(c==6){m=5;}
									if(c==7){m=6;}
									if(c==8){m=7;}
									if(c==9){m=8;}
									fl=1;
									}else{
//										printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
										//getch();
		//								system("CLS");
	//									visualizzamatrice();
										fl=0;
									}
	if(fine==1){
		fl=1;
	}

			}//fl
				n=1+rand()%9;
				n=n-1;


if(i==0){
	n=colonna22;
}
if(colonna22==0){
n=0;
}


			//	printf("c e %d n e %d", m, n);
				//getch();
				if(matrice[m][n]!='o'){
					fl1=0;
				//	printf("errore coordinata premi un pulsante per riinserire coordinata");
					//getch();
					//system("CLS");
				//	visualizzamatrice();
				}else{
					fl1=1;
				}
				if(fine==1){
						fl1=1;
					}

			}//fl1
				lettera1=m;
				numero1=n;
				if(massimo==2){
										c=1+rand()%3;
									}
									if(massimo==3){
															c=1+rand()%4;
														}
									if(massimo==4){
															c=1+rand()%5;
														}
									if(massimo==5){
															c=1+rand()%6;
														}
									if(massimo==6){
															c=1+rand()%7;
														}
									if(massimo==7){
															c=1+rand()%8;
														}
									if(massimo==8){
															c=1+rand()%9;
														}
									if(massimo==9){
															c=1+rand()%9;
														}
												if(c==1||c==2||c==3||c==4||c==5||c==6||c==7||c==8||c==9){
												if(c==1){m=0;}
												if(c==2){m=1;}
												if(c==3){m=2;}
												if(c==4){m=3;}
												if(c==5){m=4;}
												if(c==6){m=5;}
												if(c==7){m=6;}
												if(c==8){m=7;}
												if(c==9){m=8;}
												fl3=1;
												}else{
					//								printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
													//getch();
						//							system("CLS");
							//						visualizzamatrice();
													fl3=0;
												}
												if(fine==1){
														fl3=1;
													}

					}//fl3
				//	printf("colanna 22 %d",colonna22);
					//getch();
					n=1+rand()%9;
								n=n-1;


								if(matrice[m][n]!='+'){

									fl4=0;
								//	printf("non puoi spostare li la pedina premi un tasto per riselezionarla");
									//getch();
									//system("CLS");
							//		visualizzamatrice();
								}else{
									fl4=1;
								}
								if(fine==1){
										fl4=1;
									}

					}//fl4

				g=0;
				p=0;
				if(m==lettera1 || m-1==lettera1 || m+1==lettera1){
					g=1;
				}
				if(n==numero1 || n-1==numero1 || n+1==numero1){
					p=1;
				}//printf("g e %d p e %d", g,p);
				//getch();
				if(lettera1+1==m && numero1-1==n){
					g=0;
					p=0;
				}
				if(g==1 && p==1){
					fl5=1;
				}else{
					//printf("coordinate non adiacenti premi un tasto per riselezionare coordinate");
					//getch();
				//	system("CLS");
					//visualizzamatrice();
					fl5=0;
				}
				if(fine==1){
						fl5=1;
					}

					}//fl5

				if(i==0 && g==1 && p==1){
				//	printf("ciao giusep");
			//		getch();
					matrice[lettera1][numero1]='+';
					matrice[m][n]='2';
					fl6=1;
					fl7=1;
					fl17=1;
					if(matrice[riga22][colonna22]=='o'){
						matrice[lettera1][numero1]='2';
						matrice[m][n]='+';
						fl17=0;
				//		printf("ciao giusep2");
					//	getch();
					}
				}
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
									matrice [m][n]='2';
									fl6=1;

								}else{
						//			printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
									fl6=0;
									//getch();
							//		system("CLS");
								//	visualizzamatrice();
								}
					}else{
					//	printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
														fl6=0;
														//getch();
						//								system("CLS");
							//							visualizzamatrice();
					}
				}else{
				//	printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
												fl6=0;
												//getch();
					//							system("CLS");
						//						visualizzamatrice();
				}
				}

				if(i==1){
					fl7=1;
				}
				if(i==2){
					fl6=1;
				}
				if(fine==1){
						fl6=1;
					}

				}//fl6


					if(i==2 && g==1 && p==1){
									a=0;
									l=0;
									if((lettera1==lpds1 && lettera1==lpds2 )|| (lettera1+2==lpds1 && lettera1+1==lpds2) || ( lettera1-2==lpds1 && lettera1-1==lpds2)){
										a=1;
									}
									if((numero1==npds1 && numero1==npds2 )|| (numero1+2==npds1 && numero1+1==npds2) || (numero1-2==npds1 && numero1-1==npds2)){
										l=1;
										}
								if(a==1 && l==1){
									s=0;
									e=0;
									if((m==lds1 && m==lds2) ||( m+2==lds1 && m+1==lds2) ||( m-2==lds1 && m-1==lds2)){
										s=1;
									}
									if((n==nds1 && n==nds2) || (n+2==nds1 && n+1==nds2) || (n-2==nds1 && n-1==nds2)){
										e=1;
									}
							//		printf("e e %d s e %d",e,s);
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
													matrice [m][n]='2';
													fl7=1;
												}else{
								//					printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
													fl7=0;
													//getch();
									//				system("CLS");
										//			visualizzamatrice();
												}
									}else{
						//				printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																					fl7=0;
																					//getch();
							//														system("CLS");
								//													visualizzamatrice();
									}

								}else{
									//printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																				fl7=0;
																				//getch();
										//										system("CLS");
											//									visualizzamatrice();

								}
					}

					if(fine==1){
							fl7=1;
						}
								}//fl7
			//	system("CLS");
				//	visualizzamatrice();
					//GotoXY(0,11);
					//printf("attendi");
	//system("CLS");
	//visualizzamatrice();
	//printf("i++");
	//getch();
	i++;			}//i<3

//*******************************************
if(fl17==0){
	c=riga22;
	n=colonna22;
	if(matrice[c+1][n]=='+'){
		matrice[c][n]='+';
		matrice[c+1][n]='o';
		fl17=1;
		fine=1;
	}
if(fine!=1){
	if(matrice[c-1][n]=='+'){
		matrice[c][n]='+';
		matrice[c-1][n]='o';
		fl17=1;
		fine=1;
	}
}
if(fine!=1){
	if(matrice[c][n+1]=='+'){
		matrice[c][n]='+';
		matrice[c][n+1]='o';
		fl17=1;
		fine=1;
	}
}

if(fine!=1){
	if(matrice[c][n-1]=='+'){
		matrice[c][n]='+';
		matrice[c][n-1]='o';
		fl17=1;
		fine=1;
	}
}
}

//************************************************

i=0;
while(i<20){
	j=0;
	while(j<20){
	if(matrice[i][j]=='2'){
	matrice[i][j]='o';
	}
	j++;
	}
	i++;
	}
system("CLS");
visualizzamatrice();
if(fine==1 && fl17==1){

	return 0;
}else{
	return 1;
}
}



//****************************************************************************

/** \fn int cpu (char matrice[20][20])
 *  Funzione che sposta a random le pedine del pc
 *  \param matrice piena di caratteri
 * \return 0 se le pedine vengono spostate.
 */

int cpu (char matrice [20][20])
{
	int confronto_cpu(char matrice[20][20], int m, int n, int lettera1, int numero1);
	int npds2;
			int lpds2;
			int lds2;
				int nds2;
		int c;
		int m;
		int continua=0;
		int n;
		///variabile i utilizzata come contatore
		int i;
		int ritorno=0;
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
		int fine=0;
		int k=0;
	int massimo;
	int j;
		int a, l, s,e;
		GotoXY(0,11);
		i=0;

				massimo=0;
				while(i<20){
					j=0;
					while(j<20){
						if(matrice[i][j]=='o'){
							if(i>massimo){
								massimo=i;
							}
						}
					j++;}
				i++;}
				massimo=massimo+1;
		//printf("massimo e %d",massimo);
		//getch();
				i=0;
				while(i<3){
					srand(time(NULL));
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
			printf("attendi");
				while(fl==0){
					GotoXY(0,11);
					if(i!=0){
					 continua=0+rand()%9;
					// continua2=0+rand()%9;
					}
					if(continua==1 /*&& continua2==3*/){
						fine=1;
						i=3;
					}
					if(continua==1){
						//printf("continua e %d", continua);
						//getch();
					}
						if(massimo==2){
							c=1+rand()%2;
						}
						if(massimo==3){
												c=1+rand()%3;
											}
						if(massimo==4){
												c=1+rand()%4;
											}
						if(massimo==5){
												c=1+rand()%5;
											}
						if(massimo==6){
												c=1+rand()%6;
											}
						if(massimo==7){
												c=1+rand()%7;
											}
						if(massimo==8){
												c=1+rand()%8;
											}
						if(massimo==9){
												c=1+rand()%9;
											}
									if(c==1||c==2||c==3||c==4||c==5||c==6||c==7||c==8||c==9){
									if(c==1){m=0;}
									if(c==2){m=1;}
									if(c==3){m=2;}
									if(c==4){m=3;}
									if(c==5){m=4;}
									if(c==6){m=5;}
									if(c==7){m=6;}
									if(c==8){m=7;}
									if(c==9){m=8;}
									fl=1;
									}else{
		//								printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
										//getch();
			//							system("CLS");
				//						visualizzamatrice();
										fl=0;
									}
									if(fine==1){
											fl=1;
										}

			}//fl
				if(fine==1){
															break;
														}
				n=1+rand()%9;

				n=n-1;
				if(matrice[m][n]!='o'){
					fl1=0;
					//printf("errore coordinata premi un pulsante per riinserire coordinata");
					//getch();
					//system("CLS");
					//visualizzamatrice();
				}else{
					fl1=1;
				}
				if(fine==1){
						fl1=1;
					}

			}//fl1
					if(fine==1){
					break;
				}
				lettera1=m;
				numero1=n;
				if(massimo==2){
										c=1+rand()%3;
									}
									if(massimo==3){
															c=1+rand()%4;
														}
									if(massimo==4){
															c=1+rand()%5;
														}
									if(massimo==5){
															c=1+rand()%6;
														}
									if(massimo==6){
															c=1+rand()%7;
														}
									if(massimo==7){
															c=1+rand()%8;
														}
									if(massimo==8){
															c=1+rand()%9;
														}
									if(massimo==9){
															c=1+rand()%9;
														}
												if(c==1||c==2||c==3||c==4||c==5||c==6||c==7||c==8||c==9){
												if(c==1){m=0;}
												if(c==2){m=1;}
												if(c==3){m=2;}
												if(c==4){m=3;}
												if(c==5){m=4;}
												if(c==6){m=5;}
												if(c==7){m=6;}
												if(c==8){m=7;}
												if(c==9){m=8;}
												fl3=1;
												}else{
						//							printf("lettera sbagliata inserisci nuovamente lettera minuscola premi un pulsante per rinserire coordinata\n");
													//getch();
							//						system("CLS");
								//					visualizzamatrice();
													fl3=0;
												}
												if(fine==1){
														fl3=1;
													}

					}//fl3
					if(fine==1){
					break;
				}
					n=1+rand()%9;
					if(n!=1){
								n=n-1;}
//printf(" n e %d", n);
//printf("\nlettera e %d numero e %d",lettera1,numero1);

//getch();

					if(matrice[m][n]=='@'){
													printf("\n m e %d n e %d\n", m,n);
													//	getch();
						if(i==0){
														ritorno=confronto_cpu(matrice,m,n,lettera1,numero1);
						}
		//												printf("ritorno e %d",ritorno);
													//	getch();
			//											system("CLS");
				//										visualizzamatrice();

														}else if(matrice[m][n]!='+' || matrice[m][n]==0){

															fl4=0;
					//										printf("non puoi spostare li la pedina premi un tasto per riselezionarla");
														//	getch();
						//									system("CLS");
							//								visualizzamatrice();
														}else{
															fl4=1;
														}
											if(ritorno==1){
												fl4=1;
											}
											}//fl4
					if(fine==1){
																				break;
																			}
											if(ritorno==1){
																break;
															}

										g=0;
										p=0;
										if(m==lettera1 || m-1==lettera1 || m+1==lettera1){
											g=1;
										}
										if(n==numero1 || n-1==numero1 || n+1==numero1){
											p=1;
										}//printf("g e %d p e %d", g,p);
										//getch();
										if(lettera1-1==m && numero1-1==n){
											g=0;
											p=0;
										}
										if(g==1 && p==1){
											fl5=1;
										}else{
							//				printf("coordinate non adiacenti premi un tasto per riselezionare coordinate");
											//getch();
								//			system("CLS");
									//		visualizzamatrice();
											fl5=0;
										}
										if(ritorno==1){
															fl5=1;
														}
											}//fl5
					if(fine==1){
																				break;
																			}
											if(ritorno==1){
																				break;
																			}

										if(i==0 && g==1 && p==1){
											if(ritorno==0){
											matrice[lettera1][numero1]='+';
											matrice[m][n]='2';
											fl6=1;
											fl7=1;
											}
										}
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
															matrice [m][n]='2';
															fl6=1;

														}else{
										//					printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
															fl6=0;
											//				getch();
												//			system("CLS");
													//		visualizzamatrice();
														}
											}else{
											//	printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																				fl6=0;
												//								getch();
													//							system("CLS");
														//						visualizzamatrice();
											}
										}else{
										//	printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																		fl6=0;
											//							getch();
												//						system("CLS");
													//					visualizzamatrice();
										}
										}

										if(i==1){
											fl7=1;
										}
										if(i==2){
											fl6=1;
										}
										if(ritorno==1){
															fl6=1;
														}
										}//fl6
					if(fine==1){
																				break;
																			}
											if(ritorno==1){
																				break;
																			}


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
															if((n==nds1 && n==nds2) || (n+2==nds1 && n+1==nds2) ||( n-2==nds1 && n-1==nds2)){
																e=1;
															}
														//	printf("e e %d s e %d",e,s);
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
																			matrice [m][n]='2';
																			fl7=1;
																		}else{
																//			printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																			fl7=0;
																	//		getch();
																		//	system("CLS");
																			//visualizzamatrice();
																		}
															}else{
														//		printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																											fl7=0;
															//												getch();
																//											system("CLS");
																	//										visualizzamatrice();
															}

														}else{
															//printf("le coordinate inserite non vanno bene clicca un pulsante per inserire coordinate");
																										fl7=0;
																									//	getch();
																										//system("CLS");
																									//	visualizzamatrice();

														}
											}
											if(ritorno==1){
																fl7=1;
															}
														}//fl7
					if(fine==1){
																				break;
																			}
										//	system("CLS");
											//visualizzamatrice();
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
							//system("CLS");
							k=0;
							while(k<20){
								j=0;
								while(j<20){
									if(matrice[k][j]=='2'){
										matrice[k][j]='o';
									}
									j++;
								}
								k++;
							}
							if(fine==1){
				i=4;
								}
							if(ritorno==1){
										i=4;
											}
							//printf("attendi000");
								//			getch();
							system("CLS");
							visualizzamatrice();
							i++;			}//i<3

							/*k=0;
							while(k<20){
								j=0;
								while(j<20){
									if(matrice[k][j]=='1'){
										matrice[k][j]='o';
									}
									j++;
								}
								k++;

					}*/
				//printf("attendi000");
			//	getch();
				return 0;			}


/** \fn int confronto (char matrice[20][20],int m, int n, int lettera1, int numero1)
 *  Funzione che permette se e possibile di spostare le pedine avversarie
 *  \param matrice piena di caratteri
 * \param m colonna della matrice della pedina selezionata
 * \param n riga della matrice della pedina selezionata
 * \param lettera1 riga della matrice dove si vuole spostare la pedina
 * \param numero1 colonna della matrice dove si vuole spostare la pedina
 * \return 1 se le pedine sono state spostate.
 */

int confronto(char matrice[20][20],int m, int n, int lettera1, int numero1)
{


int pcpu=1;
int put=1;
int p=0;
int g=0;
/// variabile fl utilizzato come booleano
int fl=0;
/// variabile fl1 utilizzato come booleano
int fl1=0;
/// variabile fl2 utilizzato come booleano
int fl2=0;
/// variabile fl3 utilizzato come booleano
int fl3=0;
/// variabile fl5 utilizzato come booleano
int fl5=0;
//printf(" m e %d n e %d", m,n);
//getch();
//printf("lettera e %d numero e %d",lettera1,numero1);
getch();
//printf("\nciaoo %c  %d %d %c", matrice[m-1][n], m-1,n+1, matrice[m+1][n]);
//printf("\nciaoo %c %d %d ", matrice[lettera11][numero11], lettera11, numero11);
//getch();
if(m==lettera1){
	fl5=5;

}
if(lettera1-1==m){
	if(m<4 && n==numero1){

	}
if(m>=4 && numero1+1==n){
	fl5=4;

}
}
if(lettera1-1==m){
	if(m<4 && numero1-1==n){
		fl5=3;

	}
	if(m>=4 && numero1==n){
		fl5=3;

	}
}
if(lettera1+1==m){

if(m<=4 && numero1==n){

	fl5=2;}
	if(m>4 && numero1-1==n){

			fl5=2;
		}

}
if(lettera1+1==m){

if(m<=4 && numero1+1==n){

	fl5=1;

}
if(m>4 &&  numero1==n){

	fl5=1;

}
}
//printf("\nfl e %d", fl5);
//getch();
//SPOSTARE PEDINE OBBLIQUE VERSO DESTRA
//---------------------------------------
if(fl5==4){
//printf("spostamento verso destra");
 //getch();
 if(m!=lettera1){
if(m<=4){

	if(matrice[m-1][n]=='o'){
		pcpu=pcpu+1;
		fl=2;
	//	printf("11");
		//getch();

	}
	if(matrice[m-1][n]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
										return 0;

		}
	if(fl==2){
	if(matrice[m-2][n]=='o'){
		pcpu=pcpu+1;
		//printf("12");
		//		getch();
	}
	if(matrice[m-2][n]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
												getch();
												return 0;
		}
	}
	if(matrice[lettera1+1][numero1-1]=='@' ){
		put=put+1;
		fl1=2;
		//printf("97");
			//			getch();
	}
	if(fl1==2){
	if(matrice[lettera1+2][numero1-2]=='@' ){
		put=put+1;
		//printf("87");
			//			getch();
	}
	}
	if(put==1){
		if( matrice[lettera1+1][numero1]=='@'){
				put=put+1;
				//printf("197");
					//			getch();
			}
		if(put==2){
			if( matrice[lettera1+2][numero1]=='@' ){
				put=put+1;
				//printf("187");
					//			getch();
			}
		}
	}
}
//printf("fl e %d", fl);
//getch();

if(m>4){
	fl=0;
	fl1=0;
	if(matrice[m-1][n+1]=='o'){
		pcpu=pcpu+1;
		fl1=2;
	}
	if(matrice[m-1][n+1]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
														getch();
														return 0;
		}
	if(fl1==2){
	if(matrice[m-2][n+2]=='o'){
		pcpu=pcpu+1;

	}
	if(matrice[m-2][n+2]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																getch();
																return 0;

		}
	}
	if(matrice[lettera1+1][numero1-1]=='@'){
		put=put+1;
		fl1=2;
	//	printf("66");
		//		getch();

	}
	if(fl1==2){
	if(matrice[lettera1+2][numero1-2]=='@'){
		put=put+1;
		//printf("67");
			//			getch();
	}
	}
}
//printf("put e %d pcpu e %d", put,pcpu);
//getch();
if(pcpu==put){
	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
															getch();
															return 0;
}

if(put>pcpu){
	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();

if(m<=4){
	//printf("hola");
		//getch();
	if(pcpu==2){
		//if(fl==2){
			//printf("basta1");
			//getch();
			if(matrice[m-2][n]!=0){
			matrice[m-2][n]='o';}
			matrice[m][n]='@';
			matrice[lettera1+2][numero1-2]='+';
	//	}
	}
	if(pcpu==1){
		g=2;
		if(put==3){
		while(p==0){
				printf("con quante pedine vuoi spostare la vedina avversaria? ");
				scanf("%d",&g);
				if(g==2 || g==3){
					p=1;
				}

				}
		}
		if(matrice[m-1][n]!=0){
		matrice[m-1][n]='o';}
		matrice[m][n]='@';
		if(m-1<4){////////
		if(g==2){
			if(lettera1+1 >4){
				matrice[lettera1+1][numero1-1]='+';
			}else{
			matrice[lettera1+1][numero1]='+';}
		}
		if(g==3){
			if(lettera1+2>4){
							matrice[lettera1+2][numero1-2]='+';
						}else{
			matrice[lettera1+2][numero1]='+';}
		}
		}
		/*if(m-1>=4){////
			if(g==2){
						matrice[lettera1+1][numero1]='8';
					}
					if(g==3){
						matrice[lettera1+2][numero1]='9';
					}
		}*/
	}
}
if(m>4){
	if(pcpu==2){
		//if(fl1==2){
//printf("basta");
//getch();
			if(matrice[m-2][n]!=0){
			matrice[m-2][n]='o';}
			matrice[m][n]='@';
			matrice[lettera1+2][numero1-2]='+';
		//}
	}
	if(pcpu==1){
		g=2;
		if(put==3){
		while(p==0){
				printf("con quante pedine vuoi spostare la vedina avversaria? ");
				scanf("%d",&g);
				if(g==2 || g==3){
					p=1;
				}

				}
		}
		if(matrice[m-1][n+1]!=0){
		matrice[m-1][n+1]='o';}
		matrice[m][n]='@';
		if(g==2){
			matrice[lettera1+1][numero1-1]='+';
		}
		if(g==3){
			matrice[lettera1+2][numero1-2]='+';
		}
	}
}
}
}
}
//SPOSTARE PEDINE IN ORIZZONTALE
//------------------------------
if(fl5==5){
//printf("orizzontale");
//getch();
fl=0;
fl1=0;
if(matrice[m][n-1]=='o' || matrice[m][n+1]=='o'){
	pcpu=pcpu+1;
	fl=2;
}
if(fl==2){
	if(matrice[m][n-2]=='o' || matrice[m][n+2]=='o'){
		pcpu=pcpu+1;
	}
}
if(matrice[lettera1][numero1-1]=='@' ||matrice[lettera1][numero1+1]=='@'){
	put=put+1;
	fl1=2;
}
if(fl1==2){
	if(matrice[lettera1][numero1-2]=='@' ||matrice[lettera1][numero1+2]=='@'){
		put=put+1;
	}
}
//printf("\nput e %d pcpu e %d", put, pcpu);
//getch();
if(put==pcpu){
	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																getch();
																return 0;

}
if(put>pcpu){
	if(matrice[m][n-1]=='+' || matrice[m][n-1]=='o' || matrice[m][n-1]==0){
		if(pcpu==2){
		//	printf("\ncicho1");
			//getch();
			if(matrice[m][n-2]!=0){
			matrice[m][n-2]='o';}
			matrice[m][n]='@';
			matrice[lettera1][numero1+2]='+';
		}
		if(pcpu==1 && put==3){
			p=0;
			g=0;
			while(p==0){
							printf("con quante pedine vuoi spostare la vedina avversaria? ");
							scanf("%d",&g);
							if(g==2 || g==3){
								p=1;
							}

							}
			if(matrice[m][n-1]!=0){
		matrice[m][n-1]='o';}
		matrice[m][n]='@';
		if(g==2){
			matrice[lettera1][numero1+1]='+';
		}
		if(g==3){
			matrice[lettera1][numero1+2]='+';
		}
		}
	}

//*************************************
	//printf("\n nonn2");
		//						getch();
	if(matrice[m][n+1]=='+' || matrice[m][n+1]=='o' || matrice[m][n+1]==0){
			if(pcpu==2){
				//printf("\ncicho2");
					//		getch();
				if(matrice[m][n+2]!=0){
				matrice[m][n+2]='o';}
				matrice[m][n]='@';
				matrice[lettera1][numero1-2]='+';
			}
			//printf("\n nonn1");
				//			getch();
			if(pcpu==1 && put==3){
				//printf("\n nonn");
				//getch();
				p=0;
				g=0;
				while(p==0){
								printf("con quante pedine vuoi spostare la vedina avversaria? ");
								scanf("%d",&g);
								if(g==2 || g==3){
									p=1;
								}

								}
			if(matrice[m][n+1]!=0){
			matrice[m][n+1]='o';}
			matrice[m][n]='@';
			if(g==2){
				matrice[lettera1][numero1-1]='+';
			}
			if(g==3){
				matrice[lettera1][numero1-2]='+';
			}
			}
		}

}

}

//*********************************************************************************************
// ATTACCO OBLIQUA A sposta verso sinistra
//***************************************
if(fl5==3){
	//printf("sposto verso sinistra");
	//getch();
if(m>4){

	if(matrice[m-1][n]=='o'){
		pcpu=pcpu+1;
		fl=2;
		//printf("11");
		//getch();

	}
	if(matrice[m-1][n]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																getch();
																return 0;

		}
	if(m-2<4){
		fl=0;
	}
	if(fl==2){
	if(matrice[m-2][n]=='o'){
		pcpu=pcpu+1;
		//printf("12");
			//	getch();
	}
	if(matrice[m-2][n]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																		getch();
																		return 0;
		}
	}
	if(matrice[lettera1+1][numero1]=='@' ){
		put=put+1;
		fl1=2;
		//printf("97");
			//			getch();
	}
	if(fl1==2){
	if(matrice[lettera1+2][numero1]=='@' ){
		put=put+1;
		//printf("87");
			//			getch();
	}
	}
/*	if(put==1){
		if( matrice[lettera1+1][numero1]=='@'){
				put=put+1;
				printf("197");
								getch();
			}
		if(put==2){
			if( matrice[lettera1+2][numero1]=='@' ){
				put=put+1;
				printf("187");
								getch();
			}
		}
	}*/
}
//printf("fl e %d", fl);
//getch();

if(m<4){
	//printf("487");
		//	getch();
	fl=0;
	fl1=0;
	if(matrice[m-1][n-1]=='o'){
		pcpu=pcpu+1;
		fl1=2;
	}
	if(matrice[m-1][n-1]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																				getch();
																				return 0;
		}
	if(fl1==2){
	if(matrice[m-2][n-2]=='o'){
		pcpu=pcpu+1;

	}
	if(matrice[m-2][n-2]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																						getch();
																						return 0;

		}
	}
	if(lettera1<4){
	if(matrice[lettera1+1][numero1+1]=='@'){
		put=put+1;
		fl1=2;
		//printf("66");
			//	getch();

	}
	/*if(lettera1+2==4){
		fl1=0;
	}*/
	if(fl1==2){
	if((matrice[lettera1+2][numero1+2]=='@' && lettera1+2==4) || (matrice[lettera1+2][numero1+1]=='@' && lettera1+2==5) ){
		put=put+1;
	//	printf("67");
		//				getch();
	}
	}
	}
if(put==1){
	if(lettera1+1>=4){
		if(matrice[lettera1+1][numero1]=='@'){
			put=put+1;
			fl2=2;
		}

		}
	if(fl2==2){
		if(lettera1+2>=4){
			if(matrice[lettera1+2][numero1]=='@'){
				put=put+1;
			}
		}
	}
}
}

if(m==4){
	//printf("387");
		//						getch();
	if(matrice[m-1][n-1]=='@'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																						getch();
																						return 0;
	}
	if(matrice[m-1][n-1]=='o'){
		pcpu=pcpu+1;
		fl2=2;
		if(fl2==2){
			if(matrice[m-2][n-2]=='o'){
				pcpu=pcpu+1;

			}
		}
	}
	if(matrice[lettera1+1][numero1]=='@' ){
			put=put+1;
			fl1=2;
		//	printf("97");
			//				getch();
		}
		if(fl1==2){
		if(matrice[lettera1+2][numero1]=='@' ){
			put=put+1;
		//	printf("87");
			//				getch();
		}
		}
}
//printf("put e %d pcpu e %d", put,pcpu);
//getch();
if(pcpu==put){
	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																					getch();
																					return 0;
}

if(put>pcpu){
	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();

if(m>4){
	//printf("hola");
		//getch();
	if(pcpu==2){
		//if(fl==2){
			//printf("basta1");
			//getch();
			if(matrice[m-2][n-1]!=0){
			matrice[m-2][n-1]='o';}
			matrice[m][n]='@';
			matrice[lettera1+2][numero1]='+';
	//	}
	}
	if(pcpu==1){
		g=2;
		if(put==3){
		while(p==0){
				printf("con quante pedine vuoi spostare la vedina avversaria? ");
				scanf("%d",&g);
				if(g==2 || g==3){
					p=1;
				}

				}
		}
		if(matrice[m-1][n]!=0){
		matrice[m-1][n]='o';}
		matrice[m][n]='@';
	//	if(m-1<4){////////
		if(g==2){

			matrice[lettera1+1][numero1]='+';}

		if(g==3){
			//printf("\ngg1");
			//getch();

			matrice[lettera1+2][numero1]='+';}
		}
		//}
		/*if(m-1>=4){////
			if(g==2){
						matrice[lettera1+1][numero1]='8';
					}
					if(g==3){
						matrice[lettera1+2][numero1]='9';
					}
		}*/
	}
}
if(m<4){
	if(pcpu==2){
		//if(fl1==2){
//printf("basta");
//getch();
			if(matrice[m-2][n-2]!=0){
			matrice[m-2][n-2]='o';}
			matrice[m][n]='@';
			if(matrice[lettera1+2][numero1+1]=='@' && lettera1+2==5){
							matrice[lettera1+2][numero1+1]='+';
						}else if(matrice[lettera1+2][numero1+1]=='@' && lettera1+2>4){
							matrice[lettera1+2][numero1]='+';
						}else if(matrice[lettera1+2][numero1+2]=='@' && lettera1+2>4){
							matrice[lettera1+2][numero1]='+';
						}else{
			matrice[lettera1+2][numero1+2]='+';}
		//}
	}
	if(pcpu==1){
		g=2;
		if(put==3){
		while(p==0){
				printf("con quante pedine vuoi spostare la vedina avversaria? ");
				scanf("%d",&g);
				if(g==2 || g==3){
					p=1;
				}

				}
		}
	//	printf("gg");
		//getch();
		if(matrice[m-1][n-1]!=0){
		matrice[m-1][n-1]='o';}
		matrice[m][n]='@';
		if(g==2){
			if(lettera1+1==4 || lettera1+1<4){
				matrice[lettera1+1][numero1+1]='+';
			}else{
			matrice[lettera1+1][numero1]='+';
			}
		}
		if(g==3){
			if(matrice[lettera1+2][numero1+1]=='@' && lettera1+2==5){
				matrice[lettera1+2][numero1+1]='+';
			}else if (matrice[lettera1+2][numero1+2]=='@' && lettera1+2==4){
				matrice[lettera1+2][numero1+2]='+';
			}else{
			matrice[lettera1+2][numero1]='+';
			}
		//	printf("lettera1+2 e %d", lettera1+2);
			//getch();
		}
	}
}
if(m==4){
	if(pcpu==2){
		matrice[m-2][n-2]='o';
		matrice[m][n]='@';
		matrice[lettera1+2][numero1]='+';
	}
	if(pcpu==1){
		matrice[m-1][n-1]='o';
		matrice[m][n]='@';
		g=2;
				if(put==3){
				while(p==0){
						printf("con quante pedine vuoi spostare la vedina avversaria? ");
						scanf("%d",&g);
						if(g==2 || g==3){
							p=1;
						}

						}
				}
				if(g==2){
					matrice[lettera1+1][numero1]='+';
				}
				if(g==3){
					matrice[lettera1+2][numero1]='+';
				}

	}
}
}
//************************************************************************************
// ATTACCO DALL'ALTO DA SINISTRA A DESTRA
//*********************************************************************
if(fl5==1){
//printf("da sx a dx");
  // getch();
   if(m<=4){

		if(matrice[m+1][n+1]=='o'){
			pcpu=pcpu+1;
			fl=2;
		//	printf("11");
			//getch();

		}
		if(matrice[m+1][n+1]=='@'){

					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
					getch();
					return 0;

				}
		if(fl==2){
			if(m+2<4){
		if(matrice[m+2][n+2]=='o'){
			pcpu=pcpu+1;
			//printf("12");
				//	getch();
		}
		if(matrice[m+2][n+2]=='@'){

			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
								getch();
								return 0;;
				}
			}else{
				if(matrice[m+2][n]=='o'){
					pcpu=pcpu+1;
				}
				if(matrice[m+2][n]=='@'){
					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
										return 0;
								}
			}
		}
		if(matrice[lettera1-1][numero1-1]=='@' ){
			put=put+1;
			fl1=2;
			//printf("97");
				//			getch();
		}
		if(fl1==2){
		if(matrice[lettera1-2][numero1-2]=='@' ){
			put=put+1;
		//	printf("87");
			//				getch();
		}
		}

	}
	//printf("fl e %d", fl);
	//getch();

	if(m>4){
		//printf("487");
			//	getch();
		fl=0;
		fl1=0;
		if(matrice[m+1][n]=='o'){
			pcpu=pcpu+1;
			fl1=2;
		}
		if(matrice[m+1][n]=='@'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
								getch();
								return 0;
				}
		if(fl1==2){
		if(matrice[m+2][n]=='o'){
			pcpu=pcpu+1;

		}
		if(matrice[m+2][n]=='@'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
								getch();
								return 0;

				}
		}
		if(lettera1-1>=4){
		if(matrice[lettera1-1][numero1]=='@'){
			put=put+1;
			fl1=2;
			//printf("66");
				//	getch();

		}

		if(fl1==2){
			if(lettera1-2<=4){
		if(matrice[lettera1-2][numero1]=='@'){
			put=put+1;
			//printf("67");
				//			getch();
		}
			}
		}
		}
	//if(put==1){
		if(lettera1-1<4){
			if(matrice[lettera1-1][numero1-1]=='@'){
				put=put+1;
				fl2=2;
			}

			}
		if(fl2==2){
			//if(lettera1-2>=4){
				if(matrice[lettera1-2][numero1-1]=='@'){
					put=put+1;
				}
			//}
		}
//	}
	}


	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();
	if(pcpu==put){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
							getch();
							return 0;
	}
	if(pcpu==1){
				g=2;
				if(put==3){
				while(p==0){
						printf("con quante pedine vuoi spostare la vedina avversaria? ");
						scanf("%d",&g);
						if(g==2 || g==3){
							p=1;
						}

						}
				}
				//printf("gg");
				//getch();
			if(g==3){
				//printf("f e %d",g);
				//getch();
				if(put>pcpu){
	//					printf("put e %d pcpu e %d", put,pcpu);
		//				getch();

					//if(m>4){
			//			printf("hola");
				//			getch();
						if(m+1<=4){
							//if(fl==2){
					//			printf("basta1");
						//		getch();
								if(matrice[m+1][n+1]!=0){
								matrice[m+1][n+1]='o';}
								matrice[m][n]='@';
								matrice[lettera1-2][numero1-2]='+';
						//	}
						}

					//	}

					if(m+1>4){
					//	if(pcpu==2){
							//if(fl1==2){
					//printf("basta22");
					//getch();
								if(matrice[m+1][n]!=0){
								matrice[m+1][n]='o';}
								matrice[m][n]='@';
								if(lettera1-2<4){
												matrice[lettera1-2][numero1-2]='+';
											}else{
												matrice[lettera1-2][numero1]='+';
											}
							}
				}

			}
			if(g==2){
			//	printf("f e %d",g);
				//				getch();
						if(put>pcpu){
					//			printf("put e %d pcpu e %d", put,pcpu);
						//		getch();

						//	if(m>4){
							//	printf("hola");
								//	getch();
								if(m+1<=4){
									//if(fl==2){
									//	printf("basta1");
										//getch();
										if(matrice[m+1][n+1]!=0){
										matrice[m+1][n+1]='o';}
										matrice[m][n]='@';
										matrice[lettera1-1][numero1-1]='+';
								//	}
								}

							//	}
							}
							if(m+1>4){
							//	if(pcpu==2){
									//if(fl1==2){
						//	printf("cornuto");
					//		getch();
										if(matrice[m+1][n]!=0){
										matrice[m+1][n]='o';}
										matrice[m][n]='@';
										if(lettera1-1<4){
														matrice[lettera1-1][numero1-1]='+';
													}else{
														matrice[lettera1-1][numero1]='+';
													}
									}


					}
			}
	if(pcpu>1){
		//printf("put e %d pcpu e %d", put,pcpu);
		//getch();

	if(m>4){
		//printf("hola");
			//getch();
		if(m+2<4){
			//if(fl==2){
				//printf("basta1");
				//getch();
				if(matrice[m+2][n+2]!=0){
				matrice[m+2][n+2]='o';}
				matrice[m][n]='@';
				matrice[lettera1-2][numero1-2]='+';
		//	}
		}

		}

	if(m+1>=4){
	//	if(pcpu==2){
			//if(fl1==2){
	//printf("basta57");
	//getch();
	if(m+1>4){
		//printf("perche");
	//	getch();
		if(matrice[m+2][n]!=0){
						matrice[m+2][n]='o';}
	}else if(matrice[m+2][n+1]!=0){
				matrice[m+2][n+1]='o';}
				matrice[m][n]='@';
				if(lettera1-2<4){
								matrice[lettera1-2][numero1-2]='+';
							}else{
								matrice[lettera1-2][numero1]='+';
							}
			}
	}
}
//**********************************************************************
	//************************************************************************************
	// ATTACCO DALL'ALTO DA destra A sinistra
	//*********************************************************************
if(fl5==2){
	//printf("attacco da destra a sinistra");
   //getch();
  if (m<=4){

			if(matrice[m+1][n]=='o'){
				pcpu=pcpu+1;
				fl=2;
	//			printf("11");
		//		getch();

			}
			if(matrice[m+1][n]=='@'){
							pcpu=pcpu+1;
							printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																											getch();
																											return 0;

						}
			if(m==4){
				if(matrice[m+1][n-1]=='o'){
								pcpu=pcpu+1;
								fl=2;
			//					printf("11");
				//				getch();

							}
				if(matrice[m+1][n-1]=='@'){
					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																									getch();
																									return 0;

											}
			}

			if(fl==2){
				if(m+2>=4){
			if(matrice[m+2][n]=='o'){
				pcpu=pcpu+1;
				//printf("12");
					//	getch();

			}if(matrice[m+2][n]=='@'){
				pcpu=pcpu+1;
				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																								getch();
																								return 0;
			}
				}else if(matrice[m+2][n-1]=='o'){
						pcpu=pcpu+1;
					}
				if(matrice[m+2][n-1]=='@'){
					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																									getch();
																									return 0;
									}

			}
			if(matrice[lettera1-1][numero1]=='@' ){
				put=put+1;
				fl1=2;
			//	printf("97");
				//				getch();
			}
			if(fl1==2){
			if(matrice[lettera1-2][numero1]=='@' ){
				put=put+1;
				//printf("87");
					//			getch();
			}
			}

		}
//		printf("fl e %d", fl);
	//	getch();

		if(m>4){
		//	printf("487");
			//		getch();
			fl=0;
			fl1=0;
			if(matrice[m+1][n-1]=='o'){
				pcpu=pcpu+1;
				fl1=2;
			}
			if(matrice[m+1][n-1]=='@'){
				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																								getch();
																								return 0;

						}
			if(fl1==2){
			if(matrice[m+2][n-2]=='o'){
				pcpu=pcpu+1;

			}
			if(matrice[m+2][n-2]=='@'){
				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																								getch();
																								return 0;
						}
			}
			if(lettera1-1<=4){
			if(matrice[lettera1-1][numero1]=='@'){
				put=put+1;
				fl1=2;
				//printf("66");
					//	getch();

			}
			if(lettera1-1==4){
				if(matrice[lettera1-1][numero1+1]=='@'){
								put=put+1;
								fl3=2;
						//		printf("66");
							//			getch();

							}
			}
			if(lettera1-1>4){
				if(matrice[lettera1-1][numero1+1]=='@'){
												put=put+1;
												fl3=2;
								//				printf("66");
									//					getch();

											}
			}
			/*if(lettera1+2==4){
				fl1=0;
			}*/
			if(fl1==2){
				if(lettera1-2<=4){
			if(matrice[lettera1-2][numero1]=='@'){
				put=put+1;
			//	printf("67");
				//				getch();
			}
				}

			}
			if(fl3==2){
				if(lettera1-2<=4){
									if(matrice[lettera1-2][numero1+1]=='@'){
													put=put+1;
					//								printf("67");
						//											getch();
												}
								}
			}
			}
		if(put==1){
			if(lettera1-1>4){
				if(matrice[lettera1-1][numero1+1]=='@'){
					put=put+1;
					fl2=2;
				//	printf("99");
					//																	getch();
				}

				}
			if(fl2==2){
				if(lettera1-2>=4){
					if(matrice[lettera1-2][numero1+2]=='@'){
						put=put+1;
						//printf("47");
							//																getch();
					}
				}
			}
	}
		}


	//	printf("put e %d pcpu e %d", put,pcpu);
		//getch();
		if(pcpu==put){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
																							getch();
																							return 0;
		}
		if(pcpu==1){
					g=2;
					if(put==3){
					while(p==0){
							printf("con quante pedine vuoi spostare la vedina avversaria? ");
							scanf("%d",&g);
							if(g==2 || g==3){
								p=1;
							}

							}
					}
			//		printf("gg");
				//	getch();
				if(g==3){
				//	printf("f e %d",g);
					//getch();
					if(put>pcpu){
						//	printf("put e %d pcpu e %d", put,pcpu);
							//getch();

						//if(m>4){
						//	printf("hola");
							//	getch();
							if(m+1<=4){
								//if(fl==2){
					//				printf("basta1");
						//			getch();
									if(matrice[m+1][n]!=0){
									matrice[m+1][n]='o';}
									matrice[m][n]='@';
									matrice[lettera1-2][numero1]='+';
							//	}
							}

						//	}

						if(m+1>4){
						//	if(pcpu==2){
								//if(fl1==2){
					//	printf("basta22");
				//		getch();
									if(matrice[m+1][n-1]!=0){
									matrice[m+1][n-1]='o';}
									matrice[m][n]='@';
									if(lettera1==5){
											matrice[lettera1-2][numero1+1]='+';
										}else if(lettera1-2<4){
													matrice[lettera1-2][numero1]='+';
												}else{
													matrice[lettera1-2][numero1+2]='+';
												}
								}
					}

				}
				if(g==2){

					//printf("f e %d",g);
						//				getch();
										if(put>pcpu){
							//					printf("put e %d pcpu e %d", put,pcpu);
								//				getch();

											//if(m>4){
									//			printf("hola");
										//			getch();
												if(m+1<=4){
													//if(fl==2){
											//			printf("basta1");
												//		getch();
														if(matrice[m+1][n]!=0){
														matrice[m+1][n]='o';}
														matrice[m][n]='@';
														matrice[lettera1-1][numero1]='+';
												//	}
												}

											//	}

											if(m+1>4){
											//	if(pcpu==2){
													//if(fl1==2){
								//			printf("basta22");
									//		getch();
														if(matrice[m+1][n-1]!=0){
														matrice[m+1][n-1]='o';}
														matrice[m][n]='@';
														if(lettera1-1<4){
																		matrice[lettera1-1][numero1]='+';
																	}else{
																		matrice[lettera1-1][numero1+1]='+';
																	}
													}
										}


						}
				}
		if(pcpu>1){
		//	printf("put e %d pcpu e %d", put,pcpu);
		//	getch();

		if(m>4){
			//printf("hola");
				//getch();
			if(m+2<4){
				//if(fl==2){
					//printf("basta1");
			//		getch();
					if(matrice[m+2][n]!=0){
					matrice[m+2][n]='o';}
					matrice[m][n]='@';
					matrice[lettera1-2][numero1]='+';
			//	}
			}

			}

		if(m+1>=4){
		//	if(pcpu==2){
				//if(fl1==2){
	//	printf("basta57");
//		getch();
		if(m+1>4){
	//		printf("perche");
		//	getch();
			if(matrice[m+2][n-2]!=0){
							matrice[m+2][n-2]='o';}
		}else if(matrice[m+2][n-1]!=0){
				matrice[m+2][n-1]='o';}
					matrice[m][n]='@';
					if(lettera1-1==4){
						matrice[lettera1-2][numero1+1]='+';
					}else if(lettera1-2<4){
									matrice[lettera1-2][numero1]='+';
								}else{
									matrice[lettera1-2][numero1+2]='+';
								}
				}
		}
}
//************************************************************************
system("CLS");
visualizzamatrice();
getch();
return 1;
}

/** \fn int confronto_cpu1 (char matrice[20][20],int m, int n, int lettera1, int numero1)
 *  Funzione che permette se e possibile di spostare le pedine avversarie
 *  \param matrice piena di caratteri
 * \param m colonna della matrice della pedina selezionata
 * \param n riga della matrice della pedina selezionata
 * \param lettera1 riga della matrice dove si vuole spostare la pedina
 * \param numero1 colonna della matrice dove si vuole spostare la pedina
 * \return 1 se le pedine sono state spostate.
 */

int confronto_cpu1(char matrice[20][20],int m, int n, int lettera1, int numero1)
{
	int pcpu=1;
	int put=1;
	int p=0;
	int g=0;
	/// variabile fl utilizzato come booleano
	int fl=0;
	/// variabile fl1 utilizzato come booleano
	int fl1=0;
	/// variabile fl2 utilizzato come booleano
	int fl2=0;
	/// variabile fl3 utilizzato come booleano
	int fl3=0;
	/// variabile fl5 utilizzato come booleano
	int fl5=0;
	printf("attendi\n");
	//getch();
	//printf(" m e %d n e %d", m,n);
	//getch();
	//printf("\nciaoo %c  %d %d %c", matrice[m-1][n], m-1,n+1, matrice[m+1][n]);
	//printf("\nciaoo %c %d %d ", matrice[lettera11][numero11], lettera11, numero11);
	//getch();

if(m==lettera1){
	fl5=5;
}
if(lettera1-1==m){
	if(m<4 && n==numero1){
		fl5=4;
	}
if(m>=4 && numero1+1==n){
	fl5=4;
}
}
if(lettera1-1==m){
	if(m<4 && numero1-1==n){
		fl5=3;
	}
	if(m>=4 && numero1==n){
		fl5=3;
	}
}
if(lettera1+1==m){
if(m<=4 && numero1==n){
	fl5=2;}
	if(m>4 && numero1-1==n){
			fl5=2;
		}

}
if(lettera1+1==m){
if(m<=4 && numero1+1==n){
	fl5=1;

}
if(m>4 &&  numero1==n){
	fl5=1;

}
}
//printf("fl e %d", fl5);
//getch();
//ATTACCO DA SINISTRA E DESTRA
//****************************
if(fl5==1){
//printf("da sx a dx");
 //  getch();
   if(m<=4){

		if(matrice[m+1][n+1]=='@'){
			pcpu=pcpu+1;
			fl=2;
		//	printf("11");
			//getch();

		}
		if(matrice[m+1][n+1]=='o'){

			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
				getch();
					return 0;

				}
		if(fl==2){
			if(m+2<4){
		if(matrice[m+2][n+2]=='@'){
			pcpu=pcpu+1;
			//printf("12");
				//	getch();
		}
		if(matrice[m+2][n+2]=='o'){

			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
							getch();
								return 0;
				}
			}else{
				if(matrice[m+2][n]=='@'){
					pcpu=pcpu+1;
				}
				if(matrice[m+2][n]=='o'){
					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
										return 0;
								}
			}
		}
		if(matrice[lettera1-1][numero1-1]=='o' ){
			put=put+1;
			fl1=2;
			//printf("97");
				//			getch();
		}
		if(fl1==2){
		if(matrice[lettera1-2][numero1-2]=='o' ){
			put=put+1;
		//	printf("87");
			//				getch();
		}
		}

	}
	//printf("fl e %d", fl);
	//getch();

	if(m>4){
		//printf("487");
			//	getch();
		fl=0;
		fl1=0;
		if(matrice[m+1][n]=='@'){
			pcpu=pcpu+1;
			fl1=2;
		}
		if(matrice[m+1][n]=='o'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
								getch();
								return 0;
				}
		if(fl1==2){
		if(matrice[m+2][n]=='@'){
			pcpu=pcpu+1;

		}
		if(matrice[m+2][n]=='o'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
								getch();
								return 0;

				}
		}
		if(lettera1-1>=4){
		if(matrice[lettera1-1][numero1]=='o'){
			put=put+1;
			fl1=2;
			//printf("66");
				//	getch();

		}

		if(fl1==2){
			if(lettera1-2<=4){
		if(matrice[lettera1-2][numero1]=='o'){
			put=put+1;
			//printf("67");
				//			getch();
		}
			}
		}
		}
	//if(put==1){
		if(lettera1-1<4){
			if(matrice[lettera1-1][numero1-1]=='o'){
				put=put+1;
				fl2=2;
			}

			}
		if(fl2==2){
			//if(lettera1-2>=4){
				if(matrice[lettera1-2][numero1-1]=='o'){
					put=put+1;
				}
			//}
		}
//	}
	}


	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();
	if(pcpu==put){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
							getch();
							return 0;
	}
	if(pcpu==1){
				g=2;
				if(put==3){
				while(p==0){
					while(p==0){
							g=0;
							g=2+rand()%3;
						if(g==2 || g==3){
						p=1;
						}
					}
						if(g==2 || g==3){
							p=1;
						}

						}
				}
				//printf("gg");
				//getch();
			if(g==3){
				//printf("f e %d",g);
				//getch();
				if(put>pcpu){
	//					printf("put e %d pcpu e %d", put,pcpu);
		//				getch();

					//if(m>4){
			//			printf("hola");
				//			getch();
						if(m+1<=4){
							//if(fl==2){
					//			printf("basta1");
						//		getch();
								if(matrice[m+1][n+1]!=0){
								matrice[m+1][n+1]='@';}
								matrice[m][n]='o';
								matrice[lettera1-2][numero1-2]='+';
						//	}
						}

					//	}

					if(m+1>4){
					//	if(pcpu==2){
							//if(fl1==2){
			//		printf("basta22");
				//	getch();
								if(matrice[m+1][n]!=0){
								matrice[m+1][n]='@';}
								matrice[m][n]='o';
								if(lettera1-2<4){
												matrice[lettera1-2][numero1-2]='+';
											}else{
												matrice[lettera1-2][numero1]='+';
											}
							}
				}

			}
			if(g==2){
			//	printf("f e %d",g);
				//				getch();
						if(put>pcpu){
					//			printf("put e %d pcpu e %d", put,pcpu);
						//		getch();

						//	if(m>4){
							//	printf("hola");
								//	getch();
								if(m+1<=4){
									//if(fl==2){
									//	printf("basta1");
										//getch();
										if(matrice[m+1][n+1]!=0){
										matrice[m+1][n+1]='@';}
										matrice[m][n]='o';
										matrice[lettera1-1][numero1-1]='+';
								//	}
								}

							//	}
							}
							if(m+1>4){
							//	if(pcpu==2){
									//if(fl1==2){
						//	printf("cornuto");
							//getch();
										if(matrice[m+1][n]!=0){
										matrice[m+1][n]='@';}
										matrice[m][n]='o';
										if(lettera1-1<4){
														matrice[lettera1-1][numero1-1]='+';
													}else{
														matrice[lettera1-1][numero1]='+';
													}
									}


					}
			}
	if(pcpu>1){
	//	printf("put e %d pcpu e %d", put,pcpu);
		//getch();

	if(m>4){
	//	printf("hola");
		//	getch();
		if(m+2<4){
			//if(fl==2){
			//	printf("basta1");
			//	getch();
				if(matrice[m+2][n+2]!=0){
				matrice[m+2][n+2]='@';}
				matrice[m][n]='o';
				matrice[lettera1-2][numero1-2]='+';
		//	}
		}

		}

	if(m+1>=4){
	//	if(pcpu==2){
			//if(fl1==2){
//	printf("basta57");
	//getch();
	if(m+1>4){
		//printf("perche");
		//getch();
		if(matrice[m+2][n]!=0){
						matrice[m+2][n]='@';}
	}else if(matrice[m+2][n+1]!=0){
				matrice[m+2][n+1]='@';}
				matrice[m][n]='o';
				if(lettera1-2<4){
								matrice[lettera1-2][numero1-2]='+';
							}else{
								matrice[lettera1-2][numero1]='+';
							}
			}
	}
}
//ATTACCO DA DESTRA A SINISTRA
//****************************
if(fl5==2){
	//printf("attacco da destra a sinistra");
   //getch();
  if (m<=4){

			if(matrice[m+1][n]=='@'){
				pcpu=pcpu+1;
				fl=2;
	//			printf("11");
		//		getch();

			}
			if(matrice[m+1][n]=='o'){
				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
									getch();
									return 0;

						}
			if(m==4){
				if(matrice[m+1][n-1]=='@'){
								pcpu=pcpu+1;
								fl=2;
		//						printf("11");
			//					getch();

							}
				if(matrice[m+1][n-1]=='o'){
					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
										return 0;

											}
			}

			if(fl==2){
				if(m+2>=4){
			if(matrice[m+2][n]=='@'){
				pcpu=pcpu+1;
				//printf("12");
					//	getch();

			}if(matrice[m+2][n]=='o'){
				pcpu=pcpu+1;
			printf("\n non puoi spostare");
						getch();
			}
				}else if(matrice[m+2][n-1]=='@'){
						pcpu=pcpu+1;
					}
				if(matrice[m+2][n-1]=='o'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
										return 0;
									}

			}
			if(matrice[lettera1-1][numero1]=='o' ){
				put=put+1;
				fl1=2;
				//printf("97");
					//			getch();
			}
			if(fl1==2){
			if(matrice[lettera1-2][numero1]=='o' ){
				put=put+1;
			//	printf("87");
				//				getch();
			}
			}

		}
//		printf("fl e %d", fl);
	//	getch();

		if(m>4){
		//	printf("487");
			//		getch();
			fl=0;
			fl1=0;
			if(matrice[m+1][n-1]=='@'){
				pcpu=pcpu+1;
				fl1=2;
			}
			if(matrice[m+1][n-1]=='o'){
				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
									getch();
									return 0;

						}
			if(fl1==2){
			if(matrice[m+2][n-2]=='@'){
				pcpu=pcpu+1;

			}
			if(matrice[m+2][n-2]=='o'){

				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
									getch();
									return 0;
						}
			}
			if(lettera1-1<=4){
			if(matrice[lettera1-1][numero1]=='o'){
				put=put+1;
				fl1=2;
				//printf("66");
					//	getch();

			}
			if(lettera1-1==4){
				if(matrice[lettera1-1][numero1+1]=='o'){
								put=put+1;
								fl3=2;
						//		printf("66");
							//			getch();

							}
			}
			if(lettera1-1>4){
				if(matrice[lettera1-1][numero1+1]=='o'){
												put=put+1;
												fl3=2;
								//				printf("66");
									//					getch();

											}
			}
			/*if(lettera1+2==4){
				fl1=0;
			}*/
			if(fl1==2){
				if(lettera1-2<=4){
			if(matrice[lettera1-2][numero1]=='o'){
				put=put+1;
	//			printf("67");
		//						getch();
			}
				}

			}
			if(fl3==2){
				if(lettera1-2<=4){
									if(matrice[lettera1-2][numero1+1]=='o'){
													put=put+1;
			//										printf("67");
				//													getch();
												}
								}
			}
			}
		if(put==1){
			if(lettera1-1>4){
				if(matrice[lettera1-1][numero1+1]=='o'){
					put=put+1;
					fl2=2;
					//printf("99");
						//																getch();
				}

				}
			if(fl2==2){
				if(lettera1-2>=4){
					if(matrice[lettera1-2][numero1+2]=='o'){
						put=put+1;
					//	printf("47");
						//																	getch();
					}
				}
			}
	}
		}


//		printf("put e %d pcpu e %d", put,pcpu);
	//	getch();
		if(pcpu==put){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
						getch();
								return 0;
		}
		if(pcpu==1){
					g=2;
					if(put==3){
						while(p==0){
										printf("con quante pedine vuoi spostare la vedina avversaria? ");
										scanf("%d",&g);
										if(g==2 || g==3){
											p=1;
										}

										}
					}
		//			printf("gg");
			//		getch();
				if(g==3){
				//	printf("f e %d",g);
					//getch();
					if(put>pcpu){
						//	printf("put e %d pcpu e %d", put,pcpu);
							//getch();

						//if(m>4){
					//		printf("hola");
						//		getch();
							if(m+1<=4){
								//if(fl==2){
							//		printf("basta1");
								//	getch();
									if(matrice[m+1][n]!=0){
									matrice[m+1][n]='@';}
									matrice[m][n]='o';
									matrice[lettera1-2][numero1]='+';
							//	}
							}

						//	}

						if(m+1>4){
						//	if(pcpu==2){
								//if(fl1==2){
		//				printf("basta22");
			//			getch();
									if(matrice[m+1][n-1]!=0){
									matrice[m+1][n-1]='@';}
									matrice[m][n]='o';
									if(lettera1==5){
											matrice[lettera1-2][numero1+1]='+';
										}else if(lettera1-2<4){
													matrice[lettera1-2][numero1]='+';
												}else{
													matrice[lettera1-2][numero1+2]='+';
												}
								}
					}

				}
				if(g==2){

				//	printf("f e %d",g);
					//					getch();
										if(put>pcpu){
						//						printf("put e %d pcpu e %d", put,pcpu);
							//					getch();

											//if(m>4){
								//				printf("hola");
									//				getch();
												if(m+1<=4){
													//if(fl==2){
										//				printf("basta1");
											//			getch();
														if(matrice[m+1][n]!=0){
														matrice[m+1][n]='@';}
														matrice[m][n]='o';
														matrice[lettera1-1][numero1]='+';
												//	}
												}

											//	}

											if(m+1>4){
											//	if(pcpu==2){
													//if(fl1==2){
										//	printf("basta22");
											//getch();
														if(matrice[m+1][n-1]!=0){
														matrice[m+1][n-1]='@';}
														matrice[m][n]='o';
														if(lettera1-1<4){
																		matrice[lettera1-1][numero1]='+';
																	}else{
																		matrice[lettera1-1][numero1+1]='+';
																	}
													}
										}


						}
				}
		if(pcpu>1){
//			printf("put e %d pcpu e %d", put,pcpu);
	//		getch();

		if(m>4){
		//	printf("hola");
			//	getch();
			if(m+2<4){
				//if(fl==2){
				//	printf("basta1");
					//getch();
					if(matrice[m+2][n]!=0){
					matrice[m+2][n]='@';}
					matrice[m][n]='o';
					matrice[lettera1-2][numero1]='+';
			//	}
			}

			}

		if(m+1>=4){
		//	if(pcpu==2){
				//if(fl1==2){
//		printf("basta57");
	//	getch();
		if(m+1>4){
		//	printf("perche");
			//getch();
			if(matrice[m+2][n-2]!=0){
							matrice[m+2][n-2]='@';}
		}else if(matrice[m+2][n-1]!=0){
				matrice[m+2][n-1]='@';}
					matrice[m][n]='o';
					if(lettera1-1==4){
						matrice[lettera1-2][numero1+1]='+';
					}else if(lettera1-2<4){
									matrice[lettera1-2][numero1]='+';
								}else{
									matrice[lettera1-2][numero1+2]='+';
								}
				}
		}
}
//*******************************************************************************
	// DAL BASSO VERSO ALTO SPOSTA VERSO SINISTRA
//*******************************************************************************
if(fl5==3){
//printf("dal basso verso lalto sposta verso sinistra");
  // getch();
   if(m>4){

		if(matrice[m-1][n]=='@'){
			pcpu=pcpu+1;
			fl=2;
	//		printf("11");
		//	getch();

		}
		if(matrice[m-1][n]=='o'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
											return 0;


				}
		if(m-2<4){
			fl=0;
		}
		if(fl==2){
		if(matrice[m-2][n]=='@'){
			pcpu=pcpu+1;
		//	printf("12");
			//		getch();
		}
		if(matrice[m-2][n]=='o'){

			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
											getch();
											return 0;
				}
		}
		if(matrice[lettera1+1][numero1]=='o' ){
			put=put+1;
			fl1=2;
		//	printf("97");
			//				getch();
		}
		if(fl1==2){
		if(matrice[lettera1+2][numero1]=='o' ){
			put=put+1;
		//	printf("87");
			//				getch();
		}
		}
	/*	if(put==1){
			if( matrice[lettera1+1][numero1]=='@'){
					put=put+1;
					printf("197");
									getch();
				}
			if(put==2){
				if( matrice[lettera1+2][numero1]=='@' ){
					put=put+1;
					printf("187");
									getch();
				}
			}
		}*/
	}
	//printf("fl e %d", fl);
	//getch();

	if(m<4){
		//printf("487");
			//	getch();
		fl=0;
		fl1=0;
		if(matrice[m-1][n-1]=='@'){
			pcpu=pcpu+1;
			fl1=2;
		}
		if(matrice[m-1][n-1]=='o'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
											getch();
											return 0;
				}
		if(fl1==2){
		if(matrice[m-2][n-2]=='@'){
			pcpu=pcpu+1;

		}
		if(matrice[m-2][n-2]=='o'){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
											getch();
											return 0;

				}
		}
		if(lettera1<4){
		if(matrice[lettera1+1][numero1+1]=='o'){
			put=put+1;
			fl1=2;
			//printf("66");
				//	getch();

		}
		/*if(lettera1+2==4){
			fl1=0;
		}*/
		if(fl1==2){
		if((matrice[lettera1+2][numero1+2]=='o' && lettera1+2==4) || (matrice[lettera1+2][numero1+1]=='o' && lettera1+2==5 )){
			put=put+1;
			//printf("67");
				//			getch();
		}
		}
		}
	if(put==1){
		if(lettera1+1>=4){
			if(matrice[lettera1+1][numero1]=='o'){
				put=put+1;
				fl2=2;
			}

			}
		if(fl2==2){
			if(lettera1+2>=4){
				if(matrice[lettera1+2][numero1]=='o'){
					put=put+1;
				}
			}
		}
	}
	}

	if(m==4){
	//	printf("387");
		//							getch();
		if(matrice[m-1][n-1]=='@'){
			pcpu=pcpu+1;
			fl2=2;
			if(matrice[m-1][n-1]=='o'){
				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
												getch();
												return 0;
			}
			if(fl2==2){
				if(matrice[m-2][n-2]=='@'){
					pcpu=pcpu+1;

				}
				if(matrice[m-2][n-2]=='@'){

					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
													getch();
													return 0;
								}
			}
		}
		if(matrice[lettera1+1][numero1]=='o' ){
				put=put+1;
				fl1=2;
				//printf("97");
					//			getch();
			}
			if(fl1==2){
			if(matrice[lettera1+2][numero1]=='o' ){
				put=put+1;
				//printf("87");
					//			getch();
			}
			}
	}
	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();
	if(pcpu==put){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
										return 0;
	}

	if(put>pcpu){
	//	printf("put e %d pcpu e %d", put,pcpu);
		//getch();

	if(m>4){
	//	printf("hola");
		//	getch();
		if(pcpu==2){
			//if(fl==2){
			//	printf("basta1");
				//getch();
				if(matrice[m-2][n-1]!=0){
				matrice[m-2][n-1]='@';}
				matrice[m][n]='o';
				matrice[lettera1+2][numero1]='+';
		//	}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
				while(p==0){
								printf("con quante pedine vuoi spostare la vedina avversaria? ");
								scanf("%d",&g);
								if(g==2 || g==3){
									p=1;
								}

								}
			}
			if(matrice[m-1][n]!=0){
			matrice[m-1][n]='@';}
			matrice[m][n]='o';
		//	if(m-1<4){////////
			if(g==2){

				matrice[lettera1+1][numero1]='+';}

			if(g==3){
				//printf("\ngg1");
				//getch();

				matrice[lettera1+2][numero1]='+';}
			}
			//}
			/*if(m-1>=4){////
				if(g==2){
							matrice[lettera1+1][numero1]='8';
						}
						if(g==3){
							matrice[lettera1+2][numero1]='9';
						}
			}*/
		}
	}
	if(m<4){
		if(pcpu==2){
			//if(fl1==2){
	//printf("basta");
	//getch();
				if(matrice[m-2][n-2]!=0){
				matrice[m-2][n-2]='@';}
				matrice[m][n]='o';
				if(matrice[lettera1+2][numero1+1]=='o' && lettera1+2==5){
								matrice[lettera1+2][numero1+1]='+';
							}else if(matrice[lettera1+2][numero1+1]=='o' && lettera1+2>4){
								matrice[lettera1+2][numero1]='+';
							}else if(matrice[lettera1+2][numero1+2]=='o' && lettera1+2>4){
								matrice[lettera1+2][numero1]='+';
							}else{
				matrice[lettera1+2][numero1+2]='+';}
			//}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
				while(p==0){
								printf("con quante pedine vuoi spostare la vedina avversaria? ");
								scanf("%d",&g);
								if(g==2 || g==3){
									p=1;
								}

								}
			}
			//printf("gg");
			//getch();
			if(matrice[m-1][n-1]!=0){
			matrice[m-1][n-1]='@';}
			matrice[m][n]='o';
			if(g==2){
				if(lettera1+1==4 || lettera1+1<4){
					matrice[lettera1+1][numero1+1]='+';
				}else{
				matrice[lettera1+1][numero1]='+';
				}
			}
			if(g==3){
				if(matrice[lettera1+2][numero1+1]=='o' && lettera1+2==5){
					matrice[lettera1+2][numero1+1]='p';
				}else if (matrice[lettera1+2][numero1+2]=='o' && lettera1+2==4){
					matrice[lettera1+2][numero1+2]='+';
				}else{
				matrice[lettera1+2][numero1]='+';
				}
				//printf("lettera1+2 e %d", lettera1+2);
				//getch();
			}
		}
	}
	if(m==4){
		if(pcpu==2){
			matrice[m-2][n-2]='@';
			matrice[m][n]='o';
			matrice[lettera1+2][numero1]='+';
		}
		if(pcpu==1){
			matrice[m-1][n-1]='@';
			matrice[m][n]='o';
			g=2;
					if(put==3){
						while(p==0){
										printf("con quante pedine vuoi spostare la vedina avversaria? ");
										scanf("%d",&g);
										if(g==2 || g==3){
											p=1;
										}

										}
					}
					if(g==2){
						matrice[lettera1+1][numero1]='+';
					}
					if(g==3){
						matrice[lettera1+2][numero1]='+';
					}

		}
	}
}
//*******************************************************************************
	//DAL BASSO VERSO ALTO SPOSTA VERSO DESTRA
//*******************************************************************************
if(fl5==4){
	//printf("dal basso verso lalto sposta verso destra");
   //getch();
 if(m<=4){

		if(matrice[m-1][n]=='@'){
			pcpu=pcpu+1;
			fl=2;
	//		printf("11");
		//	getch();

		}
		if(matrice[m-1][n]=='o'){

			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
											getch();
											return 0;

				}
		if(fl==2){
		if(matrice[m-2][n]=='@'){
			pcpu=pcpu+1;
//			printf("12");
	//				getch();
		}
		if(matrice[m-2][n]=='o'){

			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
											getch();
											return 0;
				}
		}
		if(matrice[lettera1+1][numero1-1]=='o' ){
			put=put+1;
			fl1=2;
			//printf("97");
						//	getch();
		}
		if(fl1==2){
		if(matrice[lettera1+2][numero1-2]=='o' ){
			put=put+1;
			//printf("87");
				//			getch();
		}
		}
		if(put==1){
			if( matrice[lettera1+1][numero1]=='o'){
					put=put+1;
					//printf("197");
						//			getch();
				}
			if(put==2){
				if( matrice[lettera1+2][numero1]=='o' ){
					put=put+1;
					//printf("187");
						//			getch();
				}
			}
		}
	}
	//printf("fl e %d", fl);
	//getch();

	if(m>4){
		fl=0;
		fl1=0;
		if(matrice[m-1][n+1]=='@'){
			pcpu=pcpu+1;
			fl1=2;
		}
		if(matrice[m-1][n+1]=='o'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
											getch();
											return 0;
				}
		if(fl1==2){
		if(matrice[m-2][n+2]=='@'){
			pcpu=pcpu+1;

		}
		if(matrice[m-2][n+2]=='o'){
			printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
											getch();
											return 0;

				}
		}
		if(matrice[lettera1+1][numero1-1]=='o'){
			put=put+1;
			fl1=2;
			//printf("66");
				//	getch();

		}
		if(fl1==2){
		if(matrice[lettera1+2][numero1-2]=='o'){
			put=put+1;
			//printf("67");
				//			getch();
		}
		}
	}
	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();
	if(pcpu==put){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
										getch();
										return 0;
	}

	if(put>pcpu){
	//	printf("put e %d pcpu e %d", put,pcpu);
		//getch();

	if(m<=4){
		//printf("hola");
			//getch();
		if(pcpu==2){
			//if(fl==2){
				//printf("basta1");
				//getch();
				if(matrice[m-2][n]!=0){
				matrice[m-2][n]='@';}
				matrice[m][n]='o';
				matrice[lettera1+2][numero1-2]='+';
		//	}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
				while(p==0){
								printf("con quante pedine vuoi spostare la vedina avversaria? ");
								scanf("%d",&g);
								if(g==2 || g==3){
									p=1;
								}

								}
			}
			if(matrice[m-1][n]!=0){
			matrice[m-1][n]='@';}
			matrice[m][n]='o';
			if(m-1<4){////////
			if(g==2){
				if(lettera1+1 >4){
					matrice[lettera1+1][numero1-1]='+';
				}else{
				matrice[lettera1+1][numero1]='+';}
			}
			if(g==3){
				if(lettera1+2>4){
								matrice[lettera1+2][numero1-2]='+';
							}else{
				matrice[lettera1+2][numero1]='+';}
			}
			}
			/*if(m-1>=4){////
				if(g==2){
							matrice[lettera1+1][numero1]='8';
						}
						if(g==3){
							matrice[lettera1+2][numero1]='9';
						}
			}*/
       }
	}
	if(m>4){
		if(pcpu==2){
			//if(fl1==2){
	//printf("basta");
	//getch();
				if(matrice[m-2][n]!=0){
				matrice[m-2][n]='@';}
				matrice[m][n]='o';
				matrice[lettera1+2][numero1-2]='+';
			//}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
				while(p==0){
								printf("con quante pedine vuoi spostare la vedina avversaria? ");
								scanf("%d",&g);
								if(g==2 || g==3){
									p=1;
								}

								}
			}
			if(matrice[m-1][n+1]!=0){
			matrice[m-1][n+1]='@';}
			matrice[m][n]='o';
			if(g==2){
				matrice[lettera1+1][numero1-1]='+';
			}
			if(g==3){
				matrice[lettera1+2][numero1-2]='+';
			}
		}
	}
	}
}
//********************************************************************************
	//ORIZZONTALE
//********************************************************************************
if(fl5==5){
//printf("orizzontale");
	//getch();
	fl=0;
	fl1=0;
	if(matrice[m][n-1]=='@' || matrice[m][n+1]=='@'){
		pcpu=pcpu+1;
		fl=2;
	}
	//if(matrice[m][n-1]=='o' || matrice[m][n+1]=='o'){
		//	printf("\n non puoi spostare");
			//getch();
	//	}
	if(fl==2){
		if(matrice[m][n-2]=='@' || matrice[m][n+2]=='@'){
			pcpu=pcpu+1;
		}
		//if(matrice[m][n-2]=='o' || matrice[m][n+2]=='o'){
			//printf("\n non puoi spostare");
				//		getch();
				//}
	}
	if(matrice[lettera1][numero1-1]=='o' ||matrice[lettera1][numero1+1]=='o'){
		put=put+1;
		fl1=2;
	}
	if(fl1==2){
		if(matrice[lettera1][numero1-2]=='o' ||matrice[lettera1][numero1+2]=='o'){
			put=put+1;
		}
	}
	//printf("\nput e %d pcpu e %d", put, pcpu);
	//getch();
	if(put==pcpu){
		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
									getch();
										return 0;
	}
	if(put>pcpu){
		if(matrice[m][n-1]=='+' || matrice[m][n-1]=='@' || matrice[m][n-1]==0){
			if(pcpu==2){
				//printf("\ncicho1");
				//getch();
				if(matrice[m][n-2]!=0){
				matrice[m][n-2]='@';}
				matrice[m][n]='o';
				matrice[lettera1][numero1+2]='+';
			}
			if(pcpu==1 && put==3){
				p=0;
				g=0;
				while(p==0){
								printf("con quante pedine vuoi spostare la vedina avversaria? ");
								scanf("%d",&g);
								if(g==2 || g==3){
									p=1;
								}

								}
				if(matrice[m][n-1]!=0){
			matrice[m][n-1]='@';}
			matrice[m][n]='o';
			if(g==2){
				matrice[lettera1][numero1+1]='+';
			}
			if(g==3){
				matrice[lettera1][numero1+2]='+';
			}
			}
		}

	//*************************************
		//printf("\n nonn2");
			//						getch();
		if(matrice[m][n+1]=='+' || matrice[m][n+1]=='@' || matrice[m][n+1]==0){
				if(pcpu==2){
				//	printf("\ncicho2");
					//			getch();
					if(matrice[m][n+2]!=0){
					matrice[m][n+2]='@';}
					matrice[m][n]='o';
					matrice[lettera1][numero1-2]='+';
				}
				//printf("\n nonn1");
					//			getch();
				if(pcpu==1 && put==3){
					//printf("\n nonn");
					//getch();
					p=0;
					g=0;
					while(p==0){
									printf("con quante pedine vuoi spostare la vedina avversaria? ");
									scanf("%d",&g);
									if(g==2 || g==3){
										p=1;
									}

									}
				if(matrice[m][n+1]!=0){
				matrice[m][n+1]='@';}
				matrice[m][n]='o';
				if(g==2){
					matrice[lettera1][numero1-1]='+';
				}
				if(g==3){
					matrice[lettera1][numero1-2]='+';
				}
				}
			}

	}
}

//*********************************************************************************
//printf("\nfl e %d", fl5);
//getch();
if(fl5==0){
	return 0;
}
	system("CLS");
 visualizzamatrice();
	return 1;

}

/** \fn int confronto_cpu (char matrice[20][20],int m, int n, int lettera1, int numero1)
 *  Funzione che permette se e possibile di spostare le pedine avversarie
 *  \param matrice piena di caratteri
 * \param m colonna della matrice della pedina selezionata
 * \param n riga della matrice della pedina selezionata
 * \param lettera1 riga della matrice dove si vuole spostare la pedina
 * \param numero1 colonna della matrice dove si vuole spostare la pedina
 * \return 1 se le pedine sono state spostate.
 */

int confronto_cpu(char matrice[20][20],int m, int n, int lettera1, int numero1)
{
	int pcpu=1;
	int put=1;
	int p=0;
	int g=0;
	/// variabile fl utilizzato come booleano
	int fl=0;
	/// variabile fl1 utilizzato come booleano
	int fl1=0;
	/// variabile fl2 utilizzato come booleano
	int fl2=0;
	/// variabile fl3 utilizzato come booleano
	int fl3=0;
	/// variabile fl5 utilizzato come booleano
	int fl5=0;
	//printf("attendi\n");
	//getch();
	//printf(" m e %d n e %d", m,n);
	//getch();
	//printf("\nciaoo %c  %d %d %c", matrice[m-1][n], m-1,n+1, matrice[m+1][n]);
	//printf("\nciaoo %c %d %d ", matrice[lettera11][numero11], lettera11, numero11);
	//getch();

if(m==lettera1){
	fl5=5;
}
if(lettera1-1==m){
	if(m<4 && n==numero1){
		fl5=4;
	}
if(m>=4 && numero1+1==n){
	fl5=4;
}
}
if(lettera1-1==m){
	if(m<4 && numero1-1==n){
		fl5=3;
	}
	if(m>=4 && numero1==n){
		fl5=3;
	}
}
if(lettera1+1==m){
if(m<=4 && numero1==n){
	fl5=2;}
	if(m>4 && numero1-1==n){
			fl5=2;
		}

}
if(lettera1+1==m){
if(m<=4 && numero1+1==n){
	fl5=1;

}
if(m>4 &&  numero1==n){
	fl5=1;

}
}
//printf("fl e %d", fl5);
//getch();
//ATTACCO DA SINISTRA E DESTRA
//****************************
if(fl5==1){
//printf("da sx a dx");
 //  getch();
   if(m<=4){

		if(matrice[m+1][n+1]=='@'){
			pcpu=pcpu+1;
			fl=2;
		//	printf("11");
			//getch();

		}
		if(matrice[m+1][n+1]=='o'){

	//				printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//			getch();
					return 0;

				}
		if(fl==2){
			if(m+2<4){
		if(matrice[m+2][n+2]=='@'){
			pcpu=pcpu+1;
			//printf("12");
				//	getch();
		}
		if(matrice[m+2][n+2]=='o'){

			//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
				//				getch();
								return 0;
				}
			}else{
				if(matrice[m+2][n]=='@'){
					pcpu=pcpu+1;
				}
				if(matrice[m+2][n]=='o'){
					//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
						//				getch();
										return 0;
								}
			}
		}
		if(matrice[lettera1-1][numero1-1]=='o' ){
			put=put+1;
			fl1=2;
			//printf("97");
				//			getch();
		}
		if(fl1==2){
		if(matrice[lettera1-2][numero1-2]=='o' ){
			put=put+1;
		//	printf("87");
			//				getch();
		}
		}

	}
	//printf("fl e %d", fl);
	//getch();

	if(m>4){
		//printf("487");
			//	getch();
		fl=0;
		fl1=0;
		if(matrice[m+1][n]=='@'){
			pcpu=pcpu+1;
			fl1=2;
		}
		if(matrice[m+1][n]=='o'){
	//		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//						getch();
								return 0;
				}
		if(fl1==2){
		if(matrice[m+2][n]=='@'){
			pcpu=pcpu+1;

		}
		if(matrice[m+2][n]=='o'){
			//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
				//				getch();
								return 0;

				}
		}
		if(lettera1-1>=4){
		if(matrice[lettera1-1][numero1]=='o'){
			put=put+1;
			fl1=2;
			//printf("66");
				//	getch();

		}

		if(fl1==2){
			if(lettera1-2<=4){
		if(matrice[lettera1-2][numero1]=='o'){
			put=put+1;
			//printf("67");
				//			getch();
		}
			}
		}
		}
	//if(put==1){
		if(lettera1-1<4){
			if(matrice[lettera1-1][numero1-1]=='o'){
				put=put+1;
				fl2=2;
			}

			}
		if(fl2==2){
			//if(lettera1-2>=4){
				if(matrice[lettera1-2][numero1-1]=='o'){
					put=put+1;
				}
			//}
		}
//	}
	}


	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();
	if(pcpu==put){
	//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//					getch();
							return 0;
	}
	if(pcpu==1){
				g=2;
				if(put==3){
				while(p==0){
					while(p==0){
							g=0;
							g=2+rand()%3;
						if(g==2 || g==3){
						p=1;
						}
					}
						if(g==2 || g==3){
							p=1;
						}

						}
				}
				//printf("gg");
				//getch();
			if(g==3){
				//printf("f e %d",g);
				//getch();
				if(put>pcpu){
	//					printf("put e %d pcpu e %d", put,pcpu);
		//				getch();

					//if(m>4){
			//			printf("hola");
				//			getch();
						if(m+1<=4){
							//if(fl==2){
					//			printf("basta1");
						//		getch();
								if(matrice[m+1][n+1]!=0){
								matrice[m+1][n+1]='@';}
								matrice[m][n]='o';
								matrice[lettera1-2][numero1-2]='+';
						//	}
						}

					//	}

					if(m+1>4){
					//	if(pcpu==2){
							//if(fl1==2){
			//		printf("basta22");
				//	getch();
								if(matrice[m+1][n]!=0){
								matrice[m+1][n]='@';}
								matrice[m][n]='o';
								if(lettera1-2<4){
												matrice[lettera1-2][numero1-2]='+';
											}else{
												matrice[lettera1-2][numero1]='+';
											}
							}
				}

			}
			if(g==2){
			//	printf("f e %d",g);
				//				getch();
						if(put>pcpu){
					//			printf("put e %d pcpu e %d", put,pcpu);
						//		getch();

						//	if(m>4){
							//	printf("hola");
								//	getch();
								if(m+1<=4){
									//if(fl==2){
									//	printf("basta1");
										//getch();
										if(matrice[m+1][n+1]!=0){
										matrice[m+1][n+1]='@';}
										matrice[m][n]='o';
										matrice[lettera1-1][numero1-1]='+';
								//	}
								}

							//	}
							}
							if(m+1>4){
							//	if(pcpu==2){
									//if(fl1==2){
						//	printf("cornuto");
							//getch();
										if(matrice[m+1][n]!=0){
										matrice[m+1][n]='@';}
										matrice[m][n]='o';
										if(lettera1-1<4){
														matrice[lettera1-1][numero1-1]='+';
													}else{
														matrice[lettera1-1][numero1]='+';
													}
									}


					}
			}
	if(pcpu>1){
	//	printf("put e %d pcpu e %d", put,pcpu);
		//getch();

	if(m>4){
	//	printf("hola");
		//	getch();
		if(m+2<4){
			//if(fl==2){
			//	printf("basta1");
			//	getch();
				if(matrice[m+2][n+2]!=0){
				matrice[m+2][n+2]='@';}
				matrice[m][n]='o';
				matrice[lettera1-2][numero1-2]='+';
		//	}
		}

		}

	if(m+1>=4){
	//	if(pcpu==2){
			//if(fl1==2){
//	printf("basta57");
	//getch();
	if(m+1>4){
		//printf("perche");
		//getch();
		if(matrice[m+2][n]!=0){
						matrice[m+2][n]='@';}
	}else if(matrice[m+2][n+1]!=0){
				matrice[m+2][n+1]='@';}
				matrice[m][n]='o';
				if(lettera1-2<4){
								matrice[lettera1-2][numero1-2]='+';
							}else{
								matrice[lettera1-2][numero1]='+';
							}
			}
	}
}
//ATTACCO DA DESTRA A SINISTRA
//****************************
if(fl5==2){
	//printf("attacco da destra a sinistra");
   //getch();
  if (m<=4){

			if(matrice[m+1][n]=='@'){
				pcpu=pcpu+1;
				fl=2;
	//			printf("11");
		//		getch();

			}
			if(matrice[m+1][n]=='o'){
			//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
				//					getch();
									return 0;

						}
			if(m==4){
				if(matrice[m+1][n-1]=='@'){
								pcpu=pcpu+1;
								fl=2;
		//						printf("11");
			//					getch();

							}
				if(matrice[m+1][n-1]=='o'){
					//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
						//				getch();
										return 0;

											}
			}

			if(fl==2){
				if(m+2>=4){
			if(matrice[m+2][n]=='@'){
				pcpu=pcpu+1;
				//printf("12");
					//	getch();

			}if(matrice[m+2][n]=='o'){
				pcpu=pcpu+1;
		//		printf("\n non puoi spostare");
			//			getch();
			}
				}else if(matrice[m+2][n-1]=='@'){
						pcpu=pcpu+1;
					}
				if(matrice[m+2][n-1]=='o'){
//					printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
	//									getch();
										return 0;
									}

			}
			if(matrice[lettera1-1][numero1]=='o' ){
				put=put+1;
				fl1=2;
				//printf("97");
					//			getch();
			}
			if(fl1==2){
			if(matrice[lettera1-2][numero1]=='o' ){
				put=put+1;
			//	printf("87");
				//				getch();
			}
			}

		}
//		printf("fl e %d", fl);
	//	getch();

		if(m>4){
		//	printf("487");
			//		getch();
			fl=0;
			fl1=0;
			if(matrice[m+1][n-1]=='@'){
				pcpu=pcpu+1;
				fl1=2;
			}
			if(matrice[m+1][n-1]=='o'){
		//		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
			//						getch();
									return 0;

						}
			if(fl1==2){
			if(matrice[m+2][n-2]=='@'){
				pcpu=pcpu+1;

			}
			if(matrice[m+2][n-2]=='o'){

				//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
					//				getch();
									return 0;
						}
			}
			if(lettera1-1<=4){
			if(matrice[lettera1-1][numero1]=='o'){
				put=put+1;
				fl1=2;
				//printf("66");
					//	getch();

			}
			if(lettera1-1==4){
				if(matrice[lettera1-1][numero1+1]=='o'){
								put=put+1;
								fl3=2;
						//		printf("66");
							//			getch();

							}
			}
			if(lettera1-1>4){
				if(matrice[lettera1-1][numero1+1]=='o'){
												put=put+1;
												fl3=2;
								//				printf("66");
									//					getch();

											}
			}
			/*if(lettera1+2==4){
				fl1=0;
			}*/
			if(fl1==2){
				if(lettera1-2<=4){
			if(matrice[lettera1-2][numero1]=='o'){
				put=put+1;
	//			printf("67");
		//						getch();
			}
				}

			}
			if(fl3==2){
				if(lettera1-2<=4){
									if(matrice[lettera1-2][numero1+1]=='o'){
													put=put+1;
			//										printf("67");
				//													getch();
												}
								}
			}
			}
		if(put==1){
			if(lettera1-1>4){
				if(matrice[lettera1-1][numero1+1]=='o'){
					put=put+1;
					fl2=2;
					//printf("99");
						//																getch();
				}

				}
			if(fl2==2){
				if(lettera1-2>=4){
					if(matrice[lettera1-2][numero1+2]=='o'){
						put=put+1;
					//	printf("47");
						//																	getch();
					}
				}
			}
	}
		}


//		printf("put e %d pcpu e %d", put,pcpu);
	//	getch();
		if(pcpu==put){
		//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
			//					getch();
								return 0;
		}
		if(pcpu==1){
					g=2;
					if(put==3){
					while(p==0){
						while(p==0){
													g=0;
													g=2+rand()%3;
												if(g==2 || g==3){
												p=1;
												}
											}
							if(g==2 || g==3){
								p=1;
							}

							}
					}
		//			printf("gg");
			//		getch();
				if(g==3){
				//	printf("f e %d",g);
					//getch();
					if(put>pcpu){
						//	printf("put e %d pcpu e %d", put,pcpu);
							//getch();

						//if(m>4){
					//		printf("hola");
						//		getch();
							if(m+1<=4){
								//if(fl==2){
							//		printf("basta1");
								//	getch();
									if(matrice[m+1][n]!=0){
									matrice[m+1][n]='@';}
									matrice[m][n]='o';
									matrice[lettera1-2][numero1]='+';
							//	}
							}

						//	}

						if(m+1>4){
						//	if(pcpu==2){
								//if(fl1==2){
		//				printf("basta22");
			//			getch();
									if(matrice[m+1][n-1]!=0){
									matrice[m+1][n-1]='@';}
									matrice[m][n]='o';
									if(lettera1==5){
											matrice[lettera1-2][numero1+1]='+';
										}else if(lettera1-2<4){
													matrice[lettera1-2][numero1]='+';
												}else{
													matrice[lettera1-2][numero1+2]='+';
												}
								}
					}

				}
				if(g==2){

				//	printf("f e %d",g);
					//					getch();
										if(put>pcpu){
						//						printf("put e %d pcpu e %d", put,pcpu);
							//					getch();

											//if(m>4){
								//				printf("hola");
									//				getch();
												if(m+1<=4){
													//if(fl==2){
										//				printf("basta1");
											//			getch();
														if(matrice[m+1][n]!=0){
														matrice[m+1][n]='@';}
														matrice[m][n]='o';
														matrice[lettera1-1][numero1]='+';
												//	}
												}

											//	}

											if(m+1>4){
											//	if(pcpu==2){
													//if(fl1==2){
										//	printf("basta22");
											//getch();
														if(matrice[m+1][n-1]!=0){
														matrice[m+1][n-1]='@';}
														matrice[m][n]='o';
														if(lettera1-1<4){
																		matrice[lettera1-1][numero1]='+';
																	}else{
																		matrice[lettera1-1][numero1+1]='+';
																	}
													}
										}


						}
				}
		if(pcpu>1){
//			printf("put e %d pcpu e %d", put,pcpu);
	//		getch();

		if(m>4){
		//	printf("hola");
			//	getch();
			if(m+2<4){
				//if(fl==2){
				//	printf("basta1");
					//getch();
					if(matrice[m+2][n]!=0){
					matrice[m+2][n]='@';}
					matrice[m][n]='o';
					matrice[lettera1-2][numero1]='+';
			//	}
			}

			}

		if(m+1>=4){
		//	if(pcpu==2){
				//if(fl1==2){
//		printf("basta57");
	//	getch();
		if(m+1>4){
		//	printf("perche");
			//getch();
			if(matrice[m+2][n-2]!=0){
							matrice[m+2][n-2]='@';}
		}else if(matrice[m+2][n-1]!=0){
				matrice[m+2][n-1]='@';}
					matrice[m][n]='o';
					if(lettera1-1==4){
						matrice[lettera1-2][numero1+1]='+';
					}else if(lettera1-2<4){
									matrice[lettera1-2][numero1]='+';
								}else{
									matrice[lettera1-2][numero1+2]='+';
								}
				}
		}
}
//*******************************************************************************
	// DAL BASSO VERSO ALTO SPOSTA VERSO SINISTRA
//*******************************************************************************
if(fl5==3){
//printf("dal basso verso lalto sposta verso sinistra");
  // getch();
   if(m>4){

		if(matrice[m-1][n]=='@'){
			pcpu=pcpu+1;
			fl=2;
	//		printf("11");
		//	getch();

		}
		if(matrice[m-1][n]=='o'){
		//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
			//								getch();
											return 0;


				}
		if(m-2<4){
			fl=0;
		}
		if(fl==2){
		if(matrice[m-2][n]=='@'){
			pcpu=pcpu+1;
		//	printf("12");
			//		getch();
		}
		if(matrice[m-2][n]=='o'){

		//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
			//								getch();
											return 0;
				}
		}
		if(matrice[lettera1+1][numero1]=='o' ){
			put=put+1;
			fl1=2;
		//	printf("97");
			//				getch();
		}
		if(fl1==2){
		if(matrice[lettera1+2][numero1]=='o' ){
			put=put+1;
		//	printf("87");
			//				getch();
		}
		}
	/*	if(put==1){
			if( matrice[lettera1+1][numero1]=='@'){
					put=put+1;
					printf("197");
									getch();
				}
			if(put==2){
				if( matrice[lettera1+2][numero1]=='@' ){
					put=put+1;
					printf("187");
									getch();
				}
			}
		}*/
	}
	//printf("fl e %d", fl);
	//getch();

	if(m<4){
		//printf("487");
			//	getch();
		fl=0;
		fl1=0;
		if(matrice[m-1][n-1]=='@'){
			pcpu=pcpu+1;
			fl1=2;
		}
		if(matrice[m-1][n-1]=='o'){
		//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
			//								getch();
											return 0;
				}
		if(fl1==2){
		if(matrice[m-2][n-2]=='@'){
			pcpu=pcpu+1;

		}
		if(matrice[m-2][n-2]=='o'){
	//		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//									getch();
											return 0;

				}
		}
		if(lettera1<4){
		if(matrice[lettera1+1][numero1+1]=='o'){
			put=put+1;
			fl1=2;
			//printf("66");
				//	getch();

		}
		/*if(lettera1+2==4){
			fl1=0;
		}*/
		if(fl1==2){
		if((matrice[lettera1+2][numero1+2]=='o' && lettera1+2==4) || (matrice[lettera1+2][numero1+1]=='o' && lettera1+2==5 )){
			put=put+1;
			//printf("67");
				//			getch();
		}
		}
		}
	if(put==1){
		if(lettera1+1>=4){
			if(matrice[lettera1+1][numero1]=='o'){
				put=put+1;
				fl2=2;
			}

			}
		if(fl2==2){
			if(lettera1+2>=4){
				if(matrice[lettera1+2][numero1]=='o'){
					put=put+1;
				}
			}
		}
	}
	}

	if(m==4){
	//	printf("387");
		//							getch();
		if(matrice[m-1][n-1]=='@'){
			pcpu=pcpu+1;
			fl2=2;
			if(matrice[m-1][n-1]=='o'){
			//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
				//								getch();
												return 0;
			}
			if(fl2==2){
				if(matrice[m-2][n-2]=='@'){
					pcpu=pcpu+1;

				}
				if(matrice[m-2][n-2]=='@'){

					//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
						//							getch();
													return 0;
								}
			}
		}
		if(matrice[lettera1+1][numero1]=='o' ){
				put=put+1;
				fl1=2;
				//printf("97");
					//			getch();
			}
			if(fl1==2){
			if(matrice[lettera1+2][numero1]=='o' ){
				put=put+1;
				//printf("87");
					//			getch();
			}
			}
	}
	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();
	if(pcpu==put){
	//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//								getch();
										return 0;
	}

	if(put>pcpu){
	//	printf("put e %d pcpu e %d", put,pcpu);
		//getch();

	if(m>4){
	//	printf("hola");
		//	getch();
		if(pcpu==2){
			//if(fl==2){
			//	printf("basta1");
				//getch();
				if(matrice[m-2][n-1]!=0){
				matrice[m-2][n-1]='@';}
				matrice[m][n]='o';
				matrice[lettera1+2][numero1]='+';
		//	}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
			while(p==0){
				while(p==0){
											g=0;
											g=2+rand()%3;
										if(g==2 || g==3){
										p=1;
										}
									}
					if(g==2 || g==3){
						p=1;
					}

					}
			}
			if(matrice[m-1][n]!=0){
			matrice[m-1][n]='@';}
			matrice[m][n]='o';
		//	if(m-1<4){////////
			if(g==2){

				matrice[lettera1+1][numero1]='+';}

			if(g==3){
				//printf("\ngg1");
				//getch();

				matrice[lettera1+2][numero1]='+';}
			}
			//}
			/*if(m-1>=4){////
				if(g==2){
							matrice[lettera1+1][numero1]='8';
						}
						if(g==3){
							matrice[lettera1+2][numero1]='9';
						}
			}*/
		}
	}
	if(m<4){
		if(pcpu==2){
			//if(fl1==2){
	//printf("basta");
	//getch();
				if(matrice[m-2][n-2]!=0){
				matrice[m-2][n-2]='@';}
				matrice[m][n]='o';
				if(matrice[lettera1+2][numero1+1]=='o' && lettera1+2==5){
								matrice[lettera1+2][numero1+1]='+';
							}else if(matrice[lettera1+2][numero1+1]=='o' && lettera1+2>4){
								matrice[lettera1+2][numero1]='+';
							}else if(matrice[lettera1+2][numero1+2]=='o' && lettera1+2>4){
								matrice[lettera1+2][numero1]='+';
							}else{
				matrice[lettera1+2][numero1+2]='+';}
			//}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
			while(p==0){
				while(p==0){
											g=0;
											g=2+rand()%3;
										if(g==2 || g==3){
										p=1;
										}
									}
					if(g==2 || g==3){
						p=1;
					}

					}
			}
			//printf("gg");
			//getch();
			if(matrice[m-1][n-1]!=0){
			matrice[m-1][n-1]='@';}
			matrice[m][n]='o';
			if(g==2){
				if(lettera1+1==4 || lettera1+1<4){
					matrice[lettera1+1][numero1+1]='+';
				}else{
				matrice[lettera1+1][numero1]='+';
				}
			}
			if(g==3){
				if(matrice[lettera1+2][numero1+1]=='o' && lettera1+2==5){
					matrice[lettera1+2][numero1+1]='p';
				}else if (matrice[lettera1+2][numero1+2]=='o' && lettera1+2==4){
					matrice[lettera1+2][numero1+2]='+';
				}else{
				matrice[lettera1+2][numero1]='+';
				}
				//printf("lettera1+2 e %d", lettera1+2);
				//getch();
			}
		}
	}
	if(m==4){
		if(pcpu==2){
			matrice[m-2][n-2]='@';
			matrice[m][n]='o';
			matrice[lettera1+2][numero1]='+';
		}
		if(pcpu==1){
			matrice[m-1][n-1]='@';
			matrice[m][n]='o';
			g=2;
					if(put==3){
					while(p==0){
						while(p==0){
													g=0;
													g=2+rand()%3;
												if(g==2 || g==3){
												p=1;
												}
											}
							if(g==2 || g==3){
								p=1;
							}

							}
					}
					if(g==2){
						matrice[lettera1+1][numero1]='+';
					}
					if(g==3){
						matrice[lettera1+2][numero1]='+';
					}

		}
	}
}
//*******************************************************************************
	//DAL BASSO VERSO ALTO SPOSTA VERSO DESTRA
//*******************************************************************************
if(fl5==4){
	//printf("dal basso verso lalto sposta verso destra");
   //getch();
 if(m<=4){

		if(matrice[m-1][n]=='@'){
			pcpu=pcpu+1;
			fl=2;
	//		printf("11");
		//	getch();

		}
		if(matrice[m-1][n]=='o'){

			//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
				//							getch();
											return 0;

				}
		if(fl==2){
		if(matrice[m-2][n]=='@'){
			pcpu=pcpu+1;
//			printf("12");
	//				getch();
		}
		if(matrice[m-2][n]=='o'){

	//		printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//									getch();
											return 0;
				}
		}
		if(matrice[lettera1+1][numero1-1]=='o' ){
			put=put+1;
			fl1=2;
			//printf("97");
						//	getch();
		}
		if(fl1==2){
		if(matrice[lettera1+2][numero1-2]=='o' ){
			put=put+1;
			//printf("87");
				//			getch();
		}
		}
		if(put==1){
			if( matrice[lettera1+1][numero1]=='o'){
					put=put+1;
					//printf("197");
						//			getch();
				}
			if(put==2){
				if( matrice[lettera1+2][numero1]=='o' ){
					put=put+1;
					//printf("187");
						//			getch();
				}
			}
		}
	}
	//printf("fl e %d", fl);
	//getch();

	if(m>4){
		fl=0;
		fl1=0;
		if(matrice[m-1][n+1]=='@'){
			pcpu=pcpu+1;
			fl1=2;
		}
		if(matrice[m-1][n+1]=='o'){
			//printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
				//							getch();
											return 0;
				}
		if(fl1==2){
		if(matrice[m-2][n+2]=='@'){
			pcpu=pcpu+1;

		}
		if(matrice[m-2][n+2]=='o'){
		//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
			//								getch();
											return 0;

				}
		}
		if(matrice[lettera1+1][numero1-1]=='o'){
			put=put+1;
			fl1=2;
			//printf("66");
				//	getch();

		}
		if(fl1==2){
		if(matrice[lettera1+2][numero1-2]=='o'){
			put=put+1;
			//printf("67");
				//			getch();
		}
		}
	}
	//printf("put e %d pcpu e %d", put,pcpu);
	//getch();
	if(pcpu==put){
	//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//								getch();
										return 0;
	}

	if(put>pcpu){
	//	printf("put e %d pcpu e %d", put,pcpu);
		//getch();

	if(m<=4){
		//printf("hola");
			//getch();
		if(pcpu==2){
			//if(fl==2){
				//printf("basta1");
				//getch();
				if(matrice[m-2][n]!=0){
				matrice[m-2][n]='@';}
				matrice[m][n]='o';
				matrice[lettera1+2][numero1-2]='+';
		//	}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
			while(p==0){
				while(p==0){
											g=0;
											g=2+rand()%3;
										if(g==2 || g==3){
										p=1;
										}
									}
					if(g==2 || g==3){
						p=1;
					}

					}
			}
			if(matrice[m-1][n]!=0){
			matrice[m-1][n]='@';}
			matrice[m][n]='o';
			if(m-1<4){////////
			if(g==2){
				if(lettera1+1 >4){
					matrice[lettera1+1][numero1-1]='+';
				}else{
				matrice[lettera1+1][numero1]='+';}
			}
			if(g==3){
				if(lettera1+2>4){
								matrice[lettera1+2][numero1-2]='+';
							}else{
				matrice[lettera1+2][numero1]='+';}
			}
			}
			/*if(m-1>=4){////
				if(g==2){
							matrice[lettera1+1][numero1]='8';
						}
						if(g==3){
							matrice[lettera1+2][numero1]='9';
						}
			}*/
       }
	}
	if(m>4){
		if(pcpu==2){
			//if(fl1==2){
	//printf("basta");
	//getch();
				if(matrice[m-2][n]!=0){
				matrice[m-2][n]='@';}
				matrice[m][n]='o';
				matrice[lettera1+2][numero1-2]='+';
			//}
		}
		if(pcpu==1){
			g=2;
			if(put==3){
			while(p==0){
				while(p==0){
											g=0;
											g=2+rand()%3;
										if(g==2 || g==3){
										p=1;
										}
									}
					if(g==2 || g==3){
						p=1;
					}

					}
			}
			if(matrice[m-1][n+1]!=0){
			matrice[m-1][n+1]='@';}
			matrice[m][n]='o';
			if(g==2){
				matrice[lettera1+1][numero1-1]='+';
			}
			if(g==3){
				matrice[lettera1+2][numero1-2]='+';
			}
		}
	}
	}
}
//********************************************************************************
	//ORIZZONTALE
//********************************************************************************
if(fl5==5){
//printf("orizzontale");
	//getch();
	fl=0;
	fl1=0;
	if(matrice[m][n-1]=='@' || matrice[m][n+1]=='@'){
		pcpu=pcpu+1;
		fl=2;
	}
	//if(matrice[m][n-1]=='o' || matrice[m][n+1]=='o'){
		//	printf("\n non puoi spostare");
			//getch();
	//	}
	if(fl==2){
		if(matrice[m][n-2]=='@' || matrice[m][n+2]=='@'){
			pcpu=pcpu+1;
		}
		//if(matrice[m][n-2]=='o' || matrice[m][n+2]=='o'){
			//printf("\n non puoi spostare");
				//		getch();
				//}
	}
	if(matrice[lettera1][numero1-1]=='o' ||matrice[lettera1][numero1+1]=='o'){
		put=put+1;
		fl1=2;
	}
	if(fl1==2){
		if(matrice[lettera1][numero1-2]=='o' ||matrice[lettera1][numero1+2]=='o'){
			put=put+1;
		}
	}
	//printf("\nput e %d pcpu e %d", put, pcpu);
	//getch();
	if(put==pcpu){
	//	printf("\n non puoi spostarla premi un tasto per inserire nuove coordinate");
		//								getch();
										return 0;
	}
	if(put>pcpu){
		if(matrice[m][n-1]=='+' || matrice[m][n-1]=='@' || matrice[m][n-1]==0){
			if(pcpu==2){
				//printf("\ncicho1");
				//getch();
				if(matrice[m][n-2]!=0){
				matrice[m][n-2]='@';}
				matrice[m][n]='o';
				matrice[lettera1][numero1+2]='+';
			}
			if(pcpu==1 && put==3){
				p=0;
				g=0;
				while(p==0){
					while(p==0){
												g=0;
												g=2+rand()%3;
											if(g==2 || g==3){
											p=1;
											}
										}
								if(g==2 || g==3){
									p=1;
								}

								}
				if(matrice[m][n-1]!=0){
			matrice[m][n-1]='@';}
			matrice[m][n]='o';
			if(g==2){
				matrice[lettera1][numero1+1]='+';
			}
			if(g==3){
				matrice[lettera1][numero1+2]='+';
			}
			}
		}

	//*************************************
		//printf("\n nonn2");
			//						getch();
		if(matrice[m][n+1]=='+' || matrice[m][n+1]=='@' || matrice[m][n+1]==0){
				if(pcpu==2){
				//	printf("\ncicho2");
					//			getch();
					if(matrice[m][n+2]!=0){
					matrice[m][n+2]='@';}
					matrice[m][n]='o';
					matrice[lettera1][numero1-2]='+';
				}
				//printf("\n nonn1");
					//			getch();
				if(pcpu==1 && put==3){
					//printf("\n nonn");
					//getch();
					p=0;
					g=0;
					while(p==0){
						while(p==0){
													g=0;
													g=2+rand()%3;
												if(g==2 || g==3){
												p=1;
												}
											}
									if(g==2 || g==3){
										p=1;
									}

									}
				if(matrice[m][n+1]!=0){
				matrice[m][n+1]='@';}
				matrice[m][n]='o';
				if(g==2){
					matrice[lettera1][numero1-1]='+';
				}
				if(g==3){
					matrice[lettera1][numero1-2]='+';
				}
				}
			}

	}
}

//*********************************************************************************
//printf("\nfl e %d", fl5);
//getch();
if(fl5==0){
	return 0;
}
	system("CLS");
 visualizzamatrice();
	return 1;

}

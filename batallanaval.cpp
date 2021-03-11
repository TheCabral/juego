///LIBRERIAS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include <windows.h>
#include<iostream>
#define MAXIMO 10

//VARIABLES
int matriz1[21][11],matriz2[21][11],matriz3[21][11],matriz4[21][11];
int x,y,i,j;
int cdba=0,cdbb=0,cdbha=0,cdbhb=0;
char op1 , op2 , op3 , op4 , op5 , op6 , ota , otb ;
int tiradaa,tiradab;
int cdbpc=0,cdbhpc=0;
int cona1=0,cona2;
int conb1=0,conb2;
int v;

//FUNCIONES
void conjb1(void);
void conjb2(void);
void conja1(void);
void conja2(void);
void conja3(void);
void conjb3(void);
void diceganador(void);

//MUESTRAN UN MENU
	void menu(void);
	void menu2(void);
	void menu3(void);
	void comienso(void);
//CONFIGURACION
	void tja(void);
	void tjb(void);
	void tjpc(void);
	void tjapc(void);
//VISUALIZACION
	void verta(void);  
	void vertb(void); 
	void vertpc(void); 
	void vertapc(void);
	void vertabla(void);
//ESTRATEGIA
	void tiroa(void);  
	void tirob(void);  
	void tiropc(void);  
	void tiroapc(void);
//INTERFACE
	void barcohun(void);  
	void barcohun1(void);  
	void creditos(void);
	void musica(void);    
	void loading(void);    
	void presentacion(void);
	void reglamento(void);  
	void coordenadas(int);
	void boton(void);
//SORTEO DEL PRIMER TIRO
	void dadosa(void);      
	void dadosb(void);       
	void tirada(void);
//ADVIERTE EL GANADOR DEL JUEGO
	void diceganavspc(void); 
	void sefijaencdb (void);

//DECLARACION DE LA MATRIZ DEL JUGADOR 1 CON EL TABLEO EN '0'
void iniciomatriz1(void)
{
for(x=0;x<=20;x++)
	{
	for(y=0;y<=10;y++)
		{
		matriz1[x][y] = 0;
		}
	}
}
//DECLARACION DE LA MATRIZ DEL JUGADOR 2 CON EL TABLEO EN '0'
void iniciomatriz2(void)
{
for(x=0;x<=20;x++)
	{
	for(y=0;y<=10;y++)
		{
		matriz2[x][y] = 0;
		}
	}
}
//DECLARACION DE LA MATRIZ DEL COMPUTADOR CON EL TABLEO EN '0'
void iniciomatriz3(){
	for(x=0;x<=20;x++){
		for(y=0;y<=10;y++){
		matriz3[x][y]=0;
		}
	}
}
		
void gotoxy(int x, int y){
	HANDLE hcon;	
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
	
}
void OcultarCursor(){
	HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=50;
    cci.bVisible=FALSE;
    
    
    
    SetConsoleCursorInfo(hCon,&cci);
}
void textbackground(int X){
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
void clrscr()
{
	system("cls");
}
void textcolor(int color){
	char colorchar;
	switch(color){
		case 0:
			colorchar='0';
			break;
		case 1:
			colorchar='1';
			break;
		case 2:
			colorchar='2';
			break;
		case 3:
			colorchar='3';
			break;
		case 4:
			colorchar='4';
			break;
		case 5:
			colorchar='5';
			break;
		case 6:
			colorchar='6';
			break;
		case 7:
			colorchar='7';
			break;
		case 8:
			colorchar='8';
			break;
		case 9:
			colorchar='9';
			break;
		case 10:
			colorchar='A';
			break;
		case 11:
			colorchar='B';
			break;
		case 12:
			colorchar='C';
			break;
		case 13:
			colorchar='d';
			break;
		case 14:
			colorchar='E';
			break;
		case 15:
			colorchar='f';
			break;

		
	};
	char num_char[MAXIMO + sizeof(char)];
	sprintf(num_char, "color %c",colorchar);
	system(num_char);
}
void delay(int ms){
	Sleep(ms);
}
void MostraCursor();
//DECLARACION DE LA MATRIZ PARA QUE EL COMPUTADOR TIRE SOLO UNA VES EN CADA LUGAR
//ES PARA QUE GUERDE EL LUGAR DONDE TIRO Y NO LO REPITA
void iniciomatriz4(){
for(x=0;x<=20;x++)
	{
	for(y=0;y<=10;y++)
		{
		matriz4[x][y]=0;
		}
		}
		}
//FINCION PRINCIPAL
int main()
{
	OcultarCursor();
	menu();
	textbackground(0);
	clrscr();
	textbackground(1);
	textcolor(13);
		gotoxy(15,10);printf(" 1");textcolor(0); printf("- Ver presentacion ");
	textcolor(14);
		gotoxy(40,10);printf(" 2");textcolor(0); printf("- Empezar a jugar ");
	op1 = getch();
	switch(op1)
		{
		case '1': boton();
				presentacion();    //SE VE LA PRESENTACION DEL JUEGO
				break;
	
		case '2': boton();
				menu();    //TE LLEVA AL MENU PRINCIPAL
				break;
		}
}
void menu(void){     //MENU PRINCIPAL
	cdba=0;
	cdbb=0;
	cdbha=0;
	cdbhb=0;
	cdbpc=0;
	cdbhpc=0;
	cona1=0;
	cona2=0;
	iniciomatriz3();
	iniciomatriz4();
	OcultarCursor();
	do
	{
	clrscr();
	textbackground(0);
	clrscr();
	textcolor(14);
	gotoxy(9,1);	printf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(9,2);	printf("К                                                               К");
	gotoxy(9,3);	printf("К                                                               К");
	gotoxy(9,4);	printf("К                                                               К");
	gotoxy(9,5);	printf("К                                                               К");
	gotoxy(9,6);	printf("К                                                               К");
	gotoxy(9,7);	printf("К                                                               К");
	gotoxy(9,8);	printf("К                                                               К");
	gotoxy(9,9);	printf("К                                                               К");
	gotoxy(9,10);	printf("К                                                               К");
	gotoxy(9,11);	printf("К                                                               К");
	gotoxy(9,12);	printf("К                                                               К");
	gotoxy(9,13);	printf("К                                                               К");
	gotoxy(9,14);	printf("К                                                               К");
	gotoxy(9,15);	printf("К                                                               К");
	gotoxy(9,16);	printf("К                                                               К");
	gotoxy(9,17);	printf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	
	textcolor(14 );
	gotoxy(11,2);	printf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(11,3);	printf("К                                                           К");
	gotoxy(11,4);	printf("К                                                           К");
	gotoxy(11,5);	printf("К                                                           К");
	gotoxy(11,6);	printf("К                                                           К");
	gotoxy(11,5);	printf("К                                                           К");
	gotoxy(11,6);	printf("К                                                           К");
	gotoxy(11,7);	printf("К                                                           К");
	gotoxy(11,8);	printf("К                                                           К");
	gotoxy(11,9);	printf("К                                                           К");
	gotoxy(11,10);	printf("К                                                           К");
	gotoxy(11,11);	printf("К                                                           К");
	gotoxy(11,12);	printf("К                                                           К");
	gotoxy(11,13);	printf("К                                                           К");
	gotoxy(11,14);	printf("К                                                           К");
	gotoxy(11,15);	printf("К                                                           К");
	gotoxy(11,16);	printf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	
	textbackground(1);
	textcolor(15);
	delay(100);
	gotoxy(12,3);	printf("                                                           ");
	gotoxy(12,4);	printf("  BBBB   AAAAAA  TTTTTTT  AAAAAA  L       L       AAAAAAA  ");
	gotoxy(12,5);	printf("  B   B  A    A     T     A    A  L       L       A     A  ");
	gotoxy(12,6);	printf("  BBBB   AAAAAA     T     AAAAAA  L       L       AAAAAAA  ");
	gotoxy(12,7);	printf("  B   B  A    A     T     A    A  L       L       A     A  ");
	gotoxy(12,8);	printf("  BBBB   A    A     T     A    A  LLLLLL  LLLLLL  A     A  ");
	gotoxy(12,9);	printf("                                                           ");
	gotoxy(12,10); 	printf("         NN   N  AAAAAA   V      V  AAAAAA  L              ");
	gotoxy(12,11); 	printf("         NN   N  A    A   V      V  A    A  L              ");
	gotoxy(12,12);	printf("         N N  N  AAAAAA   V      V  AAAAAA  L              ");
	gotoxy(12,13);	printf("         N  N N  A    A    V    V   A    A  L              ");
	gotoxy(12,14);	printf("         N   NN  A    A      VV     A    A  LLLLLL         ");
	gotoxy(12,15);	printf("                                                           ");
	
	textbackground(0);
	gotoxy(4,19);
	textcolor(14);
	printf("MENU");
	gotoxy(11,19);
	textcolor(2);
	printf("1 JUGAR");
	gotoxy(11,20);
	printf("2 REGLAMENTO");
	gotoxy(11,21);
	printf("3 VER PRESENTACION");
	gotoxy(11,22);
	printf("4 CREDITOS");
	gotoxy(11,23);
	printf("0 SALIR DEL BATALLA NAVAL");
	gotoxy(4,24);
	textcolor(14);
	printf("OPCION:");
	op2 = getch();
	switch(op2)
		{
		case '1':      	boton();
				menu2();    //TE LLEVA AL MENU DE TIPOS DE JUEGO
				break;
	
		case '2':	boton();
				reglamento();   //TE MUESTRA EL REGLAMENTO DEL JUEGO
				break;
	
		case '3':      	boton();
				presentacion();     //TE MUESTRA LA PRESENTACION
				break;
	
		case '4':      	boton();
				creditos();     //TE MUESTRA LOS NOMBRES DE LOS
				break;          //CREADORES DE JUEGO
		}
	}
	
	while (op2!='0');
	exit(0);

}
//MENU PARA LA CONFIGURACION DE BARCOS DE LOS JUGADORES
void menu3(void)
{
	OcultarCursor();
	do
	{
	textbackground(0);
	clrscr();
	textcolor(14);
	gotoxy(4,4);
	printf("MENU");
	textcolor(2);
	gotoxy(11,5);
	printf("1 BARCOS JUGADOR A");
	gotoxy(11,6);
	printf("2 BARCOS JUGADOR B");
	textcolor(7);
	gotoxy(11,7);
	printf("3 COMIENSO");
	textcolor(15);
	gotoxy(11,10);
	printf("0 VOLVER");
	textcolor(14);
	gotoxy(4,12);
	printf("OPCION:");
	op3=getch();
	switch(op3)
		{
		case '1':	boton();
				conja3();
				break;
	
		case '2':	boton();
				conjb3();
				break;
	
		case '3': boton();
				sefijaencdb();
				break;
		}
	}
	
	while(op3!='0');
	menu();
}
void vertabla(void)
{
OcultarCursor();
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(4);
		printf(" ");
		}
	}
}
void MostraCursor(){
	HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=50;
    cci.bVisible=true;
    
    
    
    SetConsoleCursorInfo(hCon,&cci);
}
//TABLA DEL JUGADOR A
void tja(void)
{

iniciomatriz1(); //LLAMO A LA FUNCION INICIOMARTIZ1 QUE ME INICIALIZA LAS
cdba=0;		 // POSICIONES 'X' 'Y' TODAS EN EL VALOR 0 (cero)
textbackground(0);
clrscr();
coordenadas(22);
textcolor(15);
gotoxy(30,3);
printf("JUGADOR A:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
printf(" m");textcolor(10);printf("  Colocar barco ");
gotoxy(30,6); 		    printf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,7);
printf(" d");textcolor(10);printf("  Borrar barco  ");
gotoxy(30,8); 		    printf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,9);
printf(" V");textcolor(10);printf("olver           ");
gotoxy(30,10);	printf("Debe colocar 10 barcos");

vertabla();

gotoxy(1,1);
x=1;
y=1;

MostraCursor();
do
{
ota = getch();
switch(ota)
	{
     case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;


	case 'm':
		if ((cdba<10) && (matriz1[x][y]!=1))
		{
		{
		textcolor(1);
		printf("");
		cdba = cdba + 1;
		}
		if (x < 20)
			{
			matriz1[x][y]=1;
			x=x+1;
			}

		else
			{
			gotoxy(20,y);
			matriz1[x][y]=1;
			}
		}
		break;

	case'D':case 'd':if(matriz1[x][y]!=0)
		{
		if (x<20)
		{
		textcolor(7);
		printf(" ");
		cdba = cdba - 1;
		matriz1[x][y]=0;
		x=x+1;
		}
		else
		if (x==20)
			{
			textcolor(7);
			printf(" ");
			cdba = cdba - 1;
			matriz1[20][y]=0;
			gotoxy(20,y);
			}

		}
		else
			x=x;

		break;
	}
}
while(ota!='v' && ota!='V');
conja1();
}
//TABLA DEL JUGADOR B
void tjb(void)
{

iniciomatriz2();
cdbb=0;
textbackground(0);
clrscr();
coordenadas(22);
textcolor(15);
gotoxy(30,3);
printf("JUGADOR B:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
printf(" m");textcolor(10);printf("  Colocar barco ");
gotoxy(30,6); 		    printf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,7);
printf(" d");textcolor(10);printf("  Borrar barco  ");
gotoxy(30,8); 		    printf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,9);
printf(" V");textcolor(10);printf("olver           ");
gotoxy(30,10);	printf("Debe colocar 10 barcos");

vertabla();

gotoxy(1,1);
x=1;
y=1;

MostraCursor();
do
{
otb = getch();
switch(otb)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

		case 'm':
		if ((cdbb<10) && (matriz2[x][y]!=1))
		{
		{
		textcolor(1);
		printf("");
		cdbb = cdbb + 1;
		}
		if (x < 20)
			{
			matriz2[x][y] = 1;
			x = x+1;
			}

		else
			{
			gotoxy(20,y);
			matriz2[x][y] = 1;
			}
		}
		break;

	case'D':case 'd':if(matriz2[x][y]!=0)
			{
		if (x<20)
		{
		textcolor(7);
		printf(" ");
		cdbb = cdbb - 1;
		matriz2[x][y]=0;
		x=x+1;
		}
		else
		if (x==20)
			{
			textcolor(7);
			printf(" ");
			cdbb = cdbb - 1;
			matriz2[20][y]=0;
			gotoxy(20,y);
			}
		    }
	    else
		   x=x;


		break;
	}
}
while(otb!='v' && otb!='V');
conjb1();
}
void boton(void)
{
Beep(560,200);
}
//COMIENSO DEL JUEGO TIPO H VS H
void comienzo(void)
{
OcultarCursor();
do

{
textbackground(0);
clrscr();
textcolor(14);	gotoxy(6,3);	printf("MENU");
textcolor(2);	gotoxy(10,5);	printf("1 - Ataque jugador A\n");
textcolor(10);	gotoxy(10,6);	printf("2 - Ataque jugador B\n");
textcolor(2);	gotoxy(10,7);	printf("3 - Consultar barcos jugador A\n");
textcolor(10);	gotoxy(10,8);	printf("4 - Consultar barcos jugador B\n");
textcolor(2);	gotoxy(10,10);	printf("0 - Volver al menЃ principal\n");
textcolor(14);	gotoxy(3,12);	printf("OpciЂn:");
op4=getch();
switch(op4)
	{
	case '1':     	boton();
				tiroa();
				break;

	case '2':     	boton();
				tirob();
				break;

	case '3':     	boton();
				conja2();
				break;

	case '4':		boton();
				conjb2();
				break;

	case '0':      boton();
			     textcolor(10);
			     gotoxy(3,15);printf("DECEAN SALIR DEL JUEGO? s/n");
			     op6=getch();
				switch(op6)
			     	{
			     	case'S':case 's':	boton();
			     					menu();
			     					break;

			     	case 'n':      	boton();
			     					comienzo();
			     					break;
			     	}
			     break;
	}
}

while((cdbb !=0) && (cdba !=0));
diceganador();
}
void diceganador(void)
{
OcultarCursor();
clrscr();
textbackground(0);
if (cdbb==0)
	{
	textbackground(1);
	textcolor(15 );
	printf("                                                    ");
	printf("                                                    ");
	printf("     Ha ganado el jugador A!!                       ");
	printf("                                                    ");
	printf("                                ");
	textbackground(0);
	textcolor(15);
	gotoxy(19,7);   	printf("ЩЭЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(19,8);		printf("К A К   К BARCOS HUNDIDOS К");
	gotoxy(19,9);   	printf("ЬЭЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
	gotoxy(19,10);		printf("К B К   К BARCOS HUNDIDOS К");
	gotoxy(19,11);   	printf("ШЭЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	textcolor(10 );
	gotoxy(25,8);	printf("%d", cdbha);
	textcolor(13);
	gotoxy(25,10);	printf("%d", cdbhb);
	getch();
	menu();
	}
if (cdba==0)
	{
	textbackground(1);
	textcolor(15 );
	printf("                                                    ");
	printf("                                                    ");
	printf("     Ha ganado el jugador B!!                       ");
	printf("                                                    ");
	printf("                                ");
	textbackground(0);
	textcolor(15);
	gotoxy(19,7);   	printf("ЩЭЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(19,8);		printf("К A К   К BARCOS HUNDIDOS К");
	gotoxy(19,9);   	printf("ЬЭЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
	gotoxy(19,10);		printf("К B К   К BARCOS HUNDIDOS К");
	gotoxy(19,11);   	printf("ШЭЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	textcolor(13);
	gotoxy(25,8);	printf("%d", cdbha);
	textcolor(10 );
	gotoxy(25,10);	printf("%d", cdbhb);
	getch();
	menu();
	}
}
//TIRO DEL JUGADOR A A LOS BARCOS DEL JUGADOR B
void tiroa(void)
{
textbackground(0);
clrscr();
textbackground(0);
				textcolor(7);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(9);
						if (matriz2[x][y] == 3)
							{
							textcolor(4);
							printf("X");
							}
						else
							if (matriz2[x][y] == 2)
								{
								textcolor(0);
								printf("*");
								}
							else
								printf(" ");
						}
					}
coordenadas(22);
textcolor(15);
gotoxy(30,3);
printf("JUGADOR A:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
printf(" t");textcolor(10);printf("  Tira una bomba");
MostraCursor();
gotoxy(1,1);
x=1;
y=1;

do
{
ota = getch();
switch(ota)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

	case'T':case 't':
				if (matriz2[x][y] == 1)
				{
				textbackground(0);
				textcolor(15);	gotoxy(3,13);  printf("Hundido!!!");
				barcohun1();
				//sound(580);delay(300);nosound();
				Beep(580,300);
				//sound(700);delay(300);nosound();
				Beep(700,300);
				//sound(800);delay(200);nosound();
				Beep(800,200);
				//sound(950);delay(300);nosound();
				Beep(950,300);
				//sound(800);delay(200);nosound();
				Beep(800,200);
				//sound(950);delay(500);nosound();
				Beep(950,500);
				matriz2[x][y] = 3;
				cdbb = cdbb - 1;
				cdbha = cdbha + 1;
				if((cdba!=0) && (cdbb!=0))
				{
				tiroa();
				}
				else
				diceganador();
				}
			else
				{
				textbackground(0);
				textcolor(3);	gotoxy(3,13);	printf("Agua");
				matriz2[x][y] = 2;
				textbackground(0);
				textcolor(7);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(9);
						if (matriz2[x][y] == 3)
							{
							textcolor(4);
							printf("X");
							}
						else
							if (matriz2[x][y] == 2)
								{
								textcolor(0);
								printf("*");
								}
							else
								printf(" ");
						}
					}
				getch();
				comienzo();
				}
			break;
	}
}
while(ota!='v' && ota!='V');
comienzo();
}
//TIRO DEL JUGADOR B A LOS BARCOS DEL JUGADOR A
void tirob(void)
{
textbackground(0);
clrscr();
textbackground(0);
				textcolor(7);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(9);
						if (matriz1[x][y] == 3)
							{
							textcolor(4);
							printf("X");
							}
						else
							if (matriz1[x][y] == 2)
								{
								textcolor(0);
								printf("*");
								}
							else
								printf(" ");
						}
					}
coordenadas(22);
textcolor(15);
gotoxy(30,3);
printf("JUGADOR B:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
printf(" t");textcolor(10);printf("  Tira una bomba");
MostraCursor();
gotoxy(1,1);
x=1;
y=1;

do
{
otb = getch();
switch(otb)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

	case'T':case 't':  if (matriz1[x][y] == 1)
				{
				textbackground(0);
				textcolor(15);	gotoxy(3,13);  printf("Hundido!!!");
				barcohun1();
				//sound(580);delay(300);nosound();
				Beep(580,300);
				//sound(700);delay(300);nosound();
				Beep(700,300);
				//sound(800);delay(200);nosound();
				Beep(800,200);
				//sound(950);delay(300);nosound();
				Beep(950,300);
				//sound(800);delay(200);nosound();
				Beep(800,200);
				//sound(950);delay(500);nosound();
				Beep(950,500);
				
				matriz1[x][y] = 3;
				cdba = cdba - 1;
				cdbhb = cdbhb + 1;
				if((cdba!=0) && (cdbb!=0))
				{
				tirob();
				}
				else
				diceganador();
				}
			else
				{
				textbackground(0);
				textcolor(3);	gotoxy(3,13);	printf("Agua");
				matriz1[x][y] = 2;
				textbackground(0);
				textcolor(7);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(9);
						if (matriz1[x][y] == 3)
							{
							textcolor(4);
							printf("X");
							}
						else
							if (matriz1[x][y] == 2)
								{
								textcolor(0);
								printf("*");
								}
							else
								printf(" ");
						}
					}
				getch();
				comienzo();
				}
			break;
	}
}
while(otb!='v' && otb!='V');
comienzo();
}
//VISUALIZA LA TABLA DEL JUGADOR A
void verta(void)
{
textbackground(0);
textcolor(7);
clrscr();
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(0);
		if (matriz1[x][y] == 1)
			{
			textcolor(1);
			printf("");
			}
		else
			if (matriz1[x][y] == 3)
				{
				textcolor(4);
				printf("X");
				}
			else
				if (matriz1[x][y] == 2)
					{
					textcolor(0);
					printf("*");
					}
				else
					printf(" ");
		}
	}
	coordenadas(22);
	getch();
	comienzo();
}
//VISUALIZA LA TABLA DEL JUGADOR B
void vertb(void)
{
textbackground(0);
textcolor(7);
clrscr();
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(9);
		if (matriz2[x][y] == 1)
			{
			textcolor(1);
			printf("");
			}
		else
			if (matriz2[x][y] == 3)
				{
				textcolor(4);
				printf("X");
				}
			else
				if (matriz2[x][y] == 2)
					{
					textcolor(0);
					printf("*");
					}
				else
					printf(" ");
		}
	}
	coordenadas(22);
	getch();
	comienzo();
}
void sefijaencdb(void)
{

int m;
int er;

OcultarCursor();
textbackground(1);
clrscr();
textbackground(7);
textcolor(1);
gotoxy(13,12);	printf(" ERROR BARCOS DESCONOCIDOS PRODUCEN ERROR DESCONOCIDO ");
textbackground(1);
textcolor(15);
gotoxy(11,14);	printf("Detalles:");
gotoxy(11,15);	printf("DESCONOCIDO HUNDIRA ALEATORIAMENTE LOS BARCOS DESCONOCIDOS");
gotoxy(11,16);	printf("PARA UN JUEGO LIMPIO Y SIN ERRORES");
textcolor(15);
gotoxy(12,18);
printf("PRECIONE Entrar PARA Hundirlos O Esc PARA Volver:Aceptar");
textcolor(15);
gotoxy(61,18);
do
{
if(cdba>cdbb)
		{
          er=getch();
          if(er==13)
                    {
                    gotoxy(15,21); printf("ESTO TARDARA UN TIEMPO");
                    gotoxy(15,22); printf("HAY   BARCOS DE MAS ES EL TABLERO A");
                    do
		          {
                    for(x=1;x<=20;x++)
                         {
					for(y=1;y<=10;y++)
					      {
					      if(cdba!=cdbb)
					           {
					           if(matriz4[x][y]!=1)
					                 {
							       if(matriz1[x][y]==1)
							            {
							            gotoxy(18,22); textcolor(14); printf(" %d ",cdba-cdbb);
							            matriz1[x][y]=0;
							            cdba=cdba - 1;
							            }
							        else
							            {
							            matriz4[x][y]=1;
							            }
							       }
						      }
					      }
				     delay(1000);
				     }
			     }
                    while(cdba!=cdbb);
		          gotoxy(18,22); textcolor(14); printf(" %d ",cdbb-cdba);
		          gotoxy(25,23); printf("LA CANTIDAD DE BARCOS AHORA ES LA MISMA");
		          gotoxy(25,24); printf("  PRESIONE UNA TECLA PARA CONTINUAR");
		          getch();
		          }
          if(er==27)
                    {
                    textcolor(14 );
                    gotoxy(15,21); printf("DESCONOCIDO SE CERRARA");
                    getch();
                    exit(0);
                    }
          }
	     else
if(cdba<cdbb)
		{
		er=getch();
          if(er==13)
                    {
                    gotoxy(15,21); printf("ESTO TARDARA UN TIEMPO");
                    gotoxy(15,22); printf("HAY   BARCOS DE MAS ES EL TABLERO B");
                    do
		          {
                    for(x=1;x<=20;x++)
                         {
				     for(y=1;y<=10;y++)
					      {
					      if(cdba!=cdbb)
					           {
					           if(matriz4[x][y]!=1)
					                 {
							       if(matriz2[x][y]==1)
							            {
							            gotoxy(18,22); textcolor(14); printf(" %d ",cdbb-cdba);
							            matriz2[x][y]=0;
							            cdbb=cdbb - 1;
							            }
							        else
							            {
							            matriz4[x][y]=1;
							            }
							       }
						      }
					      }
				     delay(1000);
				     }
			     }
                    while(cdba!=cdbb);
		          gotoxy(18,22); textcolor(14); printf(" %d ",cdbb-cdba);
		          gotoxy(25,23); printf("LA CANTIDAD DE BARCOS AHORA ES LA MISMA");
		          gotoxy(25,24); printf("  PRESIONE UNA TECLA PARA CONTINUAR");
		          getch();
		          }
          if(er==27)
                    {
                    textcolor(14 );
                    gotoxy(15,21); printf("DESCONOCIDO SE CERRARA");
                    getch();
                    exit(0);
                    }
          }
}
while(cdba!=cdbb);
m=rand() %2;
if(m==0)
	{
	dadosa();
	}
if(m==1)
	{
	dadosb();
	}
}
//ACA COMIENZA LA INTERFACE
//SEGUNDA ANIMACION DEL BARCO HUNDIDO
void barcohun1(void)
{
OcultarCursor();
Beep(240,100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("             лл                       л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                                    ллллл                  ");
     		gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");


Beep(110,100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("              лл                      л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                                    ллллл                  ");
     		gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(220,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("               лл                     л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                                    ллллл                  ");
     		gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(210,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                лл                    л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                                    ллллл                  ");
     		gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(200,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                 лл                   л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                                    ллллл                  ");
     		gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(190,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                  лл                  л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                                    ллллл                  ");
     		gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(180,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                   лл                 л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                                    ллллл                  ");
     		gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(170,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                    лл                л                    ");
		     gotoxy(1,19);	printf("                                     ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
		     gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(160,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                     лл               л                    ");
		     gotoxy(1,19);	printf("                                     ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
	          gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(150,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                      лл              л                    ");
		     gotoxy(1,19);	printf("                                     ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
		     gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(140,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                       лл             л                    ");
		     gotoxy(1,19);	printf("                                     ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
		     gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(130,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                        лл            л                    ");
		     gotoxy(1,19);	printf("                                     ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
		     gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(120,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                         лл           л                    ");
		     gotoxy(1,19);	printf("                                     ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
	          gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(110,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                          лл          л                    ");
		     gotoxy(1,19);	printf("                                     ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
		     gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(100,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                           л          л                     ");
		     gotoxy(1,19);	printf("                            л        ллл                   ");
		     gotoxy(1,20);	printf("                                    ллллл                  ");
		     gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(90,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
		     gotoxy(1,19);	printf("                            л        ллл                   ");
		     gotoxy(1,20);	printf("                             л      ллллл                  ");
		     gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(80,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
     		gotoxy(1,19);	printf("                                     ллл                   ");
     		gotoxy(1,20);	printf("                             л      ллллл                  ");
     		gotoxy(1,21);	printf("                              л   ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(70,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
			gotoxy(1,19);	printf("                                     ллл                   ");
			gotoxy(1,20);	printf("                                    ллллл                  ");
			gotoxy(1,21);	printf("                              л   ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
			gotoxy(1,19);	printf("                                     ллл                   ");
			gotoxy(1,20);	printf("                                    ллллл                  ");
			gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллл ллллллллллллллллллл        ");
			gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
			gotoxy(1,19);	printf("                                     ллл                   ");
			gotoxy(1,20);	printf("                                    ллллл                  ");
			gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
			gotoxy(1,19);	printf("                                     ллл                   ");
			gotoxy(1,20);	printf("                                    ллллл                  ");
			gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	printf("                            лллл лллллллллллллллл          ");
			gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
			gotoxy(1,19);	printf("                                     ллл                   ");
			gotoxy(1,20);	printf("                                    ллллл                  ");
			gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	printf("                            лллл  ллллллллллллллл          ");
			gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
			gotoxy(1,19);	printf("                                     ллл                   ");
			gotoxy(1,20);	printf("                                    ллллл                  ");
			gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	printf("                            лллл  ллллллллллллллл          ");
			gotoxy(1,24);	printf("                              ллл ллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
			gotoxy(1,19);	printf("                                     ллл                   ");
			gotoxy(1,20);	printf("                                    ллллл                  ");
			gotoxy(1,21);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	printf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	printf("                            лллл  ллллллллллллллл          ");
			gotoxy(1,24);	printf("                              ллл  лллллллллллл            ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	printf("                                                           ");
textcolor(15);	gotoxy(1,19);	printf("                                                           ");
textcolor(15);	gotoxy(1,20);	printf("                                      л                    ");
     		gotoxy(1,21);	printf("                                     ллл                   ");
     		gotoxy(1,22);	printf("                                    ллллл                  ");
     		gotoxy(1,23);	printf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,24);	printf("                          ллллл  лллллллллллллллллл        ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,20);	printf("                                                           ");
textcolor(15);	gotoxy(1,21);	printf("                                                           ");
textcolor(15);	gotoxy(1,22);	printf("                                      л                    ");
     		gotoxy(1,23);	printf("                                     ллл                   ");
     		gotoxy(1,24);	printf("                                    ллллл                  ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,22);	printf("                                                           ");
textcolor(15);	gotoxy(1,23);	printf("                                      л                    ");
     		gotoxy(1,24);	printf("                                     ллл                   ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,23);	printf("                                                           ");
textcolor(15);	gotoxy(1,24);	printf("                                      л                    ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

textbackground(0);
Beep(50,1000);
gotoxy(1,20);
textcolor(15);	gotoxy(1,24);	printf("                                                           ");
textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");

}
//ANIMACION DEL LOADING
void loading(void)
{
	OcultarCursor();
	
	textbackground(0);
	
	clrscr();
	
	gotoxy(30,12); textcolor(7); printf("лллллллллллллллллллл");
	
	textcolor(4); gotoxy(31,10); printf("CARGANDO ANIMACION");
	gotoxy(40,12); textcolor(4); textbackground(7); printf("0%");
	gotoxy(30,12); delay(1000); printf("л");
	gotoxy(31,12); delay(1000); printf("л");
	gotoxy(39,12); textbackground(7); printf("10%");
	gotoxy(32,12); delay(1000); printf("л");
	gotoxy(33,12); delay(1000); printf("л");
	gotoxy(39,12); textbackground(7); printf("20%");
	gotoxy(34,12); delay(1000); printf("л");
	gotoxy(35,12); delay(1000); printf("л");
	gotoxy(39,12); textbackground(7); printf("30%");
	gotoxy(36,12); delay(1000); printf("л");
	gotoxy(37,12); delay(1000); printf("л");
	gotoxy(39,12); textbackground(7); printf("40%");
	gotoxy(38,12); delay(1000); printf("л");
	gotoxy(39,12); delay(1000); printf("л");
	gotoxy(39,12); textbackground(4); textcolor(7); printf("5");
	textcolor(4); textbackground(7); printf("0%");
	gotoxy(40,12); textcolor(4); delay(1000); printf("л");
	gotoxy(40,12); textbackground(4); textcolor(7); printf("0");
	gotoxy(41,12); textcolor(4); delay(1000); printf("л");
	gotoxy(39,12); textcolor(7); textbackground(4); printf("60%");
	gotoxy(42,12); textcolor(4); delay(1000); printf("л");
	gotoxy(43,12); textcolor(4); delay(1000); printf("л");
	gotoxy(39,12); textcolor(7); textbackground(4); printf("70%");
	gotoxy(44,12); textcolor(4); delay(1000); printf("л");
	gotoxy(45,12); textcolor(4); delay(1000); printf("л");
	gotoxy(39,12); textcolor(7); textbackground(4); printf("80%");
	gotoxy(46,12); textcolor(4); delay(1000); printf("л");
	gotoxy(47,12); textcolor(4); delay(1000); printf("л");
	gotoxy(39,12); textcolor(7); textbackground(4); printf("90%");
	gotoxy(48,12); textcolor(4); delay(1000); printf("л");
	gotoxy(49,12); textcolor(4); delay(2000); printf("л");
	gotoxy(38,12); textbackground(4); textcolor(7); printf("100%");
	
	delay(2400);
}
void soundbarco(int Freq){
	Beep(Freq,100);
}
//PRIMERA ANIMACION DEL BARCO HUNDIENDOSE
	void barcohun(void)
	{
	OcultarCursor();
	clrscr();
	textbackground(0);
	clrscr();
	textcolor(14 );
	gotoxy(9,1);	printf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(9,2);	printf("К                                                               К");
	gotoxy(9,3);	printf("К                                                               К");
	gotoxy(9,4);	printf("К                                                               К");
	gotoxy(9,5);	printf("К                                                               К");
	gotoxy(9,6);	printf("К                                                               К");
	gotoxy(9,7);	printf("К                                                               К");
	gotoxy(9,8);	printf("К                                                               К");
	gotoxy(9,9);	printf("К                                                               К");
	gotoxy(9,10);	printf("К                                                               К");
	gotoxy(9,11);	printf("К                                                               К");
	gotoxy(9,12);	printf("К                                                               К");
	gotoxy(9,13);	printf("К                                                               К");
	gotoxy(9,14);	printf("К                                                               К");
	gotoxy(9,15);	printf("К                                                               К");
	gotoxy(9,16);	printf("К                                                               К");
	gotoxy(9,17);	printf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	
	textcolor(14 );
	gotoxy(11,2);	printf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(11,3);	printf("К                                                           К");
	gotoxy(11,4);	printf("К                                                           К");
	gotoxy(11,5);	printf("К                                                           К");
	gotoxy(11,6);	printf("К                                                           К");
	gotoxy(11,5);	printf("К                                                           К");
	gotoxy(11,6);	printf("К                                                           К");
	gotoxy(11,7);	printf("К                                                           К");
	gotoxy(11,8);	printf("К                                                           К");
	gotoxy(11,9);	printf("К                                                           К");
	gotoxy(11,10);	printf("К                                                           К");
	gotoxy(11,11);	printf("К                                                           К");
	gotoxy(11,12);	printf("К                                                           К");
	gotoxy(11,13);	printf("К                                                           К");
	gotoxy(11,14);	printf("К                                                           К");
	gotoxy(11,15);	printf("К                                                           К");
	gotoxy(11,16);	printf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	
	textbackground(0);
	textcolor(13);
	delay(100);
	gotoxy(12,3);	printf("                                                           ");delay(100);
	gotoxy(12,4);	printf("  BBBB   AAAAAA  TTTTTTT  AAAAAA  L       L       AAAAAAA  ");delay(100);
	gotoxy(12,5);	printf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
	gotoxy(12,6);	printf("  BBBB   AAAAAA     T     AAAAAA  L       L       AAAAAAA  ");delay(100);
	gotoxy(12,7);	printf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
	gotoxy(12,8);	printf("  BBBB   A    A     T     A    A  LLLLLL  LLLLLL  A     A  ");delay(100);
	gotoxy(12,9);	printf("                                                           ");delay(100);
	gotoxy(12,10); 	printf("         NN   N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
	gotoxy(12,11); 	printf("         NN   N  A    A   V      V  A    A  L              ");delay(100);
	gotoxy(12,12);	printf("         N N  N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
	gotoxy(12,13);	printf("         N  N N  A    A    V    V   A    A  L              ");delay(100);
	gotoxy(12,14);	printf("         N   NN  A    A      VV     A    A  LLLLLL         ");delay(100);
	gotoxy(12,15);	printf("                                                           ");delay(100);
	
	textbackground(1);
	textcolor(15);
	delay(100);
	gotoxy(12,15);	printf("                                                           ");delay(100);
	gotoxy(12,14);	printf("         N   NN  A    A      VV     A    A  LLLLLL         ");delay(100);
	gotoxy(12,13);	printf("         N  N N  A    A    V    V   A    A  L              ");delay(100);
	gotoxy(12,12);	printf("         N N  N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
	gotoxy(12,11); 	printf("         NN   N  A    A   V      V  A    A  L              ");delay(100);
	gotoxy(12,10); 	printf("         NN   N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
	gotoxy(12,9);	printf("                                                           ");delay(100);
	gotoxy(12,8);	printf("  BBBB   A    A     T     A    A  LLLLLL  LLLLLL  A     A  ");delay(100);
	gotoxy(12,7);	printf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
	gotoxy(12,6);	printf("  BBBB   AAAAAA     T     AAAAAA  L       L       AAAAAAA  ");delay(100);
	gotoxy(12,5);	printf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
	gotoxy(12,4);	printf("  BBBB   AAAAAA  TTTTTTT  AAAAAA  L       L       AAAAAAA  ");delay(100);
	gotoxy(12,3);	printf("                                                           ");delay(100);
	
	
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                   л                    ");
			gotoxy(1,19);	printf("                  ллл                   ");
			gotoxy(1,20);	printf("                 ллллл                  ");
			gotoxy(1,21);	printf("               ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("       ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	printf("         ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("           ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                    л                    ");
			gotoxy(1,19);	printf("                   ллл                   ");
			gotoxy(1,20);	printf("                  ллллл                  ");
			gotoxy(1,21);	printf("                ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("        ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	printf("          ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("            ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                     л                    ");
			gotoxy(1,19);	printf("                    ллл                   ");
			gotoxy(1,20);	printf("                   ллллл                  ");
			gotoxy(1,21);	printf("                 ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("         ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	printf("           ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("             ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                      л                    ");
			gotoxy(1,19);	printf("                     ллл                   ");
			gotoxy(1,20);	printf("                    ллллл                  ");
			gotoxy(1,21);	printf("                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	printf("            ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                       л                    ");
			gotoxy(1,19);	printf("                      ллл                   ");
			gotoxy(1,20);	printf("                     ллллл                  ");
			gotoxy(1,21);	printf("                   ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("           ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	printf("             ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("               ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                        л                    ");
			gotoxy(1,19);	printf("                       ллл                   ");
			gotoxy(1,20);	printf("                      ллллл                  ");
			gotoxy(1,21);	printf("                    ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("            ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	printf("              ллллллллллллллллллллл          ");
			gotoxy(1,24);	printf("                ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                         л                    ");
				gotoxy(1,19);	printf("                        ллл                   ");
				gotoxy(1,20);	printf("                       ллллл                  ");
				gotoxy(1,21);	printf("                     ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("             ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("               ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                 ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                          л                    ");
				gotoxy(1,19);	printf("                         ллл                   ");
				gotoxy(1,20);	printf("                        ллллл                  ");
				gotoxy(1,21);	printf("                      ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("              ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                  ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                           л                    ");
				gotoxy(1,19);	printf("                          ллл                   ");
				gotoxy(1,20);	printf("                         ллллл                  ");
				gotoxy(1,21);	printf("                       ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("               ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                 ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                   ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                            л                    ");
				gotoxy(1,19);	printf("                           ллл                   ");
				gotoxy(1,20);	printf("                          ллллл                  ");
				gotoxy(1,21);	printf("                        ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                  ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                    ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                             л                    ");
				gotoxy(1,19);	printf("                            ллл                   ");
				gotoxy(1,20);	printf("                           ллллл                  ");
				gotoxy(1,21);	printf("                         ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                 ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                   ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                     ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                              л                    ");
				gotoxy(1,19);	printf("                             ллл                   ");
				gotoxy(1,20);	printf("                            ллллл                  ");
				gotoxy(1,21);	printf("                          ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                  ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                    ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                      ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                               л                    ");
				gotoxy(1,19);	printf("                              ллл                   ");
				gotoxy(1,20);	printf("                             ллллл                  ");
				gotoxy(1,21);	printf("                           ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                   ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                     ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                       ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                                л                    ");
				gotoxy(1,19);	printf("                               ллл                   ");
				gotoxy(1,20);	printf("                              ллллл                  ");
				gotoxy(1,21);	printf("                            ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                    ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                      ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                        ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                                 л                    ");
				gotoxy(1,19);	printf("                                ллл                   ");
				gotoxy(1,20);	printf("                               ллллл                  ");
				gotoxy(1,21);	printf("                             ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                     ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                       ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                         ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                                  л                    ");
				gotoxy(1,19);	printf("                                 ллл                   ");
				gotoxy(1,20);	printf("                                ллллл                  ");
				gotoxy(1,21);	printf("                              ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                      ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                        ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                          ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                                   л                    ");
				gotoxy(1,19);	printf("                                  ллл                   ");
				gotoxy(1,20);	printf("                                 ллллл                  ");
				gotoxy(1,21);	printf("                               ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                       ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                         ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                           ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                                    л                    ");
				gotoxy(1,19);	printf("                                   ллл                   ");
				gotoxy(1,20);	printf("                                  ллллл                  ");
				gotoxy(1,21);	printf("                                ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                        ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                          ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                            ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                                     л                    ");
				gotoxy(1,19);	printf("                                    ллл                   ");
				gotoxy(1,20);	printf("                                   ллллл                  ");
				gotoxy(1,21);	printf("                                 ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                         ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                           ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                             ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("                                      л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	soundbarco(380);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("л                                     л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(370);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("лл                                    л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	delay(100);
	textbackground(0);
	soundbarco(360);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf(" лл                                   л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(350);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("  лл                                  л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(340);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("   лл                                 л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(330);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("    лл                                л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(320);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("     лл                               л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(310);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("      лл                              л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(300);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("       лл                             л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(290);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("        лл                            л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(280);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("         лл                           л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(270);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("          лл                          л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(260);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("           лл                         л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	
	textbackground(0);
	soundbarco(250);
	gotoxy(1,20);
	textcolor(15);	gotoxy(1,18);	printf("            лл                        л                    ");
				gotoxy(1,19);	printf("                                     ллл                   ");
				gotoxy(1,20);	printf("                                    ллллл                  ");
				gotoxy(1,21);	printf("                                  ллллллллл                ");
	textcolor(6);	gotoxy(1,22);	printf("                          ллллллллллллллллллллллллл        ");
				gotoxy(1,23);	printf("                            ллллллллллллллллллллл          ");
				gotoxy(1,24);	printf("                              ллллллллллллллллл            ");
	textcolor(3);	gotoxy(1,25);	printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
}
//MUSICA DEL JUEGO "POPEYE"
void soundmusica(int Freq){
	Beep(Freq,300);
}
void musica(void)
{
soundmusica(500); 
soundmusica(600); 
soundmusica(600); 
soundmusica(600); 
soundmusica(540); 
soundmusica(500); 
soundmusica(600); 
soundmusica(600); 
soundmusica(700); 
soundmusica(550); 
soundmusica(700); 
soundmusica(850); 
soundmusica(700); 
soundmusica(600); 
soundmusica(600); 
soundmusica(780); 
soundmusica(700); 
soundmusica(800); 
soundmusica(840); 
soundmusica(800); 
soundmusica(700); 
soundmusica(600); 
soundmusica(700); 
soundmusica(600); 
soundmusica(500); 
soundmusica(600); 
soundmusica(600); 
soundmusica(600); 
soundmusica(600); 
soundmusica(700); 
soundmusica(800); 
soundmusica(850); 
}
//MUESTRA LOS NOMBRES DE LOS CREADORES
void creditos(void)
{
OcultarCursor();
clrscr();
barcohun1();
gotoxy(1,10); 	printf("Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("   Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("      Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("         Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("            Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("               Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("                  Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("                     Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("                        Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("                           Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("                              Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("                                 Gandhi Arturo Cabral");
gotoxy(1,10); 	printf("                                    Gandhi Arturo Cabral ");
gotoxy(1,10); 	printf("                                   Gandhi Arturo Cabral ");
gotoxy(1,10); 	printf("                                  Gandhi Arturo Cabral ");
getch();
menu();
}
//MUESTRA EL REGLAMENTO DEL JUEGO
void reglamento(void)
{
OcultarCursor();
clrscr();
textcolor(6);
gotoxy(33,2);
printf("REGLAMENTO");
textcolor(9);
gotoxy(2,4);
printf("Bienbenidos al juego Batalla Naval!!");
gotoxy(1,6);
printf("El juego consiste en hundir todos los barcos del oponente antes que hundan los  ");
printf("nuestros. Cada jugador tendr  una tabla donde colocar sus barcos y otra para    ");
printf("hundir los de su contrincante. Una vez dentro de la tabla deber n ingresar la   ");
printf("misma cantidad de barcos los dos jugadores para que el juego se desarrolle de    ");
printf("forma normal sin que intervenga el juez derribando los barcos que sobran de uno ");
printf("El juego termina cuando uno de los jugadores elimina todos los barcos del otro. ");
printf("En tal caso el juez decidira quien fue el ganador del juego.                    ");
printf("El juez les desea suerte a el o los jugadores y no hagan trampa!!               ");
gotoxy(28,15);
getch();
textcolor(14);
printf("LOS ESTARE VIJILANDO!!");


getch();
}
//PRESENTACION RESUMIDA EN FUNCIONES
void presentacion(void)
{
	loading();
	barcohun();
	barcohun1();
	musica();
	menu();
}
//MUESTRA LA TABLA DE COORDENADAS X , Y
void coordenadas(int v)
{
OcultarCursor();
textbackground(0);
textcolor(14);
gotoxy(v,1);	printf("1");
gotoxy(v,2);	printf("2");
gotoxy(v,3);	printf("3");
gotoxy(v,4);	printf("4");
gotoxy(v,5);	printf("5");
gotoxy(v,6);	printf("6");
gotoxy(v,7);	printf("7");
gotoxy(v,8);	printf("8");
gotoxy(v,9);	printf("9");
gotoxy(v,10);	printf("10");
gotoxy(v-21,11);	printf("12345678911111111112");
gotoxy(1,12);	printf("         01234567890");
}
//ACA COMIENZA EL JUEGO JUGADOR VS PC
//MENU SECUNDARIO DE TIPOS DE JUEGO
void menu2(void)
{
OcultarCursor();
do
{
textbackground(0);
clrscr();
textcolor(14);    gotoxy(4,4);      printf("MENU");
textcolor(2);     gotoxy(11,5);     printf("1 JUGADOR");
		  gotoxy(11,6);     printf("2 JUGADORES ");
textcolor(15);    gotoxy(11,8);     printf("0 VOLVER");
textcolor(14);    gotoxy(4,10);     printf("OPCION:");

op5=getch();
switch(op5)
	   {
	   case '1':	boton();
			tjapc();
			break;
	   case '2':    boton();
			menu3();
			break;
	   }
}
while(op5!='0');
exit(0);
}
//TABLA DEL JUGADOR A VS PC
void tjapc(void)
{

	iniciomatriz1();
	
	clrscr();
	coordenadas(22);
	textcolor(15);
	gotoxy(30,3);
	printf("JUGADOR A:\n");
	textcolor(12);
	textbackground(1);
	gotoxy(30,5);
	printf(" m");textcolor(10);printf("  Colocar barco ");
	gotoxy(30,6); 		    printf("                  ");
	textcolor(12);
	textbackground(1);
	gotoxy(30,7);
	printf(" d");textcolor(10);printf("  Borrar barco  ");
	gotoxy(30,8); 		    printf("                  ");
	textcolor(12);
	textbackground(1);
	gotoxy(30,9);
	printf(" V");textcolor(10);printf("   volver           ");
	
	for(x=1;x<=20;x++)
	{
		for(y=1;y<=10;y++)
			{
			gotoxy(x,y);
			textbackground(9);
			printf(" ");
			}
	}
	
	gotoxy(1,1);
	x=1;
	y=1;
	
	MostraCursor();
	do
	{
	ota = getch();
	switch(ota)
		{
	     case 77: if (x<20)
					{
					x = x + 1;
					gotoxy(x,y);
					}
				else
					if(y!=10)
						{
						y=y+1;
						x=1;
						}
					else
					if((y==10) && (x==20))
						{
						x=x-20;
						y=y;
						}
			break;
	
		case 75: if (x>1)
					{
					x = x - 1;
					gotoxy(x,y);
					}
				else
					if(y!=1)
						{
						y=y-1;
						x=20;
						}
					else
					if((x==1) && (y==1))
						{
						x=x+20;
						y=y;
						}
			break;
	
		case 72: if (y > 1)
					{
					y = y - 1;
					gotoxy(x,y);
					}
				else
					if(y==1)
						{
						y=y+9;
						x=x;
						}
				break;
	
		case 80: if (y < 10)
					{
					y = y + 1;
					gotoxy(x,y);
					}
				else
					if(y==10)
						{
						y=y-9;
						x=x;
						}
			break;
	
		case 'm':
			if ((cdba<10) && (matriz1[x][y]!=1))
			{
			{
			textcolor(1);
			printf("");
			cdba = cdba + 1;
			}
			if (x < 20)
				{
				matriz1[x][y] = 1;
				x = x+1;
				}
	
			else
				{
				gotoxy(x,y);
				matriz1[x][y] = 1;
				}
			}
		else    if(cdba==6)
			{
			x = x + 1;
			}
	
	
			break;
	
		case'D':case 'd':if(matriz1[x][y]!=0)
			{
			if (x<20)
			{
			textcolor(7);
			printf(" ");
			cdba = cdba - 1;
			matriz1[x][y]=0;
			x=x+1;
			}
			else
			if (x==20)
				{
				textcolor(7);
				printf(" ");
				cdba = cdba - 1;
				matriz1[20][y]=0;
				gotoxy(20,y);
				}
	
			}
			else
				x=x;
	
			break;
		}
	}
	while(ota!='v' && ota!='V');
	tjpc(); //iniciallizo la matriz de la pc
	tiroapc();
}
//TIRO DEL PC
void tiroapc(void)
{
textbackground(0);
clrscr();
vertapc();
textbackground(0);
				textcolor(7);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(9);
						if (matriz3[x][y] == 3)
							{
							textcolor(4);
							printf("X");
							}
						else
							if (matriz3[x][y] == 2)
								{
								textcolor(0);
								printf("*");
								}
							else
								printf(" ");
						}
					}
coordenadas(22);
textcolor(15);
gotoxy(4,14); printf("Tabla del PC");
textcolor(15);
gotoxy(24,3);
printf("JUGADOR A:\n");
textcolor(12);
textbackground(1);
gotoxy(24,5);
printf("t");textcolor(10);printf("  Tirar bomba");
textcolor(12);
textbackground(1);
gotoxy(24,9);
printf("S");textcolor(10);printf("alir del juego");
gotoxy(1,1);
x=1;
y=1;
MostraCursor();
do
{
ota = getch();
switch(ota)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

	case 'T':case 't':  if (matriz3[x][y] == 1)
				{
				textcolor(15);	gotoxy(3,13);  printf("Hundido!!!");
				barcohun1();
		//	sound(580);delay(300);nosound();
			Beep(580,300);
		//	sound(700);delay(300);nosound();
			Beep(700,300);
		//	sound(800);delay(200);nosound();
			Beep(800,200);
		//	sound(950);delay(300);nosound();
			Beep(950,300);
		//	sound(800);delay(200);nosound();
			Beep(800,300);
		//	sound(950);delay(500);nosound();
			Beep(950,500);
				matriz3[x][y] = 3;
				cdbpc = cdbpc - 1;
				cdbha = cdbha + 1;
				diceganavspc();
				tiroapc();
				}
			else
				{
				textcolor(3);	gotoxy(3,13);	printf("Agua");
				matriz3[x][y] = 2;
				textbackground(0);
				textcolor(7);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(9);
						if (matriz3[x][y] == 3)
							{
							textcolor(4);
							printf("X");
							}
						else
							if (matriz3[x][y] == 2)
								{
								textcolor(0);
								printf("*");
								}
							else
								printf(" ");
						}
					}
				getch();
				tiropc();
				}
			break;
	}
}
while(ota!='s' && ota!='S');
boton();
textbackground(0);
textcolor(10);
gotoxy(3,15);printf("DECEA SALIR DEL JUEGO? s/n");
op6=getch();
switch(op6)
	{
	case'S':case 's':	boton();
					menu();
					break;

	case 'n': 	     boton();
					tiroapc();
					break;
	}
}
//VISUALIZA LA TABLA DEL JUGADOR A VS PC
void vertapc(void)
{
textbackground(0);
textcolor(7);
clrscr();
for(x=40;x<60;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(9);
		if (matriz1[x-39][y] == 1)
			{
			textcolor(1 );
			printf("");
			}
		else
			if (matriz1[x-39][y] == 3)
				{
				textcolor(4);
				printf("X");
				}
			else
				if (matriz1[x-39][y] == 2)
					{
					textcolor(0);
					printf("*");
					}
				else
					printf(" ");
		}
	}
	coordenadas(61);
	textcolor(15);
	gotoxy(42,14); printf("Tabla del Jugador");
	}
//TABLA DEL PC
void tjpc(void)
{

iniciomatriz3(); //Inicializo tablero jugador 3

for (x=3;x<=17;x++)
	{
	for (y=2;y<=9;y++)
		{
		gotoxy(x,y);
		textbackground(3);
		if(cdbpc<=cdba)
			{
			gotoxy(x,y);
			matriz3[x][y]=rand() % 2;
			if(matriz3[x][y]==1)
				{
				textcolor(1);
				printf("");
				cdbpc=cdbpc+1;
				}
			else
				{
				textcolor(0);
				printf(" ");
				matriz3[x][y]=0;
				}
			}
		else
			{
			textcolor(0);
			printf(" ");
			matriz3[x][y]=0;
			}
		}
	}
coordenadas(22);
}
//TIRO DEL PC VS JUGADOR A
void tiropc(void)
{
textbackground(0);
textcolor(7);
clrscr();
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(9);
		if (matriz1[x][y] == 3)
			{
			textcolor(4);
			printf("X");
			}
		else
			if (matriz1[x][y] == 2)
				{
				textcolor(0);
				printf("*");
				}
			else
				printf(" ");
		}
	}
coordenadas(22);
textbackground(0);
textcolor(6);	gotoxy(30,12);	printf("PC\n\n");


x=rand() % 21;
y=rand() % 11;


if (matriz4[x][y] == 0)// 0 NUNCA TIRO    1 YA TIRO
	{
	if (matriz1[x][y] == 1)
		{
		textcolor(5);	gotoxy(3,13);	printf("Hundido!!!");

		matriz1[x][y] = 3;
		matriz4[x][y] = 1;

		cdba = cdba - 1;
		cdbhpc=cdbhpc + 1;


		Beep(580,300);
		//	sound(700);delay(300);nosound();
			Beep(700,300);
		//	sound(800);delay(200);nosound();
			Beep(800,200);
		//	sound(950);delay(300);nosound();
			Beep(950,300);
		//	sound(800);delay(200);nosound();
			Beep(800,300);
			Beep(950,500);
		getch();
		diceganavspc();
		tiropc();
		}

	else
		{

		matriz1[x][y] = 2;
		matriz4[x][y] = 1;
		tiroapc();
		}
	}
else
tiropc();
}
//VISUALIZA LA TABLA DEL PC VS JUGADOR A
void vertpc(void)
{

textbackground(0);
textcolor(7);
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(9);
			if (matriz3[x][y] == 3)
				{
				textcolor(4);
				printf("X");
				}
			else
				if (matriz3[x][y] == 2)
					{
					textcolor(0);
					printf("*");
					}
				else
				printf(" ");
		}
	}
}
//DICE EL GANADOR DEL JUEGO H VS PC
void diceganavspc(void)
{
clrscr();
textbackground(0);
if (cdbpc==0)
	{

	textbackground(1);
	textcolor(15 );
printf("                                                    ");
printf("                                                    ");
printf("     Ha ganado el jugador A!!                       ");
printf("                                                    ");
printf("                                ");

textcolor(15);
gotoxy(19,7);   	printf("ЩЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(19,8);		printf("К  К   К               К");
gotoxy(19,9);   	printf("ЬЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
gotoxy(19,10);		printf("К  К   К               К");
gotoxy(19,11);   	printf("ШЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textbackground(0);
textcolor(15);
gotoxy(20,8);	printf("A К  %dКbarcos hundidos", cdbha);
gotoxy(20,10);	printf("pcК  %dКbarcos hundidos", cdbhpc);
getch();
menu();
	}
if (cdba==0)
	{

	textbackground(1);
	textcolor(15 );
printf("                                                    ");
printf("                                                    ");
printf("     Ha ganado el computador!!                       ");
printf("                                                    ");
printf("                                ");


textcolor(15);
gotoxy(19,9);   	printf("ЩЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(19,10);		printf("К  К   К               К");
gotoxy(19,11);   	printf("ЬЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
gotoxy(19,12);		printf("К  К   К               К");
gotoxy(19,13);   	printf("ШЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textbackground(0);
textcolor(15);
gotoxy(20,10);	printf("A К  %dКbarcos hundidos", cdbha);
gotoxy(20,12);	printf("pcК  %dКbarcos hundidos", cdbhpc);

getch();
menu();
}
}
//ACA COMIENZA LA PARTE DEL AZAR DE LOS JUGADORES
void conja1(void) /* Simula una clave de acceso */
{
   OcultarCursor();
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&cona1);
   menu3();
}
void conja2(void) /* Simula una clave de acceso */
{
   OcultarCursor();
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&cona2);
   if(cona1==cona2)
	{
	 verta();
	 }
   else
	 {
	 printf("Acceso denegado\n");
	 getch();
	 comienzo();
	 }
}
void conjb1(void) /* Simula una clave de acceso */
{
   OcultarCursor();
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&conb1);
   menu3();
}
void conjb2(void) /* Simula una clave de acceso */
{
   OcultarCursor();
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&conb2);
   if(conb1==conb2)
	{
	 vertb();
	 }
   else
	 {
	 printf("Acceso denegado\n");
	 getch();
	 comienzo();
	  }
}
void conja3(void) /* Simula una clave de acceso */
{
   OcultarCursor();
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Si es la primera vez que entras digita 0\n\n");
   printf("Introduce tu clave: ");
   scanf("%d",&cona2);
   if(cona1==cona2)
	{
	tja();
	}
   else
	 {
	 printf("Acceso denegado. Digite su nueva contraseЄa!!\n");
	 getch();
	 menu3();
	 }
}
void conjb3(void) /* Simula una clave de acceso */
{
   OcultarCursor();
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Si es la primera vez que entras digita 0\n\n");
   printf("Introduce tu clave: ");
   scanf("%d",&conb2);
   if(conb1==conb2)
	{
	tjb();
	}
   else
	 {
	 printf("Acceso denegado. Digite su nueva contraseЄa!!");
      getch();
	 menu3();
	 }
}
void randomize(){
	srand(1);
}
//TIRA LOS DADOS EL JUGADOR A
void dadosa(void)
{
int n1,n2;

clrscr();
randomize();
n1=rand() % 6;
printf("\tJuagador A:\n");
printf("Del 1 al 5,que nЃmero crees que pienso?? ");
scanf("%d",&n2);
if(n1==n2)
	{
	printf("\n\n%d\n\n",n1);
	printf("\n\nGanaste, empiezas tirando");
	delay(1500);
	tiroa();
	}
else
	{
	printf("\n\nPerdiste, el numero en el que pensaba era %d",n1);
	getch();
	dadosb();
	}
}
//TIRA LOS DADOS EL JUGADOR B
void dadosb(void)
{
int n1,n2;

clrscr();
randomize();
n1=rand() % 6;
printf("\tJuagador B:\n");
printf("Del 1 al 5,que nЃmero crees que pienso?? ");
scanf("%d",&n2);
if(n1==n2)
	{
	printf("\n\n%d\n\n",n1);
	printf("\n\nGanaste, empiezas tirando");
	delay(1500);
	tirob();
	}
else
	{
	printf("\n\nPerdiste, el numero en el que pensaba era %d",n1);
	getch();
	dadosa();
	}
}


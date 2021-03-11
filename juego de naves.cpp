#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <list>
using namespace std;


void gotoxy(int ,int);
void OcultarCursor();
void PintarLimites();

class NAVE{
	int x,y;
	int corazones;
	int vidas;
public:
	NAVE(int _x, int _y,int _corazones,int _vidas):x(_x),y(_y),corazones(_corazones),vidas(_vidas){}
	int VID(){return vidas;}
	int X(){return x;}
	int Y(){return y;}
	void pintar();
	void borrar();
	void mover();
	void PintarCorazones();
	void morir();
	void COR(){corazones--;}
};
class AST{
	int x, y;
public:
	AST(int _x,int _y):x(_x),y(_y){}
	int X(){return x;}
	int Y(){return y;}
	void pintar();
	void mover();
	void choque(NAVE &N);
};
class BALA{
	int x,y;
public:
	int X(){return x;}
	int Y(){return y;}

	BALA(int _x,int _y):x(_x),y(_y){}
	void mover();
	bool fuera();
};

int main (){

	OcultarCursor();
	PintarLimites();

	NAVE N(37,30,1,1);
	N.pintar();
	N.PintarCorazones();

	list<AST*>A;
	list<AST*>::iterator itA;

	for(int i=0;i<3;i++){
		A.push_back(new AST(rand()%75+3 , rand()%5+4));
	}
    gotoxy(0,0);
    system("pause");

	list <BALA*> B;
	list <BALA*>:: iterator it;
	bool game_over=false;
	int puntos =0;
	while(!game_over){

		gotoxy(4,2);printf("Puntos %d",puntos);
		if(kbhit()){
			char tecla = getch();
			if(tecla == 'q'){
				B.push_back(new BALA(N.X()+2 , N.Y()-1));
			}

		}
		for(it=B.begin(); it != B.end();it++){
			(*it)-> mover();
			if((*it)->fuera()){
				gotoxy((*it)->X(),(*it)->Y()); printf(" ");
				delete(*it);
				it =B.erase(it);
			}
		}

		for(itA=A.begin();itA!=A.end();itA++){
			(*itA)->mover();
			(*itA)->choque(N);
		}

		for(itA=A.begin();itA!=A.end();itA++){
			for(it=B.begin();it!=B.end();it++){
				if((*itA)->X()==(*it)->X() && ((*itA)->Y()==(*it)->Y()||(*itA)->Y()+1==(*it)->Y())){
					gotoxy((*it)->X(),(*it)->Y()); printf(" ");
					delete(*it);
					it=B.erase(it);

					A.push_back(new AST(rand()%74+3, 4));
					gotoxy((*itA)->X(),(*itA)->Y());
					delete(*itA);
					itA=A.erase(itA);
					puntos+=5;
				}

			}

		}
		if(N.VID()==0) game_over=true;
		N.morir();
		N.mover();
		Sleep(30);
	}

	gotoxy(0,80);
	getch();

	return 0;

}
void BALA::mover(){
	gotoxy(x,y); printf(" ");
	y--;
	gotoxy(x,y); printf("*");

}
bool BALA::fuera(){
	if(y==4)return true;
	return false;
}


void AST::pintar(){
	gotoxy(x,y);printf("%c",184);

}
void AST::mover(){
	gotoxy(x,y);printf(" ");
	y++;
	if(y>32){
		x=4+rand()%71;
		y=4;
	}
	pintar();
}
void AST::choque(NAVE &N){
	if(x>=N.X()&& x<(N.X()+6)&&y>=N.Y()&&y<=(N.Y()+2)){
		N.COR();
		N.borrar();
		N.pintar();
		N.PintarCorazones();
		x=4+rand()%71;
		y=4;
	}
}

void NAVE::pintar(){
	gotoxy(x,y);   printf("  %c",30);
	gotoxy(x,y+1); printf(" %c%c%c",40,207,41);
	gotoxy(x,y+2); printf("%c%c %c%c",30,190,190,30);
}
void NAVE::borrar(){
	gotoxy(x,y);   printf("        ");
	gotoxy(x,y+1); printf("        ");
	gotoxy(x,y+2); printf("        ");
}
void NAVE::mover(){
	if(kbhit()){
		char tecla=getch();
		borrar();
		if((tecla=='a'|| tecla=='A')&&x>3) x--;
		if((tecla=='d'|| tecla=='D')&&x+6<77) x++;
		if((tecla=='w'|| tecla=='W')&&y>4) y--;
		if((tecla=='s'|| tecla=='S')&&y+3<33) y++;
		if(tecla=='i')corazones--;

		pintar();
		PintarCorazones();
	}
}



void PintarLimites(){
	for(int i = 2;i<78;i++){
		gotoxy(i,3);printf("%c",205);
		gotoxy(i,33);printf("%c",205);
	}
	for(int i = 4;i<33;i++){
		gotoxy(2,i);printf("%c",186);
		gotoxy(77,i); printf("%c",186);
	}
	gotoxy(2,3);   printf("%c",201);
	gotoxy(2,33);  printf("%c",200);
	gotoxy(77,3);  printf("%c",187);
	gotoxy(77,33); printf("%c",188);

}
void NAVE::PintarCorazones(){
	gotoxy(50,2); printf("VIDAS %d",vidas);
	gotoxy(64,2); printf("Salud");
	gotoxy(70,2); printf("     ");
	for(int i=0;i<corazones;i++){
		gotoxy(70+i,2);
			printf("%c",3);
	}
}
void NAVE::morir(){
	if(corazones==0){
		borrar();
		gotoxy(x,y);   printf("   **   ");
		gotoxy(x,y+1); printf("  ****  ");
		gotoxy(x,y+2); printf("   **   ");
		Sleep(200);
		borrar();
		gotoxy(x,y);   printf(" *  ** *");
		gotoxy(x,y+1); printf("   ****  ");
		gotoxy(x,y+2); printf(" *  ** *");
		Sleep(200);
		borrar();
		vidas--;
		corazones=3;
		PintarCorazones();
		pintar();
	}
}

void gotoxy(int x,int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hCon,dwPos);
}
void OcultarCursor(){
	HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=50;
    cci.bVisible=FALSE;



    SetConsoleCursorInfo(hCon,&cci);
}

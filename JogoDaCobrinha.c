#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define LINHA 20
#define COLUNA 20

int horizontal = 10, vertical = 10;// as codernadas da onde a cobrinha vai ficar
int score = 220, apagarx = 0, apagary = 0, tem_frutinha = 0, x, y, limpar = 0, limpax, limpay, encerrar = 0;
char direcao = 'd';

int contagem = 220;

int mapaDestino[LINHA][COLUNA];
int mapa[LINHA][COLUNA] = {
    {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219},
    {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219}
};

void Desenho_Mapa();
void set_cursor_position(int x, int y);
void frutinha();
void andar();
void atualizar();
void comer();
void colisao();
void copiarMatriz(int origem[LINHA][COLUNA], int destino[LINHA][COLUNA]);

int main(){
    mapa[vertical][horizontal] = 220;
    do{
        frutinha();
        Desenho_Mapa();
        andar();
        colisao();
        comer();
        atualizar();
        Sleep(500);
        set_cursor_position(0, 0);
    }while(encerrar != 1);
    system("cls");
}


void Desenho_Mapa(){
    int i, j;
    copiarMatriz(mapa, mapaDestino);
    for (i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            if(mapaDestino[i][j] == 0){
                mapaDestino[i][j] = ' ';
            }
            if(mapaDestino[i][j] != ' ' && mapaDestino[i][j] != 219 && mapaDestino[i][j] != 120){
                mapaDestino[i][j] = 4;
            }
            printf("%c", mapaDestino[i][j]);
        }
    printf("\n");
    }
}

void set_cursor_position(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void andar() {
    if (kbhit())
    {
        direcao = getch();       
    }
    switch (direcao) {
        case 'd':
            horizontal++;
            break;
        case 'a':
            horizontal--;
            break;
        case 'w':
            vertical--;
            break;
        case 's':
            vertical++;
            break;
        case 'x':
            system("cls");
            printf("Jogo encerrado ao precionar x");
            break;   
    }
}

void cobrinha() {
    
}

void atualizar() {
    int i, j;
    mapa[vertical][horizontal] = contagem;
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            if(i != vertical || j != horizontal){
                if(mapa[i][j] == contagem){
                    mapa[i][j] = ' ';
                }
            }
        }
    }
    if(contagem == score){
        contagem = 220;
    } else{
        contagem++;
    }
}


void frutinha() {
    srand(time(NULL));
    if (tem_frutinha == 0) {
        x = 1 + rand() % 18;
        y = 1 + rand() % 18;
        mapa[y][x] = 120;
        tem_frutinha = 1;
    }
}

void comer()
{
    if(horizontal == x && vertical == y) // cobrinha comeu fruta
    {
        score++;
        tem_frutinha = 0; // não tem frutinha
    }else{
        tem_frutinha = 1;
    }
}

void colisao(){
    if(mapa[vertical][horizontal] == 219){
        encerrar = 1;
    }
}

void copiarMatriz(int origem[LINHA][COLUNA], int destino[LINHA][COLUNA]) {
    int i, j;
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}

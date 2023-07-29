#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>

#define LINHA  20 
#define COLUNA 20

int horizontal = 10,vertical = 10;// as codernadas da onde a cobrinha vai ficar
int score = 1,apagarx = 0,apagary = 0,tem_frutinha = 0,x,y,limpar = 0,limpax,limpay;
char direcao = 'd';

void cursor(int x,int y);//colocar cursor no lugar
void cobrinha();//printar cobra
void background();//printar paredes 
void andar();//fazer cobrinha andar
void atualizar();//atualizar posição da cobrinha
void frutinha();//gerar e printar fruta aleatoria
int comer();//cobrinha comer a frutinha
void colisao(); //verifica se a cobra colide com a parede
//fazer cobrinha crescer
//ver se a cobrinha morreu e printar
//calcular score e printar score
//colocar tempo

int main()
{
    do
    {
        atualizar();
        cobrinha();// esse tem que vim primeiro do que o background
        //background();
        frutinha();// tem q ficar aqui se n n vai
        background();//tem que está a cima do andar
        andar();
        colisao();
        comer();
        
        Sleep(1000);

    } while (direcao != 'x');

    return 0;
}
void background()
{
    int i;
    for (i = 0; i < COLUNA; i++)//linha superior
    {
        cursor(i,0);
        printf("\xDB");
    }
    for (i = 0; i < LINHA; i++)//linha do lado esquerdo
    {
        cursor(0,i);
        printf("\xDB");
    }
    for (i = 0; i < LINHA; i++)//linha do lado direito
    {
        cursor(COLUNA,i);
        printf("\xDB");
    }
    for (i = 0; i <= COLUNA; i++)// linha de baixo //tive que colocar esse = pra poder ficar bonitinho não sei como não fazer sem essa gambiarra
    {
        cursor(i,LINHA);
        printf("\xDB");
    }
}
void cursor(int x,int y)//usando codernadas x e y para colocar o cursor
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});    
}
void cobrinha()
{
    int i;
    for ( i = 0; i < score; i++)
    {
        cursor(horizontal,vertical);
        printf("%c",220);
    }  
}
void andar()
{
    if (kbhit())
    {
        direcao = getch();       
    }
    
    switch (direcao)        
        {
        case 'd':
            horizontal++;
            apagarx = 1 * score;
            apagary = 0;
            break;
        case 'a':
            horizontal--;
            apagarx = -1 * score;
            apagary = 0;
            break;
        case 'w':
            vertical--;
            apagary = -1 * score;
            apagarx = 0;
            break;
        case 's':
            vertical++;
            apagary = 1 * score;
            apagarx = 0;
            break;
        case 'x':
            system("cls");
            printf("Jogo encerrado ao precionar x");
            break;    
        }
}
void atualizar()
{
        int i;
        for ( i = 0; i < score; i++)
        {
            cursor(horizontal - apagarx,vertical - apagary);
            printf(" ");
        }
    
}   
void frutinha()
{
    if (tem_frutinha == 0)
    {
        srand(time(NULL));
        do
        {
            x = rand() % COLUNA - 1;
            y = rand() % LINHA - 1;
        } while (x == 0 || y == 0 ||x == horizontal || y == vertical );

        cursor(x,y);
        printf("0");

        tem_frutinha = 1;
    }
    
}
void colisao()
{
    if (horizontal <= 0 || horizontal >= COLUNA || vertical <= 0 || vertical >= LINHA)
    {
        direcao = 'x';
        system("cls");
        printf("\n\n\tVOCE PERDEU\n"); // Encerrar o jogo se a cobrinha colidir com as paredes
    }
}

int comer()
{
    if(horizontal == x && vertical == y) // cobrinha comeu fruta
    {
        score++;
        return tem_frutinha = 0;// não tem frutinha
    }
    else
    {
        return tem_frutinha = 1;
    }
}



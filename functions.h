#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "animacoes.h"
int limpa_tela(int tempo){ // Aguarda o tempo informado, limpa o console, e aguarda novamente
    Sleep(tempo);
    system("cls");
    Sleep(tempo);
    return 0;
}

int mostra_menu(){ // Arranjo de prints para mostrar o MENU
    printf("\n------- SAVE T-REX -------- \n");
    printf("============================= \n");
    printf("\n---------- MENU ----------- \n");
    printf("----------------------------- \n");
    printf("----- ESCOLHA UMA OPÇÃO ----- \n");
    printf("============================= \n");
    printf("1 - JOGAR \n");
    printf("2 - JOGADOR \n");
    printf("3 - RANKING \n");
    printf("4 - CREDITOS \n");
    printf("5 - SAIR \n");
    printf("=============================");
    return 0;
}

int jogar()
{
    animacao_dino();
    return 0;
}

int jogador() // Pede o nick do jogador
{
    char nome[20];
    fflush(stdin); // apaga o ENTER quando a funcao "gets" for captar uma string
    printf ("\nDigite seu nick: ");
    gets(nome); // Guarda o texto inserido pelo usuario, incluindo espaços em branco.
    printf("\n======= JOGADOR CADASTRADO: %s ======= \n", nome);
    return 0;
}

int ranking() // "Registra" o nick e a pontuacao do jogador.
{
    char nome[20];
    int pontuacao;

    printf("\nRANKING\n------------- \n");

    fflush(stdin); //apaga o ENTER quando a funcao "gets" for captar uma string
    printf("Digite seu nick: ");
    gets(nome); // Guarda o texto inserido pelo usuario, incluindo espaços em branco.
    printf("Digite sua pontuação: ");
    scanf("%d", &pontuacao);

    Sleep(1000);
    printf("\n============================");
    printf(" \n   JOGADOR: %s \n",nome);
    printf("   PONTUAÇÃO: %d \n", pontuacao);
    printf("============================");

    return 0;
}

int creditos()
{
    animacao_creditos();
    limpa_tela(500);
    return 0;
}

int menu(int *op){
    Sleep(500);
    //animacao_inicial();
    mostra_menu();
    printf("\n - Digite sua opção: ");
    scanf("%d", &*op);
    limpa_tela(500);
    return;
}


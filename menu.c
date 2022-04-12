#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#include "functions.h"

int limpa_tela(int tempo){ // Aguarda o tempo informado, limpa o console, e aguarda novamente
    Sleep(tempo);
    system("cls");
    Sleep(tempo);
    return 0;
}

int mostra_menu(){ // Arranjo de prints para mostrar o MENU
    printf("\n------- SAVE T-REX -------- \n");
    printf("============================= \n");
    printf("----------- MENU ------------ \n");
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
    char nome[100];
    fflush(stdin); // apaga o ENTER quando a funcao "gets" for captar uma string
    printf ("\nDigite seu nick: ");
    gets(nome); // Guarda o texto inserido pelo usuario, incluindo espaços em branco.
    printf("\n======= JOGADOR CADASTRADO: %s ======= \n", nome);
    return 0;
}

int ranking(){// "Registra" o nick e a pontuacao do jogador.

    struct sistema_pontuacao {
        char nome [50];
        int pontuacao;
    };
    struct sistema_pontuacao jogador[10];

    for(int i=0;i<10;i++){
        printf("==============================\n");
        printf (" ---- JOGADOR %d ----\n",i+1);
        printf (" - Digite seu nick >> ");
        fflush (stdin);
        fgets (jogador[i].nome,50,stdin);
        printf (" - Digite sua pontuação >> ");
        scanf ("%d", &jogador[i].pontuacao);
        printf("==============================\n");
        printf ("\tJOGADOR: %s \tPONTUAÇÃO: %d \n",jogador[i].nome, jogador[i].pontuacao);
        printf("==============================\n");
        limpa_tela(1000);
    }

    printf("========== RANKING ========== \n");
    for(int i=0; i<=9; i++){
        printf(" -------- JOGADOR %d -------- \n", i+1);
        printf(" - Jogador: %s ", jogador[i].nome);
        printf(" - Pontuação: %d", jogador[i].pontuacao);
        printf("\n\n");
    }
    system("pause");
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
    mostra_menu();
    printf("\n - Digite sua opção: ");
    scanf("%d", &*op);
    limpa_tela(500);
    return 0;
}


#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define TAM 3
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
    FILE *p_ranking;
    int contador;
    // FUNCOES

    /* ===================== FUNCOES PRATICAS=======================*/
    int limpa_tela(int tempo);
    int mostra_menu();
    int creditos();
    int menu();

    /* ===================== FUN�OES DE RANKING ====================*/
    int le_ranking();
    int organiza_ranking();
    int mostra_ranking(char modo);

    /* ===================== FUNCOES DO MENU =======================*/
    int cadastra_jogador();
    int jogar();
    int salvar();
    /* ===================== ANIMA��ES =============================*/
    int animacao_creditos();
    int animacao_dino();
    int animacao_inicial();
    int animacao_piscando();
    //==============================================================

    typedef struct {
        char nick [50];
        int pontuacao;
    }sistema_pontuacao;
    sistema_pontuacao ranking[TAM];
    sistema_pontuacao aux[2];

#endif // FUNCTIONS_H_INCLUDED

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define TAM 10
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>

    // FUNCOES
    int menu();
    int jogar();
    int ranking();
    int creditos();
    int limpa_tela(int tempo);
    int mostra_menu();
    // ==================
    int animacao_creditos();
    int animacao_dino();
    int animacao_inicial();
    int animacao_piscando();
    //===================

    typedef struct {
        char nome [50];
        int pontuacao;
    }sistema_pontuacao;
    sistema_pontuacao jogador[TAM];
    sistema_pontuacao aux[1];



#endif // FUNCTIONS_H_INCLUDED

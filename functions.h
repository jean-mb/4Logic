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
    void animacao_creditos(void);
    void animacao_dino(void);
    void animacao_inicial(void);
    void animacao_piscando(void);
    void animacao_tchau(void);
    //===================

    typedef struct {
        char nome [50];
        int pontuacao;
    }sistema_pontuacao;
    sistema_pontuacao jogador[TAM];
    sistema_pontuacao aux[1];



#endif // FUNCTIONS_H_INCLUDED

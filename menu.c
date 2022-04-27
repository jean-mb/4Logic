#include "functions.h"

int limpa_tela(int tempo)  // Aguarda o tempo informado, limpa o console, e aguarda novamente
{
    Sleep(tempo);
    system("cls");
    Sleep(tempo);
    return 0;
}

int mostra_menu()  // Arranjo de prints para mostrar o MENU
{
    printf("\n------- SAVE T-REX -------- \n");
    printf("============================= \n");
    printf("----------- MENU ------------ \n");
    printf("----------------------------- \n");
    printf("----- ESCOLHA UMA OPÇÃO ----- \n");
    printf("============================= \n");
    printf("\t1 - JOGAR \n");
    printf("\t2 - RANKING \n");
    printf("\t3 - CREDITOS \n");
    printf("\t4 - SAIR \n");
    printf("=============================");
    return 0;
}

int jogar(int *p_contador) // Ponteiro para o contador do menu principal
{
    int existe,index; // Variaveis auxiliares para testar se uma string existe
    struct aux
    {
        char nome[50];
    };
    struct aux testa_string; // struct auxiliar pra guardar nick do usuario para depois comparar com outra struct
    animacao_dino();
    //------
    printf("============== JOGADOR %d ==============\n", *p_contador+1);
    printf(" ---- CADASTRE SEU USUÁRIO ----\n");
    printf(" - Digite seu nick >> ");
    fflush(stdin);
    gets(testa_string.nome); // guarda na struct auxiliar
    for(int i=0; i<TAM; i++)
    {
        if(strcmp(jogador[i].nome, testa_string.nome) == 0) // testa em todas as posicoes da struct de ranking se existe a string inserida
        {
            existe = 1; //
            index = i;  // localizacao
        }
    }
    if(existe==1){ // se existe, sobrescreve a pontuacao
        printf("%d",index);
        printf(" - Esse nick já existe! \n");
        printf(" - Digite sua pontuação >> ");
        scanf("%d", &jogador[index].pontuacao);
    }else{
        //se nao existe, cadastra nick e pontuacao
        strcpy(jogador[*p_contador].nome, testa_string.nome);
        printf(" - Digite sua pontuação >> ");
        scanf("%d", &jogador[*p_contador].pontuacao);
        printf("============================================\n");
        printf("\tJOGADOR: %s \tPONTUAÇÃO: %d \n",jogador[*p_contador].nome, jogador[*p_contador].pontuacao);
        printf("============================================\n");
    }
    return 0;
}

int ranking() // "Registra" o nick e a pontuacao do jogador.
{
    printf("================ RANKING ================ \n");

    for (int contador=0; contador<TAM; contador++)
    {
        for (int i=0; i<TAM-1; i++)
        {
            if (jogador[i].pontuacao<jogador[i+1].pontuacao) // bubble sort em ordem decrescente
            {
                // aux
                strcpy(aux[0].nome,jogador[i].nome); // auxiliar recebe nome de jogador "i"
                aux[0].pontuacao = jogador[i].pontuacao; // auxiliar recebe pontuacao de jogador"i"
                // troca
                strcpy(jogador[i].nome,jogador[i+1].nome); // jogador "i" recebe nome de jogador "i+1"
                jogador[i].pontuacao= jogador[i+1].pontuacao; // jogador "i" recebe pontuacao de jogador "i+1"
                // troca com aux
                strcpy(jogador[i+1].nome,aux[0].nome); // jogador "i+1" recebe nome de auxiliar
                jogador[i+1].pontuacao = aux[0].pontuacao; // jogador "i+1" recebe pontuacao de auxiliar
            }
        }
    }
    for (int i=0; i<4; i++)
    {
        if(jogador[i].pontuacao!=0) // se a pontuacao eh zero, nao eh exibida no ranking
        {
            printf ("%d° - %s - ",i+1,jogador[i].nome);
            printf ("%4d\n",jogador[i].pontuacao);
        }
        else
        {
            break;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}

int creditos()
{
    animacao_creditos();
    limpa_tela(500);
    return 0;
}

int menu(int *op)
{
    Sleep(500);
    mostra_menu();
    printf("\n - Digite sua opção: ");
    scanf("%d", &*op);
    limpa_tela(500);
    return 0;
}


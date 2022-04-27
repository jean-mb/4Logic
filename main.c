#include "functions.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao, contador = 0; //contador pra saber qual posicao guardar cadastro do jogador
    animacao_inicial();
    do{
        menu(&opcao);
        switch(opcao)
        {
            case 1:
                jogar(&contador);
                contador++; // aumenta contador a cada loop em que a opcao "jogar" for escolhida
                break;

            case 2:
                ranking();
                break;

            case 3:
                creditos();
                break;

            case 4:
                animacao_tchau();
                break;

            default:
                printf ("\n======== Não há essa opção! ======== \n");
                break;
        }
        limpa_tela(1000);
    }while(opcao != 4 );
    return 0;
}

#include "functions.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    animacao_inicial();
    do{
        menu(&opcao);
        switch(opcao)
        {
            case 1:
                jogar();
                break;

            case 2:
                jogador();
                break;

            case 3:
                ranking();
                break;

            case 4:
                creditos();
                break;

            case 5:
                printf ("\nSaindo... \n");
                break;

            default:
                printf ("\n======== Não há essa opção! ======== \n");
                break;
        }
        limpa_tela(1000);
    }while(opcao != 5 );
    return 0;
}

#include "functions.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    contador=0;
    le_ranking();
    int opcao; //contador pra saber qual posicao guardar cadastro do jogador
    do{
        mostra_menu();
        opcao = menu();
        switch(opcao)
        {
            case 1:
                organiza_ranking();
                jogar();
                animacao_dino();
                break;

            case 2:
                organiza_ranking();
                mostra_ranking('c');
                system("pause");
                break;

            case 3:
                animacao_creditos();
                creditos();
                break;

            case 0:
                salvar();
                printf("\tSaindo... Volte sempre!");
                break;

            default:
                printf ("\n======== Não há essa opção! ======== \n");
                break;
        }
        limpa_tela(1000);
    }while(opcao != 0 );
    return 0;
}

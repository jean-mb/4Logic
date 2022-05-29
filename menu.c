#include "functions.h"

/* ===================== FUNCOES PRATICAS=======================*/

int limpa_tela(int tempo)  // Aguarda o tempo informado, limpa o console, e aguarda novamente
{
    Sleep(tempo);
    system("cls");
    Sleep(tempo);
    return 0;
}

int mostra_menu()  // Arranjo de prints para mostrar o MENU
{
    printf("\t\t\t\t ___________________________________________ \n");
    printf("\t\t\t\t|                                           | \n");
    printf("\t\t\t\t<\t\t  SAVE T-REX\t\t    > \n");
    printf("\t\t\t\t|___________________________________________|\n");
    printf("\n");
    printf("\t\t\t\t\t>>>>> ESCOLHA UMA OPÇÃO <<<<< \n");
    printf("\t\t\t\t\t============================= \n");
    printf("\t\t\t\t\t\t1 -> JOGAR \n");
    printf("\t\t\t\t\t\t2 -> RANKING \n");
    printf("\t\t\t\t\t\t3 -> CREDITOS \n");
    printf("\t\t\t\t\t\t0 -> SAIR \n");
    return 0;
}

int creditos() // Mostra o nome da equipe e integrantes
{
    animacao_creditos();
    limpa_tela(500);
    return 0;
}

int menu() // Registra a opcao escolhid pelo jogador no menu
{
    int opc;
    printf("\n - Digite sua opção: ");
    scanf("%d", &opc);
    limpa_tela(500);
    return opc;
}


/* ===================== FUNÇOES DE RANKING ================================ */

int le_ranking() // Abre o arquivo jogadores.txt, lê os dados do arquivo, e joga dentro da struct ranking
{
    p_ranking = fopen("jogadores.txt", "r"); //abre arquivo em modo de leitura
    char c;

    for(int i=0; !feof(p_ranking); i++)
    {
        fscanf(p_ranking,"%d", &ranking[i].pontuacao);//importa a pontuação
        for(int a= 0; a < 10; a++)//importa nicks, caracter por carcater, evitando quebras de linha
        {
            c = fgetc(p_ranking);
            if(c=='\n' || c==EOF) //evita quebra de linhas e fim de arquivo
            {
                break;
            }
            ranking[i].nick[a]= c;
        }
    }
    for(int i=0; i<TAM; i++){
        if(ranking[i].pontuacao == 0){// acha em que ponto o ranking esta completo
            contador = i-1;
        }
    }
    fclose(p_ranking);
    return 0;
}

int organiza_ranking() // Organiza o ranking por bubble sort
{
  for (int contador=0; contador<TAM; contador++)
    {
        for (int i=0; i<TAM; i++)
        {
            if (ranking[i].pontuacao<ranking[i+1].pontuacao) // bubble sort em ordem decrescente
            {
                aux[0] = ranking[i];
                ranking[i] = ranking[i+1];
                ranking[i+1] = aux[0];
            }
        }
    }
    return 0;
}

int mostra_ranking(char modo) // Mostra o ranking de acordo com o modo de exibicao
{
    /*
        'c' -> completo = nick e pontuacao
        'p' -> apenas pontuacao
        'n' -> apenas nick
    */
    printf("\t\t\t RANKING \n");
    printf("\t\t__________________________\n\n");
    for (int i=0; i<TAM; i++)
    {
        if(ranking[i].pontuacao!=0) // se a pontuacao eh zero, nao eh exibida no ranking
        {
            switch(modo){
                case 'n':
                    printf ("\t\t\t%d° | %s\n",i+1,ranking[i].nick);
                    break;
                case 'p':
                    printf ("\t\t\t%d° %4d\n",ranking[i].pontuacao);
                    break;
                case 'c':
                default:
                    printf ("\t\t%d° | %s\t>> ",i+1,ranking[i].nick);
                    printf ("%4d\n",ranking[i].pontuacao);
                    break;
            }
        }
        else break;
    }
    printf("\n");
    return 0;
}

/* ===================== FUNCOES DO MENU ===================================*/

int cadastra_jogador() // Cadastra jogador no ranking de acordo com o contador
{
    int existe,index; // Variaveis auxiliares para testar se uma string existe
    printf("\n\n\t ================ CADASTRE SEU USUÁRIO ================\n");
    printf("\n\t -> Digite seu nick \t\t>> ");
    fflush(stdin);
    gets(aux[0].nick); // guarda na struct auxiliar
    for(int i=0; i<TAM; i++)
    {
        if(strcmp(ranking[i].nick, aux[0].nick) == 0) // testa em todas as posicoes da struct de ranking se existe a string inserida
        {
            existe = 1; //
            index = i;  // localizacao
        }
    }
    if(existe==1)  // se existe, sobrescreve a pontuacao
    {
        printf("\n\t -> Esse nick já existe! \n");
        printf("\n\t -> Digite sua pontuação \t>> ");
        scanf("%d", &ranking[index].pontuacao);
    }
    else if (contador >=TAM)
    {
        printf("\n\t -> Digite sua pontuação \t>> ");
        scanf("%d", &aux[0].pontuacao);
        for(int i=0; i<TAM; i++)
        {
            if (aux[0].pontuacao > ranking[i].pontuacao)
            {
                index=i;
                for(index; index<TAM; index++)
                {
                    aux[1] = ranking[index];
                    ranking[index] = aux[0];
                    aux[0] = aux[1];
                }
                break;
            }
        }
        printf("============================================\n");
        printf("\tJOGADOR: %s \tPONTUAÇÃO: %d \n",ranking[index].nick, ranking[index].pontuacao);
        printf("============================================\n");
    }
    else
    {
        //se nao existe, cadastra nick e pontuacao
        strcpy(ranking[contador].nick, aux[0].nick);
        printf("\t -> Digite sua pontuação \t>> ");
        scanf("%d", &ranking[contador].pontuacao);
        printf("============================================\n");
        printf("\tJOGADOR: %s \tPONTUAÇÃO: %d \n",ranking[contador].nick, ranking[contador].pontuacao);
        printf("============================================\n");
        contador++;
    }
    return 0;
}

int jogar() // Futuro jogo
{
    int opc, existe;
    mostra_ranking('n');
    printf("\n\t\t     0 >> Criar Novo \n");
    opc = menu();

    existe = ranking[opc-1].pontuacao != 0;

    if(opc == 0){
        cadastra_jogador();
    }
    else if(existe){
        printf("\n\n\n\n\n\t\t\t\t\tJogador >> %s <<  selecionado!\n\n\n\n\n\n\n", ranking[opc-1].nick);
    }else{
        printf("\n\n\t\t\t >> Essa posição não está ocupada no ranking! Cadastre um Novo Jogador!");
        limpa_tela(5000);
        cadastra_jogador();
    }
    system("pause");
    limpa_tela(10);
    animacao_dino();
    return 0;
}

int salvar() // Salva
{
    p_ranking = fopen("jogadores.txt", "w");
    for (int i=0; i<TAM; i++)
    {
        if(ranking[i].pontuacao !=0)
        {
            fprintf(p_ranking,"%d%s\n",ranking[i].pontuacao, ranking[i].nick);
        }
    }
    fclose(p_ranking);

    return 0;
}


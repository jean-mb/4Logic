# <b style="color:lime;">Save T-Rex | 4Logic</b> 
## <b>Documentação</b>
## Funcionamento 
### Arquivos
---
- <code>main.c</code> -> Arquivo principal com o menu principal. Importa demais arquivos
- <code>menu.c</code> -> Arquivo onde estão todas as funções internas
- <code>animacoes.c</code> -> Arquivo com arranjos de printf para mostrar animações no prompt
- <code>functions.h</code> -> Arquivo header do projeto, com os protótipos de todas as funções;
---
### Váriaveis Globais
---
- <code>FILE * p_arquivo</code> -> Ponteiro que aponta para o arquivo "jogadores.txt"
- <code>int contador</code> -> Variável global que conta quantas vezes um jogador foi adicionado ao ranking
---
### Funções
---
- <code>int limpa_tela(int tempo);</code> -> Recebe como parametro o tempo em _ms_ e procede: Espera o tempo informado -> limpa o prompt -> espera o tempo informado.
- <code>int menu();</code> -> Pede pro usuário digitar qual opção deseja, e retorna o valor digitado pelo usuário
- <code>int le_ranking();</code> -> Lê o arquivo txt, executa _fscanf_ para pegar a pontuação, e logo em seguida recolha o nick, caracter a caracter.
- <code>int organiza_ranking();</code> -> Organiza o ranking por BubbleSort em ordem decrescente. 
- <code>int mostra_ranking(char modo);</code> -> Mostra o ranking de acordo com o modo de exibição inserido no parâmetro. <br>'c' -> completo = nick e pontuacao<br>'p' -> apenas pontuacao<br>'n' -> apenas nick<br>Outros -> nick e pontuação
- <code>int cadastra_jogador();</code> -> Cadastra jogador seguindo as regras: Se existir um nick igual, apenas trocar a pontuação > Se o ranking está cheio, colocar na posição certa > Caso contrário, cadastrar no ranking, levando em conta como índice, a váriavel global _contador_. Incrementa a váriavel _contador_ no final do cadastro (a não ser que o nick já existia, nesse caso o contador não sofre alterações porquê o ranking não ganhou novas posições e sim substituiu uma existente)
- <code>int jogar();</code> -> Responsável pela lógica do submenu de cadastramento de jogador. É possível selecionar um jogador ou Criar um Novo (neste caso, a função <code style="color: gray;">int cadastra_jogador();</code> é chamada.
- <code>int salvar();</code> -> Abre o arquivo em modo _w_, salva o ranking em memória local, e fecha o arquivo.

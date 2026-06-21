extern char nomeJogador1[50];
extern char nomeJogador2[50];
extern char simboloJ1, simboloJ2;
extern int jogador, posicao, i, j;
extern int somaLinhas, somaColunas, somaDiagonal1, somaDiagonal2;
extern int matrizEscolha[3][3];
extern char matrizResposta[3][3];


void configuraJogadores(){
     printf("Digite o nome do jogador 1: ");
     scanf("%s", nomeJogador1);

     printf("Digite o nome do jogador 2: ");
     scanf("%s", nomeJogador2);

     do{
        printf("\n%s, voce quer ser X ou O? (digite em caixa alta)", nomeJogador1);
        scanf(" %c", &simboloJ1);

        if(simboloJ1 == 'x') simboloJ1 = 'X';
        if(simboloJ1 == 'o') simboloJ1 = 'O';
     
    } while (simboloJ1 != 'X' && simboloJ1 != 'O');

    if(simboloJ1 == 'X'){
        simboloJ2 = 'O';
    } else{
        simboloJ2 = 'X';
        simboloJ1 = 'O';
    }

    printf("\nConfiguracao aceita!\n");
    printf("%s vai jogar com: %c\n", nomeJogador1, simboloJ1);
    printf("%s vai jogar com: %c\n", nomeJogador2, simboloJ2);
    
    system("pause");
}

void inicia(){

    printf("Exemplo das posi��es:\n");
	printf("\t_1_|_2_|_3_\n");
	printf("\t_4_|_5_|_6_\n");
	printf("\t 7 | 8 | 9 \n");
	system("pause");
	system("cls");
	printf("\n");
	printf("\t___|___|___\n");
	printf("\t___|___|___\n");
	printf("\t   |   |   \n");
	
	do {
		if (jogador == 1) {
			int linhaUsuario, colunaUsuario;
            
            printf("%s %c, Digite a posicao da linha que deseja efetuar a jogada: ", nomeJogador1, simboloJ1);
            scanf("%d", &linhaUsuario);
            printf("Digite agora a posicao da coluna que deseja efetuar a jogada: ");
            scanf("%d", &colunaUsuario);

            matrizEscolha[linhaUsuario][colunaUsuario] = 100;
            matrizResposta[linhaUsuario][colunaUsuario] = simboloJ1;
            
            jogador = 2;

         }else if (jogador == 2) {
			int linhaUsuario, colunaUsuario;

            printf("%s %c, Digite a linha que deseja efetuar a jogada (0 a 2): ", nomeJogador2, simboloJ2);
            scanf("%d", &linhaUsuario);
            printf("Digite a coluna que deseja efetuar a jogada: ");
            scanf("%d", &colunaUsuario);

            matrizEscolha[linhaUsuario][colunaUsuario] = 400;
            matrizResposta[linhaUsuario][colunaUsuario] = simboloJ2;

			jogador = 1;
		} else {
			break;
		}
        
		system("cls");
		printf("\n");
		printf("\t_%c_|_%c_|_%c_\n", matrizResposta[0][0], matrizResposta[0][1], matrizResposta[0][2]);
		printf("\t_%c_|_%c_|_%c_\n", matrizResposta[1][0], matrizResposta[1][1], matrizResposta[1][2]);
		printf("\t %c | %c | %c \n", matrizResposta[2][0], matrizResposta[2][1], matrizResposta[2][2]);
		
		somaDiagonal1 = matrizEscolha[0][0] + matrizEscolha[1][1] + matrizEscolha[2][2];
		somaDiagonal2 = matrizEscolha[0][2] + matrizEscolha[1][1] + matrizEscolha[2][0];

		for (i = 0; i < 3; i++) {
			somaLinhas = 0;
			somaColunas = 0;
				for (j = 0; j < 3; j++) {
					somaLinhas += matrizEscolha[i][j];
					somaColunas += matrizEscolha[j][i];
					if (somaLinhas == 300 || somaColunas == 300 || somaDiagonal1 == 300 || somaDiagonal2 == 300) {
						printf("\nParabéns! O jogador %s ganhou!", nomeJogador1);
						jogador = 3;
						break;
					
					}else if (somaLinhas == 1200 || somaColunas == 1200 || somaDiagonal1 == 1200 || somaDiagonal2 == 1200) {
						printf("\nParabéns! O jogador %s ganhou!", nomeJogador2);
						jogador = 3;
						break;
					}
                }

                if (jogador == 3){
                    break;
                }
            }
      		
	} while(jogador == 1 || jogador == 2);
	
}

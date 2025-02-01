#include "../Interface/BMH.h"
#include "../Interface/tons.h"

int boyerMoore(char **musica, char **trecho, int m, int t){
    if(t > m){
        printf("O trecho para pesquisa é maior que a música!\n");
        return -1;
    }

    char *(*notas)[2] = listaNotas();
    int d[12]; // Array de deslocamento do tamanho do dicionário, 12 notas

    for(int deslocamento = 0; deslocamento < 12; deslocamento++){
        // Inicializa o array com o valor do tamanho do padrão
        for(int j = 0; j < 12; j++){
            d[j] = t;
        }

        // Preenche o array considerando as notas do padrão e o índice delas
        for(int j = 0; j <  t - 1; j++){
            int index = indexNota(trecho[j]);
            if(index != -1){
                d[index] = t - j - 1;
            }
        }

        // Início da pesquisa de casamento
        int i = 0;
        while(i <= m - t){
            int j = t - 1; // é atribuído o último índice do padrão
            int casamento = 1;

            // Compara todas as notas do padrão
            while(j >= 0 && casamento){
                int index = indexNota(trecho[j]);
                if(index == -1){
                    casamento = 0;
                    break;
                }

                // Salva nessas variáveis a nota e sua equivalente
                char *nota1 = notas[index][0];
                char *nota2 = notas[index][1];

                // Compara a nota e sua equivalente
                int casamentoAtual = (strcmp(musica[i + j], nota1) == 0);
                if(!casamentoAtual  && nota2[0] != '\0'){
                    casamentoAtual = (strcmp(musica[i + j], nota2) == 0);
                }

                if(!casamentoAtual){ // Se as notas não são iguais sairá do loop
                    casamento = 0;
                }

                j--;
            }
            
            // Se chegou ao final do padrão retorna o índice do início do casamento
            if(casamento){
                return i;
            }

            // Calcula o deslocamento para comparação no texto
            int index = indexNota(musica[i + t - 1]); // Primeira nota do texto da direita pra esquerda
            if(index != -1){
                i = i + d[index];
            } else {
                i = i + t;
            }
        }

        subirMeioTom(trecho, t);
    }
    return -1;
}
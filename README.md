Foram implementados os seguintes algoritmos:

1 - Força Bruta  
2 - KMP  
3 - Boyer-Moore (BMH)  
4 - ShiftAndExato  

Para executar o programa, primeiro altere o arquivo de entrada presente em ./Entrada_saida/Arquivos/entrada.txt com a entrada que desejar seguindo o padrão abaixo:

16 4  
D G A B C D G G G C D E F# G C C  
G G C D  
4 3  
C E G Bb  
D F# A  
0 0  

Para compilar digite "make" no terminal e para executar o programa existem duas opções:

1. Digite "./tp3" com dois parâmetros. O primeiro é o arquivo de entrada, e o segundo o número do algoritmo que deseja executar.  
Exemplo: "./tp3 entrada.txt 1"

2. Digite "make run" com o número do algoritmo que deseja executar depois de "run".  
Exemplo: "make run1"

O resultado estará presente em ./Entrada_saida/Arquivos/saida.txt. E caso queira excluir os arquivos objetos(.o) e o executável basta digitar "make clean" no terminal.
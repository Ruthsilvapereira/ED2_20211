// Aluno: José Guiherme da Silva Neves
// Exemplo retirado em http://www.jppreti.com/2019/07/15/ponteiros-em-c/
// Atividade sobre ponteiros

#include <stdio.h>
#include <stdlib.h>

int main() {
	
    int number = 25;// Declaracao de variavel int
    int *numberP = &number;// Variavel tipo ponteiro, apontando para o endereco de memoria da variavel number
    
    printf("Valor da variavel number: %d\n",number);
    printf("Endereco da variavel number: %p\n",&number);// Exibe o endereço da variavel number na memoria
    printf("Valor da variavel numberP: %p\n",numberP);// Exibe o endereco da variavel number, que esta referenciado pelo ponteiro numberP
    printf("Valor apontado por numberP: %d\n\n",*numberP);
    printf("Mudando o valor de number de forma indireta\n\n");
   
    *numberP = 30; // Muda o valor da variavel number, atraves do ponteiro
    
    printf("Valor da variavel number: %d\n",number);
//numberP++: desloca para o proximo endereco de memoria
	numberP++;
    printf("Valor da variavel numberP: %p\n", numberP);
    printf("Valor no endereco apontado: %d\n", *numberP);
// Aloca um espaco na memoria de tamanho float, para o ponteiro pi   
    float *pi = (float *) malloc(sizeof(float));
    printf("Valor da variavel pi: %p\n", pi);
// Altera o valor apontado
    *pi=3.1415;
    
    printf("Valor no endereco apontado: %f\n", *pi);
    free(pi);
    printf("Valor da variavel pi: %p\n", pi);
    printf("Valor da variavel apontada: %f\n", *pi);
// O conteudo enderecado por pi é alterado
    *pi = 0;
    pi = NULL;
// malloc: faz a alocacao de um espaco na memoria, de tamanho determinado pelo sizeof
// sizeof: verifica o tipo da variavel e retorna o tamanho necessario pata a alocacao em bytes
    int *numbers = (int *) malloc(sizeof(int) * 3);// aloca tres espacos na memoria para variavel tipo int
    *(numbers+0) = 1;
    *(numbers+1) = 2;
    *(numbers+2) = 3;
    
    for (int i = 0; i < 3; i++)
        printf("numbers[%d] = %d\n",i,numbers[i]);
    
    for (int i = 0; i < 3; i++)
        printf("*(numbers+%d) = %d\n",i,*(numbers+i));
    
    int *aux = numbers;
    for (int i = 0; i < 3; i++) {
        printf("aux = %d\n",*aux);
        aux++;
    }
    return EXIT_SUCCESS;
}

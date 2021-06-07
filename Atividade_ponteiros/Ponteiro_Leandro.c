/*Atividade sobre Ponteiros tendo como base os exemplos disponibilizados em http://www.jppreti.com/2019/07/15/ponteiros-em-c/*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int number = 75; //variavel do tipo int recebendo um valor
    int *numberP = &number; //variavel do tipo ponteiro recebendo o endereço de memoria da variavel number
    printf("Valor da variável number: %d\n",number); //mostra o valor da variavel number
    printf("Endereço da variável number: %p\n",&number); //mostra o endereço alocado na memoria da variavel number
    printf("Valor da variável numberP: %p\n",numberP); // mostra o conteudo referenciado pelo ponteiro numberP
    printf("Valor apontado por numberP: %d\n\n",*numberP);//mostra o valor da variavel ponteiro
    printf("Mudando o valor de number de forma indireta\n\n");
    *numberP = 40;//o conteudo da variavel number é alterado por meio do ponteiro
    printf("Valor da variável number: %d\n",number);
    numberP++;//o ponteiro avança para outra posição
    printf("Valor da variável numberP: %p\n", numberP);
    printf("Valor no endereço apontado: %d\n", *numberP);
    float *pi = (float *) malloc(sizeof(float));//memoria alocada para variavel do tipo ponteiro com tamanho de float
    printf("Valor da variável pi: %p\n", pi);
    *pi=3.1415;// o conteudo referenciado pelo ponteiro é alterada
    printf("Valor no endereço apontado: %f\n", *pi);
    free(pi);//libera o espaço alocado na memorária
    printf("Valor da variável pi: %p\n", pi);
    printf("Valor da variável apontada: %f\n", *pi);
    //*pi = 0;//a variavel é zerada
    //pi = NULL;//o espaco alocado esta definitivamente zerado
    int *vet = (int *) malloc(sizeof(int) * 3);//alocado 3 espacos de memoria do tamanho int 
    *(vet+0) = 5;//o espaco referenciado nesta posicao recebe o conteudo de valor 5
    *(vet+1) = 10;
    *(vet+2) = 15;
    printf("\nImpressao do vetor\n\n");
    for (int i = 0; i < 3; i++)
        printf("vet[%d] = %d\n",i,vet[i]);
    
    printf("\nOutra forma de imprimir o vetor\n\n");
    for (int i = 0; i < 3; i++)
        printf("*(vet+%d) = %d\n",i,*(vet+i));
    
    int *aux = vet;
    printf("\nOutra outra alternativa para exibir o conteudo do vetor\n\n");
    for (int i = 0; i < 3; i++) {
        printf("aux = %d\n",*aux);
        aux++;
    }
    return EXIT_SUCCESS;
}
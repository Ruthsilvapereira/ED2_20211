/*Código retirado do site http://www.jppreti.com/2019/07/15/ponteiros-em-c/.
Aluno : Gabriel Robert Gonçalves Reis*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int number = 50; 
    //declaração de ponteiro (*numberP) e está apontando para o endereço da váriavel (number).
    int *numberP = &number;  
    
    printf("Valor da variavel number: %d\n",number);
    printf("Endereço da variavel number: %p\n",&number);
    printf("Valor da variavel numberP: %p\n",numberP);
    printf("Valor apontado por numberP: %d\n\n",*numberP);
    printf("Mudando o valor de number de forma indireta\n\n");
    
    *numberP = 35;
    printf("Valor da variavel number: %d\n",number);
    
    //Está acrescentando 1 ao endereço, descolando ao próximo endereço de memória.
    numberP++;
    
    printf("Valor da variavel numberP: %p\n", numberP);
    printf("Valor no endereço apontado: %d\n", *numberP);
    float *pi = (float *) malloc(sizeof(float));
    printf("Valor da variavel pi: %p\n", pi);
    printf("Valor no endereço apontado: %f\n", *pi);
    
    // O conteúdo apontado é alterada.
    *pi=3.1415;
    free(pi);
    
    printf("Valor da variavel pi: %p\n", pi);
    printf("Valor da variavel apontada: %f\n", *pi);
    
    //não deixa rastro na memória.
    *pi = 0;
    pi = NULL;
    
    //malloc loca espaço para um bloco de bytes consecutivos na memória RAM e devolve o endereço inicial desse bloco.
    //malloc sizeof retorna a quantidade de bytes necessária para armazenar um int.
    
    int *numbers = (int *) malloc(sizeof(int) * 3); 
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

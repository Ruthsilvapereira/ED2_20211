//Autor: Wallatan com base no material do Dr. Pr. João Paulo 
//Material disponível em http://www.jppreti.com/2019/07/15/ponteiros-em-c/
//Atividade de ponteiro

//Declarando váriaveis
#include <stdio.h>
#include <stdlib.h>

//Iniciando a função principal do sistema
int main() {
    // Declarando variavel inteira e atribuindo um valor  
    int number = 10;
    // Declarando uma variavel ponteiro do tipo inteiro
    int *numberP = &number;
    //exbindo valores especificos de memoria, endereço, etc...
    printf("Valor da variavel number: %d\n",number);
    printf("Endereco da variavel number: %p\n",&number);
    printf("Valor da variavel numberP: %p\n",numberP);
    printf("Valor apontado por numberP: %d\n\n",*numberP);
    printf("Mudando o valor de number de forma indireta\n\n");
    *numberP = 15;
    printf("Valor da variavel number: %d\n",number);
    //avança uma posição na memoria em numberP
    numberP++;
    printf("Valor da variavel numberP: %p\n", numberP);
    printf("Valor no endereco apontado: %d\n", *numberP);
    //Cria um variavel ponteiro do tipo float e aloca um espaço na memoria do tipo float
    //Através da função malloc, uma quantidade x espaço é gerado na memória, e seus endereços são retornados 
    float *pi = (float *) malloc(sizeof(float));
    printf("Valor da variavel pi: %p\n", pi);
    //atribui um valor no endereço apontado
    *pi=3.1415;
    printf("Valor no endereco apontado: %f\n", *pi);
    //limpa os dados de pi
    free(pi);
    printf("Valor da variavel pi: %p\n", pi);
    printf("Valor da variavel apontada: %f\n", *pi);
    *pi = 0;
    //pi recebe vazio
    pi = NULL;
    //Alocando na memória três espaço do tipo inteiro
    int *numbers = (int *) malloc(sizeof(int) * 3);
    //atribuindo valores aos espaços da memória
    *(numbers+0) = 1;
    *(numbers+1) = 2;
    *(numbers+2) = 3;
    //Exibe os valores das variaveis 
    for (int i = 0; i < 3; i++)
        printf("numbers[%d] = %d\n",i,numbers[i]);
    //Exibe os valores das variaveis de acordo com a posição na memoria
    for (int i = 0; i < 3; i++)
        printf("*(numbers+%d) = %d\n",i,*(numbers+i));
    //Cria uma variavel ponteiro do tipo inteiro que aponta para numbers
    int *aux = numbers;
    //exibe os valores do numbers atráves da variavel ponteiro *aux
    for (int i = 0; i < 3; i++) {
        printf("aux = %d\n",*aux);
        aux++;
    }
    //Retorna que o programa foi finalizado 
    return EXIT_SUCCESS;
}

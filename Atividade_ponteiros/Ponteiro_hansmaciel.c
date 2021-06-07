//Aluno: Hans Maciel
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 12; //variavel int do nome number recebe valor 12
    int *numberP = &number;
    //Mostrando na tela os valores e os passo a passo
    printf("Valor da variável number: %d\n",number); //mostrando na tela o valor da variavel number
    printf("Endereço da variável number: %p\n",&number); //mostrando o endereço da variavel number
    printf("Valor da variável numberP: %p\n",numberP); //mostra na tela o valor da variavel numberP
    printf("Valor apontado por numberP: %d\n\n",*numberP); //Aponta o valor apontado pelo numberP

    printf("Mudando o valor de number de forma indireta\n\n"); //Mostrando na tela a mudança de valor de number de forma indireta
    *numberP = 15; 
    printf("Valor da variável number: %d\n",number); //Mostrando valor de number

    //recebendo +1 ao valor
    numberP++; 
    printf("Valor da variável numberP: %p\n", numberP); //mostrando na tela o valor em numberP
    printf("Valor no endereço apontado: %d\n", *numberP); //Mostrando o valor do endereço  

    //reservando espaço na memoria para um float
    float *pi = (float *) malloc(sizeof(float));
    printf("Valor da variável pi: %p\n", pi);
    *pi=3.1415;
    printf("Valor no endereço apontado: %f\n", *pi);
    free(pi);
    printf("Valor da variável pi: %p\n", pi);
    printf("Valor da variável apontada: %f\n", *pi);
    *pi = 0;
    pi = NULL;

    //reservando espaço na memoria para 3 int
    int *numbers = (int *) malloc(sizeof(int) * 3);
    *(numbers+0) = 1;
    *(numbers+1) = 2;
    *(numbers+2) = 3;

    //exibindo os espaços na memoria
    for (int i = 0; i < 3; i++)
        printf("numbers[%d] = %d\n",i,numbers[i]);

    for (int i = 0; i < 3; i++)
        printf("*(numbers+%d) = %d\n",i,*(numbers+i));

    int *aux = numbers;
    for (int i = 0; i < 3; i++) {
        printf("aux = %d\n",*aux);
        aux++;
    }

    return 0; 
} 

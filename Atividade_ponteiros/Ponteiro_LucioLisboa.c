//programa desenvolvido por Lucio Lisboa, baseado nos codigos do professor Joao Paulo com o intuito de aprender sobre o conceito de ponteiro em C
#include <stdio.h>
#include <stdlib.h>
int main() {
        //declara uma variavel do tipo inteiro e uma do tipo ponteiro a serem usadas no codigo
        int number = 10;
        int *numberP = &number;

        printf ("\n INICIO \n\n");

        //paragrafo mostrando a diferenca pratica entre uma variavel inteira e uma variavel ponteiro
        printf("Valor da variavel number: %d\n",number);
        printf("Endereco da variavel number: %p\n",&number);
        printf("Valor da variavel numberP: %p\n",numberP);
        printf("Valor apontado por numberP: %d\n\n",*numberP);

        //paragrafo mostrando que e possivel alterar a variavel do tipo inteiro por meio da variavel ponteiro
        printf("Mudando o valor de number de forma indireta\n");
        *numberP = 15;
        printf("Valor da variavel number: %d\n",number);

        //paragrafo referente a teste da aritmetica em ponteiros
        numberP++;
        printf("Valor da variavel numberP: %p\n", numberP);
        printf("Valor no endereco apontado: %d\n", *numberP);

        //paragrafo mostrando a como alocar memoria para o uso dos ponteiros e como liberar o espaco alocado da memoria
        float *pi = (float *) malloc(sizeof(float));
        printf("Valor da variavel pi: %p\n", pi);
        *pi=3.1415;
        printf("Valor no endereco apontado: %f\n", *pi);
        free(pi);
        printf("Valor da variavel pi: %p\n", pi);
        printf("Valor da variavel apontada: %f\n", *pi);
        *pi = 0;
        pi = NULL;

        //paragrafo mostrando como criar um array(vetor) de ponteiros
        int *numbers = (int *) malloc(sizeof(int) * 3);
        *(numbers+0) = 1;
        *(numbers+1) = 2;
        *(numbers+2) = 3;

        //exibindo os dados salvos em cada posicao do array
        for (int i = 0; i < 3; i++)
                printf("numbers[%d] = %d\n",i,numbers[i]);

        //outra forma de mostrar os dados do vetor
        for (int i = 0; i < 3; i++)
                printf("*(numbers+%d) = %d\n",i,*(numbers+i));

        int *aux = numbers;
        for (int i = 0; i < 3; i++) {
                printf("aux = %d\n",*aux);
                aux++;
        }
        return EXIT_SUCCESS;
}
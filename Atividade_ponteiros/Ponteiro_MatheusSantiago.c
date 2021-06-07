// Aluno: Matheus Santiago
// Representação do Exemplo encontrado em http://www.jppreti.com/2019/07/15/ponteiros-em-c/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 10; // Ponteiro, guarda o endereço de memoria que contem um numero inteiro
    int *numberP = &number; // variavel que guarda um endenreço de memoria
    printf("Valor da variável number: %d\n",number); // valor guardado na variavel number
    printf("Endereço da variável number: %p\n",&number); //endereço de number
    printf("Valor da variável numberP: %p\n",numberP); // valor da variavel numberP
    printf("Valor apontado por numberP: %d\n\n",*numberP); // valor guardado no endereço apontado por numberP
    printf("Mudando o valor de number de forma indireta\n\n");
    *numberP = 15; // é a mesma coisa que number = 15;
    printf("Valor da variável number: %d\n",number);
    numberP++; 
    printf("Valor da variável numberP: %p\n", numberP);
    printf("Valor no endereço apontado: %d\n", *numberP);
    float *pi = (float *) malloc(sizeof(float)); //malloc: aloca espaco para um bloco de bytes consecutivos na memoria ram e devolve o endereco inicial desse bloco
    printf("Valor da variável pi: %p\n", pi);
    *pi=3.1415;
    printf("Valor no endereço apontado: %f\n", *pi);
    free(pi);// libera o endereco de memoria que guardava a variavel pi guardava
    printf("Valor da variável pi: %p\n", pi);
    printf("Valor da variável apontada: %f\n", *pi);
    *pi = 0;
    pi = NULL; // para nao deixar rastros na memoria
    int *numbers = (int *) malloc(sizeof(int) * 3); // alocado 3 vezes o tamanho de um int
    *(numbers+0) = 1; // mesmo que numbers[0] = 1;
    *(numbers+1) = 2; // mesmo que numbers[1] = 2;
    *(numbers+2) = 3; // ||     || numbers[2] = 3;
 //formas para testar o preenchimento da variavel numbers   
    for (int i = 0; i < 3; i++)
        printf("numbers[%d] = %d\n",i,numbers[i]);
    
    for (int i = 0; i < 3; i++)
        printf("*(numbers+%d) = %d\n",i,*(numbers+i));
    
    int *aux = numbers;
    for (int i = 0; i < 3; i++) {
        printf("aux = %d\n",*aux);
        aux++;}
return EXIT_SUCCESS;}

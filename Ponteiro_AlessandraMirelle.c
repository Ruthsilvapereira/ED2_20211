// Representação do Exemplo encontrado em http://www.jppreti.com/2019/07/15/ponteiros-em-c/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 10; //Variavel number neste exemplo contem um numero inteiro.
    int *numberP = &number; //Ponteiro *numberP ira guarda um endenreço de memoria number.
    printf("Valor da variável number: %d\n",number); //Ira mostrar o valor guardado na variavel number.
    printf("Endereço da variável number: %p\n",&number); //Ira mostrar endereço da variavel number.
    printf("Valor da variável numberP: %p\n",numberP); //Ira mostrar o valor da variavel numberP.
    printf("Valor apontado por numberP: %d\n\n",*numberP); //Ira mostrar o valor guardado em numberP.
    printf("Mudando o valor de number de forma indireta\n\n");
    *numberP = 15; //Introduzindo numberP = 15 é a mesma coisa que number = 15.
    printf("Valor da variável number: %d\n",number);
    numberP++; 
    printf("Valor da variável numberP: %p\n", numberP);
    printf("Valor no endereço apontado: %d\n", *numberP);
    float *pi = (float *) malloc(sizeof(float)); //Aloca espaco para um bloco de bytes consecutivos na memoria ram e devolve o endereco inicial desse bloco.
    //sizeof retorna a quantidade de bytes necessaria para armazenar um float.
    printf("Valor da variável pi: %p\n", pi);
    *pi=3.1415;
    printf("Valor no endereço apontado: %f\n", *pi);
    free(pi);//free efetua a liberação do endereço da memoria.
    printf("Valor da variável pi: %p\n", pi);
    printf("Valor da variável apontada: %f\n", *pi);
    *pi = 0; //*pi = 0 e pi = null sera utilizado para não deixar rastro na memoria.
    pi = NULL;
    int *numbers = (int *) malloc(sizeof(int) * 3); //Efetua alocação 3 vezes o tamanho de um int
    *(numbers+0) = 1; //É o mesmo que numbers[0] = 1;
    *(numbers+1) = 2; //É o mesmo que numbers[1] = 2;
    *(numbers+2) = 3; //É o mesmo que numbers[2] = 3;
 
    //Modos para testar o preenchimento da variavel numbers.
    for (int i = 0; i < 3; i++)
        printf("numbers[%d] = %d\n",i,numbers[i]);
    
    for (int i = 0; i < 3; i++)
        printf("*(numbers+%d) = %d\n",i,*(numbers+i));
    
    int *aux = numbers;
    for (int i = 0; i < 3; i++) {
        printf("aux = %d\n",*aux);
        aux++;}
return EXIT_SUCCESS;}

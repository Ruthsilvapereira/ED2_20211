//Exemplo dado em http://www.jppreti.com/2019/07/15/ponteiros-em-c/
//Um ponteiro é um tipo especial de variável que guarda como dado um endereço de memória
//number não guarda um número inteiro, mas sim um endereço de memória. Esse endereço sim contém um número inteiro
//number guarda um número inteiro (10), já a variável numberP guarda o endereço de memória da variável number

#include <stdio.h>
#include <stdlib.h>
int main() {
    int number = 10;
//*numberP ponteiro, guarda endereço de memoria e o endereço de memoria contém um número inteiro 
    int *numberP = &number;
//Valor da variável number: 10
    printf("Valor da variável number: %d\n",number);
//Endereço da variável number (endereço onde está o dado): ENDEREÇO
    printf("Endereço da variável number: %p\n",&number);
//Valor da variável numberP (sem usar *): VALOR 
    printf("Valor da variável numberP: %p\n",numberP);
//*numberP (usando *) valor apontado por numberP: 10
    printf("Valor apontado por numberP: %d\n\n",*numberP);
//Mudando o valor de number de forma indireta
    printf("Mudando o valor de number de forma indireta\n\n");
//Valor da variável numberP será modificado para 15
    *numberP = 15;
    printf("Valor da variável number: %d\n",number);
//numberP++: navega para o proximo endereço de memoria
    numberP++;
//Valor da variável numberP: 15
    printf("Valor da variável numberP: %p\n", numberP);
//Valor no endereço apontado *numberP
    printf("Valor no endereço apontado: %d\n", *numberP);
//malloc: reserva espaço e devolve o endereço de memoria
//Valor da variável pi
    float *pi = (float *) malloc(sizeof(float));
    printf("Valor da variável pi: %p\n", pi);
//Valor no endereço apontado
    *pi=3.1415;
//Valor no endereço apontado
    printf("Valor no endereço apontado: %f\n", *pi);
//free: libera o endereço (free(pi) será liberado o endereço de memoria que guardava o pi)
    free(pi);
//Valor da variável pi: VALOR
    printf("Valor da variável pi: %p\n", pi);
//Valor da variável apontada: 0.000000
    printf("Valor da variável apontada: %f\n", *pi);
//*pi = 0: o conteudo/endereço que havia em pi é zerado
    *pi = 0;
    pi = NULL;
//será alocado espaço para inteiro (int *)
//malloc(sizeof(int) * 3: alocar 3X espaço
//numbers[0] = 1, é o mesmo que, *(numbers+0) = 1;
//numbers[1] = 2, é o mesmo que, *(numbers+1) = 2;
//numbers[2] = 3, é o mesmo que, *(numbers+2) = 3;
    int *numbers = (int *) malloc(sizeof(int) * 3);
    *(numbers+0) = 1;
    *(numbers+1) = 2;
    *(numbers+2) = 3;
//primeira opção para preencher a variável numbers   
    for (int i = 0; i < 3; i++)
        printf("numbers[%d] = %d\n",i,numbers[i]);
//segunda opção para preencher a variável numbers    
    for (int i = 0; i < 3; i++)
        printf("*(numbers+%d) = %d\n",i,*(numbers+i));

//terceira opção para preencher a variável numbers
    int *aux = numbers;
    for (int i = 0; i < 3; i++) {
        printf("aux = %d\n",*aux);
        aux++;
    }
    return EXIT_SUCCESS;
}

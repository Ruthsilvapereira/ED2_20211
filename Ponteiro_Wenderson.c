// ATIVIDADE 01
// Atividade de ponteiro feito em c

//Aluno: Wenderson Pinheiro Farias

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,b;
    int *x;
    x = &a;
    a = 16;
    b = 15;

    // Mostrando os valores das variveis
     printf("\n------------------------------------------------------------\n");

    printf("Valor da variavel a: %d \n", a);
    printf("Valor da variavel b: %d \n", b);

    // Mostrando o endereco das variveis

    printf("Endereco da variavel a: %p \n", &a);
    printf("Endereco da variavel b: %p \n", &b);
    printf("Endereco do ponteiro x: %p \n", &x);

    //É possivel mudar o valor da variavel que esta sendo sendo apontada!

    *x = 14;

    //Verificando se o valor da variavel a é maior que a da b, por meio de ponteiro

    if(*x > b)
        printf(" \nO valor da variavel A eh maior que a variavel B!\n");
    else
        printf(" \nO valor da variavel B eh maior que a variavel A!\n");

    // Verifica se o endereco de memoria eh maior que o outro.

    if(a > b){
        printf("O endereco da variavel A eh maior que da variavel B!\n\n");
    }else{
        printf("O endereco da variavel B eh maior que da variavel A!\n\n");
    }

    //***********************************************************************
    //-----------------------------------------------------------------------

    //Ponteiro usando alocacao dinamica

    //A funcao ''malloc'' reserva um espaco da memoria
    //e retorna NULL em caso de erro
    //ou retorna um ponteiro com endereço com inicio
    //do espaço de memoria alocado


    int *p;
    p = (int *) malloc(5*sizeof(int));

    if(p == NULL){
        printf("Erro: Sem Memoria!");
        exit(1);
    }

    int i;

    //Utilizando um vetor com ponteiros com 3 posição
    printf("\n------------------------------------------------------------\n");
    printf("\nInforme os valores do vetor\n\n");
    for(i= 0; i<3 ; i++ ){
        printf("Digite  um valor para p[%d]: ",i);
            scanf("%d", &p[i]);
    }

    printf("\n\nDados do vetor \n");
    for(i= 0; i<3 ; i++ ){
        printf("\nEndereco: %p\n",&p[i]);
        printf("valor: %d \n",p[i]);
    }
     printf("\n------------------------------------------------------------\n");

    //Libera o espaço de memoria alocada
    free(p);
    printf("\n");




    //Fazendo um matriz com ponteiros

    //utilizando o conceito de ponteiro para ponteiro

    /*Em um ponteiro para ponteiro, cada
    nivel do ponteiro permite criar uma
    nova dimensão no array.
    */
    //int* -> permite criar um array de int
    //int** -> permite criar um array de int*

    //Criando uma matriz 2x2

    //cria um vetor de int*
    int **m = (int **) malloc(2 * sizeof(int *));
    int j;

    printf("\nDigite os valores da matriz!\n\n");
    for(i = 0 ; i< 2; i++){
        //cria um vetor de int
        m[i] = (int *) malloc(2 * sizeof(int));

        for(j=0; j <2 ; j++){
            //lê a matriz de inteiros.
            printf("Digite os valores da posicao p[%d][%d]: ", i,j);
                scanf("%d", &m[i][j]);
        }
    }

    for(i = 0 ; i< 2; i++){
         for(j=0; j <2 ; j++){
               printf("\nEndereco: %p\n",&m[i][j]);
            printf("valor: %d \n",m[i][j]);
         }
    }

     printf("\n------------------------------------------------------------\n");

    //liberando a memoria alocada
    //Em um array com mais de uma dimensão, a
    //memoria é liberada na ordem inversa da alocação.

    for(i = 0 ; i< 2; i++){
        free(m[i]);
    }

    free(m);





    return 0;



}

//Olá a todos! Estou adiantando a atividade DoublyLinkedListTest.c
//As funções são semelhantes a Lista Simplesmente Ligada (LinkedListTest.c), porém, temos novas funçoes e um novo ponteiro que será detalhado no algoritmo. 
#include <stdlib.h> 
#include <stdio.h>
#include "DoublyLinkedList.h"
bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}
//Como dito, temos agora um novo ponteiro de função para o algoritmo de impressão que será utilizado pela nossa biblioteca
void impressao(void *data) {
    int *dado = (int*)data;
    printf("%d - ",*dado);
}
int main() {
    DoublyLinkedList list;
    init(&list);
//show: exibe os dados de todos os nós da lista
//showMem: exibe a organização na memória de todos os nós da lista
    
    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=2;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=3;
    enqueue(&list, aux);
    show(&list,impressao);
    showMem(&list);
    printf("%d\n",*((int*)first(&list)));
    printf("%d\n",indexOf(&list,aux,compara));
    printf("%d\n",*((int*)getPos(&list,2)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    //printf("%d\n",*((int*)dequeue(&stack)));
    
    return EXIT_SUCCESS;
}
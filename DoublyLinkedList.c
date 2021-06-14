//Olá a todos! Estou adiantando a atividade Lista Duplamente Ligada, atividade dois do AVA
//O QUE É?
//Veremos que o uso da Lista Duplamente Ligada é indicada para situações que precise voltar, ou seja, navegar entre as posições.
//Caso a necessidade seja apenas de avançar e nunca voltar, então o indicado é a Lista Simplesmente Ligada vista anteriormente.
//Dito isso, vejamos o funcionamento das funções usadas na Lista Simplesmente Ligada, usando a Lista Duplamente Ligada.
//Nota-se que as funções são um pouco semelhantes a anterior, porém, as funções são colocadas de forma a corresponder a Lista Duplamente Ligada (bidirecional).
//Biblioteca da Lista Duplamente Ligada (DoublyLinkedList.h)
//Operações complementares: 
//          2.2.1 show: exibe os dados de todos os nós da lista
//          2.2.2 showMem: exibe a organização na memória de todos os nós da lista
//Descrição da atividade
//   	DoublyLinkedList.c
//   	DoublyLinkedList.h
//   	DoublyLinkedListTest.c 
//   	Por gentileza coloque o nome a frente da sua escolha de implementação, comente sempre seu nome em tudo que foi feito e detalhe para melhor endendimento dos demais.
// Divisão da atividade por alunos, conforme Lista Simplesmente Ligada (primeira lista). Porém, agora será para Lista Duplamente Ligada
//(caso queira mudar a função de escolha é só editar).
//   		3.2.1 init ======> Ruth
//   		3.2.2 isEmpty ======> Leandro
//   		3.2.3 enqueue ======> Matheus Santiago
//   		3.2.4 first ======>Gabriel Robert
//   		3.2.5 last ======>Jose Guilherme Neves
//   		3.2.6 dequeue ======> Carlos Henrique Teixeira Carneiro
//   		3.2.7 pop ======> Zhaira Rachid Jaudy
//   		3.2.8 top ======> Thiago Ramalho Setúbal
//   		3.2.9 push ======> Vinicius Matusita
//   		3.2.10 getNodeByPos ======>Lucio Lisboa
//   		3.2.11 getPos ======> Alessandra Mirelle
//   		3.2.12 add ======> Guilherme Mendes 
//   		3.2.13 addAll ======> Hans Maciel
//   		3.2.14 removePos ======>Wallatan França
//   		3.2.15 indexOf ======> by Eduardo Hideki  
//   		3.2.16 removeData ======>
//          2.2.1 show ======> Wenderson Farias
//          2.2.2 showMem ======> Mickael Luiz Dias da Silva
//implementação da Lista Duplamente Ligada: DoublyLinkedList.c
//Resultado esperado: compilação correta e sem ERRO na execução
//Início
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

//Alguns pontos e diferenças da Lista Duplamente Ligada X Lista Simplesmente Ligada
//Agora na Lista Duplamente Ligada temos dois ponteiros: next e previous
//Lista Duplamente Ligada permite a navegação nos dois sentidos, ela ocupa mais memória que a anterior (Lista Simplesmente Ligada)
//Essa Lista Duplamente Ligada será feita no formato circular, por isso, diferente da Lista Simplesmente ligada onde first: nulo  (list->first=NULL;) agora first: nó lixo  (list->first=trashNode;) recebe trashNode
//init ==> inicializa a DoublyLinkedList.h
void init(DoublyLinkedList *list) {
//trashNode: nó lixo, ou sentinela (permite que mesmo a lista estando vazia ela aponta para um nó: (list->first=trashNode;)
    Node *trashNode = (Node*)malloc(sizeof(Node));
    trashNode->data=NULL;
//uso do nó trash: pressupõe que a lista nunca vai estará vazia, o first nunca será nulo
//Dito isso, diferentemente da Lista Simplesmente Ligada não precisamos verificar se a lista está vazia
    trashNode->previous=trashNode;
    trashNode->next=trashNode;
    list->first=trashNode;
    list->size=0;
}

// enqueue by Matheus Santiago, semelhante a lista ligada, este enqueue tem a função de inserir um novo elemento respeitando o conceito de fila.
int enqueue(DoublyLinkedList *list, void *data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode==NULL) return -1; 
	// caso nao haja espaço informa ao usuario
	
	newNode -> data= data; // o novo nó aponta para a data
	newNode -> next = list -> first; //o novo nó avança e a lista aponta para o primeiro
	newNode -> previous = list -> first -> previous; 
	// o novo nó aponta para anterior e a lista aponta para o primeiro que aponta para o anterior	
	list -> first ->previous ->next = newNode;
	list -> first -> previous = newNode;
	// o ultimo nó aponta para o novo nó;
	
	list -> size++; // incrementa a quantidade de elementos na lista
	return 1;
}

// Dequeue (by Carlos Henrique T. Carneiro) Função com objetivo de remover o primeiro elemento da lista, se a lista possuir elementos.
void* dequeue(DoublyLinkedList *list) {
    if (isEmpty(list)) return NULL;   //Retorna valor vazio caso a lista não possua elementos
	Node *trash = list->first;
  	Node *first = list->first->next;
    
	first->next->previous = trash;
    trash->next = first->next;
	
    void *data = first->data;        //dado do nó a ser removido
    
    free(first);     //Libera a memoria
    list->size--;     //Reduz a quantidade de elementos presentes na lista 
    return data;     //Retorna o elemento removido
}

//first (by Gabriel Robert) descobre qual o primeiro dado da lista.
void* first(DoublyLinkedList *list) {
    return list->first->next->data; 
//assim como na "lista simplesmente ligada" o "first" retorna o endereço de memória do dado no primeiro nó,
//porém não contem mais a função "(isEmpty(list))?NULL" para retornar NULL se o endereço estiver Vazio.
}

//last (by José Guilherme Neves), tem a mesma funçao da lista simplesmente ligada, onde retorna o endereço de memoria do ultimo nó
void* last(DoublyLinkedList *list) {
    return list->first->previous->data;
}


//Push por Vinicius Matusita, faz a inserna  inserção do elemento no inicio como na simplesmente ligada, porem com mais 2 ponteiros.
int push(DoublyLinkedList *list, void *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data; 
    
    newNode->next = list->first->next; //novo ó que recebe list, first, next
    newNode->previous = list->first; //previous que recebe list,first que esta apontando para o inicio 
    list->first->next->previous = newNode; // recebe o novo nó
    list->first->next = newNode;
    
    list->size++;
    
    return 1;
}
//top( by Thiago Ramalho) usado somente em pilha, retorna o elemento superior da pilha, ela possui duas funções, retornar o elemento para a parte superior da pilha para permitir modificações, a segunda função é para retornar uma referência constante,com intuito de garantir que não haja modificações acidentaisna pilha.
void* pop (DoublyLinkedList *list) {
	return dequeue(list);
}
void* top (DoublyLinkedList *list){
	return first (list);
}
bool isEmpty(DoublyLinkedList *list) {
	return (list -> size==0);
}

int indexOf(DoublyLinkedList *list,void *data,compare equal) {
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first->next;
    
    while(aux!=list->first && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    
    return (aux==list->first)?-1:count;
}
// GetNodeByPos por Lucio Lisboa, função com o proposito de encontrar um nó em uma posição especifica da lista e retorna-lo. Função identica a de LinkedList
Node* getNodeByPos(DoublyLinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
//condição para checar se a lista esta vazia ou se a posição desejada é superior ao tamanho da lista, caso qualquer uma seja verdadeira, retorna nulo
    
//gera uma copia do ponteiro que aponta o primeiro nó da função na variavel aux
    Node *aux = list->first->next;
//estrutura de repetição que caminha do primeiro nó até a posição desejada ou até o ultimo nó da lista e retorna ele para a função principal
    for (int count=0;(aux!=list->first && count<pos);count++,aux=aux->next);
    return aux;
}

// getpos por Alessandra Mirelle, tem a mesma função que na simplesmente ligada, onde a função retorna o dado e não o endereço do nó.
void* getPos(DoublyLinkedList *list,int pos) {
    Node *res = getNodeByPos(list,pos);
    return (res==NULL)?NULL:res->data;
}

int add(DoublyLinkedList *list, int pos, void *data) {
    Node *aux = getNodeByPos(list, pos);
    if (aux==NULL) return -2;
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    
    newNode->data = data;
    newNode->next = aux;
    newNode->previous = aux->previous;
    
    aux->previous->next = newNode;
    aux->previous = newNode;
    
    list->size++;
    
    return 1;
}

int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource) {
    Node *aux = getNodeByPos(listDest, pos);
    if (aux==NULL) return -2;
    
    if (isEmpty(listSource)) return -1;
    
    listSource->first->previous->next = aux;
    listSource->first->next->previous = aux->previous;
    
    aux->previous->next = listSource->first->next;
    aux->previous = listSource->first->previous;
    
    listDest->size+=listSource->size;
    
    return listSource->size;
}

//removePos (By Wallatan França)  remove um elemento de uma determinada posição
// cria uma função do tipo vazio e ponteiro
void* removePos(DoublyLinkedList *list, int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL; //se a condição for atendida é retornado null
    Node *nodeRemove = getNodeByPos(list, pos); 
//cria uma váriavel auxiliar que vai receber um nó de uma posição da lista
    nodeRemove->previous->next = nodeRemove->next; 
// NodeRemove recebe o próximo nó a ele, e atribui ele como o valor do next do nó anterior a ele
    nodeRemove->next->previous = nodeRemove->previous; // Atribui o valor de previous para o privious do próximo nó
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    
    return dataRemove;
}
int removeData(DoublyLinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
    
    Node *nodeRemove = list->first->next;
    while(nodeRemove!=list->first && !equal(nodeRemove->data,data))
        nodeRemove=nodeRemove->next;
    
    if (nodeRemove!=list->first) {
        nodeRemove->previous->next = nodeRemove->next;
        nodeRemove->next->previous = nodeRemove->previous;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return 1;
    } else {
        return 0;
    }
}

//Exibe os dados de todos os nós da lista;
void show(DoublyLinkedList *list, printNode print) {
    Node *aux = list->first->next;
    while (aux!=list->first) {
        print(aux->data);
        aux=aux->next;
    }
    printf("\n");
}
// Esta função mostra a estrutura em memória da lista duplamente ligada
void showMem(DoublyLinkedList *list) {
    printf("Trash Node: %p\n\n",list->first);
    Node *aux = list->first->next;
    printf("Node Addr  : Previous    - Data        - Next\n\n");
    while (aux!=list->first) {
        printf("%p: %p - %p - %p\n",aux, aux->previous, aux->data, aux->next);
        aux=aux->next;
    }
}
//Compilando sem ERRO
//gcc DoublyLinkedList.c DoublyLinkedList.h DoublyLinkedListTest.c -o teste
//./teste
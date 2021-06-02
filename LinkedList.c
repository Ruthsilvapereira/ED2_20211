//Olá a todos! Estou adiantando a atividade Lista Simplesmente Ligada, conforme video aula disponivel em:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view
//
// Informações sobre Lista Simplesmente Ligada
// Lista Simplesmente Ligada: Alocação dinamica, pode crescer conforme a necessidade.
// Só é possivel avançar em uma Lista Simplesmente Ligada, navegação (unidirecional) sempre para o proximo e nunca voltando. 
// Biblioteca (LinkedList.h) tanto para uso de pilhas e filas
// Pilhas (push, pop, top) e filas (enqueue, dequeue, first, last, isEmpty)
//
//	  Descrição da atividade
//   	LinkedList.h ======> Ruth (postada completa com as operaçoes, conforme proposto no video:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view)
//   	LinkedList.c ======> Ruth (cada um fazer as operaçoes, conforme proposto no video:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view)
//   	LinkedList.c 
//   	Por gentileza coloque o nome a frente da sua escolha de implementação, comente sempre seu nome em tudo que foi feito e detalhe para melhor endendimento dos demais.
//
//		  Divisão da ativiade por alunos, conforme disponivel em:http://www.jppreti.com/2019/07/15/lista-simplesmente-ligada/#LinkedListc e explicado em:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view
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
//   		3.2.13 addAll ======>
//   		3.2.14 removePos ======>Wallatan França
//   		3.2.15 indexOf ======> by Eduardo Hideki and Wenderson Farias
//   		3.2.16 removeData ======> Mickael Luiz Dias da Silva

//LinkedListTest.c ======> Ruth (postada completa com as operaçoes, conforme proposto no video:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view
// Lista Simplesmente Ligada atividade dois da plataforma AVA, será feita em grupo ====>  ou seja, a sala toda vai usar esse mesmo local LinkedList.c e trabalhar em equipe
// inicio ========>  LinkedList.c

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
//init: inicializa a LinkedList, atraves da first e size da estrutura
//first não está apontando para nenhum endereço de memória válido NULL, elementos da lista = 0
void init(LinkedList *list) {
    list->first=NULL;
    list->size=0;
}
//verifica se a lista está ou não vazia
//caso a lista esteja vazia, retorna tamanho igual a zero.
bool isEmpty(LinkedList *list) {
    return (list->size == 0);
}
//enqueue (by Matheus Santiago) insere um novo elemento respeitando o conceito de fila ou seja  sera inserido no final da fila
int enqueue (LinkedList *list, void *data){
	Node *newNode =(Node*) malloc(sizeof(Node)); // reserva um novo espaço na memoria para caber um nó da lista;
		if (newNode == NULL) return -1; // caso não haja espaço, é informado ao usuario 
		newNode -> data = data;
		newNode -> next = NULL; // recebe o NULL pois será o ultimo da lista, logo, sem proximo.
		
		if (isEmpty(list))		// O nó é inserido caso a lista esteja vazia, ele sera o primeiro elemento
			list -> first = newNode;
		else{					// Caso não esteja, descobriremos o ultimo e sera inserido após ele.
			Node *aux = list -> first;
			while (aux-> next != NULL)
				aux = aux -> next;	//auxiliar apontara para o primeiro da lista e avançara até encontrar um nó cujo next seja NULL, em outras palavras até o final da lista.
				aux -> next = newNode;} // ao encontrar é atualizado o valor de next para o endereço do novo nó
	list -> size++; // Incrementa a quantidade de elementos
	return 1;} // e retorna a quantidade de elementos inseridos
	
//top( by Thiago Ramalho) usado somente em pilha, retorna o elemento superior da pilha, ela possui duas funções, retornar o elemento para a parte superior da pilha para permitir modificações, a segunda função é para retornar uma referência constante,com intuito de garantir que não haja modificações acidentaisna pilha.
void* top(LinkedList *list) {
    return first(list);
}
//First (by Gabriel Robert) descobre qual o primeiro dado da lista.
void* first(LinkedList *list) {
    	return (isEmpty(list))?NULL:list->first->data; //retornar NULL se a lista estiver vazia.Se não estiver vazia, retorna o endereço de memória do dado no primeiro nó.
}

// Last (by Jose G. Neves) descobre o ultimo elemento da lista, percorrendo ela a partir do elemento (first) ate encontrar um nó em que o proximo seja (null)
void* last(LinkedList *list) {
    void *data = NULL;
    if (!isEmpty(list)) {      //verifica se a lista nao esta vazia
        Node *aux = list->first;  //variavel auxiliar aponta para o primeiro nó
        while (aux->next != NULL)  //enquanto o nó seguinte nao for o ultimo (null)
            aux = aux->next;   //a auxiliar vai varrendo e verificano os proximos 
        data = aux->data;   //até encontrar e receber o endereço de memoria do dado do ultimo nó
    }
    return data;
}

// Dequeue (by Carlos Henrique T. Carneiro) Função com objetivo de remover o primeiro elemento da lista, se a lista possuir elementos.
void* dequeue(LinkedList *list) {
    if (isEmpty(list)) return NULL;    //Retorna valor vazio caso a lista não possua elementos
	
    Node *trash = list->first;       //variável que guarda o endereço do nó que será removido
    list->first = list->first->next;      //O segundo elemento da lista passa a ser o primeiro
    void *data = trash->data;        //dado do nó a ser removido
    
    free(trash);     //Libera a memoria
    list->size--;     //Reduz a quantidade de elementos presentes na lista 
    return data;     //Retorna o elemento removido
}

//Push (by Vinicius Matusita) a inserção do elemento é feita no topo da lista(inicio da lista).
int push(LinkedList *list, void *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty(list))               //verifica se a lista estiver vazia
        list->first = newNode;       //o first passa a novo nó é o primeiro
    else {
        newNode->next = list->first; //passa o topo atual para o segundo da lista
        list->first = newNode;       //o first passa a novo nó será o topo
    }
    list->size++;
    return 1;
}

//GetNodeByPos (by Lucio Lisboa) Função com intuito de buscar o endereço de um no na lista
Node* getNodeByPos(LinkedList *list, int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;

    Node *aux = list->first;

    for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    return aux;
}

//getPos (by Alessandra Mirelle) Função que retorna o dado e não o endereço do nó.
void* getPos(LinkedList *list, int pos) {
    Node *aux = getNodeByPos(list,pos);
    if (aux==NULL) 
        return NULL;
    else
        return aux->data;
}


//removePos (by Wallatan França)
void* removePos(LinkedList *list, int pos){


}

//removeData (by Mickael Luiz)
//Função que remove algum dado da lista
bool removeData(LinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
//Essa etapa verifica se o dado a ser removido é o primeiro da lista e o remove se for.
Node *nodeRemove = NULL;
if (equal(list->first->data,data)){
    nodeRemove = list->first;
    list->first = list->first->next;
    free(nodeRemove->data); 
    free(nodeRemove);
    list->size--;
    return true;
}
else {
	//essa etapa procura o dado para remover de nó em nó até o fim da lista
        Node *aux = list->first;
        while(aux->next!=NULL && !equal(aux->next->data,data)) {
            aux=aux->next;
	
        if (aux->next!=NULL) {
            Node *nodeRemove = aux->next;
            aux->next = nodeRemove->next;
            free(nodeRemove->data);
            free(nodeRemove);
            list->size--;
            return true;
        }
	else {
            return false;
        }
    	}
}
// BY: GUILHERME MENDES
int add(LinkedList *list, int pos, void *data) { // Função permite adicionar um único dado a determinada posição da lista
    if (pos <= 0) return push(list,data);
    Node *aux = getNodeByPos(list, (pos-1));     // Função auxiliar responsavel por localizar nó da posição anterior da posição que iremos inserir
    if (aux==NULL) return -2;
    
    Node *newNode = (Node*) malloc(sizeof(Node));// Retorna -2 para informar que a posição informada é inválida
    if (newNode==NULL) return -1;
    
    newNode->data = data;
    newNode->next = NULL;
    
    newNode->next = aux->next;                    //Rensponsável por inserir o nó dentro da lista
    aux->next = newNode;
    
    list->size++;
    
    return 1;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource) { // Adiciona tudo --- By : Hans Maciel
    if (listDest==NULL || isEmpty(listDest)) return -1; // verifica se essas listas possuem elementos para que faça sentido a inserção de uma em outra
    if (listSource==NULL || isEmpty(listSource)) return -2;
    Node *last = NULL; // verifica se a posição a ser inserida é o início (pos==0)
    for (last = listSource->first;last->next!=NULL;last=last->next); // se for, teremos que atualizar a variável first de nosso struct LinkedList
    if (pos == 0) {  // o último nó de nossa lista de origem apontará para o nó que era o first inicialmente
        last->next = listDest->first; 
        listDest->first = listSource->first;
    } else { // Caso a posição a ser inserida não for a de início, precisaremos localizar o nó anterior a posição desejada.
        Node *aux = getNodeByPos(listDest, (pos-1)); 
        if (aux==NULL) return -3;        
        last->next = aux->next; 
        aux->next = listSource->first;
    }
    listDest->size+=listSource->size; //Ao final, basta incrementarmos a quantidade de elementos da lista de destino com a quantidade de elementos da lista de origem e retornar essa quantidade de elementos novos inseridos
    return listSource->size;
}

int indexOf(LinkedList *list, void *data, compare equal) { //retorna a posicao da lista de um determinado elemento, by Eduardo Hideki and Wenderson
    if (isEmpty(list)) return -1; //verifica se a lista esta vazia, se estiver vazia ele retorna -1
    int count=0; //variavel contadora para as posicoes da lista
    Node *aux = list->first; //variavel auxiliar para navegar na lista
	
	while(aux!=NULL && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    
    return (aux==NULL)?-1:count;
}

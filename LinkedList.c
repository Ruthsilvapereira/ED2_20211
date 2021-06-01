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
//   		3.2.6 dequeue ======>
//   		3.2.7 pop ======>
//   		3.2.8 top ======>
//   		3.2.9 push ======>
//   		3.2.10 getNodeByPos ======>Lucio Lisboa
//   		3.2.11 getPos ======>
//   		3.2.12 add ======>
//   		3.2.13 addAll ======>
//   		3.2.14 removePos ======>
//   		3.2.15 indexOf ======>
//   		3.2.16 removeData ======>

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
//GetNodeByPos (by Lucio Lisboa) Função com intuito de buscar o endereço de um no na lista
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
//   		3.2.3 enqueue ======>
//   		3.2.4 first ======>
//   		3.2.5 last ======>
//   		3.2.6 dequeue ======>
//   		3.2.7 pop ======>
//   		3.2.8 top ======>
//   		3.2.9 push ======>
//   		3.2.10 getNodeByPos ======>
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
//Lista generalizadas by Matheus Santiago e Thiago Ramalho
#include <stdlib.h>
#include <stdio.h>

enum elem_t {tipo_int, tipo_char, tipo_sublista};

union info_lista {
  int i;
  char c;
  struct No* sublista;
};

typedef struct No {
  enum elem_t tipo;
  union info_lista info;
  struct No* prox;
} No;


// Conta atomos utilizando dupla recursao 
int conta_atomos (No* l) {
  if (l == NULL)
    return 0;
  else
    if (l->tipo == tipo_int || l->tipo == tipo_char)
      return 1 + conta_atomos(l->prox);
    else
      return  conta_atomos(l->info.sublista)
	+ conta_atomos(l->prox);}


// Conta atomos utilizando recursao simples
int conta_atomos_2 (No* l) {
  int c = 0;
  while (l != NULL) {
    if (l->tipo == tipo_int || l->tipo == tipo_char)
      c++;
    else
      c += conta_atomos_2(l->info.sublista);
    l = l->prox;
  }
  return c;}


int iguais (No* l1, No* l2) {
  return 0;}

// Imprime com parenteses

void imprime(No* l) {
  printf("(");
  while(l!=NULL) {
    switch(l->tipo){
    case tipo_int:
      printf("%d", l->info.i);
      break;
    case tipo_char:
      printf("%c", l->info.c);
      break;
    case tipo_sublista:
      imprime(l->info.sublista);
      break;
    }
    l = l->prox;
    if (l != NULL)
      printf(", ");
  }
  printf(")");}


No* concat(No* ap_elem, No* ap_lista) {
  ap_elem->prox = ap_lista;
  return ap_elem;}

No* atomo(int i) {
  No* n = (No*) malloc (sizeof(No));
  n->info.i = i;
  n->tipo = tipo_int;
  return n;}

No* sublista(No* sublista) {
  No* n = (No*) malloc (sizeof(No));
  n->info.sublista = sublista;
  n->tipo = tipo_sublista;
  return n;}


No* copia(No* p) {  
  if (p == NULL)
    return NULL;
  No* n = (No*) malloc (sizeof(No));
  n->tipo = p->tipo;
  switch(p->tipo){
    case tipo_int:
      n->info.i = p->info.i;
      break;
    case tipo_char:
      n->info.c = p->info.c;
      break;
    case tipo_sublista:
      n->info.sublista = copia(p->info.sublista);
      break;}
  n->prox = copia(p->prox);
  return n;}


/* 
  Monta uma lista ligada a partir de uma string do tipo ((3),5,(6,8),9)
  lida da entrada padrao.
*/ 
No* cria_lista_padrao () {
  return NULL;
}

/* 
  Monta uma lista generalizada a partir de uma string do tipo ((3),5,(6,8),9)
  passada como parametro.
 */  
No* cria_lista (char* str) {
  return NULL;}

int main() {
  // Monta a lista (1) 
  No* l0 = concat(atomo(1), NULL);
  
  // Monta a lista ((1,2)) 
  No* l1 = concat(atomo(1), concat(atomo(2), NULL));
  l1 = concat(sublista(concat(atomo(1), concat(atomo(2), NULL))), NULL);

  // Monta a lista (1,(2,3)) 
  No* l2 = 
    concat(atomo(1), 
	   concat(sublista(concat(atomo(2), concat(atomo(3), NULL))),
		  NULL));

  /* Como montar a lista
     (1,(2,3),4,5,(6,(7,8))) ? */


  /* ((3,5),8,((9),10)) */


  /* ((9),10) */

  No* l3 = concat(atomo(9),NULL); /* (9) */
  No* l4 = concat(sublista(l3),
		  concat(atomo(10), NULL));
  No* l5 = concat(atomo(3),
		  concat(atomo(5),NULL));
  No* l6 = concat(sublista(l5),
		  concat(atomo(8),
			 concat(sublista(l4),NULL)));
  imprime(l6);

  return 0;}
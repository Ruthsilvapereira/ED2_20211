//Operações
//isHashEmpty: verifica se a tabela de hash está vazia;
//hash: calcula o hash para a chave;
//put: insere um par (chave,valor);
//containsKey: verifica se a chave já existe na tabela de hash;
//get: retorna o valor buscando pela chave;
//removeKey: remove um par (chave,valor);
//showHashStruct: exibe os pares armazenados

#ifndef EstruturaDeDados_Hash_h
#define EstruturaDeDados_Hash_h

#include "DoublyLinkedList.h"

#define MAX 10

typedef struct HashStruct {
    DoublyLinkedList hashes[MAX];
    int size;
}HashStruct;

void initHash(HashStruct *hashStruct);
bool isHashEmpty(HashStruct *hashStruct);
int hash(char *key);
int put(HashStruct *hashStruct, char *key, void *data, compare equal);
bool containsKey(HashStruct *hashStruct, char *key, compare equal);
void* get(HashStruct *hashStruct, char *key, compare equal);
void* removeKey(HashStruct *hashStruct, char *key, compare equal);
void showHashStruct(HashStruct *hashStruct, printNode print);
#endif

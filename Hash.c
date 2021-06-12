//Olá a todos! Estou adiantando a atividade Hash do AVA
//Por gentileza coloque o nome a frente da sua escolha de implementação, comente sempre seu nome em tudo que foi feito e detalhe para melhor endendimento dos demais.

//       5.2.1 initHash ======> Ruth
//       5.2.2 hash
//       5.2.3 containsKey
//       5.2.4 put
//       5.2.5 get
//       5.2.6 removeKey
//       5.2.7 showHashStruct

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

//Inicio
//Nesta função de inicialização iremos percorrer cada posição de nossa tabela de hash inicializando a lista duplamente ligada de cada posição (Definição em http://www.jppreti.com/2019/07/29/tabela-hash/#Hashh)

void initHash(HashStruct *hashStruct) {
    for (int i=0;i<MAX;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
}

bool isHashEmpty(HashStruct *hashStruct) {
    return hashStruct->size==0;
}

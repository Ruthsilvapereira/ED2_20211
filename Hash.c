//Olá a todos! Estou adiantando a atividade Hash do AVA
//Por gentileza coloque o nome à frente da sua escolha de implementação, comente sempre seu nome em tudo que foi feito e detalhe para melhor entendimento dos demais.
//Tabela Hash
//Sem varrer todas as chaves ou posições, a tabela hash consegue localizar a posição em que o elemento se encontra.
//Função de hash: é a fórmula de matemática que está sendo usada
//Tabela de hash: é o vetor (tabela com todos os valores, resultado da função de hash)
//Tratamento de colisões em hash: usou no exemplo a Lista Simplesmente ligada para tratamento das colisões
//Hash: pode ser usado para criptografia, verificação de integridade do dado (saber se não foi alterado/modificado)
//Hash: não aceita dados duplos (exemplo: nome do aluno, nome do aluno) 
//       Funções Hash a ser implementada
//       5.2.1 initHash ======> Ruth
//       5.2.2 hash ======>
//       5.2.3 containsKey ======>
//       5.2.4 put ======>
//       5.2.5 get ======>
//       5.2.6 removeKey ======>
//       5.2.7 showHashStruct ======>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

//Inicio
//Nesta função de inicialização iremos percorrer cada posição de nossa tabela de hash inicializando a lista duplamente ligada de cada posição (Definição em http://www.jppreti.com/2019/07/29/tabela-hash/#Hashh)
//init usado é o da DoublyLinkedList, Lista Duplamente Ligada.

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

//Comandos para compilar codigo completo no goormIDE (Disponivel em: http://www.jppreti.com/2019/07/29/tabela-hash/#Biblioteca)
//gcc DoublyLinkedList.c Hash.c Hash.h DoublyLinkedList.h HashTest.c -o teste1234
//./teste1234
//OBSERVAÇÃO: Usar o .h e .c da DoublyLinkedList no comando (DoublyLinkedList.h HashTest.c), pois na biblioteca da Hash tem o include de DoublyLinkedList
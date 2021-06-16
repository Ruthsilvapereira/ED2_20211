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
//       5.2.2 hash ======> Matheus Santiago
//       5.2.3 containsKey ======> Leandro Klein
//       5.2.4 put ======> Wenderson Farias
//       5.2.5 get ======> Carlos Henrique Teixeira Carneiro
//       5.2.6 removeKey ======> Wallatan França / Mickael Luiz
//       5.2.7 showHashStruct ======> Lucio Lisboa

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
// hash (by Matheus Santiago) : Recebe uma chave e calcula qual posição deveremos inserir o dado associado a chave. A chave pode ser um nome, numero ou codigo de barras, normalmente é um dado unico.
int hash(char *key){
	int sum = 0;
	for (int i =0; key[i] != 0;  i++){  // percorre todos os caracteres da string passada
// Acumula os códigos ascii de cada letra com um peso, perceba que o codigo ascii é multiplicado por um peso baseado em sua posição. Caso contrário a palavra "ALO" e "OLA" teriam o mesmo codigo de hash
		sum += key[i]*(i+1); } 
	return sum%MAX; } // retorna o resto da divisão 

// containsKey (by Leandro Klein) : verificar se a chave já existe na tabela de hash.
bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    //calcula a posição
    int hashValue = hash(key);//função para descobrir em que lista está a chave.
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); //A função indexOf retorna a posição da chave na lista. Caso o retorno seja -1 a chave não está na lista.
    
    return (pos!=-1)?true:false;
}

// put by Wenderson Farias / verifica se a chave ja foi inserida na tabela
//                         / caso nao, então é inserido um novo elemento na tabela.
int put(HashStruct *hashStruct, char *key, void *data, compare equal)  {
    if (!containsKey(hashStruct, key, equal) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    return 0;
}

//Função get by Carlos Henrique: Reqaliza busca no codigo e retorna o dado procurado, se não houverem dados retorna o primeiro nó (sentinela) de valor nulo.
void* get(HashStruct *hashStruct, char *key, compare equal) {
    // descobre em qual fila/lista está o dado
    int hashValue = hash(key);
    //first é nó sentinela, começamos do segundo nó
    Node *aux = hashStruct->hashes[hashValue].first->next;
    // procuramos o dado na lista
    while(aux!=hashStruct->hashes[hashValue].first && !equal(aux->data, key))
        aux=aux->next;
    return aux->data;
}	

//Função removeKey (by Wallatan França / Mickael Luiz)	remove um par (chave, valor)
void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);// após calcular o hash da chave enviada, atribui o valor a váriavel do tipo hashValue
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);// a váriavel pos tipo int, recebe a posição encontrada por indexOf com base nos parâmetros passados
	//remove o valor da posição
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
	//Verifica se é o unico nó da lista, se nao for, diminui um valor de size em 1
    if (result!=NULL) hashStruct->size--;
    return result;
}

//função ShowHashStruct por Lucio Lisboa. Função com o proposito de exibir os pares armazenados, ou seja, mostra quantos hash tem e quantos elementos cada hash tem
void showHashStruct(HashStruct *hashStruct, printNode print) {
    //printf mostrando na tela quantos elementos a hash tem
    printf("There are %d elements in the Hash\n\n",hashStruct->size);
    //estrutura de repetição com o intuito de navegar entre as hashes e mostrar quantos elementos cada hash tem
    for (int i=0; i < MAX; i++) {
        printf("Hash %d has %d elements: ",i,hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i],print);
        printf("\n");
    }
}
//Comandos para compilar codigo completo no goormIDE (Disponivel em: http://www.jppreti.com/2019/07/29/tabela-hash/#Biblioteca)
//gcc DoublyLinkedList.c Hash.c Hash.h DoublyLinkedList.h HashTest.c -o teste1234
//./teste1234
//OBSERVAÇÃO: Usar o .h e .c da DoublyLinkedList no comando (DoublyLinkedList.h HashTest.c), pois na biblioteca da Hash tem o include de DoublyLinkedList

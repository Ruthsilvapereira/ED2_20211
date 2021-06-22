//Olá a todos! Estou adiantando a atividade Blockchain do AVA
//Por gentileza coloque o nome à frente da sua escolha de implementação, comente sempre seu nome em tudo que foi feito e detalhe para melhor entendimento dos demais.
//=======================================================================================================================
//Definir o que é Blockchain ==========> 
//initBlockchain ==========> Ruth
//hash_to_string ==========> Matheus Santiago
//calculateHash ==========> 
//calculateBlockHash ==========> 
//generateNextBlock ==========> Wenderson Farias
//getLatestBlock ==========> 
//isValidNewBlock ==========> Lucio Lisboa
//isBlockchainValid ==========> Jose Guilherme
//addBlock ==========> Gabriel Robert
//Incluir testes em ponteiro/BlockchainTest.c ==========> 
//=======================================================================================================================
//Atenção: para rodar a Blockchain sem alteração, conforme exemplo em: http://www.jppreti.com/2019/08/05/blockchain/
//é necessário:
//sha256.c e sha256.h (incluída por Ruth)
//Disponivel em: https://github.com/983/SHA-256/blob/main/sha256.c e https://github.com/983/SHA-256/blob/main/sha256.h
//Comando goormIDE para rodar comandos completos de http://www.jppreti.com/2019/08/05/blockchain/
//gcc Blockchain.h BlockchainTest.c Blockchain.c -o Blockchain
//./Blockchain
//ou então: 
//gcc Blockchain.h BlockchainTest.c Blockchain.c sha256.h sha256.c -o Blockchain
//=======================================================================================================================
//Definir o que é Blockchain ==========> 
//
//=======================================================================================================================
//Seguimos com a Blockchain.c, início 
#include "Blockchain.h"
#include <string.h>
#include "sha-256.h"
#include <time.h>

//initBlockchain ==========> Ruth
//void initBlockchain(Blockchain *blockchain) {
  
//}


//hash_to_string (by Matheus Santiago) : Procedimento que transforma um hash de 32 bytes em uma string de 64 characteres: 
static void hash_to_string(char string [65], const uint8_t hash[32]){
	size_t i; // monta uma string com 64 caracteres hexadecimais
	for (i=0; i< 32; i++){
		// 2x hexadecimal em 2 caracteres
		string += sprintf(string,"%02x", hash[i]);}
}


//calculateHash



//calculateBlockHash



// generateNextBlock by Wenderson Farias -- Esta função gera um novo bloco
// usando o hash do bloco anterior e a data definida pelo usuario.
Block* generateNextBlock(Blockchain *blockchain, float data) {
    //pegamos uma referência ao último bloco da lista
    Block *previousBlock = getLatestBlock(blockchain);
    Block *newBlock = (Block*)malloc(sizeof(Block));
    
    newBlock->data = data;
    newBlock->previousHash = previousBlock->hash;
    newBlock->index = previousBlock->index+1;
    //pegamos a data e hora atual
    newBlock->timestamp = time(NULL);
    //calculamos o hash do novo bloco
    newBlock->hash = calculateBlockHash(newBlock);
    
    return newBlock;
}



//Função IsValidNewBlock por Lucio Lisboa. Função com o intuito de validar a integridade de um unico bloco
bool isValidNewBlock(Block* newBlock, Block* previousBlock) {
    //Condição para checar se o index do bloco anterior é diferente do bloco atual, se for retorna false
    if (previousBlock->index + 1 != newBlock->index) {
        return false;
    //Condição para checar se a hash do bloco anterior é diferente do bloco atual, se for retorna false
    } else if (previousBlock->hash != newBlock->previousHash) {
        return false;
    //Condição para comparar a string criada a partir da hash do novo bloco com a string do bloco que atualmente é o novo bloco, se forem distintos retonar false
    } else if (strcmp(calculateBlockHash(newBlock),newBlock->hash)!=0) {
        return false;
    }
    //Se nenhuma das condições anteriores forem atendidas, o novo bloco foi validado e retorna true
    return true;
}

//isBlockchainValid (by Jose Guilherme) : Faz a validacao da integridade da cadeia de blocos (blockchain)
bool isBlockchainValid(Blockchain *blockchain) {
    Block *aux = getLatestBlock(blockchain);// bloco aux recebe o ultimo bloco da blockchain
    while (aux!=blockchain->genesisBlock) { 
        if (!isValidNewBlock(aux, aux->previousBlock)) // chama a funcao de validacao do bloco, com o bloco auxiliar e o anterior a esse
            return false;
        aux = aux->previousBlock;
    }
    return true;
}


//addBlock (by Gabriel Robert) : adiciona um novo bloco.
int addBlock(Blockchain *blockchain, Block *newBlock) {
    if (isValidNewBlock(newBlock, getLatestBlock(blockchain))) { // faz a validação, valida o bloco novo e pega a ultima posição do blockchain.
        newBlock->previousBlock = getLatestBlock(blockchain); // função que faz a troca de posição e libera a ultima posição do blockchain.
        blockchain->latestBlock = newBlock; // a ultima posição do blockchain recebe o bloco novo.
        return 1; //se os requisitos for atendidos retorna 1.
    }
    return -1; //se não retorna menos -1.
}


//getLatestBlock

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
//isValidNewBlock ==========> Gabriel Robert
//isBlockchainValid ==========> Jose Guilherme
//addBlock ==========> 
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



//isValidNewBlock



//isBlockchainValid (by Jose Guilherme) : Faz a validacao da integridade da cadeia de blocos (blockchain)
bool isBlockchainValid(Blockchain *blockchain) {
    Block *aux = getLatestBlock(blockchain);// bloco aux recebe o ultimo bloco da blockchain
    while (aux!=blockchain->genesisBlock) {
        if (!isValidNewBlock(aux, aux->previousBlock))
            return false;
        aux = aux->previousBlock;
    }
    return true;
}


//addBlock



//getLatestBlock

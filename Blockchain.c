//Olá a todos! Estou adiantando a atividade Blockchain do AVA
//Por gentileza coloque o nome à frente da sua escolha de implementação, comente sempre seu nome em tudo que foi feito e detalhe para melhor entendimento dos demais.
//=======================================================================================================================
//Definir o que é Blockchain ==========> 
//initBlockchain ==========> Ruth
//hash_to_string ==========> 
//calculateHash ==========> 
//calculateBlockHash ==========> 
//generateNextBlock ==========> Wenderson Farias
//getLatestBlock ==========> 
//isValidNewBlock ==========> 
//isBlockchainValid ==========> 
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


//hash_to_string



//calculateHash



//calculateBlockHash



// generateNextBlock by Wenderson Farias -- Esta função gera uma novo bloco
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



//isBlockchainValid



//addBlock



//getLatestBlock

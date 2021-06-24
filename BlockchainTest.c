//Olá a todos!
//Teste as funções e caso sua tentativa não rodar direito, deixa ela inativada em comentário // para que o colega tente fazer rodar corretamente.
//BlockchainTest.c é feita de forma colaborativa
//No demais, seguimos conforme as anteriores, atenciosamente: Ruth
#include "Blockchain.h"

int main() {
    Blockchain blockchain;
    //printf("");
    initBlockchain(&blockchain);
    printf("%s\n",blockchain.genesisBlock->hash);
    printf("%lu\n",blockchain.genesisBlock->timestamp);
    
    Block *newBlock2 = generateNextBlock(&blockchain,80.0);
    addBlock(&blockchain, newBlock2);
    
    Block *newBlock3 = generateNextBlock(&blockchain,250.0);
    addBlock(&blockchain, newBlock3);

    Block *newBlock4 = generateNextBlock(&blockchain,333.0);
    addBlock(&blockchain, newBlock4);
    
    Block *newBlock5 = generateNextBlock(&blockchain,45.0);
    addBlock(&blockchain, newBlock5);

    Block *newBlock6 = generateNextBlock(&blockchain,12.0);
    addBlock(&blockchain, newBlock6);

    Block *newBlock7 = generateNextBlock(&blockchain,22.0);
    addBlock(&blockchain, newBlock7);

    printf("Block 4 is valid? %i\n",isValidNewBlock(newBlock4, blockchain.genesisBlock));
    //newBlock2->data = 74.00;

    printf("Block 5 is valid? %i\n",isValidNewBlock(newBlock5, blockchain.genesisBlock));

    printf("Block 6 is valid? %i\n",isValidNewBlock(newBlock6, blockchain.genesisBlock));

    printf("Block 7 is valid? %i\n",isValidNewBlock(newBlock7, blockchain.genesisBlock));

    printf("Blockchain is valid? %i\n",isBlockchainValid(&blockchain));
    printf("size: %u\n",blockchain.latestBlock->index);
    return 0;


}
//Precisamos da sha256.c e sha256.h na Blockchain, ambas incluida completa. By Ruth

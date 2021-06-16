#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
typedef struct Cliente {
    char nome[50];
    char email[50];
	char cpf[50];
	
}Cliente;
bool comparaChaves(void *key, void *data) {
    char *chave = (char*)key;
    Cliente *c = (Cliente*)data;
    
    return (strcmp (chave, c->email) == 0)?true:false;
}
void printCliente(void *data) {
    Cliente *cliente = (Cliente*)data;
    printf("{%s,%s,%s} - ", cliente->nome, cliente->email, cliente->cpf);
}
int main() {
    HashStruct hashes;
    initHash(&hashes);
    printf("%d\n",hash("joao.preti@cba.ifmt.edu.br"));
    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Joao Paulo") ;
    strcpy(c->email,"joao.preti@cba.ifmt.edu.br");
	strcpy(c->cpf,"011.111.111-11");
    printf("%d\n",hash(c->email));
    put(&hashes, c->email, c, comparaChaves);
    printf("%d\n",hashes.hashes[hash("joao.preti@cba.ifmt.edu.br")].size);
    printf("%d\n",hashes.size);
    printf("%d\n",containsKey(&hashes, "joao.preti@cba.ifmt.edu.br", comparaChaves));
    
    Cliente *cliente = (Cliente*)get(&hashes, "joao.preti@cba.ifmt.edu.br", comparaChaves);
    printf("%s\n",cliente->nome);
    
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Maria") ;
    strcpy(c->email,"maria@email.br");
	strcpy(c->cpf,"022.222.222-22");
    put(&hashes, c->email, c, comparaChaves);
    
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Pedro") ;
    strcpy(c->email,"pedro@email.com.br");
	strcpy(c->cpf,"033.333.333-33");
    put(&hashes, c->email, c, comparaChaves);
    
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Carla") ;
    strcpy(c->email,"carla@gmail.com.br");
	strcpy(c->cpf,"044.444.444-44");
    put(&hashes, c->email, c, comparaChaves);
	
	c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Ruth") ;
    strcpy(c->email,"ruthsilva1994@gmail.com.br");
	strcpy(c->cpf,"055.555.555-55");
    put(&hashes, c->email, c, comparaChaves);
	
	c = (Cliente *)malloc(sizeof(Cliente));
	strcpy(c->nome,"Matheus");
	strcpy(c->email,"matheus.ssantiag@gmail.com.br");
	strcpy(c->cpf,"066.666.666-66");
	put(&hashes, c->email, c,comparaChaves);
       
       c = (Cliente *)malloc(sizeof(Cliente));
	strcpy(c->nome,"Hans");
	strcpy(c->email,"hans_maciel@hotmail.com");
	strcpy(c->cpf,"077.777.777-77");
	put(&hashes, c->email, c,comparaChaves);
	
	c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Jose Guilherme") ;
    strcpy(c->email,"joseguilhermesn@gmail.com");
	strcpy(c->cpf,"088.888.888-88");
    put(&hashes, c->email, c, comparaChaves);
    
        c = (Cliente *)malloc(sizeof(Cliente));
	strcpy(c->nome,"Eduardo");
	strcpy(c->email,"edu-hideki@hotmail.com");
	strcpy(c->cpf,"888.888.888-88");
	put(&hashes, c->email, c,comparaChaves);
	
	c = (Cliente *)malloc(sizeof(Cliente));
   	strcpy(c->nome,"Gabriel Robert") ;
   	strcpy(c->email,"gabrielrobert46@gmail.com.br");
	strcpy(c->cpf,"099.999.999-99");
  	put(&hashes, c->email, c, comparaChaves)

    c = (Cliente *)malloc(sizeof(Cliente));
	strcpy(c->nome,"Guilherme Mendes");
	strcpy(c->email,"guiaoms@gmail.com");
	strcpy(c->cpf,"055.382.485-72");
	put(&hashes, c->email, c,comparaChaves);

    c = (Cliente *)malloc(sizeof(Cliente));
	strcpy(c->nome,"Leandro");
	strcpy(c->email,"klein.leandro@outlook.com");
	strcpy(c->cpf,"101.111.010-11");
	put(&hashes, c->email, c,comparaChaves);
  
    showHashStruct(&hashes, printCliente);
    return 0;
}
 
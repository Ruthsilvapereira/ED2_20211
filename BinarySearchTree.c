//Árvore Binária de Busca
//Anteriormente vimos Hash
//Hash: busca com a chave completa
//Veremos agora uma forma diferente de BUSCA (Árvore de Busca)
//Árvore de Busca: busca tranquilamente por intervalo, pois está em ordem. 
//Árvore: POSSUI O NÓ RAIZ (NÓ PAI), TEM APENAS UM. Seus decedentes são sub-arvores (NÓ FILHOS)
//Grau de NÓ: quantidade de filhos (SUB-ARVORES)
//NÓ FOLHA: GRAU DE NÓ=0 
//Árvore Binária de Busca: usamos conceitos já visto, Ponteiros, Lista e Hash
//Árvore Binária: permite busca em varias direcoes, depende da forma que usar os ponteiros (Bidirecional)

//Visualizador online de Árvore Binária de Busca
//Disponivel em: https://www.cs.usfca.edu/~galles/visualization/BST.html
//teste nesse site permite uma visualização do comportamento da Árvore de Busca

// Deixe seu nome na função implemantada e comente tudo para melhor entendimento dos demais.
//		add =======> Ruth
//              find ======> Wenderson Farias
//              in_order ======> Leandro Klein
//              pre_order ======> Matheus Santiago
//              post_order ======> Carlos Henrique Teixeira Carneiro
//              greaterRight ======> Wallatan França
//              smallerLeft ======> Thiago Ramalho
//              removeTreeNode ======> Lucio Lisboa
//              height ======>  Alessandra Mirelle, Vinicius Matusita
//              destroy ======>José Guilherme, Gabriel Robert

//Incluir testes em ponteiro/BinarySearchTreeTest.c ==========> Guilherme Mendes, Hans Maciel
//============================================================================================================

//Duplas para proxima atividade: 

//Implementação em Dupla de trabalho valendo 40% da nota final que envolve o estudo e implementação sobre:

// Lista Generalizada (autocomplete)
// Gráfico de espalhamento da tabela hash
// Árvore para compressão de dados
// Árvore de Busca Balanceada (AVL)
// Árvore Rubro-negra
// Árvore B

//Duplas: Ruth e (deixe seu nome, caso tenha interesse)
//Duplas: Vinicius e Alessandra Mirelle 
//Duplas: Gabriel Robert e José guilherme
//Duplas:
//Duplas: 
//Duplas: Guilherme Mendes, Hans Maciel

//============================================================================================================

//Inicio: Árvore Binária de Busca (.c)

//biblioteca

#include "BinarySearchTree.h"

//Começando a nossa Árvore Binária de Busca
//função add em Árvore Binária de Busca: adiciona um novo elemento na árvore
//root: raiz 
// * : ponteiro
//usamos ponteiro e estruturas vistas anteriores na aplicação da Árvore Binária de Busca
int add(TreeNode **root, void *element, TreeComparator f) {
    if ((*root) == NULL) {
        // alcançou o local da folha, atualiza o pai
        TreeNode *newnode = (TreeNode *) malloc(sizeof(TreeNode));
        if (newnode == NULL)
            return 0;
        newnode->element = element;
        newnode->left = newnode->right = NULL;
        *root = newnode;
        return 1;
    }
    
    int compvalue = f(element, (*root)->element);
    if (compvalue > 0) {
        return add(&(*root)->right, element, f);
    } else if (compvalue < 0) {
        return add(&(*root)->left, element, f);
    } else {
        return -1;
    }
    
}

// find by Wenderson Farias // esta função procura um dado na árvore, precisa de 4 elementos para funcionar
//sendo eles 'root, 'key', 'f', e 'element'.
int find(TreeNode *root, void *key, TreeComparator f, void **element) {
    int compvalue;
    
    // Passamos a folha
    if (root == NULL)
        return 0;
    
    compvalue = f(key, root->element);
    if (compvalue == 0) {
        // encontrado
        *element = root->element;
        return 1;
    }
    
    // desce no nível da árvore
    if (compvalue > 0)
        return find(root->right, key, f, element);
    
    return find(root->left, key, f, element);
}


//in_order by Leandro Klein - é passado o nó raiz, se nao encontrar nulo, a funçao é chamada novamente para esquerda, indo por este caminho até encontrar nulo. 
//Quando não tiver mais a esquerda, imprime o nó.
void in_order(TreeNode *root, printNode print) {
    if (root!=NULL) {
        in_order(root->left, print);
        print(root->element);
        in_order(root->right, print);
    }
}



//void pre_order by Matheus Santiago : imprime os elementos raiz esquerda direita, é passado o nó raiz, caso nao encontre nulo, imprimo o nó e caminha para esquerda e direita.
void pre_order(TreeNode *root, printNode print){
	if (root !=NULL){
		print(root->element);
		pre_order(root->left,print);
		pre_order(root->right,print);}}


//void post_order by Carlos Henrique Teixeira Carneiro : Passa o nó raiz, caso não encontre valor nulo, caminha para a esquerda e para a direita e imprime o nó.
void post_order(TreeNode *root, printNode print) {
    if (root!=NULL) {
        post_order(root->left, print);
        post_order(root->right, print);
        print(root->element);
    }
}

//TreeNode *greaterRight (by Wallatan França)

TreeNode *greaterRight(TreeNode **no){
    if((*no)->right != NULL)
        return greaterRight(&(*no)->right);
    else{
        TreeNode *aux = *no;
        if((*no)->left != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
            *no = (*no)->left;
        else
            *no = NULL;
        return aux;
    }
}


//TreeNode *smallerLeft


//Função removeTreeNode por Lucio Lisboa. Função com intuito de remover um nó da arvoré
int removeTreeNode(TreeNode **root, void *key, TreeComparator f) 


//função int height por Alessandra Mirelle, Vinicius Matusita. Função com intuito de ver a altura da arvore. 
int height (TreeNode *root) {
    if (root == NULL)
        return -1; // altura da árvore estando vazia.
    else {
        int hl = height(root->left); //Calcula a altura da arvore para esquerda
        int hr = height(root->right); //Calcula a altura da arvore para direita
        if (hl < hr) return hr + 1;
        else return hl + 1;
    }
}


// void destroy (by Gabriel Robert, José Guilherme)
//navegar em pos-ordem
void destroy (TreeNode **root) {
    if (*root==NULL) return; // se (*root==NULL) for verdadeiro, quer dizer que alcaçamos a extremidade da árvore.
    destroy(&(*root)->left);// destroy(&(*root) recebe o left em recursivade.
	
 destroy(&(*root)->right);
    free(*root);
    *root=NULL;
}

	//função smallerLeft (Thiago Ramalho) ela é usada com a ideia de pré-calcular a contagem de elementos menores consecutivos à esquerda e à direita para cada elemento existente na matriz, significa que se um elemento à esquerda desse elemento também seram menores que o elemento atual
if (arr [i-1] <arr [i])
    smallLeft [i] = menorLeft [i-1] + 1

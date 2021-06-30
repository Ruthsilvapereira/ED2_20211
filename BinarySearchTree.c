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
//              smallerLeft ======> RUTH (30/06)
//              removeTreeNode ======> Lucio Lisboa
//              height ======> RUTH (30/06)
//              destroy ======> RUTH (30/06)

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
//Duplas: 
//Duplas: 
//Duplas:
//Duplas: 
//Duplas: 

//============================================================================================================

//Inicio: Árvore Binária de Busca (.c)

//biblioteca

#include "BinarySearchTree.h"

//add -----> RUTH
//Começando a nossa Árvore Binária de Busca
//função add em Árvore Binária de Busca: adiciona um novo elemento na árvore
//root: raiz 
// * : ponteiro
//usamos ponteiro e estruturas vistas anteriores na aplicação da Árvore Binária de Busca

int add(TreeNode **root, void *element, TreeComparator f) {
    if ((*root) == NULL) {
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
	if (root!=NULL){
		print(root->element);
		pre_order(root->left,print);
		pre_order(root->right,print);
   }
}

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

TreeNode *smallerLeft(TreeNode **no){
    if((*no)->left != NULL)
        return smallerLeft(&(*no)->left);
    else{
        TreeNode *aux = *no;
        if((*no)->right != NULL)
            *no = (*no)->right;
        else
            *no = NULL;
        return aux;
    }
}

//Função removeTreeNode por Lucio Lisboa. Função com intuito de remover um nó da arvoré
int removeTreeNode(TreeNode **root, void *key, TreeComparator f) {
    if(*root == NULL){   // caso a chave nao exista na arvore
        return 0;
    }
    int compvalue = f(key, (*root)->element);
    if(compvalue < 0)
        removeTreeNode(&(*root)->left, key, f);
    else {
        if(compvalue > 0) {
            removeTreeNode(&(*root)->right, key, f);
        } else {    // se nao eh igual
            TreeNode *aux = *root;
            // Se nao tem filhos
            if (((*root)->left == NULL) && ((*root)->right == NULL)){
                free(aux);
                (*root) = NULL;
            }
            else{ // so tem o filho da direita
                if ((*root)->left == NULL){
                    (*root) = (*root)->right;
                    aux->right = NULL;
                    free(aux); aux = NULL;
                } else { //so tem filho da esquerda
                    if ((*root)->right == NULL){
                        (*root) = (*root)->left;
                        aux->left = NULL;
                        free(aux); aux = NULL;
                    }
                    else{ //Busco o maior filho à direita da subarvore esquerda.
                        aux = greaterRight(&(*root)->left);
                        aux->left = (*root)->left;
                        aux->right = (*root)->right;
                        (*root)->left = (*root)->right = NULL;
                        free((*root));  *root = aux;  aux = NULL;
                    }
                }
            }
        }
    }
    return 1;
}

//int height
int height (TreeNode *root) {
    if (root == NULL)
        return -1; // altura da árvore vazia
    else {
        int hl = height(root->left); //altura esquerda
        int hr = height(root->right); //altura direita
        if (hl < hr) return hr + 1;
        else return hl + 1;
    }
}

//navegar em pos-ordem
void destroy (TreeNode **root) {
    if (*root==NULL) return;
    destroy(&(*root)->left);
    destroy(&(*root)->right);
    free(*root);
    *root=NULL;
}

// gcc BinarySearchTreeTest.c BinarySearchTree.h BinarySearchTree.c -o BinarySearchTree
// ./BinarySearchTree
// 12 22 44 48 50 53 55 60
// 44 12 22 60 50 48 53 55
// 22 12 48 55 53 50 60 44
// Altura: 4
#include "BinarySearchTree.h"

//add -----> RUTH
int add(TreeNode **root, void *element, TreeComparator f) {

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



// void destroy

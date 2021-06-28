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


//void in_order



//void pre_order



//void post_order


//TreeNode *greaterRight


//TreeNode *smallerLeft


//int removeTreeNode



//int height



// void destroy
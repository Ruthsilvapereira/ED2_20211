//Olá a todos! Estou adiantando a atividade Lista Simplesmente Ligada, conforme video aula disponivel em:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view
//LinkedList.h ======> by Ruth (postada completa com as operaçoes, conforme proposto no video:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view)
//LinkedList.h, exemplo disponivel em:http://www.jppreti.com/2019/07/15/lista-simplesmente-ligada/#LinkedListh
//Lembrando que a lista a ser criada em grupo é a ===>LinkedList.c <=== já criada e iniciada por by Ruth, na LinkedList.c todos vão editar e escrever parte do codigo juntos no mesmo projeto
//Inicio
#ifndef DataStructure_DoublyLinkedList_h
#define DataStructure_DoublyLinkedList_h
enum boolean {
    true = 1, false = 0
};
typedef enum boolean bool;
typedef struct Node {
    void *data;
    struct Node *previous;
    struct Node *next;
}Node;
typedef struct DoublyLinkedList {
    Node *first;
    int size;
}DoublyLinkedList;
typedef bool (*compare)(void*,void*);
typedef void (*printNode)(void*);
void init(DoublyLinkedList *list);
int enqueue(DoublyLinkedList *list, void *data);
void* dequeue(DoublyLinkedList *list);
void* first(DoublyLinkedList *list);
void* last(DoublyLinkedList *list);
int push(DoublyLinkedList *list, void *data);
void* pop(DoublyLinkedList *list);
void* top(DoublyLinkedList *list);
bool isEmpty(DoublyLinkedList *list);
int indexOf(DoublyLinkedList *list,void *data, compare equal);
Node* getNodeByPos(DoublyLinkedList *list,int pos);
void* getPos(DoublyLinkedList *list,int pos);
int add(DoublyLinkedList *list, int pos, void *data);
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource);
void* removePos(DoublyLinkedList *list, int pos);
int removeData(DoublyLinkedList *list, void *data, compare equal);
void show(DoublyLinkedList *list, printNode print);
void showMem(DoublyLinkedList *list);
#endif
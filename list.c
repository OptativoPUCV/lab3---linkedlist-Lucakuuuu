#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
  Node* nodo = (Node*) malloc(sizeof(Node));
  if(nodo == NULL) return NULL;
  nodo->data = data;
  nodo->next = NULL;
  nodo->prev = NULL;
  return nodo;
}

List * createList() {
  List* lista = (List*) malloc(sizeof(List));
  if(lista == NULL) return NULL;
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;
}

void * firstList(List * list) {
  list->current = list->head;
  if(list->current) return list->current->data;
  else return NULL;
}

void * nextList(List * list) {
  if(list->current != NULL)
      list->current = list->current->next;
  if(list->current != NULL)
      return list->current->data;
  else return NULL;
}

void * lastList(List * list) {
  
  return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
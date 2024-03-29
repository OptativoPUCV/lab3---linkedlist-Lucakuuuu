#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data; //dato
    Node * next; //siguiente nodo
    Node * prev; //anterior nodo
};

struct List {
    Node * head; //principal
    Node * tail; //ultimo
    Node * current; //actual
};

typedef List List;

Node * createNode(void * data) {
  Node* nodo = (Node*) malloc(sizeof(Node)); //memoria para nodo
  nodo->data = data; //dato correspondiente del nodo
  nodo->next = NULL; //siguiente nodo
  nodo->prev = NULL; //anterior nodo
  return nodo;
}

List * createList() {
  List* lista = (List*) malloc(sizeof(List)); //memoria para lista
  lista->head = NULL; //principal
  lista->tail = NULL; //ultimo
  lista->current = NULL; //actual
  return lista;
}

void * firstList(List * list) {
  list->current = list->head; //asigno el actual al principal
  if(list->current) return list->current->data; //si no es null, retorno el dato del actual
  else return NULL; //sino retorno null
}

void * nextList(List * list) {
  if(list->current != NULL) //si el actual no es null  
      list->current = list->current->next; //asigno el siguiente al actual
  if(list->current != NULL) //si el actual no es null
      return list->current->data; //retorno el dato del actual
  else return NULL; //sino retorno null
}

void * lastList(List * list) {
  list->current = list->tail; //asigno el actual al ultimo
  if(list->current) return list->current->data; //si no es null, retorno el dato del actual
  else return NULL; //sino retorno null
}

void * prevList(List * list) {
  if(list->current != NULL){ //si el actual no es null
    list->current = list->current->prev; //asigno el anterior al actual
    if(list->current) return list->current->data; //si no es null, retorno el dato del actual
    else return NULL;
  }
  else return NULL;
}

void pushFront(List * list, void * data) {
  Node* newNodo = createNode(data); //creo un nuevo nodo
  if(list->head == NULL){ //si la lista esta vacia
    list->head = newNodo; //el nuevo nodo es el principal
    list->tail = newNodo; //el nuevo nodo es el ultimo
  }
  else{
    newNodo->next = list->head;
    list->head->prev = newNodo;
    list->head = newNodo;
  }
}

void pushBack(List * list, void * data) {
  list->current = list->tail;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* newNodo = createNode(data);
  list->current->next = newNodo;
  list->tail = newNodo;
  newNodo->prev = list->current;
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
  if(list->current == NULL) return NULL;
  else{
    void* data = list->current->data;
    if(list->current->prev == NULL)
    {
      list->head = list->current->next;
      list->current->next->prev = NULL;
    }
    else
    {
      list->current->prev->next = list->current->next;
      list->current->next->prev = list->current->prev;
    }
    if(list->current->next == NULL) list->tail = list->current->prev;
    free(list->current);
    list->current = NULL;
    return data;
  }
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
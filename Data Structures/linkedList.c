#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct link_node{
   char * data;
   struct link_node *next;
} *link_node;


link_node initLink(char *data){
  link_node newNode =(link_node)malloc(sizeof(link_node));
  newNode->data= (char*)malloc(sizeof(data)+1);
  strcpy(newNode->data, data);
  newNode->next = NULL;
  return newNode;
}

link_node insertLink(link_node head, char *data){
  link_node new = (link_node)malloc(sizeof(link_node));
  new->next = head;
  new->data = (char*)malloc(sizeof(data)+1);
  strcpy(new->data, data);
  return new;
}

void printLinks(link_node head){
  link_node current = head;
  while (current != NULL){
    if(current->next != NULL) {
	printf("%s ", current->data);
	current = current->next;
    }else if(current->next == NULL){
	printf("%s ", current->data);
	current = current->next;
    }
  }
}
/*
int main(void){
link_node head;
head = initLink("a");
head = insertLink(head, "b");
head = insertLink(head, "c");
printLinks(head);
}
*/





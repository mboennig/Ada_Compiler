#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct rec_l{
   char name[20];
   char type[20];
   int offset;
   struct rec_l *next;
} *rec_l;



void insertLinkRec_l(struct rec_l** head, char n[20], char t[20], int off){
  struct rec_l *new = (struct rec_l*)malloc(sizeof(struct rec_l));
  struct rec_l *last = *head;
  new->next = NULL;
  strcpy(new->name,n);
  strcpy(new->type,t);
  new->offset = off;
  if(*head == NULL){
    *head = new;
    return;
  }
  while(last->next !=NULL){
    last = last->next;
  }
  last->next=new;
  return;
}

void insertLinkRec_l_node(struct rec_l** head, struct rec_l** newnode){
  struct rec_l *last = *head;
  while(last->next !=NULL){
    last = last->next;
  }
  last->next=*newnode;

}

void printRec_l(struct rec_l *head){
  while(head != NULL){
     printf("the name is: %s  The type is: %s  The offset is: %d\n", head->name, head->type, head->offset);
     head = head->next;
  }
}/*
int main(void){
struct rec_l *test = NULL;
insertLinkRec_l(&test, "a", "integer", 5);
insertLinkRec_l(&test, "c", "integ", 0);
insertLinkRec_l(&test, "d", "integer", 9);
struct rec_l *test2 = NULL;
insertLinkRec_l(&test2, "f", "integer", 7);
insertLinkRec_l(&test2, "g", "integ", 1);
insertLinkRec_l(&test2, "e", "integer", 6);
insertLinkRec_l_node(&test2, &test);
printRec_l(test2);
}*/







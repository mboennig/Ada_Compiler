#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


struct link_Patch{
   int lineNo;
   int value;
   struct link_Patch *next;
};


struct link_toPatch{
   int value;
   struct link_toPatch *next;
};

int toPatchCount = 0;
struct link_toPatch *toPatchArr[20];
int toPatchExpC = 0;
struct link_toPatch *toPatchExp[20];
int toPatchCondi = 0;
struct link_toPatch *toPatchCond[20];



void insert_Patch(struct link_Patch** head, int line, int val){
  struct link_Patch *new = (struct link_Patch*)malloc(sizeof(struct link_Patch));
  struct link_Patch *last = *head;
  new->next = NULL;
  new->lineNo= line;
  new->value=val;
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


 

void swap(struct link_Patch *a, struct link_Patch *b)
{
    int temp = a->lineNo;
    int temp2 = a->value;
    a->lineNo = b->lineNo;
    a->value = b->value;
    b->lineNo = temp;
    b->value = temp2;
}

 
/* Bubble sort the given linked list */
void bubbleSort(struct link_Patch *start) 
{ 
    int swapped, i; 
    struct link_Patch *ptr1; 
    struct link_Patch *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->lineNo > ptr1->next->lineNo) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);  
  
} 



void printPatch(struct link_Patch *head, FILE *output){
  bubbleSort(head);
  while (head != NULL){
     fprintf(output,"%d , %d\n", head->lineNo, head->value);
     head = head->next;
    }
  }

void insert_toPatch(struct link_toPatch** head, int val){
  struct link_toPatch *new = (struct link_toPatch*)malloc(sizeof(struct link_toPatch));
  struct link_toPatch *last = *head;
  new->next = NULL;
  new->value=val;
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

void print_toPatch(){
  struct link_toPatch *head = toPatchArr[toPatchCount];
  while (head != NULL){
     printf("%d ,", head->value);
     head = head->next;
    }
  printf("\n");
}


void add_toPatch(int val){
   insert_toPatch(&toPatchArr[toPatchCount], val);
}

void push_toPatch(){
  toPatchCount++;
  struct link_toPatch * head = NULL;
  toPatchArr[toPatchCount]=head;
}

void pop_toPatch(){
   toPatchArr[toPatchCount] = NULL;
   toPatchCount--;
}

struct link_toPatch* grab_toPatch(){
  return toPatchArr[toPatchCount];
}

void add_toPatchExp(int val){
   insert_toPatch(&toPatchExp[toPatchExpC], val);
}

void push_toPatchExp(){
  toPatchExpC++;
  struct link_toPatch * head = NULL;
  toPatchExp[toPatchExpC]=head;
}

void pop_toPatchExp(){
   toPatchExp[toPatchExpC] = NULL;
   toPatchExpC--;
}


struct link_toPatch* grab_toPatchExp(){
  return toPatchExp[toPatchExpC];
}

void add_toPatchCond(int val){
   insert_toPatch(&toPatchCond[toPatchCondi], val);
}

void push_toPatchCond(){
  toPatchCondi++;
  struct link_toPatch * head = NULL;
  toPatchCond[toPatchCondi]=head;
}

void pop_toPatchCond(){
   toPatchCond[toPatchCondi] = NULL;
   toPatchCondi--;
}


struct link_toPatch* grab_toPatchCond(){
  return toPatchCond[toPatchCondi];
}



/*
int main(void){
struct link_Patch * head = NULL;
insert_Patch(&head,1, 27);
insert_Patch(&head,1,33);
insert_Patch(&head, 4,6);
printPatch(head);
push_toPatch();
add_toPatch(6);
add_toPatch(9);
struct link_toPatch *h = grab_toPatch();
  while (h != NULL){
     printf("%d ,", h->value);
     h = h->next;
    }
printf("\n");

push_toPatch(10);
pop_toPatch();
pop_toPatch();
}
*/



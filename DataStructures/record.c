#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int arr[999];
int current_pos =0;
typedef struct Records{
  int value;
  int register_n;
  int offset;
  bool is_reg;
  bool is_walkback;
  int walkback_n;
  char param_n[20];
  char primary_n[20];
}record;


typedef struct link{
   record * data;
   struct link *next;
} *link;



record* newRec(){
  record* name = (record*)malloc(sizeof(record));
  name->value=0;
  name->register_n=0;
  name->offset=0;
  name->is_reg = false;
  name->is_walkback = false;
  name->walkback_n =0;
  strcpy(name->param_n, "");
  strcpy(name->primary_n, "");
  return name;
}

void incrementOffset(int num){
    int i = arr[current_pos];
    arr[current_pos] = num + i;
}

int currentOffset(){
    return arr[current_pos];
}

void nextOffset(){
    current_pos++;
}
void prevOffset(){
   arr[current_pos]=0;
   current_pos--;
}


link initLinkRec(record* data){
  link newNode =(link)malloc(sizeof(link));
  newNode->data= (record*)malloc(sizeof(data)+1);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

link insertLinkRec2(link head, record *data){
  link newNode =(link)malloc(sizeof(link));
  newNode->next = head;
  newNode->data= (record*)malloc(sizeof(data)+1);
  newNode->data = data;
  return newNode;
}


void insertLinkRec(link head, record* data){
  link new = (link)malloc(sizeof(link));
  link last = head;
  new->next = NULL;
  new->data = (record*)malloc(sizeof(data)+1);
  new->data = data;
  //if(head == NULL){
   //head = new;
   //return new;
  //}
  while(last->next !=NULL){
    last = last->next;
  }
  last->next=new;
  
}

int printRecs(link head, FILE *output, int instructions){
  while (head != NULL){
	fprintf(output,"%d      write %s%d \n", instructions++,
                                                              head->data->is_reg?"r":"contents b, ",
                                                              head->data->is_reg?head->data->register_n:head->data->offset);
	//fprintf(output, "%d	write r%d\n",instructions++, head->data->register_n);
        head = head->next;
    }
    return instructions;
}


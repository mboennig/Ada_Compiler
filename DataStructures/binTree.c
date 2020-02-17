/*
   binary tree
Matthew Boennighausen
https://www.learn-c.org/en/Binary_trees
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20


//****For the array of structures ***
typedef struct listEntry {
  char name[MAX_SIZE];
  struct node * tree;
} list_e;


//****For the Binary Tree node ****
typedef struct node
{
  char str[MAX_SIZE];
  struct node * left;
  struct node * right;
  int memSpace;
  int offset;
  char kind[MAX_SIZE]; //kind of node
  struct node * parent_Type; //for variables
  int value; //for a number or size the variable type
  char mode[MAX_SIZE]; //formal parameter
  struct node * next; //for formal parameter
  struct node * component_type; //for arrays
  struct rec_l * recor_l; //for when using records
  int lower; //first index of array
  int upper; //last index of array
  int real_off;
  int parent_memory;
  int starting_off;
   
} node_t;

//functions for Binary Tree
struct node* insert(node_t * tree, char string[]);
void print_tree(node_t * current);
struct node* createNode(char string[]);
int searchDFS(struct node* node, char string[]);
void printInorder(struct node* node);
void print(list_e array[], int pos);
void printAllInfo(struct node* node);
//functions for Stack
void push(list_e array[], int *pos, char name[]);
void pop(int *pos);
void add(list_e array[], int pos, char str[]);
struct node * search(list_e array[], int pos, char str[], int counter);
struct node * searchDFSnode(struct node* node, char string[]);
struct node * searchLocal(list_e array[], int pos, char str[]);
struct node * searchAll(list_e array[], int pos, char str[]);
//***********MAIN***************

/*
int main(){
	struct listEntry array[10];
	int current_position = 0;
	
	push(array, &current_position, "od");
	add(array, current_position, "hello");
	add(array, current_position, "coolStuff");
	node_t * temp = searchLocal(array, current_position, "hello");
	node_t * temp_n = searchLocal(array, current_position, "coolStuff");
	add(array, current_position, "whyamIinthisclass");
//	print(array, current_position);
	temp_n->lower = 1;
	temp_n->upper = 27;	
	temp->lower = 15;
        temp->value = 66;
	print(array, current_position);
//	printAllInfo(temp_n);
//	printAllInfo(searchLocal(array, current_position, "hello"));
}
*/


void push(list_e array[], int *pos, char name[]){//push a struct into the array for the user
	list_e * temp = (list_e *)malloc(sizeof(list_e));
	printf("\n Pushing new scope of '%s' \n", name);
	strcpy(temp->name, name);
	temp->tree = createNode(" ");
	array[*pos] = *temp;
	*pos = *pos +1;
}

void pop(int *pos){ //will know the top of the array using a global location (pointer?
	if(*pos > 0){
  	  *pos = *pos -1;
	}else{
  	  printf("ERROR: Cannot pop, need to have at least one entry in list \n");
	}
}


void add(list_e array[], int pos, char str[]){ //add to the first tree but also needs to do a DFS on the tree make sure it isnt present 
  if(pos > 0){
        insert(((array[pos-1]).tree), str);
  }else{
    printf("ERROR: Cannot add, need to have at least one entry in list \n");
  }
}

struct node * searchAll(list_e array[], int pos, char str[]){
	return search(array, pos, str, 1);
}



int searchInt1(list_e array[], int pos, char str[], int counter){ //needs to let the user know how many trees you travel down 
  //start the search at the top and then move down if not found
  if((pos-counter) >= 0){
    if(searchDFS(array[pos-counter].tree, str) == 1){
	return counter-1;
    }else{
      //increment the counter
      searchInt1(array, pos, str, counter+1);
    }
  }else{
    return -1;
  }
}


int searchInt(list_e array[], int pos, char str[]){
    return searchInt1(array, pos, str, 1);
}


struct node * search(list_e array[], int pos, char str[], int counter){ //needs to let the user know how many trees you travel down 
  //start the search at the top and then move down if not found
  if((pos-counter) >= 0){
    if(searchDFS(array[pos-counter].tree, str) == 1){
     // printf("Found the value '%s' in the tree '%s' \n", str, array[pos-counter].name);
    // printf("Need to search the stack %d deep \n", counter-1);
      return searchDFSnode(array[pos-counter].tree, str); //TODO fix this
    }else{
      //increment the counter
      search(array, pos, str, counter+1);
    }
  }else{
    printf("Did not find the value you are searching for in any of the trees \n");
  }
}




struct node * searchLocal(list_e array[], int pos, char str[]){
  return searchDFSnode(array[pos-1].tree, str);
}

void print(list_e array[], int pos){
   for(int i = 0; i < pos; i++){
     printf("%s ->", array[i].name);
     printInorder(array[i].tree);
     printf("\n");
   }
}

/***************************************BINARY TREE*****************************************/

struct node * createNode(char string[]){
  node_t* name = (node_t*)malloc(sizeof(node_t));
  strcpy(name->str, string);
  name->left = NULL;
  name->right = NULL;
  name->parent_Type = NULL;
  name->next = NULL;
  name->component_type = NULL;
  name->recor_l = NULL;
  strcpy(name->kind, "");
  name->value = 0;
  name->lower = 0;
  name->starting_off = 0;
  name->upper = 0;
  name->parent_memory = 0;
  name->memSpace =1;
  name->offset = -1;
  name->real_off = 0;
  return name;
}

struct node * insertNode(node_t * tree, char string[])
{
  if(tree == NULL){
    return createNode(string);
  }else if(strcmp(string, tree->str) < 0){
    tree->left = insertNode(tree->left, string);
  }else if(strcmp(string, tree->str) > 0){
    tree->right = insertNode(tree->right, string);
  }else{
    printf("ERROR: Duplicate value %s \n", string);
  }
  return tree;
}


struct node * insert(node_t * tree, char string[])
{
   if(strcmp(tree->str, " ")==0){
   strcpy(tree->str, string);
   return tree;
  }else{
   return insertNode(tree, string);
  }
}


struct node * searchDFSnode(struct node* node, char string[]){
     if (node == NULL){
	return NULL;
     }
     else if(strcmp(node->str,string) == 0){
	return node;
     }else if (strcmp(node->str, string) > 0){
        return searchDFSnode(node->left, string);
     }else{
        return searchDFSnode(node->right, string);
     }
}

int searchDFS(struct node* node, char string[]){
     if (node == NULL){
	return 0;
     }
     else if(strcmp(node->str,string) == 0){
	return 1;
     }else if (strcmp(node->str, string) > 0){
	return searchDFS(node->left, string);
     }else{
	return searchDFS(node->right, string);
     }
}
  
void printInorder(struct node* node) 
{ 
     if (node == NULL){
	return; 
     }
     printInorder(node->left); 
     printAllInfo(node);
     printInorder(node->right); 
}
void printInParent(struct node* node)
{
     if (node == NULL){
        return;
     }
     printInParent(node->left);
     if(strcmp(node->kind,"variable")==0){
	 printf("%s - object w/ parent type %s \n",node->str, node->parent_Type->str);
     }else if(strcmp(node->kind,"procedure")==0){
         printf("%s - procedure \n", node->str);
     }else{
         printf("%s - type(%s) \n",node->str, node->kind);
     }
     printInParent(node->right);
}

void addOuter(list_e array[], int pos){
//	push(array, pos, "Outer Context");
        
	add(array, pos, "integer");
	node_t * current_node = searchLocal(array, pos, "integer");
	strcpy(current_node->kind, "type");
	current_node->memSpace=1;
	printf("integer - %s \n", current_node->kind);
        
	add(array, pos, "boolean");
        node_t * current_node2 = searchLocal(array, pos, "boolean");
        strcpy(current_node2->kind, "type");
	current_node2->memSpace=1; 
        printf("boolean - %s \n", current_node2->kind);
	
	add(array, pos, "true");
	node_t * current_node3 = searchLocal(array, pos, "true");
        strcpy(current_node3->kind, "literal");
	current_node3->value=1;
	current_node3->memSpace=1; //the size for now is just 1
        printf("true - %s \n", current_node3->kind);
        
	add(array, pos, "false");
	node_t * current_node4 = searchLocal(array, pos, "false");
	strcpy(current_node4->kind, "literal");
	current_node4->value=0;
	current_node4->memSpace=1; //the size for now is just 1
        printf("false - %s \n", current_node4->kind);
        
	add(array, pos, "maxint");
	node_t *current_node5 = searchLocal(array, pos, "maxint");
	strcpy(current_node5->kind, "value");
	current_node5->memSpace=1; //the size for now is just 1
        printf("maxint - %s \n", current_node5->kind);
	
	add(array, pos, "read");
        node_t *current_node6 = searchLocal(array, pos, "read");
        strcpy(current_node6->kind, "read_routine");
        current_node6->memSpace=1; //the size for now is just 1
        printf("read - %s \n", current_node6->kind);

	add(array, pos, "write");
        node_t *current_node7 = searchLocal(array, pos, "write");
        strcpy(current_node7->kind, "write_routine");
        current_node7->memSpace=1; //the size for now is just 1
        printf("write - %s \n", current_node7->kind);

	add(array, pos, "constraint_error");
        node_t *current_node8 = searchLocal(array, pos, "constraint_error");
        strcpy(current_node8->kind, "exception");
        current_node8->memSpace=0; //the size for now is just 1
        current_node8->value=1;
        printf("constraint_error - %s \n", current_node8->kind);

	add(array, pos, "numeric_error");
        node_t *current_node9 = searchLocal(array, pos, "numeric_error");
        strcpy(current_node9->kind, "exception");
        current_node9->memSpace=0; //the size for now is just 1
        current_node9->value=2;
        printf("numeric_error - %s \n", current_node9->kind);


}


void printAllInfo(struct node* node){
     printf("%s ", node->str);
    // printf("%s ", node->kind);
    // printf("%d ", node->value);
    // printf("%s ", node->mode);
     printf("The lower is %d ", node->lower);
     printf("The upper is %d ", node->upper);
     
     if(node->kind != ""){
        printf("The kind is %s ", node->kind);
     }
     printf("The value is %d ", node->value);
     if(node->mode != ""){
        printf("The mode is %s ", node->mode);
     } 
     /*
     if(node->lower != NULL){
        printf("%d ", node->lower);
     }
     if(node->upper != NULL){
        printf("%d ", node->upper);
     }*/ 
     printf(" \n");
}





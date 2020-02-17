 /*ada.y
Matthew Boennighausen
Final*/
%{
int yylex();
int yyerror(char*);
#include <stdio.h>
#include <string.h>
#include "DataStructures/binTree.c"
#include "DataStructures/linkedList.c"
#include "DataStructures/record.c"
#include "DataStructures/patchLink.c"
#include "DataStructures/rec_l.c"
int instruction = 0;
int current_register =1;
FILE *output;
int current_position = 0;
int is_raise = 0;
int handler_done = 0;
int exception_jump = 0;
int exception_count = 3;
int return_except = 0;
struct listEntry array[20];
extern int lineno;
struct link_Patch * patchList = NULL;
int jump_table[20];
%}

%token IS BEG END PROCEDURE ID NUMBER TYPE ARRAY RAISE OTHERS
%token RECORD IN OUT RANGE CONSTANT ASSIGN EXCEPTION NULLWORD LOOP IF
%token THEN ELSEIF ELSE EXIT WHEN AND OR EQ NEQ LT GT GTE LTE TICK
%token NOT EXP ARROW OF DOTDOT ENDIF ENDREC ENDLOOP EXITWHEN
%type <integer>NUMBER
%type <var> ID
%type <var> identifier /*maybe shouldnt have this*/
%type <var> type_name
%type <integer> constant
%type <head> identifier_list
%type <var> mode
%type <var> parameters
%type <var> formal_parameter_part
%type <tree_node> procedure_specification
%type <head> variable
%type <rec> expression
%type <rec> opt_rec_arr
%type <rec> primary
%type <rec> relation
%type <rec> simple_expr
%type <rec> term
%type <rec> factor
%type <var> multiplying_op
%type <var> adding_op
%type <var> boolean_op
%type <var> relation_op
%type <integer> declarative_part
%type <tree_node> procedure_prime
%type <integer> begin
%type <rec_head> exprlist
%type <integer> loopStart
%type <integer> end_if
%type <rec> condition
%type <rec_head> opt_param
%type <rec> opt_assign
%type <rec_o> record_ob
%type <rec_o> component_list
%type <integer> choice_sequence
%union {
  int integer;
  char *var;
  struct link_node * head;
  struct node * tree_node;
  struct Records * rec;
  struct link * rec_head;
  struct rec_l * rec_o;
}
%%
program : main_body {printf ("\n*****\nDONE.\n*****\n");
		    printPatch(patchList, output);
		    }
	;

main_body : main_specification IS
	    declarative_part begin
	    sequence_of_statements
	    exception_part END ';' { //take $4 for the jump number 
				   printf("Popping off the top of the stack %s \n", array[current_position-1].name);
				   printInParent(array[current_position-1].tree);
				   pop(&current_position);
				   fprintf(output, "%d	r%d := contents b, 1\n", instruction++, current_register);
                                   fprintf(output, "%d	b := contents b, 3\n", instruction++);
				   fprintf(output, "%d	pc := r%d\n", instruction++, current_register);
				   current_register++;
				   //pop off the the pop
				   insert_Patch(&patchList,0, instruction);
				   insert_Patch(&patchList,1, instruction + $3);
				   insert_Patch(&patchList,4, $4);
				   }
	    ;


main_specification : PROCEDURE ID {push(array, &current_position, $2);
				   //put into start current instruction count 
				   fprintf(output, "%d 	b := ?\n", instruction++);
				   fprintf(output, "%d	contents b, 0 := ?\n", instruction++);
				   fprintf(output, "%d	contents b, 1 := 5\n", instruction++);
				   fprintf(output, "%d	r%d := 0\n", instruction++, current_register);
				   current_register++;
				   fprintf(output, "%d	pc := ?\n", instruction++);
				   fprintf(output, "%d	halt\n", instruction++);
				   incrementOffset(4);
				   }
	       	   

procedure_body : procedure_prime IS
		 declarative_part begin
		 sequence_of_statements
		 exception_part END ';' {
                                        printf("Popping off the top of the stack %s \n", array[current_position-1].name);
                                        printInParent(array[current_position-1].tree);
                                        pop(&current_position);
					//fprintf(output, "THE CURRENT OFFSET IS %d\n", $3);
					$1->lower= $3;
					$1->value= $4;
					int i = 0;
					node_t * prodNode = $1->next;
					if(prodNode != NULL){
                                        while(i == 0){
                                            printf("The kind is %s \n",prodNode->str);
					    if(strcmp(prodNode->mode,"In Out")==0 || strcmp(prodNode->mode, "Out")==0){
						fprintf(output, "%d	r%d := contents b, %d\n", instruction++, current_register, prodNode->value);
						fprintf(output, "%d	contents r%d := contents b, %d\n", instruction++, current_register, prodNode->offset);
						current_register++;
					    }
                                            if(prodNode->next != NULL){
                                                 prodNode = prodNode->next;
                                            }else{i=1;}
					}}
					
					fprintf(output, "%d	r%d := contents b, 1\n", instruction++, current_register);
                                        fprintf(output, "%d	b := contents b, 3\n", instruction++);
                                        fprintf(output, "%d	pc := r%d\n", instruction++, current_register);
					current_register++;
					prevOffset();
					}
		;

begin : BEG{ $$= instruction;
	     push_toPatchExp();
	   }
	;
procedure_prime: procedure_specification formal_parameter_part { //link the next if something is in parameters
								if(strcmp($2, "")!=0){
								  node_t * topProd = $1;
								  $1->next = searchLocal(array, current_position, $2);
							        }
								$$=$1;
								}

procedure_specification : PROCEDURE identifier { //do an add here, pass up the pointer to the procedure prime
						add(array, current_position, $2);
						node_t * prodNode = searchLocal(array, current_position, $2);
						strcpy(prodNode->kind, "procedure");
						//fprintf(output, "THE CURRENT OFFSET LATER IS %d\n", currentOffset());
						//prodNode->value=instruction;
						$$ = prodNode;
  						push(array, &current_position, $2);
						nextOffset();
						incrementOffset(4);
						}
			;

formal_parameter_part : '(' parameters ')' { $$ = $2; 
					  }
                        | {$$ = "";} 		   	
			;


parameters : identifier_list ':' mode type_name ';' parameters {
                                   
					  printf("	line#: %d: ", lineno);
					  printLinks($1);
                                          printf(": %s \n", $4);
					  //$6 is the varaible of the node being passed in, do a search on it and connect it to the last
					  link_node current = $1;
                                          while (current != NULL){
						 if(searchDFS(array[current_position-1].tree, current->data) == 1){
						    printf("ERROR: Duplicate IDs \n");
						    current = current->next;
						    continue;
					         }
 						 add(array, current_position, current->data);
                                                 node_t * current_node = searchLocal(array, current_position, current->data);
                                                 strcpy(current_node->mode, $3);
						 strcpy(current_node->kind, "variable");
                                                 current_node->parent_Type= searchAll(array, current_position, $4);
                                           	 //current_node->memSpace = current_node->parent_Type->memSpace;
						 if(current->next == NULL){
                                                     $$ = current->data;
                                                  }
						  
						 int off = currentOffset();
                                                 off = off - current_node->parent_Type->lower;
                                                 current_node->real_off = currentOffset();
                                                 current_node->offset = off;
                                                 incrementOffset(current_node->parent_Type->memSpace);
						 if(strcmp($3, "In Out")==0 || strcmp($3, "Out")==0){
                                          	      int offf = currentOffset();
                                                      offf = offf - current_node->parent_Type->lower;
						      current_node->value = offf;		
						      incrementOffset(current_node->parent_Type->memSpace);
                                                 }
						 current = current->next;

					 }
						
					 link_node c =$1;
					 while(c->next != NULL){
                                                node_t * n_current = searchLocal(array, current_position, c->next->data);
                                                n_current->next = searchLocal(array, current_position, c->data);
                                                c = c->next;
                                            }
					node_t * make_next = searchLocal(array,current_position, $1->data);
					make_next->next = searchLocal(array, current_position, $6);

                                        }
	   | identifier_list ':' mode type_name {
						printf("    line#: %d: ", lineno);
						printLinks($1);
                                                printf(": %s \n", $4);
						link_node current = $1;
                                                while (current != NULL){
						 if(searchDFS(array[current_position-1].tree, current->data) == 1){
                                                    printf("ERROR: Duplicate IDs \n");
						    current = current->next;
                                                    continue;
                                                 }
						 //Here I connect all of the nodes together and pass up a pointer for the first node
                                                 add(array, current_position, current->data);
                                                 node_t * current_node = searchLocal(array, current_position, current->data);
                                                 strcpy(current_node->mode, $3);
						 //set the next to localSearch(current->next->data)
					         strcpy(current_node->kind, "variable");
                                                 current_node->parent_Type= searchAll(array, current_position, $4);
                                                 //current_node->memSpace = current_node->parent_Type->memSpace;

						 if(current->next == NULL){
						     $$ = current->data;
						  }
					          int off = currentOffset();
                                                 off = off - current_node->parent_Type->lower;
                                                 current_node->real_off = currentOffset();
                                                 current_node->offset = off;
                                                 incrementOffset(current_node->parent_Type->memSpace);
                                                 if(strcmp($3, "In Out")==0 || strcmp($3, "Out")==0){
                                                      int offf = currentOffset();
                                                      offf = offf - current_node->parent_Type->lower;
                                                      current_node->value = offf;               
                                                      incrementOffset(current_node->parent_Type->memSpace);
                                                 }
                                                 current = current->next;

                                            }//have another while loop that connects all of the nexts
					    link_node c =$1;
					    while(c->next != NULL){
						node_t * n_current = searchLocal(array, current_position, c->next->data);
						n_current->next = searchLocal(array, current_position, c->data);
						c = c->next; 
					    }
					}
	   ;


declarative_part: declares ';' declarative_part {$$ = currentOffset();}
		| procedure_body_part {$$ = currentOffset();}
		| {$$= currentOffset();}
		;

procedure_body_part: procedure_body procedure_body_part
		   | procedure_body
		   ;


declares: objects
	| types
	| exceptions
	;
/*ADDED objectDecls*/
objects: variable
       | const_variable
       ;

variable: identifier_list ':' type_name { printf("	line#: %d - ", lineno);
					  printLinks($1);
					  printf(": %s \n", $3);
					  link_node current = $1;
					  while (current != NULL){
						 if(searchDFS(array[current_position-1].tree, current->data) == 1){
                                                    printf("ERROR: Duplicate IDs \n");
						    current = current->next;
                                                    continue;
                                                 }
                                                 add(array, current_position, current->data);
					         node_t * current_node = searchLocal(array, current_position, current->data);
					    	 strcpy(current_node->kind, "variable"); 
						 current_node->parent_Type= searchAll(array, current_position, $3);
						 if(strcmp(current_node->parent_Type->kind, "record")==0){
						    int running_off = currentOffset();
						    struct rec_l *head = current_node->parent_Type->recor_l;
						    struct rec_l *new = NULL; 
                                                    while(head != NULL){
                                                           node_t * node_type = searchAll(array, current_position, head->type);
							   insertLinkRec_l(&new, head->name,head->type ,running_off - node_type->lower);
                                                           running_off = running_off + node_type->memSpace;
                                                           head = head->next;
                                                        }
						    current_node->recor_l = new;
						    printf("Printing the old one\n");
						    printRec_l(current_node->parent_Type->recor_l);
						    printf("Printing the new one\n");
						    printRec_l(current_node->recor_l);
						 }else if(strcmp(current_node->parent_Type->kind, "array")==0 && strcmp(current_node->parent_Type->component_type->kind, "record")==0){
						   int running_off = currentOffset();
                                                    struct rec_l *head = current_node->parent_Type->component_type->recor_l;
                                                    struct rec_l *new = NULL; 
						    int i = 0;
                                                    while(head != NULL){
                                                           node_t * node_type = searchAll(array, current_position, head->type);
                                                           insertLinkRec_l(&new, head->name,head->type ,i);
							   i++;
                                                           head = head->next;
                                                        }
                                                    current_node->recor_l = new;
                                                    printf("Printing the new one\n");
                                                    printRec_l(current_node->recor_l);
						    current_node->parent_memory = current_node->parent_Type->component_type->memSpace;
						  
						 }
						 //current_node->memSpace = current_node->parent_Type->memSpace
						 int off = currentOffset();
						 off = off - current_node->parent_Type->lower;
						 printf("The current offset is %d\n", currentOffset());
						 current_node->real_off = currentOffset();
						 current_node->offset = off;
						 printf("The menspace for the offset is %d \n", current_node->parent_Type->memSpace);
						 incrementOffset(current_node->parent_Type->memSpace);

                                                 current = current->next;
                                            }
                                          }

	;

const_variable: identifier_list ':' CONSTANT ASSIGN  expression
	      ;

identifier: ID {$$ = $1;}		
	  ;

types: array
     | record
     | range
     ;

array: TYPE identifier IS ARRAY '(' constant DOTDOT constant ')' OF type_name { add(array, current_position, $2);
     										node_t * current_node = searchLocal(array, current_position, $2);
										current_node->lower = $6;
										current_node->upper = $8;
										current_node->component_type = searchAll(array, current_position, $11);
										strcpy(current_node->kind, "array");
										printf("The range is %d to %d\n", $8, $6);
										int range = $8 - $6;
										range = range+1;
										printf("I am multiplying %d by %d \n",range, current_node->component_type->memSpace);
                                                 				current_node->memSpace = range*current_node->component_type->memSpace;
										printf("THE CURRENT MEMSPACE IS %d \n", current_node->memSpace);
										}
     ;

record: TYPE identifier IS RECORD component_list ENDREC{add(array, current_position, $2);
							node_t * current_node = searchLocal(array, current_position, $2);
							current_node->recor_l = $5;
				   			struct rec_l *head = $5;
							int memS = 0;
							while(head != NULL){
							   node_t * node_type = searchAll(array, current_position, head->type);
							   memS = memS + node_type->memSpace;
							   head = head->next;
							}
							current_node->component_type = createNode("");
							strcpy(current_node->kind, "record");
							current_node->memSpace = memS;
							printRec_l($5);
						       }
      ;

range: TYPE identifier IS RANGE constant DOTDOT constant {add(array, current_position, $2);
                                                          node_t * current_node = searchLocal(array, current_position, $2);
                                                          current_node->lower = $5;
                                                          current_node->upper = $7;
                                                          strcpy(current_node->kind, "range");
							  current_node->memSpace = 1;//TODO:This is hard coded, just assuming it is an int
                                                         }
     ;

exceptions: identifier_list ':' EXCEPTION{
					 printf("      line#: %d - ", lineno);
                                          printLinks($1);
                                          printf(": Exception \n");
                                          link_node current = $1;
                                          while (current != NULL){
                                                 if(searchDFS(array[current_position-1].tree, current->data) == 1){
                                                    printf("ERROR: Duplicate IDs \n");
                                                    current = current->next;
                                                    continue;
                                                 }
                                                 add(array, current_position, current->data);
                                                 node_t * current_node = searchLocal(array, current_position, current->data);
                                                 strcpy(current_node->kind, "exception");
					         current_node->value = exception_count;
						 exception_count++;
                                                 current = current->next;
                                            }
					   }
	  ;

identifier_list : identifier_list ',' identifier {$1 = insertLink($1,$3);
						  $$ = $1;
						}
	        | identifier{struct link_node *head;
			     head = initLink($1);
		             $$ = head;
			    }
		;

type_name: identifier {$$ = $1;}
	 ;

constant: ID {$$=0;} 
	| NUMBER {$$=$1;}
	;

component_list: record_ob ';' component_list {
                               		      insertLinkRec_l_node(&$1, &$3);
                               		      $$ = $1;
					     }
	      | record_ob ';' {
			       $$ = $1;
			      }
	      ;


record_ob: identifier_list ':' type_name {struct rec_l *test = NULL;
					  link_node current = $1;
                                          while (current != NULL){ 
					   insertLinkRec_l(&test, current->data, $3, 0);
					   current = current->next; 
					  }
					 $$ = test;
					 }
	 ;

mode: IN {$$ = "In";}
    | OUT {$$ = "Out";}
    | IN OUT {$$ = "In Out";}
    | {$$ = "In";}
    ;


boolean_op: AND {$$ ="and";}
          | OR  {$$ = "or";}
          ;


expression: expression boolean_op relation {record * new_record = newRec();
					    if($1->is_walkback){
                                   		fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $1->register_n,$1->walkback_n, $1->offset);
                                 	   }	
                                 	   if($3->is_walkback){
                                   	       fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                 	    }	
                                            fprintf(output,"%d	r%d:= %s%d %s %s%d\n", instruction++, current_register,
                                                                                         $1->is_reg?"r":"contents b, ",
                                                                                         $1->is_reg?$1->register_n:$1->offset,
                                                                                         $2,
                                                                                         $3->is_reg?"r":"contents b, ",
                                                                                         $3->is_reg?$3->register_n:$3->offset);

                                           new_record->is_reg = true;
                                           new_record->register_n = current_register;
                                           $$ = new_record;
                                           current_register++; 
				           }
	  | relation {$$ = $1;}
	  ;

exprlist: exprlist ',' expression{ //TODO Make this a list of expressions 
	 			  insertLinkRec($1,$3);
                                  $$ = $1;
				 }
	 | expression {struct link *head;
                       head = initLinkRec($1);
                       $$ = head;
		      }
	 ;

relation: relation relation_op simple_expr{
					    record * new_record = newRec();
					    if($1->is_walkback){
                                   		fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $1->register_n,$1->walkback_n, $1->offset);
                                 	    }
                                 	    if($3->is_walkback){
                                   		fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                 	    }
					    if(!$3->is_reg){
					       fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, $3->offset);
					       $3->register_n = current_register;
					       current_register++;
					    }
					    if(!$1->is_reg){
                                               fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, $1->offset); 
                                               $1->register_n = current_register;
                                               current_register++;
                                            }	
					    if(strcmp($2, ">")==0){
					     fprintf(output,"%d	r%d:= r%d < r%d\n", instruction++, current_register,$3->register_n, $1->register_n);
					    }else if(strcmp($2, ">=")==0){
                                            fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,$3->register_n, $1->register_n);
					   }else{
					     fprintf(output,"%d	r%d:= r%d %s r%d\n", instruction++, current_register,
                                                                                         $1->register_n,
                                                                                         $2,
                                                                                         $3->register_n);

					   }
                                           new_record->is_reg = true;
                                           new_record->register_n = current_register;
                                           $$ = new_record;
                                           current_register++;
					 }
	| simple_expr {$$=$1;}
	;


simple_expr: simple_expr adding_op term {
					record * new_record = newRec();
					if($1->is_walkback){
                                   	   fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $1->register_n,$1->walkback_n, $1->offset);
                                 	}
                                 	if($3->is_walkback){
                                   	  fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                 	}
                                        fprintf(output,"%d	r%d:= %s%d %s %s%d\n", instruction++, current_register,
                                                                                     $1->is_reg?"r":"contents b, ",
                                                                                     $1->is_reg?$1->register_n:$1->offset,
                                                                                     $2,
                                                                                     $3->is_reg?"r":"contents b, ",
                                                                                     $3->is_reg?$3->register_n:$3->offset);

                                         new_record->is_reg = true;
                                         new_record->register_n = current_register;
                                         $$ = new_record;
                                         current_register++;
					}
	   | term {$$=$1;}
	   | '-' term {record * new_record = newRec();
                       if($2->is_reg){
                           fprintf(output, "%d	r%d := - r%d\n",  instruction++, current_register, $2->register_n);
                           new_record->is_reg = true;
                           new_record->register_n = current_register;
                           current_register++;
                        }else{
                           fprintf(output, "%d	r%d := - contents b, %d\n",  instruction++, current_register, $2->offset);
                           new_record->is_reg = true;
                           new_record->register_n = current_register;
                           current_register++;
                        }
                        $$ = new_record;           
			}           
	   ;

term: term multiplying_op factor {//TODO mulitplying opp, grab register, then move up stack, 
				 record * new_record = newRec();
			         if($1->is_walkback){
				   fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $1->register_n,$1->walkback_n, $1->offset);
				 }
				 if($3->is_walkback){
                                   fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                 }
				 fprintf(output,"%d	r%d:= %s%d %s %s%d\n", instruction++, current_register,
				 					 $1->is_reg?"r":"contents b, ",
									 $1->is_reg?$1->register_n:$1->offset,
									 $2,
									 $3->is_reg?"r":"contents b, ",
                                                                         $3->is_reg?$3->register_n:$3->offset);

				 new_record->is_reg = true;					
				 new_record->register_n = current_register;
				 $$ = new_record;
				 current_register++;
				 } 
    | factor {$$=$1;}
    ;

factor: primary {$$ = $1;}
      | primary EXP primary {record * new_record = newRec();
			    if($1->is_walkback){
                      		fprintf(output, "%d	r%d := contents r%d, %d\n",  instruction++, current_register, $1->walkback_n, $1->offset);
				$1->is_reg = true;
                      		$1->register_n = current_register;
                      		current_register++;
			    }else if(!$1->is_reg){
				fprintf(output, "%d	r%d := contents b, %d\n",  instruction++, current_register, $1->offset);
                      		$1->is_reg = true;
                      		$1->register_n = current_register;
                      		current_register++;
			    }
			    if($3->is_walkback){
                                fprintf(output, "%d	r%d := contents r%d, %d\n",  instruction++, current_register, $3->walkback_n, $3->offset);
                                $3->is_reg = true;
                                $3->register_n = current_register;
				current_register++;
                            }else if(!$3->is_reg){
                                fprintf(output, "%d	r%d := contents b, %d\n",  instruction++, current_register, $3->offset);
                                $3->is_reg = true;
                                $3->register_n = current_register;
                                current_register++;
                            }
			    
			    fprintf(output, "%d	r%d := 1\n",  instruction++, current_register);
			    int product_reg = current_register;
			    current_register++;
			    fprintf(output, "%d	r%d := 1\n",  instruction++, current_register);
                            int dec_reg = current_register;
                            current_register++;
			    int jump_int = instruction;
			    fprintf(output,"%d	r%d:= r%d * r%d\n", instruction++, product_reg, product_reg, $1->register_n);
			    fprintf(output, "%d	r%d := r%d = r%d\n",  instruction++, current_register, $3->register_n, dec_reg);
                            int comp_reg = current_register;
                            current_register++;
			    fprintf(output,"%d	r%d:= r%d - r%d\n", instruction++, $3->register_n, $3->register_n, dec_reg);
			    fprintf(output,"%d	pc:= %d if not r%d\n", instruction++, jump_int, comp_reg);
			    new_record->is_reg = true;
                            new_record->register_n = product_reg;
			    $$= new_record;
			    }
      | NOT primary {record * new_record = newRec();
		     if($2->is_walkback){
		      fprintf(output, "%d	r%d := not contents r%d, %d\n",  instruction++, current_register, $2->walkback_n, $2->offset);
                      new_record->is_reg = true;
                      new_record->register_n = current_register;
                      current_register++;
		    }else if($2->is_reg){
		      fprintf(output, "%d	r%d := not r%d\n",  instruction++, current_register, $2->register_n);
		      new_record->is_reg = true;
                      new_record->register_n = current_register;
		      current_register++;
		    }else{
		      fprintf(output, "%d	r%d := not contents b, %d\n",  instruction++, current_register, $2->offset);
                      new_record->is_reg = true;
                      new_record->register_n = current_register;
		      current_register++;
		     }
		    $$ = new_record;
		    }
      ;



sequence_of_statements : statement_list
		       ;

statement_list: statement
	      | statement statement_list
	      ;


statement: looppart
	 | ifstruct
	 | name';'
	 | null_stmt 
	 | raise_i
	 ;

name: identifier opt_param opt_assign {
		 node_t * current_node = searchAll(array, current_position, $1);//There should be a node in the tree since it added before 
                 record * rec = newRec();
                 if(strcmp(current_node->kind, "read_routine")==0){
                     if($2->data->is_walkback){
                         fprintf(output, "%d	read contents r%d, %d\n",instruction++, $2->data->walkback_n, $2->data->offset);
                     }else{
                         fprintf(output,"%d	read %s%d \n", instruction++,
                         $2->data->is_reg?"r":"contents b, ",
                         $2->data->is_reg?$2->data->register_n:$2->data->offset);
                         }
                }else if(strcmp(current_node->kind, "write_routine")==0){
		      link head = $2;
		      while (head != NULL){
                      if(head->data->is_walkback){
                                fprintf(output, "%d     r%d := contents r%d, %d\n",  instruction++, current_register, head->data->walkback_n, head->data->offset);
				current_register++;
		      }
        	      fprintf(output,"%d      write %s%d \n", instruction++,
                                                              head->data->is_reg?"r":"contents b, ",
                                                              head->data->is_reg?head->data->register_n:head->data->offset);
        	      head = head->next;
    		     }
 
                      //instruction = printRecs($2, output, instruction);
                }else if($2 != NULL && $3 != NULL){
			//LHS ARRAY ALSO use for LHS records
				printf("The current node parent type is %s\n", current_node->parent_Type->kind);
				printf("The current component type is '%s'\n", current_node->parent_Type->component_type->kind);
				if(strcmp(current_node->parent_Type->component_type->kind, "array")==0){
				//For LHS Arrays of Arrays
					printf("Going into an array of arrays\n");
					record * first_exp = newRec();
					record * second_exp = newRec();
					second_exp = $2->data;
					first_exp = $2->next->data;
                                        node_t * second_node = current_node->parent_Type->component_type;
                                        if(first_exp->is_walkback){
                                             fprintf(output, "%d  r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                         }
                                        if(first_exp->is_walkback){
                                             fprintf(output, "%d  r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                        }
					fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    	int lower_r = current_register;
                                    	current_register++;
                                    	fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    	int upper_r = current_register;
                                    	current_register++;
                                    	if(!$2->data->is_reg){
                                      	fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, $2->data->offset);
                                      	$2->data->register_n = current_register;
                                      	current_register++;
                                    	}
                                    	fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,$2->data->register_n,
                                                                                         upper_r);
                                    	int upper_comp = current_register;
                                   	 current_register++;
                                    	fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          $2->data->register_n);
                                    	int lower_comp = current_register;
                                    	current_register++;
                                    	fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                    	is_raise = 1;
                                    	int i = instruction + 3;
                                    	fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    	fprintf(output,"%d	r1 := 1\n", instruction++);
                                    	//if there are no handlers need to jump to the base 
                                    	add_toPatchExp(instruction);
                                    	fprintf(output,"%d	pc := ?\n", instruction++);
                                    	current_register++;

					fprintf(output,"%d      r%d:= %d\n", instruction++, current_register,second_node->lower);
                                        int lower_reg = current_register;
                                        current_register++;
                                        fprintf(output,"%d      r%d:= %d\n", instruction++, current_register,second_node->upper);
                                        int upper_reg = current_register;
                                        current_register++;
                                        if(!second_exp->is_reg){
                                        fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, second_exp->offset);
                                        second_exp->register_n = current_register;
                                        current_register++;
                                        }
                                        fprintf(output,"%d      r%d:= r%d <= r%d\n", instruction++, current_register,second_exp->register_n,
                                                                                         upper_reg);
                                        int upper_comper = current_register;
                                         current_register++;
                                        fprintf(output,"%d      r%d:= r%d <= r%d\n", instruction++, current_register, lower_reg,
                                                                                          second_exp->register_n);
                                        int lower_comper = current_register;
                                        current_register++;
                                        fprintf(output, "%d     r%d:= r%d and r%d\n", instruction++, current_register, upper_comper, lower_comper);
                                        is_raise = 1;
                                        int in = instruction + 3;
                                        fprintf(output, "%d     pc := %d if r%d\n", instruction++,in, current_register);
                                        fprintf(output,"%d      r1 := 1\n", instruction++);
                                        //if there are no handlers need to jump to the base 
                                        add_toPatchExp(instruction);
                                        fprintf(output,"%d      pc := ?\n", instruction++);
                                        current_register++;

					      int space_1 = second_node->upper;
                                              space_1 = space_1 - second_node->lower;
                                              space_1++;
                                              int low = current_node->parent_Type->lower;
                                              //to find the offset I am taking the base offset then adding the two expressions onto it 
                                              //int space_1 = second_node->upper - second_node->lower;
					      int old_reg;
                                              int numberWalk = searchInt(array, current_position, $1);
                                              if(numberWalk == 0){
                                                fprintf(output, "%d     r%d := %d\n", instruction++, current_register, low);
                                                int w = current_register;
                                                current_register++;
                                                fprintf(output, "%d      r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
						int p = current_register;
                                                current_register++;
                                                fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
                                                int r = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, first_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset);
                                                int s = current_register;
                                                current_register++;
                                               	fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register, s);
						old_reg = current_register;
                                                current_register++;
                                              }else{
                                                  fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                                  while(numberWalk > 0){
                                                     fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                      numberWalk--;
                                                  }
						int walk_reg = current_register;
   						current_register++;
                                                fprintf(output, "%d	r%d := %d\n", instruction++, current_register, low);
                                                int w = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
						int p = current_register;
                                                current_register++;
                                                fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
                                                int r = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, first_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset);
 						current_register++;
						fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register, current_register-1, walk_reg);                                               
                                                old_reg = current_register;
                                                current_register++;
                                                //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                                current_register++;
                                                }
					int of = current_node->real_off - second_node->lower;
					if($3->is_walkback){
                                           fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, of, $3->walkback_n, $3->offset);
                                        }else if($3->is_reg){
                                           fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, of, $3->register_n);
                                        }else{
                                           fprintf(output, "%d	contents r%d, %d := contents b, %d\n",instruction++, old_reg, of, $3->offset);
                                        }

				}else if(strcmp(current_node->parent_Type->component_type->kind,"record")==0){
					printf("Going into an array of records\n");
					int numberWalk = searchInt(array, current_position, $1);
                                	int offset;
                                	struct rec_l *head = current_node->recor_l;
                                	node_t * type_node;
                                	while(head != NULL){
                                   	if(strcmp(head->name, $2->data->param_n)==0){
                                      		offset=head->offset;
                                      	type_node = searchAll(array, current_position, head->type);
                                   	break;
                                  	}
                                  	head = head->next;
				     }
					fprintf(output,"%d	 r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    int upper_r = current_register;
                                    current_register++;
                                    if(!$2->data->is_reg){
                                      fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, $2->data->offset);
                                      $2->data->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,$2->data->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          $2->data->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d 	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                   if($2->data->is_walkback){
                                     fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $2->data->register_n,$2->data->walkback_n, $2->data->offset);
                                    }
                                    int old_reg;
                                    if(numberWalk == 0){
				    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
                                    int i = current_register;
                                    current_register++; 
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i, $2->data->is_reg?"r":"contents b, ",
                                                                                                                   $2->data->is_reg?$2->data->register_n:$2->data->offset);
                                    int y = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
                                    int z = current_register;
                                    fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register,z);
				      old_reg = current_register;
                                      current_register++;
                                    }else{
                                      fprintf(output, "%d       r%d := b\n",  instruction++, current_register);
                                          while(numberWalk > 0){
                                                  fprintf(output, "%d   r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                  numberWalk--;
                                          }
                                    int reg = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
                                    int i = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i, $2->data->is_reg?"r":"contents b, ",
                                                                                                                   $2->data->is_reg?$2->data->register_n:$2->data->offset);
                                    int y = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
                                    int z = current_register;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,z, reg);
                                      old_reg = current_register;
                                      current_register++;

				     }
                                    if($3->is_walkback){
                                        fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, current_node->offset, $3->walkback_n, $3->offset);
                                    }else if($3->is_reg){
                                      fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, current_node->offset, $3->register_n);
                                    }else{
                                     fprintf(output, "%d	contents r%d, %d := contents b, %d\n",instruction++, old_reg, current_node->offset, $3->offset);
                                  }

                                

				
				}else if(strcmp(current_node->parent_Type->kind,"array")==0){
				    printf("Going into a regular array\n");
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
				    int upper_r = current_register;
                                    current_register++;
                                    if(!$2->data->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, $2->data->offset);
                                      $2->data->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,$2->data->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          $2->data->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                
                                   if($2->data->is_walkback){
                                     fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $2->data->register_n,$2->data->walkback_n, $2->data->offset);
                                    }
                                    int numberWalk = searchInt(array, current_position, $1);
				    int old_reg;
                                    if(numberWalk == 0){
                                      fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register,$2->data->is_reg?"r":"contents b, ", 
														   $2->data->is_reg?$2->data->register_n:$2->data->offset);
                                      old_reg = current_register;
                                      current_register++;
                                    }else{
                                      fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                          while(numberWalk > 0){
                                                  fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                  numberWalk--;
                                          }
                                     fprintf(output, "%d	r%d := r%d + %s%d\n",  instruction++, current_register, current_register, $2->data->is_reg?"r":"contents b, ",
                                                                                                                   $2->data->is_reg?$2->data->register_n:$2->data->offset);
                                     old_reg = current_register;
                                     current_register++;
                                    }
				    if($3->is_walkback){
                                        fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, current_node->offset, $3->walkback_n, $3->offset);
                                    }else if($3->is_reg){
                                      fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, current_node->offset, $3->register_n);
                                    }else{
                                     fprintf(output, "%d	contents r%d, %d := contents b, %d\n",instruction++, old_reg, current_node->offset, $3->offset);
                                  }
			    }
				
			    //For records
			    else if(strcmp(current_node->parent_Type->kind,"record")==0){
                       		//search the list to find the what is trying to be accessed 
				printf("Going into a regular record\n");
                        	int numberWalk = searchInt(array, current_position, $1);
                        	int offset;
                        	struct rec_l *head = current_node->recor_l;
				node_t * type_node;
                        	while(head != NULL){
                           	   if(strcmp(head->name, $2->data->param_n)==0){
                                      offset=head->offset;
				      type_node = searchAll(array, current_position, head->type);
                                   break;
                                  }
                                  head = head->next;
                                }
			     if(strcmp(type_node->kind, "array")==0){
				    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->upper);
                                    int upper_r = current_register;
                                    current_register++;
				    if(!$2->data->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, $2->data->offset);
                                      $2->data->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         $2->data->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                            $2->data->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;

                                   if($2->data->is_walkback){
                                     fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $2->data->register_n,$2->data->walkback_n, $2->data->offset);
                                    }
                                    int old_reg;
                                    if(numberWalk == 0){
                                      fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register,$2->data->is_reg?"r":"contents b, ",
                                                                                                                   $2->data->is_reg?$2->data->register_n:$2->data->offset);
                                      old_reg = current_register;
                                      current_register++;
                                    }else{
                                      fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                          while(numberWalk > 0){
                                                  fprintf(output, "%d   r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                  numberWalk--;
                                          }
                                     fprintf(output, "%d	r%d := r%d + r%d\n",  instruction++, current_register, current_register, $2->data->register_n);
                                     old_reg = current_register;
                                     current_register++;
                                    }
                                    if($3->is_walkback){
                                        fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, offset, $3->walkback_n, $3->offset);
                                    }else if($3->is_reg){
                                      fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, offset, $3->register_n);
                                    }else{
                                     fprintf(output, "%d	contents r%d, %d := contents b, %d\n", instruction++,  old_reg, offset, $3->offset);
                                  }




			     }else{
			     if(numberWalk ==0){
                                    if($3->is_walkback){
                                      fprintf(output, "%d	contents b, %d := contents r%d, %d\n",  instruction++, offset, $3->walkback_n, $3->offset);
                                    }else if($3->is_reg){
                                      fprintf(output, "%d	contents b, %d := r%d\n",  instruction++, offset, $3->register_n);
                                    }else{
                                      fprintf(output, "%d	contents b, %d := contents b, %d\n",  instruction++, offset, $3->offset);
                                   }
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                   while(numberWalk > 0){
                                        fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                        numberWalk--;
                                   }
                                   if($3->is_walkback){
                                      fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++, current_register,
                                                                                             offset, $3->walkback_n, $3->offset);
                                   }else{
                                   fprintf(output,"%d	contents r%d, %d := %s%d \n", instruction++, current_register,offset,
                                                                         $3->is_reg?"r":"contents b, ",
                                                                         $3->is_reg?$3->register_n:$3->offset);
                                  }
                                  current_register++;
                     	    }
			  }
			}

		 }else if ($2 == NULL && $3 != NULL){
		    //node_t * current_node = searchAll(array, current_position, $1);
				if(strcmp(current_node->parent_Type->kind,"range")==0){
				    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
				    int lower_r = current_register;
				    current_register++;
				    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
				    int upper_r = current_register;
				    current_register++;
				    if(!$3->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, $3->offset);
                                      $3->register_n = current_register;
                                      current_register++;
                                    }
				    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         $3->register_n,
                                                                                         upper_r);
				    int upper_comp = current_register;
				    current_register++;
				    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         $3->register_n);
				    int lower_comp = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                     current_register++;


				 }
                                 int numberWalk = searchInt(array, current_position, $1);
                                 if(numberWalk ==0){
                                    if($3->is_walkback){
                                      fprintf(output, "%d	contents b, %d := contents r%d, %d\n",  instruction++, current_node->offset, $3->walkback_n, $3->offset);
                                    }else if($3->is_reg){
                                      fprintf(output, "%d	contents b, %d := r%d\n",  instruction++, current_node->offset, $3->register_n);
                                    }else{
                                      fprintf(output, "%d	contents b, %d := contents b, %d\n",  instruction++, current_node->offset, $3->offset);
                                   }
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                   while(numberWalk > 0){
                                        fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                        numberWalk--;
                                   }
                                   if($3->is_walkback){
                                      fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++, current_register,
                                                                                             current_node->offset, $3->walkback_n, $3->offset);
                                   }else{
                                   fprintf(output,"%d	contents r%d, %d := %s%d \n", instruction++, current_register,current_node->offset,
                                                                         $3->is_reg?"r":"contents b, ",
                                                                         $3->is_reg?$3->register_n:$3->offset);
                                  }
                                  current_register++;
                                }
                                

		 }else{
		 //THIS IS FOR PROCEDURE CALLS, ADD A CHECK TO SEE IF THERE ARE ANY PARAMETER 
	         //do register and everything here 
		 //fprintf(output, "%d      contents b, %d := r%d\n",  instruction++, current_node->offset, $3->register_n); 
		 //TODO for function call
		 //node_t * current_node = searchAll(array, current_position, $1);//Finding the node for the procedure to get the size;
		 int x = searchInt(array, current_position, $1);
		 fprintf(output,"%d	r%d:= b\n", instruction++, current_register);
		 fprintf(output,"%d	b := contents r%d, 0\n", instruction++, current_register);
		 fprintf(output,"%d	contents b, 3 := r%d\n", instruction++, current_register);
		 if(x==0){
		 	fprintf(output,"%d	contents b, 2 := r%d\n", instruction++, current_register);
		  }else{
			//fprintf(output, "%d     r%d := contents b, 2\n",  instruction++, current_register);
			while(x>0){
			fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
			x--;
			}
			fprintf(output, "%d	contents b, 2 := r%d\n",  instruction++, current_register);
		  }
		 //Do the other one here
		 //Increase register
		 int theWalkBackReg = current_register;
		 current_register++;
		 fprintf(output,"%d	r%d:= %d\n", instruction++, current_register, current_node->lower);
		 fprintf(output,"%d	contents b, 0 := b + r%d\n", instruction++, current_register);
		 current_register++;
		 //check here for in and in out
		 if($2 != NULL){
		    //take the link from the procedure node
		    
		    //take exprlist and go over it
		    struct link *list = $2;
		    struct link * list_r;
		    while(list != NULL){
		        list_r = insertLinkRec2(list_r, list->data);
			list = list->next;
		    }
                    node_t * prodNode = current_node->next;
		    while($2 != NULL){
			if(strcmp(prodNode->mode,"In")==0){//IN
			  if($2->data->is_reg){
			    if($2->data->is_walkback){
                                fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $2->data->register_n,$2->data->walkback_n, $2->data->offset);
                             }
			  fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->offset,$2->data->register_n);
			  }else{
			   fprintf(output, "%d   contents b, %d := contents r%d, %d\n", instruction++, prodNode->offset, theWalkBackReg, $2->data->offset);
			  }
			}
			else if(strcmp(prodNode->mode,"In Out")==0){//IN OUT
                          if($2->data->is_reg){
			     if($2->data->is_walkback){
                                fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $2->data->register_n,$2->data->walkback_n, $2->data->offset);
                             }
                          fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->offset,$2->data->register_n);
                          }else{
                           fprintf(output, "%d	contents b, %d := contents r%d, %d\n", instruction++, prodNode->offset, theWalkBackReg, $2->data->offset);
                          }
			  fprintf(output, "%d	r%d := %d\n", instruction++, current_register, $2->data->offset);
			  int u = current_register;
			  current_register++;
			  fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register, theWalkBackReg, u);
			  int y = current_register;
			  current_register++;
			  fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->value,y);
                        }else if(strcmp(prodNode->mode,"Out")==0){//OUT
			 fprintf(output, "%d	r%d := %d\n", instruction++, current_register, $2->data->offset);
                          int u = current_register;
                          current_register++;
                          fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register, theWalkBackReg, u);
                          int y = current_register;
                          current_register++;
                          fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->value,y);
			}
			prodNode = prodNode->next;
                        $2 = $2->next;
		   
		   }
		 }
		 fprintf(output,"%d	r%d:= %d\n", instruction++, current_register, instruction+3);
		 fprintf(output,"%d	contents b, 1 := r%d\n", instruction++, current_register);
		 current_register++;
		 fprintf(output,"%d	pc := %d\n", instruction++, current_node->value);
		 return_except = instruction;	 
		 fprintf(output,"%d	pc := ? if r1\n", instruction++);
		 }
		}

	;
opt_param: '(' exprlist ')' {$$ = $2;}
	 | '(' exprlist ')''('exprlist ')' {struct link *head;
						head = initLinkRec($2->data);
						insertLinkRec(head, $5->data);
						$$ = head;
						}
	 | '('exprlist ')''.'ID{strcpy($2->data->param_n, $5); 
                                $$ = $2;
				}
	 | '.' ID opt_rec_arr {//for records
		   //need to add another option in the exprList for a string so I can pass up ID
		   if($3 == NULL){
		      struct link *head;
		      record * new_record = newRec();
		      strcpy(new_record->param_n,$2);
                      head = initLinkRec(new_record);
                      $$ = head;
		   }else{
		     strcpy($3->param_n, $2);
		     struct link *head;
		     head = initLinkRec($3);
		     $$ = head;
		   }
		  }
	 | {$$ = NULL;}
	;

looppart: loopStart loop_list_struct ENDLOOP ';'{fprintf(output,"%d	pc := %d\n", instruction++, $1);
						 struct link_toPatch *h = grab_toPatch();
  						 while (h != NULL){
						    insert_Patch(&patchList,h->value, instruction);
     						    //printf("%d ,", h->value);
     						    h = h->next;
    						  }
						  pop_toPatch();
						  //fprintf(output,"%d	pc := %d\n", instruction++, $1);
					        }

	;

loopStart: LOOP {$$ = instruction;
		push_toPatch();
		}
	 ;

loop_list_struct: loopstmt
		| loop_list_struct loopstmt
		;

loopstmt: statement
	| exit_statement
	;

exit_statement: EXIT ';' {add_toPatch(instruction);
                          fprintf(output,"%d	pc := ?\n", instruction++);
                         }
	      | EXITWHEN condition ';'{fprintf(output,"%d	pc := ? if r%d\n", instruction++, $2->register_n);
				      }
	      ;
 
null_stmt: NULLWORD ';'
	 ;

raise_i: RAISE identifier ';'{is_raise = 1;
			      node_t * current_node = searchAll(array, current_position, $2);
			      fprintf(output,"%d	r1 := %d\n", instruction++, current_node->value);
			      add_toPatchExp(instruction);
			      fprintf(output,"%d	pc := ?\n", instruction++);
			      
			     }
	| RAISE ';'         {is_raise = 1;
			     handler_done = 1;
			     add_toPatchExp(instruction);
                             fprintf(output,"%d	pc := ?\n", instruction++);
			     }
       ;


opt_assign: ASSIGN expression {$$= $2;}
	  | {$$ = NULL;}
	 ;

ifstruct: ifstart condition_if THEN sequence_of_statements else_if_sequence option_else_part end_if ';'{
												     struct link_toPatch *r = grab_toPatchCond();
                                                                      				     while (r != NULL){
                                                                          				insert_Patch(&patchList,r->value,$7);
                                                                          				//printf("inserting into if %d ,", h->value);
                                                                          				r = r->next;
                                                                      				      }
                                                                      				     //printf("\n");
												     struct link_toPatch *h = grab_toPatch();
                                                 						     while (h != NULL){
                                                    						     insert_Patch(&patchList,h->value, $7);
                                                    						     //printf("inserting into if %d ,", h->value);
                                                    						     h = h->next;
                                                 						     }
												     //printf("\n");
                                                  						     pop_toPatch();
												     pop_toPatchCond();
												    }
	;

ifstart: IF{
            push_toPatch();
	   push_toPatchCond();
	   }
       ;


else_if_sequence: else_if_list {
			       }
		|{
		}
	        ;

option_else_part: else_part
		| {struct link_toPatch *r = grab_toPatchCond();
                  while (r != NULL){
                      insert_Patch(&patchList,r->value,instruction);
                      r = r->next;
                   }
                 pop_toPatchCond();
		  }
		;

else_if_list: else_if else_if_list
	    | else_if
	    ;

else_if: else_if_start condition_if_else THEN sequence_of_statements {//struct link_toPatch *h = grab_toPatchCond();
                                                                      //while (h != NULL){
                                                                        //  insert_Patch(&patchList,h->value,instruction+1);
                                                                          //printf("inserting into if %d ,", h->value);
                                                                         // h = h->next;
                                                                     // }
                                                                      //printf("\n");
                                                                      //pop_toPatchCond();

								}
       ;


else_if_start: ELSEIF{struct link_toPatch *h = grab_toPatchCond();
                      while (h != NULL){
                      insert_Patch(&patchList,h->value,instruction+1);
                      //printf("inserting into if %d ,", h->value);
                      h = h->next;
                      }
                      //printf("\n");
		      //pop_toPatch();
                      pop_toPatchCond();
		      fprintf(output,"%d	pc := ?\n", instruction++);
		      add_toPatch(instruction-1);
		      
		     }
	     ;

else_part: else_start sequence_of_statements
	 ;


else_start: ELSE{  struct link_toPatch *h = grab_toPatchCond();
                      while (h != NULL){
                      insert_Patch(&patchList,h->value,instruction+1);
                      //printf("inserting into if %d ,", h->value);
                      h = h->next;
                      }
                      //printf("\n");
                      pop_toPatchCond();
		      fprintf(output,"%d        pc := ?\n", instruction++);
                      add_toPatch(instruction-1);
		}
   	  ;

end_if: ENDIF {$$=instruction;}
      ;

condition_if_else: expression{if($1->is_walkback){
                                 fprintf(output, "%d    r%d := contents r%d, %d \n",  instruction++, $1->register_n,$1->walkback_n, $1->offset);
                              }
			      push_toPatchCond();
			      add_toPatchCond(instruction);
			      fprintf(output,"%d     pc := ? if not r%d\n", instruction++, $1->register_n);
			     }

condition_if: condition{ fprintf(output,"%d	pc := ? if not r%d\n", instruction++, $1->register_n);
			}
	    ;

condition: expression{if($1->is_walkback){
                        fprintf(output, "%d    r%d := contents r%d, %d \n",  instruction++, $1->register_n,$1->walkback_n, $1->offset);
                      } 
		      $$ = $1;
		      push_toPatchCond();
		      add_toPatchCond(instruction);
		      //ifprintf(output,"%d	pc := ? if not r%d\n", instruction++, $1->register_n);
		     }
	 ;

relation_op: EQ {$$ = "=";}
	   | NEQ{$$ = "/=";}
	   | LT {$$ = "<";}
	   | LTE{$$ = "<=";}
	   | GT {$$ = ">";}
	   | GTE{$$ = ">=";}
	   ;

adding_op: '+'{$$ = "+";}
	  |'-'{$$ = "-";}
	 ;

multiplying_op: '*' {$$ = "*";}
	      | '/' {$$ = "/";}
	      ;


primary: NUMBER{
	        record * rec = newRec();
		rec->value = $1;
		rec->register_n = current_register;
		rec->is_reg = true;
		$$=rec;
		fprintf(output, "%d	r%d := %d\n",instruction++, current_register, $1);
		current_register++;
		//printf("This is the offset %d\n", $$->offset);
		}
       | ID {//look up local or do walk back find the node
	     node_t * current_node = searchAll(array, current_position, $1);//There should be a node in the tree since it added before 
	     record * rec = newRec();
	     if(strcmp(current_node->kind, "literal")==0){
		rec->value = current_node->value;
                rec->register_n = current_register;
                rec->is_reg = true;
                $$=rec;
                fprintf(output, "%d	r%d := %d\n",instruction++, current_register, current_node->value);
                current_register++;
	     }else{
	     	int numberWalk = searchInt(array, current_position, $1);
	     	if(numberWalk == 0){
			rec->offset = current_node->offset;
	     	}else{
			fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                	while(numberWalk > 0){
                     	   fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                           numberWalk--;
                      	   }
		      int old_reg = current_register;
		      current_register++;
                      //fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                      rec->register_n = current_register;
		      rec->offset = current_node->offset;
                      rec->is_reg = true;
		      rec->is_walkback = true;
		      rec->walkback_n = old_reg;
		      current_register++;

	             }
	    }
	     $$ = rec;
	    }
       | '(' expression ')' {$$ = $2;}
       | ID '('expression ')''('expression')'{//access arrays of arrays
					      node_t * current_node = searchAll(array, current_position, $1);
					      node_t * second_node = current_node->parent_Type->component_type;
                                	      record * rec = newRec();
                                	      if($3->is_walkback){
                                   		 fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                 	       }
					      if($6->is_walkback){
                                                 fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                               }
					      fprintf(output,"%d      r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
					     record * first_exp = newRec();
                                        record * second_exp = newRec();
                                        first_exp = $6;
                                        second_exp = $3;
                                        int lower_r = current_register;
                                        current_register++;
                                        fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                        int upper_r = current_register;
                                        current_register++;
                                        if(!$3->is_reg){
                                        fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, second_exp->offset);
                                        $3->register_n = current_register;
                                        current_register++;
                                        }
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,second_exp->register_n,
                                                                                         upper_r);
                                        int upper_comp = current_register;
                                         current_register++;
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          second_exp->register_n);
                                        int lower_comp = current_register;
                                        current_register++;
                                        fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                        is_raise = 1;
                                        int i = instruction + 3;
                                        fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                        fprintf(output,"%d	r1 := 1\n", instruction++);
                                        //if there are no handlers need to jump to the base 
                                        add_toPatchExp(instruction);
                                        fprintf(output,"%d	pc := ?\n", instruction++);
                                        current_register++;

                                        fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,second_node->lower);
                                        int lower_reg = current_register;
                                        current_register++; 
                                        fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,second_node->upper);
                                        int upper_reg = current_register;
                                        current_register++;
                                        if(!second_exp->is_reg){
                                        fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, first_exp->offset);
                                        second_exp->register_n = current_register;
                                        current_register++;
                                        }
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,first_exp->register_n,
                                                                                         upper_reg);
                                        int upper_comper = current_register;
                                         current_register++;
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_reg,
                                                                                          first_exp->register_n);
                                        int lower_comper = current_register;
                                        current_register++;
                                        fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comper, lower_comper);
                                        is_raise = 1;
                                        int in = instruction + 3;
                                        fprintf(output, "%d	pc := %d if r%d\n", instruction++,in, current_register);
                                        fprintf(output,"%d	r1 := 1\n", instruction++);
                                        //if there are no handlers need to jump to the base 
                                        add_toPatchExp(instruction);
                                        fprintf(output,"%d	pc := ?\n", instruction++);
                                        current_register++;
					      int space_1 = second_node->upper;
					      space_1 = space_1 - second_node->lower;
					      space_1++;
					      int low = current_node->parent_Type->lower;
					      //to find the offset I am taking the base offset then adding the two expressions onto it 
					      //int space_1 = second_node->upper - second_node->lower;
					      
					      int numberWalk = searchInt(array, current_position, $1);
                                	      if(numberWalk == 0){
						fprintf(output, "%d	r%d := %d\n", instruction++, current_register, low);
                                                int w = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
						int p = current_register;
						current_register++;
						fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
						int r = current_register;
						current_register++;
						fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, second_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset); 
						int s = current_register;
						current_register++;
                                   	       fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register, s);
                                                 rec->register_n = current_register;
                                                 rec->offset = current_node->real_off - second_node->lower;
                                                 rec->is_reg = true;
                                                 rec->is_walkback = true;
                                                 rec-> walkback_n = current_register;
                                                current_register++;
                                	      }else{
                                   		  fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                                  while(numberWalk > 0){
                                                     fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                      numberWalk--;
                                                  }
						int walk_reg = current_register;
						current_register++;
						fprintf(output, "%d	r%d := %d\n", instruction++, current_register, low);
						int w = current_register;
						current_register++;
                                                fprintf(output, "%d	r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
                                                int p = current_register;
                                                current_register++;
                                                fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
						int r = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, first_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset);
						current_register++;
                                                fprintf(output, "%d     r%d := r%d + r%d\n", instruction++, current_register, current_register-1, walk_reg);
                                                int old_reg = current_register;
                                                current_register++;
                                   		//fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                   		rec->register_n = current_register;
                                   		rec->offset = current_node->real_off - second_node->lower;
                                   		rec->is_reg = true;
                                   		rec->is_walkback = true;
                                   		rec->walkback_n = old_reg;
                                   		current_register++;
                                		}

					      $$= rec;
					     }
       | ID '(' expression ')' {node_t * current_node = searchAll(array, current_position, $1);
				record * rec = newRec();
				if($3->is_walkback){
                                   fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                 }
				if(strcmp(current_node->parent_Type->kind,"array")==0){
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    int upper_r = current_register;
                                    current_register++;
				    if(!$3->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, $3->offset);
                                      $3->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         $3->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         $3->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
				    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
				    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                 }
				int numberWalk = searchInt(array, current_position, $1);
				if(numberWalk == 0){
				    fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register, $3->is_reg?"r":"contents b, ",
                                                                                                             $3->is_reg?$3->register_n:$3->offset);
				    rec->register_n = current_register;
                        	    rec->offset = current_node->offset;
				    rec->is_reg = true;
                      		    rec->is_walkback = true;
				    rec-> walkback_n = current_register;
				    current_register++;
				}else{
				   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                        		while(numberWalk > 0){
                           			fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                           			numberWalk--;
                           		}
				   fprintf(output, "%d	r%d := r%d + r%d\n",  instruction++, current_register, current_register, $3->register_n);
                      	  	   int old_reg = current_register;
                      		   current_register++;
                      		   //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                      		   rec->register_n = current_register;
                      		   rec->offset = current_node->offset;
                      		   rec->is_reg = true;
                      		   rec->is_walkback = true;
                      		   rec->walkback_n = old_reg;
                      		   current_register++;
				}
				$$ = rec;
		  }

	  | ID '(' expression ')''.' ID {node_t * current_node = searchAll(array, current_position, $1);
                                record * rec = newRec();
				node_t * type_node;
                       //search the list to find the what is trying to be accessed 
                        int offset;
                        struct rec_l *head = current_node->recor_l;
                        while(head != NULL){
                           if(strcmp(head->name, $6)==0){
                                offset=head->offset;
                                type_node = searchAll(array, current_position, head->type);
                                break;
                           }
                           head = head->next;
                        }
	                

                                if($3->is_walkback){
                                   fprintf(output, "%d  r%d := contents r%d, %d \n",  instruction++, $3->register_n,$3->walkback_n, $3->offset);
                                 }
                                if(strcmp(current_node->parent_Type->kind,"array")==0){
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    int upper_r = current_register;
                                    current_register++;
                                    if(!$3->is_reg){
                                      fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, $3->offset);
                                      $3->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         $3->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         $3->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                 }
                                int numberWalk = searchInt(array, current_position, $1);
                                if(numberWalk == 0){
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
				    int i = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++; 
				    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i,  $3->is_reg?"r":"contents b, ",
                                                                                                             $3->is_reg?$3->register_n:$3->offset);
				    int y = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
				    int z = current_register;
				    fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register,z);
                                    rec->register_n = current_register;
                                    rec->offset = current_node->real_off;
                                    rec->is_reg = true;
                                    rec->is_walkback = true;
                                    rec-> walkback_n = current_register;
                                    current_register++;
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                        while(numberWalk > 0){
                                                fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                numberWalk--;
                                        }
				    int reg = current_register;
				    current_register++;
				   fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
                                    int i = current_register;
                                    current_register++; 
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i,  $3->is_reg?"r":"contents b, ",
                                                                                                             $3->is_reg?$3->register_n:$3->offset);
                                    int y = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
                                   fprintf(output, "%d	r%d := r%d + r%d\n",  instruction++, current_register, current_register, reg);
                                   int old_reg = current_register;
                                   current_register++;
                                   //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                   rec->register_n = current_register;
                                   rec->offset = current_node->real_off;
                                   rec->is_reg = true;
                                   rec->is_walkback = true;
                                   rec->walkback_n = old_reg;
                                   current_register++;
                                }
				rec->offset = rec->offset + offset;
                                $$ = rec;


	  }
	  |ID '.' ID opt_rec_arr{//used for records
		       node_t * current_node = searchAll(array, current_position, $1);
		       record * rec = newRec();
			node_t * type_node;
			int numberWalk = searchInt(array, current_position, $1);
		       //search the list to find the what is trying to be accessed 
			int offset;
			struct rec_l *head = current_node->recor_l;
                        while(head != NULL){
			   if(strcmp(head->name, $3)==0){
			   	offset=head->offset;
				type_node = searchAll(array, current_position, head->type);
				break;
			   }	
                           head = head->next;
			}
			if($4 != NULL){
			//for arrays
			if($4->is_walkback){
                           fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, $4->register_n,$4->walkback_n, $4->offset);
                        }
			   if(strcmp(type_node->kind,"array")==0){
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->upper);
                                    int upper_r = current_register;
                                    current_register++;
				    if(!$4->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, $4->offset);
                                      $4->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         $4->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         $4->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                 }
                                if(numberWalk == 0){
                                    fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register, $4->is_reg?"r":"contents b, ",
													     $4->is_reg?$4->register_n:$4->offset);
                                    rec->register_n = current_register;
                                    rec->offset = offset;
                                    rec->is_reg = true;
                                    rec->is_walkback = true;
                                    rec-> walkback_n = current_register;
                                    current_register++;
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                        while(numberWalk > 0){
                                                fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                numberWalk--;
                                        }
                                   fprintf(output, "%d	r%d := r%d + %s%d\n",  instruction++, current_register, current_register, $4->is_reg?"r":"contents b, ",
                                                                                                                                 $4->is_reg?$4->register_n:$4->offset);
                                   int old_reg = current_register;
                                   current_register++;
                                   //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                   rec->register_n = current_register;
                                   rec->offset = offset;
                                   rec->is_reg = true;
                                   rec->is_walkback = true;
                                   rec->walkback_n = old_reg;
                                   current_register++;
                                }
			}else{
                	    if(numberWalk == 0){
                        	rec->offset = offset;
                	   }else{
                        	fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                        	while(numberWalk > 0){
                           	  fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                           	  numberWalk--;
                           	}	
                      		int old_reg = current_register;
                      		current_register++;
                      		//fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                     		rec->register_n = current_register;
                      		rec->offset = offset;
                      		rec->is_reg = true;
                      		rec->is_walkback = true;
                      		rec->walkback_n = old_reg;
                      		current_register++;
                            }
			  }
			  $$ = rec;

		     }
       ;

opt_rec_arr : '(' expression ')'{ $$ = $2;}
	    | {$$ = NULL;}
	    ;

exception_part: exception_start exceptionList { int u = instruction + exception_count -1;
						if(handler_done != 0){
						 insert_Patch(&patchList, exception_jump, instruction-1);
						 for(int i = 1; i < exception_count; i++){
							if(jump_table[i] == 0){
							  fprintf(output, "%d	pc: = %d\n", instruction++, u);
							}else{
                                                        fprintf(output, "%d	pc := %d\n", instruction++,jump_table[i]);
							}
                                                   } 
						
						}else{
						  if(is_raise != 0){
						  insert_Patch(&patchList, exception_jump, instruction-1);
						  for(int i = 1; i < exception_count; i++){
							if(jump_table[i] == 0){
							  if(jump_table[0] == 0){
								fprintf(output, "%d	pc := %d\n", instruction++, u);	
							  }else{
							  fprintf(output, "%d	pc := %d\n", instruction++, jump_table[0]);
							  }
							}else{
							  fprintf(output, "%d	pc := %d\n", instruction++,jump_table[i]);
						   	}
						    }
						 }
						}
						
						 struct link_toPatch *h = grab_toPatchExp();
                                                while (h != NULL){
                                                  insert_Patch(&patchList,h->value, instruction);
                                                  //printf("inserting into if %d ,", h->value);
                                                  h = h->next;
						}
						for(int i =0; i < 20; i++){
						   jump_table[i] = 0;
						}
						is_raise = 0;
						handler_done =0;
						return_except =0;
						pop_toPatchExp();
					      }
	      | {//if there is nothin
		 if(is_raise != 0){
		 struct link_toPatch *h = grab_toPatchExp();
                 while (h != NULL){
                     insert_Patch(&patchList,h->value, instruction);
                     //printf("inserting into if %d ,", h->value);
                     h = h->next;
                
		  }
		 }
		if(return_except != 0){
		insert_Patch(&patchList,return_except, instruction);
		}
		}
	      ;

exception_start: EXCEPTION{
                                 struct link_toPatch *h = grab_toPatchExp();
                                 int instruct = instruction+1;
                                    while (h != NULL){
                                        insert_Patch(&patchList,h->value, instruct);
                                        //printf("inserting into if %d ,", h->value);
                                         h = h->next;
                                     }
                               
			       pop_toPatchExp();
                               push_toPatchExp();
                               add_toPatchExp(instruction);
                               fprintf(output, "%d     pc := ?\n", instruction++);
                               exception_jump = instruction;
			       if(return_except != 0){
			          insert_Patch(&patchList,return_except, instruction);
			       }
                               fprintf(output, "%d     pc := r1, ?\n", instruction++);
			       is_raise = 1;
			   }
		;

exceptionList: exceptionList excepthand
	     | excepthand
	     ;

excepthand: WHEN choice_sequence ARROW sequence_of_statements 
	    {//if(handler_done == 0){
	     fprintf(output, "%d	r1 := 0\n", instruction++);
	     add_toPatchExp(instruction);
	     fprintf(output, "%d	pc := ?\n", instruction++);
	    // }
	    }
	  ;

choice_sequence : ID {node_t * current_node = searchAll(array, current_position, $1);
		     $$ = current_node->value;
		     jump_table[current_node->value] = instruction;
		     }
		| OTHERS {$$= 1;
			  jump_table[0] = instruction;
			 }
		;


%%
int main()
{
	output = fopen("simple.out", "w");
	push(array, &current_position, "Outer Context");
 	addOuter(array, current_position);
	yyparse();
	fclose(output);
}

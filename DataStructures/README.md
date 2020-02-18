# Data Structures
Below are a brief description of each of the data structures and how they were used in the compiler. 

#### bintree.c
A stack of binary trees with ability to search an individual tree or search the entire stack to find a node. Nodes can only be added to the top of the stack however. This is the core data structure for the compiler as all of the variables and data types are stored here. Also have the ability to know how deep in the stack a node was found. This is useful when trying to find if an element is local or non-local based on the location in the stack. 

### linkedList.c
A basic linked list data structure. This is used to move information about data types such as integer, boolean, array or record.

### patchLink.c
A linked list that keeps track of the line numbers and values that need to be used for patching. Whenever there is a jump the values need to patched. In the final code, ? represent values that need to be patched. 

### rec_l.c
A linked list of records that keep track of the variable name, type and the amount of memory space. Makes it easy for information when trying to keep track of the record variable type.  

### record.c
A linked list of records that stories information about variables, such as type, register number, offset and if it is local or non-local.   


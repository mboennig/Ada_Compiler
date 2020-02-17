# Ada_Compiler
The compiler takes source code writen in Ada and produces compiled code. A sample of this compiled code can be seen in *simple.out*. The compiler seperates the Ada code into tokens, then parses these tokens and puts them into code trees. The compiler makes basic syntax checks. This compiler does not handle the full Ada langauge, but it does handle a large subset of it (see below). 

###Features of the Compiler
1.
2.
3.
4.
5.
6.


###Layout of Folders
* Compiled Program - The compiled program with instructions on how to run
* Data Structures - All of the data structures used in the program 
* Test Programs - A variety of Ada programs used to test functionality


#How to run the compiler 

###Prerequisites:
Lex Flex Yacc Bison Extension by Faustino Aguilar for reading the syntax in the ada.y file


###Running the program 
1. Choose from the Ada files un the Test Programs folder. You can also use your own Ada program but remember that this compiler only handles a subset of the Ada language (see the features section)
2. Rather than including a compiled program that might not work with every system I included a bash script to compile the program. 

# Ada_Compiler
The compiler takes source code written in Ada and produces compiled code. A sample of this compiled code can be seen in *simple.out*. The compiler separates the Ada code into tokens, then parses these tokens and puts them into code trees. The compiler makes basic syntax checks. This compiler does not handle the full Ada language, but it does handle a large subset of it (see below). The Ada grammar is contained within the *ada.y* and *ada.l* files. The *ada.y* file contains a majority of the grammar specifications as well as the C code that goes along with it. All the data structures used in *ada.y* are included in a separate folder. 

### Features of the Compiler
1. Mutliple data types (arrays, records, local and non-local)
2. Procedure calls
3. Loops
4. If statements 
5. Input and output calls
6. Exceptions in Ada 
7. Prologue and Epilogue


### Layout of Folders
* Data Structures - All of the data structures used in the program 
* Test Programs - A variety of Ada programs used to test functionality


# How to run the compiler 

### Prerequisites:
Lex Flex Yacc Bison Extension by Faustino Aguilar for reading the syntax in the ada.y file


### Running the program 
1. Choose from the Ada files un the Test Programs folder. You can also use your own Ada program but remember that this compiler only handles a subset of the Ada language (see the features section). I would recommend looking at the formatting of the example files first. 
2. Open the bash script that is included called *ada_bash* and change the input to be the ada file that you would like to test 
3. If all the prerequisites are in place then the script should output a file called *simple.out* 

Note: if running on Windows would recommending getting the Lex Flex Yacc Bison Extension for Visual Studio. 


### Example of program output
#### Input Ada File
```
   procedure upper is
   begin
       null;
   end;
   procedure nest is
      bbb : boolean;
       procedure inner is
           procedure innest is
           begin
              a := 5;   -- big walkback to get a's base
              upper;    -- must walkback static links here
           end;
       begin
          innest;
          bbb := true;  --one walkback
       end;
   begin
       bbb := false;  -- local access
       upper;  --call sibling (get caller's static link)
       inner;  --call child
   end;
begin
   nest;
end;
```
#### File Output from Compiler
```
0 	b := ?
1	contents b, 0 := ?
2	contents b, 1 := 5
3	r1 := 0
4	pc := ?
5	halt
6	r2 := contents b, 1
7	b := contents b, 3
8	pc := r2
9	r3 := 5
10	r4 := b
11	r4 := contents r4, 2
12	r4 := contents r4, 2
13	r4 := contents r4, 2
14	contents r4, 4 := r3
15	r5:= b
16	b := contents r5, 0
17	contents b, 3 := r5
18	r5 := contents r5, 2
19	r5 := contents r5, 2
20	r5 := contents r5, 2
21	contents b, 2 := r5
22	r6:= 4
23	contents b, 0 := b + r6
24	r7:= 27
25	contents b, 1 := r7
26	pc := 6
27	pc := ? if r1
28	r8 := contents b, 1
29	b := contents b, 3
30	pc := r8
31	r9:= b
32	b := contents r9, 0
33	contents b, 3 := r9
34	contents b, 2 := r9
35	r10:= 4
36	contents b, 0 := b + r10
37	r11:= 40
38	contents b, 1 := r11
39	pc := 9
40	pc := ? if r1
41	r12 := 1
42	r13 := b
43	r13 := contents r13, 2
44	contents r13, 4 := r12
45	r14 := contents b, 1
46	b := contents b, 3
47	pc := r14
48	r15 := 0
49	contents b, 4 := r15
50	r16:= b
51	b := contents r16, 0
52	contents b, 3 := r16
53	r16 := contents r16, 2
54	contents b, 2 := r16
55	r17:= 4
56	contents b, 0 := b + r17
57	r18:= 60
58	contents b, 1 := r18
59	pc := 6
60	pc := ? if r1
61	r19:= b
62	b := contents r19, 0
63	contents b, 3 := r19
64	contents b, 2 := r19
65	r20:= 4
66	contents b, 0 := b + r20
67	r21:= 70
68	contents b, 1 := r21
69	pc := 31
70	pc := ? if r1
71	r22 := contents b, 1
72	b := contents b, 3
73	pc := r22
74	r23:= b
75	b := contents r23, 0
76	contents b, 3 := r23
77	contents b, 2 := r23
78	r24:= 5
79	contents b, 0 := b + r24
80	r25:= 83
81	contents b, 1 := r25
82	pc := 48
83	pc := ? if r1
84	r26 := contents b, 1
85	b := contents b, 3
86	pc := r26
0 , 87
1 , 92
4 , 74
27 , 28
40 , 45
70 , 71
83 , 84
```
At the bottom are the values that are patched at the end of the program replacing the *?*. 

### Credit
*  Compiler Construction Course Professor- Laurie Smith King
*  John Levine, Lex & Yacc, 2nd Edition


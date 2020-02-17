/* Matthew Boennighausen
 Project Part 2
 ada.l
*/

%{
#include "y.tab.h"
int lineno = 1;
%}

%%
[ \t]+ //ignore white space
[-]?[0-9]+ {yylval.integer = atof(yytext); return NUMBER;}
[\n] {lineno++;}
--.*\n {lineno++; break;}
"end if" {return ENDIF;}
"type" {return TYPE;}
"if" {return IF;}
">" {return GT;}
"end record" {return ENDREC;}
"array" {return ARRAY;}
"then" {return THEN;}
"<" {return LT;}
"end loop" {return ENDLOOP;}
"record" {return RECORD;}
"elsif" {return ELSEIF;}
">=" {return GTE;}
"<=" {return LTE;}
"exit when" {return EXITWHEN;}
"in" {return IN;}
"else" {return ELSE;}
"is" {return IS;}
"out" {return OUT;}
"exit" {return EXIT;}
"**" {return EXP;}
"of" {return OF;}
"range" {return RANGE;}
"when" {return WHEN;}
"raise" {return RAISE;}
"begin" {return BEG;}
"constant" {return CONSTANT;}
"and" {return AND;}
"others" {return OTHERS;}
"end" {return END;}
":=" {return ASSIGN;}
"or" {return OR;}
"=>" {return ARROW;}
".." {return DOTDOT;}
"exception" {return EXCEPTION;}
"not" {return NOT;}
"'" {return TICK;}
"null" {return NULLWORD;}
"=" {return EQ;}
"procedure" {return PROCEDURE;}
"loop" {return LOOP;}
"/=" {return NEQ;}
[a-zA-z][a-zA-Z0-9_]* {yylval.var = strdup(yytext); return ID; /*This is for identifiers*/}
. {return yytext[0];}
%%

int yyerror(char *s){
printf("%d %s at the '%s' symbol\n", lineno, s, yytext);
}

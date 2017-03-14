 /* Lexical tokens for IMP */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tmp/imp.tab.h"
%}

%option yylineno

%%

 /* Operators */
":=" { return Af; }
"skip" { return Sk; }
";" { return Se; }
"if" { return If; }
"then" { return Th; }
"else" { return El; }
"while" { return Wh; }
"do" { return Do; }
"+" { return Pl; }
"-" { return Mo; }
"*" { return Mu; }
"(" { return Open; }
")" { return Close; }

 /* Manage integers */
([1-9][0-9]*)|0 {yylval.constant = atoi(yytext);return I; }
 /* Manage variables
[a-zA-Z_][a-zA-Z0-9_]* { yylval.variable = strdup(yytext); return V; }

 /* Handle line return */
[ \t\n] {;}

. {;}

%%

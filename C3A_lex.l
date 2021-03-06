 /* Lexical tokens for C3A */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tmp/c3a.tab.h"
%}

%option yylineno

%%

 /* Operators */
"Pl" {return Pl;}
"Mo" {return Mo;}
"Mu" {return Mu;}
"Af" {return Af;}
"Afc" {return Afc;}
"Sk" {return Sk;}
"Jp" {return Jp;}
"Jz" {return Jz;}
"St" {return St;}
"(" {return Open;}
")" {return Close;}
"-" {return Minus;}
"+" {return Plus;}

":" {return Sp;}
\n {return Se;}

 /* Manage integers */
([1-9][0-9]*)|0 { yylval.constant = atoi(yytext); return I; }
 /* Manage variables */
[a-zA-Z_][a-zA-Z0-9_]* { yylval.variable = strdup(yytext); return V; }

[ \t] {;} //Ignore

. {;}

%%

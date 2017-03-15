%{
    /* INCLUDES */
	#include <stdio.h>
	#include <string.h>
	#include "include/Environment.h"
	#include "include/Quadruplet.h"
	// Specific
	#include "include/C3A_Compiler.h"

	int yyerror(char *s);
	int yylex();
	int yylineno;
%}
    /* Start state */
	%start app

    /* Types used */
	%union {
		int constant;
		char* var;
		struct Arg* arg;
		struct Quad quad;
		struct Bilquad* bilquad;
	}

    // Arguments / values
	%type<arg> F FI
	// Bilquad - Liste chaînée de Quadruplets
	%type<bilquad> C
	// QUAD
	%type<quad> O

    // VARIABLES
	%token<var>V
	// INTEGERS
	%token<constant>I
	// OPERATORS
	%token Open Close Pl Mo Mu Af Afc Sk Jp Jz St Sp Se Minus Plus


    // ASSOCIATIVITY
    %left Se
	%left Pl Mo
	%left Mu
	%left Open


%%

 /* In this program, we will just compile the C3A code to Y86 one */
app: C	{
			C3A_compile_in_y86($1);
	 	}
    ;
 /* Command */
C : V Sp O
    | Sp O
    | C Se C
    | C Se
    ;

 /* Operators */
O : Pl Sp F Sp F Sp V
    | Mo Sp F Sp F Sp V
    | Mu Sp F Sp F Sp V
    | Af Sp V Sp F Sp
    | Afc Sp FI Sp Sp V
    | Sk Sp Sp Sp
    | Jp Sp Sp Sp V
    | Jz Sp F Sp Sp V
    | St Sp Sp Sp
    ;

 /* Variables and integers */
F : I
    | Minus I
    | Plus I
    | V
    ;
 /*
FI : I
    | Minus I
    | Plus I
    ;

%%

/* Handling error function */
int yyerror(char *s)
{
    fprintf(stderr, "Error detected: %s at %d\n", s, yylineno);
}

/* Main Function */
int main()
{
	yyparse();
}


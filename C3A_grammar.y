%{
    /* INCLUDES */
	#include <stdio.h>
	#include "include/Environment.h"
	#include "include/Quadruplet.h"
	#include "include/C3A_Interpretor.h"

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

    // VARIABLES
	%token<var>V
	// INTEGERS
	%token<constant>I
	// OPERATORS
	%token Open Close Pl Mo Mu Af Afc Sk Jp Jz St Sp Se Minus Plus
    // Arguments / values
	%type<arg> F FI
	// Bilquad - Liste chaînée de Quadruplets
	%type<bilquad> C
	// QUAD
	%type<quad> O

    // ASSOCIATIVITY
    %left Se
	%left Pl Mo
	%left Mu
	%left Open
	

%%

/* We shall begin by initializing the Environment variable */
app: C	{
			Environment e;
			Env_initEnv(e);
			C3A_run($1, e);
			Env_print(&env);
	 	}
    ;


C: V Sp O
    | Sp O
    | C Se C
    | C Se
    ;

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

F: I
    | Minus I
    | Plus I
    | V
    ;

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


%{
    /* INCLUDES */
	#include <stdio.h>
	#include <string.h>
	#include "include/Environment.h"
	// Specific
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
        Quad quad;
        Bilquad bilquad;
	    Arg *arg;
		int constant;
		char *var;
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

/* In this program, we will just interpret the analysed C3A code and print the Environment resulting from this */
app: C {
            // Initing environment
			Environment e;
			Environment_initEnv(e);
			// Simulating app
			C3A_Interpretor_simulate($1, e);
			// Printing environment we got from this
			Environment_print(&env);
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
int yyerror(char *s){
    fprintf(stderr, "Error detected: %s at %d\n", s, yylineno);
}

/* Main Function */
int main(){
	yyparse();
}


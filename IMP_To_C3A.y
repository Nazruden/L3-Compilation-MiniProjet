%{
    /* INCLUDES */
  	#include <stdio.h>
  	#include "include/Environment.h"
  	// Specific
  	#include "include/Syntax_Tree.h"
  	#include "include/IMP_Compiler.h"


	int yyerror(char *s);
	int yylex();
	int yylineno;
%}
    /* Start state */
	%start app

    /* Types used */
	%union {
		STree tree;
		int constant;
		char* variable;
	}

    // TREES
    %type<tree> C E T F

    // VARIABLES
	%token<variable>V
	// INTEGERS
	%token<constant>I
	// OPERATORS
	%token Af Sk Se If Th Wh Do Pl Mo Mu Open Close

    // ASSOCIATIVITY
	%nonassoc El Th
	%left Pl Mo
	%left Mu
	%left Open

%%

 /* In this program, we will just compile the IMP code to C3A one */
app: C {
	 		// Calling the compiler function
	 		IMP_compile_in_C3A($1);
	   }
    ;

 /** IMP Grammar **/
 /* Basic expression */
E: E Pl T { $$ = STree_create('E', Pl, $1, $3); }
    | E Mo T { $$ = STree_create('E', Mo, $1, $3); }
    | T { $$ = $1; }
    ;

 /* Mu forms */
T: T Mu F { $$ = STree_create('E', Pl, $1, $3); }
    | F { $$ = $1 }
    ;

F: Open E Close { $$ = $2; }
    | I { $$ = STree_createLeaf('I', &$1); }
    | Mo I { $2 = $2 * (-1); $$ = STree_createLeaf('I', &$2); }
    | V { $$ = STree_createLeaf('I', &$2); }
    ;

 /* Commands */
C: V Af E { $$ = STree_create('C', Af, STree_createLeaf('V', $1), $3); }
    | Sk { $$ = STree_creaate('C', Sk, 0,0); }
    | Open C Close { $$ = $2; }
    | If E Th C El C { $$ = STree_create('C', If, $2, STree_create('C', El, $4, $6)); }
    | Wh E Do C { $$ = STree_create('C', Wh, $2, $4);}
    | C Se C { $$ = STree_create('C', Se, $1, $3);}
    | C Se { $$ = STree_create('C', Se, $1, 0);}
    ;

%%

/* Handling error function */
int yyerror(char *s){
    fprintf(stderr, "error: %s near %d\n", s, yylineno);
}

/* Main Function */
int main(){
	yyparse();
}



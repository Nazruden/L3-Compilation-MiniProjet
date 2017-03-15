%{
    /* INCLUDES */
  	#include <stdio.h>
  	#include "include/Environment.h"
  	#include "include/Quadruplet.h"
  	#include "include/C3A_Interpretor.h"
	#include <stdio.h>
	#include "include/Ast.h"
	#include "include/IMP.h"
	#include "include/Env.h"

	int yyerror(char *s);
	int yylex();
	int yylineno;
%}
    /* Start state */
	%start app

    /* Types used */
	%union {
		int constant;
		char* variable;
		STree tree;
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
app: C	{
	 		IMP_compile_in_C3A($1);
	 	}
    ;


E: E Pl T
    | E Mo T
    | T
    ;

T: T Mu F
    | F
    ;

F: Open E Close
    | I
    | Mo I
    | V
    ;

C : V Af E {$$ = Ast_init('C', Af, Ast_IMP_init_leaf('V', $1), $3);}
    | Sk {$$ = Ast_init('C', Sk, 0,0);}
    | Open C Close {$$ = $2;}
    | If E Th C El C {$$=Ast_init('C', If, $2, Ast_init('C', El, $4, $6));}
    | Wh E Do C {$$=Ast_init('C', Wh, $2, $4);}
    | C Se C { $$ = Ast_init('C', Se, $1, $3);}
    | C Se { $$ = Ast_init('C', Se, $1, 0);}
    ;

%%

/* Handling error function */
int yyerror(char *s)
{
    fprintf(stderr, "error: %s near %d\n", s, yylineno);
}

/* Main Function */
int main()
{
	yyparse();
}


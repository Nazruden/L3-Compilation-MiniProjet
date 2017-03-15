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

	%union {
		int constant;
		char* variable;
		struct Ast *node;
	}

	%token<variable>V
	%token<constant>I
	%token Af Sk Se If Th Wh Do Pl Mo Mu Open Close
	%start prog 

	%type<node> C E T F

	%nonassoc El Th

	%left Pl Mo
	%left Mu
	%left Open
	

%%

/* Un programme est une suite de déclaration (C) composé de déclaration atomique (C0) */ 
prog: C	{ 
	 		Environment env;
			Environment_initEnv(&env);
			Ast_IMP_run($1, &env);
			Env_print(&env);
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

C: V Af E {$$ = Ast_init('C', Af, Ast_IMP_init_leaf('V', $1), $3);}
    | Sk {$$ = Ast_init('C', Sk, 0,0);}
    | Open C Close {$$ = $2;}
    | If E Th C El C {$$=Ast_init('C', If, $2, Ast_init('C', El, $4, $6));}
    | Wh E Do C {$$=Ast_init('C', Wh, $2, $4);}
    | C Se C { $$ = Ast_init('C', Se, $1, $3);}
    | C Se { $$ = Ast_init('C', Se, $1, 0);}
    ;





%%

int main()
{
	yyparse();
}


int yyerror(char *s)
{
 fprintf(stderr, "error: %s near %d\n", s, yylineno);
}
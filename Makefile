int_imp: IMP_lex.l IMP_grammar.y
	bison -d IMP_grammar.y
	flex IMP_lex.l
	cc -o test/int_imp tmp/imp.tab.h lex.yy.c include/*.c -lfl -DDEBUG
	rm *.c;

comp_imp: IMP_lex.l IMP_To_C3A.y
	bison -d IMP_To_C3A.y
	flex IMP_lex.l
	cc -o test/comp_imp tmp/imp.tab.h lex.yy.c include/*.c -lfl
	rm *.c;

comp_c3a: C3A_lex.l C3A_To_Y86.y
	bison -d C3A_To_Y86.y
	flex C3A_lex.l
	cc -o test/comp_c3a tmp/c3a.tab.h lex.yy.c include/*.c -lfl
	rm *.c;

int_c3a: C3A_lex.l C3A_grammar.y
	bison -d C3A_grammar.y
	flex C3A_lex.l
	cc -o test/int_c3a tmp/c3a.tab.h lex.yy.c include/*.c -lfl -DDEBUG
	rm *.c;

iimp: imp.c
	make comp_imp
	make comp_c3a
	cc -o test/iimp imp.c

parser: y.tab.c lex.yy.c action.c symbolTable.c labelStack.c
	gcc y.tab.c lex.yy.c action.c symbolTable.c labelStack.c -ll -ly -o Parser

y.tab.c: parser.y 
	bison -y -d parser.y

lex.yy.c: scanner.l
	flex scanner.l

clean: 
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	rm Parser
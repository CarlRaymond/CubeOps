lex.yy.c : scanner
	flex scanner
  
y.tab.c : parser
	yacc -d -v parser

lex.yy.o : lex.yy.c
	cc -c lex.yy.c

y.tab.o : y.tab.c
	cc -c y.tab.c

cube.o : cube.c
	cc -c cube.c

cube : cube.o y.tab.o lex.yy.o
	cc -o cube cube.o y.tab.o lex.yy.o -L/usr/people/bosch/lib -lfl


  
  

#ifndef YYERRCODE
#define YYERRCODE 256
#endif

#define U_TOK 257
#define D_TOK 258
#define L_TOK 259
#define R_TOK 260
#define F_TOK 261
#define B_TOK 262
#define LIST_TOK 263
#define SAVE_TOK 264
#define LOAD_TOK 265
#define QUIT_TOK 266
#define INT_TOK 267
#define SYMBOL_TOK 268
#define STRING_TOK 269
typedef union { struct operator op;
         struct symbol *sym;
         char *str;
	 int ival;
       } YYSTYPE;
extern YYSTYPE yylval;

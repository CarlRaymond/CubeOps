#ifndef lint
static char const 
yyrcsid[] = "$FreeBSD: src/usr.bin/yacc/skeleton.c,v 1.28 2000/01/17 02:04:06 bde Exp $";
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
static int yygrowstack();
#define YYPREFIX "yy"
#line 2 "parser"
/* Elucidates permutaions on Rubik's Cube */
/* CJR */

#include <stdio.h>
#include "operator.h"
#include "cube.h"
#include "symbol.h"

extern struct operator U, D, L, R, F, B;

#line 15 "parser"
typedef union { struct operator op;
         struct symbol *sym;
         char *str;
	 int ival;
       } YYSTYPE;
#line 34 "y.tab.c"
#define YYERRCODE 256
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
const short yylhs[] = {                                        -1,
    1,    1,    1,    1,    1,    1,    2,    2,    2,    2,
    2,    3,    3,    4,    4,    4,    4,    4,    4,    4,
    5,    5,    0,
};
const short yylen[] = {                                         2,
    1,    1,    1,    1,    1,    1,    1,    2,    2,    3,
    1,    1,    2,    2,    4,    2,    3,    3,    2,    2,
    0,    2,    1,
};
const short yydefred[] = {                                     21,
    0,    0,    0,    1,    2,    3,    4,    5,    6,    0,
    0,    0,    0,    0,    0,    7,    0,    0,   22,   20,
   16,    0,    0,   19,    0,   11,    0,    9,    8,   14,
    0,   17,   18,    0,   10,   15,
};
const short yydgoto[] = {                                       1,
   16,   17,   18,   19,    2,
};
const short yysindex[] = {                                      0,
    0,  -26,  -55,    0,    0,    0,    0,    0,    0,  -54,
 -263, -262,  -51,  -52,   46,    0,  -18,   10,    0,    0,
    0,  -49,  -47,    0,   46,    0,   22,    0,    0,    0,
  -18,    0,    0,   34,    0,    0,
};
const short yyrindex[] = {                                      0,
    0,   15,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -39,    0,    0,  -14,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   -2,    0,    0,    0,    0,    0,
};
const short yygindex[] = {                                      0,
    0,  -16,  -12,    0,    0,
};
#define YYTABLESIZE 314
const short yytable[] = {                                      11,
   11,   31,   27,   20,   21,   22,   23,   24,   25,   32,
   31,   33,   34,   15,   23,    0,    0,   31,    0,   11,
   29,    0,    0,    0,    0,   12,   12,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   13,   13,    0,
    0,    0,    0,    0,   12,    0,    0,    0,    0,   15,
    0,    0,    0,    0,    0,    0,   13,    0,    0,    0,
    0,   15,   35,    0,    0,    0,    0,    0,   30,    0,
    0,    0,    0,   15,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,    0,    0,    0,    0,
    0,    0,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   11,   11,   11,
   11,   11,   11,    0,    0,    0,    0,   11,   11,    3,
    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
    0,   14,   12,   12,   12,   12,   12,   12,   28,    0,
    0,    0,    0,   12,   13,   13,   13,   13,   13,   13,
    0,    0,    0,    0,    0,   13,    4,    5,    6,    7,
    8,    9,    0,    0,    0,    0,    0,   26,    4,    5,
    6,    7,    8,    9,    0,    0,    0,    0,    0,   26,
    4,    5,    6,    7,    8,    9,    0,    0,    0,    0,
    0,   26,    4,    5,    6,    7,    8,    9,    0,    0,
    0,    0,    0,   26,
};
const short yycheck[] = {                                      39,
   40,   18,   15,   59,   59,  269,  269,   59,   61,   59,
   27,   59,   25,   40,    0,   -1,   -1,   34,   -1,   59,
   39,   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,
   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,
   -1,   40,   41,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,   -1,   -1,   -1,   -1,  267,  268,  256,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
   -1,  268,  257,  258,  259,  260,  261,  262,  267,   -1,
   -1,   -1,   -1,  268,  257,  258,  259,  260,  261,  262,
   -1,   -1,   -1,   -1,   -1,  268,  257,  258,  259,  260,
  261,  262,   -1,   -1,   -1,   -1,   -1,  268,  257,  258,
  259,  260,  261,  262,   -1,   -1,   -1,   -1,   -1,  268,
  257,  258,  259,  260,  261,  262,   -1,   -1,   -1,   -1,
   -1,  268,  257,  258,  259,  260,  261,  262,   -1,   -1,
   -1,   -1,   -1,  268,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#if YYDEBUG
const char * const yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'\\''","'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"U_TOK",
"D_TOK","L_TOK","R_TOK","F_TOK","B_TOK","LIST_TOK","SAVE_TOK","LOAD_TOK",
"QUIT_TOK","INT_TOK","SYMBOL_TOK","STRING_TOK",
};
const char * const yyrule[] = {
"$accept : file",
"face : U_TOK",
"face : D_TOK",
"face : L_TOK",
"face : R_TOK",
"face : F_TOK",
"face : B_TOK",
"expr : face",
"expr : expr '\\''",
"expr : expr INT_TOK",
"expr : '(' seq ')'",
"expr : SYMBOL_TOK",
"seq : expr",
"seq : seq expr",
"statement : seq ';'",
"statement : SYMBOL_TOK '=' seq ';'",
"statement : LIST_TOK ';'",
"statement : SAVE_TOK STRING_TOK ';'",
"statement : LOAD_TOK STRING_TOK ';'",
"statement : QUIT_TOK ';'",
"statement : error ';'",
"statements :",
"statements : statements statement",
"file : statements",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 105 "parser"

int yyerror()
  { printf("Syntax error.\n");
  }
#line 228 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss);
    if (newss == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs);
    if (newvs == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG void
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif	/* ANSI-C/C++ */
#else	/* YYPARSE_PARAM */
#ifndef YYPARSE_PARAM_TYPE
#define YYPARSE_PARAM_TYPE void *
#endif
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;
#endif	/* ANSI-C/C++ */
#endif	/* ! YYPARSE_PARAM */

int
yyparse (YYPARSE_PARAM_ARG)
    YYPARSE_PARAM_DECL
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 33 "parser"
{ copy_op(&U, &yyval.op); }
break;
case 2:
#line 34 "parser"
{ copy_op(&D, &yyval.op); }
break;
case 3:
#line 35 "parser"
{ copy_op(&L, &yyval.op); }
break;
case 4:
#line 36 "parser"
{ copy_op(&R, &yyval.op); }
break;
case 5:
#line 37 "parser"
{ copy_op(&F, &yyval.op); }
break;
case 6:
#line 38 "parser"
{ copy_op(&B, &yyval.op); }
break;
case 7:
#line 42 "parser"
{ copy_op(&yyvsp[0].op, &yyval.op);
    }
break;
case 8:
#line 46 "parser"
{ invert(&yyvsp[-1].op, &yyval.op);
    }
break;
case 9:
#line 50 "parser"
{ power(&yyvsp[-1].op, yyvsp[0].ival, &yyval.op);
    }
break;
case 10:
#line 54 "parser"
{ copy_op(&yyvsp[-1].op, &yyval.op);
    }
break;
case 11:
#line 58 "parser"
{ copy_op(&(yyvsp[0].sym->op), &yyval.op);
    }
break;
case 12:
#line 63 "parser"
{ copy_op(&yyvsp[0].op, &yyval.op);
    }
break;
case 13:
#line 66 "parser"
{ compose(&yyvsp[-1].op, &yyvsp[0].op, &yyval.op);
    }
break;
case 14:
#line 71 "parser"
{ print_cycles(&yyvsp[-1].op);
    }
break;
case 15:
#line 74 "parser"
{ copy_op(&yyvsp[-1].op, &(yyvsp[-3].sym->op));
      printf("%s = ", yyvsp[-3].sym->name);
      print_cycles(&(yyvsp[-3].sym->op));
    }
break;
case 16:
#line 79 "parser"
{ list_symbols();
    }
break;
case 17:
#line 82 "parser"
{ save_symbols(yyvsp[-1].str);
    }
break;
case 18:
#line 85 "parser"
{ load_symbols(yyvsp[-1].str);
      list_symbols();
    }
break;
case 19:
#line 89 "parser"
{ return(0);
    }
break;
case 20:
#line 92 "parser"
{ yyerror();
      yyerrok;
    }
break;
#line 521 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}

/* Driver for CUBE */
#include <stdio.h>
#include <string.h>
#include "operator.h"
#include "cube.h"
#include "def.h"
#include "symbol.h"

#define TRUE 1
#define FALSE 0

/* Head of the current symbol list */
struct symbol *symbol_head;

void main()
  { symbol_head = NULL;
    if (yyparse())
      printf("Not OK\n");
    else
      printf("OK\n");
  }

/* Inverts a permutation.  b(x) = a'(x) */
void invert(struct operator *a, struct operator *b)
  { int i, fa, ta;

    for (i=0;  i<20;  i++)
      { fa=a->perm[i];
	b->perm[fa]=i;
	ta=a->twist[i];
	b->twist[fa] = (fa<12 ? ta : (3-ta) % 3);
      }
  }

/* Performs the composition c(x) = b(a(x)) */
void compose(struct operator *a, struct operator *b, struct operator *c)
  { int i, fa, ta, tb;

    for (i=0;  i<20;  i++)
      { fa = a->perm[i];
	ta = a->twist[i];
	c->perm[i] = b->perm[fa];
	tb = b->twist[fa];
	c->twist[i] = (ta+tb) % (i<12 ? 2 : 3);
      }
  }

/* Raises a permutation to a power B(x)=A(x)**n */
void power(struct operator *a, int n, struct operator *b)
  { struct operator s, t;

    copy_op(&I, b);
    copy_op(a, &s);
    while (n>0)
      { if (n & 0x01)
          { compose(b, &s, &t);
            copy_op(&t, b);
          }
        compose(&s, &s, &t);
        copy_op(&t, &s);
        n = n>>1;
      }
  }
 
/* Copies one operator over another */
void copy_op(struct operator *a, struct operator *b)
  { memcpy(b, a, sizeof(struct operator));
  }
  
/* Prints a permutation in cycle notation.  Edge flips are shown with "T"
   and corner twists are shown with "+" and "-".  Also computes the order
   n such that P^n is the identity.
*/
void print_cycles(struct operator *op)
  { int i, j, t;
    int flag[24];
    int l, n;   /* Length, power */
    
    for (i=0;  i<20;  i++)
      flag[i]=FALSE;

    n=0;
    for (i=0;  i<20;  i++)
      { if (flag[i] == FALSE)
	  { flag[i] = TRUE;
	    if (op->perm[i] != i  ||  op->twist[i] != 0)
	      { printf("(%s", name[i]);
		j=i;
		t=0;
		l=1;
		while ((j=op->perm[j]) != i)
		  { printf(" %s", name[j]);
		    flag[j] = TRUE;
		    t+=op->twist[j];
		    l++;
		  }
		printf(")");
		t+=op->twist[j];
		if (j<12)
		  { t=t%2;
		    if (t != 0)
		      { printf("T ");
		        l*=2;
		      }
		  }
		else
		  { t=t%3;
		    if (t != 0)
		      { printf(t==1 ? "+" : "-");
		        l*=3;
		      }
		  }
		printf(" ");
		if (n == 0)
		  n = l;
		else
		  n = (n*l) / gcd(l, n);
	      }
	  }
      }
    if (n==0)
      printf("Identity\n");
    else
      printf(" [%d]\n", n);
  }

/* Uses Euclid's algorithm to find the GCD of two integers */
int gcd(int n, int m)
  { int r;
  
    if (m>n)
      { r=m%n;
        m=r;
      }
    while (m>0)
      { r=n%m;
        n=m;
        m=r;
      }
    return(n);
  }

/* Searches the current list for a symbol name.  If found, returns a
   pointer to it.  If not found, a new symbol is added to the beginning of
   the list, and a pointer to it is returned.
*/
struct symbol *find_symbol(char *name)
  { struct symbol *p;
  
    /* Is the list empty? */
    if (symbol_head == NULL)
      { symbol_head = new_symbol(name);
        return(symbol_head);
      }

    /* List not empty.  Search it */      
    p = symbol_head;
    while (p != NULL)
      { if (strcmp(p->name, name) == 0)
          return(p);
        p=p->next;
      }
  
    /* Not found */
    p = new_symbol(name);
    p->next = symbol_head;
    symbol_head = p;
    return(p);
  }
  
/* Allocates and names a new symbol */
struct symbol *new_symbol(char *name)
  { struct symbol *p;
    int i;

    p = (struct symbol *) malloc(sizeof(struct symbol));
    if (p == NULL)
      { fprintf(stderr, "ERROR: Can't allocate space for a symbol.\n");
        exit(-1);
      }

    if (strlen(name) > 20)
      name[21] = '\0';
    strcpy(p->name, name);
    
    for (i=0;  i<20;  i++)
      { p->op.perm[i] = i;
        p->op.twist[i] = 0;
      }
    p->next = NULL;
    return(p);
  }

/* Lists all symbol names on the current list */
void list_symbols()
  { struct symbol *p;
  
    for (p=symbol_head;  p != NULL;  p=p->next)
      { printf("%s = ", p->name);
        print_cycles(&(p->op));
      }
  }

/* Saves all symbols in the named file */
void save_symbols(char *name)
  { FILE *fp;
    int i;
    struct symbol *p;
    
  
    if ((fp = fopen(name, "w")) == NULL)
      { printf("ERROR: Can't open file %s\n", name);
        return;
      }
      
    for (p=symbol_head;  p != NULL;  p=p->next)
      { fprintf(fp, "%s ", p->name);
        for (i=0;  i<20;  i++)
          fprintf(fp, "%d %d  ", p->op.perm[i], p->op.twist[i]);
      }
   fclose(fp);
 }
 
/* Loads a file of symobls, prepending to the current list */
void load_symbols(char *name)
  { FILE *fp;
    int i, x, y;
    char str[21];
    struct symbol *p;
    
    if ((fp = fopen(name, "r")) == NULL)
      { printf("ERROR: Can't open file %s\n", name);
        return;
      }
      
    while (fscanf(fp, "%s", str) != EOF)
      { p = new_symbol(str);
        for (i=0;  i<20;  i++)
          { fscanf(fp, "%d %d", &x, &y);
            p->op.perm[i] = x;
            p->op.twist[i] = y;
          }
        p->next = symbol_head;
        symbol_head = p;
      }
    fclose(fp);
  }

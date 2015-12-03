/* Symbol structure */

struct symbol
  { char name[21];
    struct operator op;
    struct symbol *next;
  };
  

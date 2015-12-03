
void main(void);
void print_cycles(struct operator *op);
void invert(struct operator *a, struct operator *b);
void power(struct operator *a, int n, struct operator *b);
void copy_op(struct operator *a, struct operator *b);
void compose(struct operator *a, struct operator *b, struct operator *c);
int gcd(int n, int m);
struct symbol *find_symbol(char *name);
struct symbol *new_symbol(char *name);
void list_symbols(void);
void save_symbols(char *name);

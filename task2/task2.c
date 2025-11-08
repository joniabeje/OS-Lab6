// task2/task2.c
#include <stdio.h>
#include <stdlib.h>

typedef int (*op_fn)(int, int);

/* operations */
static int add_(int a, int b)     { puts("Adding 'a' and 'b'");           return a + b; }
static int sub_(int a, int b)     { puts("Subtracting 'b' from 'a'");     return a - b; }
static int mul_(int a, int b)     { puts("Multiplying 'a' and 'b'");      return a * b; }
static int div_(int a, int b)     { puts("Dividing 'a' by 'b'");          return a / b; }
static int quit_(int a, int b)    { (void)a; (void)b; exit(0); return 0; } /* not reached */

int main(void) {
    const int a = 6;
    const int b = 3;

    /* build a 256-entry dispatch table with a default action */
    op_fn dispatch[256];
    for (int i = 0; i < 256; ++i) dispatch[i] = quit_;

    dispatch[(unsigned char)'0'] = add_;
    dispatch[(unsigned char)'1'] = sub_;
    dispatch[(unsigned char)'2'] = mul_;
    dispatch[(unsigned char)'3'] = div_;
    dispatch[(unsigned char)'4'] = quit_;

    printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");

    int ch = getchar();
    int x = dispatch[(unsigned char)ch](a, b);
    printf("x = %d\n", x);
    return 0;
}

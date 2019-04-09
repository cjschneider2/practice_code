#include <stdio.h>

int main (int argc, const char * argv[])
{
/* Program Setup */
    /* Check Inputs */
    if (argc > 2) {
        printf ("argc: %d\n", argc);
        printf ("argv[1]: %s", argv[1]);
    }
    /* Variables */
    FILE
        *file = fopen(argv[1], "r");
    int
        c = 0,
        bit_cnt = 0;
/* Program Logic */
    /* Check for open file */
    if (!file)
        return 1;
    do
    {
        c = fgetc (file);
        if (c != EOF)
            bit_cnt++;
    }
    while ( c != EOF );
    /* Print the output */
    printf ("%d\n", bit_cnt);
/* Cleanup */
    return 0;
}

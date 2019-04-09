#include <stdio.h>

int main (int argc, const char * argv[])
{
/* Program Setup */
    /* Check Inputs */
    if (argc > 2) {
        printf ("argc: %d", argc);
        printf ("argv[0]: %s", argv[1]);
    }
    /* Variables */
    FILE *file = fopen(argv[1], "r");
    char line[1024];
/* Program Logic */
    /* Read each line of the file */
    while (fgets(line, 1024, file))
    {
        printf("%s\n", line);
    }

/* Cleanup */
    return 0;
}

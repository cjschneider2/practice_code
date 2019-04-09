#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_CATE 20
#define MAX_PART 10

int main (int argc, const char * argv[])
{
/* Program Setup */
    /* Check Inputs */
    if (argc > 2) {
        printf ("argc: %d", argc);
        printf ("argv[0]: %s", argv[1]);
    }
    /* Variables */
    FILE
       *file = fopen(argv[1], "r");
    int
        idx = 0, /* index value into array */
       *values = calloc (20, sizeof(int)); /* our return list */
    char
        line[1024];

/* Program Logic */
    /* Read each line of the file */
    while (fgets(line, 1024, file))
    {
        char *token = strtok (line, " "); /* the space ' ' is our "splitting char" */
        while (token != NULL)
        {
            errno = 0;
            sscanf (token, "%d", (values + idx) );
            if (token == '|')
            {
               printf ("%s", token);
            }
            token = strtok (NULL, " ");
            idx++;
        }
        printf ("\n");
        for (int i = 0; i < 20; i++) {
           printf ("%d", *(values+i));
        }
        printf ("\n");
    }

/* Cleanup */
    fclose (file);

    return 0;
}

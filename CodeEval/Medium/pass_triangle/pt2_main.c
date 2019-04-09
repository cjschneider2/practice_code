#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_val(int* intMatrix, int x, int y)
{
    int idx = (x*(x+1))/2;
    return *(intMatrix + idx + y);
}

void set_val(int* intMatrix, int x, int y, int val)
{
    int idx = (x*(x+1))/2;
    *(intMatrix + idx + y) = val;
}

int main(int argc, const char * argv[]) {

    FILE* file = fopen(argv[1], "r");
    char line[1024];
    // NOTE: this would definitely have to change if I didn't know my
    //       set size already...
    int row_max = 100;
    // NOTE: the number of entries between 1 and n is (n(n+1))/2
    //       so (100*(1+100))/2 = 5050 entries
    int* intMatrix = calloc(5050, sizeof(int));

    // iterating variables
    int idx, idy, ln_no;

    /* parsing */
    idx = 0, ln_no = 1;
    while (fgets(line, 1024, file)) {
        /* NOTE: *MAJOR* assumption that each line has the same
         *       number of elements as the line number...
         */
        char* token = strdup(line);
        idy = 0;
        while ( ((token = strtok(token, " \n")) != NULL) &&
                (idy < ln_no) )
        {
            sscanf(token, "%d", (intMatrix + idx) );
            token = NULL;
            idx++;
            idy++;
        }
        ln_no++;
    }
    row_max = ln_no - 2; // get the true number of lines

    /* find the largest sum */
    int x = 0, y = 0, val;
    for( x = row_max-1; x>=0; x-- )
    {
        for ( y = 0; y <= x ; y++)
        {
            int v = get_val(intMatrix, x ,y);
            int v1 = get_val(intMatrix, x+1, y);
            int v2 = get_val(intMatrix, x+1, y+1);
            if (v1>v2) { val=v1; }
            else { val=v2; }
            set_val(intMatrix, x, y, v+val);
        }
    }

    /* Output to stdout */
    printf("%d\n",get_val(intMatrix, 0, 0));

    /* memory management */
    free(intMatrix);
}

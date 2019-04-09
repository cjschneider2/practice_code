#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[50];
    int n=0, x=0;

    /*
     * The goal here is for every set of numbers "n,x" to output the largest
     * multiple of 'x' greater than 'n'.
     */
    while (fgets(line, 50, file)) {
        sscanf(line, "%d,%d", &n, &x);
        if ( n || x ) {  // the calculation is done here
            int mult = (int)ceil((double)n/(double)x); // typecasting fun :/
            printf("%d\n", mult*x);
        } else {         // if they are both zero we'll just throw an error.
            printf("Read input failed.\n");
            return 1;
        }
    }
    return 0;
}

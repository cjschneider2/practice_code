#include <stdio.h>

int main (int _argc, const char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int a, b;
    while ( fscanf (file, "%d,%d", &a, &b) == 2 ) {
        printf ("%d\n", a % b);
    }
    fclose (file);
}
 

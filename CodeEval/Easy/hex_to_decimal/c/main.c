#include <stdio.h>

int main (int _argc, const char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int a;
    while ( fscanf (file, "%x", &a) == 1 ) {
        printf ("%d\n", a);
    }
    fclose (file);
}

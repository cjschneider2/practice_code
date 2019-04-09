#include <stdio.h>

void fizzBuzz(int x, int y, int n) {
    n++;
    for (int i=1; (i<n); i++) {
        if ( (i%x == 0) && (i%y == 0) ) {
            printf("%s", "FB");
        }
        else if ( i%x == 0 ) {
            printf("%s", "F");
        }
        else if ( i%y == 0 ) {
            printf("%s", "B");
        }
        else {
            printf("%d", i);
        }
        if ( i!=(n-1) ){
            printf("%s", " ");
        }
    }
    return;
}

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int x, y, n;

    while (fgets(line, 1024, file)) {
        /* parse input */
        sscanf( line, "%d %d %d", &x, &y, &n);
        /* fizzBuzz() -> stdout */
        fizzBuzz(x,y,n);
        printf("%s","\n");
    }
    return 0;
}

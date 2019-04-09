#include <stdio.h>

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while ( fgets(line, 1024, file) )
    {
        int orig = 0;
        sscanf(line, "%d", &orig);
        int inv = orig;
        int sum = 0;
        while (inv !=0) {
            sum += (inv%10);
            inv = inv/10;
        }
        printf("%d\n", sum);
    }
    return 0;
}

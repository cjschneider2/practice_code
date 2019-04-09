#include <stdio.h>
int main(int argc, const char * argv[]) {
    int MAX = 12;
    for ( int i = 1; i <= MAX; i++) {
        int j = 1;
        printf("%d ", i*j);
        for (++j; j < MAX; j++ ){
            printf("%3d ", i*j);
        }
        printf("%3d\n", i*j);
    }
    return 0;
}

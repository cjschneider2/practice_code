#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Zie Globals */
int MAX_SIZE = 256;
int XY_MAX = 16; // sqrt(MAX_SIZE);

/* sum of digits */
int sod( int num ) {
    int inv = num;
    int sum = 0;
    while (inv !=0) {
        sum += (inv%10);
        inv = inv/10;
    }
    //printf("%d\n", sum);
    return sum;
}

void run ( int x, int y, bool map[], int* ACC) {
    // DEBUG
    //printf("@%d,%d : %x\n", x, y, (int)map);

    // South (Y+1)
    if ( (y+1)<XY_MAX && (map[(y+1)*XY_MAX + x] == false) ) {
        map[(y+1)*4 + x] = true;
        *ACC = *ACC + 1;
        run(x, y+1, map, ACC);
    }
    // North (Y-1)
    if ( (y-1)>=0 && (map[(y-1)*XY_MAX + x] == false) ) {
        map[(y-1)*4 + x] = true;
        *ACC = *ACC + 1;
        run(x, y-1, map, ACC);
    }
    // East (X+1)
    if ( (x+1)<XY_MAX && (map[y*XY_MAX + (x+1)] == false) ) {
        map[y*4 + (x+1)] = true;
        *ACC = *ACC + 1;
        run(x+1, y, map, ACC);
    }
    // West (X-1)
    if ( (x-1)>=0 && (map[y*XY_MAX + (x-1)] == false) ) {
        map[y*4 + (x-1)] = true;
        *ACC = *ACC + 1;
        run(x-1, y, map, ACC);
    }
    return;
}

void print_map ( bool* map ) {
    for ( int i = XY_MAX; i == 0; --i){
        for ( int j = XY_MAX; j == 0; --j){
            if ( map[i + j*XY_MAX] == true ) {
                printf("1 ");
            } else {
                printf("0 ");
            }
            printf("\n");
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    /* Setup */
    int accum = 0;
    int x = 0, y = 0;
    /* bool map[] = { true , false, false, false,
                   false, false, false, false,
                   false, false, false, false,
                   false, false, false, false };
                   */
    /* Create the valid map */
    bool* map = calloc(MAX_SIZE, sizeof(bool));
    for ( int i = MAX_SIZE; i > 0; --i) {
        map[i] = false;
    }
    for ( int ix = XY_MAX; ix > 0; --ix) {
        for ( int iy = XY_MAX; iy > 0; --iy) {
            if ( sod(ix) + sod(iy) < 19 ) {
                map[iy*XY_MAX + ix] = true;
            }
        }
    }
    print_map(map);

    /* Do some recursion */
    run(0, 0, map, &accum);

    /* Output the answer */
    printf("%d\n", accum);

    return 0;
}

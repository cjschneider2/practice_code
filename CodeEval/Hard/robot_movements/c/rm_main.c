#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void run ( int x, int y, bool map[], int* ACC) {
    // DEBUG
    //printf("@%d,%d : %x\n", x, y, (int)map);
    // Check end position
    if ( x == 3 && y == 3 ) {
        *ACC = *ACC + 1;
        return;
    }
    // South (Y+1)
    if ( (y+1)<4 && (map[(y+1)*4 + x] == false) ) {
        bool* t_map = calloc(16, sizeof(bool));
        memcpy(t_map, map, sizeof(bool)*16);
        t_map[(y+1)*4 + x] = true;
        run(x, y+1, t_map, ACC);
    }
    // North (Y-1)
    if ( (y-1)>=0 && (map[(y-1)*4 + x] == false) ) {
        bool* t_map = calloc(16, sizeof(bool));
        memcpy(t_map, map, sizeof(bool)*16);
        t_map[(y-1)*4 + x] = true;
        run(x, y-1, t_map, ACC);
    }
    // East (X+1)
    if ( (x+1)<4 && (map[y*4 + (x+1)] == false) ) {
        bool* t_map = calloc(16, sizeof(bool));
        memcpy(t_map, map, sizeof(bool)*16);
        t_map[y*4 + (x+1)] = true;
        run(x+1, y, t_map, ACC);
    }
    // West (X-1)
    if ( (x-1)>=0 && (map[y*4 + (x-1)] == false) ) {
        bool* t_map = calloc(16, sizeof(bool));
        memcpy(t_map, map, sizeof(bool)*16);
        t_map[y*4 + (x-1)] = true;
        run(x-1, y, t_map, ACC);
    }
    return;
}

int main(int argc, const char * argv[]) {
    /* Setup */
    int accum = 0;
    int x = 0, y = 0;
    bool map[] = { true , false, false, false,
                   false, false, false, false,
                   false, false, false, false,
                   false, false, false, false };

    /* Do some recursion */
    run(0, 0, map, &accum);

    /* Output the answer */
    printf("%d\n", accum);

    return 0;
}

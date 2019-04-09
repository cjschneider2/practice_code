#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void parse( char *line, int* x, int* y)
{
    /* 'x' is read in as the first character and then transformed
     * into a number in the range [0,7] corresponding to the
     * board characters ['a','h'].
     */
    *x = *line - 'a' ;
    /* 'y' should be able to be read and converted directly */
    *y = atoi( (line + 1) );
    return;
}

bool valid_position( int x, int y)
{
    /* return : true = valid, false = invalid */
    /* we just need to make sure that x and y are bounded by [0,7] */
    if ( (x >= 0) && (x <= 7) &&
         (y >= 1) && (y <= 8) )
    {
        return true;
    }
    return false;
}

void possible_positions( int x, int y)
{
    /* there are 8 checks in total. If done in the correct order,
     * they will turn out in alphabetical order.
     * order : [LT, LB, TL, BL, TR, BR, RT, RB]
     * L : left
     * R : right
     * T : top
     * B : bottom
     */
    if ( valid_position( x-2, y-1 ) ) { printf("%c%d ", (x-2)+'a' , y-1); };
    if ( valid_position( x-2, y+1 ) ) { printf("%c%d ", (x-2)+'a' , y+1); };
    if ( valid_position( x-1, y-2 ) ) { printf("%c%d ", (x-1)+'a' , y-2); };
    if ( valid_position( x-1, y+2 ) ) { printf("%c%d ", (x-1)+'a' , y+2); };
    if ( valid_position( x+1, y-2 ) ) { printf("%c%d ", (x+1)+'a' , y-2); };
    if ( valid_position( x+1, y+2 ) ) { printf("%c%d ", (x+1)+'a' , y+2); };
    if ( valid_position( x+2, y-1 ) ) { printf("%c%d ", (x+2)+'a' , y-1); };
    if ( valid_position( x+2, y+1 ) ) { printf("%c%d ", (x+2)+'a' , y+1); };
    printf("\n");
    return;
}
int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int x=0, y=0;
        parse(line, &x, &y);
        possible_positions(x, y);
    }
    return 0;
}

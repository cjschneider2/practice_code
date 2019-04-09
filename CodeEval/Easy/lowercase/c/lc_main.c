#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char cur_char;

    while ( fgets(line, 1024, file) )
    {
        for ( int idx=0 ; (idx < strlen(line)); idx++)
        {
            cur_char = line[idx];
            if ( (cur_char >= 'A') && (cur_char <= 'Z') )
            {
                cur_char += 32;
            }
            /* Output line -> stdout */
            printf("%c", cur_char);
        }
    }
    return 0;
}

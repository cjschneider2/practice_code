#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];

    const char* slang[] = {
        ", yeah!",
        ", this is crazy, I tell ya.",
        ", can U believe this?",
        ", eh?",
        ", aw yea.",
        ", yo.",
        "? No way!",
        ". Awesome!"
    };

    int punt_cnt = 0, punt_len = 2;
    int slang_cnt = 0, slang_len = 8;
    while (fgets(line, 1024, file)) {
        for ( int idx = 0; idx < strlen(line); idx++)
        {
            if ( (line[idx] == '.') ||
                 (line[idx] == '!') ||
                 (line[idx] == '?') )
            {
                punt_cnt = (punt_cnt + 1) % punt_len;
                if (punt_cnt == 0)
                {
                    printf("%s", slang[slang_cnt]);
                    slang_cnt = (slang_cnt + 1) % slang_len;
                }
                else printf("%c", line[idx]);
            }
            else printf("%c", line[idx]);
        }
    }
    return 0;
}

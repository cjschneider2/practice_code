#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int HH1, MM1, SS1; // time 1
    int HH2, MM2, SS2; // time 2
    int HHO, MMO, SSO; // output times
    int sec1, sec2; // amount of seconds past 00:00:00
    int diff;
    while (fgets(line, 1024, file)) {
        // Parse the input
        if ( sscanf(line, "%d:%d:%d %d:%d:%d",
                    &HH1, &MM1, &SS1, &HH2, &MM2, &SS2) != 6 ){
            printf("%s\n", "scan failed");
        } else {
            // convert into seconds for difference calculations
            sec1 = 3600*HH1+60*MM1+SS1;
            sec2 = 3600*HH2+60*MM2+SS2;
            // calculate difference
            diff = abs(sec1-sec2);
            // back calculate the HH:MM:SS of the difference
            HHO = diff/3600; diff = diff%3600;
            MMO = diff/60; diff = diff%60;
            SSO = diff;
            // Output
            printf("%02d:%02d:%02d\n", HHO, MMO, SSO);
        }
    }
    return 0;
}

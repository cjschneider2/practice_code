#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI 3.141592653589793
#define WS 4096

void _fft( double complex* buf, double complex* out, int n, int step)
{
    if (step < n) {
        _fft( out, buf, n, step * 2);
        _fft( out + step, buf + step, n, step * 2);

        for ( int i = 0; i < n; i += 2 * step )
        {
            double complex t = cexp(-I * PI * i / n) * out[i + step];
            buf[i / 2] = *(out + i) + t;
            buf[(i+n)/2] = out[i] - t;
        }
    }
}

void fft( double complex* data_in)
{
     double complex* out = calloc(WS, sizeof(double complex));
     for (int i = 0; i < WS; i++)
     {
         *(out + i) = *(data_in + i);
     }
     _fft(data_in, out, WS, 1);
}

int main(int argc, const char * argv[]) {

    if ( argc < 2 ) {
        printf("%s", "Please give the input file as the first cmd argument ");
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    char* line = calloc(8192, sizeof(char));

    while (fgets(line, 8192, file)) {

        int* vals = calloc(WS, sizeof(int));

        /* Read in the values to the vals array */
        int idx = 0;
        char* token = strtok(line, " ");
        while ( token != NULL )
        {
            sscanf(token, "%d", (vals + idx) );
            token = strtok( NULL, " ");
            idx++;
        }

        double complex* data = calloc(WS, sizeof(double complex));
        for ( int i = 0; i < WS; i++){
            *(data + i) = (double)*(vals + i);
        }

        /* begin the FFT procedure based on Cooley-Tukey */
        fft(data);

        /* DEBUG */
        printf("\n\n start \n\n");
        int max_idx = 0;
        double max = 0;
        for ( int i = 100; i < WS/2; i++){
            double mag = (fabs(creal(data[i])) + fabs(cimag(data[i])));
            if (mag > max) { max = mag; max_idx = i; }
        }

        printf("max val :%f @ %d\n", max, max_idx);

        //free(data);
        //free(data_out);
    }
    free(line);
    close(file);
    return EXIT_SUCCESS;
}

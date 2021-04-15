#include <stdio.h>
#include <unistd.h>
#include "mathlib.h"
#include <math.h>

#define OPTIONS "asctl"

int main(int argc, char **argv){
    int opt = 0;
    int arcSin = 0;
    int arcCos = 0;
    int arcTan = 0;
    int Log = 0;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1){
        switch (opt){
	    case 'a':
                arcSin = 1;
		arcCos = 1;
		arcTan = 1;
		Log = 1;

		break;
	    case 's':
		arcSin = 1;
		break;
	    case 'c':
		arcCos = 1;
		break;
	    case 't':
		arcTan = 1;
		break;
	    case 'l':
		Log = 1;
	    default:
		printf("correct usage %s -[asctl]", argv[0]);
		return 1;
	}
    
    }
    
    if(arcSin == 1){
        printf("Header");
        printf(" results");
	printf("% 7.4lf % 16.8lf % 16.8lf % 16.10lf\n" i, arcSin(i), asin(i), arcSin(i) - asin(i));
    }
    if(arcCos == 1){
        printf("Header");
        printf(" results");
	printf("% 7.4lf % 16.8lf % 16.8lf % 16.10lf\n" i, arcCos(i), acos(i), arcCos(i) - acos(i)
    }
    if(arcTan == 1){
        printf("Header");
        printf(" results");
	printf("% 7.4lf % 16.8lf % 16.8lf % 16.10lf\n" i, arcTan(i), atan(i), arcTan(i) - atan(i)
    }
    if(Log == 1){
        printf("Header");
        printf(" results");
	printf("% 7.4lf % 16.8lf % 16.8lf % 16.10lf\n" i, Log(i), log(i), Log(i) - log(i)
    }
    return 0;
}


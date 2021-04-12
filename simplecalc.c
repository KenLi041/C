//r
//  main.c

//  Created by Yiming Li on 2/12/20.
//  Copyright © 2020 Ken Li. All rights reserved.
//



#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    int x, y; char operator; //define variables
    if (argc != 4){ //check if argument is too many or too few & output error
        fprintf(stderr, "Error: usage is simplecalc <x> <op> <y>\n"); exit(1);
    }
    if(sscanf(argv[1], "%d", &x) == 1 && //check if all 3 arguments are properly scanned
       sscanf(argv[2], "%c", &operator) == 1 &&
       sscanf(argv[3], "%d", &y) == 1)
    {
        switch(operator){//use switch command for different cases
                //case 13 : printf("Error: usage is simplecalc <x> <op> <y>"); return 1;
            case 43 : fprintf(stderr, "%d\n", x+y); return 0;
            case 45 : fprintf(stderr, "%d\n", x-y); return 0;
            case 42 : fprintf(stderr, "%d\n", x*y); return 0;
            case 47 : fprintf(stderr, "%d\n", x/y); return 0;
            default: fprintf(stderr, "%c not a valid operator\n", operator);
                exit(2);
        }}
    return 0;
    
}





//
//  main.c

//  Created by Yiming Li on 4/3/20.
//  Copyright © 2020 Ken Li. All rights reserved.
//

//comment section
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


//5+ files total: Makefile, git.txt, main, sum1, sum2, compile.txt, .h
//program name: polyapp
//directory & git, at least 4 commits out by 15 min

//SUBMIT Makefile



//comment section


//#include <sum1.c>
//#include <sum2.c>
//#include <declaration.h>

#include <stdio.h>

int main(int argc , char* argv[]){
    int i = 1; double d = 3.6; char s[] = "later line";
    
    int secint = 0; double d1 = 0.00; char string;
    
    // Declare second integer, double, and String variables.
    scanf("%d\n%lf\n%s", &secint, &d1, &string);
    // Read and save an integer, double, and String to your variables.
    printf("\n%d", i+secint);
    // Print the sum of both integer variables on a new line.
    printf("\n%lf", d+d);
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    return 0;
}







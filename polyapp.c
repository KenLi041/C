
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


//5+ files total: Makefile, gitlog.txt, polyapp.c (contains main), poly.c, utils.c (contains parse & powi function), ANY HEADER FILES (.h)
//program name: polyapp
//directory & git, at least 4 commits out by 15 min

//SUBMIT Makefile

//a case without input argc < 1|| >1
//In polyapp.c: main: use fgets, command line input argv[1] = file name, read file name from command line! WARNING: error if each line pass 2 numbers

//In utils.c: parse(char* string, int* integer1, int* integer2), powi(int x, int e): 2 3 -> 8 no math.h
//In poly.c: global variable head, make linked list: struct PolyTerm{ int coeff; int expo; struct PolyTerm *next;}; function addPolyTerm

//This version is declaration.h!


//
//  main.c
//  COMP206
//
//  Created by Yiming Li on 4/3/20.
//  Copyright © 2020 Ken Li. All rights reserved.
//

//comment section

/*
 Program to implement a polynomial evaluation application
 Author     Dept        Date        Notes
 Ken Li Comp. Science . April 3, 2020 first version,
 */

//5+ files total: Makefile, gitlog.txt, polyapp.c (contains main), poly.c, utils.c (contains parse & powi function), ANY HEADER FILES (.h)
//program name: polyapp
//directory & git, at least 4 commits out by 15 min

//SUBMIT Makefile

//a case without input argc < 1|| >1
//In polyapp.c: main: use fgets, command line input argv[1] = file name, read file name from command line! WARNING: error if each line pass 2 numbers

//In utils.c: parse(char* string, int* integer1, int* integer2), powi(int x, int e): 2 3 -> 8 no math.h
//In poly.c: global variable head, make linked list: struct PolyTerm{ int coeff; int expo; struct PolyTerm *next;}; function addPolyTerm

//This version is poly.c!

//#include "utils.c"
//#include "poly.c"
#include "declaration.h"


/*
void create_node(int a, int b){
    struct PolyTerm *r, *z;
    struct PolyTerm **temp;
    z = *temp;
    
    if(z == NULL){
        r = (struct PolyTerm*)malloc(sizeof(struct PolyTerm));
        r->coeff = a;
        r->expo = b;
        *temp = r;
        r->next = (struct PolyTerm*)malloc(sizeof(struct PolyTerm));
        r = r->next;
        r->next = NULL;
    }
    else{
        r->coeff = a;
        r->expo = b;
        r->next = (struct PolyTerm*)malloc(sizeof(struct PolyTerm));
        r = r->next;
        r->next = NULL;
    }
}
*/




int main(int argc , char* argv[]){
    FILE *fp;
    char filename[30];
    char line[255];
    int integer1 = 0, integer2 = 0; //之后去掉重复定义
    char ch;
    int count = 0;
    
    if (argc <= 1){ //argc = 1 if no argument passed! so must be argc <= 1 otherwise segfault!
        fprintf(stderr, "Incorrect commandline argument entered\n");
        return 0;
    }
    if (argc > 2){ //can't say argc < 1 since it can't be negative!
        fprintf(stderr, "Incorrect commandline argument entered\n");
        return 0;
    }
    
    //   printf("breakpoint1");
    //fgets(argv[1], 30, stdin);
    // printf("breakpoint2");
    strcpy(filename, argv[1]);
    fp = fopen(filename, "r");
    // printf("passbadexc");
    if (fp == NULL){
        printf("can't open file");
        return 0;
    }
    for (ch = getc(fp); ch != EOF; ch = getc(fp)){
        if (ch == '\n')
            count += 1;
        //printf("count is %d", count);
    }
    rewind(fp);
    while(fgets(line, 255, fp)){ //先parse，再addpoly, displaypoly, evaluatepoly
        parse(line, count, integer1, integer2, fp);
        /*create_node(integer1, integer2);
         addPolyTerm(integer1, integer2);
         displayPolynomial();
         evaluatePolynomial(integer1);*/
    }
    
    fclose(fp);
    
    return 0;
}








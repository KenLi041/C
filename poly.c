
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

//This version is poly.c!
#ifndef POLY_C
#define POLY_C

#include "declaration.h"


typedef struct PolyTerm* head;
typedef struct PolyTerm node_t;

struct PolyTerm{
    int coeff;
    int expo;
    struct PolyTerm *next;
};


void addPolyTerm(int a, int b){ //in increasing order of exponent
    struct PolyTerm *poly1; struct PolyTerm *poly2; struct PolyTerm *poly3;
    while(poly1->next && poly2->next){
        if(poly1->expo > poly2->expo){ //if 1st poly > 2nd, store 2nd
            poly3->expo = poly2->expo;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else if(poly1->expo < poly2->expo){ //vice versa
            poly3->expo = poly1->expo;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else{ //add coefficient if power of both polynomial is same
            poly3->expo = poly1->expo;
            poly3->coeff = poly1->coeff+poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly3->next = (struct PolyTerm*)malloc(sizeof(struct PolyTerm));
        poly3 = poly3->next;
        poly3->next = NULL;;
    }
    while(poly1->next || poly2->next){
        if(poly1->next)
        {
            poly3->expo = poly1->expo;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2->next)
        {
            poly3->expo = poly2->expo;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly3->next = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
        poly3 = poly3->next;
        poly3->next = NULL;
    }
}

void displayPolynomial(){
    struct PolyTerm *node;
    char* p[2];
    while(node->next != NULL){
        //printf("%dx%d", node->coeff, node->expo);
        node = node->next;
        if(node->next != NULL){ //if coefficient is positive/negative
            if (node->coeff > 0){
                *p = "+";
            }
            else if (node->coeff < 0){
                *p = "-";
            }
        }
    }
}

void evaluatePolynomial(int x){
    int value;
    int answer;
    for (value = -2; value < 3; value++){
        answer *= value; }
}

#endif



//
//  main.c
//  COMP206
//
//  Created by Yiming Li on 4/3/20.
//  Copyright © 2020 Ken Li. All rights reserved.
//

//comment section
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
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

//This version is declaration.h!

#ifndef DECLARATION_H
#define DECLARATION_H

void create_node(int, int);

void addPolyTerm(int, int);

void displayPolynomial();

void evaluatePolynomial(int);

int powi(int, int);

void parse(char*, int, int, int, FILE*);

#endif


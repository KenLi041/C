
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

//This version is utils.c!
#ifndef UTILS_C
#define UTILS_C

#include "declaration.h"



/*printf("parameter is %d %d", value1[2], value2[2]);
 printf("pow test is %d", powi(value1[2], -2, value2[2]));
 
 for(i = -2; i < 3; i++){
 int sum[size];
 for(j = 0; j < size; j++){
 sum[j] += powi(value1[j], i, value2[j]);
 }
 printf("for x=%d, y = %d\n", i, sum[j]);
 }*/

int powi(int x, int e){
    int result = 1;
    if(e == 0){
        result = 1;
    }
    while (e){
        if (e & 1)
            result *= x;
        e >>=1;
        x *= x;
    }
    return result;
}

void parse(char* string, int count, int integer1, int integer2, FILE *fp){
    //char buffer[255];
    int i, size = 0;
    int j, k;
    if(string[strlen(string) - 1] == '\n'){//check if reaches enter key/end of line
        string[strlen(string) - 1] = '\0';
    }
    
    //int* intpoint1 = NULL;
    //intpoint1 = &integer1; //store address in pointers
    //int* intpoint2 = NULL;
    //intpoint2 = &integer2;
    int value1[count];
    int value2[count];
    rewind(fp);
    while((size <= count) && fscanf(fp, "%d %d", &value1[size], &value2[size])==2){
        size++;
    }
    //for (i = 0; i < size; i++){ //count or size?
    // printf("coeff is %d\n, expo is %d\n", value1[i], value2[i]);}
    // printf("negative addition is %d", value1[2]+value1[4]);
    
    for (i = 0; i < size; i++){
        for (j = i + 1; j < size; ++j){
            if (value2[i] > value2[j]){
                int swap1 = value1[i];
                int swap2 = value2[i];
                value1[i] = value1[j];
                value2[i] = value2[j];
                value1[j] = swap1;
                value2[j] = swap2;
            }
        }
    }
    
    for (i = 0; i < size; i++){
        for (j = i + 1; j < size; ++j){
            if (value2[i] == value2[j]){
                int new1 = value1[i] + value1[j];
                value1[j] = new1;
                for (k = j-1; k<count-1; k++){
                    value1[k] = value1[k + 1];
                    value2[k] = value2[k + 1];
                    
                }
                size--;
                j--;
            }
        }
    }
    printf("%dx%d", value1[0], value2[0]);
    for (i = 1; i < size; i++){ //count or size?
        if (value1[i] > 0){
            printf("+%dx%d", value1[i], value2[i]);}
        else printf("%dx%d", value1[i], value2[i]);
    }
    printf("\n");
    int *sum1 = malloc(sizeof(int)*size);
    //printf("size is %d", size);
    int *sum2 = malloc(sizeof(int)*size);
    int *sum3 = malloc(sizeof(int)*size);
    int *sum4= malloc(sizeof(int)*size);
    int *sum5 = malloc(sizeof(int)*size);
    
    
    int total1 = 0;
    int total2 = 0;
    int total3 = 0;
    int total4 = 0;
    int total5 = 0;
    for (i = 0; i < size; i++){
        sum1[i] += value1[i]*powi(-2, value2[i]);
        total1 += sum1[i];
    }
    for (i = 0; i < size; i++){
        sum2[i] += value1[i]*powi(-1, value2[i]);
        total2 += sum2[i];
    }
    for (i = 0; i < size; i++){
        sum3[i] += value1[i]*powi(0, value2[i]);
        total3 += sum3[i];
    }
    for (i = 0; i < size; i++){
        sum4[i] += value1[i]*powi(1, value2[i]);
        total4 += sum4[i];
    }
    for (i = 0; i < size; i++){
        sum5[i] += value1[i]*powi(2, value2[i]);
        total5 += sum5[i];
    }
    
    printf("for x=%d, y=%d\n", -2, total1);
    printf("for x=%d, y=%d\n", -1, total2);
    printf("for x=%d, y=%d\n", 0, total3);
    printf("for x=%d, y=%d\n", 1, total4);
    printf("for x=%d, y=%d\n", 2, total5);
    
    
    
}
#endif


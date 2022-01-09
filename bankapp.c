
//
//  main.c
//  COMP206
//
//  Created by Yiming Li
//  Copyright © 2022 Ken Li. All rights reserved.
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



typedef struct person{
    //set up information slots that corresponds to user's inputs
    char account1[25];
    //becareful of different name related to account!
    char name[40];
    //Becareful the type difference!
    double money;
    struct person* new; //points to new account
}var;



var* search(var* start, char *account1){//search if account exists, like pg15 traverse of week7 slide
    var *temp = start;  //first, create a temporary variable to hold original node value
    //printf(“searchcheck”);
    while(temp!= NULL){
        if(strcmp(temp->account1, account1) == 0)
            return temp;
        //compare if account matches using strcmp, if yes then update values
        temp=temp->new; //existing account case, else go to next line to find new account
    }
    //no existing account case
    return NULL;
}

//
var* addNode(var* start, var* node){ //necessary for a linkedlist style execution
    if(start == NULL){ //base case
        return node;
    }
    //printf("testaddnode");
    else{
        start->new = addNode(start->new, node); //recursion
        return start;
    }
}

var* newaccount(var* start, char* account_placeholder, char* name_placeholder){
    var* newa = malloc(sizeof(var)); //dynamic allocation of memory taught
    strcpy(newa->account1 , account_placeholder);
    strcpy(newa->name , name_placeholder);
    newa->money = 0;
    newa->new = NULL;
    return addNode(start , newa);
}

void newmoney(var* start, char* account_placeholder , char* amount){
    var* newa = search(start, account_placeholder);
    if(newa == NULL){//program must not crash for any other situation
        fprintf(stderr, "Can't read file\n");
        exit(1);
    }
    //update moneyance
    double amount1 = strtod(amount, NULL); //convert amount as char token to double for calculation
    newa->money += amount1;
    if(newa->money < 0){//program must not crash for any other situation
        fprintf(stderr, "Can't read file\n");
        exit(1);
    }
}

var* csv(FILE* fp){
    //processing & updating csv file
    var* start = NULL;
    char line[255]; //space for contents
    //printf("enteringcsvfunction");
    while(fgets(line, 255, fp)){
        //scan contents from input to file
        if(line[strlen(line) - 1] == '\n'){//check if reaches enter key/end of line
            line[strlen(line) - 1] = '\0';
        }
        char* operation_placeholder = strtok(line, ","); //tokenize each line of input
        char* account_placeholder; //other necessary variables
        char* another_name_placeholder;
        char* amount; //becareful of confusion between amount & amount1!
        char* date;
        if(operation_placeholder!=NULL){
            if(strcmp(operation_placeholder, "AC") == 0){//find line that starts with account
                //printf("checkenteringACloop");
                //the next 2 tokens are account & name
                account_placeholder = strtok(NULL, ",");
                another_name_placeholder = strtok(NULL, ",");
                if(!account_placeholder||!another_name_placeholder){
                    fprintf(stderr, "Can't read file\n");//program must not crash for any other situation
                    exit(1);
                }
                start = newaccount(start, account_placeholder, another_name_placeholder); //now call update money function to verify balance
            }
            else if(strcmp(operation_placeholder, "TX") == 0){ //check if equal to transaction, get account, date & amount information
                //printf("checkenteringTXloop");
                account_placeholder = strtok(NULL , ",");
                date = strtok(NULL , ",");
                amount = strtok(NULL , ",");
                if(!account_placeholder||!date||!amount){
                    fprintf(stderr, "Can't read file\n");
                    exit(1);}
                newmoney(start , account_placeholder , amount);
            }
            else{fprintf(stderr, "Can't read file\n");
                exit(1);}//bracket needed?
        }
    }
    return start;
}

void addaccount(FILE* fp, var* start, char* num, char* name){
    //if (start == NULL){
     //   printf("addaccountstartNULL!");
    //}
    //if (search(start, numbercheck) == NULL){
    //    printf("searchfunctionNULL!");
    //}
    if(search(start, num) != NULL){ //if search function not null means find account so overlap
        fprintf(stderr, "Error, account number %s already exists\n", num);
        exit(50);
    }
    fprintf(fp , "AC,%s,%s\n",num, name);
}

void deposit(FILE* fp, var* start, char* num, char* date, char* amount){
    if(search(start, num ) == NULL){ //deposit & withdrawl same logicbut reverse
        fprintf(stderr, "Error, account number %s does not exist\n", num);
        exit(50);
    }
    fprintf(fp, "TX,%s,%s,%s\n",num, date , amount);
}

void withdrawl(FILE* fp, var* start, char* num, char* date, char* amount){
    var* newa;
    if((newa = search(start, num )) == NULL){
        fprintf(stderr, "Error, account number %s does not exist\n", num);
        exit(50);
    }
    double amount1 = strtod(amount, NULL);
    if(amount1 > newa->money){//is this right?
        fprintf(stderr, "Error, account number %s has only %.2lf\n", num , newa->money);
        exit(50);
    }
    fprintf(fp, "TX,%s,%s,-%s\n",num, date, amount);
}

int main(int argc , char* argv[]){
   
    int switchcase; //for switch statement
    //need every scenario to avoid seg fault
    if(argc < 2){
        fprintf(stderr, "Error, incorrect usage! \n-a ACCTNUM NAME\n-d ACCTNUM DATE AMOUNT\n-w ACCTNUM DATE AMOUNT\n");
        exit(1);
    } //customized error message
    if(strcmp(argv[1], "-a") == 0){
        if(argc < 4){
            fprintf(stderr, "Error, incorrect usage! -a ACCTNUM NAME\n");
            exit(1);
        }
        switchcase = 1;
    }
    else if(strcmp(argv[1], "-d") == 0){
        if(argc < 5){
            fprintf(stderr, "Error, incorrect usage! -d ACCTNUM DATE AMOUNT\n");
            exit(1);
        }
        switchcase = 2;
    }
    else if(strcmp(argv[1], "-w") == 0){
        if(argc < 5){
            fprintf(stderr, "Error, incorrect usage! -w ACCTNUM DATE AMOUNT\n");
            exit(1);
        }
        switchcase = 3;
    }
    else{ //for all other incorrect input format
        fprintf(stderr, "Error, incorrect usage! \n-a ACCTNUM NAME\n-d ACCTNUM DATE AMOUNT\n-w ACCTNUM DATE AMOUNT\n");
        exit(1);
    }
    
    FILE* fp = fopen("bankdata.csv", "r");
    if(fp == NULL){ //for unavailable file
        fprintf(stderr, "Error, unable to locate the data file bankdata.csv\n");
        exit(100);
    }
    
    var* start = csv(fp); //need to firstly read r mode then close reopen for append
    fclose(fp);
    fp = fopen("bankdata.csv", "a");
    
    switch(switchcase){ //for different addaccount, deposit, withdrawl scenarios
        case 1:
            addaccount(fp, start, argv[2], argv[3]);
            break;
        case 2:
            //
            deposit(fp, start, argv[2], argv[3], argv[4]);
            break;
        case 3:
            withdrawl(fp, start, argv[2], argv[3], argv[4]);
            break;
    }
    fclose(fp); //close file pointer
    return 0;
}

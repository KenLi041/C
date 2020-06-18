//
//  main.c
//  COMP206
//
//  Created by Yiming Li on 2/12/20.
//  Copyright © 2020 Ken Li. All rights reserved.
//

/*
 Program to implement a simple caesar cipher
 Author     Dept        Date        Notes
 Ken Li Comp. Science . Feb 13 2020 Initial version .
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//look at argv in the slides

int main(int argc, const char * argv[]) {
    char string[200]; //define variables: the input string and a temporary variable to store the chaning input
    int i = 0, offset = 0;  //i = 0 missed, i for incremental variable that transfer every elements from letters to temp, offset variable for user entering offset
    //scan all inputs
    if (argc < 2){ //if input argument < 2 print error message & output1
        fprintf(stderr, "Error: usage is caesarcipher <offset>\n"); return 1;
    }
    offset = atoi(argv[1]);
    char ch;
    while((ch=getchar()) != '\n'){
 //use getchar for reading multiple lines
    if(sscanf(argv[1], "%d", &offset) == 1){
    
  
    
    //if(sscanf(argv[1], "%d", &offset) == 1 &&
    //sscanf(argv[2], "%c", &string) == 1){
    
    //int lastch = getchar() + 1;
    //if (ch == '\n'){
    //if (lastch == '\n'){exit(-1);}
    //else printf("Error: usage is caesarcipher <offset>"); return 1;}
    
    while(ch != EOF){
        //printf("%d", strlen(letters));
        //printf("%s", letters);
        
        //for (i = 0; i < strlen(ch); i++){
        
        //if(letters[i] == letters[strlen(letters)]){
        //    break;
        //}
        
        if (ch != '\n'){string[i] = ch;
            //read again
        }
        //if (ch == '\n32'){return 0;}
        
        if (ch >= 'A' && ch <= 'Z'){
            int temp = ch;
            putchar((char) temp);
            
        }
        //else if (ch == EOF){
        //    printf("EOF detected");
        //    int temp = ch;
        //    putchar((char) temp);
        //}
        else if (ch == 32){
            //puts('space detected');
            int temp = 32;
            putchar((char) temp);
        }
        
        else if(ch >= 'a' && ch <= 'z'){
            if(offset > 0){ //normal encryption scenario
                int temp = (ch - 'a' + offset)%26 + 'a';
                putchar((char) temp);
            }
            else if(offset < 0){ //normal decryption scenario
                if ((ch - 'a' + offset)%26 < 0){
                    int temp = 26 + (ch - 'a' + offset)%26 + 'a';
                    putchar((char) temp);

                }
                
                else {int temp = (ch - 'a' + offset)%26 + 'a';
                    putchar((char) temp);}
            }
        } //putchar
        //else 后要扛进去不然直接就return 1结束了
        else  {
            int temp = ch;
            putchar((char) temp);
            
        }
        ch = getchar();
    }if (ch == EOF){
        putchar(ch);
    }
    
    }
    } return 0;
}





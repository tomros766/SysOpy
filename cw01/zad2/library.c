#include "library.h"
#include <string.h>

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


//char**** createTable(int size, char* args[]);
//char*** prepareSequence(char* args[]);
//FILE* compare(char*** sequence, char**** table);
//int putBlock(FILE* block, char**** table);
//int getOpCnt(char*** block);
//void deleteBlock(char**** table, int index);
//void deleteOp(char*** block, int index);

size_t max(size_t s1, size_t s2){
    if(s1>= s2) return s1;
    else return s2;
}

char*** createTable(int size){
    
    char*** table = (char ***) calloc(size, sizeof(char**));
    return table;
}

char*** prepareSequence(char* args[], int size){
    if(size < 2) return NULL;

    char*** sequence = (char***) calloc(size/2, sizeof(char**));
    
    for(int i = 0; i < size - 1; i+=2){
        char** op = (char **) calloc(2,sizeof(char*));
        op[0] = args[i + 1];
        op[1] = args[i+ 2];
        sequence[i/2] = op;
    }
    return sequence;
}

void blockToTmpFile(char* f1, char* f2){
        char command [15 + strlen(f1) + strlen(f2)];
       
        strcpy(command, "diff ");
        strcat(command, f1);
        strcat(command, " ");
        strcat(command, f2);
        strcat(command, " >> block");
        system(command);
}

void compare(char*** sequence, char*** table){
    int size = 0;
    while(sequence[size]) size++;
    system("touch block");

    for(int i = 0; i < size; i++){
        blockToTmpFile(sequence[i][0], sequence[i][1]);
    
        putBlock("block", table);
        
        system("truncate -s 0 block");
    }

}

int putBlock(char blockname[], char*** table){
    int index = 0;
    while(table[index]) index++;
    FILE *block;
    block = fopen(blockname, "r");
    
    if(block == NULL)
    {
        printf("Error!");
        exit(1);
    }
    char* line = NULL;
    size_t tmpsize = 0;
    int it = 0;
    
    
    while(getline(&line, &tmpsize, block) != -1){
        if(line[0]>= 48 && line[0] <= 57) it++;
    }
     
    
    char **ops = (char **) calloc(it, sizeof(char *));
    free(line);
    line = NULL;
    
    // block = fclose(blockname);
    block = fopen(blockname, "r");
        
    int i;
    char* op;
    for(i = -1; i < it -1; ){
             
        op = calloc(10000,sizeof(char));
        while(getline(&line, &tmpsize, block) >= 0){
            
            if(line[0]>= 48 && line[0] <= 57) {
                
                i++;
                if(i > 0) {
                    ops[i-1] = op;
                }
                op = calloc(10000,sizeof(char));
            }
            
            if(op[0] == '\0'){
                op = strcpy(op,line); 
            }
            else{
                strcat(op, line);
            }
            
        } 
        free(line);
        line = NULL;
    }

    ops[i] = op;

    table[index] = ops;
    return index;

}

int getOpCnt(char** block){
    int i = 0;
    while(block[i]) i++;
    return i;
};

void deleteBlock(char*** table, int index) {
    if(table[index]){
        for(int i = 0; i < getOpCnt(table[index]) ; i++){
            deleteOp(table[index], i);
        }
        free(table[index]);
        table[index] = NULL;
    }
};

void deleteOp(char** block, int index){
    if(block[index]){
        free(block[index]);
        block[index] = NULL;
    }

}
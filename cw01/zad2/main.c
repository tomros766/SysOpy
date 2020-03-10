//
// Created by tomasz on 10.03.2020.
//

#include <stdio.h>
#include "library.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

double count_time(clock_t t1, clock_t t2){
    return ((double)(t2-t1)/CLOCKS_PER_SEC);
}

bool charInString(char c, char *string){
    if(!string) return false;
    for(int i = 0; i < strlen(string); i++){
        if(string[i]==c) return true;
    }
    return false;
}

bool stringInString(char *s1, char *s2){
    if (!s1) return true;
    if (!s2) return false;
    for(int i = 0; i < strlen(s1); i++){
        if(!charInString(s1[i],s2)) return false;
    }
    return true;
}

int toNumber(char* s){
    int res = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            res = res*10 + (s[i] - '0');
        }
        else return -1;
    }
    return res;
}



int main(int argc, char* argv[]){

    struct tms **tms_time = malloc(6*sizeof(struct tms*));
    clock_t real_time[2];
    for (int i=0; i<2; i++){
        tms_time[i] = (struct tms*) malloc(sizeof(struct tms*));
    }

    real_time[0] = times(tms_time[0]);


    if(argc == 1){
        printf("no arguments given! \n");
        exit(1);
    }
    if(strcmp(argv[1],"create_table") != 0){
        printf("you must create table first \n");
        exit(1);
    }
    else{
        if(!stringInString(argv[2],"1234567890")){
            printf("wrong table size \n");
            exit(1);
        }
        else{
            int size = toNumber(argv[2]);
            char ***table = createTable(size);
            int pairscnt = 0;
            int i = 3;
            while(i < argc){
                if(strcmp(argv[i], "compare_pairs")==0){
                    if(i==argc){
                        printf("no files to compare \n");
                        exit(1);
                        }
                    i++;
                    while(i<argc && charInString(':', argv[i])){
                        if(pairscnt>=size){
                            printf("Too many operations for too small array!\n");
                            exit(1);
                        }
                        
                        char* s1 = calloc(strlen(argv[i]), sizeof(char));
                        char* s2 = calloc(strlen(argv[i]), sizeof(char));
                        int k=0;
                        while(argv[i][k]!=':'){
                            s1[k]=argv[i][k];
                            k++;
                        }
                        int ind = 0;
                        for(int j=k+1; j<strlen(argv[i]); j++){
                            s2[ind] = argv[i][j];
                            ind++;
                        }
                        blockToTmpFile(s1, s2);
                        putBlock("block", table);
                        system("truncate -s 0 block");
                        free(s1);
                        free(s2);
                        i++;
                    }
                }
                else{ 
                    if (strcmp(argv[i],"remove_block")==0){
                        if (i<argc-1){
                            i++;
                            int index = toNumber(argv[i]);
                            if(index!=-1)
                                deleteBlock(table, index);
                            i++;
                        }
                        else{
                            printf("Nothing to remove");
                            exit(1);
                        }
                    }
                    else{
                        if (strcmp(argv[i], "remove_operation")==0){
                            if (i<argc-2){
                                i++;
                                int blockindex = toNumber(argv[i]);
                                if (blockindex >= size){
                                    printf("on such block index \n");
                                    exit(1);
                                }
                                i++;
                                int opindex = toNumber(argv[i]);
                                if (blockindex!=-1 && opindex!=-1)
                                    deleteOp(table[blockindex], opindex);
                                i++;
                            }
                            else{
                                printf("Too few arguments");
                                exit(1);
                            }
                        }
                        else {
                        printf("%s\n", argv[i]);
                        printf("unknown argument\n");
                        exit(1);
                    }
                    }        
                }
            }
        }
    }

    real_time[1] = times(tms_time[1]);
    printf("Czasy wykonania:\n");
    printf("Rzeczywisty:\n");
    printf("%lf   ", count_time(real_time[0], real_time[1]));
    printf("\nUzytkownika\n");
    printf("%lf   ", count_time(tms_time[0]->tms_utime, tms_time[1]->tms_utime));
    printf("\nSystemowy\n");
    printf("%lf \n", count_time(tms_time[0]->tms_stime, tms_time[1]->tms_stime));

    return 0;
}

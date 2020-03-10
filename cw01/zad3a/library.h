#ifndef SYSOPY_LAB1_LIBRARY_H
#define SYSOPY_LAB1_LIBRARY_H

#include <bits/types/FILE.h>

struct block{
    int opCnt;
    char* ops[];
};

char*** createTable(int size);
char*** prepareSequence(char* args[], int size);
void compare(char*** sequence, char*** table);
int putBlock(char block[], char*** table);
int getOpCnt(char** block);
void deleteBlock(char*** table, int index);
void deleteOp(char** block, int index);


#endif //SYSOPY_LAB1_LIBRARY_H

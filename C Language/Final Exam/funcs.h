/**************************************************************
STUDENT CODER NAME : ABDULHAKEEM MOHAMMED AL-ABSI
DATE : JAN 5, 2021
UNIVERSITY :  Eötvös Loránd University
THIS PROGRAM WAS A SOLUTION FOR A TASK GIVEN AS A FINAL EXAM
FIND THE PROBLEM DESCRIPTION IN (TASK DECRIPTION.TXT)
**************************************************************/

#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED
#define WORD_BUFFER_SIZE 32

typedef struct pair {
char str[WORD_BUFFER_SIZE];
int num;
}pair;

typedef struct map{
    pair** items;
    int size;
}map;

void init(map*);
void dest(map* m);
pair* find(map* ,char*);
void set(map*,char*,int);
int get (map* ,char* strg);
void print(map*);

#endif // FUNCS_H_INCLUDED

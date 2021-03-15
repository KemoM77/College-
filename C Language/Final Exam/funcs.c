/**************************************************************
STUDENT CODER NAME : ABDULHAKEEM MOHAMMED AL-ABSI
DATE : JAN 5, 2021
UNIVERSITY :  Eötvös Loránd University
THIS PROGRAM WAS A SOLUTION FOR A TASK GIVEN AS A FINAL EXAM
FIND THE PROBLEM DESCRIPTION IN (TASK DECRIPTION.TXT)
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"


void init(map* m ){

m->size = 0;
m->items = NULL;

}




void dest(map* m ){
for (int i = 0 ; i < m->size ; i++)
    {

        free(m->items[i]);

    }
    free(m->items);
}


pair* find( map* m, char* str){

pair* p =NULL;
 for (int i = 0 ; i < m->size ; i++ ){

    if(strcmp(str,m->items[i]->str)==0)
    {
        p = m->items[i];
    }
 }


    return p;
}

void set(map *m,char* strg ,int n){


	m->size ++;
    m->items = (pair**) realloc ( m->items, (m->size) * sizeof(pair*));  // when element is added, memory should be extended. (number of pointers increased)
    m->items[ (m->size-1) ] = malloc(sizeof(pair)); // then each pointer should point to pair object. In order to that, memory is allocated.

    strcpy( m->items[ (m->size-1) ]-> str, strg);
    n++;
    m->items[ (m->size-1) ]-> num = n;


    printf("memory is allocated %d \n", m->size);


}

int get (map* m,char* strg){

pair* p;
p = find (m,strg);

if  (p == NULL)
    {
        set (m,strg,0);
        return 0;

    }

    else
        p->num++;
        return p->num;
}


void print(map* m){
for (int i = 0 ; i < m -> size ; i++)
    {
        printf(" %s -> %d \n", m ->items[i] -> str, m -> items[i]->num);
    }

}

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

int main(int argc, char *argv[])
{


 map* m;
 map M;
 m=&M;  // the pointer should point to that object(now m pointer points to M object)

// or you have the following option
//m=malloc(sizeof(map));

init(m);
m->items = (pair**) malloc (sizeof(pair*));

FILE* fp = NULL;
char  buf[WORD_BUFFER_SIZE];
if(argc < 2)
    {
        fp = stdin;
        while(fscanf(fp,"%s",buf) != EOF){

            get(m,buf);


        }
    }

else {
for (int i = 1 ; i < argc ;i++){

    fp = fopen(argv[i], "r");

while(fscanf(fp, "%s",buf) != EOF)
    {
        get(m,buf);
     }

}
}

fclose(fp);
print(m);
dest(m);

    return 0;
}

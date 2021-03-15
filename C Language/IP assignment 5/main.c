/**************************************************************
STUDENT CODER NAME : ABDULHAKEEM MOHAMMED AL-ABSI
DATE : Dec 12, 2020
UNIVERSITY :  Eötvös Loránd University
THIS PROGRAM WAS A SOLUTION FOR A TASK GIVEN AS AN ASSIGNMENT
FIND THE PROBLEM DESCRIPTION IN (TASK DECRIPTION.TXT)
**************************************************************/









#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "rle.h"

int main() {

//Here is inputing the string , and checking if  it meets the requirments.
char sequence[500];
printf("\nEnter The Sequence : ");
scanf("%s",sequence);
int i=0;
while (i < strlen(sequence) && sequence[i] >= 'a' && sequence[i] <= 'z'   )
    {i++;}

if (i < strlen(sequence))
    {
        printf("Bad input!");
        exit(0);
    }


// Here we encode the string was added by the user
struct Encoded* encodedTxt=NULL;
encodedTxt=encode(sequence);

for (int i = 0 ; i < encodedTxt->length ; i++)
    {
        printf("(%c, %d) ", encodedTxt->arr[i]->c , encodedTxt->arr[i]->n );
    }

//Here we are Decoding the encoded string using its pointer
char* decodedTxt;
decodedTxt= decode(encodedTxt);
printf("-> %s",decodedTxt);


//Here we deallocate all used pointers
for (int j = 0 ; j < encodedTxt->length ; j++)
 {
   free(encodedTxt->arr[j]);
 }

 free(encodedTxt);
 free(decodedTxt);

   return(0);
}



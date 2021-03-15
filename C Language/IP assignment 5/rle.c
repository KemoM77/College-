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


///ENCODIING  FUNCTION THAT TAKE A STRING (SEQUENCE OF CHARACTERS) AND ENCODE IT INTO CHARACTERS AND NUMBERS(ENCODED TYPE)
///AND RETURN ENCODED TYPE
struct Encoded* encode( char *sequence){
struct Encoded* encodedTxt;
encodedTxt = (struct Encoded* ) malloc (sizeof(struct Encoded));
encodedTxt->length = 1;
 for (int i =1 ; i < strlen(sequence) ;i++)
 {
     if (sequence[i] != sequence[i-1])
         {
             encodedTxt->length++;
         }
 }
encodedTxt->arr = (struct Pair** ) malloc ((encodedTxt->length)*sizeof(struct Pair*));
 for (int j = 0 ; j < encodedTxt->length  ; j++)
 {
     encodedTxt->arr[j] = (struct Pair* ) malloc (sizeof(struct Pair));
 }
 int ind=0;
encodedTxt->arr[ind]->c = sequence[0];
encodedTxt->arr[ind]->n = 1;
for (int i =1 ; i < strlen(sequence) ;i++)
 {
     if (sequence[i] == sequence[i-1])
         {
             encodedTxt->arr[ind]->n++;

         }
    else
         {
            ind++;
           encodedTxt->arr[ind]->c = sequence[i];
            encodedTxt->arr[ind]->n = 1;
         }
 }
return encodedTxt;
}





///ENCODIING  FUNCTION THAT TAKE ENCODED TYPE AND DECODE IT INTO SEQUENCE OF CHARACTERS(STRING) AND RETURN IT
char* decode (struct Encoded* encodedTxt){

char* decodedTxt;
int lengthOfString;
for (int i = 0 ; i < encodedTxt->length ;i++)
{
lengthOfString += encodedTxt->arr[i]->n;
}
decodedTxt = (char*) malloc (lengthOfString*sizeof(char));
int charNum=0;
for(int j = 0 ; j < encodedTxt->length;j++)
{
    for(int f = 0 ; f < encodedTxt->arr[j]->n;f++)
    {
        decodedTxt[charNum] = encodedTxt->arr[j]->c;
        charNum++;
    }
}
return decodedTxt;
}





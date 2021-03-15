/**************************************************************
STUDENT CODER NAME : ABDULHAKEEM MOHAMMED AL-ABSI
DATE : Dec 12, 2020
UNIVERSITY :  Eötvös Loránd University
THIS PROGRAM WAS A SOLUTION FOR A TASK GIVEN AS AN ASSIGNMENT
FIND THE PROBLEM DESCRIPTION IN (TASK DECRIPTION.TXT)
**************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidTime(char* TimFrmt ){
if ( TimFrmt[0] < '0' || TimFrmt[0] > '2' )
       return 0;
    if ( TimFrmt[1] < '0' || TimFrmt[1] > '9' )
       return 0;
    if ( TimFrmt[2] != ':' )
        return 0;
    if ( TimFrmt[3] < '0' || TimFrmt[3] > '5' )
       return 0;
    if ( TimFrmt[4] < '0' || TimFrmt[4] > '9' )
        return 0;
    if ( TimFrmt[5] != '\0' )
        return 0;

    if ( TimFrmt[0] == '2' && TimFrmt[1] > '3' )
        return 0;

    else
return 1;}


int isValidNote(char* NtFrmt){


for(int i=0;i < strlen(NtFrmt) ;i++){
	if (('A' <= (int)NtFrmt[i] && (int)NtFrmt[i]<='Z' || 'a' <= (int)NtFrmt[i] && (int)NtFrmt[i]<='z') == 0)
return 0;}

return 1 ;}



int main(int argc, char* argv[])
{
    FILE *fp;
	fp = fopen("todolist.txt","w");

	if(argc < 3){
	printf("wrong input! (more arguments needed)\n");}

	else {
	    for (int i = 1 ; i < argc ; i+=2 ){
        if ( isValidTime(argv[i]) == 0 ||  isValidNote(argv[i+1]) == 0 )
            printf("Wrong Input\n");
        else { fprintf(fp,"%s - %s\n",argv[i],argv[i+1]);}
            }


	}
	fclose(fp);

return 0;
}

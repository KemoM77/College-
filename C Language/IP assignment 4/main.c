/**************************************************************
STUDENT CODER NAME : ABDULHAKEEM MOHAMMED AL-ABSI
DATE : Dec 6, 2020
UNIVERSITY :  Eötvös Loránd University
THIS PROGRAM WAS A SOLUTION FOR A TASK GIVEN AS AN ASSIGNMENT
FIND THE PROBLEM DESCRIPTION IN (TASK DECRIPTION.TXT)
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size= 10;
int count = 0;
typedef struct Person
{
char name[30];
unsigned int age;
char job[30];
} Person;

Person **iterator = NULL;

void Add_person (char *N,unsigned int A ,char *J)
{
			if(size<=count)
			{
              size+=5;
              iterator = (Person**)realloc(iterator,size*sizeof(Person*));

              for(int i=count; i<size; i++)
                {
                     iterator[i]=malloc(sizeof(Person));
                }

			}

          	 strcpy(iterator[count]->name,N);
          	 strcpy(iterator[count]->job, J);
          	 iterator[count]->age= A;
          	 count++;
}


void List_people(){
    printf("\n\nThe List :-\n\n");
    for (int i = 0 ; i < count ; i++)
    {
        printf("Name: %s        Age: %u        Job: %s \n\n",iterator[i]->name,iterator[i]->age,iterator[i]->job);

    }

     printf("\nTHE TOTAL NUMBER OF PEOPLE IS: %d",count);

}


 void Del_person ( int ind ) {

    count-- ;

    for (int i = 0 ;i < count; i++)
    {
        if (i >= ind)
        {
         strcpy(iterator[i]->name,iterator[i+1]->name);
         iterator[i]->age = iterator[i+1]->age;
         strcpy(iterator[i]->job,iterator[i+1]->job);
        }

        else
        {
            strcpy(iterator[i]->name,iterator[i]->name);
            iterator[i]->age = iterator[i]->age;
            strcpy(iterator[i]->job,iterator[i]->job);
        }

    }

    if (size - count >= 5 && size > 10 )
    {
         for (int i = size-1 ; i > count;i--)
        {
            free(iterator[i]);
        }

        size -=5;

        iterator = (Person** ) realloc(iterator,size * (sizeof (Person*) ));

    }

}


void Exit_program(){


     for (int i = 0 ; i > size ;i++)
        {
            free(iterator[i]);
        }

    free(iterator);
    exit(0);

}




int main()
{

iterator = (Person** ) malloc (size * sizeof(Person*));

    for(int i=0; i<size; i++)
    {
        iterator[i]=malloc(sizeof(Person));
	}


while (1){
printf("__________________________________________________________________________________________________________\n");
printf("THE MENU:-\n\n- A:To Add a new person to the database.\n");
printf("- L:To List the whole database.\n");
printf("- D:To Delete person from the database.\n");
printf("- X:To Exit from the program.\n\n");
printf("THERE ARE %d PEOPLE ALREADY IN THE LIST.\nTHE DATABASE CARRYING CAPACITY NOW IS : %d.\n\n",count,size);

printf("Select one of the menu items: ");

char buf;
scanf("%s",&buf);

        switch (buf)
            {
                case 'A':

                        printf("\nAdding new person :-\n");
                        printf("Please Enter the person's name here(30 chars MAX): ");
                        char temp_name[32];
                        scanf("%s",temp_name);

                       // int length_name_of_person = strlen(temp_name);

                        while ( strlen(temp_name) >= 30)
                        {printf("\nWRONG INPUT, (you entered too long name, please try again).\n\n");
                        scanf("%s",temp_name);}
                        //else

                           printf("Please Enter the person's age: ");
                            unsigned int temp_age;
                            scanf("%u", &temp_age);

                            printf("Please Enter the person's job (30 chars MAX): ");
                            char temp_job[32];
                            scanf("%s",temp_job);

                            //int length_name_of_job = strlen(temp_job);
                            while(strlen(temp_job) >= 30)
                            {printf("\nWRONG INPUT, (you entered too long name, please try again).\n\n");
                              scanf("%s",temp_job);}

                            //else

                                    Add_person(temp_name,temp_age,temp_job);
                                    printf("\n\nINFORMATIONS WERE SAVED SUCCESSFULLY.\n\n");




                break;

                case 'L':
                  if ( count == 0 ){printf("THERE IS NO PEOPLE IN THE LIST YET, SO PLEASE ADD SOME PEOPLE FIRST.\n\n");}
                    else{
                        List_people();
                         printf("\n");
                        }
                break;

                case 'D':
                      if ( count == 0 ){printf("There is no people to delete yet, so please add some people first.\n\n");}
                    else{
                            printf("Please enter the name of the person you want to delete from the database: ");
                            char temp_delName[30];
                            scanf("%s",temp_delName);
                            int index = 0;
                            while (index < count && ((strcmp(temp_delName,iterator[index]->name)) != 0))
                                {
                                    index++;
                                }
                            if (index >= count) {printf("There is no such name, please check whether you entered an existing name.\n\n");}

                            else{
                                printf("\n\n%s INFORMATIONS WERE DELETED SUCCESSFULLY.\n ",iterator[index]->name);

                                Del_person(index);
                                printf("\n");
                                }

                        }
                break;

                case 'X':
                    printf("GOODBYE, HOPE SEE YOU AGAIN. \n");
                    Exit_program();

                    break;

                default:
                    printf("WRONG ITEM, PLEASE TRY AGAIN.\n\n");

            }



         }


    return 0;
}

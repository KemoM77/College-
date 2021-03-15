/**************************************************************
STUDENT CODER NAME : ABDULHAKEEM MOHAMMED AL-ABSI
DATE : Dec 12, 2020
UNIVERSITY :  Eötvös Loránd University
THIS PROGRAM WAS A SOLUTION FOR A TASK GIVEN AS AN ASSIGNMENT
FIND THE PROBLEM DESCRIPTION IN (TASK DECRIPTION.TXT)
**************************************************************/

#ifndef RLE_H_INCLUDED
#define RLE_H_INCLUDED

struct Pair {
char c;
int n;
};

struct Encoded{
int length;
struct Pair **arr;
};
struct Encoded* encode( char*);
char* decode (struct Encoded*);

#endif

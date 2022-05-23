#ifndef MYHEADERFILES_H
#define MYHEADERFILES_H

int staircase(int);
int binarySearch(int [], int, int);
int binarySearch_helper(int [],int ,int ,int);
int subset(int [], int n, int [][20]) ;

// Print Array substring
void printSubsetsOfArray_helper(int [], int , int *,int ) ;
void printSubsetsOfArray(int [], int )  ;

int subsetSumToK(int [], int , int [][50], int ) ;


void printSubsetSumToK_helper(int [],int , int , int , int []) ;
void printSubsetSumToK(int [], int , int ) ; 

#endif
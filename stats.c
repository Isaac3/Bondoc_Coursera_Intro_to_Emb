/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 *
 * @brief code for a few functions that analyze an array of unsigned char data
 * 	  data items. Functions find minimum, maximum, mean, median, and sort
 * 	  the array.
 *
 * @author Isaac Bondoc
 *
 * @date 10/27/2018
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
 // print_statitics();
  printf("Below is the UNSORTED array\n");
  print_array(test,SIZE);
  printf("\n\n");
  printf("Below is the SORTED array\n");
  sort_array(test,SIZE);
  print_array(test,SIZE);
  printf("\n\n");
  int median = find_median(test,SIZE);
  printf("\nThe median is %d\n\n",median);
}


/* Add other Implementation File Code Here */
void print_array(char * x ,int y) 
{
	for(int i = 0; i<y; i++)
       	{
		printf("%d ",*(x+i));
	}
	printf("\n");
}

int find_median(char * x, int y)
{
	int median=0, temp=0;
	if(y%2 == 0)
	{
	  temp = y/2;
	  median = (*(x+temp)+*(x+temp+1))/2;
	}
	else
	  median = *(x+temp+1);

	return median;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(char* x, int b)
{
	// if b is zero, then there is only one element left
	if(b==1)
	  return ;
	
	// Bubble sort. After this pass the largest element is bubbled
	// to the end.
	for(int i = 0; i<b-1;i++)
	{
		printf("TEST[%d] = %d  and TEST[%d]= %d\n\n",i,*(x+i),i+1,*(x+i+1));
		if(*(x+i) > *(x+i+1))
		  swap((x+i), (x+i+1));
	}

	// Recur for the remaining element of the array
	sort_array(x, b-1);
}

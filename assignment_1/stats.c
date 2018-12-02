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
 print_statistics(test,SIZE);
}


/* Add other Implementation File Code Here */
void print_statistics(unsigned char *x, int y)
{
	printf("Unsorted Array is Below:\n");
	print_array(x,y);
        sort_array(x,y);
	printf("\n\nSorted Array is Below:\n");
	print_array(x,y);	
	printf("\n\nMinimum is: %d \n", find_minimum(x,y));
	printf("Maximum is: %d \n", find_maximum(x,y));
        printf("The median is %d \n", find_median(x,y));
	printf("The mean is %d \n", find_mean(x,y));
}

void print_array(unsigned char * x ,int y) 
{
	for(int i = 0; i<y; i++)
       	{
		printf("%d ",*(x+i));
	}
	printf("\n");
}

int find_median(unsigned char * x, int y)
{
	int median=0, temp=0;
	temp = y/2;
	if(y%2 == 0)
	{
	  median = (*(x+temp-1)+*(x+temp))/2;
	}
	else
	  median = *(x+temp);

	return median;
}

void swap(unsigned char *a, unsigned char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(unsigned char* x, int b)
{
	// if b is zero, then there is only one element left
	if(b==1)
	  return ;
	
	// Bubble sort. After this pass the largest element is bubbled
	// to the end.
	for(int i = 0; i<b-1;i++)
	{
		if(*(x+i) < *(x+i+1))
		  swap((x+i), (x+i+1));
	}

	// Recur for the remaining element of the array
	sort_array(x, b-1);
}

int find_mean(unsigned char *x, int b)
{
	int sum = 0, mean = 0;
	for(int i = 0; i < b; i++)
	{
		sum += *(x+i);
	}
	mean = sum/b;

	return mean;
}

int find_maximum(unsigned char *x, int b)
{
	sort_array(x,b);
	return *x;
}

int find_minimum(unsigned char *x, int b)
{
	sort_array(x,b);
	return *(x+b-1);
}

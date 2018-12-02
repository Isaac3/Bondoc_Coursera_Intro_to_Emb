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
 * @file Isaac Bondoc
 * @brief Header file for stats.c
 *
 * @author Isaac Bondoc
 * @date 10/27/2018
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_statistics(unsigned char * x, int y);
/**
 * @brief A function that prints the statistics of an array including minimum,
 * 	  maximum, mean, and median.
 *
 * @param char *: pointer to traverse array
 * @param int : holds size of array
 *
 * @return NONE
 */

void print_array(unsigned char *, int);
/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param char *: point to traverse array
 * @param int: size of array
 *
 * @return NONE
 */

int find_median(unsigned char *,int);
/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param char *: point to traverse array
 * @param int: size of array
 *
 * @return integer with the median value of the array
 */

int find_mean(unsigned char *,int);
/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param char *: point to traverse array
 * @param int: size of array
 *
 * @return integer with the mean value of the array
 */

int find_maximum(unsigned char *,int);
/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param char *: point to traverse array
 * @param int: size of array
 *
 * @return integer with the maximum value of the array
 */

int find_minimum(unsigned char *,int);
/**
 * @brief Given an array of data and a length, return the minimum
 *
 * @param char *: pointer to traverse array
 * @param int : holds size of array
 *
 * @return integer with the minimum value of the array
 */

void sort_array(unsigned char *,int);
/**
 * @brief Given an array of data an a length, sorts the array from largest to
 * 	  smallest. (Zeroth element should be largest value)
 *
 *
 * @param char *: point to traverse array
 * @param int: size of array
 *
 * @return sorted array
 */

void swap(unsigned char *a,unsigned char *b);
/**
 * @brief Given an array of data an a length, sorts the array from largest to
 * 	  smallest. (Zeroth element should be largest value)
 *
 *
 * @param char *a: pointer to memory location that will be swapped with b
 * @param char *b: pointer to memory location that will be swapped with a
 *
 * @return none
 */

#endif /* __STATS_H__ */

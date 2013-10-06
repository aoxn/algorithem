/*
 * file: sort.h
 * author: spacedudu
 * version: V0.1
 * initial: 2013-10-03
 */
#include "sort.h"
#include "../utils/util.c"
void bubble_sort(int a[],int n,int min,int max)
{
  int i,j,tmp;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n-i-1;j++)
	{
	  if(a[j] > a[j+1])
	    {
	      swap_int(&a[j],&a[j+1]);
	    }

	}
    }
  return ;
}

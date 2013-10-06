/*
 * file   : binary_search.c
 * author : 15549400497@163.com
 * history: 
 * initial: 2013-09-30
 */
#include <stdlib.h>
#include "binary_search.h"

#define assert(x)
#define pdata(arr,pos,size) (((void *)arr)+size*pos)

void * bin_search(const void *arrp,size_t cnts,size_t size,void *key,cmpf cmp){
  int min=0,max=cnts-1,mid;
  assert(arrp&&key&&cmp);
  while(min <= max){
    mid = min + ((max - min)>>1);
    if(cmp(pdata(arrp,mid,size),key)>0){
      //go to left area
      max = mid-1;
    }else if(cmp(pdata(arrp,mid,size),key)<0){
      //go to right area
      min = mid+1;
    }else{
      //bingo we find it
      return pdata(arrp,mid,size);
    }
  }
  return 0;
}

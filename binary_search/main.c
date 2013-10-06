/*
 * file   : main.c
 * author : 15549400497@163.com
 * history:
 * initial: 2013-09-30
 */

#include <stdio.h>
#include "binary_search.h"
static int cmp(const int *first,const int *second){
  if(*first > *second)
    return 1;
  else if(*first < *second)
    return -1;
  else
    return 0;
}
static void dump(int *arrp, size_t cnts ){
  int i=0;
  while(i < cnts){
    printf("%d ",arrp[i++]);
  }
  printf("\n");
}

#define test(arr,cnts,key) {\ 
dump((arr),(cnts));\ 
int *res = bin_search((arr),cnts,sizeof(arr[0]),&key,cmp);\
if(*res==0)\
  printf("Num [%d] Not Found!\n",key);\
else\
  printf("Num [%d] Found!\n",key);\
}
int main(){
  int arr[]={1,4,9,16,25,36};
  int key = 16;
  test(arr,6,key);
  
}

/*
 * file: sort.h
 * author: spacedudu
 * version: V0.1
 * initial: 2013-10-03
 */
#include <stdio.h>
#include "../sort/sort.c"

int min(int *ser,int m)
{
  int min,i,j=0;
  //assert(ser&&m>0);
  min = ser[0];
  for (i=1;i<m;i++)
    {
      if (ser[i] < min)
	{
	  j=i;
	  min = ser[i];
	} 
    }
  return j;
}
void task_dispatch(int task[], int n, int ser[], int m)
{
  int i,m_ser;
  bubble_sort(task,n,0,n-1);
  for(i = n-1; i >= 0; i--)
    {
      m_ser = min(ser,m);
      ser[m_ser] += task[i];
      printf("Task [%d] dispatch to server num [%d]\n ",task[i],m_ser);
    }
  return ;
}


int main()
{
  int t[]={4,8,6,5,7};
  int s[3]={0,0,0};
  task_dispatch(t,5,s,3);
}

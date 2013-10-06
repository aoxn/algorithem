/*
 *    file: fullarrange
 *  author: space
 *    mail: 15549400497@163.com
 * history: 2013-10-01
 *  modify:
 * version: v1.0
 */

#include <stdio.h>
#include "fullarrange.h"
void swap(char *a , char *b )
{
  char tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}
void arrange(char * str, char *begin)
{
  static int i=0;
  char *p=begin;
  if(*begin=='\0') printf("%4d:%s\n",++i,str);
  for(;*p!='\0';p++)
  {
    swap(begin,p);
    arrange(str,begin+1);
    swap(begin,p);
  }
  return;
}


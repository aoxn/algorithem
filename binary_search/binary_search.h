/* file: binary_search.h
 *
 * author: 15549400497@163.com
 * history:
 * initial:2013-09-30
 */

#ifndef _H_BINSEARCH_
#define _H_BINSEARCH_
typedef int (*cmpf)(const int *first,const int *second);
void * bin_search(const void *arrp,size_t cnts,size_t size,void *key,cmpf cmp);
#endif

#include "fullarrange.h"

int main()
{
  char s[]="abc";
  char str[100];
  arrange(s,s);
  printf("Please input String:");
  scanf("%s",str);
  arrange(str,str);
  return 0;
}

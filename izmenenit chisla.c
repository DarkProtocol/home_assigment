#include <stdio.h>
#include <stdlib.h>

int chislo( int a)
{
if (a>0)
     a=a*2;
     else 
        if (a<0)
         a=a-3;
         else 
                 a=10;
    printf("chislo a= %d",a);
	return(a);	
}



int main()
{
  int a;
  printf("Vvedite a\n"); 
  scanf("%d",&a);
  chislo(a);
    return 0;
}



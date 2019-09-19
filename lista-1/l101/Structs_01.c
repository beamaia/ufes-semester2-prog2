#include <stdio.h>
#include <stdlib.h>
/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.   
*/

typedef struct {
   int p, q, sinal;
} racional;

int divisivel(int num, int div)
{
   return num % div == 0;
}

int num_maior(int n1, int n2)
{
   return n1 >= n2;
}

int limite_min(int a, int b)
{
   if(num_maior(a, b))
      return b;
   else
      return a;
}

racional reduz (int a, int b) 
{
   if(b < 0)
   {
      b = b * -1;
      a = a * -1;
   }

   int lim = limite_min(a, b);
   for(int i = lim; i >= 2; i--)
   {
      if(divisivel(a, i) && divisivel(b, i))
      {
         a = a/i;
         b = b/i;
      }
   }  

   racional r;
   r.p = a;
   r.q = b;
   return r;
}

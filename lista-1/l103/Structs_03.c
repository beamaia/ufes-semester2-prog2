#include <stdio.h>

/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.
*/

typedef struct {
   int p, q;
} racional;

int limite_min(int a, int b)
{
   if(a >= b)
      return b;
   else
      return a;
}

racional reduz (int a, int b) 
{
   int sinal = 1;
   racional r;
   r.p = a;
   r.q = b;

   if(b < 0)
   {
      sinal = -1;
      r.q = b * -1;
   }

   if(a < 0)
   {
      sinal = sinal * -1;
      r.p = a * -1;
   }
   
   int lim = limite_min(r.p, r.q);
   for(int i = lim; i >= 2; i--)
   {
      if(r.p % i == 0 && r.q % i == 0)
      {
         r.p = r.p/i;
         r.q = r.q/i;
      }
   }  

   r.p = r.p * sinal;
   return r;
}

racional soma (racional x, racional y) {
	
	racional s; 
   s.q = x.q * y.q;
   s.p = (x.p * y.q) + (y.p * x.q);
   s = reduz(s.p, s.q);
   return s;	
}

int main()
{
   racional r1, r2, s;
   
   scanf("%d%d%d%d", &r1.p, &r1.q, &r2.p, &r2.q);
   s = soma(r1, r2);
   printf("(%d/%d)", s.p, s.q);
   return 0;
}
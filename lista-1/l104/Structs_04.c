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
   int x = a, y = b;

   if(a < 0)
      x = a*-1;
   if(b < 0)
      y = b *-1;

   if(x >= y)
      return x;
   else
      return y;
}

racional reduz (int a, int b) 
{
   int lim = limite_min(a, b);
   racional r;
   r.p = a;
   r.q = b;

   if(b < 0)
   {
      r.q = b * -1;
      r.p = a * -1;
   }

   for(int i = lim; i >= 2; i--)
   {
      if(a % i == 0 && b % i == 0)
      {
         r.p = r.p/i;
         r.q = r.q/i;
      }
   }  

   return r;
}

/* Recebe os racionais x e y e devolve o racional que representa o produto de x por y */
racional produ (racional x, racional y) {

   racional a, b;
   a.p = x.p * y.p;
   a.q = x.q * y.q;
	
   a = reduz(a.p, a.q);
   return a;
}

int main()
{
   racional r1, r2, s;
   
   scanf("%d%d%d%d", &r1.p, &r1.q, &r2.p, &r2.q);
   s = produ(r1, r2);
   printf("(%d/%d)", s.p, s.q);
   return 0;
}
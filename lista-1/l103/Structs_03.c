#include <stdio.h>

/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.
*/

typedef struct {
   int p, q;
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
   int x = a, y = b;

   if(a < 0)
      x = a*-1;
   if(b < 0)
      y = b *-1;

   if(num_maior(x, y))
      return x;
   else
      return y;
}

racional reduz (int a, int b) 
{
   int lim = limite_min(a, b);

   if(b < 0)
   {
      b = b * -1;
      a = a * -1;
   }

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
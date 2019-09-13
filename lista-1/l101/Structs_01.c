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

void leia_racional(racional *r)
{
   scanf("%d", &r->p);
   scanf("%d", &r->q);
}

int tem_sinal(int num)
{
   return num < 0;
}

int divisivel(int num, int div)
{
   return num % div == 0;
}

void numero_negativo(racional * r)
{
   if(tem_sinal(r->p) && tem_sinal(r->q))
   {
      r->sinal = 0;
      r->p = abs(r->p);
      r->q = abs(r->q);
   }
   else if(tem_sinal(r->q))
   {
      r->sinal = 1;
      r->q = abs(r->q);
   }
   else if(tem_sinal(r->p))
   {
      r->sinal = 1;
      r->p = abs(r->p);
   }
   else
      r->sinal = 0;
}

int num_maior(int n1, int n2)
{
   return n1 >= n2;
}

int limite_min(racional *r)
{
   if(num_maior(r->p, r->q))
      return r->q;
   else
      return r->p;
}

void reduz (racional *r, int lim) 
{
   for(int i = lim; i >= 1; i--)
   {
      if(divisivel(r->p, i) && divisivel(r->q, i))
      {
         r->p = r->p/i;
         r->q = r->q/i;
      }
   }   
}

void calcula(racional * r)
{
   int lim;
   numero_negativo(r);
   lim = limite_min(r);
   reduz(r, lim);
}

void apresenta(racional r)
{
   if(r.sinal)
      printf("-");
   
   printf("%d/%d\n", r.p, r.q);
}

int main()
{
   racional numero;
   leia_racional(&numero);
   if(numero.q != 0)
   {
      calcula(&numero);
      apresenta(numero);
   }
   return 0;
}
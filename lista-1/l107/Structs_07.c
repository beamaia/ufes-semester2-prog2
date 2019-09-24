/* Estrutura para representar um ponto no espaço 2D */
typedef struct ponto {
   float x;
   float y;
} Ponto;

/* INSIRA SEU CODIGO AQUI, CASO DESEJE CRIAR ALGUMA FUNCAO AUXILIAR */



/* Funcao que indica se um dado ponto p estah localizado dentro ou fora de um retangulo.
   O retangulo eh definido por seus vertices inferior esquerdo v1 e superior direito v2.
   A funcao retorna 1 caso o ponto esteja localizado dentro do retangulo, e 0 caso contrario,
   sendo que os limites sao considerados como parte do retangulo */
int dentroRet (Ponto v1, Ponto v2, Ponto p)
{
   if((v1.x <= p.x <= v2.x) && (v1.y <= p.y <= v2.y))
      return 1;
   else
      return 0; 
}

int main()
{
   Ponto esqinf, supdir, pon;
   scanf("%d%d%d%d%d%d", &esqinf.x, &esqinf.y, &supdir.x, &supdir.y, &pon.x, &pon.y);

   int sit;
   sit = dentroRet(esqinf, supdir, pon);
}
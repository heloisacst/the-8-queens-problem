#include <stdio.h>
#include <stdlib.h>
 
//k é igual a indice 

funcao Troca(inteiro v[], inteiro i, inteiro j) 

var
  inteiro tmp;
  inicio
  tmp = v[i]; 
  v[i] = v[j];
  v[j] = tmp;
  
fimFuncao

inteiro SolucaoValida(inteiro linhas[])

	var
      inteiro i;
      inteiro x,y;
      inteiro xx,yy;
 
  para i de 0 até 8 faça
    x = i;
    y = linhas[i];
  fimPara
  
  var
    xx = x;
    yy = y;
    
    enquanto verdadeiro
      xx += 1;
      yy -= 1;
      se(xx > 7 || yy < 0) entao 
	     break 
	  fimSenao
       
      se(yy == linhas[xx]) entao
        return 0 
		
	  fimSenao
    fimEnquanto
 
 	var
      xx = x;
      yy = y;
    
    enquanto verdadeiro
      xx -= 1;
      yy -= 1;
      
      se(xx < 0 || yy < 0) entao 
	     break
	  fimSe
       
      se(yy == linhas[xx]) entao
        retorna 0;
      fimSe
    fimEnquanto

  retorna 1;
  
fimFuncao

funcao ImprimeSolucao(inteiro linhas[])
  caracter tabuleiro[8][8];
  inteiro i,j;
  inteiro x,y;
  estatico inteiro nsols = 0;
 
  nsols++;
 
  imprime("******** SOL: %d ********\n", nsols);
 
  
  para i de 0 até 8 faça
    para j de até faça
      tabuleiro[i][j] = '.';
    paraFim
  paraFim
 
  para i de 0 até 8 faça
    x = i;
    y = linhas[i];
    tabuleiro[y][x] = 'R';
  paraFim
 
  para i de 0 até 8 faça
    para j de 0 até 8 faça
      imprime(" %c ",tabuleiro[i][j]);
    paraFim   
    imprime("\n");
  paraFim
fimFuncao

funcao void Solucoes8Rainhas()
  inteiro linhas[8];
  inteiro i;
 para i de 0 até 8 faça
    linhas[i] = i;
  TestaPermutacoes(linhas, 0);
  paraFim
fimFuncao

funcao TestaPermutacoes(inteiro linhas[], inteiroeiro k)
  inteiroeiro i;
   
  se(k == 8) entao
    se(SolucaoValida(linhas))
      ImprimeSolucao(linhas);
    fimSe
  fimSe
  
  senao
    para i de 0 até 8 faça
      Troca(linhas, k, i);
      TestaPermutacoes(linhas, k + 1);
      Troca(linhas, i, k);
    paraFim
  fimSenao
fimFuncao

funcao main(){
	
  Solucoes8Rainhas();
  return 0;

fimFuncao



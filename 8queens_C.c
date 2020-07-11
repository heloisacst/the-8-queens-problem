#include <stdio.h>
#include <stdlib.h>
 
//k é igual a indice 

Algoritmo "8 Rainhas"

funcao Troca(int v[], int i, int j){
	
  int tmp;
  tmp = v[i]; 
  v[i] = v[j];
  v[j] = tmp;
  
}

funcao SolucaoValida(int linhas[]){
  int i;
  int x,y;
  int xx,yy;
 
  for(i = 0; i < 8; i++){
    x = i;
    y = linhas[i];
 
    xx = x;
    yy = y;
    
    while(1){
      xx += 1;
      yy -= 1;
      if(xx > 7 || yy < 0) break;
       
      if(yy == linhas[xx]) 
        return 0;
    }
 
    xx = x;
    yy = y;
    while(1){
      xx -= 1;
      yy -= 1;
      if(xx < 0 || yy < 0) break;
       
      if(yy == linhas[xx]) 
        return 0;
    }
  }
  return 1;
}

funcao ImprimeSolucao(int linhas[]){
	
  caractere tabuleiro[8][8];
  inteiro i,j, x, y;
  global inteiro nsols = 0; //global?
 
  nsols++;
 
  imprima("******** SOL: %d ********\n", nsols);
 
  for(i = 0; i < 8; i++)
    for(j = 0; j < 8; j++)
      tabuleiro[i][j] = '.';
 
  for(i = 0; i < 8; i++){
    x = i;
    y = linhas[i];
    tabuleiro[y][x] = 'R';
  }
 
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf(" %c ",tabuleiro[i][j]);
    }    
    printf("\n");
  }
}

funcao Solucoes8Rainhas() {
  inteiro linhas[8];
  inteiro i;
  for(i = 0; i < 8; i++)
    linhas[i] = i;
  TestaPermutacoes(linhas, 0);
}

funcao TestaPermutacoes(int linhas[], int k) {
  inteiro i;
   
  if(k == 8) {
    SE(SolucaoValida(linhas))
      ImprimeSolucao(linhas);
  }
  else{
    for(i = k; i < 8; i++) {
      Troca(linhas, k, i);
      TestaPermutacoes(linhas, k + 1);
      Troca(linhas, i, k);
    }
  }
}

int main(){
  Solucoes8Rainhas();
  return 0;
}



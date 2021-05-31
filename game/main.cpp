#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 3

void tabuleiro();
void menu();

int main(void)
{
  setlocale(LC_ALL,"Portuguese");
  menu();
  
  return 0;
}

void menu(){
  int num;
  char resp;
  do{
    //system("clear"); // clear no linux
	system("cls");
    printf("#############################################\n");
    printf("# CLIQUE [1] PARA INICIAR O JOGO DA VELHA   #\n");
    printf("# CLIQUE [2] PARA VER O MANUAL DO JOGO      #\n");
    printf("#-------------------------------------------#\n");
    printf("# CLIQUE [3] PARA INICIAR O JOGO DA MEMORIA #\n");
    printf("# CLIQUE [4] PARA VER O MANUAL DO JOGO      #\n"); // falta fazer
    printf("#############################################\n");
    printf("\nDIGITE O NUMERO ESCOLHIDO!\n");
    scanf("%d",&num);
    Beep(700,50); // retirar quando for usar no linux
    Beep(1000,50);
	switch(num){
      case 1:
        tabuleiro();
      break;
      case 2:
        system("cls");
        printf("Um jogador joga com o círculo ( O ) e outro com os xis ( X ). Cada jogador, na sua vez, desenha (ou coloca a peça ), numa lacuna que esteja vazia. Quando um jogador conquista o objetivo, costuma-se riscar os três símbolos. Quando há empate costuma-se dizer que o jogo “deu velha”.\n");
      break;
  }
  printf("\n\nDeseja voltar para o menu principal? [S-N]\n");
  scanf("%s",&resp);
    Beep(700,50);
    Beep(1000,50); 
  }while(resp == 's'|| resp == 'S');
    system("cls");
	printf("\nFIM DO PROGRAMA!!\nObrigado por jogar");
}
void tabuleiro(){
  int cont,linha,coluna,vezes=0,i,j;
  char resp;
  char casas2[TAM][TAM]= {{'1','2','3'},
                          {'4','5','6'},
                          {'7','8','9'} };
  
  //----
  
  do{
    cont=1;
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
        casas2[i][j]=' '; 
      }
    }
    do{
      system("cls"); 
      printf("\n\t\t[1] [2] [3]      ->Coluna\n\n");
      printf("\t\t %c | %c | %c  [1]  ->Linha\n",casas2[0][0],casas2[0][1],casas2[0][2]);
      printf("\t\t-----------\n");
      printf("\t\t %c | %c | %c  [2]\n",casas2[1][0],casas2[1][1],casas2[1][2]);
      printf("\t\t-----------\n");
      printf("\t\t %c | %c | %c  [3]\n  ",casas2[2][0],casas2[2][1],casas2[2][2]);
      if(vezes %2==0){
	  	printf("\nJogador 1  ou X\n");
	  }else{
	  	printf("\nJogador 2  ou O\n");
	  }
	  printf("Digite a linha: \n");
      scanf("%i",&linha);
      Beep(1400,70);
      printf("\nDigite a coluna: \n");
      scanf("%i",&coluna);
      Beep(1400,70);
	  
	
	  if(linha < 1 || coluna < 1 || linha > 3 || coluna >3){
		linha=0;
        coluna=0;
        Beep(250,400);
	  	cont=11;
	  }
	  else if (casas2[linha-1][coluna-1]!= ' '){
        linha=0;
        coluna=0;
    	Beep(250,400);
	  }else{
        if(vezes%2==0){
          casas2[linha-1][coluna-1]='X';
        }else{
          casas2[linha-1][coluna-1]='O';
        }
      }
      vezes++;
      cont++;
      //--
	  system("cls"); 
	  if(casas2[0][0] == 'X' && casas2[0][1] == 'X'&& casas2[0][2] == 'X'){
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
		casas2[0][0]='-',casas2[0][1]='-',casas2[0][2]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
		cont=11;
	  }
      else if(casas2[1][0] == 'X' && casas2[1][1] == 'X'&& casas2[1][2] == 'X'){
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
		casas2[1][0]='-',casas2[1][1]='-',casas2[1][2]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
		cont=11;
	  }
      else if(casas2[2][0] == 'X' && casas2[2][1] == 'X'&& casas2[2][2] == 'X'){
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
	  	casas2[2][0]='-',casas2[2][1]='-',casas2[2][2]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
      else if(casas2[0][0] == 'X' && casas2[1][0] == 'X'&& casas2[2][0] == 'X'){ //coluna esqerda
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
	  	casas2[0][0]='|',casas2[1][0]='|',casas2[2][0]='|';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }	 	  	  
      else if(casas2[0][1] == 'X' && casas2[1][0] == 'X'&& casas2[2][0] == 'X'){
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
		casas2[0][1]='-',casas2[1][0]='-',casas2[2][0]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }	  
      else if(casas2[0][1] == 'X' && casas2[1][1] == 'X'&& casas2[2][1] == 'X'){ // coluna meio
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
	  	casas2[0][1]='|',casas2[1][1]='|',casas2[2][1]='|';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
      else if(casas2[0][2] == 'X' && casas2[1][2] == 'X'&& casas2[2][2] == 'X'){ // coluna direita
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
	  	casas2[0][2]='|',casas2[1][2]='|',casas2[2][2]='|';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }	
      else if(casas2[0][0] == 'X' && casas2[1][1] == 'X'&& casas2[2][2] == 'X'){ //-- diagonal
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
	  	casas2[0][0]='\\',casas2[1][1]='\\',casas2[2][2]='\\';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
      else if(casas2[0][2] == 'X' && casas2[1][1] == 'X'&& casas2[2][0] == 'X'){ //-- diagonal
	  	printf("Parabens!! o jogador X ou 1 é o vencedor\n");
	  	casas2[0][2]='/',casas2[1][1]='/',casas2[2][0]='/';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
	 
	  //--- segundo jogador
	 
	  if(casas2[0][0] == 'O' && casas2[0][1] == 'O'&& casas2[0][2] == 'O'){
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
		casas2[0][0]='-',casas2[0][1]='-',casas2[0][2]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
		cont=11;
	  }
      else if(casas2[1][0] == 'O' && casas2[1][1] == 'O'&& casas2[1][2] == 'O'){
		printf("Parabens!! o jogador O ou 2 é o vencedor\n");
		casas2[1][0]='-',casas2[1][1]='-',casas2[1][2]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
		cont=11;
	  }
      else if(casas2[2][0] == 'O' && casas2[2][1] == 'O'&& casas2[2][2] == 'O'){
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
	  	casas2[2][0]='-',casas2[2][1]='-',casas2[2][2]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
      else if(casas2[0][0] == 'O' && casas2[1][0] == 'O'&& casas2[2][0] == 'O'){ //coluna esqerda
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
	  	casas2[0][0]='|',casas2[1][0]='|',casas2[2][0]='|';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }	 	  	  
      else if(casas2[0][1] == 'O' && casas2[1][0] == 'O'&& casas2[2][0] == 'O'){
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
		casas2[0][1]='-',casas2[1][0]='-',casas2[2][0]='-';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }	  
      else if(casas2[0][1] == 'O' && casas2[1][1] == 'O'&& casas2[2][1] == 'O'){ // coluna meio
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
	  	casas2[0][1]='|',casas2[1][1]='|',casas2[2][1]='|';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
      else if(casas2[0][2] == 'O' && casas2[1][2] == 'O'&& casas2[2][2] == 'O'){ // coluna direita
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
	  	casas2[0][2]='|',casas2[1][2]='|',casas2[2][2]='|';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }	
      else if(casas2[0][0] == 'O' && casas2[1][1] == 'O'&& casas2[2][2] == 'O'){ //-- diagonal
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
	  	casas2[0][0]='\\',casas2[1][1]='\\',casas2[2][2]='\\';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
      else if(casas2[0][2] == 'O' && casas2[1][1] == 'O'&& casas2[2][0] == 'O'){ //-- diagonal
	  	printf("Parabens!! o jogador O ou 2 é o vencedor\n");
	  	casas2[0][2]='/',casas2[1][1]='/',casas2[2][0]='/';
		Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  	cont=11;
	  }
			  		  	 
    }while(cont<10); 
	  printf("\n\t\t[1] [2] [3]      ->Linha\n\n");
      printf("\t\t %c | %c | %c  [1]  ->Coluna\n",casas2[0][0],casas2[0][1],casas2[0][2]);
      printf("\t\t-----------\n");
      printf("\t\t %c | %c | %c  [2]\n",casas2[1][0],casas2[1][1],casas2[1][2]);
      printf("\t\t-----------\n");
      printf("\t\t %c | %c | %c  [3]\n  ",casas2[2][0],casas2[2][1],casas2[2][2]);
      
	  
	  if(cont == 10){
	  	printf("Deu velha!!\n");
	  	Beep(3000,130);
    		Beep(2000,130);
		Beep(1560,130);
	  }
	
	  printf("\n\nDeseja jogar novamente [S / N]\n");
      scanf("%s",&resp);
      Beep(700,50);
      Beep(1000,50); 
   }while(resp == 's' || resp == 'S');
   system("cls");
   printf(" FIM do programa!!");
}

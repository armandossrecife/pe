#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int menu(){
int k;
printf("Menu Principal\n1-Checa uma nota válida\n2-Imprime números impares\n3-Palavra invertida\n4-Soma de matrizes\n5- Produto de matrizes\n6-Sair\n");
  scanf("%i",&k);
  return k;
  

}

void checa_nt(float valor){

 

  do{
    
    printf("Informe um valor de 0 a 10:");
    scanf("%f",&valor);
    
    if(valor<0||valor>10){
    printf("Valor inválido digite novamente:");
    printf("\n\n");
    
    }
  }while(valor<0||valor>10);


  
}

void num_impar(int num){

int  i;

  printf("Digite um número inteiro qualquer:");
  scanf("%d",&num);

  if(num%2==0){

   num = num+1;
printf("%d\n",num);
    for(i=0;i<9;i++){

      printf("%d\n", num += 2);
    }
     
    
  } else{

    num = num;
    for(i=0;i<10;i++){
     printf("%d\n",num+=2);
      
    }
  }


  
}

void nome_invertido(char palavra[10]){


 int i ,z;

printf("Digite uma palavra de até 10 caracteres:");
scanf("%s",palavra);
z = strlen(palavra);

while(z>10){

  printf("A palavra digita está acima do limite de caracteres!!!");
  printf("\n");
  printf("Digite novamente!!!\n");
  scanf("%s",palavra );
  z = strlen(palavra);
  if(z <10){
    break;
  }
    
}  
printf("Palavra invertida:\n");
for(i = z-1;i>=0;i--){

  printf("%c",palavra[i]);
}
  
}

void soma_de_matrizes(void){

int l , c;
float matriz1[2][3],matriz2[2][3],matriz3[2][3];

printf("Digite os valores da matriz 1:\n");
  for(l=0;l<2;l++){
  for(c=0;c<3;c++){
  printf("Valores da Matriz 1:[%d][%d]\n", l+1,c+1);
    scanf("%f",&matriz1[l][c]);

    
  }
  }
  printf("\n");
  printf("Digite os valores da matriz 2:\n");
  for(l=0;l<2;l++){
  for(c=0;c<3;c++){
  printf("Valores da Matriz 2:[%d][%d]\n", l+1,c+1);
    scanf("%f",&matriz2[l][c]);
    }
    }
  printf("\n");

  for(l=0;l<2;l++){
  for(c=0;c<3;c++){
    matriz3[l][c] =matriz1[l][c] + matriz2[l][c];
  }
 }
   printf("\n");
  printf("Matriz Soma:\n");
  for(l=0;l<2;l++){
  for(c=0;c<3;c++){
  printf("Matriz Soma:[%d][%d]: %2.f\n", l+1,c+1,matriz3[l][c]);
    }
    }
  

}


void produto_de_matrizes(void){

  int l , c;
float matriz1[2][2],matriz2[2][2],matriz3[2][2];

printf("Digite os valores da matriz 1:\n");
  for(l=0;l<2;l++){
  for(c=0;c<2;c++){
  printf("Valores da Matriz 1:[%d][%d]\n", l+1,c+1);
    scanf("%f",&matriz1[l][c]);

    
  }
  }
  printf("\n");
  printf("Digite os valores da matriz 2:\n");
  for(l=0;l<2;l++){
  for(c=0;c<2;c++){
  printf("Valores da Matriz 2:[%d][%d]\n", l+1,c+1);
    scanf("%f",&matriz2[l][c]);
    }
    }
  printf("\n");

  for(l=0;l<2;l++){
  for(c=0;c<2;c++){
    matriz3[l][c] =matriz1[l][c] + matriz2[l][c];
  }
 }
   printf("\n");
  printf("Matriz Soma:\n");
  for(l=0;l<2;l++){
  for(c=0;c<2;c++){
  printf("Matriz Soma:[%d][%d]: %2.f\n", l+1,c+1,matriz3[l][c]);
    }
    }
  
}
int main(void) {
  
  int j;
  float valor;
  int num;
  char palavra[10];

  
  do
  {
  	j = menu();
  	printf("\n");
    switch(resp)
    {  
        
        case 1: 
        	 checa_nt(valor);
        	 printf("\n");
			     break;
		    
        case 2:
			     num_impar(num); 
           printf("\n");
				   break;
		    
        case 3:
  			    nome_invertido(palavra);
            printf("\n");
				    break;
		    
        case 4:
			      soma_de_matrizes();
            printf("\n");
				    break;	
  		  
        case 5:
  			    produto_de_matrizes();
            printf("\n");
				    break;	
		    
        case 6:
        	  break;
        
        default:
        	  printf("Esta opção nao esta no menu, por favor digite uma opção válida:\n ");
        	  printf("\n");
        	  break;
    }
  
}while(j!=6);
  
  return 0;
}

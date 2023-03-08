#include <stdio.h>
#include <string.h>

//variáveis globais
int i,j;

//função para o menu
int menu(){
  	int op;
  	printf("\n-------------Menu Principal-------------\n");
  	printf("1 - Checa uma nota válida\n2 - Imprime números ímpares\n");
  	printf("3 - Palavra invertida\n4 - Soma de matrizes\n");
  	printf("5 - Produto de matrizes\n6 - Sair\n");
  	printf("----------------------------------------\n");
  	printf("Escolha uma opção:\n");
  	scanf("%d",&op);
  	return op;	
  }

//funcionalidade 1 - obrigar inserir nota válida
void func1(){
  float nota;

  printf("Digite uma nota válida:\n");
  do{
    scanf("%f",&nota);

    if(nota < 0 || nota > 10){
      printf("Nota inválida! Digite novamente:\n");
    }
  }while(nota < 0 || nota > 10);

  printf("Você digitou %.2f que é uma nota válida!\n",nota);
}

/*funcionalidade 2 - 10 números ímpares após um número escolhido 
pelo usuário*/
void func2(){
  int num;

  printf("Digite um número:\n");
  scanf("%d",&num);
  printf("Os 10 primeiros números ímpares depois do%d são:\n",num);

  if(num%2==0){
    num=num+1;
    printf("\n%d\n", num);

    for(i=0; i<10; i++){
      num=num+2;
      printf("%d\n", num);
    }
    
    printf("\n");
    
  } else {
    for(i=0; i<10; i++){
      num=num+2;
      printf("\n%d\n", num);
    }
    printf("\n");
  }
}

//funcionalidade 3 - mostra palavra invertida
void func3(){
  char palavra[50]; /*o tamanho de 50, se deve pois, por exemplo, com o tamanho 11 digitando uma palavra de 12 caracteres, para repetir a palavra dá erro e não a mostra invertida, assim, se garante a digitação de uma palavra certa e errada */
  int tam;
  
  printf("Digite uma palavra de até 10 caracteres:\n");
  do{
  scanf("%s", palavra);

  tam = strlen(palavra);
    
  if(tam>10){
    printf("Essa palavra possui mais de 10 caracteres.Insira outra palavra!\n");
    }
  }while(tam>10);

  printf("Palavra invertida: ");
  for(i=strlen(palavra)-1; i>=0; i--){
      printf("%c", palavra[i]);
  }
}  

//funcionalidade 4 - soma de 2 matrizes 2x3
void func4(){
  float m1[2][3], m2[2][3], msoma[2][3];

  for(i=0;i<2;i++){
    printf("Digite os elementos da linha %d da matriz 1:\n",i+1);
    for(j=0;j<3;j++){
      scanf("%f",&m1[i][j]);
    }
  }

  for(i=0;i<2;i++){
    printf("Digite os elementos da linha %d da matriz 2:\n",i+1);
    for(j=0;j<3;j++){
      scanf("%f",&m2[i][j]);
    }
  }

  //somando...
  for(i=0;i<2;i++){
    for(j=0;j<3;j++){
      msoma[i][j] = m1[i][j] + m2[i][j];
    }
  }

  printf("\nMatriz soma das 2 matrizes 2x3:\n");
  for(i=0; i<2; i++){
    for(j=0; j<3; j++){
      printf("%.1f ",msoma[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

//funcionalidade 5 - multiplicação de 2 matrizes 2x2 
void func5(){
  float m1[2][2], m2[2][2], mprod[2][2];
  int k; //variável para auxiliar na multiplicação

  for(i=0;i<2;i++){
    printf("Digite os elementos da linha %d da matriz 1:\n",i+1);
    for(j=0;j<2;j++){
      scanf("%f",&m1[i][j]);
    }
  }

  for(i=0;i<2;i++){
    printf("Digite os elementos da linha %d da matriz 2:\n",i+1);
    for(j=0;j<2;j++){
      scanf("%f",&m2[i][j]);
    }
  }

  //inicialização da matriz resultado da multiplicação
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      mprod[i][j]=0;
      }
    }

  //multiplicando...
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      for(k=0; k<2; k++){
        mprod[i][j] = mprod[i][j] + m1[i][k]* m2[k][j];
      }
    }
  }

  printf("\nMatriz produto das 2 matrizes 2x2:\n");
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      printf("%.1f ",mprod[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(){
  int res;

  do{
   res = menu();

  switch(res){
    case 1: func1();
            break;

    case 2: func2();
            break;

    case 3: func3();
            break;

    case 4: func4();
            break;

    case 5: func5();
            break;

    case 6: break;
    default: printf("Opção inválida! Digite novamente:\n");
  }
  }while(res!=6);
  return 0;
}
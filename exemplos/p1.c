#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define total_alunos 50
#define mat 12
typedef struct tpAluno {
  char nome[50];
  char matricula[mat];
  float notas[3], media;
  int ativo;
} tpAluno;
tpAluno alunos[total_alunos];
void menu();
void cadastrar();
void listar_alunos();
void pesquisar();
void mostrar_media();
void listar_media();
int main(void) {
  menu();
  return 0;
}
void menu() {
  int o;
  do {
    printf("\n———————— Menu Principal ———————————————");
    printf("\n(1). Cadastrar aluno e notas\n(2). Listar todos os alunos\n");
    printf("(3). Pesquisar as notas de um aluno\n(4). Mostrar a media geral da "
           "turma\n");
    printf("(5). Listar as médias finais dos alunos\n(6). Sair\n");
    printf("———————————————————————————————————————\n");
    scanf("%d", &o);
    switch (o) {
    case 1:
      cadastrar();
      break;
    case 2:
      listar_alunos();
      break;
  	case 3:
	  pesquisar();
	  break;
    case 4:
      mostrar_media();
	  break;
    case 5:
      listar_media();
      break;
    case 6:
      break;
    default: 
      printf("\nOpção inválida!\n");
    }	   	
  } while (o != 6);
}

void cadastrar() {
  char nome[50];
  char matricula[mat];
  float notas[3], media;
  int o, i;
  do {
    printf("\nNome: ");
    scanf(" %[^\n]s", &nome);
    printf("\nMatricula: ");
    scanf("%s", &matricula);
    printf("\nNota 1: ");
    scanf("%f", &notas[0]);
    while(notas[0]<0 || notas[0]>10){
      printf("\nNota invalida!\nDigite um novo valor!\n");
      scanf("%f", &notas[0]);
    }
    printf("\nNota 2: ");
    scanf("%f", &notas[1]);
    while(notas[1]<0 || notas[1]>10){
      printf("\nNota invalida!\nDigite um novo valor!\n");
      scanf("%f", &notas[1]);
    }    
    printf("\nNota 3: ");
    scanf("%f", &notas[2]);
    while(notas[2]<0 || notas[2]>10){
      printf("\nNota invalida!\nDigite um novo valor!\n");
      scanf("%f", &notas[2]);
    }    
    for (i = 0; i < total_alunos; i++) {
      if (alunos[i].ativo == 0) {
        strcpy(alunos[i].matricula, matricula);
        strcpy(alunos[i].nome, nome);
        alunos[i].notas[0] = notas[0];
        alunos[i].notas[1] = notas[1];
        alunos[i].notas[2] = notas[2];
        alunos[i].media = alunos[i].notas[0]+alunos[i].notas[1]+alunos[i].notas[2];
        alunos[i].ativo = 1;
        break;
      }
    }
    printf("\nDeseja cadastrar mais alunos?\n(1). continuar\n(2). sair\n");
    scanf("%d", &o);
  } while (o != 2);
}

void listar_alunos() {
  int i;
  printf("\nLista de alunos:\n");
  printf("\nMatricula - Nome - Nota 1 - Nota 2 - Nota 3 - MF\n");
  for (i = 0; i < total_alunos; i++) {
    if (alunos[i].ativo == 1) {
      printf("\n---------------------------------------------------------\n");
      printf("%s - ", alunos[i].matricula);
      printf("%s - ", alunos[i].nome);
      printf("%.2f - ", alunos[i].notas[0]);
      printf("%.2f - ", alunos[i].notas[1]);
      printf("%.2f - ", alunos[i].notas[2]);
      printf("%.2f\n", alunos[i].media/3.0);
      printf("---------------------------------------------------------\n");
    }
  }
};
void pesquisar(){
	int i;
	char matricula[mat];
	printf("\nDigite a matricula do aluno: ");
	scanf("%s", &matricula);
	for(i=0; i<total_alunos; i++){
    if(alunos[i].ativo==1){
		if(strcmp(alunos[i].matricula, matricula)==0){
      printf("\nMatricula - Nome - Nota 1 - Nota 2 - Nota 3 - MF\n");
   	  printf("\n---------------------------------------------------------\n");
      printf("%s - ", alunos[i].matricula);
      printf("%s - ", alunos[i].nome);
      printf("%.2f - ", alunos[i].notas[0]);
      printf("%.2f - ", alunos[i].notas[1]);
      printf("%.2f - ", alunos[i].notas[2]);
      printf("%.2f\n", alunos[i].media/3.0);
      printf("---------------------------------------------------------\n");
      return 0;
		}
    }
  }
      printf("\nAluno não cadastrado!\n");
    
};
void mostrar_media(){
	int i, cont=0;
	float media, soma_geral=0;
	for(i=0; i<total_alunos; i++){
		if(alunos[i].ativo==1){
		soma_geral = soma_geral + alunos[i].media;
		cont++;
	}
	}
	printf("\nPara os seguintes alunos cadastrados: \n");
	printf("\nMatricula - Nome - Nota 1 - Nota 2 - Nota 3 - MF\n");
	for(i=0; i<total_alunos; i++){
		if(alunos[i].ativo==1){
   	  printf("\n---------------------------------------------------------\n");
      printf("%s - ", alunos[i].matricula);
      printf("%s - ", alunos[i].nome);
      printf("%.2f - ", alunos[i].notas[0]);
      printf("%.2f - ", alunos[i].notas[1]);
      printf("%.2f - ", alunos[i].notas[2]);
      printf("%.2f\n", alunos[i].media/3.0);
      printf("---------------------------------------------------------\n");		
	}
	}
 	printf("\nA média final, neste momento, é %.2f\n", soma_geral/(3.0*cont));
};
void listar_media(){
  int i, j, z;
float f[total_alunos], aux = 0;
  for (i = 0; i < total_alunos; i++) {
    f[i] = alunos[i].media;
  }
  for (i = 0; i < total_alunos; i++) {
    for (j = i + 1; j < total_alunos; j++) {
      if (f[i] > f[j]) {
        aux = f[i];
        f[i] = f[j];
        f[j] = aux;
      }
    }
  }
printf("\nPara os seguintes alunos já cadastrados, ordenados pela média final: \n");
printf("\nMatricula - Nome - MF\n");
  for (i = total_alunos-1; i >= 0; i--) {
    if (f[i] == '\0') {
      break;
    }
    for (z = total_alunos-1; z >= 0; z--) {
      if (f[i] == alunos[z].media) {
      printf("\n---------------------------------\n");
      printf("%s - ", alunos[z].matricula);
      printf("%s - ", alunos[z].nome);
      printf("%.2f\n", alunos[z].media/3.0);
      printf("---------------------------------\n");
      }
    }
    }
  
};
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char nome[50];
  float notas[3];
  char matricula[12];
  float media[50];
  int ativo;
}ALUNO;

ALUNO alunos[50];

int contador = 0;

void menu();
void cadastro();
void listagem();
void pesquisar();
void media_turma();
void media_cada_aluno();
int confere();

int main(void) {
  menu();
  return 0;
}

void menu() {
  int op;
  do{
  system("clear");
  printf("MENU PRINCIPAL\n1. Cadastrar aluno e notas\n2. Listar todos os "
         "alunos\n3. Pesquisar as notas de um aluno\n4. Mostrar a media geral "
         "da turma\n5. Listar as medias finais dos alunos\n6. Sair\n");
  scanf("%d", &op);

  getchar();
  
  switch(op){
    case 1:
      cadastro();
      break;
    case 2:
      listagem();
      break;
    case 3:
      pesquisar();
      break;
    case 4:
      media_turma();
      break;
    case 5:
      media_cada_aluno();
      break;
    case 6:
      break;
  }
    
  getchar();

  }while(op!=6);
}

void cadastro(){
  char nome[50];
  float notas[3];
  char matricula[12];
  float media_aluno;
  int op;
  int i;

  do{
    system("clear");

    printf("\nNome: ");
    getchar();
    fgets(nome, 50, stdin);
    
    printf("\nMatricula: ");
    fgets(matricula, 12, stdin);
    
    printf("\nNota 1: ");
    scanf("%f", &notas[0]);
    
    printf("\nNota 2: ");
    scanf("%f", &notas[1]);
    
    printf("\nNota 3: ");
    scanf("%f", &notas[2]);

    media_aluno = 0;
    media_aluno = (notas[0]+notas[1]+notas[2])/3;

    for(i=0; i<50; i++){
      if(alunos[i].ativo == 0){
        alunos[i].notas[0] = notas[0];
        alunos[i].notas[1] = notas[1];
        alunos[i].notas[2] = notas[2];
        alunos[i].media[i] = media_aluno;
        strcpy(alunos[i].nome, nome);
        strcpy(alunos[i].matricula, matricula);
        
        alunos[i].ativo=1;

        contador++;
        printf("\nAluno cadastrado!\n");
        break;
      }
    }
    
    printf("\n1 - Continuar\n2 - Sair\n");
    scanf("%d", &op);
    op = confere(op);
    
}while(op!=2);
}
void listagem(){
  system("clear");
  printf("Lista dos alunos cadastrados:\n");
  for(int i=0; i<50; i++){
    if(alunos[i].ativo == 1){
       printf("%s - ", alunos[i].matricula);
       printf("%s", alunos[i].nome);
       printf("Nota 1: %.2f;", alunos[i].notas[0]);
       printf("Nota 2: %.2f;", alunos[i].notas[1]);
       printf("Nota 3: %.2f.", alunos[i].notas[2]);
       printf(" MF: %.2f.", alunos[i].media[i]);
       printf("\n===============");
       printf("======================\n");

     }
  }
  printf("\n\n\nAperte ENTER para voltar ao menu\n");

}
void pesquisar(){
  system("clear");
  char matricula[12];
  int op;
  int not=0;
  do{
    system("clear");
    not=0;
    printf("Digite a matricula do aluno para pesquisar: ");
    getchar();
    fgets(matricula, 12,stdin);
    for(int i=0;i<50;i++){
      if(strstr(alunos[i].matricula, matricula)!=NULL){
        printf("\n\n%s - ", alunos[i].matricula);
        printf("%s\n", alunos[i].nome);
        printf("Nota 1: %.2f;", alunos[i].notas[0]);
        printf("Nota 2: %.2f;", alunos[i].notas[1]);
        printf("Nota 3: %.2f.", alunos[i].notas[2]);
        printf(" MF: %.2f.\n", alunos[i].media[i]);
        break;           
      }else{
        not++;
      }   
    }
    if(not!=0){
      printf("\nAluno nao encontrado!\n");
    }  
    printf("\nPesquisar novamente?\n1 - Sim\n2 - Nao\n");
    scanf("%d",&op);
    
    op = confere(op);
    
  }while(op!=2);
  
}
void media_turma(){
  system("clear");
  
  float soma = 0;
  float media;
  
  for(int i=0; i<50; i++){
    if(alunos[i].ativo == 1){
      soma = soma + alunos[i].media[i];
    }
  }
  
  media = soma/contador;

  printf("Media geral da turma, neste momento: %.2f", media);
  printf("\n\n\nAperte ENTER para voltar ao menu\n");
  
}
void media_cada_aluno(){
  system("clear");
  
	int aux_nota;
  char aux_matricula[12];
  char aux_nome[50];
  int i;
  int j;
  
  printf("Media de cada um dos alunos cadastrados:\n\n");
	for(j=0; j<100; j++){
  	for(i=0; i<50; i++){
  		if(alunos[i].media[i]<alunos[i+1].media[i+1]){
  			aux_nota = alunos[i].media[i];  		  
        strcpy(aux_nome, alunos[i].nome);
        strcpy(aux_matricula, alunos[i].matricula);
        alunos[i].media[i] = alunos[i+1].media[i+1];
        strcpy(alunos[i].nome, alunos[i+1].nome);
        strcpy(alunos[i].matricula, alunos[i+1].matricula);
  			alunos[i+1].media[i+1] = aux_nota;
        strcpy(alunos[i+1].nome, aux_nome);
        strcpy(alunos[i+1].matricula, aux_matricula);
  		}
  	}
  }
	
for(int i=0; i<50; i++){
    if(alunos[i].ativo == 1){
       printf("%s - ", alunos[i].matricula);
       printf("%s", alunos[i].nome);
       printf(" MF: %.2f.", alunos[i].media[i]);
       printf("\n===============");
       printf("======================\n");
     }
  }
  
  printf("\n\n\nAperte ENTER para voltar ao menu\n");

}
int confere(int op){
	int op_ok;
	while(op<1 || op>2){
		printf("Opcao invalida, digite novamente: ");
		scanf("%d", &op);
	}
	op_ok = op;
	return op_ok;
}
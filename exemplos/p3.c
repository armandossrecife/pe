#include <stdio.h>

int main() {

int option=0;
char matricula[11];
char name[50];
float nota1=0;
float nota2=0;
float nota3=0;
float media = 0;
printf("--------MENU PRINCIPAL--------\n (1).Cadatrar alunos e notas\n (2).Listar todos os alunos\n (3).Pesquisar as notas de um aluno\n (4).Mostrar a média geral da turma\n (5).Listar as médias finais dos alunos\n (6).Sair\n------------------------------\n");

  scanf("%d", &option);

  if (option == 1){
  printf("DIGITE SUA MATRICULA:\n");
    scanf("%s", matricula);
  printf("DIGITE SEU NOME:\n");
    scanf("%s", name);
    printf ("DIGITE 3 NOTAS:\n");
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);
    media = (nota1+ nota2+nota3)/2;
    printf("SUA MÉDIA É: %f", media);
  
  
    scanf("%s", name);
    


} else if(option == 2){;
  

} else if(option == 3){;


}  else if(option == 4){;
  

} else if (option == 5){;
    

} else if(option == 6){
    
};
  
  
  
  }

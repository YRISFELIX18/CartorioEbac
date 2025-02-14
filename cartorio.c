#include <stdio.h>  // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de textos por região
#include <string.h> // biblioteca responsável por cuidar das string

int regristro() // função responsavel por cadrastar os usuários no sistema
{
	// inicio da criação da variavel/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação da variavel/string
	
	printf("digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy( arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadrstado: "); // colentando informação do usuário
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadrastado: "); // coletando informação do usuário
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadrstrado: "); // coletando informação do usuário
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consuta()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	 // inicio da criação da variavel/string
 	 char cpf[40];
 	 char conteudo[200];
 	 // final da criação da variavel /string
 	 
 	 printf("digite o CPF a ser consultado: "); // coletando informações do usuário
 	 scanf("%s", cpf); // %s refere-se a string
 	 
 	 FILE *file; // cria o arquivo
 	 file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler 
 	 
 	 if(file ==NULL)
 	 {
 	 	printf("não foi possivel abrir o arquivo, não localizamos!.\n");
	 }
	 
	 while(fgets(conteudo, 200,file) != NULL)
	 {
	 	printf("\nEssas são as informações do usuario: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
 	 
 	 system("pause");
}

int deletar()
{
	// inicio da criaçaõ da variavel/string
	 char cpf[40];
	 // final da criaçaõ da variavel/string
	 
	 printf("digite o CPF do usuário a ser deletado: "); // coletando informação do usuário
	 scanf("%s", cpf); // %s refere-se a string
	 
	 remove(cpf);
	 
	 FILE *file; // cria o arquivo
	 file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler
	 
	 if(file == NULL)
	 {
	 	printf("O usuário não se encontra no sistema!.\n");
	 	system("pause");
	 }
}


int main()
    {
    int opcao=0; // definindo variavez
    int laco=1;
    
    for(laco=1;laco=1;)
   {
	
	  system("cls"); // responsavel por limpa a tela
	  
      setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	    
      printf(" ### cartorio da EBAC ###\n\n"); // inicio do munu
      printf("escolha a opção desejada do menu:\n\n");
      printf("\t1 - registrar nomes\n");
      printf("\t2 - consutar nomes\n");
      printf("\t3 - deletar nomes\n\n");
      printf("\t4 - sair do sistema\n\n");
  	  printf("opção: "); // fim do menu

      scanf("%d", &opcao); // armazenamento a escolha do usuario
	       
      system("cls"); // responsavel por limpar a tela
      
      switch(opcao) // inicio da seleção do menu
      {
      	 case 1: // chamada de funções
      	 regristro(); 
      	 break;
	     
         case 2: // chamada de funções
         consuta();
         break;
     
         case 3: // chamada de funções
         deletar();
         break;
         
         case 4:
         printf("obrigado por ultiliza o sistema!");
         return 0;
         break;
     
         default:
         printf("essa opção não está disponivel!\n");
         system("pause");
         break;
	    }
   } 
}
   
   

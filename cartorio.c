#include <stdio.h>  // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de textos por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int regristro() // fun��o responsavel por cadrastar os usu�rios no sistema
{
	// inicio da cria��o da variavel/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o da variavel/string
	
	printf("digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy( arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadrstado: "); // colentando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadrastado: "); // coletando informa��o do usu�rio
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadrstrado: "); // coletando informa��o do usu�rio
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consuta()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	 // inicio da cria��o da variavel/string
 	 char cpf[40];
 	 char conteudo[200];
 	 // final da cria��o da variavel /string
 	 
 	 printf("digite o CPF a ser consultado: "); // coletando informa��es do usu�rio
 	 scanf("%s", cpf); // %s refere-se a string
 	 
 	 FILE *file; // cria o arquivo
 	 file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler 
 	 
 	 if(file ==NULL)
 	 {
 	 	printf("n�o foi possivel abrir o arquivo, n�o localizamos!.\n");
	 }
	 
	 while(fgets(conteudo, 200,file) != NULL)
	 {
	 	printf("\nEssas s�o as informa��es do usuario: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
 	 
 	 system("pause");
}

int deletar()
{
	// inicio da cria�a� da variavel/string
	 char cpf[40];
	 // final da cria�a� da variavel/string
	 
	 printf("digite o CPF do usu�rio a ser deletado: "); // coletando informa��o do usu�rio
	 scanf("%s", cpf); // %s refere-se a string
	 
	 remove(cpf);
	 
	 FILE *file; // cria o arquivo
	 file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler
	 
	 if(file == NULL)
	 {
	 	printf("O usu�rio n�o se encontra no sistema!.\n");
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
      printf("escolha a op��o desejada do menu:\n\n");
      printf("\t1 - registrar nomes\n");
      printf("\t2 - consutar nomes\n");
      printf("\t3 - deletar nomes\n\n");
      printf("\t4 - sair do sistema\n\n");
  	  printf("op��o: "); // fim do menu

      scanf("%d", &opcao); // armazenamento a escolha do usuario
	       
      system("cls"); // responsavel por limpar a tela
      
      switch(opcao) // inicio da sele��o do menu
      {
      	 case 1: // chamada de fun��es
      	 regristro(); 
      	 break;
	     
         case 2: // chamada de fun��es
         consuta();
         break;
     
         case 3: // chamada de fun��es
         deletar();
         break;
         
         case 4:
         printf("obrigado por ultiliza o sistema!");
         return 0;
         break;
     
         default:
         printf("essa op��o n�o est� disponivel!\n");
         system("pause");
         break;
	    }
   } 
}
   
   

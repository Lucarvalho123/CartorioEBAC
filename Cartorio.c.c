#include <stdio.h>//biblioteca de comunica��o com  o usuario
#include <stdlib.h>//biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca responsavel por cuidar das string

int registro ()//Fun��o responsavel por cadastrar os usuarios no sistema
{
	//Inicio de cria��o das variaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final de cria��o das variaveis/string
   
   printf("Digite o cpf a ser cadastrado: ");//Coletando a inform��o do usuario
   scanf("%s", cpf);//%s se refere a string
   
   strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
   
   FILE *file;//Cria oarquivo
   file = fopen(arquivo,"w");//Cria o arquivo e o "w" significa escrever
   fprintf(file,cpf);//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,",");//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   printf("Digite o nome a ser cadastrado: ");//Coletando a informa��o do usuario
   scanf("%s", nome);//%s se refere a string
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file, nome);//Salva o valor da variavel
   fclose(file);//Fecha o arquivo
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,",");//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   printf("Digite o sobrenome a ser cadastrado: ");//Coletando a informa��o do usuario
   scanf("%s",sobrenome);//%s se refere a string
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file, sobrenome);//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,",");//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   printf("Digite o cargo a ser cadastrado: ");//Coletando a informa��o do usuario
   scanf("%s", cargo);//%s se refere a string
   
   file = fopen(arquivo, "a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,cargo);//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   system("pause");//Responsavel por pausar a tela
   
}

int consulta ()//Fun��o responsavel por consultar os usuarios no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
	
	//Inicio de cria��o das variaveis/string
	char cpf[40];
	char conteudo[200];
	//Fim de cria��o das variaveis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando a inform��o do usuario
	scanf("%s" ,cpf);//%s se refere a string
	
	FILE *file;//Cria oarquivo
	file = fopen(cpf,"r");//Cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");//Responsavel por pausar a tela
	
}

int deletar ()//Fun��o responsavel por deletar os usuarios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");//Coletando a inform��o do usuario
	scanf("%,s",cpf);//%s se refere a string
	
	remove(cpf);
	
	FILE *file;//Cria oarquivo
	file = fopen(cpf,"r");//Cria o arquivo e o "r" significa ler
	
	if(file == NULL)
    {
	printf("O ususario n�o se encontra no sistema.\n ");
	system("pause");//Responsavel por pausar a tela
	
	}	
}

int main()

{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");//Responsavel por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
	   
	   printf("###Cart�rio da EBAC###\n\n"); //inicio do menu
       printf("Escolha a op��o desejada no menu:\n\n"); 
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sistema\n\n\n");
	   printf("Op��o:");//fim do menu
	   
	   scanf("%d",&opcao); //Armazenando a escolha do usuario
	   
	   system("cls");//Responsavel por limpar a tela
	   
	   switch(opcao)//Inicio da sele��o do menu
	   {
	   	case 1:
	   		registro();//chamada de fun��es
		break;
		
		case 2:
			consulta();
		break;
		
		case 3:
			deletar();
		break;
		
		case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
		break;
		
		default:
			printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		break;
	   }//Fim da sele��o do menu

	}
}

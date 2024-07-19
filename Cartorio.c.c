#include <stdio.h>//biblioteca de comunicação com  o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsavel por cuidar das string

int registro ()//Função responsavel por cadastrar os usuarios no sistema
{
	//Inicio de criação das variaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final de criação das variaveis/string
   
   printf("Digite o cpf a ser cadastrado: ");//Coletando a informção do usuario
   scanf("%s", cpf);//%s se refere a string
   
   strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
   
   FILE *file;//Cria oarquivo
   file = fopen(arquivo,"w");//Cria o arquivo e o "w" significa escrever
   fprintf(file,cpf);//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,",");//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   printf("Digite o nome a ser cadastrado: ");//Coletando a informação do usuario
   scanf("%s", nome);//%s se refere a string
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file, nome);//Salva o valor da variavel
   fclose(file);//Fecha o arquivo
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,",");//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   printf("Digite o sobrenome a ser cadastrado: ");//Coletando a informação do usuario
   scanf("%s",sobrenome);//%s se refere a string
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file, sobrenome);//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   file = fopen(arquivo,"a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,",");//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   printf("Digite o cargo a ser cadastrado: ");//Coletando a informação do usuario
   scanf("%s", cargo);//%s se refere a string
   
   file = fopen(arquivo, "a");//Cria o arquivo e o "a" significa arquivo
   fprintf(file,cargo);//Salva o valor da variavel
   fclose(file);//fecha o arquivo
   
   system("pause");//Responsavel por pausar a tela
   
}

int consulta ()//Função responsavel por consultar os usuarios no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
	
	//Inicio de criação das variaveis/string
	char cpf[40];
	char conteudo[200];
	//Fim de criação das variaveis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando a informção do usuario
	scanf("%s" ,cpf);//%s se refere a string
	
	FILE *file;//Cria oarquivo
	file = fopen(cpf,"r");//Cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");//Responsavel por pausar a tela
	
}

int deletar ()//Função responsavel por deletar os usuarios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");//Coletando a informção do usuario
	scanf("%,s",cpf);//%s se refere a string
	
	remove(cpf);
	
	FILE *file;//Cria oarquivo
	file = fopen(cpf,"r");//Cria o arquivo e o "r" significa ler
	
	if(file == NULL)
    {
	printf("O ususario não se encontra no sistema.\n ");
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
	   
	   printf("###Cartório da EBAC###\n\n"); //inicio do menu
       printf("Escolha a opção desejada no menu:\n\n"); 
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sistema\n\n\n");
	   printf("Opção:");//fim do menu
	   
	   scanf("%d",&opcao); //Armazenando a escolha do usuario
	   
	   system("cls");//Responsavel por limpar a tela
	   
	   switch(opcao)//Inicio da seleção do menu
	   {
	   	case 1:
	   		registro();//chamada de funções
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
			printf("Essa opção não está disponivel!\n");
		    system("pause");
		break;
	   }//Fim da seleção do menu

	}
}

#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar o usu�rio no sistema
{
	
	//�nicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");  //Coleta de informa��o do usu�rio
	scanf("%s", cpf); // Valida a vari�vel CPF / %S refere-se a string usado toda vez que for salvar uma string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE*file; // Cria o arquivo no PC 
	file = fopen(arquivo,  "w"); // Cria o arquivo no PC e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); // Aqui fecho o arquivo 
	
	file = fopen(arquivo, "a"); // Abre o arquivo e o "a" se refere ao arquivo
	fprintf(file, ","); // Atualiza o arquivo
	fclose(file); // Fecha o comando 
	
	printf("Digite o nome a ser cadastrado: ");  
	scanf("%s", &nome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, sobrenome); 
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", &cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); 
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ".");
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	fclose(file);
	system("pause");
	

	
}

int deletar()
{

	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
	fclose(file);
	system("pause");
	
}

int sair ()
{	
	printf("Voc� escolheu a op��o sair do sistema.\n");
	system("pause");
}
 


int main() 
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo la�o
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cat�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		
		for(laco=1;laco=1;)
		{
	
	
			setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
			printf( "### Cart�rio da EBAC ###\n\n"); // Inicio do menu

			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d",&opcao); // armazenando a escolha do usu�rio
	
			system("cls"); //respons�vel por limpar a tela
	
			switch(opcao) //inicio da sele��o.
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta(); 
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				sair();
				break;
		
				default: 
				printf("Essa op��o n�o est� dispon�vel, tente novamente.\n\n"); 
				system("pause");
			}	break;
				
		}  
	}
	
		
	else 
	printf("Senha incorreta, digite novamete uma seha valida!");
}



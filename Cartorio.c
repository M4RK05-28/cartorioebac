#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de oloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de oloca��o de texte por regi�o
#include <string.h> // biblioteeca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	// inic�o cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final cria��o de vari�veis/string
	
	printf("digite o cpf a ser cadastrado: "); // coloetando as informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se as string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informa��o
	fprintf(file,","); // salvar informa��o dentro do arquivo e a "," salvar a atualiza��o
	fclose(file), // fechar o arquivo
	
	printf("Digite o nome a ser cadastrado:"); // coloetando as informa��es do usu�rio
	scanf("%s",nome); // %s refere-se as string
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informa��o
	fprintf(file,nome); // salva o conte�do da vari�vel nome dentro do arquivo
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informa��o
	fprintf(file,","); // salvar informa��o dentro do arquivo e a "," salvar a atualiza��o
	fclose(file), // fechar o arquivo
	
	printf("digite o sobrenome a ser cadastrado"); // coloetando as informa��es do usu�rio
	scanf("%s", sobrenome); // %s refere-se as string
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informa��o
	fprintf(file,sobrenome); // salva o conte�do da vari�vel sobrenome dentro do arquivo
	fclose(file); // fechar o aquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informa��o
	fprintf(file,","); // salvar informa��o dentro do arquivo e a "," salvar a atualiza��o
	fclose(file), // fechar o arquivo
	
	printf("digite o cargo a ser cadastrado: "); // coloetando as informa��es do usu�rio
	scanf("%s",cargo); // %s refere-se as string
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informa��o
	fprintf(file,cargo); // salva o conte�do da vari�vel cargo dentro do arquivo
	fclose(file); // fechar o arquivo
	
	system("pause");	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("nessas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}



int deletar()
{
	char cpf[40];
	
	printf("digite o CPF do usu�rio a ser deletado; ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
 {
	int opcao=0;   //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");	
	  setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
	  printf("###Cart�rio da EBAC###\n\n");  // inicio do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("op��o:");   // fim do menu
	
	  scanf("%d",&opcao);  // armazenando a escolha do usu�rio

      system("cls");// responsavel por limpar a tela
    
    
      switch(opcao) // inicio da sele��o do menu
      {
      	case 1:
      	registro(); //chamada de fun��es de registro
    	break;
    	
    	case 2:
    	consulta(); //chamada de fun��es de consulta
		break;
		
		case 3:
		deletar(); //chamada de fun��es de deletar
    	break;
    
	    	
    	default:
    	printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
    	
    	
	  }// fim da sele��o
    

   }    	
 }

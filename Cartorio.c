#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de olocação de espaço em memória
#include <locale.h> // biblioteca de olocação de texte por região
#include <string.h> // biblioteeca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	// inicío criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final criação de variáveis/string
	
	printf("digite o cpf a ser cadastrado: "); // coloetando as informações do usuário
	scanf("%s", cpf); // %s refere-se as string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informação
	fprintf(file,","); // salvar informação dentro do arquivo e a "," salvar a atualização
	fclose(file), // fechar o arquivo
	
	printf("Digite o nome a ser cadastrado:"); // coloetando as informações do usuário
	scanf("%s",nome); // %s refere-se as string
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informação
	fprintf(file,nome); // salva o conteúdo da variável nome dentro do arquivo
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informação
	fprintf(file,","); // salvar informação dentro do arquivo e a "," salvar a atualização
	fclose(file), // fechar o arquivo
	
	printf("digite o sobrenome a ser cadastrado"); // coloetando as informações do usuário
	scanf("%s", sobrenome); // %s refere-se as string
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informação
	fprintf(file,sobrenome); // salva o conteúdo da variável sobrenome dentro do arquivo
	fclose(file); // fechar o aquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informação
	fprintf(file,","); // salvar informação dentro do arquivo e a "," salvar a atualização
	fclose(file), // fechar o arquivo
	
	printf("digite o cargo a ser cadastrado: "); // coloetando as informações do usuário
	scanf("%s",cargo); // %s refere-se as string
	
	file = fopen(arquivo, "a"); // abrir o arquivo salvo e o "a" atualizar informação
	fprintf(file,cargo); // salva o conteúdo da variável cargo dentro do arquivo
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
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("nessas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}



int deletar()
{
	char cpf[40];
	
	printf("digite o CPF do usuário a ser deletado; ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
 {
	int opcao=0;   //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");	
	  setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
	  printf("###Cartório da EBAC###\n\n");  // inicio do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("opção:");   // fim do menu
	
	  scanf("%d",&opcao);  // armazenando a escolha do usuário

      system("cls");// responsavel por limpar a tela
    
    
      switch(opcao) // inicio da seleção do menu
      {
      	case 1:
      	registro(); //chamada de funções de registro
    	break;
    	
    	case 2:
    	consulta(); //chamada de funções de consulta
		break;
		
		case 3:
		deletar(); //chamada de funções de deletar
    	break;
    
	    	
    	default:
    	printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
    	
    	
	  }// fim da seleção
    

   }    	
 }

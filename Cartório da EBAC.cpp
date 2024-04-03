#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int Registrar ()
{
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char arquivo [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}

int Consultar ()
{
	char cpf[40];
	char consulta[200];
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(cpf != NULL)
	{
		while(fgets(consulta,200,file) !=NULL)
		{	
			printf("Estes são os dados encontrados: ");
			printf("\n\n");
			printf("%s", consulta);
		
		}
	}
	else
	{
		printf("Este CPF não consta no banco de dados");
		
	}
	
	system("pause");
	
	
	fclose(file);
}

int Deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	if(cpf != NULL)
	{
		remove(cpf);
	}
	else
	{
		printf("Este CPF não consta no banco de dados"); 
	}
	system("pause");
}

int main()
{
	int laco =1;
	int opcao =0;
	
	setlocale(LC_ALL, "portuguese");
	
	for(laco==1;laco==1;)
	{
		system("cls");
		
		printf("###CARTÓRIO DA EBAC###\n\n");
		printf("\t1 - Registrar usuário\n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Deletar usuário\n\n");
		printf("Opção: ");
		
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{
			case 1: Registrar();
			break;
			
			case 2: Consultar();
			break;
			
			case 3: Deletar();
			break;
			
		}
		
	}
}

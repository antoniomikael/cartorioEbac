#include <stdio.h> //blibioteca de comunicação com o usuário
#include <stdlib.h> // blibioteca de alocação de memoria
#include <locale.h> // blibioteca de texto por regeião
#include <string.h> //biblioteca responsavel por cuidar da string


int registro(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40] = "CPF: ";
	char nome[40] = "Nome: ";
	char sobrenome[40] = "Sobrenome: ";
	char cargo[40] = "Cargo: ";
	
	printf("Digite seu CPF a ser cadastrado: ");
	scanf("%s", cpf); //salvando o que tive na variavel string
	
	strcpy(arquivo, cpf); //responsavel por copiar as string
	
	FILE *file; //criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo
	fprintf(file,cpf);
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome + 6);
	
	
	file = fopen(arquivo, "a"); // abrindo arquivo 
	fprintf(file, nome); //add nome no arquivo
	fclose(file);
	
	file =fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome + 11);
	
	file = fopen(arquivo, "a"); // abrindo arquivo 
	fprintf(file,sobrenome); //add nome no arquivo
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo + 7);
	
	file = fopen(arquivo, "a"); // abrindo arquivo 
	fprintf(file,cargo); //add nome no arquivo
	fclose(file);
	system("pause");
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[300];
	
	printf("Digite o CPF a ser consultado \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("usuario não localizado.\n");
	
	}
	
	if(file != NULL){
		printf("\nEssas são as informações do usuário: ");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{		
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar(){

	char cpf[40];
	printf("Digite o cpf a ser deletado:");
	
	scanf("%s", cpf);
	
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("usuario não existe\n");
		system("pause");
	}

	else{
		remove(cpf);
		printf("usuario deletado! \n");
		system("pause");
	}	
}


int main(){
	
	int opcao=0;
	int x=1;	
	for(x=1; x=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf(" ### Cartorio da Ebac ### \n\n");
		printf("\t Escolha uma opção do menu\n\n");\
		printf("\t\t1 - Registrar nomes\n\n");
		printf("\t\t2 - Consultar nomes\n\n");
		printf("\t\t3 - Deletar nomes\n\n\n");
	
	
		scanf("%d", &opcao); //armazenando a escolha do úsuario
	
		system("cls");
	
		switch(opcao){
			case 1:
			registro();
	 		break;
	 		
	 		case 2:
	 		consulta();
	 		break;
	 		
	 		case 3:
	 		deletar();
	 		break;
	 		
	 		default:
	 		printf("essa opção não esta disponivel\n");
	 		system("pause");
	 		break;
		}	 	
		  
	}
} 

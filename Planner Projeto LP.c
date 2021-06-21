/* Nome: Gabriela de Faria Sígolo */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <conio.c>
#define TAM 10


// Definição das structs que o programa utilizará

typedef struct Eventos
	{
		char NomeEvent[30];
		char Desc[30];
		char DataEvent[20]; 
		char HoraEvento[6];
	} agendamento; 
	
	agendamento agenda[TAM];
	
typedef struct {
	
	int Codigo;
	char Nome[30];		
	char Descricao[30];
	char Hora[10];
			
} EventoManha;	
	
EventoManha Manha[TAM];

typedef struct {
	
	int Codigo;	
	char Nome[30];		
	char Descricao[30];
	char Hora[10];
			
} EventoTarde;	
	
EventoTarde Tarde[TAM];

typedef struct {
	
	int Codigo;	
	char Nome[30];		
	char Descricao[30];
	char Hora[10];
			
} EventoNoite;	
	
EventoNoite Noite[TAM];


// Definição das funções

void criarEvento();
void criarRotina();
void menu();
void delay();

// Definição de variaveis Globais

int i;

// Função inicial

int main(){
	
	menu();
	
	return 0;
}

void menu(){
	
	setlocale(LC_ALL,"Portuguese");
	int resposta;
	
	
	textcolor ( LIGHTRED );
    gotoxy ( 35 , 5 );
    printf ( "PLANNER" );
	textcolor ( LIGHTBLUE );
    gotoxy ( 29 , 6 );
    printf ( "  SEJA BEM VINDO! " );
    textcolor ( LIGHTCYAN );
    gotoxy ( 29 , 7 );
    printf ( "1 - Criar Rotina diaria");
    gotoxy ( 29 , 8 );
    printf ( "2 - Criar Evento");
	gotoxy ( 29 , 9 );   
    printf ( "3 - Sair do Sistema");
 	gotoxy( 29, 10 );
    printf ( "Escolha uma opção: ");    
    scanf("%d", &resposta);
         
    switch(resposta){
    	case 1:
    		
    		system("cls");
    		
    		criarRotina();
    		
    		
    	break;
    	
    	case 2:
    		
    		system("cls");
    		
    		criarEvento();
    		
    	break;
    	
    	case 3:
    		
    		system("cls");
    		
    		printf("Fim do Programa!!!");
    		
    		printf ( "\n\n" );
    		
    		system("pause");
    		
    		exit(0);  		
    		
    	break;
    		
	}
	
}

void criarRotina(){
	
	char nome[30];
	int i, resposta, decisao, qdt=1;
	textcolor(LIGHTRED);		
	printf ( "    Criar Rotina    ");
	
	printf("\n\n");
	textcolor(LIGHTBLUE);
	printf("ADS Bot: Bem vindo!!!\n");
	
	delay(2);
	
	printf("ADS Bot: Olá meu nome é ADS Bot e estou aqui para lhe ajudar fazer sua rotina diária.\n");
	
	delay(2);
	
	printf("ADS Bot: Para iniciarmos preciso saber qual é seu nome? ");
	fflush(stdin);
	fgets(nome, 30, stdin);
	
	delay(2);
	
	printf("ADS Bot: É um prazer te conhecer %s %c \n\n", nome, 2);
	
	delay(2);
			
	do{		
			printf("\nADS Bot: Periodo da Manhã");
				
			printf("\n\n");
				
			printf("ID: %d ", qdt);
				
			Manha[qdt].Codigo = qdt;				
				
			printf("\nADS Bot: Digite um nome para essa rotina: ");
			fflush(stdin);
			fgets(Manha[qdt].Nome, 30, stdin);		
				
			printf("ADS Bot: Descreva de forma resumida essa rotina(max de 50 caracteres): ");
			fflush(stdin);
			fgets(Manha[qdt].Descricao, 50, stdin);
					
			printf("ADS Bot: Informe o horario da rotina:");
			fflush(stdin);
			fgets(Manha[qdt].Hora, 10, stdin);		
				
			printf("\n\n");
				
			printf("ADS Bot: Periodo da Tarde\n\n");		
				
			printf("ID: %d ", qdt);
				
			Tarde[qdt].Codigo = qdt;		
				
			printf("\nADS Bot: Digite um nome para essa rotina: ");
			fflush(stdin);
			fgets(Tarde[qdt].Nome, 30, stdin);	
				
			printf("ADS Bot: Descreva de forma resumida essa rotina(max de 50 caracteres): ");
			fflush(stdin);
			fgets(Tarde[qdt].Descricao, 30, stdin);					
				
			printf("ADS Bot: Informe o horario da rotina:");
			fflush(stdin);
			fgets(Tarde[qdt].Hora, 30, stdin);						
				
			printf("\n\n");
				
			printf("ADS Bot: Periodo da Noite\n\n");		
				
			printf("ID: %d ", qdt);
				
			Noite[qdt].Codigo = qdt;		
				
			printf("\nADS Bot: Digite um nome para essa rotina: ");				
			fflush(stdin);
			fgets(Noite[qdt].Nome, 30, stdin);
							
			printf("ADS Bot: Descreva de forma resumida essa rotina(max de 50 caracteres): ");
			fflush(stdin);
			fgets(Noite[qdt].Descricao, 30, stdin);			
				
			printf("ADS Bot: Informe o horario da rotina:");
			fflush(stdin);
			fgets(Noite[qdt].Hora, 30, stdin);			
				
			printf("\n\n");	
			
			textcolor(LIGHTRED);
			printf("ADS Bot: Deseja salvar sua rotina? ");
			printf("\n[1] Salvar \n[2] Cancelar\n");
			scanf("%d", &decisao);
				
			if ( decisao == 1 ){
				FILE *arq = fopen("Rotinas.txt", "a");
						
				if(arq){
					fprintf(arq, "ROTINA DIÁRIA\n\n");
					fprintf(arq, "Período da Manha\n\n");
						
					fprintf(arq, "ID: %i\n", Manha[qdt].Codigo);
					fprintf(arq, "Nome da rotina: %s", Manha[qdt].Nome);
					fprintf(arq, "Descricao: %s", Manha[qdt].Descricao);
					fprintf(arq, "Hora: %s", Manha[qdt].Hora);
						
					fprintf(arq, "\nPeríodo da Tarde\n\n");						
						
					fprintf(arq, "ID: %i\n", Tarde[qdt].Codigo);
					fprintf(arq, "Nome da rotina: %s", Tarde[qdt].Nome);
					fprintf(arq, "Descricao: %s", Tarde[qdt].Descricao);
					fprintf(arq, "Hora: %s", Tarde[qdt].Hora);
						
					fprintf(arq, "\nPeríodo da Noite\n\n");						
						
					fprintf(arq, "ID: %i\n", Noite[qdt].Codigo);
					fprintf(arq, "Nome da rotina: %s", Noite[qdt].Nome);
					fprintf(arq, "Descricao: %s", Noite[qdt].Descricao);
					fprintf(arq, "Hora: %s", Noite[qdt].Hora);
						
				
					fclose(arq);	
						
					printf("Rotina salva com Sucesso!");					
			
				}
		
				else{
						
					printf("ERRO: não foi possivel abrir o arquivo.\n\n");
						
				}
			}
			
			qdt++;
			
			printf("\n\nADS Bot: Digite 1 para criar nova rotina ou 2 para voltar ao menu inicial ");
			scanf("%d", &decisao);
			
			system("cls");
			
		}while( decisao == 1 );
		
		system("cls");
		
		menu();	
		
	}
	

void criarEvento(){
	FILE *arquivo = NULL;
	int resp, respSalvar;
	
	do{
				
			printf ( "    Criar Evento    ");
	
			printf("\n\n");
			textcolor(LIGHTRED);
			printf("ADS Bot: Bem vindo!!!\n");
			
			delay(2);
			
			printf("ADS Bot: Olá meu nome é ADS Bot e estou aqui para lhe ajudar a criar seu evento.\n");
			
			delay(2);
			
			textcolor(LIGHTMAGENTA);
			printf("\n\nDigite um nome para o seu evento: ");
			fflush(stdin); gets(agenda[TAM].NomeEvent);
			printf("Descrição: ");
			fflush(stdin); gets(agenda[TAM].Desc);
			printf("Hora: ");
			fflush(stdin); gets(agenda[TAM].HoraEvento);
			printf("Data: ");
			fflush(stdin); gets(agenda[TAM].DataEvent);
			
			textcolor(LIGHTRED);
			printf("\n\nDeseja salvar?\n [1] - Salvar \n [2] - Cancelar ");
			textcolor(LIGHTBLUE);
			printf("\nRESPOSTA: ");
			scanf("%i", &respSalvar);
			
			if(respSalvar == 1){
				arquivo = fopen("Evento Planner.txt", "a");
			
			if(arquivo){
				fprintf(arquivo, "EVENTO: %s \nDESCRIÇÃO: %s \nHORA: %s \nDATA: %s \n", agenda[TAM].NomeEvent, agenda[TAM].Desc, agenda[TAM].HoraEvento, agenda[TAM].DataEvent); 
				fclose(arquivo);
				
				printf("\nEvento salvo com sucesso!\n");
				
				system("pause");
				system("cls");
			}else{
				printf("ERRO: não foi possivel abrir o arquivo.\n\n");
			}
			
			textcolor(LIGHTRED);	
			printf("Deseja criar outro evento ou voltar ao menu?");
			printf("\nEscolha uma das opções abaixo: ");
			textcolor(LIGHTBLUE);
			printf("\n[1] - Criar novo evento");
			printf("\n[2] - Voltar ao menu");
			printf("\nRESPOSTA: ");
			scanf("%i", &resp);
			}
			
			system("cls");
	}while(resp == 1);
	
	menu();
}

void delay( int a){
	
	int add;
	int time;
	int i;
	
	time = a * 100000000;
	
	for( i = 0; i < time; i++ ){
		add*=i;
		add++;
		add++;
	}
	
}




#include <stdio.h>
#include <ios>
//Definição das constantes para o número de linhas e colunas do hotel
#define LINHA 20
#define COLUNA 14

int i=0,j=0;
char hotel[20][14];

//Declaração das funções
int MenuHotel();
char RealizarCheckIN(char m[LINHA][COLUNA]);
int gerarhotel(int i,int j);
void verhotel(int i,int j);
void reservarapto(int i,int j);

int main(){
    MenuHotel();
    if(MenuHotel() == 1){
        RealizarCheckIN(hotel);
    }else if(MenuHotel() == 2){
        //Função RealizarCheckOUT
    }else if(MenuHotel() == 3){
        reservarapto(i,j);
    }else if(MenuHotel() == 4){ 
        //Função CancelarReserva
    }else if(MenuHotel() == 5){
        verhotel(i,j);
    }else if(MenuHotel() == 6){
        //Função Informações do hospede
    }else if(MenuHotel() == 7){
        //Função Taxa de ocupação e reservas do hotel
    }else if(MenuHotel() == 8){
        printf("Obrigado por usar o Hotel LIC! Volte sempre!\n");
    }else{
        printf("Opção inválida! Por favor, escolha uma opção válida.\n");
    }


    return 0;
}

//REQ03
char RealizarCheckIN(char m[LINHA][COLUNA]){
    int checkIN;
    printf("Digite o apartamento e o andar da reserva para realizar o check-in: \n");
    scanf("%d %d", &checkIN, &checkIN);
    if (checkIN == 'O'){
        printf("Erro! Apartamento Ocupado!\n");

    }else{
        printf("Check-in realizado com sucesso!\n");
        return 'O'; // 'O' para Ocupado
    }
    
}
//Menu do Hotel
int MenuHotel(){
    int escolha;
    printf("==========================\n");
    printf("  Bem-vindo ao Hotel LIC! \n");
    printf("==========================\n");
    printf("[1]. Realizar Check-in\n");
    printf("[2]. Realizar Check-out\n");
    printf("[3]. Reservar Apartamento\n"); //Função Reservarapto
    printf("[4]. Cancelar Reserva\n");
    printf("[5]. Mapa de ocuopação do hotel\n"); //Função Verhotel
    printf("[6]. Informações do hospede\n");
    printf("[7]. Taxa de ocupação e reservas do hotel\n");
    printf("[8]. Sair\n");
    printf("==========================\n");
    printf("Escolha um número para acessar a opção : \n");
    scanf("%d", &escolha);
    return escolha;
}


//REQ01 - Gera o mapa do hotel
int gerarhotel(int i,int j)
{
	int countap=0;
	printf("aptos:  \t");
	for(j=1;j<=COLUNA;j++){
		printf("%2d ",j);
		if(j%COLUNA==0){
			printf("\n");
		}
	}
	printf("\n");
	for(i=20;i>=LINHA;i--){
		printf("andar: %2d\t",i);
		for(j=1;j<=COLUNA;j++){
			hotel[i][j]='.';
			printf(" %c ",hotel[i][j]);
			if(j%COLUNA==0){
				printf("\n");
			}
			countap++;
		}
	}
	printf("\n\n\n");
	return countap,hotel[20][14];
}

//REQ01 - Exibe o mapa do hotel
void verhotel(int i,int j)
{
	printf("aptos:  \t");
	for(j=1;j<=COLUNA;j++){
		printf("%2d ",j);
		if(j%COLUNA==0){
			printf("\n");
		}
	}
	printf("\n");
	for(i=20;i>=LINHA;i--){
		printf("andar: %2d\t",i);
		for(j=1;j<=COLUNA;j++){
			printf(" %c ",hotel[i][j]);
			if(j%COLUNA==0){
				printf("\n");
			}
		}
	}
}

//REQ02 - Realiza a reserva do apartamento
void reservarapto(int i,int j)
{
	int escolhendo=1;
	while(escolhendo!=0){
	printf("\n\nescolher andar: ");
	scanf("%d",&i);
	printf("\n\n");
	while(i>20||i<0){
		printf("\n\nescolher andar: ");
		scanf("%d",&i);
	}
	printf("\n\n");
	printf("escolher apartamento: ");
	scanf("%d",&j);
	printf("\n\n");
	while(j>14||j<0){
		printf("\n\nescolher apartamento: ");
		scanf("%d",&j);
	}
	printf("\n\n");
	hotel[i][j]='R';
	system("cls");
	printf("continuar?\n\n0-nao\noutro-sim\n\n");
	scanf("%d",&escolhendo);
	printf("\n\n");
	}
}
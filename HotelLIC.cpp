#include <stdio.h>
#include <ios>
//Definição das constantes para o número de linhas e colunas do hotel
#define LINHA 20
#define COLUNA 14

//Declaração das funções
int MenuHotel();
void RealizarCheckIN(char m[LINHA][COLUNA]);
void gerarhotel(char m[LINHA][COLUNA]);
void verhotel(char m[LINHA][COLUNA]);

int main(){
	char hotel[LINHA][COLUNA];

	gerarhotel(hotel);
	do{

	
    switch (MenuHotel()){
        case 1:
            RealizarCheckIN(hotel);
            break;
        case 2:
            //Função Check-out
            break;
        case 3:
            break;
        case 4:
            //Função Cancelar Reserva
            break;
        case 5:
            verhotel(hotel);
            break;
        case 6:
            //Função Informações do hospede
            break;
        case 7:
            //Função Taxa de ocupação e reservas do hotel
            break;
        case 8:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Por favor, escolha uma opção válida.\n");
    }
}while(MenuHotel() != 8);

    return 0;
}

//REQ03
void RealizarCheckIN(char m[LINHA][COLUNA]){
	int Apto, Andar;
    int checkIN;
    printf("Digite o apartamento e o andar da reserva para realizar o check-in: \n");
    scanf("%d %d", &Apto, &Andar);
	if (Andar < 1 || Andar > LINHA || Apto < 1 || Apto > COLUNA) {
        printf("Erro! O andar deve ser de 1 a %d e o apartamento de 1 a %d.\n", LINHA, COLUNA);
        return; // Sai da função imediatamente, voltando para o menu
    }
    if (m[Andar-1][Apto-1] == 'O'){
        printf("Erro! Apartamento Ocupado!\n");

    }else{
        printf("Check-in realizado com sucesso!\n");
        m[Andar-1][Apto-1] = 'O'; // 'O' para Ocupado
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
void gerarhotel(char m[LINHA][COLUNA]){
	for(int i = 0;i < LINHA;i++){
		for(int j =0 ;j < COLUNA;j++){
			m[i][j]='.';
		}
	}
}

//REQ01 - Exibe o mapa do hotel
void verhotel(char m[LINHA][COLUNA]){
    printf("\n=== MAPA DO HOTEL ===\n\n");
    // Mostra o cabeçalho dos apartamentos (1 a 20)
    printf("Apartamento:   ");
    for(int j = 1; j <= COLUNA; j++){
        printf("%2d ", j);
    }
    printf("\n-------------------------------------------------------------\n");

    // (Linha-1) pois queriamos imprimir o hotel de baixo para cima!
    for(int i = LINHA - 1; i >= 0; i--){
        // i + 1 serve para arrumar a numeração dos andares, já que o índice começa em 0 e não em 1.
        printf("Andar %2d |     ", i + 1); 
        for(int j = 0; j < COLUNA; j++){
            printf(" %c ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
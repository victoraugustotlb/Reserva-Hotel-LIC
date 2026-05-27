#include <stdio.h>
#define LINHA 20
#define COLUNA 14


void MenuHotel();
char RealizarCheckIN(char m[LINHA][COLUNA]);

int main(){
    MenuHotel();

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

void MenuHotel(){
    printf("==========================\n");
    printf("  Bem-vindo ao Hotel LIC! \n");
    printf("==========================\n");
    printf("[1]. Realizar Check-in\n");
    printf("[2]. Realizar Check-out\n");
    printf("[3]. Reservar Apartamento\n");
    printf("[4]. Cancelar Reserva\n");
    printf("[5]. Mapa de ocuopação do hotel\n");
    printf("[6]. Informações do hospede\n");
    printf("[7]. Taxa de ocupação e reservas do hotel\n");
    printf("[8]. Sair\n");
}
#include <stdio.h>

int main(){


    return 0;
}

//REQ03
char RealizarCheckIN(char m[20][14]){
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
    printf(". Bem-vindo ao Hotel LIC! \n");
    printf("==========================\n");
    printf("[1]. Realizar Check-in\n");
    printf("");
}
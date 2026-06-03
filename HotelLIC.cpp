#include <stdio.h>
#include <string.h>

//Definição das constantes para o número de linhas e colunas do hotel
#define LINHA 20
#define COLUNA 14
#define MAX_HOSPEDES 280 //20 andares x 14 apartamentos por andar

//Aqui é armazenado o cadastro de cada hóspede do hotel
struct hospede{
    char nome[50];
    char cpf[15];
    char telefone[20];
};

//Aqui estão declaradas as funções do programa, elas estão em ordem de uso para facilitar a leitura do código
int MenuHotel();
int RealizarCheckIN(char m[LINHA][COLUNA], struct hospede lista[], int qtd);
void fazerCheckout(char m[LINHA][COLUNA]);
void gerarhotel(char m[LINHA][COLUNA]);
void verhotel(char m[LINHA][COLUNA]);
void ReservarApto(char m[LINHA][COLUNA]);
void porcentagem(char m[LINHA][COLUNA]);
struct hospede Cadastro(struct hospede h);
void limparBuffer();
void cancelarReserva(char m[LINHA][COLUNA]);
struct hospede lista[MAX_HOSPEDES];
int quantidadeHospedes = 0; // Variável para controlar o número de hóspedes cadastrados

//Aqui se encontra a função principal do programa.
int main(){
    char hotel[LINHA][COLUNA]; // Matriz que representa o mapa do hotel
    int opcao;

    gerarhotel(hotel);
    do{
        opcao = MenuHotel();
    
    switch (opcao) {
        case 1:
            quantidadeHospedes = RealizarCheckIN(hotel, lista, quantidadeHospedes); // Atualiza a quantidade de hóspedes após o check-in
            break;
        case 2:
            fazerCheckout(hotel);
            break;
        case 3:
            ReservarApto(hotel);
            break;
        case 4:
            cancelarReserva(hotel);
            break;
        case 5:
            verhotel(hotel);
            break;
        case 6:
            printf("\n=== HÓSPEDES NO HOTEL ===\n");
                if (quantidadeHospedes == 0) {
                    printf("Nenhum hóspede cadastrado no momento.\n");
                } else {
                    for (int i = 0; i < quantidadeHospedes; i++) {
                        printf("%d. %s - CPF: %s - Telefone: %s\n", i + 1, lista[i].nome, lista[i].cpf, lista[i].telefone);
                    }
                }
                break;
            break;
        case 7:
            porcentagem(hotel);
            break;
        case 8:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Por favor, escolha uma opção válida.\n");
    }
}while(opcao != 8);

    return 0;
}

//REQ03
int RealizarCheckIN(char m[LINHA][COLUNA], struct hospede lista[], int qtd) {
    int Apto, Andar;
    printf("Digite o apartamento e o andar da reserva para realizar o check-in: \n");
    scanf("%d %d", &Apto, &Andar);
    
    if (Andar < 1 || Andar > LINHA || Apto < 1 || Apto > COLUNA) {
        printf("Erro! O andar deve ser de 1 a %d e o apartamento de 1 a %d.\n", LINHA, COLUNA);
        return qtd; //retorna a mesma quantidade
    }
    
    if (m[Andar-1][Apto-1] == 'O') { 
        printf("Erro! Apartamento Ocupado!\n");
        return qtd; //retorna a mesma quantidade
        
    } else if (m[Andar-1][Apto-1] == 'R') {
        lista[qtd] = Cadastro(lista[qtd]); 
        m[Andar-1][Apto-1] = 'O'; // Passa de Reservado para Ocupado
        printf("Check-in de reserva realizado com sucesso!\n");
        return qtd + 1; // Incrementa e retorna a nova quantidade
        
    } else {
        lista[qtd] = Cadastro(lista[qtd]); 
        m[Andar-1][Apto-1] = 'O'; // Passa de Livre para Ocupado
        printf("Check-in realizado com sucesso!\n");
        return qtd + 1; // Incrementa e retorna a nova quantidade
    }
}
//Menu do Hotel
int MenuHotel(){
    int escolha;
    printf("==========================\n");
    printf("  Bem-vindo ao Hotel LIC! \n");
    printf("==========================\n");
    printf("[1]. Realizar Check-in\n"); //Função RealizarCheckIN
    printf("[2]. Realizar Check-out\n"); //Função fazerCheckout
    printf("[3]. Reservar Apartamento\n"); //Função Reservarapto
    printf("[4]. Cancelar Reserva\n"); //Função cancelarReserva
    printf("[5]. Mapa de ocuopação do hotel\n"); //Função Verhotel
    printf("[6]. Informações do hospede\n"); //Função Cadastro
    printf("[7]. Taxa de ocupação e reservas do hotel\n"); //Função porcentagem
    printf("[8]. Sair\n"); 
    printf("==========================\n");
    printf("Escolha um número para acessar a opção : \n");
    scanf(" %d", &escolha);
    return escolha;
}


//REQ01 - Gera o mapa do hotel
void gerarhotel(char m[LINHA][COLUNA]){ //looping para preencher a matriz do hotel com '.'
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

    //Imprime o hotel de baixo para cima. 
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

void ReservarApto(char m[LINHA][COLUNA]){
    int Apto, Andar;
    printf("==== Reservar apartamento ====\n");
    printf("Escolha o apartamento e o andar para reservar: \n");
    scanf("%d %d", &Apto, &Andar);

    if (m[Andar-1][Apto-1] == 'R'){ // Verifica se o apartamento já está reservado, se estiver com R é porque está reservado
        printf("Erro! Apartamento já reservado!\n");
    } else if (m[Andar-1][Apto-1] == 'O') { // Verifica se o apartamento já está ocupado, se estiver com O é porque está ocupado
        printf("Erro! Apartamento já ocupado!\n");
    } else {
        printf("Apartamento reservado com sucesso!\n");
        m[Andar-1][Apto-1] = 'R'; // 'R' para Reservado
    }
}
//REQ06 - Cancelar reserva
void cancelarReserva(char m[LINHA][COLUNA]){
	int andar, apt;
	printf("=== Cancelar Reserva ===\n");
	printf("Insira respectivamente o andar e o apartamento(x y):\n");
	scanf("%d %d", &apt, &andar);

	if((andar > LINHA || andar < 1) || (apt > COLUNA || apt < 1)){ //Verifica se o andar e o apartamento existem, se não existirem, exibe a mensagem de erro
		printf("Erro: Apartamento/Andar inexistente\n");
		return;
	}
	else if(m[andar - 1][apt - 1] != 'R'){
		printf("Erro: Apartamento nao reservado\n");
		return;
	}
	else{
		m[andar - 1][apt - 1] = '.';
		printf("Reserva cancelada com sucesso\n");
		return;
	}
}
//REQ05 - Fazer checkout
void fazerCheckout(char m[LINHA][COLUNA]){
	int andar, apt;
	printf("=== Fazer Checkout ===\n");
	printf("Insira respectivamente o andar e o apartamento(x y):\n");
	scanf("%d %d", &apt, &andar);

	if((andar > LINHA || andar < 1) || (apt > COLUNA || apt < 1)){
		printf("Erro: Apartamento/Andar inexistente\n");
		return;
	}
	else if(m[andar - 1][apt - 1] != 'O'){
		printf("Erro: Apartamento nao ocupado\n");
		return;
	}
	else{
		m[andar - 1][apt - 1] = '.';
		printf("Checkout feito com sucesso\n");
		return;
	}
}
//REQ07 - Calcular a porcentagem de ocupação e reservas do hotel
void porcentagem(char m[LINHA][COLUNA]){
	float taxaO = 0;
	float taxaR = 0;
	for(int i = 0; i < LINHA; i++){ //Looping para percorrer a matriz do hotel e contar quantos apartamentos estão ocupados e quantos estão reservados
		for(int j = 0; j < COLUNA; j++){
			if(m[i][j] == 'O'){
				taxaO++;
			}
			else if(m[i][j] == 'R'){
				taxaR++;
			}
		}
	}
	taxaO = (taxaO / 280) * 100; //Calcula a porcentagem de ocupação
	taxaR = (taxaR / 280) * 100;//Calcula a porcentagem de reservas
	printf("=== Taxas ===\n");
	printf("Taxa de ocupacao: %.2f%%\n",taxaO);
	printf("Taxa de reservas: %.2f%%\n",taxaR);
	return;
}
//REQ08 - Cadastrar informações do hóspede
struct hospede Cadastro(struct hospede h){

    printf("=== Cadastro do Hóspede ===\n");
    printf("Digite o nome do hóspede: ");
    limparBuffer(); //Limpa o buffer do teclado  
    fgets(h.nome, sizeof(h.nome), stdin); //Lê o nome do hóspede, incluindo espaços, por isso o fgets
    printf("Digite o CPF do hóspede: ");
    scanf("%s", h.cpf);
    printf("Digite o telefone do hóspede: ");
    scanf("%s", h.telefone);

    return h;
}

//Essa função é utilizada para limpar o buffer do teclado, ela pode ser reutilizada quantas vezes forem necessárias no código.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

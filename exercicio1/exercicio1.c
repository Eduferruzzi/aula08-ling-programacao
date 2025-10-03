// EXERCÍCIO 1: SISTEMA DE CALCULADORA MODULAR

#include <stdio.h>

// Declararação das funções
void show_menu();
void get_option(int *option);
void get_numbers(float *n1, float *n2);
float sum(float n1, float n2);
float sub(float n1, float n2);
float mul(float n1, float n2);
float div(float n1, float n2);
void show_result(float result);

// Implementação das funções
// Função para mostrar o menu de opções
void show_menu(){
    printf("\n=== CALCULADORA ===\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
}

// Função para pegar a opção escolhida pelo usuário
void get_option(int *option){
    printf("Selecione uma opcao: ");
    scanf("%d", option);

    while (getchar() != '\n');
}

// Função para pegar os números escolhidos pelo usuário
void get_numbers(float *n1, float *n2){
    printf("Digite o primeiro numero: ");
    scanf("%f", n1);
    printf("Digite o segundo numero: ");
    scanf("%f", n2);
}

// Função que realiza a soma
float sum(float n1, float n2){
    return n1 + n2;
}

// Função que realiza a subtração
float sub(float n1, float n2){
    return n1 - n2;
}

// Função que realiza a multiplicação
float mul(float n1, float n2){
    return n1 * n2;
}

// Função que realiza a divisão
float div(float n1, float n2){
    // Valida o valor de n2 para não ocorrer divisão por zero
    if (n2 == 0){
        printf("Nao e possivel dividir por zero, o resultado sera 0\n");
        return 0;
    }
    return n1 / n2;
}

// Função que mostra o resultado
void show_result(float result){
    printf("Resultado: %.2f\n", result);
}

int main(){
    // Inicializa as variáveis usadas
    int option;
    float n1, n2, result;

    do {
        show_menu(); // Mostra o menu
        get_option(&option); // Pega a opção
 
        // Procede conforme a opção
        switch(option) {
            case 1: // Adição
                get_numbers(&n1, &n2);
                result = sum(n1, n2);
                show_result(result);
                break;
            case 2: // Subtração
                get_numbers(&n1, &n2);
                result = sub(n1, n2);
                show_result(result);
                break;
            case 3: // Multiplicação
                get_numbers(&n1, &n2);
                result = mul(n1, n2);
                show_result(result);
                break;
            case 4: // Divisão
                get_numbers(&n1, &n2);
                result = div(n1, n2);
                show_result(result);
                break;
            case 0: // Sai do ciclo
                printf("Saindo...");
                break;
            default: // Pede pro usuário repetir, caso não seja uma das opções válidas
                printf("Opcao invalida tente novamente\n");
        }
    } while (option);

    return 0;
}

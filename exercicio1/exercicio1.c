// EXERCÍCIO 1: SISTEMA DE CALCULADORA MODULAR

#include <stdio.h>

void show_menu();
void get_option(int *option);
void get_numbers(float *n1, float *n2);
float sum(float n1, float n2);
float sub(float n1, float n2);
float mul(float n1, float n2);
float div(float n1, float n2);
void show_result(float result);

void show_menu(){
    printf("\n=== CALCULADORA ===\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
}

void get_option(int *option){
    printf("Selecione uma opcao: ");
    scanf("%d", option);
}

void get_numbers(float *n1, float *n2){
    printf("Digite o primeiro numero: ");
    scanf("%f", n1);
    printf("Digite o segundo numero: ");
    scanf("%f", n2);
}

float sum(float n1, float n2){
    
    return n1 + n2;
}

float sub(float n1, float n2){
    return n1 - n2;
}

float mul(float n1, float n2){
    return n1 * n2;
}

float div(float n1, float n2){
    if (n2 == 0){
        printf("Nao e possivel dividir por zero, o resultado sera 0\n");
        return 0;
    }
    return n1 / n2;
}

void show_result(float result){
    printf("Resultado: %.2f\n", result);
}

int main(){
    int option;
    float n1, n2, result;

    do {
        show_menu();
        get_option(&option);
        switch(option) {
            case 1:
                get_numbers(&n1, &n2);
                result = sum(n1, n2);
                show_result(result);
                break;
            case 2:
                get_numbers(&n1, &n2);
                result = sub(n1, n2);
                show_result(result);
                break;
            case 3:
                get_numbers(&n1, &n2);
                result = mul(n1, n2);
                show_result(result);
                break;
            case 4:
                get_numbers(&n1, &n2);
                result = div(n1, n2);
                show_result(result);
                break;
            case 0:
                printf("Saindo...");
                break;
            default:
                printf("Opcao invalida tente novamente\n");
        }
    } while (option);

    return 0;
}

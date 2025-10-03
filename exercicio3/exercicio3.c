// EXERCÍCIO 3: MANIPULADOR DE STRINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Declararação das funções
void show_menu();
void get_option(int *option);
void read_string(char *string, int max_length);
int count_chars(char string[]);
void invert_string(char *string);
void to_uppercase(char *string);
void to_lowercase(char *string);
int count_words(char string[]);

// Implementação das funções
// Função para mostrar o menu de opções
void show_menu(){
    printf("\n=== MANIPULADOR DE STRINGS ===\n");
    printf("1. Contar caracteres\n");
    printf("2. Inverter string\n");
    printf("3. Converter maiuscula\n");
    printf("4. Converter minuscula\n");
    printf("5. Contar palavra\n");
    printf("0. Sair\n");
}

// Função para pegar a opção escolhida pelo usuário
void get_option(int *option){
    printf("Opcao: ");
    scanf("%d", option);

    while (getchar() != '\n');
}

// Função para pegar os números escolhidos pelo usuário
void read_string(char *string, int max_length){
    printf("Digite uma string: ");
    fgets(string, max_length, stdin);
    
    // Substitui a quebra de linha no final da string
    size_t length = strlen(string);
    if (length > 0 && string[length-1] == '\n') {
        string[length-1] = '\0';
    }
}

// Função para contar os caracteres
int count_chars(char string[]){
    int i = 0;
    while(string[i] != '\0') {
        i++;
    }
    return i;
}

// Função para inverter a string
void invert_string(char *string) {
    int lenght = strlen(string);
    char *init = string;
    char *end = string + (lenght - 1);
    char aux;
    for(int i = 0; i < lenght/2; i++) {
        aux = *(init + i);
        *(init + i) = *(end - i);
        *(end - i) = aux;
    }
}

// Função para converter os caracteres para maiúsculos
void to_uppercase(char *string){
    int i = 0;
    while(string[i] != '\0') {
        string[i] = toupper(string[i]);
        i++;
    }
}

// Função para converter os caracteres para minúsculos
void to_lowercase(char *string){
    int i = 0;
    while(string[i] != '\0') {
        string[i] = tolower(string[i]);
        i++;
    }
}

// Função para contar palavras
int count_words(char string[]){
    int words = 0;
    int inside_word = 0;
    while(*string != '\0') {
        if (isspace((unsigned char)*string)) {
            inside_word = 0;
        } else if (!inside_word) {
            inside_word = 1;
            words++;
        }
        string++;
    }
    return words;
}

int main(){
    // Inicializa as variáveis usadas
    int option, length = 100;
    char string[length];

    read_string(string, length); // Lê a string do usuário

    do {
        show_menu(); // Mostra o menu
        get_option(&option); // Pega a opção
 
        // Procede conforme a opção
        switch(option) {
            case 1: // Contar os caracteres
                printf("A string possui %d caracteres\n", count_chars(string));
                break;
            case 2: // Inverter string
                invert_string(string);
                printf("String invertida: %s\n", string);
                break;
            case 3: // Converter para maiúscula
                to_uppercase(string);
                printf("Maiuscula: %s\n", string);
                break;
            case 4: // Converter para minúscula
                to_lowercase(string);
                printf("Minuscula: %s\n", string);
                break;
            case 5: // Contar as palavras
                printf("A string possui %d palavras\n", count_words(string));
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

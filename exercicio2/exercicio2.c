// EXERCÍCIO 2: ANÁLISE DE ARRAY

#include <stdio.h>

// Declararação das funções
void fill_array(int *array, int size);
void show_array(const int array[], int size, int is_ordered);
int max(const int array[], int size);
int min(const int array[], int size);
float avg(const int array[], int size);
void order(int *array, int size, int *is_ordered);

// Implementação das funções
// Pega os inteiros do usuário
void fill_array(int *array, int size){
    printf("Digite %d numeros: \n", size);
    for (int i = 0; i < size; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", array+i);
    }
}

// Mostra o array
void show_array(const int array[], const int size, const int is_ordered){
    // Se não estiver ordenado fala que é o original
    if (!is_ordered) {
        printf("Array original: [");
    } else { // Caso o contrário fala que é o ordenado
        printf("Array ordenado: [");
    }
    // Faz o padrão "n, " até o penúltimo elemento
    for (int i = 0; i < size-1; i++) {
        printf("%d, ", array[i]);
    }
    // Fecha o array "n]"
    printf("%d]\n", array[size-1]);
}

// Função que retorna o maior elemento do array
int max(const int array[], int size){
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Função que retorna o menor elemento do array
int min(const int array[], int size){
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Função que retorna a média dos valores do array
float avg(const int array[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (float)sum/size;
}

// Função que ordena o array ordenado utilizando método bubblesort 
void order(int *array, int size, int *is_ordered){
    int aux;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }
    *is_ordered = 1;
}

int main(){
    // Inicializa as variáveis
    int array[10];
    int size = sizeof(array) / sizeof(array[0]); // Faz o tamanho do array em bytes dividido pelo tamanha de um elemento para achar o tamanho dele
    int is_ordered = 0;

    fill_array(array, size); // Preenche o array com o input
    show_array(array, size, is_ordered); // Mostra o array original

    printf("Maior valor: %d\n", max(array, size)); // Mostra o maior elemento
    printf("Menor valor: %d\n", min(array, size)); // Mostra o menor elemento
    printf("Media: %.2f\n", avg(array, size)); // Mostra a média

    order(array, size, &is_ordered); // Ordena o array
    show_array(array, size, is_ordered); // Mostra o array ordenado
    
    return 0;
}

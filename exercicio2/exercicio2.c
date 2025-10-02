// EXERCÍCIO 2: ANÁLISE DE ARRAY

#include <stdio.h>

void fill_array(int *array, int size);
void show_array(const int array[], const int size, const int is_ordered);
int max(int array[], int size);
int min(int array[], int size);
float avg(int array[], int size);
void order(int *array, int size, int *is_ordered);

void fill_array(int *array, int size){
    printf("Digite %d numeros: \n", size);
    for (int i = 0; i < size; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", array+i);
    }
}

void show_array(const int array[], const int size, const int is_ordered){
    if (!is_ordered) {
        printf("Array original: [");
    } else {
        printf("Array ordenado: [");
    }
    for (int i = 0; i < size-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size-1]);
}

int max(int array[], int size){
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int min(int array[], int size){
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

float avg(int array[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (float)sum/size;
}

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
    int array[10];
    int size = sizeof(array) / sizeof(array[0]);
    int is_ordered = 0;

    fill_array(array, size);
    show_array(array, size, is_ordered);

    printf("Maior valor: %d\n", max(array, size));
    printf("Menor valor: %d\n", min(array, size));
    printf("Media: %.2f\n", avg(array, size));

    order(array, size, &is_ordered);
    show_array(array, size, is_ordered);
    
    return 0;
}

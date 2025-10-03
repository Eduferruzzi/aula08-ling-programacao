// EXERCÍCIO 4: SISTEMA DE GESTÃO DE NOTAS

#include <stdio.h>

#define ALUNOS 5
#define DISCIPLINAS 4 

// Declararação das funções
void show_menu();
void get_option(int *option);
void inserir_notas(float notas[][DISCIPLINAS]); 
void exibir_notas(const float notas[][DISCIPLINAS]); 
float calcular_media_aluno(const float notas[][DISCIPLINAS], int aluno); 
float calcular_media_disciplina(const float notas[][DISCIPLINAS], int disciplina);
char* determinar_situacao(float media);
void exibir_relatorio_final(const float notas[][DISCIPLINAS]);

// Implementação das funções
// Função para mostrar o menu de opções
void show_menu(){
    printf("\n=== SISTEMA DE NOTAS ===\n");
    printf("1. Inserir notas\n");
    printf("2. Exibir notas\n");
    printf("3. Medias por aluno\n");
    printf("4. Medias por disciplina\n");
    printf("5. Exibir aprovados/reprovados\n");
    printf("0. Sair\n");
}

// Função para pegar a opção escolhida pelo usuário
void get_option(int *option){
    printf("Opcao: ");
    scanf("%d", option);

    while (getchar() != '\n');
}

// Função para inserir as notas na matriz
void inserir_notas(float notas[][DISCIPLINAS]){
    printf("Insira as notas dos alunos\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("\n=== ALUNO %d ===\n", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("Disciplina %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    printf("Notas registradas com sucesso\n");
}

// Função para exibir a matriz com as notas
void exibir_notas(const float notas[][DISCIPLINAS]){
    printf("\n=== NOTAS DOS ALUNOS ===\n");
    printf("        ");
    for (int j = 0; j < DISCIPLINAS; j++) {
        printf("Disc %d  ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ALUNOS; i++) {
        printf("Aluno %d  ", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("%.2f    ", notas[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular a média de um aluno
float calcular_media_aluno(const float notas[][DISCIPLINAS], int aluno) {
    float soma = 0.0;
    for (int j = 0; j < DISCIPLINAS; j++) {
        soma += notas[aluno][j];
    }
    return soma / DISCIPLINAS;
}

// Função para calcular a média de uma disciplina
float calcular_media_disciplina(const float notas[][DISCIPLINAS], int disciplina) {
    float soma = 0.0;
    for (int i = 0; i < ALUNOS; i++) {
        soma += notas[i][disciplina];
    }
    return soma / ALUNOS;
}

// Função para determinar se o aluno foi aprovado ou reprovado
char* determinar_situacao(float media) {
    return media >= 6.0 ? "APROVADO" : "REPROVADO";
}

// Função para exibir o relatório final de notas com a situação dos alunos
void exibir_relatorio_final(const float notas[][DISCIPLINAS]) {
    printf("\n=== RELATORIO FINAL ===\n");
    printf("Aluno | Media | Situacao\n");
    printf("===========================\n");

    for (int i = 0; i < ALUNOS; i++) {
        float media = calcular_media_aluno(notas, i);
        printf("  %d   | %.2f  | %s\n", i + 1, media, determinar_situacao(media));
    }
}

int main(){
    // Inicializa as variáveis usadas
    float notas[ALUNOS][DISCIPLINAS];
    int option;

    do {
        show_menu(); // Mostra o menu
        get_option(&option); // Pega a opção
 
        // Procede conforme a opção
        switch(option) {
            case 1: // Inserir as notas
                inserir_notas(notas);
                break;
            case 2: // Exibir as notas
                exibir_notas(notas);
                break;
            case 3: // Calcular média por aluno
                printf("=== MEDIAS POR ALUNO ===\n");
                for (int i = 0; i < ALUNOS; i++) {
                    printf("Aluno %d: %.2f\n", i + 1, calcular_media_aluno(notas, i));
                }
                break;
            case 4: // Calcular média por disciplina
                printf("=== MEDIAS POR DISCIPLINA ===\n");
                for (int j = 0; j < DISCIPLINAS; j++) {
                    printf("Disciplina %d: %.2f\n", j + 1, calcular_media_disciplina(notas, j));
                }
                break;
            case 5: // Exibir aprovados/reprovados
                exibir_relatorio_final(notas);
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

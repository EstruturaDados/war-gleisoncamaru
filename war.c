// Desafio novato: Cadastro de Territorios - Jogo WAR
// Objetivo: Criar um programa em C que permita o cadastro de territorios para o jogo WAR.
// O programa deve permitir o cadastro de no maximo 5 territorios, cada um com nome, cor do exército que o domina e quantidade de tropas.
// Ao atingir o limite, o programa deve exibir todos os territorios cadastrados.

#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TERRITORIO 5

// --- Definicao da struct ---
struct Territorio {
    char nome[30];
    char cor[10];
    int tropa;
};

// --- Limpar o buffer ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Cadastro dos territorios ---
void listarTerritorios(struct Territorio mapa[], int total) {
    int i;
    printf("\n===== TERRITORIOS CADASTRADOS =====\n");
    for (i = 0; i < total; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Dominado por: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropa);
    }
    printf("==================================\n");
}

// --- Funcao principal ---
int main() {
    struct Territorio mapa[MAX_TERRITORIO];
    int totalMapas = 0;

    printf("=== CADASTRO DE TERRITORIOS (WAR) ===\n");

    while (totalMapas < MAX_TERRITORIO) {

        printf("\nCadastro do territorio %d\n", totalMapas + 1);

        printf("Nome do territorio: ");
        fgets(mapa[totalMapas].nome, 30, stdin);
        mapa[totalMapas].nome[strcspn(mapa[totalMapas].nome, "\n")] = '\0';

        printf("Dominado por (cor): ");
        fgets(mapa[totalMapas].cor, 10, stdin);
        mapa[totalMapas].cor[strcspn(mapa[totalMapas].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[totalMapas].tropa);
        limparBufferEntrada();

        totalMapas++;
        printf("Territorio cadastrado com sucesso!\n");
    }
    // Ao terminar o cadastro, ira exibir todos os territorios
    printf("\nLimite maximo de territorios atingido!\n");
    listarTerritorios(mapa, totalMapas);
    // Para que o executavel nao feche imediatamente, aguarda um Enter
    printf("Pressione Enter para sair do programa...\n");
    limparBufferEntrada();
    getchar();
    return 0;
}
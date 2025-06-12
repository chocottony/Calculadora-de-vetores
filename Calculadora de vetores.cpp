// Projeto 01 - Geometria Vetorial

// Beatriz Souza - 202408800
// Antonio Garcia - 202408633
// Lonardo Camargo - 202510184

#include <stdio.h>
#include <locale.h>
#include <math.h>

// Função para somar vetores
void somar_vetores(float vetor1[], float vetor2[], int tamanho, float resultadoSoma[]) {
    for (int i = 0; i < tamanho; i++) {
        resultadoSoma[i] = vetor1[i] + vetor2[i];
    }
}

// Função para subtrair vetores
void subtrair_vetores(float vetor1[], float vetor2[], int tamanho, float resultadoSubtracao[]) {
    for (int i = 0; i < tamanho; i++) {
        resultadoSubtracao[i] = vetor1[i] - vetor2[i];
    }
}

// Função para multiplicar um vetor por um escalar
void multiplica_escalar_vetor(float vetor1[], float escalar, int tamanho, float resultadoMultEscalar[]) {
    for (int i = 0; i < tamanho; i++) {
        resultadoMultEscalar[i] = vetor1[i] * escalar;
    }
}

// Função para calcular a norma de um vetor
float norma(float v[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += v[i] * v[i];
    }
    return sqrt(soma);
}

// Função para calcular o produto escalar
float produto_escalar(float u[], float v[], int tamanho) {
    float produto = 0;
    for (int i = 0; i < tamanho; i++) {
        produto += u[i] * v[i];
    }
    return produto;
}

// Função para calcular o ângulo entre vetores
float angulo(float u[], float v[], int tu, int tv) {
    float angulorad = acos(produto_escalar(u, v, tu) / (norma(u, tu) * norma(v, tv)));
    return angulorad * (180 / M_PI);
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao, tamanho;
    float vetor1[100], vetor2[100], escalar, resultado[100];

    do {
        printf("\nG E O M E T R I A  V E T O R I A L\n");
        printf("1 - Soma de Vetores\n");
        printf("2 - Diferença de Vetores\n");
        printf("3 - Multiplicação de um Escalar por um vetor\n");
        printf("4 - Norma de um Vetor\n");
        printf("5 - Produto Escalar de vetores\n");
        printf("6 - Ângulo entre vetores\n");
        printf("0 - Finalizar\n");
        printf("Escolha a sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        printf("Informe o tamanho dos vetores: ");
        scanf("%d", &tamanho);

        printf("Digite o vetor 1:\n");
        for (int i = 0; i < tamanho; i++) {
            scanf("%f", &vetor1[i]);
        }

        if (opcao != 4) {
            printf("Digite o vetor 2:\n");
            for (int i = 0; i < tamanho; i++) {
                scanf("%f", &vetor2[i]);
            }
        }

        switch (opcao) {
            case 1:
                somar_vetores(vetor1, vetor2, tamanho, resultado);
                break;
            case 2:
                subtrair_vetores(vetor1, vetor2, tamanho, resultado);
                break;
            case 3:
                printf("Digite o escalar: ");
                scanf("%f", &escalar);
                multiplica_escalar_vetor(vetor1, escalar, tamanho, resultado);
                break;
            case 4:
                printf("Norma: %.2f\n", norma(vetor1, tamanho));
                continue;
            case 5:
                printf("Produto Escalar: %.2f\n", produto_escalar(vetor1, vetor2, tamanho));
                continue;
            case 6:
                printf("Ângulo: %.2f graus\n", angulo(vetor1, vetor2, tamanho, tamanho));
                continue;
            default:
                printf("Opção inválida!\n");
                continue;
        }

        printf("Resultado: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%.2f ", resultado[i]);
        }
        printf("\n");
    } while (opcao != 0);

    return 0;
}
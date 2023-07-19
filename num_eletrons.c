#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

double converterNotacaoCientifica(char *notacao) {
    char *ptr;
    double valor = strtod(notacao, &ptr);
    if (ptr[0] == ',' || ptr[0] == '.') {
        ptr++; // Avançar o ponteiro para ignorar a vírgula ou ponto decimal
        valor *= pow(10.0, -strlen(ptr)); // Ajustar a potência para tratar a vírgula decimal
    }
    return valor;
}

void imprimirResultado(double eletronsPorSegundo) {
    long long int trilhao = 1000000000000LL;
    long long int quatrilhao = 1000000000000000LL;
    long long int quintilhao = 1000000000000000000LL;

    if (eletronsPorSegundo >= quintilhao) {
        printf("O número de elétrons que flui pelo condutor por segundo é: %.2lf quintilhões\n", eletronsPorSegundo / quintilhao);
    } else if (eletronsPorSegundo >= quatrilhao) {
        printf("O número de elétrons que flui pelo condutor por segundo é: %.2lf quatrilhões\n", eletronsPorSegundo / quatrilhao);
    } else if (eletronsPorSegundo >= trilhao) {
        printf("O número de elétrons que flui pelo condutor por segundo é: %.2lf trilhões\n", eletronsPorSegundo / trilhao);
    } else {
        printf("O número de elétrons que flui pelo condutor por segundo é: %.2lf\n", eletronsPorSegundo);
    }
}

int main() {
    setlocale(LC_ALL, ""); // Configurar a localização para lidar com a vírgula decimal corretamente
    char correnteStr[100], tempoStr[100];
    double corrente, tempo, carga, eletronsPorSegundo;

    // Receber o valor da corrente elétrica e o tempo de fluxo digitados pelo usuário
    printf("Digite o valor da corrente elétrica (em A): ");
    fgets(correnteStr, sizeof(correnteStr), stdin);
    corrente = converterNotacaoCientifica(correnteStr);

    printf("Digite o tempo de fluxo (em s): ");
    fgets(tempoStr, sizeof(tempoStr), stdin);
    tempo = converterNotacaoCientifica(tempoStr);

    // Calcular a carga elétrica (em C)
    carga = corrente * tempo;

    // Converter a carga para a quantidade de elétrons
    double eletronsPorCoulomb = 6.25E19;
    double quantidadeEletrons = carga * eletronsPorCoulomb;

    // Calcular a quantidade de elétrons que flui pelo condutor por segundo
    eletronsPorSegundo = quantidadeEletrons / tempo;

    // Exibir os resultados
    printf("\nResultados:\n");
    imprimirResultado(eletronsPorSegundo);

    return 0;
}


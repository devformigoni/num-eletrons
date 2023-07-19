#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

double converterNotacaoCientifica(char *notacao) {
    char *ptr;
    double valor = strtod(notacao, &ptr);
    if (ptr[0] == ',' || ptr[0] == '.') {
        ptr++; // Avan�ar o ponteiro para ignorar a v�rgula ou ponto decimal
        valor *= pow(10.0, -strlen(ptr)); // Ajustar a pot�ncia para tratar a v�rgula decimal
    }
    return valor;
}

void imprimirResultado(double eletronsPorSegundo) {
    long long int trilhao = 1000000000000LL;
    long long int quatrilhao = 1000000000000000LL;
    long long int quintilhao = 1000000000000000000LL;

    if (eletronsPorSegundo >= quintilhao) {
        printf("O n�mero de el�trons que flui pelo condutor por segundo �: %.2lf quintilh�es\n", eletronsPorSegundo / quintilhao);
    } else if (eletronsPorSegundo >= quatrilhao) {
        printf("O n�mero de el�trons que flui pelo condutor por segundo �: %.2lf quatrilh�es\n", eletronsPorSegundo / quatrilhao);
    } else if (eletronsPorSegundo >= trilhao) {
        printf("O n�mero de el�trons que flui pelo condutor por segundo �: %.2lf trilh�es\n", eletronsPorSegundo / trilhao);
    } else {
        printf("O n�mero de el�trons que flui pelo condutor por segundo �: %.2lf\n", eletronsPorSegundo);
    }
}

int main() {
    setlocale(LC_ALL, ""); // Configurar a localiza��o para lidar com a v�rgula decimal corretamente
    char correnteStr[100], tempoStr[100];
    double corrente, tempo, carga, eletronsPorSegundo;

    // Receber o valor da corrente el�trica e o tempo de fluxo digitados pelo usu�rio
    printf("Digite o valor da corrente el�trica (em A): ");
    fgets(correnteStr, sizeof(correnteStr), stdin);
    corrente = converterNotacaoCientifica(correnteStr);

    printf("Digite o tempo de fluxo (em s): ");
    fgets(tempoStr, sizeof(tempoStr), stdin);
    tempo = converterNotacaoCientifica(tempoStr);

    // Calcular a carga el�trica (em C)
    carga = corrente * tempo;

    // Converter a carga para a quantidade de el�trons
    double eletronsPorCoulomb = 6.25E19;
    double quantidadeEletrons = carga * eletronsPorCoulomb;

    // Calcular a quantidade de el�trons que flui pelo condutor por segundo
    eletronsPorSegundo = quantidadeEletrons / tempo;

    // Exibir os resultados
    printf("\nResultados:\n");
    imprimirResultado(eletronsPorSegundo);

    return 0;
}


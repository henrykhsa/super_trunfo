#include <stdio.h>

//Definindo as propriedades das cartas
struct Carta {
    char estado;
    char codigo[5];  
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float PIBperCapita;
    float superpoder;
};

//Função que lê as informações inseridas das cartas
void lerCarta(struct Carta *carta, int numeroCarta) {
    printf("Insira os dados da carta %d:\n", numeroCarta);
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0';
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    printf("\n");
}

//Função que exibe as informações das cartas
void exibirCarta(struct Carta carta, int numeroCarta) {
    printf("Carta %d:\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f por km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.PIBperCapita);
    printf("\n");
}

//Função que calcula a densidade das cartas
void calcularDensidade(struct Carta *carta) {
    carta->densidadePopulacional = (float)carta->populacao / carta->area;
}

//Função que calcula o PIB per capita das cartas
void calcularPIBperCapita(struct Carta *carta) {
    carta->PIBperCapita = (carta->pib * 1e9) / carta->populacao;
}

//Função que calcula o superpoder das cartas
void calcularsuper (struct Carta *carta) {
    carta->superpoder = 
    (carta->populacao / 1000) + 
    (carta->pontosTuristicos * 10) + 
    (carta->area * 0.1) + 
    (carta->pib * 1e3) + 
    (carta->densidadePopulacional * 5) + 
    (carta->PIBperCapita * 0.001);
}

//Função que compara dois valores inteiros
int compararInt(int valor1, int valor2) {
    return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
}   
//Função que compara dois valores em float
int compararFloat(float valor1, float valor2) {
    return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
}

// Função para comparar dois valores em float, dando vitória ao menor
int compararFloatInverso(float valor1, float valor2) {
    return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0; 
}

//Função para definir os vencedores
void definirVencedores(struct Carta carta1, struct Carta carta2) {
    printf("Resultado das comparações:\n");
    printf("População: Carta %d venceu\n", compararInt(carta1.populacao, carta2.populacao));
    printf("Área: Carta %d venceu\n", compararFloat(carta1.area, carta2.area));
    printf("PIB: Carta %d venceu\n", compararFloat(carta1.pib, carta2.pib));
    printf("Pontos Turísticos: Carta %d venceu\n", compararInt(carta1.pontosTuristicos, carta2.pontosTuristicos));
    printf("Densidade Populacional: Carta %d venceu\n", compararFloatInverso(carta1.densidadePopulacional, carta2.densidadePopulacional));
    printf("PIB per Capita: Carta %d venceu\n", compararFloat(carta1.PIBperCapita, carta2.PIBperCapita));
    printf("Superpoder: Carta %d venceu\n", compararFloat(carta1.superpoder, carta2.superpoder));
}

//Função principal
int main() {
    struct Carta carta1, carta2;

    // Chama a função para ler os dados
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Chama a função para calcular a densidade populacional
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    // Chama a função para calcular o PIB
    calcularPIBperCapita(&carta1);
    calcularPIBperCapita(&carta2);
    
    // Chama a função para calcular o superpoder
    calcularsuper(&carta1);
    calcularsuper(&carta2);
    
    // Imprime o texto e chama a função para exibir as informações
    printf("Cartas cadastradas:\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    //compara entre as cartas qual valor é o vencedor
    definirVencedores(carta1, carta2);

    return 0;
}

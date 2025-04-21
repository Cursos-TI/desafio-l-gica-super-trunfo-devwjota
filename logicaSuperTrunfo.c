#include <stdio.h>
#include <locale.h>
#include <ctype.h>

// Função para verificar se o caractere é válido (aceita letras acentuadas, espaços e hífen)
int caractere_valido(char c)
{
    return ((unsigned char)c >= 128 || isalpha((unsigned char)c) || c == ' ' || c == '-');
}


int validar_nome(const char *nome)
{
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (!caractere_valido(nome[i]))
        {
            return 0;
        }
    }
    return 1;
}


// Armazenando os dados da Cidade
struct Cidade
{
    char nome[50];
    int populacao;
    double area;  
    double pib;   
};

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    struct Cidade cidade1, cidade2;

 
    printf("Digite o nome da primeira cidade: ");
    scanf(" %[^\n]", cidade1.nome);

    if (!validar_nome(cidade1.nome))
    {
        printf("Nome inválido! Use apenas letras, espaços e hífen.\n");
        return 1;
    }

    printf("Digite a população da primeira cidade (em milhares): ");
    scanf("%d", &cidade1.populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%lf", &cidade1.area);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%lf", &cidade1.pib);

    
    printf("\nDigite o nome da segunda cidade: ");
    scanf(" %[^\n]", cidade2.nome);

    if (!validar_nome(cidade2.nome))
    {
        printf("Nome inválido! Use apenas letras, espaços e hífen.\n");
        return 1;
    }

    printf("Digite a população da segunda cidade (em milhares): ");
    scanf("%d", &cidade2.populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%lf", &cidade2.area);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%lf", &cidade2.pib);

    // === Comparações ===
    printf("\n=== Resultado da comparação ===\n");

    if (cidade1.populacao > cidade2.populacao)
        printf("%s tem mais pessoas.\n", cidade1.nome);
    else if (cidade1.populacao < cidade2.populacao)
        printf("%s tem mais pessoas.\n", cidade2.nome);
    else
        printf("As duas cidades têm a mesma quantidade de pessoas.\n");

    if (cidade1.area > cidade2.area)
        printf("%s é maior em área.\n", cidade1.nome);
    else if (cidade1.area < cidade2.area)
        printf("%s é maior em área.\n", cidade2.nome);
    else
        printf("As duas cidades têm o mesmo tamanho.\n");

    if (cidade1.pib > cidade2.pib)
        printf("%s tem o maior PIB.\n", cidade1.nome);
    else if (cidade1.pib < cidade2.pib)
        printf("%s tem o maior PIB.\n", cidade2.nome);
    else
        printf("As duas cidades têm o mesmo PIB.\n");

    return 0;
}

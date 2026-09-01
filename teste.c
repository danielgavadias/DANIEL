#include <stdio.h> 

FILE *arquivopopinvmd nbg;

char nome[50];
int idade;
float altura;

int quantidade;
int i;

int totalAlunos = 0;
int opcaolimpar;

//======================================
//              CADASTRO
//======================================

printf("\n");
printf("\n");
printf("\n");

//======================================

//======================================

arquivo = fopen("arquivos/cadastros.txt", "a");

//"a" - adicionar
//"w" - sobrescrever
//"r" - ler

if (arquivo == NULL)
{
printf ("\nERrro ao abrir o arquivo!\n");
}

//======================================
//    LENDO TODOS OS ALUNOS
//======================================

fprintf(arquivo, "Nome: %s | Idade%d | altura: %2.f\n", nome, idade, altura);

printf("\n=============================");
printf("\n      ALUNOS CADASTRADOS     ");
printf("\n=============================");

while 
(
    fscanf(
        arquivo,
        "Nome: %49s | Idade: %d | Altura: %f",
        nome,
        &idade,
        &altura,
    ) == 3
) 
{
    totalAlunos++;

    printf("\nAluno %d\n", totalAlunos);

    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f m\n", altura);
}

//======================================
//    LIMPANDO O ARQUIVO DE LEITURA
//======================================
 
int opcaoLimpar;

if (opcaoLimpar == 1) {

    // Abrir com "w" apaga o conteúdo anterior
    arquivo = fopen("arquivos/cadastros.txt", "w");

    if (arquivo == NULL) {

        printf("\nErro ao abrir o arquivo!\n");

        return 1;
    }

    // Não precisamos escrever nada.
    // Apenas abrir com "w" já limpa o arquivo.

    fclose(arquivo);

    printf("\n======================================\n");
    printf("Todos os cadastros foram apagados!\n");
    printf("========================================\n");
}

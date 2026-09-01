#include <stdio.h>
#include <stdlib.h>

void boletim()
{
    system("cls");
    
    printf("\nDigite as informações ao sistema: \n");

    char nome[15];
    float n1, n2, n3, n4, n5, maiorn, menorn = 100;

    printf("Digite o teu nome:"); 
    scanf("%s", nome);
    
    printf("Digite a tua primeira nota:" );
    scanf("%f", &n1);
    
    if(n1>=maiorn) {maiorn = n1;}
    if(n1<=menorn) {menorn = n1;}

    printf("Digite a tua segunda nota:" );
    scanf("%f", &n2);
    
    if(n2>=maiorn) {maiorn = n2;}
    if(n2<=menorn) {menorn = n2;}
    
    printf("Digite a tua terceira nota:" );
    scanf("%f", &n3);
    
    if(n3>=maiorn) {maiorn = n3;}
    if(n3<=menorn) {menorn = n3;}
    
    printf("Digite a tua quarta nota:" );
    scanf("%f", &n4);
    
    if(n4>=maiorn) {maiorn = n4;}
    if(n4<=menorn) {menorn = n4;}

    printf("Digite a tua quinta nota:" );
    scanf("%f", &n5);

    if(n5>=maiorn) {maiorn = n5;}
    if(n4<=menorn) {menorn = n5;}

    float media = (n1+n2+n3+n4+n5)/5;
    
    system("cls");

    printf("\n====BOLETIM====\n");
    printf("Nome: %s", nome);
    printf("\n1° nota: %.2f", n1);
    printf("\n2° nota: %.2f", n2);
    printf("\n3° nota: %.2f", n3);
    printf("\n4° nota: %.2f", n4);
    printf("\n5° nota: %.2f", n5);
    printf("\nMédia: %.2f", media);
    printf("\nMaior nota: %.2f", maiorn);
    printf("\nMenor nota: %.2f", menorn);
    if(media>=7)   //media
    {
        printf("\nAluno %s Aprovado!, nome");
    }
    else   //media
    {
        if(media>=5)
        {
            printf("\nAluno %s de Recuperação!", nome);
        }
        else
        {
            printf("\nAluno %s Reprovado!", nome);
        }
    }
 }
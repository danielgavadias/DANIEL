#include <stdio.h>
#include <stdlib.h>

float saldo=1000.0;
int func=1, opcao;

void banco()
{
//======================================================================================
system("cls");
while(func == 1)
{
//======================================================================================

//debug
// printf("\n%.2f", saldo);
// printf("\n%d", func);
// printf("\n%d", opcao);

printf("\n==== BANCO SENAI ====");

printf("\n1 - CONSULTAR SALDO");
printf("\n2 - DEPOSITAR");
printf("\n3 - SACAR");
printf("\n4 - SIMULADOR DE RENDIMENTO");
printf("\n0 - SAIR");

printf("\nDigite aqui a opção que deseja selecionar: "); 
scanf("%d", &opcao);
//======================================================================================
switch(opcao)
{
//======================================================================================
case 1:  
    printf("\n====CONSULTAR SALDO====\n");
    printf("\nSaldo atual: %f ", saldo);
    printf("\nVoltar ao Menu?(s=1/n=0)"); 
    scanf("%d", &func);
switch(func)
    {
        case 1:
        banco();
        break;
        
        case 0:
        printf("Finazlido.");
        break;
        
        default:
        
        break;
    }
break;
//====================================================================================== 
case 2:   
    printf("\n====DEPOSITAR====\n");
    float deposito = 0;
    printf("\nInsira o valor do depósito:"); scanf("%f", &deposito);
    saldo = saldo + deposito;
    printf("\nDeposito de %.2f reais feito.", deposito);
    printf("\nVoltar ao Menu?(s=1/n=0)"); 
    scanf("%d", &func);   
switch(func)
    {
        case 1:
        banco();
        break;
        
        case 0:
        printf("Finazlido.");
        break;
        
        default:
        
        break;

    }
break;
//======================================================================================
case 3: 
    printf("\n====SACAR====\n");
    float saque = 0;
    printf("\nInsira o valor do saque:"); scanf("%f", &saque);
    printf("\nSaque de %.2f reais feito.", saque);
    saldo = saldo - saque;
    printf("\nVoltar ao Menu?(s=1/n=0)"); 
    scanf("%d", &func);  
switch(func)
    {
        case 1:
        banco();
        break;
        
        case 0:
        printf("Finazlido.");
        break;
        
        default:
        
        break;

    }
break;
//======================================================================================
 case 4: 
    printf("\n====SIMULADOR DE RENDIMENTO====\n");
    float meses = 0;
    float rm = 0;
    float rmf = 0;
    printf("\nTaxa do rendimento mensal em porcentagem:"); scanf("%f", &rm);
    printf("\nTempo em que o dinheiro ficara rendendo(em meses):"); scanf("%f", &meses);
    rmf = (((rm/100)*saldo) * meses)+saldo;
    printf("\nO rendimento final sera de %f reais.", rmf);
    printf("\nVoltar ao Menu?(s=1/n=0)"); 
    scanf("%d", &func);  
//====================================================================================== 
default:
    func = 0;
    printf("Finalizado.");
break;
}
}
}
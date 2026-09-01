#include <stdio.h>
#include <stdlib.h>
//==========================================================================================================================================================================

char placa[10], CM; int horasPRV; // Características dos veículos

float fatPHVG, fatPHCT, fatPHMT, fatD, fatT; //Faturamentos: Veiculos no geral, Carro total, Moto total, Diário, Total

int EstOpcaoMel; char EstApagarD, EstEncerrarD, lixo; // Continuidade

int QualV, quantC, quantM, quantVT; // Quantidade de veículos

int i, dia;
//==========================================================================================================================================================================
FILE *EstHistorico;
FILE *EstInfoVeic;
FILE *EstfatDiario;
//==========================================================================================================================================================================
void estacionamento()
{
    //==========================================================================================================================================================================
    system("cls");
    //==========================================================================================================================================================================
    printf("\n===== ESTACIONAMENTO SENAI =====\n");
    printf("\n1 - REGISTRAR ENTRADA");
    printf("\n2 - REGISTRAR SAÍDA");
    printf("\n3 - CONSULTAR SITUAÇÃO");
    printf("\n4 - EXIBIR FATURAMENTO");
    printf("\n5 - ENCERRAR O DIA");
    printf("\n0 - APAGAR TODOS OS DADOS DO SISTEMA\n");

    printf("\nDigite aqui: ");

    scanf(" %d", &EstOpcaoMel);
    //==========================================================================================================================================================================
    switch (EstOpcaoMel)
    {
    case 1:
        registroEst();
    break;
    //==========================================================================================================================================================================
    case 2:
         saidaEst();
    break;
    //==========================================================================================================================================================================
    case 3:
         consultarEst();
    break;
    //==========================================================================================================================================================================
    case 4:
         faturamentoEst();
    break;
    //==========================================================================================================================================================================
    case 5:
         encerrarDiaEst();
    break;
    //==========================================================================================================================================================================
    case 0:
    printf("\nTEM CERTEZA DE QUE QUER APAGAR TODOS OS DADOS?(s/n) "); 
        
        scanf(" %c", &EstApagarD);
        switch(EstApagarD)
        {
        case 's':
            EstHistorico = fopen("arquivos/EstHistorico.txt", "w"); fprintf(EstHistorico, ""); fclose(EstHistorico);
            EstfatDiario = fopen("arquivos/EstfatDiario.txt", "w"); fprintf(EstfatDiario, ""); fclose(EstfatDiario);
            EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "w"); fprintf(EstInfoVeic, ""); fclose(EstInfoVeic);
            fatPHVG = 0;
            fatPHCT = 0;
            fatPHMT = 0;
            fatD = 0;
            fatT = 0;
            dia = 0;
            quantC = 0;
            quantM = 0;
            quantVT = 0;
            
            printf("FINALIZADO! Digite qualquer tecla para voltar a tela inical: ");  scanf(" %c", &lixo);
            2 estacionamento();
        break;
    
        case 'n':
             estacionamento();
        break;
    
        default:
        break;
        }
    break;
    
    }
    //==========================================================================================================================================================================
}
//==========================================================================================================================================================================
int registroEst()
{
    EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "a");
    EstHistorico = fopen("arquivos/EstHistorico.txt", "a");
    
    //system("cls");
    //==========================================================================================================================================================================
    if (EstHistorico == NULL)
    {
        printf("\nErro ao abrir o arquivo!H\n");
    }
    if (EstInfoVeic == NULL)
    {
        printf("\nErro ao abrir o arquivo!I\n");
    }
    //==========================================================================================================================================================================
    printf("\n===== REGISTRO =====\n");

    printf("\nQual a placa do veiculo que deseja registrar? ");
    scanf("%10s", placa);

    printf("Qual o tipo do veiculo que deseja registrar?(c/m) ");
    scanf(" %c", &CM);

    while (CM != 'c' && CM != 'm')
    {
        printf("Apenas carros(c) e motos(m) são validos! Digite um tipo de veículo válido: ");
        scanf(" %c", &CM);
    }

    printf("Quantas horas pretende ficar? ");
    scanf("%d", &horasPRV);
    switch (CM) //valorPH e quant++
    {
        case 'c':
            fatPHVG = (horasPRV * 5) + 10;
            quantC++;
        break;
        case 'm':
            fatPHVG = (horasPRV * 4) + 12;
            quantM++;
        break;
    }

    fatD = fatD + fatPHVG;
    fatT = fatT + fatD;
    quantVT++;
    fprintf(EstInfoVeic, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %.2f\n", placa, CM, horasPRV, fatPHVG);
    fprintf(EstHistorico, "ENTRADA: Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %.2f\n", placa, CM, horasPRV, fatPHVG);

    //==========================================================================================================================================================================
    printf("\nREGISTRO COMPLETO.\n");
    //==========================================================================================================================================================================
    fclose(EstHistorico);
    fclose(EstInfoVeic);
    //==========================================================================================================================================================================
    printf("\nDeseja fazer outro registro?(s/n) "); 
        char EstContReg;
        scanf(" %c", &EstContReg);
        switch (EstContReg)
        {
        case 's':
            registroEst();
        break;
    
        default:
        estacionamento();
        break;
        }
        return 0;
}
//==========================================================================================================================================================================
int saidaEst()
{
    EstHistorico = fopen("arquivos/EstHistorico.txt", "r");
    EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "r");
    //system("cls");
    //==========================================================================================================================================================================
    if (EstHistorico == NULL)
    {
        printf("\nErro ao abrir o arquivo!H\n");
    }
    if (EstInfoVeic == NULL)
    {
        printf("\nErro ao abrir o arquivo!I\n");
    }
    //==========================================================================================================================================================================
    printf("\n===== SAIDA =====\n");
    i = 0;        
        while (fscanf(EstInfoVeic, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, &CM, &horasPRV, &fatPHVG)  == 4)
        {
            i++;
            printf("\n=== Veículo N°%d ===", i);
            printf("\nPlaca: %10s", placa);
            printf("\nHoras previstas: %d", horasPRV);
            printf("\nTipo do Veículo: %c\n", CM);
        }
    fclose(EstHistorico);
    fclose(EstInfoVeic);
    //==========================================================================================================================================================================
    FILE *EstTemporario;
    EstHistorico = fopen("arquivos/EstHistorico.txt", "a");
    EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "r");
    EstTemporario = fopen("arquivos/EstTemporario.txt", "w");

    printf("\nQual veiculo desejas retirar? ");
    scanf("%d", &QualV);
    //==========================================================================================================================================================================
    i = 0;
    //==========================================================================================================================================================================
    
    while (fscanf(EstInfoVeic, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, &CM, &horasPRV, &fatPHVG) == 4)
    {
        i++;
            if (i != QualV)
                {
                    fprintf(EstTemporario, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, CM, horasPRV, fatPHVG);
                    fatPHCT = fatPHCT + fatPHVG;
                }
            
            else
                {
                    fprintf(EstHistorico, "SAÍDA: Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, CM, horasPRV, fatPHVG);
                    if(CM=='c')
                    {
                        quantC--;
                    }
                    else
                    {
                        quantM--;
                    }
                }
    }
    //==========================================================================================================================================================================
    fclose(EstInfoVeic);
    fclose(EstHistorico);
    fclose(EstTemporario);
    remove("arquivos/EstInfoVeic.txt");
    rename("arquivos/EstTemporario.txt", "arquivos/EstInfoVeic.txt");
    
    printf("\nDeseja fazer outra saída?(s/n) "); 
        char EstContSaida;
        scanf(" %c", &EstContSaida);
        switch (EstContSaida)
        {
        case 's':
            saidaEst();
        break;
    
        default:
            estacionamento();
        break;
        }
        return 0;
}
//==========================================================================================================================================================================
int consultarEst()
{
    EstHistorico = fopen("arquivos/EstHistorico.txt", "r");
    printf("\n=====SITUAÇÂO GERAL =====\n");

    if (EstHistorico == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
    }

    printf("\nVagas ocupadas por motos: %d/20", quantM);
    printf("\nVagas ocupadas por carros: %d/20", quantC);
    printf("\nVagas ocupadas: %d/20", quantC + quantM);
    printf("\nVagas livres: %d/20", 20 - (quantC + quantM));
    printf("\nQuantidade total de veículos que já passaram pelo estacionamento Senai: %d",  quantVT);
    printf("\nFaturamento total acumulado: ");

    printf("Digite qualquer tecla para voltar para o menu: ");
    scanf(" %c", &lixo);
    estacionamento();
}
//==========================================================================================================================================================================
int faturamentoEst()
{
    fatD = (fatPHCT+fatPHMT);
    EstHistorico = fopen("arquivos/EstHistorico.txt", "r");
    printf("\n=====SITUAÇÂO GERAL =====\n");

    printf("COMO É FEITA A COBRANÇA: ");
    printf("\nCARROS : (HORAS PREVISTAS * 5) + 10(TAXA FIXA)");
    printf("\nMOTOS: (HORAS PREVISTAS * 4) + 12(TAXA FIXA)\n");
    printf("\nFaturamento sobre as motos: %f", fatPHMT);
    printf("\nFaturamento sobre os carros: %f", fatPHCT);
    printf("\nFaturamento do Dia(%d): %f", dia, fatD);

    printf("\nDigite qualquer tecla para voltar para o menu: ");
    scanf(" %c", &lixo);
    estacionamento();
}
//==========================================================================================================================================================================
int encerrarDiaEst()
{   
    FILE *EstFatHistorico;
    //==========================================================================================================================================================================
    EstFatHistorico = fopen("arquivos/EstFatHistorico.txt", "a");
    printf("\nTem certeza de que quer encerrar o dia?(s/n) "); 
    scanf(" %c", &EstApagarD);
    //==========================================================================================================================================================================
        switch(EstApagarD)
        {
        case 's':
            dia++;
            fprintf(EstFatHistorico, "Dia %d: %.2f\n", dia, fatD);
            printf("\nFaturamento do dia: %.2f\nDia encerrado!", fatD);
        break;
        //==========================================================================================================================================================================
        default:
            
            estacionamento();
        break;
        }
    fclose(EstFatHistorico);
    printf("Digite qualquer tecla para voltar para o menu: ");
    scanf(" %c", &lixo);
    estacionamento();
}
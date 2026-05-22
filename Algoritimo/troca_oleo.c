#include <stdio.h>

int main() {
    int opcao;
    float kmAtual, kmUltimaTroca, kmProximaTroca, kmFaltam;
    float intervaloKM;
    int quilometragemInvalida = 0;
    printf("================================================\n");
    printf(" **** SISTEMA DE CONTROLE DE TROCA DE OLEO ****\n");
    printf("================================================ \n\n");
   
    printf("Quilometragem atual do veiculo (km): ");
    scanf("%f", &kmAtual);
    printf("Quilometragem do veiculo na ULTIMA troca de oleo (km): ");
    scanf("%f", &kmUltimaTroca);
    printf("Quantos km o veiculo deve rodar ate a proxima troca de oleo? (km): ");
    scanf("%f", &intervaloKM);
   
    // Verifica se a quilometragem atual é menor que a da última troca
    if (kmAtual < kmUltimaTroca) {
        quilometragemInvalida = 1;
    }
   
    // Determina a quilometragem da proxima troca usando o intervalo informado
    kmProximaTroca = kmUltimaTroca + intervaloKM;
   
    // Calcula quantos km faltam para a proxima troca
    if (kmAtual >= kmProximaTroca) {
        kmFaltam = 0;
    } else {
        kmFaltam = kmProximaTroca - kmAtual;
    }
   
    printf("\n\n================================================\n");
    printf("      >>> MENU DE CONSULTA <<<\n");
    printf("1 - Consultar quilometragem que falta para trocar o oleo\n");
    printf("2 - Consultar todas as informacoes completas\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    printf("\n================================================\n");
   
    // Opcao 1: Apenas quilometragem que falta
    if (opcao == 1) {
        printf("\n     >>> CONSULTA DE QUILOMETRAGEM FALTANTE <<<\n\n");
       
        if (quilometragemInvalida == 1) {
            printf("[ERRO] Quilometragem atual (%.0f km) eh menor que a da ultima troca (%.0f km)!\n", kmAtual, kmUltimaTroca);
            printf("       Verifique os valores informados.\n");
        } else if (kmAtual >= kmProximaTroca) {
            printf("ATENCAO: Voce ja ultrapassou a quilometragem da troca!\n");
            printf("Voce rodou %.0f km desde a ultima troca.\n", kmAtual - kmUltimaTroca);
            printf("TROCA DE OLEO ATRASADA! Faca a troca imediatamente.\n");
        } else {
            printf("Intervalo definido para troca: %.0f km\n", intervaloKM);
            printf("Faltam %.0f km para a proxima troca de oleo.\n", kmFaltam);
            printf("\nProxima troca deve ser aos: %.0f km\n", kmProximaTroca);
        }
    }
   
    // Opcao 2: Todas as informacoes completas
    if (opcao == 2) {
        printf("    >>> INFORMACOES COMPLETAS <<< \n");
        printf("================================================\n\n");
       
        printf("Quilometragem atual: %.0f km\n", kmAtual);
        printf("Quilometragem da ultima troca: %.0f km\n", kmUltimaTroca);
        printf("Intervalo definido para troca: %.0f km\n", intervaloKM);
        printf("Quilometragem da proxima troca: %.0f km\n", kmProximaTroca);
       
        // Verificacao de erro na quilometragem
        if (quilometragemInvalida == 1) {
            printf("\n[ALERTA] Quilometragem atual eh MENOR que a da ultima troca!\n");
            printf("         Verifique os valores informados.\n");
        }
       
        // Verifica se ja passou da quilometragem da troca
        if (kmAtual >= kmProximaTroca) {
            printf("\n[URGENTE] O veiculo ja ultrapassou a quilometragem da proxima troca!\n");
            printf("          Troca de oleo ATRASADA! Execute a troca IMEDIATAMENTE.\n");
            printf("          Voce rodou %.0f km a mais do que o recomendado.\n", kmAtual - kmProximaTroca);
        } else {
            printf("\n[OK] Faltam %.0f km para a proxima troca de oleo.\n", kmFaltam);
            printf("     Voce ja rodou %.0f km dos %.0f km recomendados.\n", kmAtual - kmUltimaTroca, intervaloKM);
           
            // Calcula e mostra o percentual completado
            float percentual = (kmAtual - kmUltimaTroca) / intervaloKM * 100;
            printf("     Percentual completado: %.1f%%\n", percentual);
        }
    }
   
    // Caso o usuario digite uma opcao invalida
    if (opcao != 1 && opcao != 2) {
        printf("OPCAO INVALIDA! Digite 1 ou 2.\n");
    }
   
    printf("\n\n================================================\n");
    printf("      **** FIM DA CONSULTA ****             \n");
    printf("================================================\n");
   
    return 0;
}

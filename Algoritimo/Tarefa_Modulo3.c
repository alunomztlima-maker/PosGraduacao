#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"portuguese");
   
    int numerador, denominador;   // Números sorteados (numerador e denominador)
    float resultado_correto;      // Resultado real da divisão
    float resposta_usuario;       // Resposta fornecida pelo jogador
    int continuar = 1;            // Controle do loop do jogo
    char opcao;                   // Opção do menu
    int acertos = 0;              // Contador de acertos
    int erros = 0;                // Contador de erros
   
    // Variáveis para o sistema de tentativas
    int tentativas;            // Controle do for
    int acertou_na_rodada;     // Flag para saber se acertou
    int tentativas_usadas;     // Quantas tentativas foram usadas
   
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
   
    printf("==============================================\n");
    printf("===   JOGO DA FRAÇÃO PARA NÚMERO DECIMAL   === \n");
    printf("==============================================\n\n");
   
    printf("==============================================\n");
    printf("        ***  REGRAS DO JOGO:  ***\n");
    printf("Regras: O computador vai sortear dois números:\n");
    printf("  - NUMERADOR\n");
    printf("  - DENOMINADOR\n");
    printf("O Jogador deve calcular o VALOR DECIMAL da divisão.\n");
    printf("O Jogador terá até 3 tentativas!\n");
    printf("==============================================\n\n");
   
    printf("Iniciado o jogo...\n\n");
   
    // Loop principal do jogo
    while(continuar == 1) {
        // Sorteia numerador (entre 1 e 50) e denominador (entre 1 e 30)      
        numerador = (rand() % 50) + 1;    
        denominador = (rand() % 30) + 1;  
       
        // Calcula o resultado correto da divisão
        resultado_correto = (float)numerador / (float)denominador;
       
        // Exibe a fração para o jogador
        printf("==============================================\n");
        printf("            FRAÇÃO SORTEADA: %d / %d\n", numerador, denominador);
        printf("==============================================\n");
       
       
        // Sistema de 3 tentativas usando FOR
        acertou_na_rodada = 0;
       
        for(tentativas = 3, tentativas_usadas = 0; tentativas >= 1 && acertou_na_rodada == 0; tentativas--) {
            tentativas_usadas++;
           
            printf("\n        >>> TENTATIVA %d de 3 <<<\n", tentativas_usadas);
            printf("Qual eh o valor decimal desta divisão?  %d / %d \n", numerador, denominador);
            printf("(Digite o resultado com 2 casas decimais ou mais): ");
           
            // Verifica se o usuário digitou um número válido
            while(scanf("%f", &resposta_usuario) != 1) {
                printf("\n==============================================\n");
                printf("      >>> ENTRADA INVÁLIDA! <<<\n");
                printf("   Digite APENAS números (ex: 0,57 ou 2,33)\n");
                printf("   Tente novamente: ");
                while(getchar() != '\n');  // Limpa o buffer do teclado
            }
           
           
            // Verifica se a resposta está correta
            float diferenca = resultado_correto - resposta_usuario;
            if(diferenca < 0) {
                diferenca = -diferenca;  // Valor absoluto
            }
           
            if(diferenca <= 0.01) {
                acertou_na_rodada = 1;  // Acertou!
                acertos++;              // Incrementa contador de acertos
                printf("\n----------------------------------------------\n");
                printf("          *** PARABÉNS! *** \n");
                printf("     *** Resposta CORRETA na %dª tentativa! ***\n", tentativas_usadas);
                printf("   %d / %d = %.2f\n", numerador, denominador, resultado_correto);
                printf("   Você respondeu: %.2f\n", resposta_usuario);
            }
            else {
                if(tentativas > 1) {
                    // Erro nas tentativas 1 ou 2
                    printf("\n----------------------------------------------\n");
                    printf("     *** Resposta ERRADA! ***\n");
                    printf("   Você respondeu: %.2f\n", resposta_usuario);
                    printf("   Tente novamente! Restam %d tentativa(s).\n", tentativas - 1);
                } else {
                    // Aqui mostra a resposta certa
                    erros++;  // Incrementa contador de erros
                    printf("\n==============================================\n");
                    printf("     *** VOCÊ ESGOTOU SUAS TENTATIVAS! ***\n");
                    printf("==============================================\n");
                    printf("       *** Resposta ERRADA! ***\n");
                    printf("\n");
                    printf("   >>> RESPOSTA CORRETA: %d / %d = %.2f <<<\n", numerador, denominador, resultado_correto);
                    printf("\n");
                    printf("   Sua última resposta foi: %.2f\n", resposta_usuario);
                    printf("==============================================\n");
                }
            }
        }
       
        // Se saiu do for sem acertar
        if(acertou_na_rodada == 0) {
            printf("\n   Não foi dessa vez! Estude mais e tente novamente.\n");
        }
       
        // Exibe placar atual
        printf("\n----------------------------------------------\n");
        printf("             PLACAR ATUAL\n");
        printf("   Acertos: %d\n", acertos);
        printf("   Erros:   %d\n", erros);
        printf("   Total:   %d jogada(s)\n", acertos + erros);
        if(acertos + erros > 0) {
            printf("   Aproveitamento: %.1f%%\n", (float)acertos / (acertos + erros) * 100);
        }
       
        // Pergunta se o jogador quer continuar
        printf("\n----------------------------------------------\n");      
        int opcao_valida = 0;
       
        while(opcao_valida == 0) {
            printf("Deseja jogar novamente? (S/N) ");
            scanf(" %c", &opcao);
           // Verifica se o usuário digitou o caractere válido
            if(opcao == 'S' || opcao == 's') {
                opcao_valida = 1;
                printf("\n\nIniciado um novo jogo...\n\n");
                while(getchar() != '\n');
            }
            else if(opcao == 'N' || opcao == 'n') {
                opcao_valida = 1;
                continuar = 0;
               
                // Exibe resultado final
                printf("\n==============================================\n");
                printf("             RESULTADO FINAL\n");
                printf("   Total de ACERTOS: %d\n", acertos);
                printf("   Total de ERROS:   %d\n", erros);
                printf("   Total de JOGADAS: %d\n", acertos + erros);
                           
                if(acertos + erros > 0) {
                    float percentual = (float)acertos / (acertos + erros) * 100;
                    printf("   Aproveitamento: %.1f%%\n", percentual);
                   
                    if(percentual >= 80) {
                        printf("   EXCELENTE! Você é um craque!\n");
                    } else if(percentual >= 60) {
                        printf("   BOM! Continue praticando!\n");
                    } else if(percentual >= 40) {
                        printf("   ATENÇÃO! Estude mais um pouco!\n");
                    } else {
                        printf("   NÃO DESISTA! A prática leva a perfeição!\n");
                    }
                }
                printf("==============================================\n\n\n");
               

                printf("**********************************************\n");
                printf("**********************************************\n");
                printf("***                                        ***\n");  
                printf("***    Obrigado por jogar! Volta logo!     ***\n");  
                printf("***                                        ***\n");  
                printf("**********************************************\n");
                printf("**********************************************\n");  
            }
            else {
                printf("\n==============================================\n");
                printf("         OPÇÃO INVÁLIDA!\n");
                printf("   Digite APENAS 'S' ou 's' para Continuar\n");
                printf("        OU 'N' ou 'n' para Sair\n");
                printf("==============================================\n\n");
                while(getchar() != '\n');
            }
        }
    }
   
    return 0;
}


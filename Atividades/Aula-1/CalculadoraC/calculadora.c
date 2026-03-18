//Para testar basta acessar a pasta via terminal e rodar os comandos:
//gcc calculadora.c -o calculadora.exe
//.\calculadora.exe

#include <stdio.h>
#include <stdlib.h>

float calcular(float a, float b, int operacao) {
    switch(operacao) {
        case 1: return a + b;
        case 2: return a - b;
        case 3: return a * b;
        case 4: 
            if(b != 0) return a / b;
            else return 0;
        default: return 0;
    }
}

void exibirResultado(float a, float b, float resultado, int operacao) {
    char operador;
    
    switch(operacao) {
        case 1: operador = '+'; break;
        case 2: operador = '-'; break;
        case 3: operador = '*'; break;
        case 4: operador = '/'; break;
        default: operador = '?';
    }
    
    if(operacao == 4 && b == 0) {
        printf("\nERRO: Divisao por zero!\n");
    } else {
        printf("\nResultado: %.2f %c %.2f = %.2f\n", a, operador, b, resultado);
    }
}

void limparTela() {
    system("cls");
}

// void validaInput(char mensagem, float valor) {
//     while (scanf("%f", &valor) != 1) {
//         printf("Entrada invalida.\n");
//         printf("Digite o \"%c\" número: ");
//     while (getchar() != '\n');
//     }
// }

int main() {
    int opcao;
    float num1, num2, resultado;
    
    do {
        printf("\n========== CALCULADORA EM C  ==========\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if(opcao >= 1 && opcao <= 4) {
            printf("Digite o primeiro numero: ");
            //scanf("%f", &num1);
            while (scanf("%f", &num1) != 1) {
                printf("Entrada invalida.\n");
                printf("Digite o primeiro numero: ");
            while (getchar() != '\n');
            }

            printf("Digite o segundo numero: ");
            //scanf("%f", &num2);
            while (scanf("%f", &num2) != 1) {
                printf("Entrada invalida.\n");
                printf("Digite o segundo numero: ");            
            while (getchar() != '\n');
            }

            resultado = calcular(num1, num2, opcao);            
            exibirResultado(num1, num2, resultado, opcao);
        }        
        if(opcao != 5 && opcao >= 1 && opcao <= 4) {
            printf("\nPressione Enter para continuar...");
            getchar();
            getchar();
            limparTela();
        } else if(opcao == 5) {
            printf("\nSaindo...\n");
        } else {
            printf("\nOpcao invalida!\n");
            printf("\nPressione Enter para continuar...");
            getchar();
            getchar();
            limparTela();
        }        
    } while(opcao != 5);
    
    return 0;
}
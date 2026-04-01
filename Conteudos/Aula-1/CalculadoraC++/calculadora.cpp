//Para testar basta acessar a pasta via terminal e rodar os comandos:
//g++ calculadora.cpp -o calculadora.exe
//.\calculadora.exe

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Calculadora {
private: 
    double resultado;
    
public:
    double calcular(double a, double b, int operacao) {
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
    
    void exibirResultado(double a, double b, double res, int op) {
        char operador;
        
        switch(op) {
            case 1: operador = '+'; break;
            case 2: operador = '-'; break;
            case 3: operador = '*'; break;
            case 4: operador = '/'; break;
            default: operador = '?';
        }
        
        cout << fixed << setprecision(2);
        
        if(op == 4 && b == 0) {
            cout << "\nERRO: Divisao por zero!" << endl;
        } else {
            cout << "\nResultado: " << a << " " << operador << " " << b 
                 << " = " << res << endl;
        }
    }
    
    void limparTela() {
        system("cls");
    }
};

int main() {
    Calculadora calc;
    int opcao;
    double num1, num2, resultado;
    
    do {
        cout << "\n========== CALCULADORA EM C++ ==========\n";
        cout << "1 - Soma\n";
        cout << "2 - Subtracao\n";
        cout << "3 - Multiplicacao\n";
        cout << "4 - Divisao\n";
        cout << "5 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        if(opcao >= 1 && opcao <= 4) {
            cout << "Digite o primeiro numero: ";
            cin >> num1;
            cout << "Digite o segundo numero: ";
            cin >> num2;
            
            resultado = calc.calcular(num1, num2, opcao);
            calc.exibirResultado(num1, num2, resultado, opcao);
        }
        
        if(opcao != 5) {
            if(opcao >= 1 && opcao <= 4) {
                cout << "\nPressione Enter para continuar...";
                cin.ignore();
                cin.get();
                calc.limparTela();
            } else {
                cout << "\nOpcao invalida!\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore();
                cin.get();
                calc.limparTela();
            }
        } else {
            cout << "\nSaindo...\n";
        }
        
    } while(opcao != 5);
    
    return 0;
}
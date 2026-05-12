#include <iostream>
using namespace std;

struct Funcionario
{
    string nome;
    float salario;
    int idade;
};

typedef struct Funcionario Funcionario;

void atualizarDados(Funcionario *f, float aumentoSalario, int idade)
{
    if(f == nullptr) return; // Verifica se o ponteiro é nulo antes de acessar os campos

    f->salario += aumentoSalario; // Atualiza o salário do funcionário somando o valor passado como parâmetro
    f->idade = idade;     // Atualiza a idade do funcionário
}


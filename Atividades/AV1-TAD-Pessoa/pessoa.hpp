#include <string>
using namespace std;

struct Pessoa 
{
    string nome;
    int idade;
    string endereco;
};

typedef struct Pessoa Pessoa;

Pessoa* _pessoa_cria(string nome, int idade, string endereco);
void _pessoa_acessa(Pessoa* p, string* nome, int* idade, string* endereco);
void _pessoa_atribui(Pessoa* p, string nome, int idade, string endereco);
void _pessoa_libera(Pessoa* p);

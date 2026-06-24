#include <iostream>
using namespace std;

/**
 * Estrutura que representa um aluno
 * Contém os dados básicos de um estudante
 */
struct aluno
{
    int matricula;      // Número de matrícula do aluno
    string nome;        // Nome completo do aluno
    string curso;       // Curso em que o aluno está matriculado
};

// Cria um alias (apelido) para a struct aluno, facilitando seu uso
typedef aluno Aluno;

/**
 * Estrutura que representa um nó da árvore binária
 * Cada nó armazena um aluno e ponteiros para os filhos esquerdo e direito
 */
struct no 
{
    aluno info;         // Dados do aluno armazenados neste nó
    no* esq;            // Ponteiro para o filho esquerdo (nomes menores)
    no* dir;            // Ponteiro para o filho direito (nomes maiores)
};

// ArvBin é um ponteiro para um nó, representando a raiz da árvore
typedef no* ArvBin;

/**
 * Função que cria uma árvore binária vazia
 * @return Ponteiro para a estrutura da árvore (ArvBin*)
 */
ArvBin* cria_ArvBin() 
{
    // Aloca memória para armazenar o ponteiro da raiz
    ArvBin* raiz = new ArvBin;

    // Verifica se a alocação foi bem sucedida
    if (raiz != nullptr)
        *raiz = nullptr;  // Inicializa a raiz como vazia

    return raiz;
}

/**
 * Função recursiva que libera todos os nós de uma subárvore
 * @param no Ponteiro para o nó raiz da subárvore a ser liberada
 */
void libera_no(no* no) 
{
    if (no == nullptr)  // Caso base: subárvore vazia
        return;

    // Libera recursivamente a subárvore esquerda
    libera_no(no->esq);
    // Libera recursivamente a subárvore direita
    libera_no(no->dir);

    // Libera a memória do nó atual
    delete no;
}

/**
 * Função que libera toda a estrutura da árvore binária
 * @param raiz Ponteiro para a estrutura da árvore
 */
void libera_ArvBin(ArvBin* raiz) 
{
    if (raiz == nullptr)  // Verifica se a árvore existe
        return;

    libera_no(*raiz);  // Libera todos os nós da árvore
    delete raiz;       // Libera o ponteiro que armazenava a raiz
}

/**
 * Função que insere um novo aluno na árvore binária
 * A inserção é feita de acordo com a ordem alfabética do nome
 * @param raiz Ponteiro para a estrutura da árvore
 * @param aluno Dados do aluno a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool insere_ArvBin(ArvBin* raiz, aluno aluno)
{
    if (raiz == nullptr)  // Verifica se a árvore existe
        return false;

    // Árvore vazia
    if (*raiz == nullptr)
    {
        no* novo = new no;
        novo->info = aluno;      // Atribui os dados do aluno
        novo->esq = nullptr;     // Inicializa filho esquerdo como vazio
        novo->dir = nullptr;     // Inicializa filho direito como vazio

        *raiz = novo;
        return true;
    }

    no* atual = *raiz;  // Começa a busca a partir da raiz

    // Loop para encontrar a posição correta de inserção
    while (true) {
        
        // Verifica se já existe um aluno com o mesmo nome e matrícula
        if (aluno.nome == atual->info.nome && aluno.matricula == atual->info.matricula)
        {
            cout << "Aluno já cadastrado!\n" << endl;
            return false;
        }

        // Navega pela árvore usando o nome como chave
        if (aluno.nome < atual->info.nome)
        {
            if (atual->esq == nullptr)
            {
                no* novo = new no;
                novo->info = aluno;
                novo->esq = nullptr;
                novo->dir = nullptr;

                atual->esq = novo;
                return true;
            }
            atual = atual->esq;  // Continua descendo pela esquerda
        }
        else
        {
            if (atual->dir == nullptr)
            {
                no* novo = new no;
                novo->info = aluno;
                novo->esq = nullptr;
                novo->dir = nullptr;

                atual->dir = novo;
                return true;
            }
            atual = atual->dir;  // Continua descendo pela direita
        }
    }
}

/**
 * Função recursiva que realiza o percurso em ordem (in-order)
 * Exibe os alunos em ordem alfabética (esquerda, raiz, direita)
 * @param no Ponteiro para o nó atual
 */
void emOrdem(no* no) 
{
    if (no == nullptr)  // Caso base: subárvore vazia
        return;

    // Percorre a subárvore esquerda (nomes menores)
    emOrdem(no->esq);
    
    // Exibe os dados do nó atual
    cout << no->info.nome << " - " << no->info.matricula << " - " << no->info.curso << endl;
    
    // Percorre a subárvore direita (nomes maiores)
    emOrdem(no->dir);
}

/**
 * Função auxiliar recursiva que busca um aluno pelo nome
 * @param raiz Ponteiro para a raiz da subárvore atual
 * @param nome Nome do aluno a ser buscado
 * @return Ponteiro para o nó encontrado, ou nullptr se não encontrado
 */
no* buscaAlunoPorNome_aux(no* raiz, string nome)
{
    if (raiz == nullptr)  // Subárvore vazia, aluno não encontrado
        return nullptr;

    // Verifica se o nó atual contém o nome procurado
    if (nome == raiz->info.nome)
        return raiz;

    // Decide se vai buscar na esquerda ou direita baseado na ordem alfabética
    if (nome < raiz->info.nome)
        return buscaAlunoPorNome_aux(raiz->esq, nome);  // Busca na esquerda
    else
        return buscaAlunoPorNome_aux(raiz->dir, nome);  // Busca na direita
}

/**
 * Função que busca um aluno pelo nome e exibe o resultado
 * @param raiz Ponteiro para a raiz da árvore
 * @param nome Nome do aluno a ser buscado
 */
void buscaAlunoPorNome(no* raiz, string nome)
{
    // Realiza a busca
    no* aluno = buscaAlunoPorNome_aux(raiz, nome);
    
    // Exibe o resultado da busca
    if(aluno != nullptr)
        cout << "Aluno encontrado: " << aluno->info.nome << " - " 
             << aluno->info.matricula << " - " << aluno->info.curso << "\n" << endl;
    else
        cout << "Aluno " << nome << " não encontrado :(\n" << endl;
}

/**
 * Função auxiliar recursiva que calcula informações da árvore
 * @param no Ponteiro para o nó atual
 * @param totalAlunos Referência para contar o total de alunos
 * @param nivelAtual Nível atual na árvore (raiz = nível 1)
 * @param alturaMaxima Referência para armazenar a altura máxima
 */
void infoArvore_aux(no* no, int& totalAlunos, int nivelAtual, int& alturaMaxima) 
{
    if (no == nullptr)  // Caso base: subárvore vazia
        return;
    
    totalAlunos++;  // Incrementa o contador de alunos
    
    // Atualiza a altura máxima se o nível atual for maior
    if (nivelAtual > alturaMaxima)
        alturaMaxima = nivelAtual;
    
    // Percorre recursivamente as subárvores, aumentando o nível
    infoArvore_aux(no->esq, totalAlunos, nivelAtual + 1, alturaMaxima);    
    infoArvore_aux(no->dir, totalAlunos, nivelAtual + 1, alturaMaxima);
}

/**
 * Função que exibe informações estatísticas da árvore
 * @param raiz Ponteiro para a estrutura da árvore
 */
void infoArvore(ArvBin* raiz) 
{
    // Verifica se a árvore está vazia
    if (raiz == nullptr || *raiz == nullptr) {
        cout << "Árvore vazia!" << endl;
        cout << "Quantidade total de alunos: 0" << endl;
        cout << "Altura da árvore: 0" << endl;
        return;
    }
    
    int totalAlunos = 0;    // Contador de alunos
    int alturaMaxima = 0;   // Altura da árvore
    
    // Calcula as informações recursivamente
    infoArvore_aux(*raiz, totalAlunos, 1, alturaMaxima);
    
    // Exibe as informações calculadas
    cout << "--- Informações da Árvore ---" << endl;
    cout << "Quantidade total de alunos cadastrados: " << totalAlunos << endl;
    cout << "Altura da árvore: " << alturaMaxima << endl;
}
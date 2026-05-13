# Apresentação: Pilhas

## Objetivo da aula

Entender o conceito de **pilha** usando o conhecimento já visto sobre **lista estática** e **lista dinâmica**.

Ao final, a turma deve conseguir responder:

- O que é uma pilha;
- Como ela funciona;
- Quais operações básicas ela oferece;
- Qual a diferença entre pilha, lista estática e lista dinâmica;
- Em que situações uma pilha é uma boa escolha.

## 1. Começando pela ideia mais simples

Imagine uma pilha de livros, pratos ou caixas.

- Você coloca um novo item sempre no topo;
- Você retira primeiro o item que está no topo;
- Não faz sentido pegar o item do meio sem tirar os de cima antes.

Essa é a essência da pilha em programação.

## 2. O que é uma pilha?

Uma **pilha** é uma estrutura de dados em que o último elemento que entra é o primeiro que sai.

Isso é chamado de **LIFO**:

- **L**ast
- **I**n
- **F**irst
- **O**ut

Em português, significa: **o último a entrar é o primeiro a sair**.

## 3. Onde a pilha aparece na prática?

Você já usa pilhas em várias situações:

- Histórico de navegação do navegador;
- Botão desfazer em editores de texto;
- Chamadas de funções na programação;
- Verificação de expressões matemáticas;
- Voltar etapas em um sistema.

## 4. Comparando com lista estática e lista dinâmica

Se a turma já conhece listas, a comparação ajuda bastante.

### Lista estática

- Tem tamanho fixo;
- Os elementos ficam em posições definidas no vetor;
- Pode haver limite máximo de armazenamento.

### Lista dinâmica

- Pode crescer e diminuir durante a execução;
- Não depende de um tamanho fixo pré-definido;
- Usa nós ligados por ponteiros ou referências.

### Pilha

- Também guarda vários elementos;
- Mas restringe o acesso apenas ao topo;
- Não permite manipular livremente qualquer posição como numa lista comum.

## 5. A diferença principal

Em uma lista, normalmente podemos acessar um elemento do meio, da frente ou do fim, dependendo da implementação.

Em uma pilha, o acesso é controlado:

- Só o topo pode receber novos elementos;
- Só o topo pode ser removido;
- Os demais ficam “guardados” abaixo dele.

Isso deixa a estrutura mais simples para problemas em que a ordem de saída importa.

## 6. Operações básicas da pilha

As operações mais importantes são:

### `push` ou empilhar

Insere um elemento no topo da pilha.

Exemplo:

- Pilha vazia
- Push 10
- Push 20
- Push 30

Topo atual: `30`

### `pop` ou desempilhar

Remove o elemento que está no topo.

Exemplo:

- Pilha: 10, 20, 30
- Pop
- Sai o `30`

### `peek` ou `top`

Mostra o elemento do topo sem removê-lo.

Exemplo:

- Pilha: 10, 20, 30
- Peek
- Retorna `30`

### `isEmpty`

Verifica se a pilha está vazia.

### `isFull`

Usada principalmente na pilha implementada com lista estática.

## 7. Exemplo visual

Considere a sequência:

1. Empilhar A
2. Empilhar B
3. Empilhar C

Representação:

```text
Topo -> C
	B
	A
```

Se removermos um elemento:

```text
Topo -> B
	A
```

O último que entrou foi o `C`, então ele sai primeiro.

## 8. Por que a pilha é útil?

A pilha é útil quando o problema precisa respeitar a ordem inversa de inserção.

Ela ajuda porque:

- Organiza o acesso de forma simples;
- Facilita o controle de chamadas e retornos;
- Evita manipulações desnecessárias no meio da estrutura;
- Resolve problemas com histórico e retorno.

## 9. Pilha com lista estática

Se a pilha for implementada com uma lista estática, normalmente usamos um vetor.

Ideia:

- Existe uma posição que representa o topo;
- Inserir é colocar no próximo espaço livre;
- Remover é voltar uma posição no topo.

Vantagens:

- Simples de implementar;
- Acesso rápido ao topo.

Limitações:

- Tamanho máximo definido;
- Se encher, não aceita novos elementos.

## 10. Pilha com lista dinâmica

Se a pilha for implementada com lista dinâmica, cada novo elemento pode ser criado quando necessário.

Ideia:

- Cada elemento aponta para o próximo;
- O topo aponta para o último elemento inserido;
- Ao remover, o topo passa a apontar para o próximo nó.

Vantagens:

- Cresce conforme a necessidade;
- Não depende de tamanho fixo.

Limitações:

- Usa mais estrutura interna;
- Exige mais cuidado com referências e memória.

## 11. Resumo comparativo

| Estrutura | Acesso | Crescimento | Melhor uso |
| --- | --- | --- | --- |
| Lista estática | Acesso por índice | Limitado | Quando o tamanho é conhecido |
| Lista dinâmica | Mais flexível | Cresce durante a execução | Quando o tamanho pode variar |
| Pilha | Apenas no topo | Depende da implementação | Quando o último a entrar deve sair primeiro |

## 12. Exemplo do dia a dia

Pense em uma pilha de bandejas em uma lanchonete:

- A próxima bandeja colocada vai para o topo;
- A bandeja retirada também sai do topo;
- Ninguém pega a bandeja de baixo sem reorganizar tudo.

Esse comportamento é exatamente o que queremos modelar.

## 13. Erros comuns

- Confundir pilha com fila;
- Tentar acessar elementos do meio diretamente;
- Esquecer de verificar se a pilha está vazia antes de remover;
- Esquecer o limite de uma pilha baseada em lista estática.

## 14. Ideia principal para guardar

A pilha é uma estrutura simples e muito útil quando a ordem importa.

Ela funciona com a regra:

**último que entra, primeiro que sai**.

## 15. Encerramento

Depois de entender listas estáticas e dinâmicas, a pilha fica fácil de visualizar:

- Ela é uma coleção de elementos;
- O acesso é restrito ao topo;
- Suas operações básicas são inserir, remover e consultar o topo.


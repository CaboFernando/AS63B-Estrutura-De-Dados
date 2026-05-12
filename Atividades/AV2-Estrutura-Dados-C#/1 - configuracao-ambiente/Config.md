## Configuração do Ambiente C# (.NET)

Este documento explica de forma prática e direta, como preparar o ambiente para desenvolver e executar projetos C# com o SDK .NET no Windows e também no Ubuntu 24.04.

## Instruções para Windows

### 1) Instalar o .NET SDK
- Acesse: https://dotnet.microsoft.com/download
- Baixe o instalador do **.NET SDK** recomendado (ex.: .NET 10) e execute-o.
- Após a instalação, abra um terminal (PowerShell) e verifique:

```bash
dotnet --version
dotnet --info
```

Se retornar a versão e informações, o SDK está instalado corretamente.

### 2) Editor recomendado: Visual Studio Code
- Baixe e instale: https://code.visualstudio.com/
- Abra o VS Code e instale a extensão **C#** (publisher: Microsoft). Essa extensão provê IntelliSense, depuração e integração com OmniSharp.
- Ao abrir um projeto pela primeira vez, aceite a sugestão do VS Code para adicionar os assets de depuração (cria `launch.json` e `tasks.json`).

### 3) Criar e executar um projeto console exemplo
- No terminal execute:

```bash
dotnet new console -o MeuHelloWorld
cd MeuHelloWorld
dotnet run
```

Isso cria um projeto console com `Program.cs` e executa o aplicativo (saída do `Console.WriteLine`).

### 4) Comandos úteis
- Restaurar dependências: `dotnet restore`
- Compilar: `dotnet build`
- Executar: `dotnet run`
- Publicar (binário pronto): `dotnet publish -c Release -o ./out`

### 5) Depuração no VS Code
- Abra a pasta do projeto (`code .`).
- Configure breakpoints em `Program.cs` e pressione F5 para executar em modo debug.
- Se não existir, aceite a criação dos arquivos de configuração de execução/depuração.

### 6) Organização e boas práticas
- Separe exemplos em pastas (ex.: `3 - exemplo-basico-hello-world/`).
- Coloque classes em arquivos separados (`Pilha.cs`, `Program.cs`).
- Use `namespace` para evitar conflitos de nomes com tipos do BCL (por exemplo, `Stack<T>`).

### 7) Problemas comuns e soluções
- `dotnet: command not found` — verifique instalação e PATH; reinicie o terminal/sistema após instalação.
- CS8803 (top-level statements precisam preceder declarações de tipo) — não misture declarações de classes/namespaces com instruções top-level no mesmo arquivo; coloque código dentro de `static void Main()` ou remova declarações de tipo do arquivo.
- Conflito de nomes (ex.: `Stack<T>` vs `System.Collections.Generic.Stack<T>`) — use `namespace` ou renomeie sua classe (ex.: `Pilha<T>`).
- TargetFramework não encontrada — ajuste `<TargetFramework>` no `.csproj` ou instale a versão correspondente do SDK.

### 8) Exemplo rápido (passo a passo)

1. Abrir PowerShell e criar projeto:

```bash
dotnet new console -o exemplo-hello
cd exemplo-hello
code .
```

2. No VS Code, edite `Program.cs` e rode `dotnet run` no terminal integrado ou use F5.

3. Para adicionar outro exemplo (pilha) crie pasta separada e um `.csproj` próprio.

---

## Instruções para Ubuntu 24 (Ubuntu 24.04)

As etapas abaixo mostram como instalar o .NET SDK e o VS Code em Ubuntu 24.04. Você pode usar a mesma versão do Windows, por exemplo `dotnet-sdk-10.0`, se ela estiver disponível no repositório Microsoft.

### 1) Adicionar o repositório Microsoft e pré-requisitos

```bash
sudo apt update
sudo apt install -y wget ca-certificates apt-transport-https gnupg
wget https://packages.microsoft.com/config/ubuntu/24.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
sudo apt update
```

### 2) Instalar o .NET SDK

Verifique quais pacotes `dotnet-sdk-<versao>` estão disponíveis:

```bash
apt list -a 'dotnet-sdk-*'
```

Instale a mesma versão que você usa no Windows, quando ela estiver disponível (substitua `<versao>`):

```bash
sudo apt install -y dotnet-sdk-<versao>
# exemplo:
sudo apt install -y dotnet-sdk-10.0
```

Verifique a instalação:

```bash
dotnet --version
dotnet --info
```

### 3) Instalar VS Code (opção via snap)

```bash
sudo snap install --classic code
```

Abra o VS Code e instale a extensão **C#** (Microsoft).

### 4) Criar e executar projeto exemplo

```bash
dotnet new console -o MeuHelloWorld
cd MeuHelloWorld
dotnet run
```

### 5) Depuração e edição

- Use o VS Code para abrir a pasta do projeto (`code .`) e pressione F5 para depurar.

### 6) Problemas comuns no Linux

- Dependências nativas ausentes: instale as bibliotecas sugeridas na mensagem de erro (por exemplo `libssl` ou `libicu`). Um comando genérico:

```bash
sudo apt install -y libssl-dev libicu-dev
```

- `dotnet` não encontrado: confirme a instalação e reinicie o terminal; verifique `which dotnet`.

---
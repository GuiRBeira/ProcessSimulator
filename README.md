# ⚙️ Simulador de Escalonamento de Processos

[![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)]()
[![GTK](https://img.shields.io/badge/GTK-7C9AA6?style=flat&logo=gtk&logoColor=white)]()
[![CMake](https://img.shields.io/badge/CMake-064F8C?style=flat&logo=cmake&logoColor=white)]()
[![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)]()

**Simulador educativo de algoritmos de escalonamento de CPU desenvolvido em C com interface GTK**

## 🎯 Sobre o Projeto

Trabalho acadêmico da disciplina de **Sistemas Operacionais** focado na implementação prática de um escalonador de processos de curto prazo com múltiplas políticas de escalonamento. O simulador permite visualizar e comparar o comportamento de diferentes algoritmos de escalonamento em tempo real.

## 🔧 Algoritmos Implementados

- **Round Robin** (quantum customizável)
- **Shortest Job First** (SJF)
- **Priority Scheduling** 
- **First-Come, First-Served** (FCFS)

## 🚀 Tecnologias Utilizadas

- **Linguagem:** C puro
- **Interface Gráfica:** GTK 3
- **Build System:** CMake
- **Sistema:** Linux

## 📥 Instalação e Execução

### Pré-requisitos

```bash
# Instalar GTK 3 e CMake (Ubuntu/Debian)
sudo apt-get install libgtk-3-dev cmake build-essential
```

## Execução Rápida

```bash
# 1. Instala dependências
./init_dep.sh

# 2. Primeira execução (limpa e configura build)
./init.sh  

# 3. Execuções subsequentes
./app.sh
```

## Execução Manual
```bash
# Configurar build
mkdir -p build && cd build
cmake ..

# Compilar
make

# Executar
./bin/process-scheduler
```

## 🏗️ Estrutura do Projeto
SimulatorProcess/
├── build/bin/                 # Executável final
├── src/                      # Código fonte em C
├── include/                  # Headers e definições
├── init_dep.sh           # Instalação de dependências
├── init.sh               # Build inicial e limpeza
├── app.sh                # Execução rápida
├── CMakeLists.txt            # Configuração do CMake
└── README.md                 # Este arquivo

## 💡 Funcionalidades
- ✅ Simulação visual em tempo real dos processos
- ✅ Métricas de desempenho: throughput, waiting time, turnaround time
- ✅ Comparação side-by-side entre diferentes políticas
- ✅ Interface educativa para aprendizado de Sistemas Operacionais
- ✅ Configuração flexível de parâmetros dos algoritmos

## 🎮 Como Usar
- Execute o simulador usando os scripts fornecidos
- Selecione a política de escalonamento desejada
- Configure os parâmetros específicos (ex: quantum para Round Robin)
- Observe a simulação em tempo real
- Analise as métricas de desempenho geradas

## 🤝 Desenvolvimento
Para contribuir com o projeto:

```bash
# Clonar e configurar ambiente
git clone [url-do-repositorio]
cd SimulatorProcess
./init_dep.sh
./init.sh
```

## 📊 Aprendizados
Este projeto proporcionou:
- Domínio de programação em C para sistemas
- Experiência com interface gráfica GTK
- Compreensão profunda de algoritmos de escalonamento
- Desenvolvimento de ferramentas educativas
- Gerenciamento de build systems com CMake

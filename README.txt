Projeto: Simulador de Gerenciador de Processos
Descrição
Neste trabalho, os discentes participantes da disciplina Sistemas Operacionais do curso de Engenharia de Computação possuem como tarefa a implementação de um simulador de gerenciador de processos. Nesse sentido, é pretendido que cada dupla implemente um escalonador de processos de curto prazo, alternando os processos de acordo com diversas políticas de escalonamento. O simulador deverá simular a execução dos processos da seguinte maneira:

Estrutura do Projeto
O arquivo executável está localizado na pasta build/bin.
Scripts importantes:
init_dep.sh: Script para instalação das dependências.
init.sh: Script para a primeira execução.
app.sh: Script para execuções subsequentes.
Pré-requisitos
Antes de iniciar, verifique se você possui os seguintes requisitos:

-- gkt 3
-- cmake

Instalação de Dependências

Para instalar as dependências do projeto, siga os passos abaixo:
Execute o script init_dep.sh:
Terminal:
./init_dep.sh

Primeira Execução, é importante executar pelo menos uma vez esse script, pois ele irá limpar a pasta build, prevenindo de possíveis erros e bugs:
Terminal:
./init.sh

Execuções Futuras
Para execuções subsequentes, basta usar o script app.sh:
Terminal:
./app.sh
# Project_Festo

## Resumo

Esse projeto visa mostrar como uma planta legado pode ser inserida dentro do contexto O-PAS com mudanças gradativas, que é economicamente mais viável para plantas já existentes.

Nessa visão, os CLP's legados funcionam como gateways para variáveis do processo e vão ter a função de rodar os servidores OPC-UA para disponibilizar as variáveis de entrada e 
saída do processo.

A lógica de controle, antes configurada diretamente dentro dos CLP's, agora vai ser executada em um DNC (que será representado por uma Raspberry-Pi) com uma lógica de controle
feita com blocos funcionais seguindo o padrão IEC 61499.

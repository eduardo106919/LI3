
# Balcões de Registo

Considere um sistema de gestão dos balcões de registos portugueses. O sistema contém um conjunto de balcões, definidos pelo seu id, nome, localização, e horário de atendimento. A cada balcão estão associados vários clientes (um cliente pode estar associado a vários balcões), definidos pelo número de cartão de cidadão, nome, data de nascimento, e morada. Considere ainda que cada balcão pode ter múltiplas filas de espera, uma por cada serviço prestado (definido pelo nome, e.g., "Renovar cartão de cidadão"), sendo que a fila deverá dar prioridade de atendimento a utilizadores com mais de 80 anos.

O sistema deverá suportar as seguintes operações:
- Consultar a informação de um cliente, fornecendo o seu número de cartão de cidadão;
- Consultar a lista de clientes de um balcão, fornecendo o seu id;
- Num dado balcão, adicionar um cliente a uma fila de espera, fornecendo o id do balcão, o número de cartão de cidadão do cliente, e o nome do serviço em questão;
- Num dado serviço de um balcão, chamar (i.e., remover) o primeiro cliente na fila, fornecendo o id do balcão e o nome do serviço.


## Entidades



## Módulos



## Estruturas de Dados



## Arquitetura

Colocar diagrama com os módulos e as suas ligações



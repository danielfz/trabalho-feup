# Trabalho prático - Parte 1

O trabalho agora enunciado apenas se refere à primeira parte do mesmo.
A segunda parte do trabalho será enunciada posteriormente (após a entrega desta
primeira parte).

## Notas relativas à implementação (itens sujeitos a avaliação)

- Deve utilizar classes adequadas para representação das entidades envolvidas.
  Os atributos devem ser escolhidos de forma a caracterizar os conceitos mais
  importantes das entidades a representar).
- Deve utilizar o conceito de herança e polimorfismo onde considerar
  conveniente.
- Os dados usados pela aplicação devem ser guardados em ficheiro,
  para utilização em futuras execuções.
- Deve tratar convenientemente possíveis excepções. 
- Deve usar algoritmos de pesquisa e ordenação (por exemplo, nas
  múltiplas listagens solicitadas)
- As classes implementadas devem ser devidamente documentadas (usando Doxygen).

## Notas relativas à demonstração (itens sujeitos a avaliação)

- Preparação adequada para demonstrar as funcionalidades do trabalho
- Deve usar um número significativo de itens (dados).
- Todos os elementos do grupo devem estar presentes

## Relatório (itens sujeitos a avaliação)

O relatório, a ser entregue em formato pdf, deve incluir:

- Página de rosto com título do trabalho, identificação dos elementos do grupo
  (nome, código, email) e data
- Descrição sucinta do tema do trabalho
- Descrição da solução implementada
- Diagramas UML do modelo de dados concebido (diagrama de classes, indicando
  para cada classe as suas relações, atributos e métodos)
- Lista de Casos de Utilização identificados para a aplicação (não é necessário
  desenhar os diagramas de casos de utilização)
- Relato das principais dificuldades encontradas no desenvolvimento do trabalho
- Indicação do esforço dedicado por cada elemento do grupo

## Entrega

Disponibilizar em um ficheiro <NOME>.zip:
- pasta codigo (contém código fonte do programa)
- pasta documentacao (contém documentação html, criada pelo Doxygen)
- ficheiro relatorio (documento em formato pdf)
- O <NOME> do ficheiro deverá obedecer ao formato AEDA1617_<TURMA>_<GRUPO>,
  onde turma é o código da turma teórico/prática e <GRUPO> é uma letra que
  identifica o grupo, conforme indicado na atribuição de trabalhos. Por
  exemplo: AEDA1617_2MIEIC5_C.zip corresponde ao trabalho realizado pelo grupo
  C da turma 2MIEIC5

## Datas

Data de entrega: dia 18/novembro, até às 23h59m. Submeter pelo Moodle:
- Relatório em pdf + Código do programa + documentação
- Apresentação do trabalho:  de 21 a 24 de novembro, em horário a combinar com
  o docente das aulas práticas


# Parte 1

Neste trabalho deve modelar um problema recorrendo ao paradigma da orientação
por objetos e usar a linguagem C++ para implementar a solução correspondente.
A aplicação a desenvolver deve permitir registar e gerir entidades , conjuntos
de entidades e relações entre elas, isto é, deve permitir as operações básicas
CRUD ( Create, Read, Update, Delete ).

A aplicação a desenvolver deve:
- Utilizar classes adequadas para representação das entidades envolvidas.  Os
  atributos devem ser escolhidos de forma a caracterizar os conceitos mais
  importantes das entidades a representar.
- Considerar relações entre classes
- Utilizar o conceito de herança e polimorfismo .
- Utilizar estruturas lineares (por exemplo, vetores) para gerir conjuntos
  (elementos de uma mesma entidade/classe)
- Tratar convenientemente possíveis excepções .
- Guardar informação em ficheiro para uso futuro A aplicação deve também
  permitir listagens várias ( totais ou parciais com critérios a definir pelo
  utilizador, com possível ordenação).
- Usar algoritmos de pesquisa e ordenação As classes implementadas devem ser
  devidamente documentadas (usando Doxygen)

# Tema 4 – Inscrição de Estudantes (Parte 1)

O plano de estudos do MIEIC inclui unidades curriculares obrigatórias e
unidades curriculares optativas (no 4ºano/2ºsemestre e 5ºano/1ºsemestre).  As
unidades curriculares optativas possuem um número fixo de vagas, pelo que o
estudante só fica inscrito se tiver vaga.  No caso de não existir vaga numa UC
optativa que interessa ao estudante, deve ser possível identificar rapidamente
outras UCs da mesma área científica existentes em outros cursos da Universidade
do Porto.  Inclua esta informação nas UCs optativas.
    
Implemente um sistema para inscrição de estudantes nas unidades curriculares
do MIEIC (seguindo o plano de estudos deste curso).
    
A inscrição de um estudante num ano letivo está limitada a 75 créditos e não é
possível a inscrição em uma UC de um ano curricular superior ao de UCs às quais
o estudante, não tendo ainda obtido aprovação, não está inscrito.  O sistema
deve registar a data da inscrição.
    
Um estudante é identificado por um código, nome, email e estatuto (pode
considerar informação adicional).
    
Todos os estudantes possuem um tutor, que é um docente do MIEIC.  No instante
em que o estudante efetua a inscrição, é­lhe atribuído um tutor.
    
A escolha do tutor é efetuada de modo a equilibrar o número de estudantes por
tutor.  O sistema deve permitir a consulta de inscrições quer por estudante,
quer por unidade curricular.

# Projeto dos Trens 🚂

## Descrição
Este projeto é parte do curso **Sistemas Operacionais (IMD0036)** do **Instituto Metrópole Digital**. Ele consiste no desenvolvimento de uma malha ferroviária que comporta 5 trens circulando no sentido horário, respeitando regras de segurança para evitar colisões e deadlocks.

## Funcionalidades
- Cinco trens independentes circulando em uma malha ferroviária.
- Controle de velocidade individual para cada trem por meio de um **QSlider**.
- Implementação de **mutex** e/ou **semáforos** para gerenciar sete regiões críticas e evitar colisões e deadlocks.
- Trens começam a se mover automaticamente ao iniciar o executável.

## Requisitos do Projeto
### Técnicos
1. Cada trem deve ser executado em sua própria thread.
2. As regiões críticas devem ser gerenciadas utilizando mutexes e/ou semáforos.
3. Os trens devem se mover sempre que possível, evitando bloqueios desnecessários.
4. Controle de velocidade implementado com um **QSlider**, onde:
   - 0: trem parado.
   - 200: velocidade máxima.
5. Interface gráfica contendo:
   - Malha ferroviária (Figura 1 do enunciado).
   - Controles de velocidade (Figura 3 do enunciado).

### Implementação
- Exclusão dos botões "Ligar" e "Parar" do código base fornecido.
- Início automático do movimento dos trens ao abrir o executável.

## Critérios de Avaliação
- **Nota mínima será atribuída a:**
  - Código que não compila.
  - Código sem tratamento correto de regiões críticas.
  - Código sem uso de mutex ou semáforos.
  - Código enviado fora do prazo ou em outro meio que não o SIGAA.
  - Submissões plagiadas.
  - Vídeo ou itens obrigatórios ausentes.

## Envio
- **Itens obrigatórios:**
  - Código completo.
  - Nome dos componentes.
  - Vídeo de até 3 minutos demonstrando a execução com diferentes velocidades.

### Instruções para o Vídeo
1. Demonstrar o funcionamento em:
   - Velocidade mínima para todos os trens.
   - Velocidade máxima para todos os trens.
   - Velocidades variadas para mostrar diferentes composições.
2. Explicar brevemente como colisões e deadlocks foram tratados.
3. Garantir ao menos 5 segundos de demonstração para cada cenário.

## Tecnologias Utilizadas
- Linguagem: C++.
- Framework: **Qt** para interface gráfica.
- Gerenciamento de threads e sincronização com **mutexes** e **semáforos**.

## Autores
- Nome dos componentes do grupo.

---

## Execução
1. Compilar o código utilizando o **Qt Creator** ou ferramentas de sua escolha.
2. Executar o programa para visualizar a simulação.

**Observação:** Certifique-se de que todas as dependências do Qt estão configuradas antes de executar o projeto.

---

**Projeto desenvolvido para fins acadêmicos.**

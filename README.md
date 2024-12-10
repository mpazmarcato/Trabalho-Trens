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
   - Malha ferroviária.
   - Controles de velocidade.

### Implementação
- Início automático do movimento dos trens ao abrir o executável.

## Critérios de Avaliação
- **Nota mínima será atribuída a:**
  - Código que não compila.
  - Código sem tratamento correto de regiões críticas.
  - Código sem uso de mutex ou semáforos.
  - Código enviado fora do prazo ou em outro meio que não o SIGAA.
  - Submissões plagiadas.
  - Vídeo ou itens obrigatórios ausentes.

## Tecnologias Utilizadas
- Linguagem: C++.
- Framework: **Qt** para interface gráfica.
- Gerenciamento de threads e sincronização com **mutexes** e **semáforos**.

---

## Execução
1. Compilar o código utilizando o **Qt Creator** ou ferramentas de sua escolha.
2. Executar o programa para visualizar a simulação.

**Observação:** Certifique-se de que todas as dependências do Qt estão configuradas antes de executar o projeto.

---

**Projeto desenvolvido para fins acadêmicos.**

#include "../estrutura/estrutura.h"

int processoEntrega(FilaListaEntrega *listaEntrega, PilhaSegundaEntrega *segundaEntrega, FilaListaDevolucao *devolucao);

void pedidoFilaEntrega(Pedido *pedido, FilaListaEntrega **entregas);

void removeFilaEntrega(FilaListaEntrega **entregas);
void segundaRota(FilaListaEntrega **entrega,PilhaSegundaEntrega **entregaNE);

void removeSegundaEntrega(PilhaSegundaEntrega **entregaNE);
void adicionaSegundaEntrega(Pedido *pedido,PilhaSegundaEntrega **entregaNE);

void primeiraEntrega(FilaListaEntrega **entrega);
void entregaNEPilha(PilhaSegundaEntrega **entregasNE);
void adicionaDevolucao(Pedido *pedido,FilaListaDevolucao **devolucao);
void segundaEntregaDevolucao(PilhaSegundaEntrega **entregasNE,FilaListaDevolucao **devolucao);
void removeDevolucao(FilaListaDevolucao** f);

/*
Se for finalizada na primeira + 5
Se for finalizada na segunda + 3
Se for 
*/
void pontuacao(Rota *rota);

void processoDevolucao(FilaListaDevolucao **devolucao);
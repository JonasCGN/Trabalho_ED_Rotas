#pragma once

#include "../estrutura/estrutura.h"

void pedidoFila(Pedido *pedido, ListaEntrega **entregas);

void removeFila(ListaEntrega **entregas);
void segundaRota(ListaEntrega **entregas,PilhaSegundaEntrega **entregaNE);

void removeSegundaEntrega(PilhaSegundaEntrega **entregaNE);
void adicionaSegundaEntrega(Pedido *pedido,PilhaSegundaEntrega **entregaNE);

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

void addHistorico(Pedido* pedido,FilaListaHistorico **historico);

int historicoVazio(FilaListaHistorico *fila);
int devolucaoVazio(FilaListaDevolucao *fila);
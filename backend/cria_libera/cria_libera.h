#pragma once

#include "../estrutura/estrutura.h"

//Cria
ListaCliente *criaListaCliente();
ListaEntrega* criaListaEntrega();
PilhaSegundaEntrega* criaListaSegundaEntrega();
FilaListaHistorico* criaListaHistorico();
FilaListaDevolucao* criaListaDevolucao();

int historicoVazio(FilaListaHistorico *fila);
int devolucaoVazio(FilaListaDevolucao *fila);

//Libera
void liberaPedido(Pedido *pedido);
void liberaListaEntrega(ListaEntrega* l);
void liberaListaSegundaEntrega(PilhaSegundaEntrega* l);

void liberaFilaListaHistorico(FilaListaHistorico *fila);
void liberaListaHistorico(ListaHistorico* l);

void liberaFilaListaDevolucao(FilaListaDevolucao* fila);
void liberaListaDevolucao(ListaDevolucao* l);
void liberarListaCliente(ListaCliente *Cliente);
#pragma once

//Cria
ListaEntrega* criaListaEntrega();
ListaSegundaEntrega* criaListaSegundaEntrega();
FilaListaHistorico* criaListaHistorico();
FilaListaDevolucao* criaListaDevolucao();

int historicoVazio(FilaListaHistorico *fila);
int devolucaoVazio(FilaListaDevolucao *fila);

//Libera
void liberaPedido(Pedido *pedido);
void liberaListaEntrega(ListaEntrega* l);
void liberaListaSegundaEntrega(ListaSegundaEntrega* l);

void liberaFilaListaHistorico(FilaListaHistorico *fila);
void liberaListaHistorico(ListaHistorico* l);

void liberaFilaListaDevolucao(FilaListaDevolucao* fila);
void liberaListaDevolucao(ListaDevolucao* l);
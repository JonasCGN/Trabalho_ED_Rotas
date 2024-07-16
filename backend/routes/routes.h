#pragma once

void cadastroPedido(Pedido* pedido,ListaEntrega **entregas);
void exibirEntregas(ListaEntrega *entregas);

void removeFila(ListaEntrega **entregas);
void segundaRota(ListaEntrega **entregas,ListaSegundaEntrega **entregaNE);

void removeSegundaEntrega(ListaSegundaEntrega **entregaNE);
void adicionaSegundaEntrega(Pedido *pedido,ListaSegundaEntrega **entregaNE);

void entregaNEPilha(ListaSegundaEntrega **entregasNE);
void adicionaDevolucao(Pedido *pedido,FilaListaDevolucao **devolucao);
void segundaEntregaDevolucao(ListaSegundaEntrega **entregasNE,FilaListaDevolucao **devolucao);
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
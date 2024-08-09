#pragma once

#include "../estrutura/estrutura.h"

void exibirPedido(Pedido *pedido);

void mostrarClientes(ListaCliente *listacliente);
void exibirClientes( ListaCliente *cliente);
void exibirInfoCliente(Cliente *cliente);


void exibirInfoRota(Rota *rota);
void exibirRotas(ListaRota *listaRota);
void exibirPedidosDeRotas(ListaRota *listaRota);

void exibirEntrega(ListaEntrega *entregas);
void mostrarPedidos(ListaPedido *lista);

void exibirSegundaEntrega(PilhaSegundaEntrega *listasegunda);
void exibirDevolucao(ListaDevolucao *listaDevolucao);

void exibirHistorico(ListaHistorico *listahistorico);

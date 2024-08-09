#pragma once

#include "../estrutura/estrutura.h"

void exibirPedido(Pedido *pedido);
void exibirClientes( ListaCliente *cliente);
void exibirInfoCliente(Cliente *cliente);

void exibirInfoRota(Rota *rota);
void exibirRotas(ListaRota *listaRota);
void exibirPedidosDeRotas(ListaRota *listaRota);

void exibirEntrega(ListaEntrega *entregas);
void mostrarPedidos(ListaPedido *lista);
void exibirHistorico(ListaHistorico *listahistorico);


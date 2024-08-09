#pragma once

#include "../estrutura/estrutura.h"

void adicionaPedido(ListaPedido **listaPedido, Pedido *pedido);
Pedido* cadastrarPedido(ListaPedido **listaPedido, ListaCliente *listaCliente);
void pedidoId(ListaPedido *listapedido,int id);

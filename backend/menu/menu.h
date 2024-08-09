#pragma once

#include "../estrutura/estrutura.h"

void telaInicial();
void menuCliente(ListaCliente **listacliente);
void menuPedido(FilaListaPedido **listaPedido, ListaCliente *listaCliente);
void menuRota(FilaListaRota **rota,FilaListaPedido *listaPedido);
void menuEntrega(Rota **rota);
#pragma once
#ifndef CLIENTE_H 
#define CLIENTE_H

#include "../estrutura/estrutura.h"

Cliente *cadastro();

void cadastroCliente(ListaCliente **listaCliente);
Cliente* verificaCliente(ListaCliente *listacliente,int id);
void procurarcliente(ListaCliente *cliente, int id);
void editarcliente(ListaCliente *cliente, int id);
void excluircliente(ListaCliente **cliente, int id);

#endif
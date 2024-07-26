#pragma once
#ifndef CLIENTE_H 
#define CLIENTE_H

typedef struct{
    int id_cliente;
    char nome[50];
    char cpf[15];
    char telefone[15];
    char email[50];
    char endereco[100];
}Cliente;

typedef struct listaCliente {  
    Cliente cliente;
    struct listaCliente *prox;
}ListaCliente;  

typedef struct filalistacLiente{
    ListaCliente *ini;
    ListaCliente *fim;
}FilaListaCLiente;

ListaCliente *criaListaCliente();
Cliente *cadastro();
int menu();
void cadastroCliente(FilaListaCLiente *filalistaclientes);
void exibirClientes( ListaCliente *cliente);
void Procurarcliente(ListaCliente *cliente, int id);
void editarcliente(ListaCliente *cliente, int id);
void excluircliente(ListaCliente **cliente, int id);
void liberar_clientes (ListaCliente **Cliente);
#endif
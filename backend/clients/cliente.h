#pragma once
#ifndef CLIENTE_H 
#define CLIENTE_H

typedef struct{
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
    ListaCLiente *ini;
    ListaCLiente *fim;
}FilaListaCLiente;

ListaCLiente *criaListaCliente();
Cliente *cadastro();
void cadastroCliente(ListaCliente **lista);
void exibirClientes( ListaCliente **cliente);
void Procurarcliente(ListaCliente **cliente);
void editarcliente(ListaCliente **cliente);
void excluircliente(ListaCliente **cliente);

#endif
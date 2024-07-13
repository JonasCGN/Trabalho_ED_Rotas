#pragma once

typedef struct{
    char nome[50];
    char cpf[15];
    char telefone[15];
    char email[50];
    char endereco[100];
}Cliente;

typedef struct listaCLiente{
    Cliente cliente;
    struct listaCliente *prox;
}ListaCLiente;

ListaCLiente *criaListaCliente();
Cliente *cadastro();
void cadastroCliente(ListaCLiente **cliente);
void exibirClientes(ListaCLiente **cliente);
void Procurarcliente(ListaCLiente **cliente);
void editarcliente(ListaCLiente **cliente);
void excluircliente(ListaCLiente **cliente);
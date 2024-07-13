#pragma once

typedef struct pedido{
    int id_cliente;
    char item[50];
    int quantidade;
    float valor;
}Pedido;

typedef struct listentrega{
    Pedido pedido;
    struct listentrega *prox;
}ListaEntrega;

typedef struct listaentregane{
    Pedido pedido;
    struct listaentregane *prox;
}ListaEntregaNaoEfetuada;

typedef struct listadevolucao{
    Pedido pedido;
    struct listadevolucao *prox;
}ListaDevolucao;

typedef struct routes{
    int score;
};

ListaEntrega criaListaEntrega();
void cadastroPedido(ListaEntrega **entregas);
void exibirPedidos(ListaEntrega *entregas);

void removeFila(ListaEntrega **entregas);
void segundaRota(ListaEntrega **entregas,ListaEntregaNaoEfetuada **entregNE);

void entregaNEPilha(ListaEntregaNaoEfetuada **entregas);
void entregaNEDevolucao(ListaEntregaNaoEfetuada **entregas,ListaDevolucao **devolucao);

void entregaNEfetuada(ListaDevolucao **pedidos);


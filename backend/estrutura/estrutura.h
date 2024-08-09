#pragma once

typedef struct pedido{
    int id_cliente;
    int id_pedido;
    char item[20];
    int quantidade;
    float valor;
    /*
        0 - Pendente
        1 - Preparando Entrega
        2 - Entregue
        3 - Segunda Tentativa
        4 - Processo de Devolução
        5 - Devolução Concluida
    */
    int status;
    int id_rota;
}Pedido;

typedef struct listaPedido{
    Pedido *pedido;
    struct listaPedido *prox;
}ListaPedido;

typedef struct filaListaPedido{
    ListaPedido *ini;
    ListaPedido *fim;
}FilaListaPedido;

typedef struct listaentrega{
    Pedido* pedido;
    struct listaentrega *prox;
}ListaEntrega;

typedef struct filaListentrega{
    ListaEntrega *ini;
    ListaEntrega *fim;
}FilaListaEntrega;

typedef struct pilhaSegundaEntrega{
    Pedido* pedido;
    struct pilhaSegundaEntrega *prox;
}PilhaSegundaEntrega;

typedef struct listadevolucao{
    Pedido *pedido;
    struct listadevolucao *prox;
}ListaDevolucao;

typedef struct filalistadevolucao{
    ListaDevolucao *ini;
    ListaDevolucao *fim;
}FilaListaDevolucao;

typedef struct listaHistorico{
    Pedido *pedido;
    struct listaHistorico *prox;
}ListaHistorico;

typedef struct rota{
    int id_rota;
    int score;
    FilaListaEntrega *entrega;
    PilhaSegundaEntrega *segundaEntrega;
    FilaListaDevolucao *devolucao;
    ListaHistorico *historico;
}Rota;

typedef struct listaRota{
    Rota *rota;
    struct listaRota *prox;
}ListaRota;

typedef struct filaListaRota{
    ListaRota *ini;
    ListaRota *fim;
}FilaListaRota;

typedef struct{
    int id_cliente;
    char nome[50];
    char cpf[15];
    char telefone[15];
    char email[50];
    char endereco[100];
}Cliente;

typedef struct listaCliente {  
    Cliente *cliente;
    struct listaCliente *prox;
}ListaCliente;  

#pragma once

typedef struct pedido{
    int id_cliente;
    char item[20];
    int quantidade;
    float valor;
    int status;
    /*
        0 - Pendente
        1 - Entregue
        2 - Segunda Tentativa
        3 - Processo de Devolução
        4 - Devolução Concluida
    */
}Pedido;

typedef struct listentrega{
    Pedido* pedido;
    struct listentrega *prox;
}ListaEntrega;

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

typedef struct listahistorico{
    Pedido* pedido;
    struct listahistorico *prox;
}ListaHistorico;

typedef struct filalistahistorico{
    ListaHistorico *ini;
    ListaHistorico *fim;
}FilaListaHistorico;

typedef struct rota{
    int id_rota;
    int score;
}Rota;

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
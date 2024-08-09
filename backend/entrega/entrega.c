#include <stdio.h>
#include <stdlib.h>

#include "../pedidos/pedidos.h"
#include "../cria_libera/cria_libera.h"
#include "entrega.h"

int processoEntrega(FilaListaEntrega *listaEntrega, PilhaSegundaEntrega *segundaEntrega, FilaListaDevolucao *devolucao){

	if(listaEntrega != NULL || segundaEntrega != NULL || devolucao != NULL)
		return 1;

	return 0;
}

void pedidoFilaEntrega(Pedido *pedido, FilaListaEntrega **entregas){
	ListaEntrega *novo;
	novo = (ListaEntrega*)malloc(sizeof(ListaEntrega));
	if(!novo){
		printf("Nao foi possivel alocar para devolucao\n");
		exit(1);
	}

	novo->pedido = pedido;
	novo->prox = NULL;

	if(entregaVazio(*entregas)){

		FilaListaEntrega *aux = (FilaListaEntrega*)malloc(sizeof(FilaListaEntrega));

		aux->fim = novo;
		aux->ini = novo;

		*entregas = aux;

		return;
	}

	(*entregas)->fim->prox = novo;
	(*entregas)->fim = novo;

}

void removeFilaEntrega(FilaListaEntrega **entregas){
	if(*entregas != NULL){
		ListaEntrega *aux = (*entregas)->ini;

		if(aux->prox == NULL){
			(*entregas) = NULL;
		}else{
			(*entregas)->ini = aux->prox;
		}
	}
}

void removeSegundaEntrega(PilhaSegundaEntrega **entregaNE){
	PilhaSegundaEntrega *aux = *entregaNE;

	if(*entregaNE != NULL){
		*entregaNE = aux->prox;
	}else{
		printf("Entrega vazia\n");
	}

}

void adicionaSegundaEntrega(Pedido *pedido,PilhaSegundaEntrega **entregaNE){
	PilhaSegundaEntrega *aux;
	aux = (PilhaSegundaEntrega*)malloc(sizeof(PilhaSegundaEntrega));
	if(!aux){
		printf("Nao foi possivel alocar para entrega\n");
		exit(1);
	}

	if((*entregaNE) == NULL){
		
		aux->pedido = pedido;
		aux->prox = NULL;

		(*entregaNE) = aux;

		return;
	}

	aux->pedido = pedido;
	aux->prox = (*entregaNE);

	(*entregaNE) = aux;
}

void adicionaDevolucao(Pedido *pedido,FilaListaDevolucao **devolucao){
	ListaDevolucao *novo;
	novo = (ListaDevolucao*)malloc(sizeof(ListaDevolucao));
	if(!novo){
		printf("Nao foi possivel alocar para devolucao\n");
		exit(1);
	}

	novo->pedido = pedido;
	novo->prox = NULL;

	if(devolucaoVazio(*devolucao)){

		FilaListaDevolucao *aux = (FilaListaDevolucao*)malloc(sizeof(FilaListaDevolucao));

		aux->fim = novo;
		aux->ini = novo;

		*devolucao = aux;

		return;
	}

	(*devolucao)->fim->prox = novo;
	(*devolucao)->fim = novo;
}

/*Remove uma entrega da devolução*/
void removeDevolucao(FilaListaDevolucao** devolucao){
	if(*devolucao != NULL){
		ListaDevolucao *aux = (*devolucao)->ini;

		if(aux->prox == NULL){
			(*devolucao) = NULL;
		}else{
			(*devolucao)->ini = aux->prox;
		}
	}
}

void primeiraEntrega(FilaListaEntrega **entrega){
	if(*entrega != NULL){
		(*entrega)->ini->pedido->status = 2;
		removeFilaEntrega(entrega);
		printf("Pedido entregado com sucesso!");
	}else{
		printf("Nao ha pedidos para serem entregados\n");
	}
}

void segundaRota(FilaListaEntrega **entrega,PilhaSegundaEntrega **entregaNE){
	if(*entrega != NULL){
		(*entrega)->ini->pedido->status = 3;

		adicionaSegundaEntrega((*entrega)->ini->pedido,entregaNE);
		removeFilaEntrega(entrega);
	
	}else{
		printf("Nao ha pedidos para serem entregados\n");
	}
}

void entregaNEPilha(PilhaSegundaEntrega **entregaNE){
	if(*entregaNE != NULL){
		
		(*entregaNE)->pedido->status = 3;
		removeSegundaEntrega(entregaNE);

	}else{
		printf("Nao ha pedidos para serem entregadoss\n");
	}
}

void segundaEntregaDevolucao(PilhaSegundaEntrega **entregaNE,FilaListaDevolucao **devolucao){
	if(*entregaNE != NULL){
		(*entregaNE)->pedido->status = 4;
		adicionaDevolucao((*entregaNE)->pedido,devolucao);
		removeSegundaEntrega(entregaNE);
	}else{
		printf("Nao ha pedidos para serem entregados\n");
	}
}

void processoDevolucao(FilaListaDevolucao **devolucao){
	if(*devolucao != NULL){
		(*devolucao)->ini->pedido->status = 5;
		removeDevolucao(devolucao);
		
		printf("Pedido devolvido com sucesso!");
	}else{
		printf("Nao ha pedidos para serem devolvidos\n");
	}
}
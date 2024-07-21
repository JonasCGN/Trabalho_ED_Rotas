#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

#include "cliente.h"
static int proxid = 1;
ListaCliente *criaListaCliente(){
    return NULL;
}
Cliente *cadastro(){
    Cliente *novocliente = (Cliente *)malloc(sizeof(Cliente));
    if (novocliente == NULL){
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!!!");
        exit(1);
    }

    novocliente->id_cliente = proxid++;
    
    int valido;
    do{
        valido = 1;
        printf("Nome: ");
        fgets(novocliente->nome, 50, stdin);
        novocliente->nome[strcspn(novocliente->nome, "\n")] = '\0';// remove o /n 

        for (int i = 0; novocliente->nome[i] != '\0'; i++){
            if (!isalpha(novocliente->nome[i])  && novocliente->nome[i] != ' '){
                printf("Nome invalido, digite novamente.\n");
                valido = 0;
                break;
            }
        }
    }while(!valido);

    do{
        valido = 1;
        printf("CPF: ");
        fgets(novocliente->cpf, 11, stdin);
        novocliente->cpf[strcspn(novocliente->cpf, "\n")] = '\0'; 

        if (strlen(novocliente->cpf) != 11){
            printf("CPF invalido, digite novamente.\n");
            valido = 0;
        }else{
            for (int i = 0; novocliente->cpf[i] != '\0'; i++){
                if (!isdigit(novocliente->cpf[i])){
                    printf("CPF invalido, digite novamente.\n");
                    valido = 0;
                    break;
                }
            }
        }
        
    }while(!valido);
    
   do{
        valido = 1;
        printf("Telefone: ");
        fgets(novocliente->telefone, 15, stdin);
        novocliente->telefone[strcspn(novocliente->telefone, "\n")] = '\0';// remove o /n 

        if (strlen(novocliente->telefone)> 15){
            printf("Telefone invalido, digite novamente.\n");
            valido = 0;
        }else{
            for (int i = 0; novocliente->telefone[i] != '\0'; i++){
                if (!isdigit(novocliente->telefone[i])){
                    printf("Telefone invalido, digite novamente.\n");
                    valido = 0;
                    break;
                }
            }
        }
        
   }while(!valido);

   do{
        valido = 1;
        printf("Email: ");
        fgets(novocliente->email, 50, stdin);
        novocliente->email[strcspn(novocliente->email, "\n")] = '\0';// remove o /n 

        for (int i = 0; novocliente->email[i] != '\0'; i++){
            if (isspace(novocliente->email[i])){
                valido = 1;
                break;
            }else{
                printf("Email invalido, digite novamente.\n");
                valido = 0;
                break;
            }
        }
        
   }while(!valido);

    
    printf("Endereco: ");
    fgets(novocliente->endereco, 100, stdin);
    novocliente->endereco[strcspn(novocliente->endereco, "\n")] = '\0';// remove o /n 
    
    return novocliente;

    
}
void cadastroCliente(FilaListaCLiente *filalistaclientes){
    Cliente *novo = cadastro();
    ListaCliente *novoNO = (ListaCliente *) malloc(sizeof(ListaCliente));
    if(!novoNO){
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!!!");
        exit(1);
    }
    
    novoNO->cliente = *novo;// copia as informações do cliente para o novo nó
    novoNO->prox = NULL;// Define proximo nó como NUll
    
    // se a lista estiver vazia add no inicio 
    if (filalistaclientes->ini == NULL){
        filalistaclientes->ini = novoNO;
        filalistaclientes->fim = novoNO;

    }else{// adiciona o novo nó no fim 
       filalistaclientes->fim->prox = novoNO;
       filalistaclientes->fim = novoNO;
    } 
    free(novo);
}
void exibirClientes(ListaCliente *cliente){
    if (cliente == NULL) {
        return;
    }

    printf("ID %d\n", cliente->cliente.id_cliente);
    printf("Nome: %s\n", cliente->cliente.nome);
    printf("CPF: %s\n", cliente->cliente.cpf);
    printf("Telefone: %s\n", cliente->cliente.telefone);
    printf("Email: %s\n", cliente->cliente.email);
    printf("Endereco: %s\n", cliente->cliente.endereco);
    printf("\n");

    exibirClientes(cliente->prox);
}
void Procurarcliente(ListaCliente *cliente, int id){
    ListaCliente *atual = cliente;
    int  encontrado = 0;
    while ( atual!= NULL){
        if (atual->cliente.id_cliente == id){
            printf("Cliente encontrado :\n");
            printf("ID %d\n", atual->cliente.id_cliente);
            printf("Nome: %s\n", atual->cliente.nome);
            printf("CPF: %s\n", atual->cliente.cpf);
            printf("Telefone: %s\n", atual->cliente.telefone);
            printf("Email: %s\n", atual->cliente.email);
            printf("Endereco: %s\n", atual->cliente.endereco);
            return;
        }
        atual = atual->prox;
        printf("Cliente  não encontrado :\n");
    }
    

}
void editarcliente(ListaCliente *cliente, int id){
    // aprimorar depois essa desgraça 
    ListaCliente *atual = cliente;
    int encontrado = 0;
    while (atual != NULL){
        if (atual->cliente.id_cliente == id){
            printf (" Editar cliente com ID %d: \n", id);
    
            int valido;
            do{
                valido = 1;
                printf("Nome: ");
                fgets(atual->cliente.nome, 50, stdin);
                atual->cliente.nome[strcspn(atual->cliente.nome, "\n")] = '\0';// remove o /n 

                for (int i = 0; atual->cliente.nome[i] != '\0'; i++){
                    if (!isalpha(atual->cliente.nome[i])  && atual->cliente.nome[i] != ' '){
                        printf("Nome invalido, digite novamente.\n");
                        valido = 0;
                        break;
                    }
                }
            }while(!valido);

            printf("Novo CPF: ");
            fgets(atual->cliente.cpf, 15, stdin);
            atual->cliente.cpf[strcspn(atual->cliente.cpf, "\n")] = '\0';// remove o /n 

            printf("Novo Telefone: ");
            fgets(atual->cliente.telefone, 15, stdin);
            atual->cliente.telefone[strcspn(atual->cliente.telefone, "\n")] = '\0';// remove o /n 

            printf("Novo Email: ");
            fgets(atual->cliente.email, 50, stdin);
            atual->cliente.email[strcspn(atual->cliente.email, "\n")] = '\0';// remove o /n 

            printf("Novo Endereco: ");
            fgets(atual->cliente.endereco, 100, stdin);
            atual->cliente.endereco[strcspn(atual->cliente.endereco, "\n")] = '\0';// remove o /n 
            
            printf(" Cliente editado com sucesso\n");
            encontrado = 1; 
        }
        atual = atual->prox;
        if (!encontrado){
            printf(" Cliente com Id %d nao encontrado. \n ", id);
        }
        
    }
   

}
void excluircliente(ListaCliente **cliente, int id ){
   // printf("Excluir cliente com ID %d\n", id);
    ListaCliente *atual = *cliente;
    ListaCliente *anterior = NULL;
  
    while (atual != NULL){
        if (atual->cliente.id_cliente == id){
            if (anterior == NULL){
               *cliente = atual->prox; 
                free(atual);
                return;
            }else{
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Cliente com Id %d excluido com sucesso.\n", id);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Cliente com Id %d nao encontrado.\n", id);
}
void liberar_clientes (ListaCliente **Cliente){
    ListaCliente *atual = *Cliente;
    ListaCliente *proximo;

    while (atual != NULL){

        proximo = atual->prox;
        free(atual);
        atual = proximo;

    }
    *Cliente = NULL;
    
}
int menu(){
    int op;
    printf("\n----- MENU -----\n");
    printf("1. Cadastrar cliente\n");
    printf("2. Exibir todos os clientes \n");
    printf("3. Procurar cliente por ID\n");
    printf("4. Editar cliente por ID\n");
    printf("5. Excluir cliente por ID\n");
    printf("6. sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    getchar();
    return op;
}

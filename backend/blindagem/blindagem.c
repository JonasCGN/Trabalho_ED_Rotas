#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

#include "blindagem.h"

/*
0-
1-Verifica CPF
2-Verifica RG
3-Verifica Numero de telefone
*/
void verifica_n_int(char *v,int vC){
    int i=0;
    char c;
    do{
        c = getch();

        if(c >= '0' && c <= '9'){
            printf("%c", c);
            *(v+i) = c;
            i++;
        }else if(c == 8 && i >= 1){
            *(v+i) = '\0';
            printf("\b \b");
            i--;
        }

        if(c == 13 && (i < 11 || i > 11) && vC == 1){
            printf("\nCPF Invalido:");
            i=0;
            c=14;
        }else if(c == 13 && (i < 11 || i > 11) && vC == 2){
            printf("\nRG Invalido:");
            i=0;
            c=14;
        }else if(c == 13 && (i < 11 || i > 11) && vC == 3){
            printf("\nNumero Invalido:");
            i=0;
            c=14;
        }

    }while(c != 13);

    *(v+i) = '\0';

}

void verifica_n_float(char *v){
    int i=0,cont = 0;
    char c;
    for(int j=0;j<10;j++){
        *(v+j) = '\0';
    }
    do{
        
        c = getch();

        if((c >= '0' && c <= '9') || c == '.'){
            if((c == '.' && cont == 0) && i != 0){
                printf("%c", c);
                *(v+i) = c;
                i++;
                cont = 1;
            }else if((c >= '0' && c <= '9')){
                printf("%c", c);
                *(v+i) = c;
                i++;
            }
        }else if(c == 8 && i >= 1){
            if(*(v+i-1) == '.'){
                cont=0;
            }

            *(v+i) = '\0';
            printf("\b \b");
            i--;
        }else if(c == 13 && *(v+i-1) == '.'){
            c = 14;
        }
        if(i==0){
            c=14;
        }

    }while(c != 13);
}

/*
0 -
1 - Nome
*/
void verifica_letra(char *v,int opc,int tam){
    char c;
    int i=0;

	for(int j=0;j < 50 ;j++){
		*(v+j) = '\0';
	}

    do{
        c = getch();

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')){
            printf("%c", c);
            *(v+i) = c;
            i++;
        }else if(c == 8 && i >= 1){
            *(v+i) = '\0';
            printf("\b \b");
            i--;
        }else if(i == 0){
            c = 14;
        }else if(*(v + i - 1) == ' '){
            c = 14;
        }
    }while(c != 13);
    *(v+i) = '\0';
}

void limparTela(){
    printf("\n");
    printf("Pressione qualquer tecla para continuar");
    getchar();
    system("cls||clear");
}

char recebeUmNumero(char v){
    char temp;
    do{
        temp = getch();

        if(temp >= '0' && temp <= '9'){
            v = temp;
            printf("%c",v);
        }

    }while(!(temp >= '0' && temp <= '9'));

    return v;
}
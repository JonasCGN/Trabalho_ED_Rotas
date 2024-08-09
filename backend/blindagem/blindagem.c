#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

#include "blindagem.h"

void verifica_n_int(char *v, int min, int max) {
    int i = 0;
    char c;

    do {
        c = getch();

        if (c >= '0' && c <= '9' && i < max) { 
            printf("%c", c);

            v[i] = c;
            i++;
        } else if (c == 8 && i >= 1) {
            i--; 
            v[i] = '\0';
            printf("\b \b");
        }

        if (c == 13 && i < min) { 
            c = 14;
        }
    } while (c != 13);

    v[i] = '\0';
}

int numero(int min,int max){
    char *v = (char*)calloc(max + 1,sizeof(char));
    if(!v){
        printf("Erro ao aolcoar memoria do numero\n");
        return 1;
    }

    verifica_n_int(v,min,max);

    int num = atoi(v);
    free(v);

    return num;
}

float verifica_n_float(int max){
    int i=0,cont = 0;
    char c;
    
    char *v = (char*)calloc(10,sizeof(char));
    if(!v){
        printf("Erro ao alocar memoria\n");
        return 10.0;
    }

    do{
        
        c = getch();

        if(((c >= '0' && c <= '9') || c == '.') && i < max){
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

        if(i > max){
            c = 14;
        }

    }while(c != 13);

    *(v+i) = '\0';

    float num = atof(v);
    free(v);

    return num;
}

void verifica_letra(char *v,int tam){
    char c;
    int i=0;

	for(int j=0;j < 50 ;j++){
		*(v+j) = '\0';
	}

    do{
        c = getch();

        if(((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')) && i < tam){
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

int verifica_email(char *v){
    int n=strlen(v);
    for(int i=0;i<n;i++){
        if(*(v+i) == ' '){
            return 0;
        }
    }
    return 1;
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
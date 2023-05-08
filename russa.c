
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct carro{
    int reg_carro;
    char tipo;
    char status;
}carro;

typedef struct cliente{
    int num_reg;
    char nome[80];
    char cpf[13];
    int dias;
}cliente;

void aloca_cliente(cliente **pcl, int tam);
void aloca_carro(carro **pcar, int tam);
void cadastra_carro(carro *pcar, int tam);
void cadastra_cliente(cliente *pcl, carro *pcar, int tam);
int busca_carro(carro *pcar, int tam, char tipocar);
void mostra_carro(carro *pcar, int tam);

main()
{
    carro *pcar = NULL;
    cliente *pcl = NULL;
    int op, cont=0;

    aloca_carro(&pcar, 15);
    cadastra_carro(pcar, 15);

    do 
{
    system("cls");
    printf("[1]locacao: \n[2]Devolucao: \n[3]Fim:\n ");
    scanf("%i", &op);
    fflush(stdin);

        switch(op)
		{
            case 1:
            mostra_carro(pcar, 15);
            aloca_cliente(&pcl, cont+1);//cont + 1 vai somar só no aloca, kd vez q passa incrementa um cliente
            cadastra_cliente(pcl+cont, pcar, 15); //kd vez q passa incrementa um cliente
            cont++;//por conta q cont+1 soma só no aloca, temos q incrementar o contador geral para usar nas outras funcoes
        break;

     case 2:
        break;

		}
 

}while (op!=3);

}//main

void aloca_cliente(cliente **pcl, int tam)
{
    if((*pcl=(cliente*)realloc(*pcl, tam*sizeof(cliente)))==NULL)
    exit(1);
}//aloca_cliente

void aloca_carro(carro **pcar, int 
tam)
{
    if((*pcar=(carro*)realloc(*pcar, tam*sizeof(carro)))==NULL)
    exit(1);
}//aloca carro

void cadastra_cliente(cliente *pcl, carro *pcar, int tam)
{
    int i;
    char tipocar;
    printf("\n\nDigite seu nome: ");
    gets(pcl->nome);
    fflush(stdin);
    printf("\nDigite seu cpf: ");
    gets(pcl->cpf);
    fflush(stdin);
    printf("\nDigite o numero de dias de reserva com o carro: ");
    scanf("%i", &pcl->dias);

    printf("\n[G] para carro grande: \n[M] para carro medio: \n [P] para carro pequeno: ");
    scanf("%c", &tipocar);
    fflush(stdin);
    busca_carro(pcar, 15, tipocar);//chamando a funcao busca carro dentro do cadastra cliente, quando o cliente escolher o tipo de carro, sera feito uma busca pra ver se o tipo de carro q o cliente escolheu esta disponivel

}//cadastro_cliente

void cadastra_carro(carro *pcar, int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        (pcar+i)->reg_carro = i+1;

        if(i<5)
        {
            (pcar+i)->tipo = 'p';
        }

        else if(i>=5 && i<=10)
        {
            (pcar+i)->tipo = 'm';
        }

        else
        {
            (pcar+i)->tipo = 'g';
        }
            (pcar+i)->status = 'l';

    }//for

}//cadastra_carro

int busca_carro(carro *pcar, int tam, char tipocar)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if((pcar+i)->tipo == tipocar && (pcar+i)->status == 'l')
        {
            (pcar+i)->status = 'a';
            return (pcar+i)->reg_carro;
        }
    }
    return -1;
}//busca carro

void mostra_carro(carro *pcar, int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("\nCarro: %i , Tipo: %c , Status: %c", (pcar+i)->reg_carro, pcar->tipo, pcar->status);

    }
}//mostra carro
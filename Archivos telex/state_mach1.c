/****************************************************************
 *								*
 * Archivo:	state_mach1.c					*
 * Descripcion: Codigo Fuente para implementar el programa	*
 *		de maquina de estados.			 	*
 *								*
 ****************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tables.h"


/*************** PROTOTIPOS DE FUNCION ***************/ 
void initialise(void *datos);
void getevent(void *datos);

int AlmacenaC(void *datos);
int Procesa(void *datos);
int AlmacenaNC(void *datos);
int nul(void *datos);


/*************** FUNCION PRINCIPAL ***************/ 
int main(int argc, char **argv)
{
    // Variables de la máquina de estados
    EVENT event;

    int actx, auxx, outcome;

    initialise(&event);
    
    while (1) {    /* loop infinito para la MFE */
        getevent(&event);

        for ((actx = state_table[event.state].start);(action_table[actx].event != event.etype) && (actx < state_table[event.state].end);actx++)
            ;
        outcome = (*(action_table[actx].action))(&event);
            if(action_table[actx].moreacts == -1)
	      event.state = action_table[actx].nextstate;
            else {
                auxx = action_table[actx].moreacts + outcome;
                while (auxx != -1){
                    outcome = (*(aux_table[auxx].action))(&event);
                    if (aux_table[auxx].moreacts == -1 ){
                        event.state = aux_table[auxx].nextstate;
                        auxx = -1;
                    }
                    else
                        auxx = aux_table[auxx].moreacts + outcome;
                
                }
        }
        
    } /* while(1) */
}

void initialise(void *datos)
{
    EVENT *event = (EVENT *) datos;

    event->state = 0;

   //valores iniciales de nuestros campos
    event->mensaje[0]='\0';
    event->pos=0;
}


void getevent(void *datos)
{
    EVENT *event = (EVENT *) datos;
    char *ptmp;
    char buf[BUFFER];
    
#ifdef DEBUG
    printf("wait event \n");
#endif
    __fpurge(stdin);
    gets(event->buf);
    //scanf("%[^\n]s",event->buf);

    strcpy(buf, event->buf);
    ptmp = &buf[2];
    
    switch (event->buf[0])
        {
       case 'Z' :
             event->etype=ENTRADA_Z;
             break;
        case 'N' :
             event->etype=ENTRADA_N;
             break;
        case 'z' :
             event->etype=ENTRADA_z;
             break;
        case 'C' :
             event->etype=ENTRADA_C;
             break;
        case 'n' :
             event->etype=ENTRADA_n;
             break;
    #ifdef DEBUG
          printf("---> %s \n",event->args);
    #endif
           default:
                event->etype=ENT_Ast;
                break;
        }//switch
}// getevent
 

/* FUNCIONES DE IMPLEMENTACION */

int AlmacenaC(void *datos)
{
  EVENT *info = (EVENT *)datos;
  
  info->mensaje[info->pos] = info->buf[0];
  info->pos = info->pos + 1;
}//funcion1

int AlmacenaNC(void *datos)
{
  EVENT *info = (EVENT *)datos;
  
  info->mensaje[info->pos] = 'N';
  info->pos = info->pos + 1;
  info->mensaje[info->pos] = info->buf[0];
  info->pos = info->pos + 1;

}//funcion2

int Procesa(void *datos)
{
  EVENT *info = (EVENT *)datos;
  
  info->mensaje[info->pos] = '\0';
  printf("El mensaje es: %s\n",info->mensaje);
  info->mensaje[0] = 0;
  info->pos = 0;
}//funcion3


int nul(void *datos)
{
	
}//nul

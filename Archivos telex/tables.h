
/************************************************************************
 *								        *
 * Archivo:	tables.h						*
 * Descripcion: Tablas para la maquina de estados y funciones externas	*
 *		Aqui se definen todos las tablas que se utilizan        *
 *		en el programa						*
 *								        *
 ************************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include "local.h"
#include <stdio.h>


/*************** FUNCIONES EXTERNAS *********************
 * En esta seccion se declaran los encabezados de 	    *
 * todas las funciones que se utilizan en las     	    *
 * tablas del programa. Todas las funciones deben 	    *
 * ser de tipo entero y no deben recibir parametros	    *
 ********************************************************/ 
extern int AlmacenaC(void *datos);
extern int Procesa(void *datos);
extern int AlmacenaNC(void *datos);
extern int nul(void *datos);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas       *
 * que se van a usar en el programa	        *
 ************************************************/ 
 
/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
        /*etype    accion    bandera   sigEdo. */    
    { ENTRADA_Z,    nul,   	-1,   ESTADO_Inicio},
    { ENT_Ast,      nul,	-1,   ESTADO_Libre},
    { ENTRADA_N,    nul,	-1,   ESTADO_Fin},
    { ENT_Ast,      AlmacenaC,	-1,   ESTADO_Mensaje},
    { ENTRADA_z,    nul,   	-1,   ESTADO_Inicio},
    { ENTRADA_C,    nul,	-1,   ESTADO_Mensaje},
    { ENT_Ast,      nul,	-1,   ESTADO_Libre},
    { ENTRADA_n,    Procesa,	-1,   ESTADO_Libre},
    { ENT_Ast,      AlmacenaNC, -1,   ESTADO_Mensaje}

};

/*************** TABLA AUXILIAR ***************/  
    AUX_TAB aux_table[]={        
/*    accion       bandera           sigEdo */
    { nul,          -1,          ESTADO_Libre},
    { nul,	    -1,          ESTADO_Libre}
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
   /*estado      inicio   fin */
    {ESTADO_Libre,     0,      1},
    {ESTADO_Mensaje,   2,      3},
    {ESTADO_Inicio,    4,      6},
    {ESTADO_Fin,       7,      8}

};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        

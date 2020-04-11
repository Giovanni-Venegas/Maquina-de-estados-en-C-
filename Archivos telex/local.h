/****************************************************************
 *								*
 * Archivo:	local.h						*
 * Descripcion: Archivo de encabezado para maquina de estados	*
 *		Aqui se definen todos los tipos de datos y 	            *
 *		constantes que se utilizan en el programa	            *
 *								                          *
 ****************************************************************/

/******************* CONSTANTES *******************
 * En esta seccion se declaran todas las 	      *
 * las constantes que se necesiten en el programa *
 **************************************************/ 
#define BUFFER        128
#define L_EVENT_ARGS  21


/****************** ESTRUCTURAS *****************
 * En esta seccion se declaran todas las	    *
 * estructuras que se necesiten en el programa	*
 ************************************************/ 

// Este tipo de datos se utiliza para leer la informacion
// que teclea el usuario 
struct event_s
{
    int etype;
    char args[L_EVENT_ARGS];
    int state;
    char buf[BUFFER];
    char mensaje[200];  // campo nuestro para manejar la info ingresada
    int pos;  // campo nuestro para la posicion del caracter introducido
};
typedef struct event_s EVENT;

// Este tipo de datos se utiliza para implementar 
// la tabla auxiliar
struct aux_table_s 
{
    int (*action)(void *datos);
    int moreacts;
    int nextstate;
};
typedef struct aux_table_s AUX_TAB;

// Este tipo de datos se utiliza para implementar
// la tabla de accion
struct action_tab_s 
{
    int event;
    int (*action)(void *datos);
    int moreacts;
    int nextstate;
};
typedef struct action_tab_s ACTION_TAB;

// Este tipo de datos se utiliza para implementar
// la tabla de estados
struct state_tab_s 
{
    int state;
    int start;
    int end;
};
typedef struct state_tab_s STATE_TAB;


/********************* EVENTOS *******************
 * En esta seccion se declaran como constantes	 *
 * los eventos (entradas) que recibe el programa *
 *************************************************/ 
#define ENTRADA_Z   0
#define ENTRADA_N   2
#define ENTRADA_z   4
#define ENTRADA_C   5
#define ENTRADA_n   7
#define ENT_Ast    -1

/********************* ESTADOS ******************
 * En esta seccion se declaran como constantes	*
 * los estados de que consta el programa 	    *
 ************************************************/ 
#define ESTADO_Libre     0
#define ESTADO_Mensaje   1
#define ESTADO_Inicio    2
#define ESTADO_Fin       3







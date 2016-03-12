#ifndef _OBJET_H_
#define _OBJET_H_

#include <commun.h>

/*
 * DEFINITION OBJET
 */

typedef struct objet_s objet_t ;

struct objet_s
{
	void (*afficher)(objet_t *);
	err_t (*detruire)(objet_t **);
} ;

#endif

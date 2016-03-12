#ifndef _LISTE_OBJET_H_
#define _LISTE_OBJET_H_


#include <commun.h>
#include <objet.h>

#define LISTE_OBJET_NULL NULL
#define LISTE_OBJET_ID_NULL -1

/*
 * DEFINITION OBJET
 */

typedef struct liste_objet_s
{
	/* Méthodes */

	booleen_t (*vide)(struct liste_objet_s * const);
	err_t (*elem_ecrire)(struct liste_objet_s *, objet_t * const, const int);
	err_t (*detruire)(struct liste_objet_s **);
	void (*afficher)(struct liste_objet_s * const, const char);

	/* Champs */
	int nb;
	objet_t ** liste;
} liste_objet_t;

extern unsigned long int liste_objet_cpt  ;

extern booleen_t liste_objet_existe( liste_objet_t * const liste) ;


extern liste_objet_t * liste_objet_creer( const int nb);


#endif

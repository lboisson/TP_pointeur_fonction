#ifndef _PERSONNE_H_
#define _PERSONNE_H_

#include <objet.h>


/*
 * DEFINITION OBJET "PERSONNE"
 */

typedef struct personne_s
{
	void (*afficher)(struct personne_s * const);
	err_t (*detruire)(struct personne_s **);
	char * nom ;
	char * prenom ;
} personne_t ;

/*
 * VARIABLE LOCALE
 * declaration du compteur d'objets personne_t comme variable externe
 * pour compter les references sur ces objets
 */

extern unsigned long int personne_cpt  ;

/*
 * FONCTIONS
 */

extern personne_t * personne_creer(char * const prenom , char * const nom ) ;
extern booleen_t personne_existe( personne_t * const personne ) ;


#endif

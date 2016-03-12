#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <liste_objet.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int liste_objet_cpt = 0 ;
/*
 * Methodes d'acces
 */

/* Nombre d'elements */

extern
int liste_objet_nb_lire( liste_objet_t * const liste )
{
  return(liste->nb );
}

/* -- Acces individuel a un element */

extern
objet_t * liste_objet_elem_lire( liste_objet_t * const liste  , const int ind )
{
  if( (ind < 0) || (ind > liste_objet_nb_lire(liste)-1 ) )
    {
      fprintf( stderr , "liste_elem_lire: mauvais indice d'element [%d] (devrait etre dans [%d..%d])\n",
	       ind , 0 , liste_objet_nb_lire(liste)-1 );
      return(NULL);
    }

  return( liste->liste[ind] ) ;
}

/*
 * Tests
 */

extern
booleen_t liste_objet_existe( liste_objet_t * const liste )
{
  if( liste == NULL )
    {
      return(FAUX) ;
    }
  else
    {
      return(VRAI) ;
    }
}

extern
booleen_t liste_objet_vide( liste_objet_t * const liste )
{
  if( liste->nb == 0 )
    {
      return(VRAI) ;
    }
  else
    {
      return(FAUX) ;
    }
}

/*
 * Methodes d'affectation
 */


/* -- Acces individuel a un element */
extern err_t liste_objet_elem_ecrire( liste_objet_t * liste , objet_t * const elem , const int ind ) {

	#ifdef _DEBUG_
	if( (ind < 0) || (ind > liste_objet_nb_lire(liste) ) ){
		fprintf( stderr , "liste_elem_ecrire: mauvais indice d'element [%d] (devrait etre dans [%d..%d]\n",ind , 0 , liste_objet_nb_lire(liste) );
		return(ERR_LISTE_IND_ELEM);
	}
	#endif
	liste->liste[ind] = elem ;

	return(OK) ;
}



/*
 * Destruction d'une liste
 */

extern
err_t liste_objet_detruire( liste_objet_t ** liste )
{
	int i;
	objet_t ** objet;
	err_t error;

	if (liste_objet_existe(*liste)) {
		for (i = 0 ; i < (*liste)->nb ; i++) {
			objet = &((*liste)->liste[i]);
			if ((*objet) != NULL) {
				error = (*objet)->detruire(objet);
				if (error != OK) {
					return error;
				}
			}
		}
		free((*liste)->liste);
		free(*liste);
		*liste = NULL;
    liste_objet_cpt--;
	}
	return(OK) ;
}


/*
 * Affichage d'une liste sur la sortie standard
 * avec un caractere de separation entre
 * l'affichage de 2 elements
 */

extern
void liste_objet_afficher( liste_objet_t * const liste , const char separateur ){
	int i;
	objet_t * objet;
	if (liste_objet_existe(liste)) {
		for (i = 0 ; i < liste->nb ; i++) {
			objet = liste->liste[i];
			if (objet != NULL) {
				objet->afficher(objet);
				putchar(separateur);
			}
		}
	}
}

/*
 * Creation d'une liste
 */
extern
liste_objet_t * liste_objet_creer(const int nb) {
	liste_objet_t * liste;

	if ((liste = malloc(sizeof(liste_objet_t))) == NULL) {
		fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
		return (liste_objet_t *) NULL;
	}

	/* Assignation des adresses des fonctions aux pointeurs sur fonctions */
	liste->vide = liste_objet_vide;
	liste->elem_ecrire = liste_objet_elem_ecrire;
	liste->detruire = liste_objet_detruire;
	liste->afficher = liste_objet_afficher;

	liste->nb = nb;
	liste->liste = (objet_t**) NULL;
	if (nb > 0) {
		if ((liste->liste = calloc(nb, sizeof(objet_t *))) == NULL) {/* Utilisation de calloc au lieu de malloc, afin d'initialiser les pointeurs du tableau à 0 (NULL) */
			fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
			free(liste);
			return (liste_objet_t *) NULL;
		}
	}
  liste_objet_cpt++;
	return liste;
}

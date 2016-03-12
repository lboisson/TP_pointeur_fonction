#include <stdlib.h>
#include <string.h>
#include <personne.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int personne_cpt = 0 ;

/*
 * FONCTIONS
 */

extern booleen_t personne_existe( personne_t * const personne ){
	if( personne == NULL )
		return(FAUX) ;
	else
		return(VRAI) ;
}

static err_t personne_detruire( personne_t ** personne ) {

	free((*personne)->nom);
	free((*personne)->prenom);
	free(*personne);
	*personne = NULL;
	personne_cpt--;
	return(OK) ;
}

static void personne_afficher( personne_t * const personne ) {

	printf( "{" ) ;
	if(  personne_existe(personne) ) {
		printf( "%s %s" , personne->prenom , personne->nom ) ;
    }
    printf( "}" ) ;
}

extern personne_t * personne_creer( char * const prenom , char * const nom ) {


	personne_t * personne = NULL;
	if(( personne= malloc(sizeof(personne_t))) == NULL ){
		fprintf( stderr , "personne_creer: debordement memoire lors de la creation d'un personne\n");
		return((personne_t *)NULL);
	}

	personne->prenom=malloc(strlen(prenom)+1);
	if(personne->prenom == NULL ){
		fprintf( stderr , "personne_creer: debordement memoire lors de la creation d'un personne->prenom\n");
		free(personne);
		return(NULL);
	}
	strcpy(personne->prenom, prenom);

	personne->nom=malloc(strlen(nom)+1);
	if(personne->nom == NULL ){
		fprintf( stderr , "personne_creer: debordement memoire lors de la creation d'un personne->nom\n");
		free(personne);
		return(NULL);
	}
	strcpy(personne->nom,nom);

	personne->afficher= personne_afficher;
	personne->detruire= personne_detruire;

	personne_cpt++;
	return( personne ) ;
}

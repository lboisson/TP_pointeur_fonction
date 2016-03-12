#include <stdlib.h>
#include <string.h>
#include <individu.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int individu_cpt = 0 ;

/*
 * FONCTIONS
 */

extern booleen_t individu_existe( individu_t * const individu ){
	if( individu == NULL )
		return(FAUX) ;
	else
		return(VRAI) ;
}

static err_t individu_detruire( individu_t ** individu ) {

	free((*individu)->nom);
	free((*individu)->prenom);
	free(*individu);
	*individu = NULL;
	individu_cpt--;
	return(OK) ;
}

static void individu_afficher( individu_t * const individu ) {

	printf( "{" ) ;
	if(  individu_existe(individu) ) {
		printf( "%s %s" , individu->prenom , individu->nom ) ;
    }
    printf( "}" ) ;
}

extern individu_t * individu_creer( char * const prenom , char * const nom ) {


	individu_t * individu = NULL;
	if(( individu= malloc(sizeof(individu_t))) == NULL ){
		fprintf( stderr , "individu_creer: debordement memoire lors de la creation d'un individu\n");
		return((individu_t *)NULL);
	}

	individu->prenom=malloc(strlen(prenom)+1);
	if(individu->prenom == NULL ){
		fprintf( stderr , "individu_creer: debordement memoire lors de la creation d'un individu->prenom\n");
		free(individu);
		return(NULL);
	}
	strcpy(individu->prenom, prenom);

	individu->nom=malloc(strlen(nom)+1);
	if(individu->nom == NULL ){
		fprintf( stderr , "individu_creer: debordement memoire lors de la creation d'un individu->nom\n");
		free(individu);
		return(NULL);
	}
	strcpy(individu->nom,nom);

	/*pointeurs sur les fonctions avec cast	*/
	individu->afficher=(void (*) (void *))individu_afficher;
	individu->detruire= (err_t (*) (void **))individu_detruire;

	individu_cpt++;
	return( individu ) ;
}

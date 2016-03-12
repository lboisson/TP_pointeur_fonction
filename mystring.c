#include <stdlib.h>
#include <string.h>
#include <mystring.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int string_cpt = 0 ;

/*
 * FONCTIONS
 */

extern
booleen_t string_existe( string_t * const string )
{
  if( string == NULL )
    return(FAUX) ;
  else
    return(VRAI) ;
}

static
err_t string_detruire( string_t ** string )
{
	free((*string)->string);
	free(*string);
	*string = NULL;
  string_cpt--;
	return(OK) ;
}

static
void string_afficher( string_t * const string )
{

  printf( "{" ) ;
  if(  string_existe(string) )
    {
      printf( "%s" , string->string) ;
    }
  printf( "}" ) ;
}

extern
string_t * string_creer( char * const chaine )
{
	string_t * string = NULL ;

	if(( string= malloc(sizeof(string_t))) == NULL ){
		fprintf( stderr , "individu_creer: debordement memoire lors de la creation d'un individu\n");
		return((string_t *)NULL);
	}

	string->string=malloc(strlen(chaine)+1);
	if(string->string == NULL ){
		fprintf( stderr , "string_creer: debordement memoire lors de la creation d'un string->string\n");
		free(string);
		return(NULL);
	}
	strcpy(string->string,chaine);

	string->afficher= (void (*) (void *))string_afficher;
	string->detruire= (err_t (*) (void **))string_detruire;
  string_cpt++;
	return( string ) ;
}

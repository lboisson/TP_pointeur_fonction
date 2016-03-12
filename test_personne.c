#include <stdio.h>
#include <personne.h>

int
main()
{
  /* err_t noerr = OK; */
  personne_t * indiv_1 = NULL ;

  printf( "Debut du programme des test sur les objets de type personne_t\n" ) ;

  printf( "Test d'existance sur un personne_t inexistant\n" ) ;
  ( personne_existe(indiv_1) ? printf("-->KO\n") : printf ("-->OK\n") )  ;

  printf( "Test creation personne_t\n" ) ;
  indiv_1 = personne_creer( "Roger" , "Waters" ) ;

  printf( "Test affichage indiv_1\n" ) ;
  /* Utilisation de la méthode afficher */
  indiv_1->afficher(indiv_1);
  printf( "\n");

  printf( "Test d'existance sur un personne_t existant\n" ) ;
  ( personne_existe(indiv_1) ? printf("-->OK\n") : printf ("-->KO\n") )  ;

  printf( "Nombre de personne_t  = %lu\n" , personne_cpt ) ;

  printf( "Test destruction indiv_1\n" ) ;
	indiv_1->detruire(&indiv_1);

  printf( "Fin du programme des test sur les objets de type personne_t\n" ) ;

  printf( "Nombre de personne_t  = %lu\n" , personne_cpt ) ;

  return(0) ;
}

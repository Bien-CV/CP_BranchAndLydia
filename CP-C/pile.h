#ifndef CGI_PILE_H
#define CGI_PILE_H
#define MAX_NB_OF_VARIABLES_EMPTY_DOMAIN 200
 /*  Structure représantant un élément de la pile. */

        typedef struct pile
        {
                int valeur;
                struct pile *prec;
        } pile ;

#ifdef __cplusplus
extern "C" {
#endif

 /*  Push empile une valeur sur la pile. */

        void Push(pile **, int);


 /*  Pop retire la dernière valeur empilée sur la pile. */

        int Pop(pile **);


 /*  Clear vide la pile. */

        void Clear(pile **);


 /*  Length retourne le nombre d'élément de la pile. */

        int Length(pile *p);


 /*  Affiche la totalité de la pile en commençant par le sommet. */

        void View(pile *);

		pile ** newMatricePile(int newn);

		
		void afficheMatricePile(pile** mat,int size);
		
		void clearMatricePile(pile** mat,int size);
		pile ** newEmptyMatricePile();
#ifdef __cplusplus
}
#endif

#endif

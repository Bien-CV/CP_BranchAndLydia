#include <stdlib.h>
#include <stdio.h>

#include "pile_Dom.h"
#include "Domain.h"

/*************************************************************************/

void Push_dom(pile_Dom **p, Domain newDom)
{
        pile_Dom *element = malloc(sizeof(pile_Dom));
        if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échouée. */
        element->dom = newDom;
        element->prec = *p;
        *p = element;       /* Le pointeur pointe sur le dernier élément. */
}
/*************************************************************************/

Domain Pop_dom(pile_Dom **p)
{
        Domain newDom;
        pile_Dom *tmp;
        //if(!*p) return NULL;
        tmp = (*p)->prec;
        newDom = (*p)->dom;
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
        return newDom;     /* Retourne la valeur soutirée de la pile. */
}

/*************************************************************************/

void Clear_dom(pile_Dom **p)
{
        pile_Dom *head=*p;
        while(head)
          {
             destroyDomainContent(head->dom);
             head = head->prec;
          }
          
        head=*p;
        
        pile_Dom* tmp;
        while(head)
          {
             tmp = head->prec;
             free(head);
             head=tmp;
          }
}
/*************************************************************************/

int Length_dom(pile_Dom *p)
{
        int n=0;
        while(p)
          {
              n++;
              p = p->prec;
          }
        return n;
}

/*************************************************************************/

void View_dom(pile_Dom *p)
{
	pile_Dom *tmp=p;
        while(tmp)
          {
             afficherDomain(tmp->dom);
             tmp = tmp->prec;
          }
}

#ifndef CGI_PILE_DOM_H
#define CGI_PILE_DOM_H

#include "Domain.h"

 /*  Structure représantant un élément de la pile. */

        typedef struct pile_Dom
        {
                Domain dom;
                struct pile *prec;
        } pile_Dom ;

#ifdef __cplusplus
extern "C" {
#endif

void Push_dom(pile_Dom **, Domain);
Domain Pop_dom(pile_Dom **);
void Clear_dom(pile_Dom **);
int Length_dom(pile_Dom *p);
void View_dom(pile_Dom *);

#ifdef __cplusplus
}
#endif

#endif
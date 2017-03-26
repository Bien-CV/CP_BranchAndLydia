

#include <stdlib.h>
#include <stdio.h>

#include "Constraint.h"
#include "Domain.h"
#include "pile.h"

int main()
{
      /*  pile *MaPile = NULL;

        Push(&MaPile, 10);
        View(MaPile);
        Length(MaPile);
        Pop(&MaPile);
        Clear(&MaPile); */

        Domain test;// = NULL;
        initDomain(test,4);
        afficherDomain(test);
        printf("%d\n",isEmpty(test));
        /*test.n = 4;
        printf("%d\n",test.n);*/

        Constraint c;
        initConstraint(c,1,2,3,4);
        //printf("xi %d %d\n",c.xi,c.xj);


#ifdef _WIN32
        system("PAUSE");  /* Pour la console Windows. */
#endif
        return 0;
}

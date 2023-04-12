#include <stdio.h>
#include <stdlib.h>



int bissextille(int a)
{
    if (!(a%4))  return((int)1);
    return((int)0);
}

int date_valide(int j,int m,int a)
{

    int Jours[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((a<1901)||(a>2099)) return((int)-1);
    if((m<1)||(m>12)) return((int)-2);
    Jours[1]+=bissextille(a);
    if((j<1)||(j>Jours[m-1])) return((int)-3);
    return((int)1);
}

unsigned long int nombre_jour_annee(int a)
{
    int nbannee;
    nbannee=a-1901;
    return((int)nbannee*365+nbannee/4);
}

int nombre_jour_mois(int m,int a)
{
    switch(m-1)
    {
                    case 0: return((int)0);
                    case 1:return((int )31);
                    case 2:return((int )59+bissextille(a));
                    case 3:return((int )90);
                    case 4:return((int )120);
                    case 5:return((int )151);
                    case 6:return((int )181);
                    case 7:return((int )221);
                    case 8:return((int )252);
                    case 9:return((int )282);
                    case 10:return((int )313);
                    case 11:return((int )343);

    }

}


int nombre_jour(int j)
{
    return((int)j-1);
}

unsigned long int nombre_jours_total(int j,int m,int a)
{
    return((unsigned long int)nombre_jour_annee(a)+nombre_jour(j)+nombre_jour_mois(m,a));

}

void la_date(int j,int m,int a)
{
   if(date_valide(j, m, a)==1)
   {
    int resultat=nombre_jours_total(j,m,a)%7;
    switch (resultat)
    {
        case 0:printf("mardi");break;
        case 1:printf("mercredi");break;
        case 2:printf("jeudi");break;
        case 3:printf("vendredi");break;
        case 4:printf("samedi");break;
        case 5:printf("dimanche");break;
        case 6:printf("lundi");break;

    }
   }
   printf("invalide\n");

}


int main ()
{
    int j,m,a;
    printf(" le jour est : \n");
    scanf("%d",&j);
    printf(" le mois est : \n");
     scanf("%d",&m);
    printf(" l annee est : \n");
    scanf("%d",&a);

     la_date(j,m, a);

}

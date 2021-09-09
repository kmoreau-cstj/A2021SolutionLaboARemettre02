/* But: �crire un programme pour calculer le montant qu�un individu devra d�bourser pour faire un voyage dans une
automobile lou�e.L�algorithme tient compte du kilom�trage parcouru et de la dur�e du voyage qui sont soumises
par le requ�rant.

Les diff�rentes sources de d�penses sont :
o Co�t de la location de 45$ par jour et comprend 250 km gratuits par jour.
o La consommation du v�hicule est 7.6 litres aux 100 km.
o 1 litre d�essence co�te 1.35$
o 0.05$ du kilom�tre est exig� pour chaque kilom�tre suppl�mentaire

Auteur: Vincent Tr�panier

Date: 2021/09/09
*/

#include <iostream>

void main() 
{
   setlocale(LC_ALL, "");
   // D�claration de constantes avec leur valeur
   const int NBKMGRATUITPARJOUR = 300;
   const double COUTKMEXCEDENTAIRE = 0.04;
   const double COUTLOCATIONPARJOUR = 50;
   const double CONSOVEHICULE = 5.6 ;
   const double COUTLITREESSENCE = 1.37;

   //D�claration des variables
   // Variables pour m�moriser les valeurs fournies par l'utilisateur, qui seront initialis�es par l'utilisateur
   int nbKM;
   int nbJour;

   // Variables interm�diaires pour faire les calculs qu'il faudra parfois initialiser
   int nbKMGratuit;
   int nbKMExcedentaire;

   //Variables pour le r�sultat seront en g�n�ral initialis�es � la d�claration
   double montantArgent = 0;

   std::cout << "Veuillez inscrire le nombre de kilom�tres que vous aviez parcourus : ";
   std::cin >> nbKM;
   std::cout << "Veuillez inscrire combien de jours vous aviez lou� le v�hicule : ";
   std::cin >> nbJour;
   //Voir si le nombre de jours et kilom�tres sont positifs
   if (nbKM < 0 || nbJour < 0)
   {
      std::cout << "Erreur, veuillez ins�rer des valeurs positives\n";
   }
   else {


      //Trouver nombre de kilom�tre exc�dentaire

      nbKMGratuit = nbJour * NBKMGRATUITPARJOUR;
      nbKMExcedentaire = nbKMGratuit - nbKM; //Si le r�sultat est positif, le client n'a pas d�pass� sa limite

      if (nbKMExcedentaire < 0)
      {
         montantArgent = nbKMExcedentaire * -1 * COUTKMEXCEDENTAIRE;
      }

      //Calculer le co�t de la location

      montantArgent = montantArgent + (nbJour * COUTLOCATIONPARJOUR);

      //Calculer le co�t en essence
      //Trouver le nombre de litres utilis�s

      montantArgent = montantArgent + (nbKM / 100 * CONSOVEHICULE * COUTLITREESSENCE);

      std::cout << "Le co�t de v�tre voyage est de : " << montantArgent << "$\n";

   }

   system("pause");
}

/*Plan de test

nbKM  nbJour   R�sultat
0     0        0
500   2        90 + (7.6 x 5 x 1.35)
1000  3        3 x 45 + 250 x 0,05 + 1000/100 x 7.6 x 1,35
-500  -5       Erreur
a     0        Erreur








*/
/* But: Écrire un programme pour calculer le montant qu’un individu devra débourser pour faire un voyage dans une
automobile louée.L’algorithme tient compte du kilométrage parcouru et de la durée du voyage qui sont soumises
par le requérant.

Les différentes sources de dépenses sont :
o Coût de la location de 45$ par jour et comprend 250 km gratuits par jour.
o La consommation du véhicule est 7.6 litres aux 100 km.
o 1 litre d’essence coûte 1.35$
o 0.05$ du kilomètre est exigé pour chaque kilomètre supplémentaire

Auteur: Vincent Trépanier

Date: 2021/09/09
*/

#include <iostream>

void main() 
{
   setlocale(LC_ALL, "");
   // Déclaration de constantes avec leur valeur
   const int NBKMGRATUITPARJOUR = 300;
   const double COUTKMEXCEDENTAIRE = 0.04;
   const double COUTLOCATIONPARJOUR = 50;
   const double CONSOVEHICULE = 5.6 ;
   const double COUTLITREESSENCE = 1.37;

   //Déclaration des variables
   // Variables pour mémoriser les valeurs fournies par l'utilisateur, qui seront initialisées par l'utilisateur
   int nbKM;
   int nbJour;

   // Variables intermédiaires pour faire les calculs qu'il faudra parfois initialiser
   int nbKMGratuit;
   int nbKMExcedentaire;

   //Variables pour le résultat seront en général initialisées à la déclaration
   double montantArgent = 0;

   std::cout << "Veuillez inscrire le nombre de kilomètres que vous aviez parcourus : ";
   std::cin >> nbKM;
   std::cout << "Veuillez inscrire combien de jours vous aviez loué le véhicule : ";
   std::cin >> nbJour;
   //Voir si le nombre de jours et kilomètres sont positifs
   if (nbKM < 0 || nbJour < 0)
   {
      std::cout << "Erreur, veuillez insérer des valeurs positives\n";
   }
   else {


      //Trouver nombre de kilomètre excédentaire

      nbKMGratuit = nbJour * NBKMGRATUITPARJOUR;
      nbKMExcedentaire = nbKMGratuit - nbKM; //Si le résultat est positif, le client n'a pas dépassé sa limite

      if (nbKMExcedentaire < 0)
      {
         montantArgent = nbKMExcedentaire * -1 * COUTKMEXCEDENTAIRE;
      }

      //Calculer le coût de la location

      montantArgent = montantArgent + (nbJour * COUTLOCATIONPARJOUR);

      //Calculer le coût en essence
      //Trouver le nombre de litres utilisés

      montantArgent = montantArgent + (nbKM / 100 * CONSOVEHICULE * COUTLITREESSENCE);

      std::cout << "Le coût de vôtre voyage est de : " << montantArgent << "$\n";

   }

   system("pause");
}

/*Plan de test

nbKM  nbJour   Résultat
0     0        0
500   2        90 + (7.6 x 5 x 1.35)
1000  3        3 x 45 + 250 x 0,05 + 1000/100 x 7.6 x 1,35
-500  -5       Erreur
a     0        Erreur








*/
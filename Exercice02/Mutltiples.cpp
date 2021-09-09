/* But:écrivez un programme qui permet de lire un entier A
et affiche, selon sa valeur, un seul des 4 messages suivants :
• A est seulement un multiple de 2.
• A est seulement un multiple de 3.
• A est à la fois multiple de 2 et de 3.
• A n'est ni multiple de 2, ni de 3
*/
// Auteur: Raphaël Bourgeois
// Date: 2021-09-09

#include <iostream>

void main()
{
   // Déclaration des variables
   int nbEntier;

   // On affiche a l'utilisateur de rentrer l'entier
   std::cout << "Entrez un nombre entier: ";
   std::cin >> nbEntier;

   //on calcule pour voir si c'est un multiple de deux
  //on calcule pour voir si c'est un multiple de deux et de trois
   if (nbEntier % 2 == 0 && nbEntier % 3 == 0)
   {
      std::cout << nbEntier << " est un multiple de deux et un multiple de trois \n";
   }
   else  if (nbEntier % 2 == 0)
   {
      std::cout << nbEntier << " est seulement un multiple de deux \n";
   }
   else    if (nbEntier % 3 == 0) //on calcule pour voir si c'est un multiple de trois
   {
      std::cout << nbEntier << " est seulement un multiple de trois \n";
   }
   else
   {
      std::cout << nbEntier << " n'est ni multiple de deux ni un multiple de trois \n";
   }
   system("pause");
}

/*plan de test
nbEntier    écran
2           multiple de 2 seulement x
3           multiplde de 3 seulement x
5           ni multiple de 2 ni mulitiple de 3 x
6           multiple de 2 et de 3 x
12          multiple de 2 et de 3 x
9           multiplde de 3 seulement x
0           multiple de 2 et de 3 x
-1          ni multiple de 2 ni mulitiple de 3 x
a           erreur (0) x
*/
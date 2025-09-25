#ifndef __TAB__
#define __TAB__
#include<stdbool.h>
typedef unsigned char int8;/*Type entiers positifs codé sur 8 bits(entre 0 et 256) */
/*************************************************************************************************************************/
typedef struct matrice {/*Une matrice a un nombre de lignes et un nombre de colonnes positifs qui ne peuvent dépasser 256*/
    int8 Nblignes;      /**Une matrice a obligatoirement un nombre de lignes ou de colonnes supérieur à 0, une nouvelle matrice est consdéré comme vide avant de la remplir et une matrice vide est la matrice nulle */
    int8 Nbcolonnes;
    float**matrix;
    bool pasDefini;
    bool estTranspose;
}* matrice;
/*************************************************************************************************************************/
/****************************************************FONCTIONS MATRICES***************************************************/
matrice newMatrice(void);/*les deux arguments sont positifs et ne doivent pas depasser 256, le premier paramètre est le nombre de lignes*/
matrice definirMatrice(matrice,int8,int8);
matrice remplirMatrice(matrice);
matrice modifierCaseMatrice(matrice,int8,int8);
matrice transposerMatrice(matrice);/*Permute le nombre de lignes avec  le nombre de colonnes*/
matrice sommeMatrice(matrice,matrice);/*Cette fonction prends en comme paramètres deux matrices aui ont le même nombre de lignes et de colonnes, puis retourne leur somme*/
matrice produitMatrices(matrice, matrice);/*prend comme paramètres deux matrices dont le nombre de colonnes de la première est égal au nombre de lignes de la deuxième, et renvoie leur produit*/
/****************************************************FONCTIONS TABLEAUX***************************************************/
matrice inverserVecteur(matrice);/*Prend un vecteur en paramètre et retourne son inverse(la premimrre valeur devient la dernière, la ddernière devient la premimière)*/
float medianVecteur(matrice);/*retourne la valeure médiane d'un tableau(vecteur)*/
/*****************************************************FONCTIONS    BONUS**************************************************/
float produit(float,float);/*Calcul le produit de deux réels positis en utilisant uniquement l'incrémentation*/


#endif
#include<stdio.h>
#include"tabMat.h"



int main(void)
{
    int i=0,k=0;
    matrice m1,m2,m3;
    m1=newMatrice();
    m1=definirMatrice(m1,1,3);
    m1=remplirMatrice(m1);
    printf("\n");
    printf("\nNombre de lignes :%d  Nombre de colonnes: %d\n",m1->Nblignes,m1->Nbcolonnes);
    for(i=0;i<m1->Nblignes;i++){
        for(k=0;k<m1->Nbcolonnes;k++){
            printf("[%f] ",m1->matrix[i][k]);
        }
        printf("\n");
    }
    m1=transposerMatrice(m1);
    printf("\n");
    printf("\nNombre de lignes :%d  Nombre de colonnes: %d\n",m1->Nblignes,m1->Nbcolonnes);
    for(i=0;i<m1->Nblignes;i++){
        for(k=0;k<m1->Nbcolonnes;k++){
            printf("[%f] ",m1->matrix[k][i]);
        }
        printf("\n");
    }
    m2=newMatrice();
    m2=definirMatrice(m2,1,3);
    m2=remplirMatrice(m2);
    m3=produitMatrices(m1,m2);
    printf("\n");
    printf("\nNombre de lignes :%d  Nombre de colonnes: %d\n",m3->Nblignes,m3->Nbcolonnes);
    for(i=0;i<m3->Nblignes;i++){
        for(k=0;k<m3->Nbcolonnes;k++){
            printf("[%f] ",m3->matrix[i][k]);
        }
        printf("\n");
    }
    return 0;
}
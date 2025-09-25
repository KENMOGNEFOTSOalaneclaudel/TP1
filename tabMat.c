#include<stdio.h>
#include<stdlib.h>
#include"tabMat.h"

//fonction de créartion d'une nouvelle matrice
matrice newMatrice(void){
    matrice M=malloc(sizeof(struct matrice));
    M->pasDefini=true;
    M->estTranspose=false;
    M->Nblignes=0;
    M->Nbcolonnes=0;
    M->matrix=NULL;
    return M;
}
// Définir la matrice
matrice definirMatrice(matrice M,int8 a, int8 b) {
    if(M==NULL) {
        printf("\nImpossible de définir la matrice car elle n'a pas ete creee\n");
        return M;
    }
    else {
        if((M->Nblignes!=0)||(M->Nbcolonnes!=0)){
            printf("\nImpossible de définir cette matrice  car elle est deja definie\n");
            return M;
        }
    }
    if((a<=0)||(b<=0)) {
        printf("\nImpossible de definir une matrice avec un nombre de ligne ou un nombre de colonnes inferieur ou egal a 0\n");
        return M;
    }
    M->Nblignes=a;
    M->Nbcolonnes=b;
    M->matrix=((float**)malloc(sizeof(float*)*a));
    for(int i=0;i<a;i++)M->matrix[i]=((float*)malloc(sizeof(float)*b));
    M->pasDefini=false;
    printf("\nAttetntion : Une matrice seulement defini contient des valeurs quelconques, il va falloir la remplir avec vos valeurs.\n");
    return M;
}
//Remplir une matrice
matrice remplirMatrice(matrice M) {
    int i,k;
    if(M==NULL)printf("\n Cette matrice n'existe pas \n");
    else {
        if((M->pasDefini==true)){
            printf("\nImpossible de remplir cette matrice car elle n'a pas ete definie (Matrice nulle)\n");
        }
        else {
            if(M->estTranspose==true) {
                printf("\n");
                for(i=0;i<M->Nblignes;i++){
                    for(k=0;k<M->Nbcolonnes;k++){
                         printf("Entrez la valeur [%d][%d]: ",i+1,k+1);
                         scanf("%f",&M->matrix[k][i]);
                     }
                }
            } else {
                printf("\n");
                for(i=0;i<M->Nblignes;i++){
                    for(k=0;k<M->Nbcolonnes;k++){
                        printf("Entrez la valeur [%d][%d]: ",i+1,k+1);
                        scanf("%f",&M->matrix[i][k]);
                    }
                }
            }
        }
        
    }
    return M;
}
//Ecrire dans un emplacement spécifique
matrice modifierCaseMatrice(matrice M,int8 x,int8 y) {
    if((M==NULL)||(M->pasDefini==true)||(x>M->Nblignes)||(y>M->Nbcolonnes)||(x<1)||(y<1)) {
        printf("\n IMPOSSIBLE D'EFFECTUER CETTE OPERATION(Matrice inexistante,non definie(matrice videnulle) ou coordonnees incorrectes)\n");
        return M;
    }
    printf("Entrez la valeur [%d][%d]: ",x,y);
    if(M->estTranspose==true) {
        scanf("%f",&M->matrix[y-1][x-1]);
    }else {
        scanf("%f",&M->matrix[x-1][y-1]);
    }
    M->pasDefini=false;
    return M;

}
//Somme matrices
matrice sommeMatrice(matrice M1,matrice M2) {
    matrice somme;
    if((M1==NULL)||(M2==NULL)) {
        printf("\nSomme des deux matrices impossible car une ou les deux matrices n'existent pas\n");
        return NULL;
    }
    
    if((M1->pasDefini==true)&&(M2->pasDefini==false)) {
        printf("\nUne des deux matrices est non defini(alors il s'agit d'une matrice nulle)");
        somme=newMatrice();
        somme=definirMatrice(somme,M2->Nblignes,M2->Nbcolonnes);
        if(M2->estTranspose==true) {
            for(int i=0;i<M2->Nblignes;i++) {
                for(int k=0;k<M2->Nbcolonnes;k++) {
                  somme->matrix[i][k]=M2->matrix[k][i];
                 }
             }
        }
        else {
            for(int i=0;i<M2->Nblignes;i++) {
                for(int k=0;k<M2->Nbcolonnes;k++) {
                    somme->matrix[i][k]=M2->matrix[i][k];
                }
            }
        }
    }
    else {
        if((M2->pasDefini==true)&&(M1->pasDefini==false)) {
            somme=newMatrice();
            somme=definirMatrice(somme,M1->Nblignes,M1->Nbcolonnes);
            if(M1->estTranspose==true) {
                for(int i=0;i<M1->Nblignes;i++) {
                    for(int k=0;k<M1->Nbcolonnes;k++) {
                         somme->matrix[i][k]=M1->matrix[k][i];
                    }
                } 
            }
            else {
                for(int i=0;i<M1->Nblignes;i++) {
                    for(int k=0;k<M1->Nbcolonnes;k++) {
                        somme->matrix[i][k]=M1->matrix[i][k];
                    }
                }  
                return somme;
            } 
        }
        else {
            if((M1->pasDefini==true)&&(M2->pasDefini==true)) {
                somme=newMatrice();
                return somme;
            }
            else {
                if((M1->Nblignes!=M2->Nblignes)||(M1->Nbcolonnes!=M2->Nbcolonnes)) {
                    printf("\nSomme des deux matrices impossible car les dimensions sont incomptibles\n");
                    return NULL;           
                }
                else {
                    somme=newMatrice();
                    somme=definirMatrice(somme,M2->Nblignes,M2->Nbcolonnes);
                    if((M1->estTranspose==true)&&(M2->estTranspose==true)) {
                        for(int i=0;i<M2->Nblignes;i++) {
                            for(int k=0;k<M2->Nbcolonnes;k++) {
                                somme->matrix[i][k]=M2->matrix[k][i]+M1->matrix[k][i];
                            }
                        }
                    }
                    else {
                        if(M1->estTranspose==true) {
                            for(int i=0;i<M2->Nblignes;i++) {
                                for(int k=0;k<M2->Nbcolonnes;k++) {
                                    somme->matrix[i][k]=M2->matrix[i][k]+M1->matrix[k][i];
                                }
                            }
                        } 
                        else {
                            if(M2->estTranspose==true) {
                                for(int i=0;i<M2->Nblignes;i++) {
                                    for(int k=0;k<M2->Nbcolonnes;k++) {
                                        somme->matrix[i][k]=M2->matrix[k][i]+M1->matrix[i][k];
                                    }
                                }
                            }
                            else {
                                for(int i=0;i<M2->Nblignes;i++) {
                                    for(int k=0;k<M2->Nbcolonnes;k++) {
                                        somme->matrix[i][k]=M2->matrix[i][k]+M1->matrix[i][k];
                                    }
                                }
                            }
                        }
                    }
                    
                    return somme;
                }
            }
        }
    }
    return somme;
}
//Transposition de matrice
matrice transposerMatrice(matrice M) {
    int8 tampon;
    if(M==NULL) {
        printf("\nImpossible de transposer car matrice inexistante\n");
        return NULL;
    }
    tampon=M->Nblignes;
    M->Nblignes=M->Nbcolonnes;
    M->Nbcolonnes=tampon;
    if(M->estTranspose==true){
        M->estTranspose=false;
    }
    else {
        M->estTranspose=true;
    }
    return M;
}
//Produit matrice
matrice produitMatrices(matrice M1, matrice M2) {
    matrice produit=NULL;
    if((M1==NULL)||(M2==NULL)) {
        printf("\nImpossible d'effectuer le produit mariciel car au moins un des parametre n'est pas une matrice\n");
    }
    else {
        if((M1->pasDefini==true)||(M2->pasDefini==true)) {
            printf("\nVous effectuer un produit avec une matrice nulle\n");
            if(M1->pasDefini==true)produit=M1;
            else produit=M2;
        }
        else {
            if(M1->Nbcolonnes!=M2->Nblignes) {
                printf("\nImpossible d'effectuer le produit mariciel car les matrices sont incompatibles\n");
            }
            else {
                produit=newMatrice();
                produit=definirMatrice(produit,M1->Nblignes,M2->Nbcolonnes);
                if((M1->estTranspose==true)||(M2->estTranspose==true)) {
                    if((M1->estTranspose==true)&&(M2->estTranspose==true)){
                        for(int i=0;i<produit->Nblignes;i++) {
                            for(int k=0;k<produit->Nbcolonnes;k++) {
                                produit->matrix[i][k]=0;
                                for(int j=0;j<M1->Nbcolonnes;j++) {
                                    produit->matrix[i][k]=produit->matrix[i][k]+(M1->matrix[j][i]*M2->matrix[k][j]); 
                                }
                                        
                            }
                        }
                    }
                    else {
                        if(M1->estTranspose==true) {
                            for(int i=0;i<produit->Nblignes;i++) {
                                for(int k=0;k<produit->Nbcolonnes;k++) {
                                    produit->matrix[i][k]=0;
                                    for(int j=0;j<M1->Nbcolonnes;j++) {
                                        produit->matrix[i][k]=produit->matrix[i][k]+(M1->matrix[j][i]*M2->matrix[j][k]); 
                                    }
                                }
                            }
                        }
                        else {
                            if(M2->estTranspose==true) {
                                for(int i=0;i<produit->Nblignes;i++) {
                                    for(int k=0;k<produit->Nbcolonnes;k++) {
                                        produit->matrix[i][k]=0;
                                        for(int j=0;j<M1->Nbcolonnes;j++) {
                                            produit->matrix[i][k]=produit->matrix[i][k]+(M1->matrix[i][j]*M2->matrix[k][j]); 
                                        }
                                    }
                                }
                            }
                            else {
                                for(int i=0;i<produit->Nblignes;i++) {
                                    for(int k=0;k<produit->Nbcolonnes;k++) {
                                        produit->matrix[i][k]=0;
                                        for(int j=0;j<M1->Nbcolonnes;j++) {
                                            produit->matrix[i][k]=produit->matrix[i][k]+(M1->matrix[i][j]*M2->matrix[j][k]); 
                                        }
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    return produit;
}
//Inverser vecteur
matrice inverserVecteur(matrice M) {
    matrice inverse=NULL;
    if((M==NULL)||(M->Nbcolonnes!=1)||(M->Nblignes!=1)) {
        printf("\nImpossible d'inverse cet element car il ne s'agit pas d'un vecteur\n");
    }
    else {
        if(M->pasDefini==true) {
            printf("\n")
        }
    }
}
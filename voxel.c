#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

<<<<<<< HEAD
int** Convert_to_matrice(int*** model, int x_length, int y_length, int z_length, unsigned int* n) {
    int** voxel_matrice = NULL; // Tableau 2D stockant des (x, y, z)
    *n = 0; // Nombre de voxels actifs trouvés

    for (int i = 0; i < z_length; i++) {
        for (int j = 0; j < y_length; j++) {
            for (int k = 0; k < x_length; k++) {
                if (model[i][j][k] == 1) {  // Si le voxel est actif

                    bool is_surrounded = false;
                    if (( 0 < i < z_length ) && ( 0 < j < y_length ) && ( 0 < k < x_length )){
                        is_surrounded = (model[i-1][j][k] && model[i+1][j][k] && model[i][j-1][k] && model[i][j+1][k] && model[i][j][k+1] && model[i][j][k+1]);
                    // Réallocation pour un nouvel élément
                    if !(is_surrounded){
                        int** temp = realloc(voxel_matrice, (*n + 1) * sizeof(int*));
                        if (!temp) {
                            free(voxel_matrice); // Libération mémoire en cas d'échec
                            return NULL;
                        }
                        voxel_matrice = temp;

                        // Allocation d'une ligne pour (x, y, z)
                        voxel_matrice[*n] = malloc(3 * sizeof(int));
                        if (!voxel_matrice[*n]) {
                            for (int l = 0; l < *n; l++) free(voxel_matrice[l]);
                            free(voxel_matrice);
                            return NULL;
                        }

                        // Stockage des coordonnées
                        voxel_matrice[*n][0] = k;
                        voxel_matrice[*n][1] = j;
                        voxel_matrice[*n][2] = i;

                        (*n)++; 
                    } // Incrémentation du compteur


                }
            }
        }
    }

    return voxel_matrice;
}


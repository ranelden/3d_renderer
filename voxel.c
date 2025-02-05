#include <stdio.h>
#include <stdlib.h>

**int Convert_to_matrice(int*** model, int x_length, int y_length, int z_length, int n){
    **int voxel_matrice = (int*) malloc(sizeof(int*)); // doit proteger malloc
    int n = 0;
    for(int i = 0 ; i < z_length ; i++){
        for(int j = 0 ; j < y_length ; j++){
            for(int k = 0 ; k < x_length ; k++){
                if(model[Z][y][x]==1){
                    voxel_matrice = realloc(voxel_matrice, sizeof(int*)*(n+1))  // doit proteger malloc
                    voxel_matrice[n][0] =  x_length;
                    voxel_matrice[n][1] =  y_length;
                    voxel_matrice[n][2] =  z_length;
                    n++;
int** Convert_to_matrice(int*** model, int x_length, int y_length, int z_length, int* n) {
    int** voxel_matrice = NULL; // Tableau 2D stockant des (x, y, z)
    *n = 0; // Nombre de voxels actifs trouvés

    for (int i = 0; i < z_length; i++) {
        for (int j = 0; j < y_length; j++) {
            for (int k = 0; k < x_length; k++) {
                if (model[i][j][k] == 1) {  // Si le voxel est actif

                    // Réallocation pour un nouvel élément
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

                    (*n)++;  // Incrémentation du compteur
                }
            }
        }
    }
}
    return voxel_matrice;
}


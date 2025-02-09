#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define F1 [1,2,3,4]
#define F2 [5,6,7,8]
#define F3 [1,4,8,5]
#define F4 [2,3,7,6]
#define F5 [1,2,6,5]
#define F6 [4,3,7,8]

double** Convert_to_matrice(int*** model, int x_length, int y_length, int z_length, unsigned int* n) {
    double** voxel_matrice = NULL; // Tableau 2D stockant des (x, y, z)
    *n = 0; // Nombre de voxels actifs trouvés

    for (double i = 0; i < z_length; i++) {
        for (double j = 0; j < y_length; j++) {
            for (double k = 0; k < x_length; k++) {
                if (model[i][j][k] == 1) {  // Si le voxel est actif

                    bool is_surrounded = false;
                    if (( 0 < i < z_length ) && ( 0 < j < y_length ) && ( 0 < k < x_length )){
                        is_surrounded = (model[i-1][j][k] && model[i+1][j][k] && model[i][j-1][k] && model[i][j+1][k] && model[i][j][k+1] && model[i][j][k+1]);
                    // Réallocation pour un nouvel élément
                    if !(is_surrounded){
                        double** temp = realloc(voxel_matrice, (*n + 1) * sizeof(double*));
                        if (!temp) {
                            free(voxel_matrice); // Libération mémoire en cas d'échec
                            return NULL;
                        }
                        voxel_matrice = temp;

                        // Allocation d'une ligne pour (x, y, z)
                        voxel_matrice[*n] = malloc(3 * sizeof(double*));
                        if (!voxel_matrice[*n]) {
                            for (int l = 0; l < *n; l++) free(voxel_matrice[l]);
                            free(voxel_matrice);
                            return NULL;
                        }

                        // Stockage des coordonnées
                        voxel_matrice[*n][0] = k - ( x_length / 2 );
                        voxel_matrice[*n][1] = j - ( y_length / 2 );
                        voxel_matrice[*n][2] = i - ( z_length / 2 );

                        (*n)++; 
                    } // Incrémentation du compteur


                }
            }
        }
    }

    return voxel_matrice;
}

double*** voxel_inheritances( double** matrice, unsigned int* n){
    
    double*** point_array = (double**) malloc( 8 * sizeof(double**))  
    for (int i = 0; i < 8; i++){
        point_array[i] = (double*) malloc((*n) * sizeof(double*))
        for(int j = 0; j < (n*); j++){
            point_array[i][j] = (double) malloc(3 * sizeof(double))
        }
    } 

    for (int i = 0; i < (*n); i++){

        point_array[0][i][0] = matrice[i][0] - (1/2);
        point_array[0][i][1] = matrice[i][1] - (1/2);
        point_array[0][i][2] = matrice[i][2] - (1/2);

        point_array[1][i][0] = matrice[i][0] + (1/2);
        point_array[1][i][1] = matrice[i][1] - (1/2);
        point_array[1][i][2] = matrice[i][2] - (1/2);

        point_array[2][i][0] = matrice[i][0] + (1/2);
        point_array[2][i][1] = matrice[i][1] + (1/2);
        point_array[2][i][2] = matrice[i][2] - (1/2);

        point_array[3][i][0] = matrice[i][0] - (1/2);
        point_array[3][i][1] = matrice[i][1] + (1/2);
        point_array[3][i][2] = matrice[i][2] - (1/2);

        point_array[4][i][0] = matrice[i][0] - (1/2);
        point_array[4][i][1] = matrice[i][1] - (1/2);
        point_array[4][i][2] = matrice[i][2] + (1/2);

        point_array[5][i][0] = matrice[i][0] + (1/2);
        point_array[5][i][1] = matrice[i][1] - (1/2);
        point_array[5][i][2] = matrice[i][2] + (1/2);

        point_array[6][i][0] = matrice[i][0] + (1/2);
        point_array[6][i][1] = matrice[i][1] + (1/2);
        point_array[6][i][2] = matrice[i][2] + (1/2);

        point_array[7][i][0] = matrice[i][0] - (1/2);
        point_array[7][i][1] = matrice[i][1] + (1/2);
        point_array[7][i][2] = matrice[i][2] + (1/2);  

    }
    
}


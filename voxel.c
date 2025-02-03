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
                }
            }
        }
    }
}
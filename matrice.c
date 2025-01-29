#include<stdio>
#include<stdlib.h>
#include<math.h>

#define PI 3.1415926535


double degToRad(double degrees) {
    return degrees * (PI / 180.0);
}

void rotation(int** array, int n, char axe, double angle){
    
    double rad_angle = degToRad(angle);
    double COS = cos(rad_angle);
    double SIN = sin(rad_angle);

    if (axe == "X"){
        int matrice_rota[3][3]={{1 , 0 , 0 },
                                {0 ,COS,-SIN},
                                {0 ,SIN, COS}}
    }

    if (axe == "Y"){
        int matrice_rota[3][3]={ {COS, 0 ,SIN},
                                 { 0 , 1 , 0 },
                                {-SIN, 0 ,COS}}
    }

    if (axe == "Z"){
        int matrice_rota[3][3]={{COS,-SIN, 0 },
                                 {SIN,COS, 0 },
                                 { 0 , 0 , 1 }}
    }
    
    else{
        return NULL;
    }
    
    for(int i = 0; i < n ; i++){
        
        int x = array[i];
        int y = array[i+1];
        int z = array[i+2];

        x = matrice_rota[0][0]*x + matrice_rota[0][1]*x + matrice_rota[0][2]*x ;
        x = matrice_rota[1][0]*y + matrice_rota[1][1]*y + matrice_rota[1][2]*y ;
        x = matrice_rota[2][0]*z + matrice_rota[2][1]*z + matrice_rota[2][2]*z ;

        array[i] = x ;
        array[i+1] = y ;
        array[i+2] = z ;
        
    }
    return  ; 
}
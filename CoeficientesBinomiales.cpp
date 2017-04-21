#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   /*Este ejemplo se prueba con los valores de la explicación del siguiente video:
          https://www.youtube.com/watch?v=XAfU0TfzRzY
    
    Datos de prueba: n = 5, k=2, da como resultado 10 subgrupos diferentes      
      5!     5 x 4 x 3 x 2 x 1    20
    ----- = ------------------ = --- = 10
    2! 3!    2 x 1 x 3 x 2 x 1    2          
    
    Datos de prueba: n = 8, k=3, da como resultado 10 subgrupos diferentes      
      8!     8 x 7 x 6 x 5 x 4 x 3 x 2 x 1    
    ----- = ------------------------------ = 56 
    3! 5!    3 x 2 x 1 x 5 x 4 x 3 x 2 x 1              

    -------------------------------------------------------------------------    
    ALGORITMO DEL LIBRO: TÉCNICAS DE DISEÑO DE ALGORITMOS
    Página 180
    
    PROCEDURE CoefIter(n,k: CARDINAL):CARDINAL;
    VAR i,j: CARDINAL;
    C: TABLA;
    BEGIN
    FOR i:=0 TO n DO C[i,0]:=1 END;
    FOR i:=1 TO n DO C[i,1]:=i END;
    FOR i:=2 TO k DO C[i,i]:=1 END;
    FOR i:=3 TO n DO
        FOR j:=2 TO i-1 DO
            IF j<=k THEN
               C[i,j]:=C[i-1,j-1]+C[i-1,j]
            END
        END
    END;
    RETURN C[n,k]
    END CoefIter.
    
    */
        
   //Declaración de variables locales
    int MAX=9;//Cantidad máxima de los componentes del arreglo 0..20=21
    int C[MAX][MAX];//Se declara el arreglo
    int n,k,i,j;//Variables tipo contador
    
    //limpieza del arreglo
    for(i=0;i<=MAX;i++)
    for(j=0;j<=MAX;j++)
    {
       C[i][j]=0;
    } 
    //Lectura de datos
    cout<<"\nCoeficientes binomiales o numeros combinatorios"; 
    cout<<"\nIngrese numero de elementos del grupo [n]: "; 
    cin>>n;
    cout<<"\nIngrese cantidad de elmentos del subgrupo a crear [k]: "; 
    cin>>k;
        
    //Se implementa el algoritmo de libro
    for(i=0;i<=n;i++) C[i][0]=1;
    for(i=1;i<=n;i++) C[i][1]=i;
    for(i=2;i<=k;i++) C[i][i]=1;
    for(i=3;i<=n;i++) 
    {
       for(j=2;j<=(i-1);j++) 
       {
              if (j<=k)
              { C[i][j]=C[i-1][j-1]+C[i-1][j];
                       }           
        }
    }
   //Se imprime el resultado
   cout<<"\nLa cantidad de subgrupos diferentes que se obtienen es: "<<C[n][k];
   cout<<"\n\n";
   system("PAUSE");//Hace una pausa.
   return EXIT_SUCCESS;
}

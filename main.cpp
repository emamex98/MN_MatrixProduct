//  Tarea de Matrices
//  Created by Emanuel Estrada Larios
//  A01633605

#include <iostream>
using namespace std;

// Clase matriz
class Matriz{
    
private:
                                // Atributos de matriz:
    int m;                      // # de filas
    int n;                      // # de columnas
    int *ptrContent;            // Apuntador al primer indice de arreglo de elementos
    int len;                    // Tamano del arreglo
    
public:
    
    // Constructor recibe m, n y arreglo en row-major-order
    Matriz(int m, int n, int contentParam[]){
        this->m = m;
        this->n = n;
        this->len = n*m;
        this->ptrContent = &contentParam[0];
    }
    
    // Getter de m
    int getM(){
        return this->m;
    }
    
    // Getter de n
    int getN(){
        return this->n;
    }
    
    // Getter de index especifico comenzando en (0,0) hasta (n-1,m-1)
    int getIndex(int i, int j){
        return *(ptrContent + i * this->n + j);
    }
    
    // Metodo multiplica matriz B por matriz actual, regresa apuntador a arreglo o NULL
    int *preMultiply(Matriz matrizB){
        
        if(matrizB.getN() == this->m){
            
            int lenR = matrizB.getM() * this->n;
            int resultado[lenR];
            
            for (int k=0; k<lenR; k++) {
                resultado[k] = 0;
            }
            
            int k = 0;
            for (int h=0; h<matrizB.getM(); h++) {
                for (int i=0; i<this->n; i++) {
                    for (int j=0; j<this->m; j++) {
                        resultado[k] += matrizB.getIndex(h, j) * this->getIndex(j,i);
                    }
                    k++;
                }
            }
            return &resultado[0];
        }
        return NULL;
    }
    
    // Metodo multiplica matriz actual por matriz B, regresa apuntador a arreglo o NULL
    int *multiply(Matriz matrizB){
        
        if(matrizB.getM() == this->n){
            
            int lenR = matrizB.getN() * this->m;
            int resultado[lenR];
            
            for (int k=0; k<lenR; k++) {
                resultado[k] = 0;
            }
            
            int k = 0;
            for (int h=0; h<this->m; h++) {
                for (int i=0; i<matrizB.getN(); i++) {
                    for (int j=0; j<matrizB.getM(); j++) {
                        resultado[k] += this->getIndex(h, j) * matrizB.getIndex(j,i);
                    }
                    k++;
                }
            }
            return &resultado[0];
        }
        return NULL;
    }
    
    // Metodo recorre matrix y la imprime en formato mxn
    void printMatriz(){
        int columna = 0;
        int columnaMax = this->n - 1;
        
        for (int i=0; i<len; i++) {
        
            cout << *(ptrContent + i) << " ";
            
            if(columna == columnaMax){
                cout << "\n";
                columna = 0;
            } else {
                columna++;
            }
        }
    }
    
};

///////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
    
    // Pruebas preMultiply()
    int arregloA [] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arregloB [] = {1,2,3,4,5,6};
    
    Matriz a = Matriz(3,4,arregloA);
    Matriz b = Matriz(2,3,arregloB);
    
    cout << "Matriz A: \n";
    a.printMatriz();
    cout << "\nMatriz B: \n";
    b.printMatriz();
    
    int *c = a.preMultiply(b);
    int cArray [8];
    
    for (int i=0; i<8; i++) {
        cArray[i] = *(c + i);
    }
    
    Matriz r = Matriz(2,4,cArray);
    
    cout << "\nMatriz BxA: \n";
    r.printMatriz();
    
    ///////////////////////////////////////////////////////////

    // Pruebas multiply()
    int arregloP [] = {1,2,3,4,5,6};
    int arregloQ [] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    Matriz p = Matriz(2,3,arregloP);
    Matriz q = Matriz(3,4,arregloQ);
    
    cout << "\nMatriz P: \n";
    p.printMatriz();
    cout << "\nMatriz Q: \n";
    q.printMatriz();
    
    int *s = p.multiply(q);
    int sArray [8];
    
    for (int i=0; i<8; i++) {
        sArray[i] = *(s + i);
    }
    
    Matriz t = Matriz(2,4,sArray);
    
    cout << "\nMatriz PxQ: \n";
    t.printMatriz();
    
    cout << "\n";
    
    return 0;
}

// Imagine++ project
// Project:  File
// Author:   Pascal Monasse
// TP réalisé par Clément RIU et Anne SPITZ




#include "file.h"
#include<iostream>
#include<ctime>

using namespace Imagine;
using namespace std;


//typedef fileListe file;
typedef fileTableau file;

const int n=300;

/*
Réponse à la question :
 On ne peut pas utiliser un algorithme récursif car le premier point traité se propagerait sur l'ensemble de l'écran.
*/


//Cette fonction examine si le voisin déterminé par la direction (i,j) a déjà été traité ou non
//Si le voisin n'a pas été traité, on le dessine puis on le note comme tel via le tableau de booléen
void pushVoisin(bool t[n][n], point P, file & f, int i, int j){
    if (!t[P.x+i][P.y+j] && P.x+i<n && P.x+i>0 && P.y+j<n && P.y+j>0){
        point Q(P.x+i,P.y+j,P.c);
        t[Q.x][Q.y]=true;
        drawPoint(Q.x,Q.y,Q.c);
        f.push(Q);
    }
}


//examine les voisins dans le cadre de la distance max
void voisins0(bool t[n][n], point P, file & f){
    pushVoisin(t, P, f, 1, 0);
    pushVoisin(t, P, f, 0, 1);
    pushVoisin(t, P, f, -1, 0);
    pushVoisin(t, P, f, 0, -1);
}

//examine les voisins dans le cadre de la distance 1
void voisins1(bool t[n][n], point P, file & f){
    pushVoisin(t, P, f, 1, 0);
    pushVoisin(t, P, f, 0, 1);
    pushVoisin(t, P, f, -1, 0);
    pushVoisin(t, P, f, 0, -1);
    pushVoisin(t, P, f, 1, 1);
    pushVoisin(t, P, f, -1, 1);
    pushVoisin(t, P, f, -1, -1);
    pushVoisin(t, P, f, 1, -1);
}



int main() {
    srand((unsigned int)time(0));
    file f; // File vide
    bool t[n][n];  // Tableau des points déjà traités
    int x,y;

    for (int i=0; i<n*n ; i++){
        t[n][n]=false;
    }

    cout << "Entrez 1 pour distance 1, 0 pour distance max" << endl;
    int d1;
    cin >> d1;

    if (d1!= 0 && d1!= 1){
        cout<<"La valeur entrée n'est pas correcte. Le programme se lancera avec la distance 1"<<endl;
        d1=1;
    }

    openWindow(n,n);
    cout << "Clics pour ajouter des points, clic droit pour lancer le programme." << endl;



    int clic;

    clic = getMouse(x, y);

    while(clic!=3) {
        Color col(rand()%256,rand()%256,rand()%256);
        point P(x,y,col);
        f.push(P);
        t[x][y]=true;

        drawPoint(x,y,col);

        clic = getMouse(x, y);
    }

    point P;

    while(! f.empty()) {
        P = f.pop();

        if (d1==0){
            voisins0(t, P, f);
        }
        if (d1==1){
            voisins1(t, P, f);
        }
    }


    endGraphics();
    return 0;
}

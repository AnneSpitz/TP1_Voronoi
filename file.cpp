#include "file.h"
#include <iostream>
#include <cassert>



// --- fileListe ---

fileListe::fileListe() {}

fileListe::~fileListe() {}

bool fileListe::empty() const {
    if (L.size()==0){
        return (true);
    }
    else {
        return (false);
    }
}

void fileListe::push(point p) {
    L.push_back(p);
}

point fileListe::pop() {
    point p(L.front());
    L.pop_front();
    return p;
}


// --- fileTableau ---

// Constructeur
fileTableau::fileTableau() {
    size=1;
    t=new point[size];
    first=0;
    last=0;
}

// Destructeur
fileTableau::~fileTableau() {
    size=0;
    delete [] t;
    t=NULL;
    first=0;
    last=0;
}

// La file d'attente est-elle vide?
bool fileTableau::empty() const {
    if (first==last) {
        return (true);
    }
    else {
        return (false);
    }
}

// Un nouveau client arrive
void fileTableau::push(point p) {
    if (last<size){
        t[last]=p;
    }
    else {
        point* ttemp = new point[2*size];
        for (int i=0; i<size; i++){
            ttemp[i]=t[i];
        }
        delete [] t;
        t=ttemp;
        t[size]=p;
        size=2*size;
    }
    last+=1;
}

// Sert le premier client
point fileTableau::pop() {
    if (! empty()){
        point p(t[first]);
        if (first<size-1){
            first+=1;
        }
        else{
            first=0;
        }
        return p;
    }
}

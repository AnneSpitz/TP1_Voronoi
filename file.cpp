#include "file.h"
#include <iostream>
#include <cassert>



// --- fileListe ---

fileListe::fileListe() {}

fileListe::~fileListe() {}

bool fileListe::empty() const {
    if (L.size()==0){return (true);}
    else {return (false);}
}

void fileListe::push(point p) {
    L.push_back(p);
}

point fileListe::pop() {
    point p;
    p.assigne(L.front());
    L.pop_front();
    return p;
}

// --- fileTableau ---

// Constructeur
fileTableau::fileTableau() {
}

// Destructeur
fileTableau::~fileTableau() {
}

// La file d'attente est-elle vide?
bool fileTableau::empty() const {
    return true;
}

// Un nouveau client arrive
void fileTableau::push(point p) {
}

// Sert le premier client
point fileTableau::pop() {
    point p;
    return p;
}

#include "file.h"
#include <iostream>
#include <cassert>

// --- fileListe ---

fileListe::fileListe() {}
fileListe::~fileListe() {}

bool fileListe::empty() const {
    return true;
}

void fileListe::push(point p) {

}

point fileListe::pop() {
    point p;
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

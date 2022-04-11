//
// Created by DANIEL on 11/04/2022.
//

#include "Extensible_Hash.h"

Extensible_Hash::Extensible_Hash(int buck_siz) {
    global_depth=1;
    hash_table.push_back(new bucket);
    hash_table.push_back(new bucket);
    this->bucket_size =buck_siz;

}


void Extensible_Hash::resizing(){ // O(n)  n= nro de directorios
        global_depth++;
    size_t oldSize = hash_table.size();

    for(size_t i  = oldSize; i <oldSize*2; i++){
        hash_table.push_back(hash_table[i%oldSize]); // Los nuevos directorios van a apuntar al bucket al que apunta su modulo
    }
}

void Extensible_Hash::split(size_t &pos) { // O(bucket_size)
    hash_table[pos]->depth+=1;
    vector<pair<int, long>> aux_cont = hash_table[pos]->container; // Copiando los elementos del viejo bucket
    int depthh  =  hash_table[pos]->depth;

    if(hash_table[pos]->depth > this->global_depth){ // Si se viola la restricción de local_depth < global_depth, se redimensiona los directorios
        resizing();
    }

    hash_table[pos]->container.clear();
    hash_table[pos] = new bucket(depthh); // Separando en otro bucket

    for(pair<int, long>& i : aux_cont){ // Redistribuyendo los elementos del viejo bucket
        insert(i.first, i.second);
    }
}

void Extensible_Hash::insert(const int &key, const long &value) {
    size_t hashF = key & ((1 << global_depth) -1) ;
    if (hash_table[hashF]->size_() + 1 <= bucket_size) {
        hash_table[hashF]->push({key, value});
    }
    else {
        split(hashF); // Split porque esta lleno el bucket
        hashF = key & ((1 << global_depth) - 1);
        hash_table[hashF]->push({key, value});
    }
}

void Extensible_Hash::display() {
    cout<<"Global depth: "<<global_depth<<'\n';
    for(int i =  0; i<hash_table.size(); i++){
        cout<<"Directorio: "<<i<<'\n';
        hash_table[i]->display();
        cout<<"------------------------------"<<endl;
    }
}



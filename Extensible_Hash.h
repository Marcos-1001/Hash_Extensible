//
// Created by DANIEL on 11/04/2022.
//

#ifndef BD2_EXT_HASH_EXTENSIBLE_HASH_H
#define BD2_EXT_HASH_EXTENSIBLE_HASH_H


#include <iostream>
#include <list>
#include <vector>
#include <fstream>
using namespace std;

struct bucket {
    int depth{};
    vector<pair<int, long>> container;   // pair< key, posfisica  >

    explicit bucket(int depth=1): depth(depth){}

    void push(const pair<int, long>& item){container.push_back(item);}
    size_t size_() const{return container.size();}

    void display(){
        cout<<"Key\t"<<"Value"<<'\n';
        for(auto & i : container){
            cout<<i.first<<'\t'<<i.second<<'\n';
        }
    }

};


class Extensible_Hash{
    int global_depth{};
    vector<bucket*> hash_table{};
    int bucket_size{};
public:
    explicit Extensible_Hash(int buck_siz = 3);
    void resizing();

    void split(size_t& pos);

    // Hash Function: key & ((1 << global_depth) - 1) | Permite obtener los global_depth bits que están más a la derecha del valor de la key.
    void insert(const int& key, const long& value);

    void display();

};


#endif //BD2_EXT_HASH_EXTENSIBLE_HASH_H

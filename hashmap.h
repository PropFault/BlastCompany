#ifndef WEAKHASHMAP_H
#define WEAKHASHMAP_H
#include "hashnode.h"
#include <iostream>
#include <stdexcept>
#include <functional>
/// incredibly shitty implementation of a hashmap.
/// Things missing: block-wise resizing, actually decent resizing mechanism that doesnt shift everything, actually decent collission handling
//// this hurts me more than it does you
template <typename k, typename v>
class HashMap
{
private:
    int totalSlots;
    int usedSpaces;
    HashNode<k,v>* dataSet;
    void resize(int newSize){
        HashNode<k,v>* oldData = this->dataSet;
        this->dataSet = new HashNode<k,v>[newSize];
        int oldSize = this->totalSlots;
        this->totalSlots = newSize;
        this->usedSpaces = 0;
        for(size_t i = 0; i < oldSize; i++){
            if(oldData[i].getIsInit())
                this->insert(oldData[i].getKey(), oldData[i].getValue());
        }
        delete[] oldData;
    };
    HashNode<k,v>& getNode(const k& key){
        if(this->totalSlots > 0){
            size_t hash = getHash(key);
            size_t slot = hash%this->totalSlots;
            for(size_t i = slot; i < this->totalSlots;i++)
                if(getHash(this->dataSet[i].getKey()) == hash){
                    return this->dataSet[i];
                }
        }
        throw std::runtime_error("Node not found");
    }
    size_t getHash(const k& key)const{
        std::hash<k> hasher;
        return hasher(key);
    }
    static constexpr int RESIZE_STEP = 5; //resize block size
public:
    HashMap()    :totalSlots(0),usedSpaces(0),dataSet(new HashNode<k,v>[0])
    {

    };
    HashMap(const HashMap& othr)    :totalSlots(othr.totalSlots), usedSpaces(othr.usedSpaces){
        this->dataSet = new v[this->totalSlots];
        for(size_t i = 0; i < othr.totalSlots; i++){
            this->dataSet[i] = othr.dataSet[i];
        }
    }
    HashMap& operator=(const HashMap &other){
        if(this == &other)
            return *this;
        delete[] this->dataSet;
        this->totalSlots = other.totalSlots;
        this->usedSpaces = other.usedSpaces;
        this->dataSet = new v[this->totalSlots];
        for(size_t i = 0; i < other.totalSlots; i++){
            this->dataSet[i] = other.dataSet[i];
        }
        return *this;
    }
    v &get(const k &key){
        return this->getNode(key).getValue();
    }
    void insert(const k &key,const v& value){
        if(!(this->usedSpaces < this->totalSlots)){
            this->resize(this->totalSlots + HashMap::RESIZE_STEP);
        }
        size_t hash = getHash(key);
        size_t slot = hash%this->totalSlots;
        bool slotInserted = false;
        int attempts = 0;
        int attemptLimit = 20;
        do{
            for(size_t i = slot; i < this->totalSlots; i++){
                if(!this->dataSet[i].getIsInit()){
                    this->dataSet[i].init(key,value);
                    slotInserted = true;
                    this->usedSpaces++;
                    break;
                }
            }
            if(slotInserted)
                break;
            this->resize(this->totalSlots + HashMap::RESIZE_STEP);
            attempts++;
            if(attempts >= attemptLimit)
                throw std::runtime_error("could not insert. attempt limit reached. unable to locate slot.");
        }while(!slotInserted);
    }
    void erase(const k &key)
    {
        this->getNode(key).clear();
    }

    ~HashMap()
    {
        delete[] this->dataSet;
    }

};

#endif // WEAKHASHMAP_H

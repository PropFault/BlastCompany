#ifndef ENTITYCOMPONENTMANAGER_H
#define ENTITYCOMPONENTMANAGER_H
#include <random>
#include "hashmap.h"
#include <string>
#include "component.h"
#include <unordered_set>
#include <exception>
#include <nlohmann/json.hpp>
#include "namecomponent.h"
#include <fstream>

class EntityComponentManager
{
public:
    typedef unsigned long long CID;
    typedef unsigned long long EID;
private:

    HashMap<std::string, Component*> blueprints;
    HashMap<CID, Component*> cidLookup;
    HashMap<std::string, std::unordered_set<CID>> typeLookup;
    HashMap<EID, std::unordered_set<CID>> entityLookup;
public:
    EntityComponentManager(){
        this->registerBlueprint(new NameComponent());
    }
    class LookupFailedException : public std::exception{
    private:
        std::string message;
    public:
        LookupFailedException(const std::string& message):message(message){}
        const char* what()const throw(){
            return (std::string("LOOKUP FAILED: ")+message).c_str();
        }
    };

    class InitFailedException : public std::exception{
    private:
        std::string message;
    public:
        InitFailedException(const std::string& message):message(message){}
        const char* what()const throw(){
            return (std::string("INIT FAILED: ")+message).c_str();
        }
    };

    void registerBlueprint(Component *comp){
        this->blueprints.insert(comp->getTypeName(), comp);
    }

    EID createNewEntity(const std::string& name){
        std::random_device rd;
        unsigned int seed = rd();
        std::default_random_engine engine(seed);
        std::uniform_int_distribution<long long unsigned> distrib(0, 0xFFFFFFFFFFFFFFFF);
        EID newEnt = distrib(engine);
        std::cout<<"NEW ENTITY: " << newEnt<<std::endl;
        this->entityLookup.insert(newEnt, std::unordered_set<CID>());
        nlohmann::json json;
        json["name"] = name;
        this->addComponentToEntity(newEnt, "name", json);
        return newEnt;
    }
    
    EID createEntityFromFile(const std::string &filePath){
        std::ifstream f(filePath);
        nlohmann::json json;
        f>>json;
        
    }

    std::string lookupEntityName(EID entity){
        std::unordered_set<CID> &entityCID = this->entityLookup.get(entity);
        for(CID id : this->lookupCIDsForType("name")){
            auto foundElement = entityCID.find(id);
            if(foundElement!= entityCID.end())
                return this->lookupCID<NameComponent>(*foundElement)->getName();
        }
    }

    void addComponentToEntity(EID entity, const std::string& componentType, const nlohmann::json& initData){
        try {
            Component* blueprint = this->blueprints.get(componentType);

            Component* newComponent = blueprint->clone();
            try {
                newComponent->init(initData);
            } catch (const std::runtime_error& err) {
                throw InitFailedException(err.what());
            }{}

            this->cidLookup.insert(newComponent->getId(), newComponent);
            this->entityLookup.get(entity).insert(newComponent->getId());
            try{
                this->typeLookup.get(componentType).insert(newComponent->getId());
            }catch(const std::runtime_error &e){
                this->typeLookup.insert(componentType, std::unordered_set<CID>());
                this->typeLookup.get(componentType).insert(newComponent->getId());
            }

        } catch (const std::runtime_error &e) {
            throw std::runtime_error(std::string("UNHANDELED EXCEPTION WHILE ADDING COMPONENT!\nTYPE PASSED: " + componentType + "! INNER EXCEPTION: \n\t") + e.what());
        }
    }

    std::unordered_set <CID> lookupCIDsForType(const std::string &type){
        return this->typeLookup.get(type);
    }

    template<typename T>
    T* lookupCID(CID id){
        return (T*)this->cidLookup.get(id);
    }


};

#endif // ENTITYCOMPONENTMANAGER_H

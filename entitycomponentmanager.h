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
#include <vector>
#include "eid.h"

//This is literally the worst class in the entire program
//too many responsibilities and way too many maps which can lead to errors.

class EntityComponentManager
{

private:

    HashMap<std::string, Component*> blueprints;
    HashMap<Component::CID, Component*> cidLookup;
    HashMap<std::string, std::unordered_set<Component::CID>> typeLookup;
    HashMap<Entity::EID, std::unordered_set<Component::CID>> entityLookup;


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

    Entity::EID createNewEntity(const std::string& name){
        std::random_device rd;
        unsigned int seed = rd();
        std::default_random_engine engine(seed);
        std::uniform_int_distribution<long long unsigned> distrib(0, 0xFFFFFFFFFFFFFFFF);
        Entity::EID newEnt = distrib(engine);
        std::cout<<"NEW ENTITY: " << newEnt<<std::endl;
        this->entityLookup.insert(newEnt, std::unordered_set<Component::CID>());
        nlohmann::json json;
        json["name"] = name;
        this->addComponentToEntity(newEnt, "name", json);
        return newEnt;
    }
    


    Entity::EID createEntityFromFile(const nlohmann::json &json){
        std::cout<<json<<std::endl;
        std::string name = json["name"].get<std::string>();

        Entity::EID entity = createNewEntity(name);


        for(const auto& component : json["components"]){
            std::string type = component["type"].get<std::string>();
            this->addComponentToEntity(entity,type,component["init"]);
        }
        return entity;
    }

    std::string lookupEntityName(Entity::EID entity){
        std::unordered_set<Component::CID> &entityCID = this->entityLookup.get(entity);
        for(Component::CID id : this->lookupCIDsForType("name")){
            auto foundElement = entityCID.find(id);
            if(foundElement!= entityCID.end())
                return this->lookupCID<NameComponent>(*foundElement)->getName();
        }
        throw new LookupFailedException("Could not find entity");
    }

    void addComponentToEntity(Entity::EID entity, const std::string& componentType, const nlohmann::json& initData){
        try {
            Component* blueprint = this->blueprints.get(componentType);
            Component* newComponent = blueprint->clone();
            try {
                newComponent->init(entity,initData);
            } catch (const std::runtime_error& err) {
                throw InitFailedException(err.what());
            }{}

            this->cidLookup.insert(newComponent->getId(), newComponent);
            this->entityLookup.get(entity).insert(newComponent->getId());
            try{
                this->typeLookup.get(componentType).insert(newComponent->getId());
            }catch(const std::runtime_error &e){
                this->typeLookup.insert(componentType, std::unordered_set<Component::CID>());
                this->typeLookup.get(componentType).insert(newComponent->getId());
            }

        } catch (const std::runtime_error &e) {
            throw std::runtime_error(std::string("UNHANDELED EXCEPTION WHILE ADDING COMPONENT!\nTYPE PASSED: " + componentType + "! INNER EXCEPTION: \n\t") + e.what());
        }
    }

    std::unordered_set <Component::CID> lookupCIDsForType(const std::string &type){
        try{
            return this->typeLookup.get(type);
        }catch(const std::runtime_error &ex){
            return std::unordered_set<Component::CID>();
        }
    }

    template<typename T>
    T* lookupCID(Component::CID id){
        return (T*)this->cidLookup.get(id);
    }



};

#endif // ENTITYCOMPONENTMANAGER_H

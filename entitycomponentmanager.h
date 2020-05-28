#ifndef ENTITYCOMPONENTMANAGER_H
#define ENTITYCOMPONENTMANAGER_H
#include <random>
#include <string>
#include "component.h"
#include <unordered_set>
#include <exception>
#include <nlohmann/json.hpp>
#include "namecomponent.h"
#include <fstream>
#include <vector>
#include "eid.h"
#include <unordered_map>
#include <iostream>

//This is literally the worst class in the entire program
//too many responsibilities and way too many maps which can lead to errors.

class EntityComponentManager
{

private:

    std::unordered_map<std::string, Component*> blueprints;
    std::unordered_map<Component::CID, Component*> cidLookup;
    std::unordered_map<std::string, std::unordered_set<Component::CID>> typeLookup;
    std::unordered_map<Entity::EID, std::unordered_set<Component::CID>> entityLookup;
    void initAndLinkComponent(Entity::EID entity, Component* uninitComponent, const nlohmann::json& initData){
        try {
            uninitComponent->init(entity,initData);
        } catch (const std::runtime_error& err) {
            throw InitFailedException(err.what());
        }{}

        this->cidLookup.insert(std::pair(uninitComponent->getId(), uninitComponent));
        this->entityLookup.at(entity).insert(uninitComponent->getId());
        this->typeLookup[uninitComponent->getTypeName()].insert(uninitComponent->getId());


    }
    Component* generateNewComponent(const std::string& componentType){
        Component* blueprint = this->blueprints.at(componentType);
        Component* newComponent = blueprint->clone();
        return newComponent;
    }

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
        this->blueprints.insert(std::pair(comp->getTypeName(), comp));
    }

    Entity::EID createNewEntity(const std::string& name){
        std::random_device rd;
        unsigned int seed = rd();
        std::default_random_engine engine(seed);
        std::uniform_int_distribution<long long unsigned> distrib(0, 0xFFFFFFFFFFFFFFFF);
        Entity::EID newEnt = distrib(engine);
        std::cout<<"NEW ENTITY: " << newEnt<<std::endl;
        this->entityLookup.insert(std::pair(newEnt, std::unordered_set<Component::CID>()));
        nlohmann::json json;
        json["name"] = name;
        this->addComponentToEntity(newEnt, "name", json);
        return newEnt;
    }
    


    Entity::EID createEntityFromFile(const nlohmann::json &json){
        std::cout<<json<<std::endl;
        std::string name = json["name"].get<std::string>();

        Entity::EID entity = createNewEntity(name);

        std::unordered_map<std::string, Component::CID> componentLinks;
        std::unordered_map<Component*, nlohmann::json::object_t> pregeneratedComponents;
        std::cout<<"reading from file"<<std::endl;
        for(const auto& component : json["components"]){
            Component* newComp = this->generateNewComponent(component["type"].get<std::string>());
            std::cout<<component<<std::endl;
            pregeneratedComponents.insert(std::pair(newComp, component["init"].get<nlohmann::json::object_t>()));

            try {
                const std::string& val = component.at("id").get<std::string>();
                componentLinks.insert(std::pair(val, newComp->getId()));
            } catch (const nlohmann::detail::out_of_range &ex) {
                std::cout<<"Component "<<newComp->getTypeName()<<" is not specified as linkable"<<std::endl;
            }{}
        }

        for(auto it = pregeneratedComponents.begin(); it != pregeneratedComponents.end(); ++it){
            for(const auto& initPart : it->second){
                std::cout<<initPart<<std::endl;
                try {
                    std::string stringVal = initPart.second.get<std::string>();
                    if(componentLinks.count(stringVal) > 0){
                        it->second[initPart.first] = componentLinks.at(initPart.second);
                    }
                } catch (const nlohmann::detail::type_error &ex) {
                    std::cout<<ex.what()<<std::endl;
                }{}
            }
            std::cout<<it->second<<std::endl;
            initAndLinkComponent(entity,it->first, it->second);
        }
        return entity;
    }

    std::string lookupEntityName(Entity::EID entity){
        std::unordered_set<Component::CID> &entityCID = this->entityLookup.at(entity);
        for(Component::CID id : this->lookupCIDsForType("name")){
            auto foundElement = entityCID.find(id);
            if(foundElement!= entityCID.end())
                return this->lookupCID<NameComponent>(*foundElement)->getName();
        }
        throw new LookupFailedException("Could not find entity");
    }


public:


    void addComponentToEntity(Entity::EID entity, const std::string& componentType, const nlohmann::json& initData){
        try {

            initAndLinkComponent(entity, generateNewComponent(componentType), initData);
        } catch (const std::runtime_error &e) {
            throw std::runtime_error(std::string("UNHANDELED EXCEPTION WHILE ADDING COMPONENT!\nTYPE PASSED: " + componentType + "! INNER EXCEPTION: \n\t") + e.what());
        }
    }

    std::unordered_set <Component::CID> lookupCIDsForType(const std::string &type){
        try{
            return this->typeLookup.at(type);
        }catch(const std::runtime_error &ex){
            return std::unordered_set<Component::CID>();
        }
    }

    template<typename T>
    T* lookupCID(Component::CID id){
        return dynamic_cast<T*>(this->cidLookup.at(id));
    }



};

#endif // ENTITYCOMPONENTMANAGER_H

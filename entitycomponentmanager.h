#ifndef ENTITYCOMPONENTMANAGER_H
#define ENTITYCOMPONENTMANAGER_H
#include <random>
#include "hashmap.h"
#include <string>
#include "component.h"
#include <vector>
#include <exception>
#include <nlohmann/json.hpp>

class EntityComponentManager
{
public:
    typedef unsigned long long CID;
    typedef unsigned long long EID;
private:

    HashMap<std::string, Component*> blueprints;
    HashMap<CID, Component*> cidLookup;
    HashMap<std::string, std::vector<CID>> typeLookup;
    HashMap<EID, std::vector<CID>> entityLookup;
public:
    EntityComponentManager();
    class LookupFailedException : public std::exception{
    private:
        std::string message;
    public:
        LookupFailedException(const std::string& message):message(message){}
        const char* what()const throw(){
            return (std::string("LOOKUP FAILED: ")+message).c_str();
        }
    };

    void registerBlueprint(Component *comp){
        this->blueprints.insert(comp->getName(), comp);
    }

    EID createNewEntity(){
        std::random_device rd;
        unsigned int seed = rd();
        std::default_random_engine engine(seed);
        std::uniform_int_distribution<long long unsigned> distrib(0, 0xFFFFFFFFFFFFFFFF);
        EID newEnt = distrib(engine);
        std::cout<<"NEW ENTITY: " << newEnt<<std::endl;
        this->entityLookup.insert(newEnt, std::vector<CID>());
        return newEnt;
    }

    void addComponentToEntity(EID entity, const std::string& componentType, const nlohmann::json& initData){
        try {
            Component* blueprint = this->blueprints.get(componentType);

            Component* newComponent = blueprint->clone();
            newComponent->init(initData);
            this->cidLookup.insert(newComponent->getId(), newComponent);
            this->entityLookup.get(entity).push_back(newComponent->getId());
            try{
                this->typeLookup.get(componentType).push_back(newComponent->getId());
            }catch(const std::runtime_error &e){
                this->typeLookup.insert(componentType, std::vector<CID>());
                this->typeLookup.get(componentType).push_back(newComponent->getId());
            }

        } catch (const std::runtime_error &e) {
            throw LookupFailedException("TYPE PASSED: " + componentType + "! INNER EXCEPTION: " + e.what());
        }
    }

    std::vector<CID> lookupCIDsForType(const std::string &type){
        return this->typeLookup.get(type);
    }

    Component* lookupCID(CID id){
        return this->cidLookup.get(id);
    }


};

#endif // ENTITYCOMPONENTMANAGER_H

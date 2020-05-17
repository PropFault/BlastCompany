#ifndef HASHNODE_H
#define HASHNODE_H
#include <stdexcept>
template <typename k, typename v>
class HashNode
{
private:
    k key;
    v value;
    bool isInit;
public:
    HashNode():isInit(false){

    }
    HashNode(const k &key, const v &value):key(key), value(value), isInit(true) {
    }


    void init(const k &key, const v&value)
    {
        if(this->isInit == true)
            throw std::runtime_error("double init of node!");
        this->key = key;
        this->value = value;
        this->isInit = true;
    }

    void clear()
    {
        this->isInit = false;
    }
    const k& getKey() const
    {
        return key;
    }
    v& getValue()
    {
        return value;
    }

    bool getIsInit() const{
        return isInit;
    }
};

#endif // HASHNODE_H

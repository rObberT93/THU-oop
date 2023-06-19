#include <unordered_map>
#include <list>
#include <iostream>

template<class Key>
class PopStrategy {
public:
    virtual void visit(const Key& key) = 0;
    virtual Key pop() = 0;
};

template<class Key>
class FIFOStrategy : public PopStrategy<Key> {
private:
    std::unordered_map<Key, typename std::list<Key>::iterator> keyMap;
    std::list<Key> keys;
public:
    void visit(const Key& key) {
        if (keyMap.find(key) == keyMap.end()) {
            keys.push_back(key);
            keyMap[key] = std::prev(keys.end());
        }
    }

    Key pop() {
        Key key = keys.front();
        keys.pop_front();
        keyMap.erase(key);
        return key;
    }
};

template<class Key>
class LRUStrategy : public PopStrategy<Key> {
private:
    std::unordered_map<Key, typename std::list<Key>::iterator> keyMap;
    std::list<Key> keys;
public:
    void visit(const Key& key) {
        if (keyMap.find(key) == keyMap.end()) {
            keys.push_front(key);
            keyMap[key] = keys.begin();
        } else {
            keys.splice(keys.begin(), keys, keyMap[key]);
            keyMap[key] = keys.begin();
        }
    }

    Key pop() {
        Key key = keys.back();
        keys.pop_back();
        keyMap.erase(key);
        return key;
    }
};

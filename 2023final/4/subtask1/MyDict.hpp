#pragma once
#include <map>
#include "HitStatsResult.hpp"

template<class Key, class Value>
class MyDict {
private:
    std::map<Key, Value> dict;
    int hitCount;
    int missCount;

public:
    MyDict() : hitCount(0), missCount(0) {}

    Value& operator[](const Key& key) {
        auto it = dict.find(key);
        if (it != dict.end()) {
            ++hitCount;
            return it->second;
        } else {
            ++missCount;
            return dict[key];
        }
    }

    HitStatsResult hitStats() const {
        return HitStatsResult(hitCount, missCount);
    }

    int size() const {
        return dict.size();
    }

    void clear() {
        dict.clear();
        hitCount = 0;
        missCount = 0;
    }
};

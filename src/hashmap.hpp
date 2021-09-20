#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <string>
#include <unordered_map>

template <typename Key, typename Value>
class HashMap {
 private:
  std::unordered_map<Key, Value> dictionary;
  std::unordered_map<Key, bool> existance;

 public:
  // To check whether the hash map contains value for given key
  bool contains(Key key) {
    return existance[key] == true;
  }

  // Returns value for given key
  Value value(Key key) {
    if (this->contains(key)) {
      return this->dictionary[key];
    }
    throw "Not Found";
  }

  // Set value for given key
  void set(Key key, Value value) {
    this->dictionary[key] = value;
    this->existance[key] = true;
  }

  // Remove value for given key
  void remove(Key key) {
    this->dictionary.erase(key);
    this->existance[key] = false;
  }
};

#endif
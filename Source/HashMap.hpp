#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <string>

template <typename Key, typename Value>
class HashMap {
 private:
  std::unordered_map<Key, Value> dictionary;

 public:
  // To check whether the hash map contains value for given key
  bool contains(Key key) {
    return dictionary.find(key) != dictionary.end();
  }

  // Returns value for given key
  Value get(Key key) {
    if (contains(key)) {
      return dictionary[key];
    }
    throw "Not Found";
  }

  // Set value for given key
  void set(Key key, Value value) {
    dictionary[key] = value;
  }

  // Remove value for given key
  void remove(Key key) {
    dictionary.erase(key);
  }

  std::vector<Key> allKeys() {
    std::vector<Key> keys;
    for (std::pair<Key, Value> item : dictionary) {
      keys.push_back(item.first);
    }
    return keys;
  }
};

#endif
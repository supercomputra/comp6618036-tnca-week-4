#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <string>

template <typename Key, typename Value>
class HashMap {
 private:
  std::unordered_map<Key, Value> dictionary;

 public:
  HashMap<Key, Value>() {}

  /**
   * To check whether the hash map contains value for given key
   * 
   * @param key the key
   * @return boolean telling whether the key exists or not
  */
  bool contains(Key key) {
    return dictionary.find(key) != dictionary.end();
  }

  /**
   * Returns value for given key
   * 
   * @param key the key
   * @return the associated value for the given key
  */
  Value get(Key key) {
    if (contains(key)) {
      return dictionary[key];
    }
    throw "Not Found";
  }

  /**
   * Set key value
   * 
   * @param key the key
   * @param value the value
  */
  void set(Key key, Value value) {
    dictionary[key] = value;
  }

  /**
   * Remove value for given key
   * 
   * @param key the key
  */
  void remove(Key key) {
    dictionary.erase(key);
  }

  /**
   * Get all available keys
   * 
   * @return list of available keys
  */
  std::vector<Key> allKeys() {
    std::vector<Key> keys;
    for (std::pair<Key, Value> item : dictionary) {
      keys.push_back(item.first);
    }
    return keys;
  }
};

#endif
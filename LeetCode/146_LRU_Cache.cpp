class LRUCache {
  public:
    LRUCache(int capacity): cap(capacity) {}

    int get(int key) {
      if (!kv.count(key)) return -1;

      li.push_back(key);
      li.erase(kl[key]);
      kl[key] = prev(li.end());
      return kv[key];
    }

    void put(int key, int value) {
      if (~get(key)) {
        kv[key] = value;
        return;
      }

      kv[key] = value;
      li.push_back(key);
      if (li.size() > cap) {
        kv.erase(li.front());
        li.pop_front();
      }
      kl[key] = prev(li.end());
    }

  private:
    const int cap;
    list<int> li;
    unordered_map<int, int> kv;
    unordered_map<int, decltype(li.begin())> kl;
};

/*
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

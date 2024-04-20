class TimeMap {
  public:
    void set(string key, string value, int timestamp) {
      tm[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
      auto it = tm[key].upper_bound(timestamp);
      if (it != tm[key].begin()) return prev(it)->second;
      else return "";
    }

  private:
    unordered_map<string, map<int, string>> tm;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

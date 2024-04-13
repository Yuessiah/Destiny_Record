class RangeModule {
  public:
    RangeModule() {
    }

    void addRange(int left, int right) {
      map<int, int> newInterval;
      for(auto& [l, r]: interval) {
        bool use = false;
        if(r >= left && l < left) left = l, use = true;
        if(l <= right && r > right) right = r, use = true;
        if(left <= l && r <= right) use = true;
        if(!use) newInterval[l] = r;
      }

      newInterval[left] = right;
      interval = newInterval;
    }

    bool queryRange(int left, int right) {
      for(auto [l, r]: interval) {
        if(l <= left && right <= r) return true;
        if(left < l && l < right) right = l;
        else if(right > r && r > left) left = r;
      }

      return false;
    }

    void removeRange(int left, int right) {
      for(auto& [l, r]: interval) {
        if(left <= l && r <= right) {
          r = l;
        } else if(l <= left && right <= r) {
          interval[right] = r;
          r = left; // interval[l] = left;
        } else if(left <= l && l < right) {
          interval[right] = r;
          r = l;
        } else if(left < r && r <= right) {
          r = left;
        }
      }
    }

  private:
    map<int, int> interval;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

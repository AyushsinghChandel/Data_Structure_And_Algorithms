class TimeMap {
private:
    unordered_map< string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()){
            return "";
        }
        const auto& values = store[key];
        int left = 0;
        int right = values.size() - 1;
        string result = "";
        while(left <= right){
            int mid = left + (right - left)/2;
            if(values[mid].first <= timestamp){
                left = mid + 1;
                result = values[mid].second;
            }
            else{
                right = mid - 1;
            }
        }
        return result;
    }
};

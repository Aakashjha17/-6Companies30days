class StockPrice {
private:
    map<int,int> mp; //{time -> price}
    multiset<int> prices;
public:
    StockPrice() {
        mp.clear();
        prices.clear();
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)){
            int oldPrice = mp[timestamp];
            prices.erase(prices.find(oldPrice));
        }

        mp[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *(prices.rbegin());
    }
    
    int minimum() {
        return *(prices.begin());
    }
};

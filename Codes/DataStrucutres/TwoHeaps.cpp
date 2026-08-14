multiset<int> low;  
multiset<int> high;  
void balance() {  
    int total = low.size() + high.size();  
    int need = (total + 1) / 2;  
    while (low.size() > need) {  
        auto it = prev(low.end());  
        high.insert(*it);  
        low.erase(it);  
    }  
    while (low.size() < need) {  
        auto it = high.begin();  
        low.insert(*it);  
        high.erase(it);  
    }  
}  
void add(int x) {  
    if (low.empty() || x <= *low.rbegin())  
        low.insert(x);  
    else  
        high.insert(x);  
    balance();  
}  
void remove(int x) {  
    auto it = low.find(x);  
    if (it != low.end())  
        low.erase(it);  
    else {  
        it = high.find(x);  
        high.erase(it);  
    }  
    balance();  
}
// true if item exists, false if not  
auto f = binary_search(vct.begin(), vct.end(), val);  

// Return iterator to first element in the given range that is > than the given value.
auto i = upper_bound(vct.begin(), vct.end(), val);

// Return iterator to first element in the given range that is >= to the given value.
auto g = lower_bound(vct.begin(), vct.end(), val);
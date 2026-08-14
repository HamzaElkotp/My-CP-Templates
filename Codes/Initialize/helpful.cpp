// fill vector with values starting from x to n
iota(allv(vct), x);


// Find in string
str.find('x') != variant_npos;


// Get char to the line end
int c = 0;  
while((c=getchar()) != '\n' && c != EOF){};


// String to Int
stoi(str);

// Integer to string
to_string(num);


// Random Value
mt19937 rng(1337)


// Sort Map
map<string, int> myMap = {{"apple",5},{"banana",2},{"cherry",8}};
// 1. Copy map elements to a vector of pairs
vector<pair<string, int>> vec(myMap.begin(), myMap.end());
// 2. Sort the vector using a lambda comparing the second value
sort(allv(vec), [](const auto& a, const auto& b) {
   return a.second < b.second; // Use > for descending order
});
// Print sorted results
for (const auto& pair : vec) {
   cout << pair.first << ": " << pair.second << "\n";
}
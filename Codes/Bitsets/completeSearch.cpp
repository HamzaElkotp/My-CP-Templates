vector<vector<int>> generateSubsets(vector<int>& arr) {  
   int n = arr.size();  
   vector<vector<int>> subsets;
   for(int mask=0; mask<(1<<n); mask++) {  
      vector<int> subset;
      for(int i = 0; i < n; i++) {  
         if(knowBit(mask, i))
            subset.push_back(arr[i]);  
      }
      subsets.push_back(subset);  
   }  
   sort(subsets.begin(), subsets.end());  
   return subsets;  
}
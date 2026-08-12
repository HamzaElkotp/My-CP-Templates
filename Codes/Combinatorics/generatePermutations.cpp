set<string> stringPermutations(string s){
    sort(allArr(s));
    set<string> words;
    do { 
        words.insert(s);  
    } while (next_permutation(allv(s)));
    return words;
}

set<vector<int>> vectorPermutations(vector<int> vct){
    sort(allArr(vct));
    set<vector<int>> res;
    do {  
        res.insert(vct);  
    } while (next_permutation(allv(vct)));
}

void generatePermutations(string& str, int lft, int rt) { // O(n*n!);
	if (lft == rt) {
		cout<<str<<"\n";
		return;
	}
	for (int i=lft; i<=rt; i++) {
		swap(str[lft], str[i]);
		generatePermutations(str, lft+1, rt);
		swap(str[lft], str[i]);
	}
}

// string str = "ABC";
// int n = str.length();
// generatePermutations(str, 0, n - 1);
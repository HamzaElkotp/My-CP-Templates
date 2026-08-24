int mex(vector<int> const& A) {
    set<int> b(allv(A));
    int result = 0;
    while (b.count(result)) ++result;
    return result;
}
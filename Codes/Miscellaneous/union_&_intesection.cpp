set_intersection(
   allv(setA),
   allv(setB),
   back_inserter(intersection_result)
);

vector<int> union_result;
set_union(
   allv(setA),
   allv(setB),
   back_inserter(union_result)
);
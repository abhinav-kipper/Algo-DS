//Find the contiguous sub-array with maximum sum

int kadaneAlgo(vector<int>& v, int n) {
    int max_so_far = v[0], max_ending_here = v[0];
    for (int i=1;i<n;i++){
        max_ending_here= max(v[i], max_ending_here+v[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

class Solution {
public:
    long long hrtaken(vector<int> pi, int h) {
        long long hr = 0;
        for (auto i : pi) {
            hr += ceil((double)i/(double)h);
        }
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxt = -1;
        int m = -1;

        for (auto i : piles)
            m = max(m, i);

        int low = 1, high = m;
        while (low <= high) {
            long long hr=INT_MAX;
            int mid = low + (high - low) / 2;
            hr = hrtaken(piles, mid);
            if (hr <= h) {
                maxt = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return maxt;
    }
};


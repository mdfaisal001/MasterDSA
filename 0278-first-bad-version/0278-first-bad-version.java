/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int low = 1, high = n, bad = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            boolean isBad = isBadVersion(mid);
            if(isBad == true) {
                bad = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        return bad;
    }
}
import java.util.*;

class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        // Create a map to store the positions of each number in the matrix
        Map<Integer, List<int[]>> map = new HashMap<>();
        int m = mat.length;
        int n = mat[0].length;
        
        // Populate the map with matrix values and their positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map.putIfAbsent(mat[i][j], new ArrayList<>());
                map.get(mat[i][j]).add(new int[]{i, j});
            }
        }
        
        // Initialize frequency arrays for rows and columns
        int[] freqRow = new int[m];
        int[] freqCol = new int[n];
        
        // Iterate over the elements of the array
        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(arr[i])) {
                for (int[] pair : map.get(arr[i])) {
                    freqRow[pair[0]]++;
                    freqCol[pair[1]]++;
                    
                    // Check if any row or column is completely filled
                    if (freqRow[pair[0]] == n || freqCol[pair[1]] == m) {
                        return i;
                    }
                }
            }
        }
        
        return 0; // Default return value if no complete row/column is found
    }
}

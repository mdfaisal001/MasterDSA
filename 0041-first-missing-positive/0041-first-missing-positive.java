class Solution {

    static void swap(int[] nums,int val1, int val2){
        int temp = nums[val1];
         nums[val1] = nums[val2];
         nums[val2] = temp;
    }
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i=0; i<nums.length; i++){
            
            while(nums[i] >0 && nums[i] <=n && nums[i] != nums[nums[i]-1]){
                 swap(nums,i,nums[i]-1);
            }
         }

         for(int i=0; i<nums.length; i++){
            if(i != nums[i]-1) return i+1;
         }

         return nums.length + 1;
     }

 }


/*  HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            mp.put(nums[i],i);
        }

        for(int i=1 ; i<=nums.length ;i++){
            if(!mp.containsKey(i)){
                return i;
            }
        }
        return nums.length + 1;*/
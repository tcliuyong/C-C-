package test;

import java.util.ArrayList;

public class Solution {
    public ArrayList<Integer> continuousSubarraySum(int[] a) {
        // Write your code here
        int start = 0;
        int end = 0;
        int sum = 0;
        int l = 0;
        int  max=-65535;
         ArrayList<Integer> arr1 = new ArrayList<Integer>();
        for(int i = 0; i < a.length; i++)
        {
              if(sum>=0)  
                sum=sum+a[i];
               else       
               {
                sum=a[i];
                l=i;
               }
               if(sum>max) 
               {
                max=sum;
                start=l;
                end=i;
        }
}
        arr1.add(start);
        arr1.add(end);
        arr1.add(max);
        return arr1;
}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int A[] = {-3,1,3,-3,4};
		arr = new Solution().continuousSubarraySum(A);
		for(Integer i : arr)
		System.out.println(i);
	
	}

}

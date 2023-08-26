import java.util.Scanner;
class Main
{
    public static int binarySearch(int[] nums, int left, int right, int target)
    {
        if (left > right) 
            return -1;
        int mid = (left + right) / 2;
        if (target == nums[mid]) 
            return mid;
         else if (target < nums[mid]) 
            return binarySearch(nums, left, mid - 1, target);
        else 
            return binarySearch(nums, mid + 1, right, target); 
    }
    public static void main(String[] args)
    {
         int c, n, search, array[];   
    Scanner in = new Scanner(System.in);  
    System.out.println("Enter number of elements");  
    n = in.nextInt();   
    array = new int[n];  
    System.out.println("Enter those " + n + " elements");   
    for (c = 0; c < n; c++)  
      array[c] = in.nextInt();  
    System.out.println("Enter value to find");  
    search = in.nextInt();
    in.close();    
        int left = 0;
        int right = array.length - 1;
        int index = binarySearch(array, left, right, search);
        if (index != -1) {
            System.out.println("Element found at index " + index);
        }
        else {
            System.out.println("Element not found in the array");
        }
    }
}

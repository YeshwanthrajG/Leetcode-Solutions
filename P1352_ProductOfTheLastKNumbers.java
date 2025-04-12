/* 
Problem ID : 1352 

Problem : Product of the Last K Numbers

Statement : Design an algorithm that accepts a stream of integers and retrieves the product of the last k 
integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that 
always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will 
fit into a single 32-bit integer without overflowing.
*/

/* Problem Link
https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14
*/

class ProductOfNumbers {
    ArrayList<Integer> list=new ArrayList<>();
    int pro=1;

    public ProductOfNumbers() {
        
    }
    
    public void add(int num) {
        if(num==0)
        {
            list=new ArrayList<>();
            pro=1;
            return;
        }
        pro*=num;
        list.add(pro);
    }
    
    public int getProduct(int k) {
        
        int n=list.size();
        if(n<k)
            return 0;
        int ans=list.get(n-1);
        if(n==k)
            return ans;
        
        return ans/list.get(n-1-k);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
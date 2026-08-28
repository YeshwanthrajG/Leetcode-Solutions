/* 
Problem ID : 1114 

Problem : Print in Order

Statement : Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), 
thread B will call second(), and thread C will call third(). Design a mechanism and modify the 
program to ensure that second() is executed after first(), and third() is executed after second().

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in 
the input seem to imply the ordering. The input format you see is mainly to ensure our tests' 
comprehensiveness.
*/

/* Problem Link
https://leetcode.com/problems/print-in-order/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Foo {
public:
    mutex m;
    condition_variable cv;
    int t;

    Foo() {
        t=1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        t=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        while(t!=2) cv.wait(lock);
        printSecond();
        t=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        while(t!=3) cv.wait(lock);
        printThird();
    }
};
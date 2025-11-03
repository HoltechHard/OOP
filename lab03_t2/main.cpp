// ==========================================
// DATA STRUCTURE STACK  
// ==========================================
//
// Create a class template MyStack for storing elements of any type T.
// As a base for the stack, you may choose an array.
// A constant template parameter can be used to define
// the maximum stack size.

// The mandatory stack operations are: Push, Pop, GetSize, and Capacity.
// Optional operation – selection by index (operator[]).
// To guarantee proper execution of these operations,
// you should generate exceptions.

// Using the MyStack template, create a stack of int variables,
// then a stack of double variables, and finally a stack of Vector variables.
// If you prepare three exception-handling classes,
// the following fragment should work

#include <iostream>
#include <cstddef>   // for size_t
using namespace std;

// ================== Exceptions ==================
struct StackOverflow { /* marker type */ };

struct StackUnderflow { /* marker type */ };

class StackOutOfRange {
    size_t index_;
    size_t size_;
public:
    StackOutOfRange(size_t index, size_t size) : index_(index), size_(size) {}
    void Out() const {
        cout << "\nStack index out of range: " << index_
             << " (current size: " << size_ << ")";
    }
};

// ================== Minimal Vector ==================
class Vector {
    double x_, y_;

public:
    Vector(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

    void Out() const{ 
        cout << "(" << x_ << ", " << y_ << ")"; 
    }

    // Optional comparisons (handy for later tasks like sort/merge/remove)
    bool operator<(const Vector& other) const {
        // Lexicographic compare by (x, y)
        if (x_ != other.x_) 
            return x_ < other.x_;
        return y_ < other.y_;
    }

    bool operator==(const Vector& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
};

// ================== MyStack<T, N> ==================
template <typename T, size_t N>
class MyStack {
    T data_[N];
    size_t top_; 

public:
    MyStack() : top_(0) {}

    // Push element on top; throw if overflow
    void Push(const T &value) {
        if (top_ == N) 
            throw StackOverflow{};
        data_[top_++] = value;
    }

    // Optionally support move-push for efficiency
    void Push(T &&value) {
        if (top_ == N) 
            throw StackOverflow{};
        data_[top_++] = std::move(value);
    }

    // Pop and return top element; throw if underflow
    T Pop() {
        if (top_ == 0) 
            throw StackUnderflow{};
        // Return by value; move helps for heavy T
        return std::move(data_[--top_]);
    }

    // Current number of elements
    size_t GetSize() const { return top_; }

    // Fixed capacity (N)
    size_t Capacity() const { return N; }

    // Bounds-checked index access (throws if idx >= size)
    T &operator[](size_t idx) {
        if (idx >= top_) throw StackOutOfRange(idx, top_);
        return data_[idx];
    }
    const T &operator[](size_t idx) const {
        if (idx >= top_) throw StackOutOfRange(idx, top_);
        return data_[idx];
    }
};

// ================== Your test driver ==================
int main() {
    try
    {
        cout << "Test MyStack\n";
        MyStack<int, 5> stack;

        cout << "\nInteger Stack capacity: " << stack.Capacity();

        stack.Push(10);
        stack.Push(20);
        stack.Push(30);
        stack.Push(40);
        stack.Push(50);

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

        //stack.Push(4);   // An exception should be thrown here

        cout << "\nInteger Stack pops: " << stack.Pop();
        cout << "\nInteger Stack pops: " << stack.Pop();

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

        stack.Pop();
        stack.Pop();
        //stack.Pop();
        //stack.Pop();    // An exception should be thrown here
        //stack.Push(2);

        //int i = stack[3];  // An exception should be thrown here
        //(void)i;           // silence unused variable warning

        MyStack<Vector, 5> ptStack;

        cout << "\nVector Stack capacity: " << ptStack.Capacity();

        ptStack.Push(Vector(1, 1));
        ptStack.Push(Vector(2, 2));
        ptStack.Push(Vector(3, 3));
        ptStack.Push(Vector(4, 4));
        //ptStack.Push(Vector(4, 4));
        //ptStack.Push(Vector(4, 4));

        cout << "\nVector Stack pops: ";
        // Use the Vector class method for outputting an element
        ptStack.Pop().Out();

        cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
    }
    catch (StackOverflow)
    {
        cout << "\nStack overflow";
    }
    catch (StackUnderflow)
    {
        cout << "\nStack underflow";
    }
    catch (StackOutOfRange o)
    {
        o.Out();
    }

    cout << "\n\n";
    return 0;
}

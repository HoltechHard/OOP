// =================================================================
//  Task 3. Standard Library Containers - Sequences of type vector
// =================================================================

// CONTAINER VECTOR

// 1. Create an empty vector of integers. Find its size using the size() method.
// 2. Use the push_back() method to fill the vector with any values.
// 3. Get the new size of the vector and display its elements.
// 4. While working with the vector, you can, in addition to the number of
//    actually filled elements (size()), find out the maximum possible number
//    of elements (max_size()) and the reserved memory (capacity())

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// A template function for printing any container
template <class T> 
void pr(const T &v, const string &s)
{
    cout << "\n\n === " << s << "  # Sequence === \n";
    
    // Iterator of any container
    typename T::const_iterator p;
    size_t i;

    for (p = v.begin(), i = 0; p != v.end(); p++, i++)
        cout << endl << "Element " << i + 1 << " ==> " << *p;
    cout << '\n';
}

template <class T>
void print_vectinfo(const vector<T> &v, const string &label)
{
    std::cout << label << " -> size: " << v.size()
              << ", capacity: " << v.capacity()
              << ", max_size: " << v.max_size() << '\n';
}

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


int main(){

    // --- vector of integers ---
    vector<int> v;

    print_vectinfo(v, "Initial vector");
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    
    print_vectinfo(v, "After 1st push");
    
    // Since we will often output sequences, it makes sense
    // to create a template function for printing any container.
    // Analyze the code of such a template (pr) given above.
    // Use it to print your vector.

    pr(v, "Vector of ints");

    // Remove the last element
    v.pop_back();

    // Print vector again
    pr(v, "Vector of ints after pop_back");

    // --- vector of doubles ---
    
    // Use another constructor to create a vector of doubles
    // with an initial size of 2 elements and fill it with (222.)
    // Then resize and check parameters again.

    vector<double> vd(2, 222.0);

    print_vectinfo(vd, "Initial vector (size 2, filled with 222.0)");
    pr(vd, "Vector of doubles (initial)");

    // Change size and fill with a new value
    vd.resize(5, 555.0);

    print_vectinfo(vd, "After resize to size 5 (filled with 555.0)");
    pr(vd, "Vector of doubles (after resize)");

    // Using the at() method and the selection operator [],
    // change the values of some elements of the vector and check the result.
    
    // Using operator[] (no bounds checking)
    vd[0] = 1000.0;

    // Using at() (with bounds checking)
    vd.at(2) = 2000.0;

    print_vectinfo(vd, "vector<double> after edits with [] and at()");
    pr(vd, "After at");

    // Copy entire vector
    vector<double> wd(vd);
    print_vectinfo(wd, "Copied vector<double> (wd)");
    pr(wd, "Copy");

    // Copy part of an existing sequence (e.g., first 3 elements)
    vector<double> ud(vd.begin()+1, vd.begin() + 3);
    print_vectinfo(ud, "Partial copy of vector<double> (ud)");
    pr(ud, "Copy part");

    // --- vector of strings ---
    // Create a character vector that is a copy of a portion of a regular string
	char s[] = "This array is a succession of chars";
	
	vector<char> vc(s, s + strlen(s));
	pr(vc, "Copy part of c-style string");

    // --- vector of Vectors ---
    // Create a vector of elements of type Vector and 
    // initialize it with a vector with coordinates (1,1).
	
    vector<Vector> vv(4, Vector(1, 1));
	
	cout << "\n\n Vector of Vectors\n";
    
    for(int i=0;  i < vv.size();  i++){
        cout<<"Element "<<i+1<< ": ";
        vv[i].Out();
        cout<<endl;
    }		
    
    // --- vector to pointers to Vectors ---    
    // Create a vector of pointers to Vector and initialize it
    // with the addresses of Vector class objects.
    
    Vector vx(1, 2);
    vector<Vector*> vp(4, &vx);
    
    cout << "\n\nVector of pointers to Vector\n";
    
    for(int i = 0; i < vp.size(); i++){
        cout<<"Element "<<i+1<< ": ";
        vp[i]->Out();
        cout<<endl;
    }        

    // --- Additional vector methods ---
    // Create and initialize a vector of char elements. Size – any.
    vector<char> vc2 = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    
    pr(vc2, "Vector of chars");
    
     // Get the value of the first element of the vector (front())
    if (!vc2.empty()) {
        cout << "vc.front(): '" << vc2.front() << "'\n";
    } else {
        cout << "vc is empty; no front()\n";
    }

    // Get the value of the last element of the vector (back())
    if (!vc2.empty()) {
        cout << "vc.back(): '" << vc2.back() << "'\n";
    } else {
        cout << "vc is empty; no back()\n";
    }

    // Get the size of the vector
    cout << "vc.size(): " << vc2.size() << '\n';

    return 0;
}

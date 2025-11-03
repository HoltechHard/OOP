// ========================================================
// Task 4. Lists. Operations characteristic for lists.
// ========================================================

// CONTAINER LIST

// 1. Create two empty lists of Vector elements – ptList1 and ptList2
// 2. Fill both lists with values using push_back(), push_front(), insert()
// 3. Sort the lists – sort().
// 4. Merge the sorted lists – merge(). See what happens to the second list afterwards
// 5. Remove an element from the list – remove()

#include <iostream>
#include <list>
using namespace std;

class Vector {
    int x, y;
public:
    Vector(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
    void Out() const {
        cout << "(" << x << ", " << y << ")";
    }
    // Required for sorting (lexicographic by x then y)
    bool operator<(const Vector& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    // Required for remove(value)
    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y;
    }
    // For easier printing with ostream
    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

void printList(const list<Vector>& L, const string& name) {
    cout << name << " (size=" << L.size() << "): ";
    for (const auto &v : L) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {

    // initialize two empty lists of Vector elements
    list<Vector> ptList1;
    list<Vector> ptList2;

    // Fill both lists with values using push_back(), push_front(), insert()
    
    // For ptList1:
    ptList1.push_front(Vector(1, 5));  // front: (1,5)
    ptList1.push_back(Vector(3, 1));   // back: (3,1)    
    
    // insert after begin (i.e., between front and back)
    {
        auto it = ptList1.begin();
        ++it; // position after the current front
        ptList1.insert(it, Vector(2, 2)); // now list: (1,5) (2,2) (3,1)
    }

    // For ptList2:
    ptList2.push_back(Vector(4, 0));
    ptList2.push_back(Vector(2, -1));
    ptList2.push_front(Vector(0, 9));
    
    // insert somewhere in the middle: after first element
    {
        auto it = ptList2.begin();
        ++it; // position after front
        ptList2.insert(it, Vector(2, 3)); // e.g., (0,9) (2,3) (4,0) (2,-1)
    }
    
    cout << "-- BEFORE sort() --\n";
    printList(ptList1, "ptList1");
    printList(ptList2, "ptList2");

    // Sort the lists – sort()    
    ptList1.sort();
    ptList2.sort();

    cout << "\n-- AFTER sort() --\n";
    printList(ptList1, "ptList1");
    printList(ptList2, "ptList2");

    // Merge the sorted lists – merge(). See what happens to the second list afterwards.
    // list::merge assumes both lists are sorted; it transfers elements from ptList2 into ptList1.
    ptList1.merge(ptList2);

    cout << "\n-- AFTER merge(ptList2 into ptList1) --\n";
    printList(ptList1, "ptList1");
    printList(ptList2, "ptList2 (should be empty after merge)");

    // Remove an element from the list – remove()
    // Remove an element with a specific value
    Vector toRemove(2, 2); // this value exists in ptList1 (from earlier)
    cout << "\nRemoving element " << toRemove << " from ptList1...\n";
    ptList1.remove(toRemove);

    cout << "\n-- AFTER remove() --\n";
    printList(ptList1, "ptList1");

    return 0;
}

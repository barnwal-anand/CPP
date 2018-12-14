Compile time polymorphism:
--------------------------


Run Time Polymorphism in a function:
We can make a function polymorphic by passing objects as reference (or pointer) to it.
print() calls the base class function show() if base class object is passed, and derived class function show() if derived class object is passed.
If reference is not used, then If we pass an object of subclass to a function that expects an object of superclass
then the passed object is sliced if it is pass by value.
class base {
public:
    virtual void show() {  // Note the virtual keyword here
        cout<<"In base \n";
    }
};


class derived: public base {
public:
    void show() {
        cout<<"In derived \n";
    }
};

// Since we pass b as reference, we achieve run time polymorphism here.
void print(base &b) {
    b.show();
}

int main(void) {
    base b;
    derived d;
    print(b);
    print(d); // if pass by value used then it will print "In base" becoz of object slicing
    return 0;
}
Output:
In base
In derived

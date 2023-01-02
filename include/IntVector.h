// Labb2, IntVector.h – klassdefinition

#include <iostream>
#include <array>
#include <list>

class IntVector
{
private: 

    int* integers;
    size_t numberOfInts;

public:

    IntVector();
    IntVector(const IntVector&);
    IntVector(std::initializer_list<int>);
    ~IntVector();

    int size() const;
    void push_back(int);

    int& operator[](int) const;
    IntVector operator=(const IntVector&);
    friend std::ostream& operator<<(std::ostream&, const IntVector&);
};
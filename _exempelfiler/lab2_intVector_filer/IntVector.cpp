// IntVector ska ha värdesemantik, dvs den (och alla dess element) ska kopieras vid tilldelning, då den skickas som värdeargument till funktioner och då den returneras från funktioner.
// Ett IntVector-objekt ska kunna konstrueras utan argument (en tom IntVector), med ett annat IntVector-objekt (en copy-konstruktor, den nya IntVector blir en kopia av argumentet), 
// med ett temporärt IntVector-objekt (en move-konstruktor, det temporära objektet nollställs), samt med värden från en initieringslista.

// Tänk på att du behöver också kunna skriva ut ett IntVector-objekt med utskriftoperatorn <<, exempelvis:
// std::cout << "vek4: " << vek4 << std::endl;   // Exempel på utskrift: vek4: 43 43 53 73

// Om ett IntVector-objekt deklarerats som const ska man kunna avläsa elementvärden med indexering och avläsa IntVector:ns storlek, men man ska inte kunna ändra elementvärdena 
// eller lägga till nya element till detta objekt.

// Att lägga till nya element till ett IntVector-objekt ska göras med medlemsfunktionen push_back, som tar det nya värdet som argument och lägger detta värde sist i IntVector:

// Dessutom ska IntVector ha en medlemsfunktion size() som returnerar antalet element som har adderats till objektet.

// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

// #include "IntVector.h"

IntVector::IntVector(){
    int size = 0;
    integers = new int[size];
    numberOfInts = 0;
};

IntVector::IntVector(const IntVector& original) {
    numberOfInts = original.size();
    integers = new int[numberOfInts];
    for (size_t i = 0; i < numberOfInts; i++){
        integers[i] = (original.integers[i]);
       // std::cout << "current int: " << integers[i] << std::endl;
    }
};

IntVector::IntVector(std::initializer_list<int> numbers) {
    numberOfInts = numbers.size();
    integers = new int[numberOfInts];
    for (size_t i = 0; i < numberOfInts; i++){
        integers[i] = *(numbers.begin() + i);
    }
}; 

IntVector::~IntVector(){
    delete [] integers;
};



int IntVector::size() const{
     return numberOfInts;
};

void IntVector::push_back(int object){
    numberOfInts = size() + 1;
    integers[size() - 1] = object;
}



int& IntVector::operator[](int index) const{
    return integers[index];
};

std::ostream& operator<<(std::ostream& os, const IntVector& iV)
{
    if (iV.numberOfInts > 0){
        for (int i = 0; i < iV.size(); i++){
            os << iV.integers[i] << " ";
        }
    }
    return os;
};

IntVector IntVector::operator=(const IntVector& toCompare){
    delete integers;
    numberOfInts = toCompare.size();
    integers = new int[numberOfInts];
    for (size_t i = 0; i < numberOfInts; i++){
        integers[i] = (toCompare.integers[i]);
    }
    return *this;
};

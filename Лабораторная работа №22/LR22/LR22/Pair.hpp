#include <iostream>

using namespace std;
class Pair {
    int first;
    double second;
public:
    Pair() { first = 0; second = 0; };
    Pair(int f, double s) { first = f; second = s; }
    Pair(const Pair& t) { first = t.first; second = t.second; }
    ~Pair() {};
    int get_first() { return first; }
    double get_second() { return second; }
    void set_first (int f) { first = f; }
    void set_second (double s) { second = s; }
    
    Pair& operator=(const Pair&);
    Pair& operator--();
    Pair operator--(int);
    Pair operator>(const Pair&);
    Pair operator<(const Pair&);
    
    friend istream& operator>>(istream& in, Pair& t);
    friend ostream& operator<<(ostream& out, const Pair& t);
};

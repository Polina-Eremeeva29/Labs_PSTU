#include "Pair.hpp"

using namespace std;
Pair& Pair::operator=(const Pair& t) {
    if (&t == this) return *this;
    first = t.first;
    second = t.second;
    return *this;
}

Pair& Pair::operator --() {
    this->first--;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp(*this);
    this->second--;
    return temp;
}

Pair Pair::operator <(const Pair& t) {
    if (this->first < t.first && this->second < t.second) {
        cout << "Да " << endl;
        return *this;
    }
    else {
        cout << "Нет " << endl;
        return t;
    }
}

Pair Pair::operator >(const Pair& t) {
    if (this->first > t.first && this->second > t.second)
{
    cout << "Да " << endl;
    return *this;
}
    else {
        cout << "Нет " << endl;
        return t;
    }
}

istream& operator>>(istream& in, Pair& t) {
    cout << "first: "; cin >> t.first;
    cout << "second: "; cin >> t.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& t) {
    return(out<<t.first << " : " << t.second << endl);
}

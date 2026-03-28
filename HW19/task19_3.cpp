#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <list>
#include <vector>

using namespace std;


class RationalException : public runtime_error {
public:
    explicit RationalException(const string &msg) : runtime_error(msg) {}
};

class Rational {
private:
    int nominator;
    int denominator;

    static int calcGCD(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    void Simplify() {
        if (denominator == 0)
            throw RationalException("Denominator cannot be 0.");

        if (denominator < 0) {
            nominator = -nominator;
            denominator = -denominator;
        }
        if (nominator == 0) {
            denominator = 1;
            return;
        }
        int g = calcGCD(abs(nominator), denominator);
        nominator /= g;
        denominator /= g;
    }

public:
    Rational() : nominator(1), denominator(1) {}
    
    Rational(int nom) : nominator(nom), denominator(1) {}

    Rational(int nom, int den) {
        if (den == 0) throw RationalException("Cannot initialize with denominator 0.");
        nominator = nom;
        denominator = den;
        Simplify();
    }

    void setNominator(int nom) { nominator = nom; Simplify(); }
    void setDenominator(int den) {
        if (den == 0) throw RationalException("Denominator cannot be 0.");
        denominator = den;
        Simplify();
    }
    double getDouble() const { return static_cast<double>(nominator) / denominator; }

    void input() {
        int nom, den;
        cout << "Enter nominator: "; cin >> nom;
        cout << "Enter denominator: "; cin >> den;
        if (den == 0) throw RationalException("Input error: denominator = 0.");
        nominator = nom; denominator = den; Simplify();
    }
    void output() const { cout << nominator << "/" << denominator; }

    Rational operator+(const Rational &other) const {
        return Rational(nominator * other.denominator + other.nominator * denominator,
                        denominator * other.denominator);
    }
    Rational operator-(const Rational &other) const {
        return Rational(nominator * other.denominator - other.nominator * denominator,
                        denominator * other.denominator);
    }
    Rational operator-() const { return Rational(-nominator, denominator); }
    Rational operator*(const Rational &other) const {
        return Rational(nominator * other.nominator, denominator * other.denominator);
    }
    Rational operator/(const Rational &other) const {
        if (other.nominator == 0) throw RationalException("Division by zero.");
        return Rational(nominator * other.denominator, denominator * other.nominator);
    }

    bool operator<(const Rational &other) const {
        return (long long)nominator * other.denominator < (long long)other.nominator * denominator;
    }
    bool operator==(const Rational &other) const {
        return nominator == other.nominator && denominator == other.denominator;
    }
    bool operator>(const Rational &other) const { return !(*this <= other); }
    bool operator!=(const Rational &other) const { return !(*this == other); }
    bool operator<=(const Rational &other) const { return (*this < other) || (*this == other); }
    bool operator>=(const Rational &other) const { return !(*this < other); }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        os << r.nominator << "/" << r.denominator;
        return os;
    }
    friend istream &operator>>(istream &is, Rational &r) {
        int nom, den; 
        char slash;
        if (is >> nom >> slash >> den) {
            if (slash == '/') r = Rational(nom, den);
        }
        return is;
    }
};

template <typename T>
class Polynomial {
private:
    list<T> coeffs;

    void trim() {
        while (coeffs.size() > 1) {
            if (coeffs.back() == T(0)) {
                coeffs.pop_back();
            } else {
                break; 
            }
        }
    }

public:
    Polynomial() {
        coeffs.push_back(T(0));
    }

    Polynomial(initializer_list<T> init) : coeffs(init) {
        if (coeffs.empty()) coeffs.push_back(T(0));
        trim();
    }

    void input() {
        coeffs.clear();
        int degree;
        cout << "Enter degree: ";
        cin >> degree;
        cout << "Enter coefficients (a0 to a" << degree << "):" << endl;
        for (int i = 0; i <= degree; ++i) {
            T val;
            cout << "x^" << i << ": ";
            cin >> val;
            coeffs.push_back(val);
        }
        trim();
    }

    void print() const {
        if (coeffs.empty() || (coeffs.size() == 1 && coeffs.front() == T(0))) {
            cout << "0" << endl;
            return;
        }

        bool first = true;
        int power = coeffs.size() - 1;

        for (auto it = coeffs.rbegin(); it != coeffs.rend(); ++it, --power) {
            T val = *it;
            if (val == T(0)) continue;

            if (!first) {
                if (val > T(0)) cout << " + ";
                else {
                    cout << " - ";
                    val = -val;
                }
            } else {
                if (val < T(0)) {
                    cout << "-";
                    val = -val;
                }
            }

            if (val != T(1) || power == 0) {
                cout << val;
            }

            if (power > 0) cout << "x";
            if (power > 1) cout << "^" << power;

            first = false;
        }
        cout << endl;
    }

    T evaluate(T x) const {
        T result = T(0);
        T currentX = T(1);
        
        for (const auto& coef : coeffs) {
            result = result + (coef * currentX);
            currentX = currentX * x;
        }
        return result;
    }

    Polynomial<T> operator+(const Polynomial<T>& other) const {
        Polynomial<T> res;
        res.coeffs.clear();

        auto it1 = coeffs.begin();
        auto it2 = other.coeffs.begin();

        while (it1 != coeffs.end() || it2 != other.coeffs.end()) {
            T val1 = (it1 != coeffs.end()) ? *it1 : T(0);
            T val2 = (it2 != other.coeffs.end()) ? *it2 : T(0);
            
            res.coeffs.push_back(val1 + val2);

            if (it1 != coeffs.end()) ++it1;
            if (it2 != other.coeffs.end()) ++it2;
        }
        res.trim();
        return res;
    }

    Polynomial<T> operator*(const Polynomial<T>& other) const {
        if (this->coeffs.empty() || other.coeffs.empty()) return Polynomial<T>();
        
        int size = coeffs.size() + other.coeffs.size() - 1;
        vector<T> resVec(size, T(0));
        
        int i = 0;
        for (const auto& c1 : coeffs) {
            int j = 0;
            for (const auto& c2 : other.coeffs) {
                resVec[i + j] = resVec[i + j] + (c1 * c2);
                j++;
            }
            i++;
        }

        Polynomial<T> res;
        res.coeffs.clear();
        for (const auto& val : resVec) {
            res.coeffs.push_back(val);
        }
        res.trim();
        return res;
    }
};

int main() {
    try {
        cout << "Test 1: Int << endl";
        Polynomial<int> p1({3, 7});
        Polynomial<int> p2({3, -5});
        
        cout << "P1: "; p1.print();
        cout << "P2: "; p2.print();
        
        Polynomial<int> pSum = p1 + p2;
        cout << "Sum: "; pSum.print();

        Polynomial<int> pMult = p1 * p2;
        cout << "Mult: "; pMult.print();

        cout << "P1(2): " << p1.evaluate(2) << endl;

        cout << "\nTest 2: Rational" << endl;
        Polynomial<Rational> r1({Rational(1, 4), Rational(2, 5)});
        Polynomial<Rational> r2({Rational(1, 2)});

        cout << "R1: "; r1.print();
        cout << "R2: "; r2.print();

        Polynomial<Rational> rSum = r1 + r2;
        cout << "Sum: "; rSum.print();

        Polynomial<Rational> rMult = r1 * r1;
        cout << "Square R1: "; rMult.print();

        cout << "R1(3): " << r1.evaluate(Rational(3)) << endl;

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
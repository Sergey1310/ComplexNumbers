#include <iostream>

class Complex
{
public:
    double EPSILON = 0.00000001; // This is magic! (for double)
    double re;
    double im;
//Constructors
    Complex()
    {
        this->re = 0;
        this->im = 0;
    }
    Complex(double valueRe, double valueIm)
    {
        this->re = valueRe;
        this->im = valueIm;
    }
    Complex(const Complex &other)
    {
        this->re = other.re;
        this->im = other.im;
    }
//Destructor
    ~Complex(){};


    // Overload =
    Complex & operator = (const Complex &other)
    {
        this->re = other.re;
        this->im = other.im;
        return *this;
    }
    // Overload ==
    bool operator == (const Complex &other)
    {
        return (EPSILON < (this->re - other.re) < EPSILON) && (EPSILON < (this->im - other.im) < EPSILON);
    }
    // Overload !=
    bool operator != (const Complex &other)
    {
        return !((EPSILON < (this->re - other.re) < EPSILON) && (EPSILON < (this->im - other.im) < EPSILON));
    }
    // Overload >=
    bool operator >= (const Complex &other)
    {
        return (EPSILON < (this->re - other.re) < EPSILON) && (EPSILON < (this->im - other.im) < EPSILON) || (this->re * this->re + this->im * this->im) > ((other.re * other.re) + (other.im * other.im));
    }
    // Overload <=
    bool operator <= (const Complex &other)
    {
        return (EPSILON < (this->re - other.re) < EPSILON) && (EPSILON < (this->im - other.im) < EPSILON) || (this->re * this->re + this->im * this->im) < ((other.re * other.re) + (other.im * other.im));
    }
    // Overload >
    bool operator > (const Complex &other)
    {
        return (this->re * this->re + this->im * this->im) > ((other.re * other.re) + (other.im * other.im));
    }
    // Overload <
    bool operator < (const Complex &other)
    {
        return (this->re * this->re + this->im * this->im) < ((other.re * other.re) + (other.im * other.im));
    }

    // Overload ++ and --
    Complex & operator ++ ()
    {
        ++re;
        ++im;
    }
    Complex & operator ++ (int)
    {
        Complex temp = *this;
        ++re;
        ++im;
        return temp;
    }
    Complex & operator -- ()
    {
        --re;
        --im;
    }
    Complex & operator -- (int)
    {
        Complex temp = *this;
        --re;
        --im;
        return temp;
    }

    // Overload += -= *= /=
    Complex & operator += (const Complex &b)
    {
        re += b.re;
        im += b.im;
        return *this;
    }
    Complex & operator -= (const Complex &b)
    {
        re -= b.re;
        im -= b.im;
        return *this;
    }
    Complex & operator *= (const Complex &b)
    {
        re *= b.re;
        im *= b.im;
        return *this;
    }
    Complex & operator /= (const Complex &b)
    {
        re /= b.re;
        im /= b.im;
        return *this;
    }

    void Print(); // Just print the number

};
// Overload +=
Complex operator += (Complex &a, const double b)
{
    a.re += b;
    return a;
}
//Overload +
Complex operator + (const Complex &a, const Complex &b)
{
    Complex temp;
    temp.re = a.re + b.re;
    temp.im = a.im + b.im;
    return temp;
}
Complex operator + (const double a, const Complex &b)
{
    Complex temp;
    temp.re = b.re + a;
    temp.im = b.im;
    return temp;
}
Complex operator + (const Complex &a, const double b)
{
    Complex temp;
    temp.re = a.re + b;
    temp.im = a.im;
    return temp;
}
//Overload -=
Complex operator -= (Complex &a, const double b)
{
    a.re += b;
    return a;
}
//Overload -
Complex operator - (const Complex &a, const Complex &b)
{
    Complex temp;
    temp.re = a.re - b.re;
    temp.im = a.im - b.im;
    return temp;
}
Complex operator - (const double a, const Complex &b)
{
    Complex temp;
    temp.re = b.re - a;
    temp.im = b.im;
    return temp;
}
Complex operator - (const Complex &a, const double b)
{
    Complex temp;
    temp.re = a.re - b;
    temp.im = a.im;
    return temp;
}
//Overload *=
Complex operator *= (Complex &a, const double b)
{
    a.re *= b;
    return a;
}
//Overload *
Complex operator * (const Complex &a, const Complex &b)
{
    Complex temp;
    temp.re = a.re * b.re;
    temp.im = a.im * b.im;
    return temp;
}
Complex operator * (const double a, const Complex &b)
{
    Complex temp;
    temp.re = b.re * a;
    temp.im = b.im * a;
    return temp;
}
Complex operator * (const Complex &a, const double b)
{
    Complex temp;
    temp.re = a.re * b;
    temp.im = a.im * b;
    return temp;
}
//Overload /=
Complex operator /= ( Complex &a, const double b)
{
    a.re /= b;
    return a;
}
//Overload /
Complex operator / (const Complex &a, const Complex &b)
{
    Complex temp;
    temp.re = a.re / b.re;
    temp.im = a.im / b.im;
    return temp;
}
Complex operator / (const double a, const Complex &b)
{
    Complex temp;
    temp.re = b.re / a;
    temp.im = b.im / a;
    return temp;
}
Complex operator / (const Complex &a, const double b)
{
    Complex temp;
    temp.re = a.re / b;
    temp.im = a.im / b;
    return temp;
}


void Complex::Print()
{
    std::cout << "Complex number: " << re << " + i" << im << std::endl;
}

void Logic (Complex &b, Complex &c)
{
    bool result = 0;
    result = b==c;
    std::cout << "b == c\t\t- " << result << std::endl;
    result = b!=c;
    std::cout << "b != c\t\t- " << result << std::endl;

    result = b>=c;
    std::cout << "b >= c\t\t- " << result << std::endl;
    result = b<=c;
    std::cout << "b <= c\t\t- " << result << std::endl;

    result = b>c;
    std::cout << "b > c\t\t- " << result << std::endl;
    result = b<c;
    std::cout << "b < c\t\t- " << result << std::endl;
}
void PrintABC (Complex &a, Complex &b, Complex &c)
{
    std::cout << std::endl;
    std::cout << " -----------------------------------------------------------" << std::endl;
    std::cout << " a = ";
    a.Print();
    std::cout << " b = ";
    b.Print();
    std::cout << " c = ";
    c.Print();
}
void Arithmetic (Complex &a, Complex &b, Complex &c)
{
    Complex result;

//Overload += test
    PrintABC(a,b,c);
    a+=b;
    std::cout << " a += b; = ";
    a.Print();

    PrintABC(a,b,c);
    a+=5.5;
    std::cout << " a += 5.5; = ";
    a.Print();

//Overload -= test
    PrintABC(a,b,c);
    b-=c;
    std::cout << " b -= c; = ";
    b.Print();

    PrintABC(a,b,c);
    b-=10.1;
    std::cout << " b -= 10.1; = ";
    b.Print();

//Overload *= test
    PrintABC(a,b,c);
    a*=b;
    std::cout << " a *= b; = ";
    a.Print();

    PrintABC(a,b,c);
    a*=5.5;
    std::cout << " a *= 5.5; = ";
    a.Print();

//Overload /= test
    PrintABC(a,b,c);
    c/=a;
    std::cout << " c /= a; = ";
    c.Print();

    PrintABC(a,b,c);
    c/=100;
    std::cout << " c /= 100; = ";
    c.Print();

//Overload + test
    PrintABC(a,b,c);
    result = a + b;
    std::cout << " a + b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = 10.1 + b;
    std::cout << " 10.1 + b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = a + 10.1;
    std::cout << " a + 10.1; = ";
    result.Print();

//Overload - test
    PrintABC(a,b,c);
    result = a - b;
    std::cout << " a - b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = 10.1 - b;
    std::cout << " 10.1 - b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = a - 10.1;
    std::cout << " a - 10.1; = ";
    result.Print();

//Overload * test
    PrintABC(a,b,c);
    result = a * b;
    std::cout << " a * b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = 2 * b;
    std::cout << " 2 * b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = a * 2;
    std::cout << " a * 2; = ";
    result.Print();

//Overload / test
    PrintABC(a,b,c);
    result = a / b;
    std::cout << " a / b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = 2 / b;
    std::cout << " 2 / b; = ";
    result.Print();

    PrintABC(a,b,c);
    result = a / 2;
    std::cout << " a / 2; = ";
    result.Print();
}


int main()
{
    Complex a;
    Complex b (15.4,12.3);
    Complex c ;
//Print a b c;
    a.Print();
    b.Print();
    c.Print();
// Test overload operator =;
    c=b;
// Print results    ;
    b.Print();
    c.Print();
// Test overload operators logic;
    Logic(b,c);
// Test overload operators ++ and --;
    ++a;
    b++;
    --c;
// Print results;
    a.Print();
    b.Print();
    c.Print();
// Test overload operators logic 2 after changers;
    std::cout << "After b++ and --c " << std::endl;
    Logic(b,c);
// Test overload operators arithmetic
    Arithmetic(a,b,c);
// Print results;
    a.Print();
    b.Print();
    c.Print();








}
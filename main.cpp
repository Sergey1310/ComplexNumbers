#include <iostream>

class T;

class Complex
{
    friend std::ostream& operator << (std::ostream& os, const Complex a);
    friend std::istream& operator >> (std::istream& in, Complex &a);
    template<typename T>
    friend Complex operator + (const T a, const Complex &b);
    template<typename T>
    friend Complex operator - (const T a, const Complex &b);
    template<typename T>
    friend Complex operator * (const T a, const Complex &b);
    template<typename T>
    friend Complex operator / (const T a, const Complex &b);



private:
    const double EPSILON = 0.00000001; // This is magic! (for double)
    double re;
    double im;
    double ZERO = 0;
    static int countNumbers; // This variable keeps count of numbers

public:
    static void ShowCountNumbers()
    {
        std::cout << "There was made : " << countNumbers << " numbers." << std::endl;
    }
//Constructors
    Complex()
    {
        this->re = 0;
        this->im = 0;
        ++countNumbers;
    }
    Complex(double valueRe, double valueIm)
    {
        this->re = valueRe;
        this->im = valueIm;
        ++countNumbers;
    }
    Complex(const Complex &other)
    {
        this->re = other.re;
        this->im = other.im;
        ++countNumbers;
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
        return !(*this == other);
    }
    // Overload >=
    bool operator >= (const Complex &other)
    {
        return (*this==other)  || (this->re * this->re + this->im * this->im) > ((other.re * other.re) + (other.im * other.im));
    }
    // Overload <=
    bool operator <= (const Complex &other)
    {
        return !(*this >= other);
    }
    // Overload >
    bool operator > (const Complex &other)
    {
        return (this->re * this->re + this->im * this->im) > ((other.re * other.re) + (other.im * other.im));
    }
    // Overload <
    bool operator < (const Complex &other)
    {
        return !(*this>other);
    }

    // Overload ++ and --
    Complex & operator ++ ()
    {
        return *this += 1.0;
    }
    Complex operator ++ (int)
    {
        Complex temp = *this;
        *this += 1.0;
        return temp;
    }
    Complex & operator -- ()
    {
        return *this -= 1.0;
    }
    Complex operator -- (int)
    {
        Complex temp = *this;
        *this -= 1.0;
        return temp;
    }

    // Overload += -= *= /=
    Complex & operator += (const Complex &other)
    {
        re += other.re;
        im += other.im;
        return *this;
    }
    Complex & operator -= (const Complex &other)
    {
        re -= other.re;
        im -= other.im;
        return *this;
    }
    Complex & operator *= (const Complex &other)
    {
        re *= other.re;
        im *= other.im;
        return *this;
    }
    Complex & operator /= (const Complex &other)
    {
        re /= other.re;
        im /= other.im;
        return *this;
    }

    // Overload += -= *= /= with another numbers
    template<typename T>
    Complex & operator += (const T b)
    {
        re += b;
        return *this;
    }
    template<typename T>
    Complex & operator -= (const T b)
    {
        re -= b;
        return *this;
    }
    template<typename T>
    Complex & operator *= (const T b)
    {
        re *= b;
        return *this;
    }
    template<typename T>
    Complex & operator /= (const T b)
    {
        re *= b;
        return *this;
    }

    // Overload + - * /
    Complex operator + (const Complex &other)
    {
        Complex temp;
        temp+=other;
        return temp;
    }
    Complex operator - (const Complex &other)
    {
        Complex temp;
        temp-=other;
        return temp;
    }
    Complex operator * (const Complex &other)
    {
        Complex temp;
        temp*=other;
        return temp;
    }
    Complex operator / (const Complex &other)
    {
        Complex temp;
        temp/=other;
        return temp;
    }

    // Overload + - * / with another numbers
    template<typename T>
    Complex operator + (const T b)
    {
        Complex temp;
        temp+=b;
        return temp;
    }
    template<typename T>
    Complex operator - (const T b)
    {
        Complex temp;
        temp-=b;
        return temp;
    }
    template<typename T>
    Complex operator * (const T b)
    {
        Complex temp;
        temp*=b;
        return temp;
    }
    template<typename T>
    Complex operator / (const T b)
    {
        Complex temp;
        temp/=b;
        return temp;
    }

    Complex operator - ()
    {
        Complex temp;
        temp.re = -re;
        temp.im = -im;
        return temp;
    }

    double& operator [] (int index){
        if (index == 0) return re;
        if (index == 1) return  im;
        else {
            std::cout << "Incorrect value!" << std::endl;
        }
        return ZERO;
    }





    void Print(); // Just print the number

};

int Complex::countNumbers = 0;

//Overload <<
std::ostream& operator << (std::ostream& os, const Complex a){
    os << "Complex number: " << a.re << " + i" << a.im << std::endl;
}
//Overload >>
std::istream& operator >> (std::istream& in, Complex &a)
{
    std::cout << "Enter real value : ";
    in >> a.re;
    std::cout << std::endl << "Enter imagine value : ";
    in >> a.im;
    std::cout << std::endl;
    return in;
}

//Overload +
template<typename T>
Complex operator + (const T a, const Complex &b)
{
    Complex temp;
    temp.re = b.re + a;
    temp.im = b.im;
    return temp;
}
//Overload -
template<typename T>
Complex operator - (const T a, const Complex &b)
{
    Complex temp;
    temp.re = b.re - a;
    temp.im = b.im;
    return temp;
}
//Overload *
template<typename T>
Complex operator * (const T a, const Complex &b)
{
    Complex temp;
    temp.re = b.re * a;
    temp.im = b.im * a;
    return temp;
}
//Overload /
template<typename T>
Complex operator / (const T a, const Complex &b)
{
    Complex temp;
    temp.re = b.re / a;
    temp.im = b.im / a;
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

//Overload - un test
    PrintABC(a,b,c);
    result = -a;
    std::cout << " -a; = ";
    result.Print();
}

int main()
{
    Complex a;
    Complex b (15.4,12.3);
    Complex c ;
   /*
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
    c.Print();*/
   std::cout << b;
   std::cin >> a;
   std::cout << a;

   Complex::ShowCountNumbers();
}
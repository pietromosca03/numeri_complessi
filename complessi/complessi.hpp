#pragma once
template<typename T> requires std::floating_point<T>
class complessi
{
    T reale, immaginaria;

public:
    complessi()
        : reale(0), immaginaria(0)
    {}

    explicit complessi(T r)
        : reale(r), immaginaria(0)
    {
        std::cout << "costruttore di conversione chiamato" << std::endl;
    }

    complessi(T r, T c)
        : reale(r), immaginaria(c)
    {}

    T parte_reale(void) const {
        return reale;
    }

    T parte_complessa(void) const{
        return immaginaria;
    }

    T coniugato(void) {
        return -immaginaria;
    }

    T partereale(void) {
        return reale;
    }

    T parteimmaginaria(void) {
        return immaginaria;
    }

    complessi& operator+=(const complessi& other){
        T r1 = reale;
        T c1 = immaginaria;
        T r2 = other.reale;
        T c2 = other.immaginaria;
        reale = r1 + r2;
        immaginaria = c1 + c2;
        return *this;
    }

    complessi operator+(const complessi& other) const{
        complessi somma = *this;
        somma += other;
        return somma;
    }

    complessi& operator+=(const T& other){
         reale += other;
        return *this;
    }
    
    complessi operator+(const T& other){
        complessi somma = *this;
        somma += other;
        return somma;
    }
    
    complessi& operator*=(const complessi& other){
        T r1 = reale;
        T c1 = immaginaria;
        T r2 = other.reale;
        T c2 = other.immaginaria;
        reale = r1*r2 - c1*c2;
        immaginaria = r1*c2 +c1*r2;
        return *this;
    }

    complessi operator*(const complessi& other) const{
        complessi prodotto = *this;
        prodotto *= other;
        return prodotto;
    }

    complessi& operator*=(const T& other) {
        reale *= other;
        immaginaria *= other;
        return *this;
    }

    complessi operator*(const T& other) const {
        complessi prodotto = *this;
        prodotto *= other;
        return prodotto;
    }


};

template<typename T>
complessi<T>
operator+(const T& t, const complessi<T>& c)
{
    return c + t;
}

template<typename T>
complessi<T>
operator*(const T& t, const complessi<T>& c)
{
    return c * t;
}



template<typename T>
std::ostream&
operator<<(std::ostream& os, const complessi<T>& c){
    if (c.parte_complessa() != 0 && c.parte_reale() != 0)
        if (c.parte_complessa() < 0)
            os << c.parte_reale()<<c.parte_complessa()<<"i";
        else
            os << c.parte_reale()<<"+"<<c.parte_complessa()<<"i";
    else
        if (c.parte_reale() ==   0)
            os << c.parte_complessa()<<"i";
        else
            os << c.parte_reale();
    return os;
}
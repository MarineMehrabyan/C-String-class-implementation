#include <iostream>
#include<cstring>
#include <cassert>
#include "String.h"

String::String()
    :m_size(0), m_str(nullptr) {
    /*m_size = 0;
    m_str = new char[m_size+1];
    m_str[m_size] = '\0';*/
}

String::String(const char* a)
    :m_size(strlen(a)) {

    if (m_size > 0) {
        m_str = new char[m_size + 1];
        for (int i = 0; i < m_size; i++) {
            m_str[i] = a[i];
        }
    }
    m_str[m_size] = '\0';
}

String::String(const String& a)
    :m_size(a.m_size) {
    m_str = new char[m_size + 1];
    for (int i = 0; i < m_size; i++) {
        m_str[i] = a.m_str[i];
    }
    m_str[m_size] = '\0';
}

String::~String() {
    delete[]m_str;
}

String& String::operator=(const String& a) {
    if (this == &a) return *this;

    if (m_size != a.m_size) {
        delete[]m_str;
        m_size = a.m_size;
        m_str = new char[m_size];
    }

    for (int i = 0; i < m_size; i++) {
        m_str[i] = a.m_str[i];
    }
    m_str[m_size] = '\0';
    return *this;
}
void String::len() {
    int l = 0;
    for (int i = 0; ; i++) {
        if ((*this).m_str[i] == '\0') {
            m_size = l;
            return;
        }l++;
    }

}

int String::get_len()const {
    if (m_size == 0) return 0;
    int count = 0;
    while (m_str[count++] != '\0');
    return count - 1;
}

char String::operator[](int n)const {
    assert(n >= 0 && n < get_len());
    return m_str[n];
}

char& String::operator[](int n) {
    assert(n >= 0 && n < get_len());
    return m_str[n];
}

std::istream& operator>>(std::istream& in, String& a) {
    if (a.m_str != nullptr) {
        in.getline(a.m_str, a.m_size);
    }
    else {
        int m;
        in >> m;
        a.m_size = m;
        a.m_str = new char[a.m_size];
        in.getline(a.m_str, a.get_len() + 1);
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, String& a) {
    if (a.m_str != nullptr) {
        out << a.m_str;
        out << std::endl;
    }return out;
}

String String::operator+(const String& a)const {
    String l = *this;
    l += a;
    return l;
    /* String l;
     l.m_size = a.m_size + m_size;
     int i;
     for(i = 0; i < m_size; i++){
         l.m_str[i] = m_str[i];
     }
     for(int j = 0; j < a.m_size; j++){
       l.m_str[i++] = a.m_str[j];
     }
     l.m_str[i] = '\0';
     return l;*/
}
String& String::operator+=(const String& a) {
    /*
      *this = *this + a;
      return *this;
    */
    int n = get_len(), m = a.get_len(), k = n + m;
    char* h = new char[k + 1];
    int i, l = 0;
    for (i = 0; i < n; i++) {
        h[l++] = m_str[i];
    }
    for (int j = 0; j < m; j++) {
        h[l++] = a.m_str[j];
    }
    h[l] = '\0';
    delete[]m_str;
    m_size = k;
    m_str = h;
    return *this;
}

bool String::operator==(const String& a) const {
    if (m_size != a.m_size) return false;
    for (int i = 0; i < get_len(); i++) {
        if (a.m_str[i] != m_str[i]) return false;
    }
    return true;
}

bool String::operator!=(const String& a) const {
    return !(*this == a);
}

bool String::operator>=(const String& a) const {
    for (int i = 0; i < get_len() || i < a.get_len(); i++) {
        if (a[i] > (*this)[i]) return false;
    }
    return !(get_len() < get_len());
}

bool String::operator<=(const String& a) const {
    for (int i = 0; i < get_len() || i < a.get_len(); i++) {
        if (a.m_str[i] < m_str[i]) return false;
    }
    return !(m_size > a.m_size);
}

bool String::operator>(const String& a) const {
    return !(*this <= a);
}

bool String::operator<(const String& a) const {
    return !(*this >= a);
}

bool String::empty() {
    return this->m_size == 0;
}

void String::clear() {
    delete[] this->m_str;
    this->m_size = 0;
}

void String::push_back(char a) {
    int n = m_size;
    char* h = new char[n + 2];
    int i, l = 0;
    for (i = 0; i < n; i++) {// 0,1,2,3,...,n-1/ 
        h[l++] = m_str[i];
    }
    h[l++] = a;
    h[l] = '\0';
    delete[]m_str;
    m_str = h;
    m_size = l;
}

void String::pop_back() {
    if (m_size <= 0) {
        std::cout << "The string is empty \n";
    }
    else {
        int n = m_size;
        char* h = new char[n];
        int i, l = 0;
        for (i = 0; i < n - 1; i++) {
            h[l++] = m_str[i];
        }
        h[l] = '\0';
        delete[]m_str;
        m_size = n - 1;
        m_str = h;
    }

}
bool String::contains(const String& a) const {
    int j = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_str[i] == a.m_str[j]) j++;
        else if (m_str[i] != a.m_str[j]) j = 0;

        if (j == a.m_size) {

            return true;
        }
    }
    return false;
}

int String::find(char a) {
    for (int i = 0; i < m_size; i++) {
        if (m_str[i] == a) {
            return i;
        }
        else {
            continue;
        }
    }
}

void String::resize(int n)
{
    if (n >= strlen(m_str)) {
        return;
    }
    char* h = new char[n + 1];
    int i, l = 0;
    for (i = 0; i < n; i++) {
        h[l++] = m_str[i];
    }
    h[l] = '\0';
    delete[] m_str;
    m_str = h;
    h = nullptr;
}

String& String::change_substr(String& a, String& b) {

    int i{}, j{};
    bool TRUE = 0;
    for (i = 0; i < m_size; i++) {
        if (m_str[i] == a.m_str[j]) {
            j++;
        }
        else {
            j = 0;
        }
        if (j == a.m_size) {
            TRUE = 1;
            break;
        }

    }
    if (!TRUE) return *this;
    i -= j;

    int r = m_size - a.m_size + b.m_size + 1;

    char* hp = new char[r];
    int t{}, g{};
    int y{};
    for (t = 0; t <= i; t++) {
        hp[y++] = m_str[t];
    }
    for (int g = 0; g < b.m_size; g++) {
        hp[y++] = b.m_str[g];
    }
    t += j;
    for (; t < m_size; t++) {
        hp[y++] = m_str[t];
    }

    hp[y] = '\0';

    delete[] m_str;
    m_str = hp;
    m_size = r - 1;
    hp = nullptr;

    return *this;
}


#pragma once
#pragma once
#include <iostream>

class String {
    char* m_str;
    int m_size;
    void len();
public:
    String();
    String(const char*);
    String(const String&);
    ~String();
    int get_len()const;
    String& operator=(const String&);
    char operator[](int)const;
    char& operator[](int);
    friend std::istream& operator>>(std::istream&, String&);
    friend std::ostream& operator<<(std::ostream&, String&);
    String operator+(const String&)const;
    String& operator+=(const String&);
    bool operator==(const String&) const;
    bool operator!=(const String&) const;
    bool operator>=(const String&) const;
    bool operator<=(const String&) const;
    bool operator>(const String&) const;
    bool operator<(const String&) const;

    bool empty();
    void clear();
    void push_back(char);
    void pop_back();
    bool contains(const String&) const;
    String& change_substr(String&, String&);
    int find(char);
    void resize(int);
};




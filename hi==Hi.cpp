// hi==Hi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>



char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int strcmp_case_insensitive(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        char c1 = to_lower(*s1);
        char c2 = to_lower(*s2);

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }

    return to_lower(*s1) - to_lower(*s2);
}



int main() {
    assert(strcmp_case_insensitive("String one", "string two") < 0);
    assert(strcmp_case_insensitive("String one", "string one") == 0);
    assert(strcmp_case_insensitive("String two", "string one") > 0);
    assert(strcmp_case_insensitive("", "") == 0);
    assert(strcmp_case_insensitive("abc", "ABC") == 0);
    assert(strcmp_case_insensitive("a", "A") == 0);
    assert(strcmp_case_insensitive("abc", "abcd") < 0);
    assert(strcmp_case_insensitive("abcd", "abc") > 0);
    assert(strcmp_case_insensitive("Hello", "hello!") < 0);
    assert(strcmp_case_insensitive("Zebra", "apple") < 0);
    assert(strcmp_case_insensitive("equal", "EQUAL") == 0);
    assert(strcmp_case_insensitive("Case", "case") == 0);
    assert(strcmp_case_insensitive("case", "Cases") < 0);
}



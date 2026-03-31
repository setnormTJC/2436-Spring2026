#include <iostream>
#include <string>

struct EasterDate {
    int month;
    int day;
    int year;
};

EasterDate calculateEaster(int year) {
    // The Anonymous Gregorian Algorithm
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;

    int month = (h + l - 7 * m + 114) / 31;
    int day = ((h + l - 7 * m + 114) % 31) + 1;

    return { month, day, year };
}

int main() {
    int year = 2026; // Current year
    EasterDate ed = calculateEaster(year);

    std::cout << "In " << year << ", Easter Sunday is on: "
        << (ed.month == 3 ? "March " : "April ")
        << ed.day << std::endl;

    return 0;
}
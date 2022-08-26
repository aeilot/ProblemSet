#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Date {
   protected:
    void fromString(string &str) {
        for (int i = 0; i < str.size(); i++) {
            if (i >= 0 && i <= 3) {
                year += (str[i] - '0') * pow(10, 3 - i);
            } else if (i >= 4 && i <= 5) {
                month += (str[i] - '0') * pow(10, 5 - i);
            } else {
                day += (str[i] - '0') * pow(10, 7 - i);
            }
        }
    }

    string toString(Date &ap) {
        string str;
        int a, b, c, d;
        str = to_string(ap.year);
        if (ap.month < 10) str += "0";
        str += to_string(ap.month);
        if (ap.day < 10) str += "0";
        str += to_string(ap.day);
        return str;
    }

   public:
    int year, month, day;
    bool run;
    string data;
    Date(string &s) {
        year = month = day = 0;
        data = s;
        fromString(s);
        run = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }
    void print() { printf("%d-%d-%d\n", year, month, day); }

    Date plus() {
        Date ans = *this;
        if (ans.day <= 27 || (ans.month == 2 && run == true && ans.day == 28) ||
            (((ans.month % 2 == 0 && ans.month >= 8) ||
              (ans.month % 2 == 1 && ans.month <= 7)) &&
             ans.day <= 30 && ans.month != 2) ||
            (((ans.month % 2 == 1 && ans.month >= 8) ||
              (ans.month % 2 == 0 && ans.month <= 7)) &&
             ans.day <= 29 && ans.month != 2)) {
            ans.day++;
        } else if ((ans.month == 2 && run == true && ans.day == 29) ||
                   (ans.month == 2 && run == false && ans.day == 28)) {
            ans.month++;
            ans.day = 1;
        } else if (((ans.month % 2 == 0 && ans.month >= 8) ||
                    (ans.month % 2 == 1 && ans.month <= 7)) &&
                   ans.day == 31) {
            if (ans.month == 12) {
                ans.year++;
                ans.month = 1;
                ans.day = 1;
                run = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
            } else {
                ans.month++;
                ans.day = 1;
            }
        } else if ((((ans.month % 2 == 1 && ans.month >= 8) ||
                     (ans.month % 2 == 0 && ans.month <= 7)) &&
                    ans.day == 30)) {
            ans.month++;
            ans.day = 1;
        }
        ans.data = toString(ans);
        return ans;
    }
};

int dateCMP(Date &a, Date &b) {
    if (a.year > b.year || (a.year == b.year && a.month > b.month) ||
        (a.year == b.year && a.month == b.month && a.day > b.day)) {
        return 1;  // a>b
    } else if (a.year < b.year || (a.year == b.year && a.month < b.month) ||
               (a.year == b.year && a.month == b.month && a.day < b.day)) {
        return -1;  // a<b
    } else if (a.year == b.year && a.month == b.month && a.day == b.day) {
        return 0;  // a==b
    }
    return -233;  // err
}

bool isPalindrome(Date &d) {
    string &s = d.data;
    for (int i = 0; i <= 3; i++) {
        if (s[i] != s[7 - i]) return false;
    }
    return true;
}

int main() {
    // Type your code here
    string one, two;
    getline(cin, one);
    getline(cin, two);
    Date a(one), b(two);
    int count = 0;
    for (Date i = a; dateCMP(i, b) < 1; i = i.plus()) {
        // cout << i.data << endl;
        if (isPalindrome(i)) count++;
    }
    cout << count << endl;
    return 0;
}
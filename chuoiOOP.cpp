#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// L?p Palindrome �? l�u tr? x�u v� c�c ph��ng th?c
class Palindrome {
    private:
        string s; // X�u ban �?u
    public:
        // H�m kh?i t?o v?i tham s? l� x�u
        Palindrome (string s) {
            this->s = s;
        }

        // H�m bi?n �?i x�u theo y�u c?u �? b�i
        // Tham s? l� k? t? c?n thay �?i v� k? t? m?i
        // Tr? v? chi ph� c?a ph�p bi?n �?i
        int transform (char old, char moi) {
            int cost = 0; // Chi ph� ban �?u b?ng 0
            for (int i = 0; i < s.length (); i++) {
                if (s [i] == old) { // N?u k? t? t?i v? tr� i b?ng k? t? c?n thay �?i
                    s [i] = moi; // Thay �?i k? t? t?i v? tr� i b?ng k? t? m?i
                    cost++; // T�ng chi ph� l�n 1
                }
            }
            return cost; // Tr? v? chi ph�
        }

        // H�m ki?m tra x�u c� ph?i l� �?i x?ng hay kh�ng
        // Tr? v? true n?u x�u �?i x?ng, false n?u kh�ng
        bool isPalindrome () {
            // So s�nh x�u v?i x�u �?o ng�?c c?a n�
            return s == string (s.rbegin (), s.rend ());
        }

        // H�m t?m chi ph� nh? nh?t �? bi?n �?i x�u th�nh x�u �?i x?ng
        // Tr? v? chi ph� t?i �u
        int minCost () {
            int cost = 0; // Chi ph� ban �?u b?ng 0
            // Duy?t qua n?a �?u c?a x�u
            for (int i = 0; i < s.length () / 2; i++) {
                // L?y k? t? t��ng ?ng ? n?a sau c?a x�u
                char c = s [s.length () - i - 1];
                // N?u k? t? ? n?a �?u kh�c k? t? ? n?a sau
                if (s [i] != c) {
                    // Bi?n �?i k? t? ? n?a sau th�nh k? t? ? n?a �?u
                    cost += transform (c, s [i]);
                }
            }
            return cost; // Tr? v? chi ph�
        }
};

// H�m main �? nh?p v� xu?t k?t qu?
int main () {
    string s; // X�u ban �?u
    cin >> s; // Nh?p x�u
    Palindrome p (s); // T?o �?i t�?ng Palindrome v?i x�u �? nh?p
    cout << p.minCost () << endl; // Xu?t chi ph� t?i �u
    return 0;
}

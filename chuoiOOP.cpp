#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// L?p Palindrome ð? lýu tr? xâu và các phýõng th?c
class Palindrome {
    private:
        string s; // Xâu ban ð?u
    public:
        // Hàm kh?i t?o v?i tham s? là xâu
        Palindrome (string s) {
            this->s = s;
        }

        // Hàm bi?n ð?i xâu theo yêu c?u ð? bài
        // Tham s? là k? t? c?n thay ð?i và k? t? m?i
        // Tr? v? chi phí c?a phép bi?n ð?i
        int transform (char old, char moi) {
            int cost = 0; // Chi phí ban ð?u b?ng 0
            for (int i = 0; i < s.length (); i++) {
                if (s [i] == old) { // N?u k? t? t?i v? trí i b?ng k? t? c?n thay ð?i
                    s [i] = moi; // Thay ð?i k? t? t?i v? trí i b?ng k? t? m?i
                    cost++; // Tãng chi phí lên 1
                }
            }
            return cost; // Tr? v? chi phí
        }

        // Hàm ki?m tra xâu có ph?i là ð?i x?ng hay không
        // Tr? v? true n?u xâu ð?i x?ng, false n?u không
        bool isPalindrome () {
            // So sánh xâu v?i xâu ð?o ngý?c c?a nó
            return s == string (s.rbegin (), s.rend ());
        }

        // Hàm t?m chi phí nh? nh?t ð? bi?n ð?i xâu thành xâu ð?i x?ng
        // Tr? v? chi phí t?i ýu
        int minCost () {
            int cost = 0; // Chi phí ban ð?u b?ng 0
            // Duy?t qua n?a ð?u c?a xâu
            for (int i = 0; i < s.length () / 2; i++) {
                // L?y k? t? týõng ?ng ? n?a sau c?a xâu
                char c = s [s.length () - i - 1];
                // N?u k? t? ? n?a ð?u khác k? t? ? n?a sau
                if (s [i] != c) {
                    // Bi?n ð?i k? t? ? n?a sau thành k? t? ? n?a ð?u
                    cost += transform (c, s [i]);
                }
            }
            return cost; // Tr? v? chi phí
        }
};

// Hàm main ð? nh?p và xu?t k?t qu?
int main () {
    string s; // Xâu ban ð?u
    cin >> s; // Nh?p xâu
    Palindrome p (s); // T?o ð?i tý?ng Palindrome v?i xâu ð? nh?p
    cout << p.minCost () << endl; // Xu?t chi phí t?i ýu
    return 0;
}

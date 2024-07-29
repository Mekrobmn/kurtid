#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int findMostFrequentMinId(const vector<int>& arr) {
    // T�rlerin frekanslar�n� tutacak dizi
    int frequency[6] = { 0 }; // T�rler 1'den 5'e kadar, 0 kullan�lmaz

    // T�rlerin frekanslar�n� hesapla
    for (int num : arr) {
        if (num >= 1 && num <= 5) {
            frequency[num]++;
        }
        else {
            cerr << "Ge�ersiz t�r ID: " << num << endl;
            return -1;
        }
    }

    // En y�ksek frekans� ve bu frekansta olan en k���k ID'yi bul
    int maxFrequency = 0;
    int minIdWithMaxFrequency = 6; // T�rler 1'den 5'e kadar, 6 ba�lang�� de�eri olarak g�venli

    for (int i = 1; i <= 5; ++i) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            minIdWithMaxFrequency = i;
        }
        else if (frequency[i] == maxFrequency && i < minIdWithMaxFrequency) {
            minIdWithMaxFrequency = i;
        }
    }

    return minIdWithMaxFrequency;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Bo�lu�u t�ket

    // Diziyi oku
    vector<int> arr;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;

    // Ayr� ayr� say�lar� oku
    while (ss >> token) {
        // Token i�erisindeki her karakteri incele
        for (char ch : token) {
            if (ch >= '1' && ch <= '5') {
                int num = ch - '0';
                arr.push_back(num);
            }
        }
    }

    if (arr.size() != n) {
        cerr << "Girdi boyutu ile dizi boyutu uyu�muyor!" << endl;
        return 1;
    }

    // Sonucu hesapla ve yazd�r
    int result = findMostFrequentMinId(arr);
    cout << result << endl;

    return 0;
}

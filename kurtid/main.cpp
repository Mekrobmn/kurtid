#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int findMostFrequentMinId(const vector<int>& arr) {
    // Türlerin frekanslarýný tutacak dizi
    int frequency[6] = { 0 }; // Türler 1'den 5'e kadar, 0 kullanýlmaz

    // Türlerin frekanslarýný hesapla
    for (int num : arr) {
        if (num >= 1 && num <= 5) {
            frequency[num]++;
        }
        else {
            cerr << "Geçersiz tür ID: " << num << endl;
            return -1;
        }
    }

    // En yüksek frekansý ve bu frekansta olan en küçük ID'yi bul
    int maxFrequency = 0;
    int minIdWithMaxFrequency = 6; // Türler 1'den 5'e kadar, 6 baþlangýç deðeri olarak güvenli

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
    cin.ignore(); // Boþluðu tüket

    // Diziyi oku
    vector<int> arr;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;

    // Ayrý ayrý sayýlarý oku
    while (ss >> token) {
        // Token içerisindeki her karakteri incele
        for (char ch : token) {
            if (ch >= '1' && ch <= '5') {
                int num = ch - '0';
                arr.push_back(num);
            }
        }
    }

    if (arr.size() != n) {
        cerr << "Girdi boyutu ile dizi boyutu uyuþmuyor!" << endl;
        return 1;
    }

    // Sonucu hesapla ve yazdýr
    int result = findMostFrequentMinId(arr);
    cout << result << endl;

    return 0;
}

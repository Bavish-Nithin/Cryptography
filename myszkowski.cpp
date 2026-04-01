#include <bits/stdc++.h>
using namespace std;

// Hash Function

string generateHash(string input)
{
    unsigned long long hashValue = 5381;

    for (char ch : input)
    {
        hashValue = ((hashValue << 5) + hashValue) + ch;
    }

    return to_string(hashValue);
}

// Ranking

vector<int> computePriority(string keyword)
{
    set<char> uniqueChars(keyword.begin(), keyword.end());
    vector<char> sortedChars(uniqueChars.begin(), uniqueChars.end());

    map<char, int> priorityMap;

    for (int i = 0; i < sortedChars.size(); i++)
    {
        priorityMap[sortedChars[i]] = i;
    }

    vector<int> priorityList;
    for (char ch : keyword)
    {
        priorityList.push_back(priorityMap[ch]);
    }

    return priorityList;
}

// Encryption Function

string encryptText(string plain, string keyword)
{
    int cols = keyword.length();
    int totalChars = plain.length();

    int rows = ceil((double)totalChars / cols);

    while (plain.length() < rows * cols)
    {
        plain += 'X';
    }

    vector<vector<char>> table(rows, vector<char>(cols));
    int idx = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            table[i][j] = plain[idx++];
        }
    }

    vector<int> priority = computePriority(keyword);
    set<int> uniqueOrder(priority.begin(), priority.end());

    string encryptedOutput = "";

    for (int rank : uniqueOrder)
    {
        for (int col = 0; col < cols; col++)
        {
            if (priority[col] == rank)
            {
                for (int row = 0; row < rows; row++)
                {
                    encryptedOutput += table[row][col];
                }
            }
        }
    }

    return encryptedOutput;
}

// Decryption Function

string decryptText(string cipher, string keyword)
{
    int cols = keyword.length();
    int totalChars = cipher.length();
    int rows = totalChars / cols;

    vector<vector<char>> table(rows, vector<char>(cols));

    vector<int> priority = computePriority(keyword);
    set<int> uniqueOrder(priority.begin(), priority.end());

    int idx = 0;

    for (int rank : uniqueOrder)
    {
        for (int col = 0; col < cols; col++)
        {
            if (priority[col] == rank)
            {
                for (int row = 0; row < rows; row++)
                {
                    table[row][col] = cipher[idx++];
                }
            }
        }
    }

    string decryptedOutput = "";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            decryptedOutput += table[i][j];
        }
    }

    return decryptedOutput;
}

// main

int main()
{
    string inputText, keyword;

    cout << "Enter the message: ";
    getline(cin, inputText);

    cout << "Enter the keyword: ";
    cin >> keyword;

    // 1: Generate hash
    string hashedValue = generateHash(inputText);

    // 2: Encrypt hash
    string cipherText = encryptText(hashedValue, keyword);

    cout << "\nEncrypted Output: " << cipherText << endl;

    // 3: Decrypt
    string recoveredHash = decryptText(cipherText, keyword);

    cout << "Decrypted Hash: " << recoveredHash << endl;

    return 0;
}
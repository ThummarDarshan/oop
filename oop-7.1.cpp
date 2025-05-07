/*
A media research team is developing a tool to analyze word frequency in large textual datasets, such
as news articles and research papers. The goal is to process a given paragraph, identify individual
words, and count their occurrences while ensuring case-insensitive matching. Since the tool is
intended for both constrained environments and high-performance systems, two different
approaches are considered—one utilizing dynamic memory management and another relying on
manually structured arrays.
The first challenge is reading an entire paragraph from the console as a single unformatted string.
Once acquired, the text must be split into individual words, ensuring that uppercase and lowercase
variations are treated as the same. To store and process words dynamically, the team designs a
mechanism using raw pointers and dynamic memory allocation, allowing the program to handle
variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, with additional logic to count
occurrences efficiently. The array expands as needed, ensuring that new words can be
accommodated. The frequency counting is implemented manually by searching for existing words in
the array and updating counts accordingly.
*/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Helper to convert string to lowercase
void toLowerCase(char* str) {
    for (int i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);
}

// Helper to compare strings case-insensitively
bool areEqualIgnoreCase(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (tolower(*s1) != tolower(*s2)) return false;
        s1++; s2++;
    }
    return *s1 == '\0' && *s2 == '\0';
}

// Structure to hold a word and its frequency
struct WordEntry {
    char* word;
    int count;
};

// Function to add/update word in the dynamic array
void addWord(WordEntry*& words, int& size, int& capacity, const char* newWord) {
    for (int i = 0; i < size; ++i) {
        if (areEqualIgnoreCase(words[i].word, newWord)) {
            words[i].count++;
            return;
        }
    }

    // Resize array if needed
    if (size == capacity) {
        capacity *= 2;
        WordEntry* temp = new WordEntry[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = words[i];
        }
        delete[] words;
        words = temp;
    }

    // Add new word
    words[size].word = new char[strlen(newWord) + 1];
    strcpy(words[size].word, newWord);
    words[size].count = 1;
    size++;
}

int main() {
    const int MAX_LEN = 1000;
    char paragraph[MAX_LEN];

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX_LEN);

    // Prepare dynamic array for words
    int capacity = 10;
    int size = 0;
    WordEntry* wordList = new WordEntry[capacity];

    // Tokenize the paragraph into words
    const char* delimiters = " ,.!?;:\n\t\r\"()[]{}";
    char* token = strtok(paragraph, delimiters);

    while (token != nullptr) {
        toLowerCase(token);  // make token lowercase
        addWord(wordList, size, capacity, token);  // add or update
        token = strtok(nullptr, delimiters);
    }

    // Print the result
    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < size; ++i) {
        cout << wordList[i].word << ": " << wordList[i].count << endl;
    }

    // Cleanup dynamic memory
    for (int i = 0; i < size; ++i) {
        delete[] wordList[i].word;
    }
    delete[] wordList;

    return 0;
}


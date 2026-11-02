#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Classes
class Book
{
public:
    int number;     // Data types
    string title;   // Strings
    string author;  
    int sales;      
};

// Classes
class Library
{
public:
    Book books[8];  // Arrays
    int count = 0;

    // File I/O
    void load(string fileName)
    {
        ifstream file(fileName);  // File types (.txt)
        while (count < 8 && file >> books[count].number && file.ignore()
               && getline(file, books[count].title, '|')
               && getline(file, books[count].author, '|') && file >> books[count].sales)
            count++;
    }

    // Binary search
    Book* search(int number)  // Pointers
    {
        int low = 0, high = count - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (books[mid].number == number)
                return &books[mid];
            if (books[mid].number < number)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nullptr;
    }
};

int main()
{
    // Data types and data sizes
    cout << "int: " << sizeof(int) << " bytes, double: " << sizeof(double)
         << " bytes, char: " << sizeof(char) << " byte, string: " << sizeof(string)
         << " bytes, Book: " << sizeof(Book) << " bytes\n\n";

    Library library;
    library.load("books.txt");
    if (library.count == 0)
        cout << "Could not read books.txt\n";

    // Arrays
    for (int i = 0; i < library.count; i++)
        cout << library.books[i].number << ". " << library.books[i].title << " - "
             << library.books[i].author << " - " << library.books[i].sales
             << " million copies sold\n";

    int number;
    cout << "\nEnter a book number: ";
    cin >> number;

    // Pointers
    Book* found = library.search(number);
    if (found != nullptr)
        cout << "Found: " << found->title << " by " << found->author
             << ", " << found->sales << " million copies sold\n";
    else
        cout << "Not found\n";

    return 0;
}

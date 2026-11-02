#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

// Classes
class Book
{
public:
    int number;     // Data types
    string title;   // Strings
    string author;  
    int sales;      

    void display()
    {
        cout << number << ". " << title << " - " << author << " - "
             << sales << " million copies sold\n";
    }
};

// Classes
class Library
{
public:
    static const int MAX = 20;
    Book books[MAX];  // Arrays
    int count = 0;

    // File I/O
    void load(string fileName)
    {
        ifstream file(fileName);  // File types (.txt)
        while (count < MAX && file >> books[count].number && file.ignore()
               && getline(file, books[count].title, '|')
               && getline(file, books[count].author, '|') && file >> books[count].sales)
            count++;
    }

    // Arrays
    void list()
    {
        for (int i = 0; i < count; i++)
            books[i].display();
    }

    // File I/O
    bool add(string fileName, string title, string author, int sales)
    {
        if (count == MAX)
            return false;
        books[count].number = (count == 0) ? 1 : books[count - 1].number + 1;
        books[count].title = title;
        books[count].author = author;
        books[count].sales = sales;

        ofstream file(fileName, ios::app);  // File types (.txt)
        file << '\n' << books[count].number << '|' << title << '|' << author << '|' << sales;
        count++;
        return true;
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

// Data types
int readNumber(string prompt)
{
    int value = 0;
    cout << prompt;
    if (!(cin >> value))
    {
        cin.clear();
        value = 0;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

// Strings
string readText(string prompt)
{
    string text;
    do
    {
        cout << prompt;
        getline(cin, text);
    } while (text.empty() || text.find('|') != string::npos);
    return text;
}

int main()
{
    // Data types and data sizes
    cout << "int: " << sizeof(int) << " bytes, double: " << sizeof(double)
         << " bytes, char: " << sizeof(char) << " byte, string: " << sizeof(string)
         << " bytes, Book: " << sizeof(Book) << " bytes\n";

    Library library;
    library.load("books.txt");
    cout << "Loaded " << library.count << " books from books.txt\n";

    int choice = 0;
    while (choice != 4)
    {
        cout << "\n1. List books\n2. Search by number\n3. Add a book\n4. Exit\n";
        choice = readNumber("Choice: ");

        if (choice == 1)
            library.list();
        else if (choice == 2)
        {
            // Pointers
            Book* found = library.search(readNumber("Book number: "));
            if (found != nullptr)
            {
                cout << "Found: ";
                found->display();
            }
            else
                cout << "Not found\n";
        }
        else if (choice == 3)
        {
            string title = readText("Title: ");
            string author = readText("Author: ");
            int sales = readNumber("Copies sold (millions): ");
            if (library.add("books.txt", title, author, sales))
                cout << "Added as book " << library.books[library.count - 1].number << " and saved to books.txt\n";
            else
                cout << "The library is full\n";
        }
        else if (choice == 4)
            cout << "Goodbye!\n";
        else
            cout << "Pick 1 to 4\n";
    }
    return 0;
}

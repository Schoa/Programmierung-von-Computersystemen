#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Book class
class Book
{
public:
    string BookID;
    string Title;
    int Due;

    friend istream &operator>>(istream &in, Book &b)
    {
        cout << "Enter Book ID: ";
        getline(in, b.BookID);
        cout << "Enter Book Title: ";
        getline(in, b.Title);
        cout << "Enter Due (days): ";
        in >> b.Due;
        in.ignore();
        return in;
    }
    friend ostream &operator<<(ostream &out, const Book &b)
    {
        out << "ID: " << b.BookID << "\n";
        out << "Title: " << b.Title << "\n";
        out << "Due: " << b.Due << " days\n";
        return out;
    }
};

// Member class
class Member
{
public:
    string MemberID;
    string Name;

    friend istream &operator>>(istream &in, Member &m)
    {
        cout << "Enter Member ID: ";
        getline(in, m.MemberID);
        cout << "Enter Member Name: ";
        getline(in, m.Name);
        return in;
    }
    friend ostream &operator<<(ostream &out, const Member &m)
    {
        out << "ID: " << m.MemberID << "\n";
        out << "Name: " << m.Name << "\n";
        return out;
    }
};

// Template class for storing any type (Book or Member)
template <typename T>
class LibraryList
{
    vector<T> items;

public:
    void add(const T &item)
    {
        items.push_back(item);
    }
    bool empty() const
    {
        return items.empty();
    }
    void displayAll(const string &header) const
    {
        if (items.empty())
        {
            cout << "No " << header << " in the library.\n";
        }
        else
        {
            cout << "\n---All " << header << "---\n";
            for (const auto &item : items)
                cout << item << endl;
        }
    }
    void saveAll(ofstream &fout, const string &header) const
    {
        fout << "---" << header << "---\n";
        for (const auto &item : items)
            fout << item << endl;
    }
};

int main()
{
    LibraryList<Book> books;
    LibraryList<Member> members;
    int n;

    while (1)
    {
        cout << "\n---Vinuniversity Library System---";
        cout << "\n1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Add New Member\n";
        cout << "4. Display All Members\n";
        cout << "5. Save Data to library_data.txt\n";
        cout << "Enter your choice: ";
        cin >> n;
        cin.ignore();

        switch (n)
        {
        case 1:
        {
            Book b;
            cin >> b;
            books.add(b);
            cout << "\nBook added successfully.\n";
            break;
        }
        case 2:
            books.displayAll("Books");
            break;
        case 3:
        {
            Member m;
            cin >> m;
            members.add(m);
            cout << "\nMember added successfully.\n";
            break;
        }
        case 4:
            members.displayAll("Members");
            break;
        case 5:
        {
            ofstream fout("library_data.txt");
            books.saveAll(fout, "Books");
            members.saveAll(fout, "Members");
            fout.close();
            cout << "Data saved to library_data.txt. Exiting the program. Goodbye!\n";
            exit(0);
        }
        default:
            cout << "Invalid choice. Please try again\n";
        }
    }
}
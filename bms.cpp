#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
using namespace std;
class movie
{
private:
    char seat[10][10];

public:
    void create(int m, int n) // used to create whole seat matrix
    {
        int i, j;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                seat[i][j] = '*';
        cout << "\nSuccessfully created new seating arrangment!!";
    }
    void display(int m, int n) // used to display whole seat matrix
    {
        int i, j;
        char ch = 'A';
        cout << "  ";
        for (i = 0; i < n; i++)
            cout << i + 1 << " ";
        cout << "\n";
        for (i = 0; i < m; i++)
        {
            cout << ch++ << " ";
            for (j = 0; j < n; j++)
            {
                cout << seat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void bookseat() //booking
    {
        int num;
        char ch;
        cout << "\nEnter Seat number : ";
        cin >> ch >> num;
        ch = toupper(ch);
        if (seat[ch - 'A'][num - 1] == '*')
        {
            seat[ch - 'A'][num - 1] = '#';
            cout << "\nYeah you successfully booked " << ch << " " << num;
        }
        else
            cout << "\nLooks like seat is already booked :( ";
    }
    void cancelseat() //cancellation
    {
        int num;
        char ch;
        cout << "\nEnter Seat number : ";
        cin >> ch >> num;
        ch = toupper(ch);
        if (seat[ch - 'A'][num - 1] == '#')
        {
            seat[ch - 'A'][num - 1] = '*';
            cout << "\nOops you cancelled " << ch << " " << num;
        }
        else
            cout << "\nLooks like you haven't booked this seat yet :( ";
    }
};

int main()
{
    int n = 0, m = 0, choice, flag = 1, slot = 0;
    int found;
    movie obj[5];
label:
    cout << "\n Which movie slot you want from 1 to 5 : ";
    cin >> slot;
    while (flag == 1)
    {
        cout << "\n\nPlease select your choice : ";
        cout << "\n\t1: Create seat arrangement (for staff only) ";
        cout << "\n\t2: View current seat status ";
        cout << "\n\t3: Book a ticket ";
        cout << "\n\t4: Cancel a ticket ";
        cout << "\n\t5: Do you want to change slot? :";
        cout << "\n\t6: Exit";
        cout << "\n\t   Enter option number : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter number of rows : ";
            cin >> m;
            cout << "\nEnter number of column : ";
            cin >> n;
            obj[slot - 1].create(m, n);
            break;
        case 2:
            if (m && n)
                obj[slot - 1].display(m, n);
            else
                cout << "No seat Diagram created yet !!";
            break;
        case 3:
            if (m && n)
                obj[slot - 1].bookseat();
            else
                cout << "No seat Diagram created yet !!";
            break;
        case 4:
            if (m && n)
                obj[slot - 1].cancelseat();
            else
                cout << "No seat Diagram created yet !!";
            break;
        case 5:
            goto label;
            break;
        case 6:
            flag = 0;
            break;
        default:
            cout << "\n Not a valid argument!!";
        }
    }
}
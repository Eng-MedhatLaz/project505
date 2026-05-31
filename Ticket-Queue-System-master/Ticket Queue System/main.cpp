#include <iostream>
#include "TicketQueue.h"

using namespace std;

int main()
{
    TicketQueue queue;

    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n Ticket Management System";
        cout << "\n================================";

        cout << "\n1. Add Ticket";
        cout << "\n2. Serve Ticket";
        cout << "\n3. Display Tickets";
        cout << "\n4. Search by ID";
        cout << "\n5. Search by Name";
        cout << "\n6. Search by Issue";
        cout << "\n7. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            queue.addTicket();
            break;

        case 2:
            queue.serveTicket();
            break;

        case 3:
            queue.displayTickets();
            break;

        case 4:
        {
            int id;
            cout << "\nEnter Ticket ID: ";
            cin >> id;
            queue.searchById(id);
            break;
        }

        case 5:
        {
            string name;
            cin.ignore(1000, '\n');
            cout << "\nEnter Customer Name: ";
            getline(cin, name);
            queue.searchByName(name);
            break;
        }

        case 6:
        {
            string issue;
            cin.ignore(1000, '\n');
            cout << "\nEnter Issue: ";
            getline(cin, issue);
            queue.searchByIssue(issue);
            break;
        }

        case 7:
            cout << "\nProgram Closed\n";
            break;

        default:
            cout << "\nInvalid Choice\n";
        }

    } while (choice != 7);

    return 0;
}
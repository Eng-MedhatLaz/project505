#include <iostream>
#include <algorithm>
#include "TicketQueue.h"

using namespace std;

// ==========================================
// Constructor
// ==========================================
TicketQueue::TicketQueue()
{
    front = NULL;
    rear = NULL;

    ticketCounter = 1;
}

// ==========================================
// Add Ticket
// ==========================================
void TicketQueue::addTicket()
{
    string name;
    string issue;

    cin.ignore(1000, '\n');

    cout << "\nEnter Customer Name: ";
    getline(cin, name);

    cout << "Enter Issue: ";
    getline(cin, issue);

    // Create new ticket
    Ticket* newTicket;

    newTicket = new Ticket(ticketCounter, name, issue);

    // If queue is empty
    if (front == NULL)
    {
        front = newTicket;
        rear = newTicket;
    }
    else
    {
        // Add node to rear
        rear->next = newTicket;

        // Move rear pointer
        rear = newTicket;
    }

    cout << "\nTicket Added Successfully\n";
    cout << "Ticket ID: " << ticketCounter << endl;

    ticketCounter++;
}

// ==========================================
// Serve Ticket
// ==========================================
void TicketQueue::serveTicket()
{
    // Check if queue is empty
    if (front == NULL)
    {
        cout << "\nQueue is Empty\n";
        return;
    }

    Ticket* temp;

    temp = front;

    cout << "\nNow Serving\n";

    cout << "Ticket ID: " << temp->id << endl;
    cout << "Customer Name: " << temp->customerName << endl;
    cout << "Issue: " << temp->issue << endl;

    // Move front pointer
    front = front->next;

    // If queue becomes empty
    if (front == NULL)
    {
        rear = NULL;
    }

    // Delete old node
    delete temp;
}

// ==========================================
// Display Tickets
// ==========================================
void TicketQueue::displayTickets()
{
    // Check if queue is empty
    if (front == NULL)
    {
        cout << "\nNo Tickets Found\n";
        return;
    }

    Ticket* temp;

    temp = front;

    cout << "\n===== Waiting Tickets =====\n";

    // Traverse linked list
    while (temp != NULL)
    {
        cout << "\n-------------------\n";

        cout << "Ticket ID: " << temp->id << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Issue: " << temp->issue << endl;

        // Move to next node
        temp = temp->next;
    }
}

// ==========================================
// Search By ID
// ==========================================
void TicketQueue::searchById(int id)
{
    if (front == NULL)
    {
        cout << "\nNo Tickets Found\n";
        return;
    }

    Ticket* temp = front;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\n===== Search Result =====\n";
            cout << "\n-------------------\n";
            cout << "Ticket ID: " << temp->id << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Issue: " << temp->issue << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nNo Ticket Found with ID: " << id << endl;
}

// ==========================================
// Search By Name
// ==========================================
void TicketQueue::searchByName(string customerName)
{
    if (front == NULL)
    {
        cout << "\nNo Tickets Found\n";
        return;
    }

    Ticket* temp = front;
    bool found = false;

    string lowerQuery = customerName;
    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    cout << "\n===== Search Results =====\n";

    while (temp != NULL)
    {
        string lowerName = temp->customerName;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

        if (lowerName.find(lowerQuery) != string::npos)
        {
            cout << "\n-------------------\n";
            cout << "Ticket ID: " << temp->id << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Issue: " << temp->issue << endl;
            found = true;
        }

        temp = temp->next;
    }

    if (!found)
        cout << "\nNo Tickets Found for Customer: " << customerName << endl;
}

// ==========================================
// Search By Issue
// ==========================================
void TicketQueue::searchByIssue(string issue)
{
    if (front == NULL)
    {
        cout << "\nNo Tickets Found\n";
        return;
    }

    Ticket* temp = front;
    bool found = false;

    string lowerQuery = issue;
    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    cout << "\n===== Search Results =====\n";

    while (temp != NULL)
    {
        string lowerIssue = temp->issue;
        transform(lowerIssue.begin(), lowerIssue.end(), lowerIssue.begin(), ::tolower);

        if (lowerIssue.find(lowerQuery) != string::npos)
        {
            cout << "\n-------------------\n";
            cout << "Ticket ID: " << temp->id << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Issue: " << temp->issue << endl;
            found = true;
        }

        temp = temp->next;
    }

    if (!found)
        cout << "\nNo Tickets Found for Issue: " << issue << endl;
}
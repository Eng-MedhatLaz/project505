#ifndef TICKET_H
#define TICKET_H

#include <string>

using namespace std;

// ==========================================
// Ticket Node Class
// ==========================================
class Ticket
{
public:

    int id;
    string customerName;
    string issue;

    // Pointer to next node
    Ticket* next;

    // Constructor
    Ticket(int ticketId, string name, string problem);
};

#endif
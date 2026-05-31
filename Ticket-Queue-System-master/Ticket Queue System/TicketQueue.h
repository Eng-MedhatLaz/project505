#ifndef TICKETQUEUE_H
#define TICKETQUEUE_H

#include "Ticket.h"

// ==========================================
// Queue Class
// ==========================================
class TicketQueue
{
private:

    Ticket* front;
    Ticket* rear;

    int ticketCounter;

public:

    // Constructor
    TicketQueue();

    // Functions
    void addTicket();
    void serveTicket();
    void displayTickets();
    void searchById(int id);
    void searchByName(string customerName);
    void searchByIssue(string issue);
};

#endif
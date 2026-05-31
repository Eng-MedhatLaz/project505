#include "Ticket.h"

// ==========================================
// Constructor Definition
// ==========================================
Ticket::Ticket(int ticketId, string name, string problem)
{
    id = ticketId;
    customerName = name;
    issue = problem;

    next = NULL;
}
#ifndef METRO_H
#define METRO_H

#define MAX_COUNT 100

typedef struct {
    char name[50];
    char pass[50];
} metro;

typedef struct {
    char name[50];
    char source[50];
    char dest[50];
    char ticket_number[20];
    char fare[20];
} Ticket;

typedef struct {
    metro users[MAX_COUNT];     
    int customercount;

    Ticket ticket[MAX_COUNT];   
    int ticketcount;
    int last_ticket_id;
} Customer;

int val_reg(Customer *customer);
int val_login(Customer *customer);
void savecustomer(Customer *customer);
void loadCustomer(Customer *customer);
void ticketbooking(Customer *customer);
void displayticket(Customer*customer);
void searchticket(Customer*customer);
void saveticket(Customer*customer);
void loadticket(Customer*customer);
void cancelticket(Customer*customer);
#endif

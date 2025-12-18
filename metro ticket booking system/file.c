#include <stdio.h>
#include<string.h>
#include "metro.h"
#include "file.h"

void saveticket(Customer *customer)
{
    if (customer->ticketcount <= 0)
    {
        printf("No ticket to save!\n");
        return;
    }

    FILE *fp = fopen("ticket.csv", "a");
    if (!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    int i = customer->ticketcount - 1;  

    fprintf(fp, "%s,%s,%s,%s,%s\n",
            customer->ticket[i].name,
            customer->ticket[i].source,
            customer->ticket[i].dest,
            customer->ticket[i].ticket_number,
            customer->ticket[i].fare);

    fclose(fp);
    printf("Ticket saved successfully...\n");
}

void loadticket(Customer *customer)
{
    FILE *fp = fopen("ticket.csv", "r");
    customer->last_ticket_id = 100;
    if (!fp)
    {
        printf("No ticket file found.\n");
        customer->ticketcount = 0;
        return;
    }

    char line[300];
    customer->ticketcount = 0;

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0'; // Remove newline

        char *name = strtok(line, ",");
        char *source = strtok(NULL, ",");
        char *dest = strtok(NULL, ",");
        char *ticket_number = strtok(NULL, ",");
        char *fare = strtok(NULL, ",");

        if (name && source && dest && ticket_number && fare)
        {
            int i = customer->ticketcount;

            strcpy(customer->ticket[i].name, name);
            strcpy(customer->ticket[i].source, source);
            strcpy(customer->ticket[i].dest, dest);
            strcpy(customer->ticket[i].ticket_number, ticket_number);
            strcpy(customer->ticket[i].fare, fare);

            customer->ticketcount++;
        }
    }
    fclose(fp);
    printf("Tickets loaded successfully...\n");
}

void savecustomers(Customer *customer)
{
    FILE *my_file = fopen("customer.txt", "w");  

    if (!my_file)
    {
        printf("Error opening file!\n");
        return;
    }

    int i = customer->customercount - 1;   

    fprintf(my_file, "%s,%s\n",customer->users[i].name,customer->users[i].pass);

    fclose(my_file);
    printf("Customer saved successfully.\n");
}

void loadCustomers(Customer *customer)
{
    FILE *my_file = fopen("customer.csv", "r");

    if (!my_file)
    {
        printf("No customer file found.\n");
        customer->customercount = 0;
        return;
    }

    char line[200];
    customer->customercount = 0;

    while (fgets(line, sizeof(line), my_file))
    {
        line[strcspn(line, "\n")] = '\0';

        char *name = strtok(line, ",");
        char *pass = strtok(NULL, ",");

        if (name && pass)
        {
            strcpy(customer->users[customer->customercount].name, name);
            strcpy(customer->users[customer->customercount].pass, pass);
            customer->customercount++;
        }
    }

    fclose(my_file);
    printf("Customer data loaded.\n");
}

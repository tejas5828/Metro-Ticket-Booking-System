#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "metro.h"
#include "file.h"

void displayticket(Customer*customer)                                                              //Displaying Booked All Ticket
{
    printf("================!! Ticket details !!=================\n");
    printf("%-10s %-11s %-11s %-11s %-13s\n","Name", "Source", "Destination", 
                    "Ticket ID", "Fare");
    printf("=====================================================\n");
    
    for (int i = 0; i < customer->ticketcount; i++)
    {
        printf("%-10s%-13s%-13s%-13s%-12s\n",customer->ticket[i].name,
            customer->ticket[i].source,
            customer->ticket[i].dest,                                                              //It Will Print All Tickets On Console
            customer->ticket[i].ticket_number,
            customer->ticket[i].fare);
    }
    printf("=====================================================\n"); 
}

void searchticket(Customer*customer)                                                               //Searching Booked Ticket                                                          
{
    char ticket[30];
    printf("Enter Ticket number : ");
    scanf("%s",ticket);
    printf("================!! Ticket details !!=================\n");
    printf("%-10s %-11s %-11s %-11s %-13s\n","Name", "Source", "Destination", 
                    "Ticket ID", "Fare");
    printf("=====================================================\n");
    
    for (int i = 0; i < customer->ticketcount; i++)
    {
        if (strcmp(ticket,customer->ticket[i].ticket_number)==0)                                   //It Will Check Ticket Number Is Present Or Not  
        {                                                                                               //If present Then Prints Ticket Information
            printf("%-10s%-13s%-13s%-13s%-12s\n",customer->ticket[i].name,
                customer->ticket[i].source,
                customer->ticket[i].dest,
                customer->ticket[i].ticket_number,
                customer->ticket[i].fare);
            break;
        }
    }
    printf("=====================================================\n");
}

int validatename(char *name, Customer *customer)                                                   //Validation Of Name
{
    int len = strlen(name);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(name[i]))                                                                     //It Will Check String Only Contains Character Or Not
        printf("**Invalid name**");                                                                               //If Not Then Returns 0
            return 0;
    }

    for (int i = 0; i < customer->customercount; i++)
    {
        if (strcmp(customer->users[i].name, name) == 0)                                            //It Will Check New Name With Customer List
                printf("**Duplicate name found**");                                                     //if Same Name Found Then Returns 0

            return 0;
    }
    return 1;
}

int validatepass(char *pass, Customer *customer)                                                   //Validation Of Pass
{
    int len = strlen(pass);

    if (len != 8){                                                                                 //It Will Check Pass Length Is 8 Or Not
        printf("**Invalid passs**");                                                                              //If Not Then Returns 0
        return 0;
    } 
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(pass[i]) && !isdigit(pass[i]))                                                //It Will Check There Is Atleast 1 Character or Digit
        {                                                                                                         //If Not Present Then Returns 0 
            printf("**Invalid passs**");
            return 0;
        }
    }

    for (int i = 0; i < customer->customercount; i++)
    {
        if (strcmp(customer->users[i].pass, pass) == 0){                                           //It Will Checks New Pass With Customers Pass 
            printf("**Duplicate pass found**");                                                         //If Same Pass Found Then Returns 0
            return 0;
        }
    }
    return 1;
}

void clearInput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int val_reg(Customer *customer)                                                                    //To Validate Registration Details
{
    char name[50], pass[50];

    clearInput();
    printf("\n===========Enter registration Details===========\n\n");
    printf("Enter name: ");
    scanf("%49[^\n]", name);

    clearInput();
    printf("Enter password (8 characters): ");
    scanf("%49[^\n]", pass);

    if (!validatename(name, customer))                                                             //Fun Call To Validate name 
    {
        printf("\n**Invalid name or Duplicate name found**\n");
        return 0;
    }

    if (!validatepass(pass, customer))                                                             //Fun Call To Validate Pass
    {
        printf("\n**Invalid pass or Duplicate passs found**\n");
        return 0;
    }

    strcpy(customer->users[customer->customercount].name, name);                                   //Copying Customers Details To File
    strcpy(customer->users[customer->customercount].pass, pass);

    customer->customercount++;                                                                     //To Increment Customer Count After Loading 
    printf("Registration successful!\n");                                                               //Customers Details
    return 1;
}

void savecustomer(Customer *customer)                                                                             
{
    savecustomers(customer);                                                                       //Fun Call TO Save Customers Details To Files
}

void loadCustomer(Customer *customer)                                                                              
{
    loadCustomers(customer);                                                                       //Fun Call To Load Customers To File
}

int val_login(Customer *customer)                                                                  //Validation Of Login Details
{
    char name[50], pass[50];
    while(1)
    {
    printf("\n=============Enter Login Details=============\n\n");

    clearInput();
    printf("Enter name: ");
    scanf("%49[^\n]", name);

    clearInput();
    printf("Enter password: ");
    scanf("%49[^\n]", pass);

    for (int i = 0; i < customer->customercount; i++)
    {
        if (strcmp(customer->users[i].name, name) == 0 &&                                          //It Wil Check Name And Pass With Customers Deatils
            strcmp(customer->users[i].pass, pass) == 0)                                                 //If Matches Then Let You Login
        {
            printf("\nLogin Successful!\n");
            return 1;
            break;
        }
    }

    printf("\n**Invalid Username or Password**\n");
    }
    return 0;
}

void ticketbooking(Customer *customer)                                                             //Fun Call For Booking Of Ticket
{
    static int ticket_id = 100;

    char *sourcelist[] = {                                                                         //Source Stations Of Metro
        "Halsuru", "Mg road", "Majestic",
        "Chikpet", "Trinity", "Hoodi"
    };

    printf("\n--- SOURCE STATIONS ---\n");    
    for (int i = 0; i < 6; i++)
        printf("%d. %s\n", i, sourcelist[i]);

    int opt;
    printf("Enter source index: ");
    scanf("%d", &opt);

    char *destlist[] = {                                                                           //Destination Stations Of Metro
        "Halsuru", "Mg road", "Majestic",
        "Chikpet", "Trinity", "Hoodi"
    };

    printf("\n--- DESTINATION STATIONS ---\n");
    for (int i = 0; i < 6; i++)
        printf("%d. %s\n", i, destlist[i]);

    int option;
    printf("Enter destination index: ");
    scanf("%d", &option);

    printf("\nYOU HAVE BOOKED TICKETS\n");
    printf("=>Source : %s\n", sourcelist[opt]);                                                    //It Will Print All Details To console
    printf("     -> TO <-\n");                                                                          //Like source Station , Dest Station
    printf("=>Destination : %s\n\n", destlist[option]);                                                      

    int fare = abs(option - opt) * 10;                                                             //Calculates Fare Amount

    printf("=>Ticket Id is : %d\n", ticket_id);                                                    //It Will Print Ticket no , Fare ,etc
    printf("=>Total travel fare is : %d\n", fare);


    int i = customer->ticketcount;

    strcpy(customer->ticket[i].name, customer->users[customer->customercount - 1].name);
    strcpy(customer->ticket[i].source, sourcelist[opt]);                                           //Loads All Information To ticket.csv File
    strcpy(customer->ticket[i].dest, destlist[option]);

    sprintf(customer->ticket[i].ticket_number, "%d", ticket_id);
    sprintf(customer->ticket[i].fare, "%d", fare);

    customer->ticketcount++;
    ticket_id++;

    //saveticket(customer);   
}

void cancelticket(Customer*customer)                                                               //Fun Call To Delete Or Cancel Ticket
{
    printf("================!! Ticket details !!=================\n");
    printf("%-10s %-11s %-11s %-11s %-13s\n","Name", "Source", "Destination", 
                    "Ticket ID", "Fare");
    printf("=====================================================\n");
    
    for (int i = 0; i < customer->ticketcount; i++)
    {
        printf("%-10s%-13s%-13s%-13s%-12s\n",customer->ticket[i].name,
            customer->ticket[i].source,
            customer->ticket[i].dest,                                                              //It Will Print All Tickets On Console
            customer->ticket[i].ticket_number,
            customer->ticket[i].fare);
    }
    printf("=====================================================\n"); 
    if (customer->ticketcount==0)
    {
       return;
    }
    
    int index;
    printf("Enter index number : ");
    scanf("%d",&index);
    
    if (index>customer->ticketcount || index<1)
    {
        return;
    }
    
    for (int i = index; i < customer->ticketcount; i++)
    {
        customer->ticket[i]=customer->ticket[i+1];
    }
    customer->ticketcount--;
}
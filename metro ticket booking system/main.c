#include <stdio.h>
#include <stdlib.h>
#include "metro.h"
#include "file.h"

int main()
{
    Customer customer;
    customer.customercount = 0;
    customer.ticketcount = 0;   

    loadticket(&customer);
    loadCustomer(&customer);
    
    printf("Ticket Count is %d",customer.ticketcount);
    int choice;

    while (1)
    {
        printf("\n========== METRO MANAGEMENT SYSTEM ==========\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("=============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            while (1)
            {
                if (val_reg(&customer))
                {
                    savecustomer(&customer);
                    break;
                }
            }
            break;

        case 2:
            if (val_login(&customer))
            {
                int opt;
                do
                {
                    printf("\n====== METRO MENU ======\n");
                    printf("1. Ticket Booking\n");
                    printf("2. Ticket management\n");  
                    printf("3. Logout\n");

                    printf("Enter option: ");
                    scanf("%d", &opt);

                    switch (opt)
                    {
                    case 1:
                        ticketbooking(&customer);
                        saveticket(&customer);
                        loadticket(&customer);
                        break;

                    case 2:
                    printf("\n====== Ticket Management ======\n");
                    printf("1.Display ticket\n2.Search ticket\n3.Cancel ticket\n");
                        int choice;
                        printf("Enter choice : ");
                        scanf("%d",&choice);
                        
                        switch (choice)
                        {
                        
                        case 1 :
                        displayticket(&customer);                        
                        break;
                    
                        case 2:
                        searchticket(&customer);
                        break;
                        case 3:
                        cancelticket(&customer);
                        break;
                    }
                    break;

                    case 3:
                        
                        break;

                    case 4:
                        //loadticket(&customer);   
                        break;

                    default:
                        printf("Invalid option! Try again.\n");
                    }

                } while (opt != 4);
            }
            else
            {
                printf("Login failed!\n");
            }
            break;

        case 3:
            printf("Exiting... Thank you!\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

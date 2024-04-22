#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Contact {
    int id;
    char phoneNumber[11];
    char email[20];
    char name[20];
    char company[30];
};
struct Contact contactsList[1000];
int numContacts, i;
int flag = 0;
int createFlag = 0;
void Create() {
    printf("Enter number of contacts to add: ");
    scanf("%d", &numContacts);
    for (i = 0; i< numContacts; i++) {
        contactsList[i].id = i + 1;
        printf("Enter phone number of %d: ", i + 1);
        scanf("\n");
        gets(contactsList[i].phoneNumber);
        printf("Enter Name of %d: ", i + 1);
        scanf("\n");
        gets(contactsList[i].name);
        printf("Enter email of %d: ", i + 1);
        scanf("\n");
        gets(contactsList[i].email);
        printf("Enter company name of %d: ", i + 1);
        scanf("\n");
        gets(contactsList[i].company);
    }
    createFlag = 1;
}

void Display() {
    if (createFlag == 1) {
        printf("\n%5s %20s %25s %25s %20s", "ID", "Phone Number", "Name", "Email", "Company");
        for (i = 0; i< numContacts + flag; i++) {
            printf("\n%5d %20s %25s %25s %20s", contactsList[i].id, contactsList[i].phoneNumber,
                   contactsList[i].name, contactsList[i].email, contactsList[i].company);
        }
        printf("\n");
    } else if (createFlag == 0) {
        printf("List is Empty!!!\n");
    }
}
void Insert() {
    contactsList[i].id = numContacts + flag + 1;
    printf("Enter phone number: ");
    scanf("\n");
    gets(contactsList[numContacts + flag].phoneNumber);
    printf("Enter name: ");
    scanf("\n");
    gets(contactsList[numContacts + flag].name);
    printf("Enter Email: ");
    scanf("\n");
    gets(contactsList[numContacts + flag].email);
    printf("Enter Company: ");
    scanf("\n");
    gets(contactsList[numContacts + flag].company);
    flag++;
}
void Delete() {
    int deleteFlag = 0;
    if (numContacts == 0) {
        printf("List is Empty\n");
    } else {
        int pos, i;
        char value[30];
        printf("Enter the name of contact to delete: ");
        scanf("\n");
        gets(value);
        for (i = 0; i < numContacts; i++) {
            if ((strcmp(contactsList[i].name, value)) == 0) {
                pos = i + 1;
                for (i = pos - 1; i < numContacts; i++) {
                    contactsList[i] = contactsList[i + 1];
                }
                numContacts--;
                deleteFlag = 1;
                break;
            } else {
                deleteFlag = 0;
            }
        }
        if (deleteFlag == 1) {
            printf("Contact Deleted!!!\n");
        } else if (deleteFlag == 0) {
            printf("Contact not found!!!\n");
        }
    }
}
void Search() {
    if (numContacts == 0) {
        printf("List is Empty!!!\n");
    } else {
        int searchFlag = 0;
        char value[30];
        printf("Enter the name to be searched: ");
        scanf("\n");
        gets(value);
        for (i = 0; i < numContacts; i++) {
            if ((strcmp(contactsList[i].name, value)) == 0) {
                printf("Contact Record found: \n");
                printf("\n%5s %20s %25s %25s %20s", "ID", "Phone Number", "Name", "Email", "Company");
                printf("\n%5d %20s %25s %25s %20s", contactsList[i].id, contactsList[i].phoneNumber,
                       contactsList[i].name, contactsList[i].email, contactsList[i].company);
                searchFlag = 1;
                printf("\n");
                break;
            }
        }
        if (searchFlag == 0) {
            printf("Contact Not Found!!!\n");
        }
    }
}
void Edit() {
    int searchFlag = 0;
    if (numContacts == 0) {
        printf("List is Empty!!!\n");
    } else {
        int x;
        char value[30];
        printf("Enter the name of contact to edit: ");
        scanf("\n");
        gets(value);
        for (int i = 0; i < numContacts; i++) {
            if ((strcmp(contactsList[i].name, value)) == 0) {
                x = i;
                searchFlag = 1;
            }
        }
        if (searchFlag == 1) {
            int choice;
            printf("Enter \n 1 to edit phone number\n 2 to edit name\n 3 to edit email\n 4 to edit company\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter phone number: ");
                    scanf("\n");
                    gets(contactsList[x].phoneNumber);
                    break;
                case 2:
                    printf("Enter Name: ");
                    scanf("\n");
                    gets(contactsList[x].name);
                    break;
                case 3:
                    printf("Enter email: ");
                    scanf("\n");
                    gets(contactsList[x].email);
                    break;
                case 4:
                    printf("Enter company name: ");
                    scanf("\n");
                    gets(contactsList[x].company);
                    break;
                default:
                    printf("Wrong Input!!!");
                    break;
            }
        } else if (searchFlag == 0) {
            printf("Contact Not Found!!!\n");
        }
    }
}
int main() {
    int choice;
    while (1) {
        system("cls");
        printf("1. Add new contacts to create list.\n");
        printf("2. Add new contact after list being created.\n");
        printf("3. List all Contacts.\n");
        printf("4. Delete a Contact\n");
        printf("5. Search Contacts.\n");
        printf("6. Edit a Contact\n");
        printf("7. Exit.\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Create();
                break;
            case 2:
                Insert();
                break;
            case 3:
                Display();
                break;
            case 4:
                Delete();
                break;
            case 5:
                Search();
                break;
            case 6:
                Edit();
                break;
            case 7:
                exit(0);
                return 0;
            default:
                printf("Invalid Choice...\n");
        }
        system("pause"); 
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct bus
{
    char busName[15];
    char busRoute[15];
    char busTime[15];
} Bus;

typedef struct node
{
    Bus busDetails;
    struct node *next;
} node;

/*For color*/
void red ()
{
    printf("\033[1;31m");
}


void reset ()
{
    printf("\033[0m");
}

node *head;
int main()
{
    int choice = interface();

    if(choice == 1){
        int choice1 = adminportal();
        if(choice1 == 1){
            displayBus(head);
        }
        else if(choice1 == 2){

            addBus();

        }
        else if(choice1 == 3){
            updateBus();

        }
        else if(choice1 == 4){
            deleteBus();

        }
        else if(choice1 == 0){
            interface();

        }




    }
    else if(choice == 2){
           int choice1 = studentPortal();

    }
    else if(choice == 3){
            int choice1 = facultyPortal();


    }
    else if(choice == 0){
            return 0;
    }
    return 0;
}

int interface(){
    int choice1;
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    red();
    printf("\t\t\t\t|      DIU Transport Management System        |\n");
    reset();
    printf("\t\t\t\t|---------------------------------------------|\n");
    printf("\n\t\t\t\t1.Admin Portal\n");
    printf("\n\t\t\t\t2.Student Portal\n");
    printf("\n\t\t\t\t3.Faculty Portal\n\n");
    printf("\n\t\t\t\t0.Exit\n\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\tEnter to access:");
    scanf("%d", &choice1);
    return choice1;

}

int adminportal(){

    int choice1;
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    red();
    printf("\t\t\t\t|      DIU Transport Management System        |\n");
    reset();
    printf("\t\t\t\t|---------------------------------------------|\n");
    printf("\n\t\t\t\t1.Display Bus Schedule\n");
    printf("\n\t\t\t\t2.Add Bus Schedule\n");
    printf("\n\t\t\t\t3.Update Bus Schedule\n");
    printf("\n\t\t\t\t4.Delete Bus Schedule\n");
    printf("\n\t\t\t\t0.Return to Main Menu\n\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\tEnter to access:");

    scanf("%d", &choice1);
    return choice1;
}
addBus(){
            system("cls");
            Bus bs;
            char name[20];
            printf("\t\t\t\tEnter Bus Name:");
            scanf("%s",name);
            strcpy(bs.busName,name);
            fflush(stdin);
            printf("\t\t\t\tEnter Bus Route:");
            scanf("%s",name);
            strcpy(bs.busRoute,name);
            fflush(stdin);
            printf("\t\t\t\tEnter Bus Time:");
            scanf("%s",name);
            strcpy(bs.busTime,name);
            busAllocation(head,bs);
}
void busAllocation(node *nd,Bus info)
{
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->busDetails = info;
    temp->next = NULL;
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        while(nd->next!=NULL){
            nd=nd->next;
            }
        nd->next = temp;
    }
    printf("\t\t\t\tYour bus  %s is enlisted now..",temp->busDetails.busName);
    fflush(stdin);
    getchar();
}

int displayBus(node *nd){
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|          ALL Bus Schedules RECORDS          |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\tBus Name\tBus Route\tBus Time\n\n");
    printf("\t----\t--\t------------\t------------\t------\t----\n\n");
    node *t = nd;


    while( t != NULL )
    {
        printf("\t%s\t%s\t%s\t\n",t->busDetails.busName,t->busDetails.busRoute,t->busDetails.busTime);
        t = t->next;
    }
    fflush(stdin);
    getchar();

    return 0;

}
int updateBus(){

    return 0;

}
int deleteBus(){
    return 0;

}


int studentPortal(){
    return 0;
}

int facultyPortal(){
    return 0;
}

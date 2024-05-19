#include <stdio.h>
#include <stdlib.h>

typedef struct bus
{
    char busName[15];
    char busRoute[15];
    char busTime[15];
    int busid;
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
            int busID;
            system("cls");
            printf("\t\t\t\tSearch by Bus ID:");
            scanf("%d",&busID);
            updateBus(head,busID);


        }
        else if(choice1 == 4){
            int busID;
            system("cls");
            printf("\t\t\t\tSearch by Bus ID:");
            scanf("%d",&busID);
            deleteBus(head,busID);

        }

        else if(choice1 == 0){
            main();

        }




    }
    else if(choice == 2){
           int choice1 = studentPortal();
           if(choice1 == 1){
            displayBus(head);
           }
           if(choice1 == 2){
            bookSeat();
           }
           if(choice1 == 3){
            noticeBoard();
           }

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
    printf("\n\t\t\t\t2.Student & Faculty Portal\n");
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
    printf("\t\t\t\t|               Admin Portal                  |\n");
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
            scanf("%s",&name);
            strcpy(bs.busName,name);
            fflush(stdin);
            printf("\t\t\t\tEnter Bus Route:");
            scanf("%s",&name);
            strcpy(bs.busRoute,name);
            fflush(stdin);
            printf("\t\t\t\tEnter Bus Time:");
            scanf("%s",&name);
            strcpy(bs.busTime,name);
            printf("\t\t\t\tEnter Bus ID:");
            scanf("%d",&bs.busid);
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
    printf("\t\t\t\tYour bus  %s is enlisted now..\n",temp->busDetails.busName);
    printf("\t\t\t\tEnter 0 to return to main menu:\n");

    int choice1;

    scanf("%d", &choice1);
    if(choice1 == 0){
        main();
    }
}

int displayBus(node *nd){
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|             ALL Bus Schedules               |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\tBus Name\tBus Route\tBus Time\tBus ID\n\n");
    printf("\t----\t--\t------------\t------------\t------\t----\n\n");
    node *t = nd;


    while( t != NULL )
    {
        printf("\t%s\t%s\t%s\t\t%d\n",t->busDetails.busName,t->busDetails.busRoute,t->busDetails.busTime,t->busDetails.busid);
        t = t->next;
    }
    printf("\n\n\t\t\t\tEnter 0 to return to main menu:\n");

    int choice1;

    scanf("%d", &choice1);
    if(choice1 == 0){
        main();
    }

    return 0;

}
void updateBus(node *nd,int id)
{
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|              Bus RECORDS             |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\t\tBus Name\t\tId\t\tBus route\t\tBus Time\t\Bus Id\t\n\n");
    node *t = nd;
    int flag=0;
    while(t!= NULL)
    {
        if(t->busDetails.busid == id)
        {
            flag=1;
            break;
        }
        t=t->next;
    }
    if(flag==0)
    {
        printf("\n\t\t\t\tBus name is not valid");
        printf("\n\n\n\t\t\t\tplease enter to get  back");
        getchar();
        return;
    }
    else
    {
        printf("\t%s\t%s\t%s\t\t%d\n",t->busDetails.busName,t->busDetails.busRoute,t->busDetails.busTime,t->busDetails.busid);
    }

    printf("\n\n\t\t\t\t.....Update Bus Details.....");

    char name[20];
    printf("\n\t\t\t\tEnter Bus Name:");
    scanf("%s",name);
    strcpy(t->busDetails.busName,name);
    printf("\n\t\t\t\tEnter Bus Route:");
    scanf("%s",name);
    strcpy(t->busDetails.busRoute,name);
    fflush(stdin);
    printf("\n\t\t\t\tEnter bus time:");
    scanf("%s",name);
    strcpy(t->busDetails.busTime,name);
    fflush(stdin);
    printf("\n\t\t\t\tBus Updated....");
    int x;
    printf("\n\t\t\t\tEnter 0 to return to main menu: ");
    scanf("%d",&x);
    if(x == 0){
        main();
    }
}
void deleteBus(node *nd,int id)
{

    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|              Bus RECORDS             |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\t\tBus Name\t\tBus route\t\tBus Time\t\Bus Id\t\n\n");
    node *t = nd;
    int flag=0;
    int count=0;
    while(t!= NULL)
    {
        if(t->busDetails.busid==id)
        {

            flag=1;
            break;
        }
        count++;
        t=t->next;
    }
    if(flag==0)
    {
        printf("\n\t\t\t\tBus Id is not valid");
        int x;
        printf("\n\t\t\t\tEnter 0 to return to main menu: ");
        scanf("%d",&x);
        if(x == 0){
            main();
        }
    }
    else
    {
        printf("\t\t%s\t%s\t%s\t\t%d\t\t\n",t->busDetails.busName,t->busDetails.busRoute,t->busDetails.busTime,t->busDetails.busid);
    }


    printf("\n\n\t\t\t\t.....Are you sure to delete this Bus  details(Y/N)?");
    printf("\n\t\t\t\tEnter Choice:");
    char ch;
//printf("\n\n\ncount %d",count);
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='Y' || ch=='y')
    {
        if(count==0)
        {

            node *temp = nd;
            head = nd->next;
            free(temp);
            printf("\n\t\t\t\tBus Details Deleted successfully..");
            int x;
            printf("\n\t\t\t\tEnter 0 to return to main menu: ");
            scanf("%d",&x);
            if(x == 0){
                main();
            }
        }
        else
        {
            node *t = nd;
            while(t->next->busDetails.busid!=id)
            {
                t=t->next;
            }
            node *temp = t;
            temp = t->next;
            t->next = temp->next;
            free(temp);
            printf("\n\t\t\t\tBus Details Deleted successfully..");
            int x;
            printf("\n\t\t\t\tEnter 0 to return to main menu: ");
            scanf("%d",&x);
            if(x == 0){
                main();
            }
        }
    }
    else if(ch=='N' || ch=='n')
    {
        return;
    }
    else
    {
        printf("\n\t\t\t\tWrong input...");
        getchar();
    }

}



int studentPortal(){
    int choice1;
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    red();
    printf("\t\t\t\t|          Student & Faculty Portal           |\n");
    reset();
    printf("\t\t\t\t|---------------------------------------------|\n");
    printf("\n\t\t\t\t1.Display Bus Schedule\n");
    printf("\n\t\t\t\t2.Book a Seat\n");
    printf("\n\t\t\t\t3.Notice Board\n");
    printf("\n\t\t\t\t0.Return to Main Menu\n\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\tEnter to access:");

    scanf("%d", &choice1);
    return choice1;
}

int bookSeat(){
    char choice1[15];
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    red();
    printf("\t\t\t\t|           Book a Seat[Beta Version]         |\n");
    reset();
    printf("\t\t\t\t|---------------------------------------------|\n");
    printf("\n\t\t\t\tThe Red Marked seats are Booked\n");

    printf("\n\t\t\t\tA1 A2\t  A3 A4\n");
    printf("\n\t\t\t\tB1 B2\t  B3 B4\n");
    printf("\n\t\t\t\tC1 C2\t  C3 C4\n");
    printf("\n\t\t\t\tD1 D2\t  D3 D4\n");
    red();
    printf("\n\t\t\t\tE1 E2\t  E3 E4\n");
    printf("\n\t\t\t\tF1 F2\t  F3 F4\n");
    printf("\n\t\t\t\tG1 G2\t  G3 G4\n");
    printf("\n\t\t\t\tH1 H2\t  H3 H4\n");
    reset();
    printf("\n\t\t\t\tI1 I2\t  I3 I4\n");
    printf("\n\t\t\t\tJ1 J2\t  J3 J4\n");
    printf("\n\t\t\t\t0.Return to Main Menu\n\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\tEnter to access:");

    scanf("%s", &choice1);

    if(choice1 == "0"){
        main();
    }else{
    printf("\n\t\t\t\t\Your seat is booked now");
    int x;
    printf("\n\t\t\t\tEnter 0 to return to main menu: ");
    scanf("%d",&x);
    if(x == 0){
        main();
    }
    }
}



void noticeBoard()
{
    system("cls");
    FILE *fptr;

    fptr = fopen("NoticeBoard.txt","r");

    char content[10000];

    if (fptr != NULL){
        while(fgets(content,10000,fptr)){
            printf("%s",content);
        }
    }
    else{
        printf("File open unsuccessful");
    }
    int x;
    printf("\n\t\t\t\tEnter 0 to return to main menu: ");
    scanf("%d",&x);
    if(x == 0){
        main();
    }

}


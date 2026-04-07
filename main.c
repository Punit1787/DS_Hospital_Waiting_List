#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct patient
{
    int id;
    char name[50];
    char disease[50];
    int priority;
    struct patient *next;
}patient;

typedef struct
{
    patient *front;
}queue;

int selectDisease(char disease[])
{
    int c, d;
    printf("\nSelect Disease Category:\n1. Common\n2. Serious\n3. Infectious\n4. Injury\nEnter Category=");
    scanf("%d", &c);
    if(c == 1)
    {
        printf("\nCommon Diseases:\n1. Fever\n2. Cold & Cough\n3. Headache\n4. Stomach Pain\nEnter Choice=");
        scanf("%d", &d);
        if(d == 1)
        {
            strcpy(disease, "Fever");
            return 2;
        }
        else if(d == 2)
        {
            strcpy(disease, "Cold & Cough");
            return 2;
        }
        else if(d == 3)
        {
            strcpy(disease, "Headache");
            return 1;
        }
        else if(d == 4)
        {
            strcpy(disease, "Stomach Pain");
            return 2;
        }
        else
        {
            printf("\nInvalid Choice");
            strcpy(disease, "Not Specified");
            return 2;
        }
    }
    else if(c == 2)
    {
        printf("\nSerious Diseases:\n1. Heart Problem\n2. Asthma Attack\n3. Chest Pain\nEnter Choice=");
        scanf("%d", &d);
        if(d == 1)
        {
            strcpy(disease, "Heart Problem");
            return 5;
        }
        else if(d == 2)
        {
            strcpy(disease, "Asthma Attack");
            return 4;
        }
        else if(d == 3)
        {
            strcpy(disease, "Chest Pain");
            return 4;
        }
        else
        {
            printf("\nInvalid Choice");
            strcpy(disease, "Not Specified");
            return 4;
        }
    }
    else if(c == 3)
    {
        printf("\nInfectious Diseases:\n1. COVID-19\n2. Dengue\n3. Malaria\nEnter Choice=");
        scanf("%d", &d);
        if(d == 1)
        {
            strcpy(disease, "COVID-19");
            return 3;
        }
        else if(d == 2)
        {
            strcpy(disease, "Dengue");
            return 3;
        }
        else if(d == 3)
        {
            strcpy(disease, "Malaria");
            return 3;
        }
        else
        {
            printf("\nInvalid Choice");
            strcpy(disease, "Not Specified");
            return 3;
        }
    }
    else if(c == 4)
    {
        printf("\nInjury Types:\n1. Fracture\n2. Burns\n3. Accident Injury\nEnter Choice=");
        scanf("%d", &d);
        if(d == 1)
        {
            strcpy(disease, "Fracture");
            return 4;
        }
        else if(d == 2)
        {
            strcpy(disease, "Burns");
            return 5;
        }
        else if(d == 3)
        {
            strcpy(disease, "Accident Injury");
            return 5;
        }
        else
        {
            printf("\nInvalid Choice");
            strcpy(disease, "Not Specified");
            return 4;
        }
    }
    else
    {
        printf("\nInvalid Category");
        strcpy(disease, "Not Specified");
        return 2;
    }
}

int isempty(queue *q)
{
    if(q->front == NULL)    return 1;
    else                    return 0;
}

void addPatient(queue *q)
{
    int id, priority;
    char name[50], disease[50];
    patient *newnode, *temp;

    printf("\nEnter Patient Name=");
    scanf(" %[^\n]", name);
    printf("Enter Patient ID=");
    scanf("%d", &id);
    priority = selectDisease(disease);

    newnode = (patient*)malloc(sizeof(patient));
    newnode->id = id;
    strcpy(newnode->name, name);
    strcpy(newnode->disease, disease);
    newnode->priority = priority;
    newnode->next = NULL;

    if(isempty(q) || priority > q->front->priority)
    {
        newnode->next = q->front;
        q->front = newnode;
    }
    else
    {
        temp = q->front;
        while(temp->next != NULL && temp->next->priority >= priority)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("\nPatient %s added successfully with Priority=%d", name, priority);
}

void removePatient(queue *q)
{
    patient *temp;

    if(isempty(q))   printf("\nQueue is Empty. No patients waiting.");
    else
    {
        temp = q->front;
        q->front = q->front->next;
        printf("\nPatient Removed:  %s", temp->name);
        free(temp);
    }
}

void displayAll(queue *q)
{
    patient *temp;
    int sr;

    if(isempty(q))  printf("\nQueue is Empty. No patients waiting.");
    else
    {
        temp = q->front;
        sr = 1;
        printf("Sr No.\tID\tName\tDisease\t\tPriority");
        while(temp != NULL)
        {
            printf("\n%d\t%d\t%s\t%s\t%d",sr,temp->id,temp->name, temp->disease, temp->priority);
            temp = temp->next;
            sr++;
        }
    }
}

void peekPatient(queue *q)
{
    if(isempty(q))  printf("\nQueue is Empty. No patients waiting.");
    else            printf("\nNext Patient to be Treated: %s", q->front->name);
}

void searchPatient(queue *q)
{
    int id, sr, f;
    patient *temp;

    if(isempty(q))  printf("\nQueue is Empty. No patients waiting.");
    else
    {
        id = 0;
        sr = 1;
        f = 0;
        printf("\nEnter Patient ID to Search=");
        scanf("%d", &id);
        temp = q->front;
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                printf("\nPatient Found at Position %d: ID=%d Name=%s Disease=%s Priority=%d", sr, temp->id, temp->name, temp->disease, temp->priority);
                f = 1;
                break;
            }
            temp = temp->next;
            sr++;
        }
        if(f == 0)  printf("\nNo Patient found with ID=%d", id);
    }
}

int countPatients(queue *q)
{
    int count;
    patient *temp;

    count = 0;
    temp = q->front;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void estimateWaitingTime(queue *q)
{
    int id, sr, f;
    patient *temp;

    if(isempty(q))  printf("\nQueue is Empty. No patients waiting.");
    else
    {
        id = 0;
        sr = 1;
        f = 0;
        printf("\nEnter Patient ID=");
        scanf("%d", &id);
        temp = q->front;
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                printf("\nPatient: %s\nEstimated Waiting Time = %d minutes", temp->name, (sr-1)*10);
                f = 1;
                break;
            }
            temp = temp->next;
            sr++;
        }
        if(f == 0) printf("\nNo Patient found with ID=%d", id);
    }
}

void displayByDiseaseType(queue *q)
{
    int cat, f;
    patient *temp;

    if(isempty(q))
    {
        printf("\nQueue is Empty...");
    }
    else
    {
        cat = 0;
        f = 0;
        printf("\nSelect Disease Category:\n1. Common\n2. Serious\n3. Infectious\n4. Injury\nEnter Category=");
        scanf("%d", &cat);
        temp = q->front;
        while(temp != NULL)
        {
            if(cat==1)
            {
                if(strcmp(temp->disease,"Fever")==0 || strcmp(temp->disease,"Cold & Cough")==0 || strcmp(temp->disease,"Headache")==0 || strcmp(temp->disease,"Stomach Pain")==0)
                {
                    printf("\n%d\t%s\t%s\t%d", temp->id, temp->name, temp->disease, temp->priority);
                    f=1;
                }
            }
            else if(cat==2)
            {
                if(strcmp(temp->disease,"Heart Problem")==0 || strcmp(temp->disease,"Asthma Attack")==0 || strcmp(temp->disease,"Chest Pain")==0)
                {
                    printf("\n%d\t%s\t%s\t%d", temp->id, temp->name, temp->disease, temp->priority);
                    f=1;
                }
            }
            else if(cat==3)
            {
                if(strcmp(temp->disease,"COVID-19")==0 || strcmp(temp->disease,"Dengue")==0 || strcmp(temp->disease,"Malaria")==0)
                {
                    printf("\n%d\t%s\t%s\t%d", temp->id, temp->name, temp->disease, temp->priority);
                    f=1;
                }
            }
            else if(cat==4)
            {
                if(strcmp(temp->disease,"Fracture")==0 || strcmp(temp->disease,"Burns")==0 || strcmp(temp->disease,"Accident Injury")==0)
                {
                    printf("\n%d\t%s\t%s\t%d", temp->id, temp->name, temp->disease, temp->priority);
                    f=1;
                }
            }
            temp=temp->next;
        }
        if(f==0)    printf("\nNo patients found...");
    }
}

void clearQueue(queue *q)
{
    patient *temp;

    if(isempty(q)) printf("\nQueue is already Empty.");
    else
    {
        while(q->front != NULL)
        {
            temp = q->front;
            q->front = q->front->next;
            free(temp);
        }
        q->front = NULL;
        printf("Queue is now emptied");
    }
}

int main()
{
    int ch, x;
    queue q;

    q.front = NULL;
    while(1)
    {
        printf("\n\nHospital Waiting List\n1-Add Patient\n2-Remove Patient\n3-Display All Patients\n4-Peek Next Patient\n5-Search Patient by ID\n6-Count Total Patients\n7-Check if Queue is Empty\n8-Estimate Waiting Time\n9-Display Patients by Disease Type\n10-Clear Entire Queue\n11-Exit\nEnter Choice=");
        scanf("%d", &ch);
        if(ch == 11)    break;
        switch(ch)
        {
            case 1:
            {
                addPatient(&q);
            }break;
            case 2:
            {
                removePatient(&q);
            }break;
            case 3:
            {
                displayAll(&q);
            }break;
            case 4:
            {
                peekPatient(&q);
            }break;
            case 5:
            {
                searchPatient(&q);
            }break;
            case 6:
            {
                x = countPatients(&q);
                printf("\nTotal Patients in Queue = %d", x);
            }break;
            case 7:
            {
                x = isempty(&q);
                if(x==1) printf("\nQueue is Empty");
                else     printf("\nQueue is not Empty");
            }break;
            case 8:
            {
                estimateWaitingTime(&q);
            }break;
            case 9:
            {
                displayByDiseaseType(&q);
            }break;
            case 10:
            {
                clearQueue(&q);
            }break;
            default:    printf("\nInvalid Choice...");
        }
    }
    return 0;
}

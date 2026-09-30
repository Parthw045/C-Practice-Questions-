#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Patient structure
typedef struct
{
    int id;
    char name[50];
    int age;
    char problem[100];
} Patient;


// Queue structure
typedef struct
{
    Patient patients[MAX];
    int front;
    int rear;
} Queue;


// Initialize Queue
void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}


// Check if Queue is Empty
int isEmpty(Queue *q)
{
    if (q->front == -1)
        return 1;

    return 0;
}


// Check if Queue is Full
int isFull(Queue *q)
{
    if (q->rear == MAX - 1)
        return 1;

    return 0;
}


// Add Patient to Queue (ENQUEUE)
void addPatient(Queue *q)
{
    Patient newPatient;

    if (isFull(q))
    {
        printf("\nQueue is full! Cannot add more patients.\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &newPatient.id);

    getchar(); // Clear newline

    printf("Enter Patient Name: ");
    fgets(newPatient.name, sizeof(newPatient.name), stdin);

    newPatient.name[strcspn(newPatient.name, "\n")] = '\0';

    printf("Enter Patient Age: ");
    scanf("%d", &newPatient.age);

    getchar();

    printf("Enter Health Problem: ");
    fgets(newPatient.problem, sizeof(newPatient.problem), stdin);

    newPatient.problem[strcspn(newPatient.problem, "\n")] = '\0';


    // If first patient
    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear++;

    q->patients[q->rear] = newPatient;

    printf("\nPatient added successfully to the queue!\n");
    printf("Queue Position: %d\n", q->rear - q->front + 1);
}


// Serve Patient (DEQUEUE)
void servePatient(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nNo patients are waiting.\n");
        return;
    }

    Patient currentPatient = q->patients[q->front];

    printf("\n====================================\n");
    printf("        PATIENT BEING SERVED\n");
    printf("====================================\n");

    printf("Patient ID: %d\n", currentPatient.id);
    printf("Name      : %s\n", currentPatient.name);
    printf("Age       : %d\n", currentPatient.age);
    printf("Problem   : %s\n", currentPatient.problem);

    // If last patient
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }

    printf("\nPatient has been served successfully!\n");
}


// Display Next Patient (PEEK)
void nextPatient(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nNo patients are waiting.\n");
        return;
    }

    Patient p = q->patients[q->front];

    printf("\n====================================\n");
    printf("         NEXT PATIENT\n");
    printf("====================================\n");

    printf("Patient ID: %d\n", p.id);
    printf("Name      : %s\n", p.name);
    printf("Age       : %d\n", p.age);
    printf("Problem   : %s\n", p.problem);
}


// Display All Patients
void displayQueue(Queue *q)
{
    int i;
    int position = 1;

    if (isEmpty(q))
    {
        printf("\nNo patients are waiting.\n");
        return;
    }

    printf("\n===============================================================\n");
    printf("                    PATIENT WAITING LIST\n");
    printf("===============================================================\n");

    printf("%-10s %-10s %-25s %-8s %-20s\n",
           "Position", "ID", "Name", "Age", "Problem");

    printf("---------------------------------------------------------------\n");

    for (i = q->front; i <= q->rear; i++)
    {
        printf("%-10d %-10d %-25s %-8d %-20s\n",
               position,
               q->patients[i].id,
               q->patients[i].name,
               q->patients[i].age,
               q->patients[i].problem);

        position++;
    }

    printf("===============================================================\n");

    printf("\nTotal Patients Waiting: %d\n",
           q->rear - q->front + 1);
}


// Main Function
int main()
{
    Queue q;

    int choice;

    initializeQueue(&q);

    printf("\n========================================\n");
    printf("   HOSPITAL PATIENT QUEUE MANAGEMENT\n");
    printf("========================================\n");

    do
    {
        printf("\n");
        printf("1. Add Patient to Queue\n");
        printf("2. Serve Next Patient\n");
        printf("3. View Next Patient\n");
        printf("4. Display All Waiting Patients\n");
        printf("5. Check Queue Status\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addPatient(&q);
                break;

            case 2:
                servePatient(&q);
                break;

            case 3:
                nextPatient(&q);
                break;

            case 4:
                displayQueue(&q);
                break;

            case 5:

                if (isEmpty(&q))
                {
                    printf("\nQueue is Empty.\n");
                }
                else
                {
                    printf("\nQueue is Not Empty.\n");
                    printf("Patients Waiting: %d\n",
                           q.rear - q.front + 1);
                }

                break;

            case 0:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
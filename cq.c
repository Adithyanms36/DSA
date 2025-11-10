    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 5

    int queue[MAX], front = -1, rear = -1;

    void enqueue()
    {
        int n;
        if (front == ((rear + 1) % (MAX)))
        {
            printf("Overflow\n");
        }
        else
        {
            printf("Enter the number to insert : ");
            scanf("%d", &n);
            if (front == -1 && rear == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = ((rear + 1) % (MAX));
            }
            queue[rear] = n;
        }
    }

    void dequeue()
    {
        int n;
        if (front == -1 && rear == -1)
        {
            printf("Underflow\n");
        }
        else
        {
            n = queue[front];
            printf("Item deleted\n");
            front = ((front + 1) % MAX);
        }
    }

    void display()
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i < MAX; i++)
            {
                printf("%d ", queue[i]);
            }

            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
    }

    int main()
    {
        int choice;
        while (1)
        {
            printf("\n1.Insert\n");
            printf("\n2.Delete\n");
            printf("\n3.Display\n");
            printf("\nEnter the choice\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3 :
                    display();
                    break;
            case 4 : 
                    exit(0);
            }
        }
        return 0;
    }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct content
{
    char movie[40];
    int release;
    int rating;
    char platform[40];
    struct web *next;
};

typedef struct content *NODE;



void platform(NODE head);
NODE getnewnode()
{
    NODE newnode = (NODE)malloc(sizeof(struct content));
    if (newnode == NULL)
    {
        printf("memory allocation failed\n");
        exit(0);
    }
    printf("Enter the movie name, year of release,  platform, rating: ");
    scanf("%s%d%s%f", newnode->movie, &newnode->release, newnode->platform, &newnode->rating);
    newnode->next = NULL;
    return newnode;
}

NODE insert_end(NODE head, NODE *last)
{
    NODE newnode = getnewnode();
    if (head == NULL)
    {
        head = newnode;
        *last = newnode;
        newnode->next = head;
    }
    else
    {
        (*last)->next = newnode;
        newnode->next = head;
        *last = newnode;
    }
    return head;
}

void display(NODE head)
{
    NODE present = head;
    if (head == NULL)
    {
        printf("movie list is empty\n");
        return;
    }
    printf("movies:\n");
    do
    {
        printf("%s %d %s %f\n", present->movie, present->release, present->platform, present->rating);
        present = present->next;
    } while (present!= head);
}

void count_display_year(NODE head)
{
    NODE present = head;
    int count = 0, syear;
    printf("Enter the year to search: ");
    scanf("%d", &syear);
    if (head == NULL)
    {
        printf("movie list is empty\n");
        return;
    }
    printf("movie released in %d:\n", syear);
    do
    {
        if (present->release == syear)
        {
            printf("%s %d\n", present->movie, present->release);
            count++;
        }
        present= present->next;
    } while (present != head);
    printf("Count: %d\n", count);
}

void platform(NODE head)
{
    NODE present= head;
    char sweb[50];
    printf("Enter the name of the movie whose platform you want to know: ");
    scanf("%s", sweb);
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    do
    {
        if (strcmp(present->movie, sweb) == 0)
        {
            printf("%s %s %.2f\n", present->movie, present->platform, present->rating);
        }
        present = present->next;
    } while (present != head);
}

void output_file(NODE head)
{
    FILE *fp;
    NODE present = head;
    fp = fopen("webseries.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    do
    {
        fprintf(fp, "%s %d %s %2f\n", present->movie, present->release, present->platform, present->rating);
        present = present->next;
    } while (present != head);

    fclose(fp);
}

NODE input_file()
{
    FILE *fp;
    NODE head = NULL, last = NULL;
    fp = fopen("webseries.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening the file.\n");
        return NULL;
    }

    while (!feof(fp))
    {
        NODE newnode = getnewnode();
        if (head == NULL)
        {
            head = newnode;
            last = newnode;
            newnode->next = head;
        }
        else
        {
            last->next = newnode;
            newnode->next = head;
            last = newnode;
        }

        fscanf(fp, "%s %d %s %f", newnode->movie, &newnode->release, newnode->platform, &newnode->rating);
    }

    fclose(fp);
    printf("Data loaded from file successfully.\n");
    return head;
}



int main()
{
    NODE head = NULL, tail = NULL;
    int i, n;
    char choice;

    printf("Do you want to load data from file? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        head = input_file();
    }
    else
    {
        printf("Enter the number of movies: ");
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            head = insert_end(head, &tail);
        }
    }

    display(head);
    count_display_year(head);
    platform(head);

    printf("Do you want to record data to file? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        output_file(head);
    }

    return 0;
}



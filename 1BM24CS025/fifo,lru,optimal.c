#include <stdio.h>

void FIFO(int pages[], int n, int f)
{
    int frames[10], i, j, k;
    int front = 0, faults = 0;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement\n");

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        for(k = 0; k < f; k++)
            if(frames[k] != -1)
                printf("%d ", frames[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
}

void LRU(int pages[], int n, int f)
{
    int frames[10], time[10];
    int i, j, k;
    int faults = 0, counter = 0;

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement\n");

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int pos = 0;

            for(j = 1; j < f; j++)
                if(time[j] < time[pos])
                    pos = j;

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        for(k = 0; k < f; k++)
            if(frames[k] != -1)
                printf("%d ", frames[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
}

void Optimal(int pages[], int n, int f)
{
    int frames[10];
    int i, j, k;
    int faults = 0;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement\n");

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int pos = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                int farthest = -1;

                for(j = 0; j < f; j++)
                {
                    int nextUse = 9999;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            nextUse = k;
                            break;
                        }
                    }

                    if(nextUse > farthest)
                    {
                        farthest = nextUse;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        for(k = 0; k < f; k++)
            if(frames[k] != -1)
                printf("%d ", frames[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
}

int main()
{
    int pages[50];
    int n, f, i;

    printf("Ajay k o ---> 1BM24CS025\n");
    printf("USN: 1BM24CS025\n");

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    FIFO(pages, n, f);
    LRU(pages, n, f);
    Optimal(pages, n, f);

    return 0;
}

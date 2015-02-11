#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


#define NUM 10
#define MAXVALUE 100

void initialArray(int *_data)
{

    int i;

    for (i = 0; i<NUM; ++i)
    {
        _data[i] = rand()%MAXVALUE;
    }


}

void printfArray(int*array)
{
    int i;

    printf ("The Array is :[");
    for (i=0;i<NUM;i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void bubbleSort(int *array)
{
    int i, l;
    int temp;
    for (i=0;i<NUM-1;i++)
    {
        for (l=0;l<NUM-i-1;l++)
        {
            if (array[l]>array[l+1])
            {
                temp = array[l+1];
                array[l+1] = array[l];
                array[l] = temp;
            }
        }
    }
}

void quickSort(int *array, int low, int up)
{
    int key = low, orig_low = low, orig_up = up, temp;
    if(low>=up)
        return;
    low = low + 1;
    while(low<=up)
    {
        while(array[up]>array[key])
            up = up - 1;
        while(array[low]<array[key] && low <=orig_up)
            low = low + 1;
        if(low < up)
        {
            temp = array[low];
            array[low] = array[up];
            array[up] = temp;
        }
    }
    temp = array[key];
    array[key] = array[up];
    array[up] = temp;
    quickSort(array, orig_low, up-1);
    quickSort(array, low, orig_up);
}

struct timespec nanoTime1, nanoTime2;

void startTimer()
{
    clock_gettime(CLOCK_REALTIME, &nanoTime1);

}

void stopTimer()
{
    clock_gettime(CLOCK_REALTIME, &nanoTime2);
    long int diffNano = (nanoTime2.tv_sec-nanoTime1.tv_sec)*1000000000+nanoTime2.tv_nsec-nanoTime1.tv_nsec;
    printf("passing time: %ld (nanosecs) \t",diffNano);

}

int main()
{

    int data[NUM];



    initialArray(data);
    printfArray(data);
    bubbleSort(data);
    printfArray(data);
    startTimer();
    quickSort(data, 0, NUM-1);
    stopTimer();
    return EXIT_SUCCESS;
}

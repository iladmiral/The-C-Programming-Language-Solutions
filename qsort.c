#include <stdio.h>

/* swap: swap between two elements with the given index */
void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: sort v[left]...sort v[right] into increacing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    //swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (right + left) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


int main(void)
{
    int v[] = {1, 5, 3, 2, 4};
    qsort(v, 0, 4);
    for (int i = 0; i < 5; i++)
        printf("%i ", v[i]);
    printf("\n");
    return 0;
}
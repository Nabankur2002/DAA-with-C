#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int weight;
    int profit;
    float ratio;
} item;
int compare(const void *a, const void *b)
{
    item *i1 = (item *)a;
    item *i2 = (item *)b;
    return (i2->ratio > i1->ratio) - (i2->ratio < i1->ratio);
}
void fractional_knapsack(int n, int capacity, item its[])
{
    qsort(its, n, sizeof(item), compare);
    float total_profit = 0.0;
    float fractions[n];
    for (int i = 0; i < n; i++)
    {
        fractions[i] = 0.0;
    }
    int rc = capacity;
    for (int i = 0; i < n; i++)
    {
        if (its[i].weight <= rc)
        {
            fractions[i] = 1.0;
            total_profit += its[i].profit;
            rc -= its[i].weight;
        }
        else
        {
            fractions[i] = (float)rc / its[i].weight;
            total_profit += its[i].profit * fractions[i];
            break;
        }
    }
    printf("\nMax profit: %.2f\n", total_profit);
    printf("\nProportion of items taken:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: %.2f %%\n", i + 1, fractions[i] * 100);
    }
}
int main()
{
    int n, capacity;
    printf("\nEnter number of items: ");
    scanf("%d", &n);
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);
    item its[n];
    printf("\nEnter weight and profit for each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d - Weight Profit: ", i + 1);
        scanf("%d %d", &its[i].weight, &its[i].profit);
        its[i].ratio = (float)its[i].profit / its[i].weight;
    }
    fractional_knapsack(n, capacity, its);
    return 0;
}
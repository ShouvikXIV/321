#include <stdio.h>

struct Paratha
{
    int quantity;
    int unit;
};
struct Vegetable
{
    int quantity;
    int unit;
};
struct Mineral_Water
{
    int quantity;
    int unit;
};
int main() {
    int q;
    int u;
    struct Paratha p;
    printf("Quantity Of Paratha: ");
    scanf("%d",&q);
    printf("\nUnit Price: ");
    scanf("%d",&u);
    p.quantity = q;
    p.unit = u;
    int tp = p.quantity*p.unit;

    struct Vegetable v;
    printf("Quantity Of Vegetable: ");
    scanf("%d",&q);
    printf("\nUnit Price: ");
    scanf("%d",&u);
    v.quantity = q;
    v.unit = u;
    int tv = v.quantity*v.unit;

    struct Mineral_Water mw;
    printf("Quantity Of Mineral Water: ");
    scanf("%d",&q);
    printf("\nUnit Price: ");
    scanf("%d",&u);
    mw.quantity = q;
    mw.unit = u;
    int tmw = mw.quantity*mw.unit;

    int n;
    printf("Number of People: ");
    scanf("%d",&n);

    float result = (tp+tv+tmw)/n;
    printf("Individual people will pay: %f tk\n",result);


  return 0;
} 
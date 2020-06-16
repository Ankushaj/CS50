#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float dollars;
    do{
    dollars=get_float("how much changes is owed($):\n");
    }while(dollars<=0.0);

    int cent = round(dollars*100);
    int quarter = cent / 25;
    int dime = (cent -(quarter * 25)) / 10;
    int nickel = (cent -(quarter * 25) - (dime * 10)) / 5;
    int penny = cent - (quarter * 25) - (dime * 10) - (nickel * 5);
    int coins = quarter + dime + nickel + penny;
    printf("%i\n", coins);
   

}

//***************************************************************************** 
//Workshop - #2 (Part - 2) 
//Full Name : Abcedi Ilacas 
//Student ID# : 138180211 
//Email : ailacas1@myseneca.ca 
//Section : NBB 
//Authenticity Declaration : 
//I declare this submission is the result of my own work and has not been 
//shared with any other student or 3rd party content provider.This submitted 
//piece of work is entirely of my own creation. 
//***************************************************************************** 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() 
{
    double small_price, medium_price, large_price;
    int pattys_shirts, tommys_shirts, sallys_shirts;
    double pattys_total, tommys_total, sallys_total, grand_total, tax_total, net_total;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &small_price);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medium_price);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &large_price);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", small_price);
    printf("MEDIUM : $%.2lf\n", medium_price);
    printf("LARGE  : $%.2lf\n\n", large_price);

    printf("Patty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &pattys_shirts);
    printf("\nTommy's shirt size is 'L'\n");
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tommys_shirts);
    printf("\nSally's shirt size is 'M'\n");
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &sallys_shirts);

    const int tax = 13;

    pattys_total = small_price * pattys_shirts;
    int pattys_total_cents = (int)(pattys_total * 100 + 0.5);
    int pattys_tax_cents = (pattys_total_cents * tax + 50) / 100;
    double pattys_tax = pattys_tax_cents / 100.0;
    double pattys_final = pattys_total + pattys_tax;

    tommys_total = large_price * tommys_shirts;
    int tommys_total_cents = (int)(tommys_total * 100 + 0.5);
    int tommys_tax_cents = (tommys_total_cents * tax + 50) / 100;
    double tommys_tax = tommys_tax_cents / 100.0;
    double tommys_final = tommys_total + tommys_tax;

    sallys_total = medium_price * sallys_shirts;
    int sallys_total_cents = (int)(sallys_total * 100 + 0.5);
    int sallys_tax_cents = (sallys_total_cents * tax + 50) / 100;
    double sallys_tax = sallys_tax_cents / 100.0;
    double sallys_final = sallys_total + sallys_tax;

    grand_total = pattys_total + tommys_total + sallys_total;
    int grand_total_cents = (int)(grand_total * 100 + 0.5);
    int tax_total_cents = (grand_total_cents * tax + 50) / 100;
    tax_total = tax_total_cents / 100.0;
    net_total = grand_total + tax_total;

    int total_shirts = pattys_shirts + tommys_shirts + sallys_shirts;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    S    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", small_price, pattys_shirts, pattys_total, pattys_tax, pattys_final);
    printf("Sally    M    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", medium_price, sallys_shirts, sallys_total, sallys_tax, sallys_final);
    printf("Tommy    L    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", large_price, tommys_shirts, tommys_total, tommys_tax, tommys_final);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", grand_total, tax_total, net_total);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    int balance_cents_excl = (int)(grand_total * 100 + 0.5);

    printf("%22.4lf\n", balance_cents_excl / 100.0); 

    int coins = balance_cents_excl / 200;
    balance_cents_excl %= 200;
    printf("Toonies  %3d %9.4lf\n", coins, balance_cents_excl / 100.0);
    coins = balance_cents_excl / 100;
    balance_cents_excl %= 100;
    printf("Loonies  %3d %9.4lf\n", coins, balance_cents_excl / 100.0);
    coins = balance_cents_excl / 25;
    balance_cents_excl %= 25;
    printf("Quarters  %2d %9.4lf\n", coins, balance_cents_excl / 100.0);
    coins = balance_cents_excl / 10;
    balance_cents_excl %= 10;
    printf("Dimes  %5d %9.4lf\n", coins, balance_cents_excl / 100.0);
    coins = balance_cents_excl / 5;
    balance_cents_excl %= 5;
    printf("Nickels  %3d %9.4lf\n", coins, balance_cents_excl / 100.0);
    coins = balance_cents_excl;
    printf("Pennies  %3d %9.4lf\n\n", coins, 0.0); 
    printf("Average cost/shirt: $%.4lf\n\n", grand_total / total_shirts);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    int balance_cents_incl = (int)(net_total * 100 + 0.5);
    printf("%22.4lf\n", balance_cents_incl / 100.0); 
    coins = balance_cents_incl / 200;
    balance_cents_incl %= 200;
    printf("Toonies  %3d %9.4lf\n", coins, balance_cents_incl / 100.0);
    coins = balance_cents_incl / 100;
    balance_cents_incl %= 100;
    printf("Loonies  %3d %9.4lf\n", coins, balance_cents_incl / 100.0);
    coins = balance_cents_incl / 25;
    balance_cents_incl %= 25;
    printf("Quarters  %2d %9.4lf\n", coins, balance_cents_incl / 100.0);
    coins = balance_cents_incl / 10;
    balance_cents_incl %= 10;
    printf("Dimes  %5d %9.4lf\n", coins, balance_cents_incl / 100.0);
    coins = balance_cents_incl / 5;
    balance_cents_incl %= 5;
    printf("Nickels  %3d %9.4lf\n", coins, balance_cents_incl / 100.0);
    coins = balance_cents_incl;
    printf("Pennies  %3d %9.4lf\n\n", coins, 0.0); 
    printf("Average cost/shirt: $%.4lf\n\n", net_total / total_shirts);

    return 0;

}














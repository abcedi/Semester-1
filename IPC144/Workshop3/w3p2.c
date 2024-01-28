/*/////////////////////////////////////////////////////////////////////////
//                          Workshop - #3 (P2)
//Full Name  : Abcedi Ilacas
//Student ID#: 138180211
//Email      : ailacas1@myseneca.ca
//Section    : NBB
//
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    char coffee1_type;
    char coffee2_type;
    char coffee3_type;
    int coffee1_weight;
    int coffee2_weight;
    int coffee3_weight;
    char coffee1_cream;
    char coffee2_cream;
    char coffee3_cream;
    
    char coffee_strenght;
    char cream_preference;
    int daily_servings;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1_type);
    printf("Bag weight (g): ");
    scanf(" %i", &coffee1_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1_cream);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2_type);
    printf("Bag weight (g): ");
    scanf(" %i", &coffee2_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2_cream);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3_type);
    printf("Bag weight (g): ");
    scanf(" %i", &coffee3_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3_cream);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee1_type == 'L' || coffee1_type == 'l', coffee1_type == 'M' || coffee1_type == 'm', coffee1_type == 'R' || coffee1_type == 'r', coffee1_weight, coffee1_weight / GRAMS_IN_LBS, coffee1_cream == 'Y' || coffee1_cream == 'y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee2_type == 'L' || coffee2_type == 'l', coffee2_type == 'M' || coffee2_type == 'm', coffee2_type == 'R' || coffee2_type == 'r', coffee2_weight, coffee2_weight / GRAMS_IN_LBS, coffee2_cream == 'Y' || coffee2_cream == 'y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee3_type == 'L' || coffee3_type == 'l', coffee3_type == 'M' || coffee3_type == 'm', coffee3_type == 'R' || coffee3_type == 'r', coffee3_weight, coffee3_weight / GRAMS_IN_LBS, coffee3_cream == 'Y' || coffee3_cream == 'y');

    printf("\nEnter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffee_strenght);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream_preference);
    printf("Typical number of daily servings: ");
    scanf(" %i", &daily_servings);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (coffee_strenght == coffee1_type || coffee_strenght == (coffee1_type + ('a' - 'A')) || coffee_strenght + ('a' - 'A') == coffee1_type), daily_servings >= 1 && daily_servings <= 4, ((cream_preference == 'Y' || cream_preference == 'y') && (coffee1_cream == 'Y' || coffee1_cream == 'y')) || ((cream_preference == 'N' || cream_preference == 'n') && (coffee1_cream == 'N' || coffee1_cream == 'n')));
    printf(" 2|       %d         |      %d      |   %d   |\n", (coffee_strenght == coffee2_type || coffee_strenght == (coffee2_type + ('a' - 'A')) || coffee_strenght + ('a' - 'A') == coffee2_type), daily_servings >= 5 && daily_servings <= 9, ((cream_preference == 'Y' || cream_preference == 'y') && (coffee2_cream == 'Y' || coffee2_cream == 'y')) || ((cream_preference == 'N' || cream_preference == 'n') && (coffee2_cream == 'N' || coffee2_cream == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n", (coffee_strenght == coffee3_type || coffee_strenght == (coffee3_type + ('a' - 'A')) || coffee_strenght + ('a' - 'A') == coffee3_type), daily_servings >= 10, ((cream_preference == 'Y' || cream_preference == 'y') && (coffee3_cream == 'Y' || coffee3_cream == 'y')) || ((cream_preference == 'N' || cream_preference == 'n') && (coffee3_cream == 'N' || coffee3_cream == 'n')));
    
    printf("\nEnter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffee_strenght);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream_preference);
    printf("Typical number of daily servings: ");
    scanf(" %i", &daily_servings);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (coffee_strenght == coffee1_type || coffee_strenght == (coffee1_type + ('a' - 'A')) || coffee_strenght + ('a' - 'A') == coffee1_type), daily_servings >= 1 && daily_servings <= 4, ((cream_preference == 'Y' || cream_preference == 'y') && (coffee1_cream == 'Y' || coffee1_cream == 'y')) || ((cream_preference == 'N' || cream_preference == 'n') && (coffee1_cream == 'N' || coffee1_cream == 'n')));
    printf(" 2|       %d         |      %d      |   %d   |\n", (coffee_strenght == coffee2_type || coffee_strenght == (coffee2_type + ('a' - 'A')) || coffee_strenght + ('a' - 'A') == coffee2_type), daily_servings >= 5 && daily_servings <= 9, ((cream_preference == 'Y' || cream_preference == 'y') && (coffee2_cream == 'Y' || coffee2_cream == 'y')) || ((cream_preference == 'N' || cream_preference == 'n') && (coffee2_cream == 'N' || coffee2_cream == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n", (coffee_strenght == coffee3_type || coffee_strenght == (coffee3_type + ('a' - 'A')) || coffee_strenght + ('a' - 'A') == coffee3_type), daily_servings >= 10, ((cream_preference == 'Y' || cream_preference == 'y') && (coffee3_cream == 'Y' || coffee3_cream == 'y')) || ((cream_preference == 'N' || cream_preference == 'n') && (coffee3_cream == 'N' || coffee3_cream == 'n')));
    
    printf("\nHope you found a product that suits your likes!\n");

    return 0;
}

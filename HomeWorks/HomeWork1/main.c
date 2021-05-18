//Avichai Aziz & Asaf Ben Shabat.

#include <stdio.h> 

double house_cost = 0, down_payment = 0, initial_savings = 0, saving_annual_rate = 0, mortgage_annual_rate = 0;
double fraction_house_buying = 0, monthly_rent = 0;
double initial_monthly_salary = 0, raise_fraction = 0;

double house_rent(int months) {
    int month = 0;

    while(month < months) {

        initial_savings += initial_savings * (saving_annual_rate / 12);
        initial_savings += (initial_monthly_salary * fraction_house_buying) - monthly_rent;
        month++;

        if (month % 12 == 0) { //check if past 1 year(12 months)

            initial_monthly_salary += (initial_monthly_salary * raise_fraction); 
            
        }
    }

    return initial_savings;
}


int main() {
    
    printf("Enter (House-cost, down-payment, savings, savings-annual-rate, mortgage-annual-rate, salary, fraction-saving, annual-raise, house-rent):\n");
    if (scanf("(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)",&house_cost, &down_payment, &initial_savings, &saving_annual_rate, 
    &mortgage_annual_rate, &initial_monthly_salary, &fraction_house_buying, &raise_fraction, &monthly_rent) == 9) {
    
    double current_savings = initial_savings;
    double current_monthly_salary = initial_monthly_salary;
    double own_furtune_needed = (house_cost * down_payment);
    double salary_for_houses = (current_monthly_salary *  fraction_house_buying); //included the rent and the salary of the wanted house 
    double salary_to_save = (salary_for_houses - monthly_rent); //the part of salary for the house wants to buy
    double saving_monthly_rate = (saving_annual_rate / 12);
    double mortgage_monthly_rate = (mortgage_annual_rate / 12);
    int count_months = 0;
    int count_years = 0;
    int total_months = 0;
    double house_rent_call= 0;

    while (current_savings < own_furtune_needed) {
        
        if ((salary_for_houses) >= (monthly_rent)) {
            
            while (count_months != 13) { //unequal to 13 couse we want to count from 1-12
            
                if (count_months == 12) { //count years

                    current_monthly_salary += (current_monthly_salary * raise_fraction); //add the raise to salary
                    salary_for_houses = (current_monthly_salary *  fraction_house_buying); //the money saved for the rent house and the wish house
                    ++count_years; //add 1 each year
                    count_months = 0; //equate to zero after 12 month (1 year)
                }
                
                current_savings += (current_savings * saving_monthly_rate); //add the monthly rate to the savings
                salary_to_save = (salary_for_houses - monthly_rent); //the part of salary for the wanted house each month
                current_savings += salary_to_save; //add the saved salary for the house, to the savings every month            
                
                ++count_months;

                if (current_savings > own_furtune_needed) { //check if we have enough money to pay the first down payment
                    
                    total_months = ((count_years * 12) + count_months);
                    printf("After %d years and %d months you will have enough money for the down payment\n", count_years,
                    count_months);

                    break;
                }
                
            }
        }

        else 
        {
            printf("Error: housing portion of the salary is insufficient to cover rent\n");
            
            return 2;
        }
    }

    double house_payment = (house_cost - current_savings); //the rest payment for the house
    current_savings = 0; //after the payment for the bank        
    double refund_money = (current_monthly_salary * fraction_house_buying); //the const refund money for the house each month
    double rate_on_mortgage = 0;

    if (refund_money > (house_payment * mortgage_monthly_rate)) {
        
        while (house_payment > 0) {
            
            total_months++; //add 1 after one month
            
            if(total_months % 12 == 0){
            
                current_monthly_salary += (current_monthly_salary * raise_fraction);
            }

            rate_on_mortgage += (house_payment * mortgage_monthly_rate); //the rate on the mortgage update each month
            house_payment += (house_payment * mortgage_monthly_rate); //update after each month to new one
            salary_for_houses = (current_monthly_salary * fraction_house_buying); //the salary allocated for housing 
            house_payment -= refund_money; //subtract the const money each month from the house payment left
            current_savings += (current_savings * saving_monthly_rate); //update after each month
            current_savings += (salary_for_houses-refund_money); //add the difference between the money for houses and const refund money
                        
            if(current_savings > house_payment){
            
                current_savings -= house_payment;
                house_payment = 0;
            }

        }
     


    }
    

    else
    {
        printf("Error: The monthly repayment amount is lower than the amount to be paid as a monthly repayment\n");

        return 3;
    }

    house_rent_call =  house_rent(total_months);
    printf("After %d years and %d months you will cover the cost of the house\n", (total_months/12),(total_months%12));
    printf("Actual payment for the house: %.1lf\n", (rate_on_mortgage + house_cost));
    printf("House worth is %.1lf\n",house_cost);
    printf("Alternatively, if you rent you will end up with %.1lf\n", house_rent_call);

    }   


    else
    {
        printf("Error,you must enter 9 values\n");
        return 1;
    }
        
    return 0;
}

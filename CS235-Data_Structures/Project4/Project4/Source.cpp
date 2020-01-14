/*
Caleb Hill, Section 2, calebleehill1993@gmail.com

Purpose:  To help individuals determine if solar power is worth the investment.

Input:
Price of solar installation
Buy or finance
interest rate on financed
numbers of years fincancing
first year of electricity bill
Type of electiricity company
opportunity cost in %

Output:
20 years of net growth on the investment
Tells if and when the investment becomes positive

TEST CASES

TEST CASE 1

input: 
Initial purchase price: 50000
Is it purchased(P) or financed(F)? (P or F) f
Interest rate as a %: 3
Number of years to finance: 13
First-year electricity bill: 1500
Is your electricity from a municipality(M) or a shareholder-owned company(C)? (M or C) c
Opportunity cost as a %: 4

expected output:
1       -$25671.28
2       -$24292.63
3       -$22921.64
4       -$21555.24
5       -$20190.01
6       -$18822.15
7       -$17447.41
8       -$16061.10
9       -$14658.03
10      -$13232.48
11      -$11778.13
12      -$10288.04
13      -$8754.58
14      -$7058.43
15      -$5186.00
16      -$3122.63
17      -$852.57
18      $1641.13
19      $4376.74
20      $7373.86

There were net savings beginning in year 18.

actual output:
1       -$25671.28
2       -$24292.63
3       -$22921.64
4       -$21555.24
5       -$20190.01
6       -$18822.15
7       -$17447.41
8       -$16061.10
9       -$14658.03
10      -$13232.48
11      -$11778.13
12      -$10288.04
13      -$8754.58
14      -$7058.43
15      -$5186.00
16      -$3122.63
17      -$852.57
18      $1641.13
19      $4376.74
20      $7373.86

There were net savings beginning in year 18.


TEST CASE 2

input:
Initial purchase price: 32000
Is it purchased(P) or financed(F)? (P or F) p
First-year electricity bill: 3500
Is your electricity from a municipality(M) or a shareholder-owned company(C)? (M or C) m
Opportunity cost as a %: 8

expected output:
1       -$9532.00
2       -$7689.56
3       -$5879.97
4       -$4111.28
5       -$2392.32
6       -$732.80
7       $856.60
8       $2364.20
9       $3777.18
10      $5081.51
11      $6261.85
12      $7301.43
13      $8181.94
14      $8883.38
15      $9383.95
16      $9659.85
17      $9685.19
18      $9431.73
19      $8868.74
20      $7962.78

There were net savings beginning in year 18.

actual output:
1       -$9532.00
2       -$7689.56
3       -$5879.97
4       -$4111.28
5       -$2392.32
6       -$732.80
7       $856.60
8       $2364.20
9       $3777.18
10      $5081.51
11      $6261.85
12      $7301.43
13      $8181.94
14      $8883.38
15      $9383.95
16      $9659.85
17      $9685.19
18      $9431.73
19      $8868.74
20      $7962.78

There were net savings beginning in year 18.


TEST CASE 3

input:
Initial purchase price: 10000
Is it purchased(P) or financed(F)? (P or F) f
Interest rate as a %: 8
Number of years to finance: 5
First-year electricity bill: 1500
Is your electricity from a municipality(M) or a shareholder-owned company(C)? (M or C) c
Opportunity cost as a %: 6

expected output:
1       -$1836.55
2       -$386.33
3       $1091.81
4       $2600.68
5       $4143.32
6       $5798.18
7       $7573.37
8       $9477.59
9       $11520.14
10      $13711.02
11      $16060.92
12      $18581.33
13      $21284.54
14      $24183.72
15      $27293.00
16      $30627.52
17      $34203.49
18      $38038.30
19      $42150.59
20      $46560.31

There were net savings beginning in year 18.

actual output:
1       -$1836.55
2       -$386.33
3       $1091.81
4       $2600.68
5       $4143.32
6       $5798.18
7       $7573.37
8       $9477.59
9       $11520.14
10      $13711.02
11      $16060.92
12      $18581.33
13      $21284.54
14      $24183.72
15      $27293.00
16      $30627.52
17      $34203.49
18      $38038.30
19      $42150.59
20      $46560.31

There were net savings beginning in year 18.

*/



#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	// VARIABLES
	int net_savings_year = 0;
	int year_countdown = 0;
	int current_year = 1;
	int try_another = 1;
	int number_of_payments = 0;
	double initial_purchase_price = 0;
	double interest_rate = 0; // PERCENTAGE
	double anticipated_first_year_payment = 0;
	double opportunity_cost_percentage = 0; // PERCENTAGE
	double annual_utility_payment = 0;
	double annual_solar_payment = 0;
	double cumulative_annual_solar_payments = 0;
	double opportunity_cost = 0;
	double cumulative_opportunity_cost = 0;
	double net_annual_benefit = 0;
	double cumulative_net_annual_benefit = 0;
	double increased_home_value = 0;
	double cumulative_gain_or_loss = 0;
	double initial_cost = 0;
	double cumulative_annual_utility_payment = 0;
	double remaining_indebtedness = 0;
	double positive_gain = 0;

	// CONSTANTS
	const double FEDERAL_TAX_CREDIT = .30; // PERCENTAGE
	const double STATE_TAX_CREDIT = 2000;
	const double ANNUAL_RATE_INCREASE_ME = .03; // PERCENTAGE
	const double ANNUAL_RATE_INCREASE_SOE = .07; // PERCENTAGE
	const double HOME_VALUE_INCREASE = .30; // PERCENTAGE OF INITIAL COST OF THE HOE SOLAR SYSTEM
	const double MAX_HOME_VALUE_INCREASE = 9000;
	const double NUMBER_OF_YEARS = 20;
	const double ANNUAL_INCREASE_PCP = .03; // PERCENTAGE
	const double ANNUAL_INCREASE_RMP = .07; // PERCENTAGE
	const int run_again = 1;

	// STRINGS
	string initial_purchase_price_string = "";
	string anticipated_first_year_payment_string = "";
	string purchase_o_or_f = "";
	string municipality_or_sharesholder = "";

	while (try_another == run_again)
	{
		cout << "Initial purchase price: ";

		cin >> initial_purchase_price_string;

		cout << "Is it purchased(P) or financed(F)? (P or F) ";

		cin >> purchase_o_or_f;

		if (purchase_o_or_f == "F" || purchase_o_or_f == "f")
		{
			cout << "Interest rate as a %: ";

			cin >> interest_rate;

			cout << "Number of years to finance: ";

			cin >> number_of_payments;
		}
		cout << "First-year electricity bill: ";

		cin >> anticipated_first_year_payment_string;

		cout << "Is your electricity from a municipality(M) or a shareholder-owned company(C)? (M or C) ";

		cin >> municipality_or_sharesholder;

		cout << "Opportunity cost as a %: ";

		cin >> opportunity_cost_percentage;

		cout << endl;

		//SETTING UP MATH

		if (initial_purchase_price_string.substr(0, 1) == "$")
		{
			initial_purchase_price_string = initial_purchase_price_string.substr(1);
		}
		initial_purchase_price = stod(initial_purchase_price_string);

		if (anticipated_first_year_payment_string.substr(0, 1) == "$")
		{
			anticipated_first_year_payment_string = anticipated_first_year_payment_string.substr(1);
		}
		anticipated_first_year_payment = stod(anticipated_first_year_payment_string);

		initial_cost = initial_purchase_price;

		initial_purchase_price = initial_purchase_price - initial_purchase_price * FEDERAL_TAX_CREDIT
			- STATE_TAX_CREDIT;

		interest_rate = interest_rate / 100;

		annual_solar_payment = (interest_rate * initial_purchase_price)
			/ (1 - pow((1 + interest_rate), - number_of_payments));

		opportunity_cost_percentage = opportunity_cost_percentage / 100;

		annual_utility_payment = anticipated_first_year_payment;

		increased_home_value = initial_cost * HOME_VALUE_INCREASE;

		if (increased_home_value > 9000)
		{
			increased_home_value = 9000;
		}
		cout << endl << "Year\tCumulative Gain/loss" << fixed << setprecision(2) << endl;

		for (year_countdown = NUMBER_OF_YEARS; year_countdown > 0; year_countdown--)
		{
			if (purchase_o_or_f == "F" || purchase_o_or_f == "f")
			{
				if (current_year <= number_of_payments)
				{
					cumulative_annual_solar_payments = current_year * annual_solar_payment;
				}
			}
			else
			{
				cumulative_annual_solar_payments = initial_purchase_price;
			}
			cumulative_opportunity_cost = cumulative_opportunity_cost + opportunity_cost;

			opportunity_cost = (cumulative_annual_solar_payments + cumulative_opportunity_cost) 
				* opportunity_cost_percentage;

			cumulative_annual_utility_payment = annual_utility_payment + cumulative_annual_utility_payment;

			if ((purchase_o_or_f == "F" || purchase_o_or_f == "f") && current_year <= number_of_payments)
			{
				net_annual_benefit = annual_utility_payment - annual_solar_payment - opportunity_cost;
			}
			else
			{
				if (current_year == 1)
				{
					net_annual_benefit = annual_utility_payment - initial_purchase_price - opportunity_cost;
				}
				else
				{
					net_annual_benefit = annual_utility_payment - opportunity_cost;
				}
			}
			cumulative_net_annual_benefit = net_annual_benefit + cumulative_net_annual_benefit;

			if ((purchase_o_or_f == "F" || purchase_o_or_f == "f") && current_year <= number_of_payments)
			{
				remaining_indebtedness = annual_solar_payment * (number_of_payments - current_year);

				cumulative_gain_or_loss = increased_home_value - remaining_indebtedness 
					+ cumulative_net_annual_benefit;
			}
			else
			{
				cumulative_gain_or_loss = increased_home_value + cumulative_net_annual_benefit;
			}
			if (cumulative_gain_or_loss < 0)
			{
				positive_gain = cumulative_gain_or_loss * -1;

				cout << current_year << "\t" << "-$" << positive_gain << endl;
			}
			else
			{
				if (cumulative_gain_or_loss > 0 && net_savings_year < 1)
				{
					net_savings_year = current_year;
				}
				cout << current_year << "\t" << "$" << cumulative_gain_or_loss << endl;
			}
			if (municipality_or_sharesholder == "M" || municipality_or_sharesholder == "m")
			{
				annual_utility_payment = annual_utility_payment * (1 + ANNUAL_INCREASE_PCP);
			}
			else
			{
				annual_utility_payment = annual_utility_payment * (1 + ANNUAL_INCREASE_RMP);
			}
			current_year++;
		}
		if (net_savings_year > 0)
		{
			cout << endl << "There were net savings beginning in year " << net_savings_year << "." << endl << endl;
		}
		else
		{
			cout << endl << "It will not be profitable during the first 20 years." << endl << endl;
		}
		cout << "Try another? (1 to continue, 0 to exit) ";

		cin >> try_another;

		cout << endl;
		  
		// RESET NUMBERS

		current_year = 1;

		cumulative_annual_solar_payments = 0;

		cumulative_gain_or_loss = 0;

		cumulative_net_annual_benefit = 0;

		cumulative_opportunity_cost = 0;

		opportunity_cost = 0;

		net_annual_benefit = 0;
	}
	return 0;
}
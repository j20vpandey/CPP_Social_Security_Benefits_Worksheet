// PortfolioProject1 : Social Security Benefits Worksheet.
// By Vishnu Pandey
// Date: 12-06-2018

#include <iostream>
#include <string>
using namespace std;

//function prototype
double input_f1040(string);
void get_income(double []);
char marid_status();
double smaller(double, double);
void process_f1040(double[], double[]);
void output_f1040(double []);

int main()
{
	double input[14];
	double calculate[19];

	get_income(input);
	process_f1040(input, calculate);
	output_f1040(calculate);

	system("pause");
	return 0;
}

//valid input function
double input_f1040(string str)
{
	bool lossCheck = false;
	double v(0);

	if (str == "business income or (loss)." || str == "capital gain or (loss).")
		lossCheck = true;

	do
	{
		cout << "Enter " << str << endl;
		cin >> v;
	} while (v < 0 && lossCheck != true);

	return v;
}

//input function
void get_income(double inp[])
{
	double f1040_07(input_f1040("wages, salaries & tips."));
	double f1040_8a(input_f1040("taxable interest."));
	double f1040_8b(input_f1040("tax-exempt interest."));
	double f1040_9a(input_f1040("ordinary dividends."));
	double f1040_9b(input_f1040("qualified dividends."));
	double f1040_11(input_f1040("alimony received."));
	double f1040_12(input_f1040("business income or (loss)."));
	double f1040_13(input_f1040("capital gain or (loss)."));
	double f1040_15(input_f1040("IRA distributions."));
	double f1040_16(input_f1040("pensions and annuities."));
	double f1040_17(input_f1040("rental real estate."));
	double f1040_19(input_f1040("unemployment compensation."));
	double f1040_20a(input_f1040("social security benefits."));
	double f1040_36(input_f1040("total adjustments"));

	//data store
	inp[0] = f1040_07;
	inp[1] = f1040_8a;
	inp[2] = f1040_8b;
	inp[3] = f1040_9a;
	inp[4] = f1040_9b;
	inp[5] = f1040_11;
	inp[6] = f1040_12;
	inp[7] = f1040_13;
	inp[8] = f1040_15;
	inp[9] = f1040_16;
	inp[10] = f1040_17;
	inp[11] = f1040_19;
	inp[12] = f1040_20a;
	inp[13] = f1040_36;
}
//check marrid status
char marid_status() {
	char stat(' ');
	do {
		cout << "If you are marrid, enter 'M'. Single, enter 'S'." << endl;
		cin >> stat;
	} while (stat != 'M' && stat != 'm' && stat != 'S' && stat != 's');
	
	return stat;
}
double smaller(double dou1, double dou2)
{
	double small;
	if ((dou1 - dou2) < 0) {
		small = dou1;
	}
	else
	{
		small = dou2;
	}
	return small;
}

//Process function
void process_f1040(double inp[], double pro[]) {
	char marriedSt(marid_status());

	pro[0] = inp[12];
	pro[1] = inp[12] / 2;
	pro[2] = inp[0] + inp[1] + inp[3] + inp[5] +  inp[6] +  inp[7] + inp[8] +  inp[9] +   inp[10] + inp[11] + inp[12];
	pro[3] = inp[2];
	pro[4] = pro[1] + pro[2] + pro[3];
	pro[5] = inp[13];

	//condition check for pro[6]
	if (pro[5] >= pro[4])
	{
		cout << "your social security benefits are taxable. Enter 0 on taxable amount.\n" << endl;
		main();
	}
	else
	{
		pro[6] = pro[4] - pro[5];
	}

	//condition check for pro[7] & pro[9]
	if (marriedSt == 'm' || marriedSt == 'M')
	{
		pro[7] = 32000;
		pro[9] = 12000;
	}
	else
	{
		pro[7] = 25000;
		pro[9] = 9000;
	}

	//condition check for pro[8]
	if (pro[7] >= pro[6])
	{
		cout << "your social security benefits are taxable. Enter 0 on taxable amount\n" << endl;
		main();
	}
	else
	{
		pro[8] = pro[6] - pro[7];
	}
	
	//condition check for pro[10]
	pro[10] = pro[8] - pro[9];
	if (pro[10] < 0)
	{
		pro[10] = 0;
	}

	pro[11] = smaller(pro[9], pro[8]);
	pro[12] = pro[11] / 2;
	pro[13] = smaller(pro[1], pro[12]);
	pro[14] = pro[10] * 0.85;
	pro[15] = pro[13] + pro[14];
	pro[16] = pro[0] * 0.85;
	pro[17] = smaller(pro[15],pro[16]);
	
}
//Output function
void output_f1040(double out[]) {

	cout << "\n\t  Social Security Benefits Worksheet\n\t  ----------------------------------" << endl;
	cout << "1. Enter the amount of your Social Security Benefits (line 20a)   1. " << out[0] << endl;
	cout << "2. Enter one-half of line 1.                                      2. " << out[1] << endl;
	cout << "3. Combine the amounts from Form 1040, lines 7, 8a, 9a, 11" << endl;
	cout << "   through 13, 15 through 17, and 19, 20a.                        3. " << out[2] << endl;
	cout << "4. Enter the amount, if any, from Form 1040, line 8b.             4. " << out[3] << endl;
	cout << "5. Combine lines 2, 3, and 4.                                     5. " << out[4] << endl;
	cout << "6. Enter the total of the amounts from Form 1040, lines 23" << endl;
	cout << "   through 32.                                                    6. " << out[5] << endl;
	cout << "7. Is the amount on line 6 less than the amount on line 5?" << endl;
	cout << "   If No, None of your social security benefits are taxable."<< endl;
	cout << "   Enter 0 on Form 1040, line 20b." << endl;
	cout << "   If Yes, Subtract line 6 from line 5.                           7. " << out[6] << endl;
	cout << "8. If you are married, enter  $32,000. Single, enter $25,000      8. " << out[7] << endl;
	cout << "9. Is the amount on line 8 less than the amount on line 7?" << endl;
	cout << "   If No, None of your social security benefits are taxable." << endl;
	cout << "	Enter 0 on Form 1040, line 20b." << endl;
	cout << "   If Yes, Subtract line 8 from line 7.                           9.  " << out[8] << endl;
	cout << "10. Enter $12,000 if married. Enter $9,000 if single.            10. " << out[9] << endl;
	cout << "11. Subtract line 10 from line 9. If zero or less, enter 0.      11. " << out[10] << endl;
	cout << "12. Enter the smaller of line 9 or line 10.                      12. " << out[11] << endl;
	cout << "13. Enter one-half of line 12.                                   13. " << out[12] << endl;
	cout << "14. Enter the smaller of line 2 or line 13.                      14. " << out[13] << endl;
	cout << "15. Multiply line 11 by 85% (0.85). If line 11 is zero, enter 0  15. " << out[14] << endl;
	cout << "16. Add lines 14 and 15.                                         16. " << out[15] << endl;
	cout << "17. Multiply line 1 by 85% (0.85).                               17. " << out[16] << endl;
	cout << "18. Taxable social security benefits." << endl;
	cout << "    Enter the smaller of line 16 or line 17." << endl;
	cout << "    Also enter this amount on Form 1040, line 20b.               18. " << out[17] << endl;
}
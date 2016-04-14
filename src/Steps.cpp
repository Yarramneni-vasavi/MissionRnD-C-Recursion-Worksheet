/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

int Fact(int N);
int Steps_Count(int s, int two, int res);

int get_steps(int s)
{
	if (s == 0)
		return 0;
	return Steps_Count(s, 0, 0);
}

int Steps_Count(int s, int two, int res)
{
	//'two' calculates no. of times two steps taken
	int count = 0;	//count is to store possible combinations with 'one' & 'two' steps
	int one = s - two;	//'one' calculates no. of times single step taken

	if (one < 0)
		return count;

	count = Fact(s) / (Fact(one) * Fact(two));//calculates no. of combination possible  with 'one' & 'two' steps
	two++;
	res = count + Steps_Count(s - 1, two, res);
	return res;
}

int Fact(int N)
{
	if (N == 0)
		return 1;
	else
		return N*Fact(N - 1);
}
#include <stdio.h>		/* printf, scanf */
#include <stdlib.h>		/* system("pause") */
#include <math.h>		/* fabs */

// Error domain for Newton-Raphson algorithem
#define EPSILON 0.000001

void Ex1();
void Ex1_Implementation( int*, unsigned int );
void input_array_dyn( int**, unsigned int );
void print_array( int *, unsigned int );
void Ex2();
int Ex2_Implementation( int, int );
void Ex3();
void Ex3_Implementation( unsigned int );
void print_space( unsigned int, unsigned int );
void print_pascal_line( unsigned int );
void Ex4();
void betrothed_numbers( unsigned int );
int sum_divisors_2( int );
int round( double );
void Ex5();
double Newton_Raphson( double, double );

void main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf( "Run menu once or cyclycally?\n(Once - enter 0, cyclically - enter other number) " );
	if( scanf( "%d", &all_Ex_in_loop ) == 1 )
		do
		{
			for( i = 1; i <= 5; i++ )
				printf( "Ex%d--->%d\n", i, i );
			printf( "EXIT-->0\n" );
			do
			{
				select = 0;
				printf( "Please select 0-5: " );
				scanf( "%d", &select );
			} while( ( select < 0 ) || ( select > 5 ) );
			switch( select )
			{
				case 1:
					Ex1();
					break;
				case 2:
					Ex2();
					break;
				case 3:
					Ex3();
					break;
				case 4:
					Ex4();
					break;
				case 5:
					Ex5();
					break;
			}
		} while( all_Ex_in_loop && select );
	system( "pause" );
}

void Ex1()
{
	/*
	define pointer to array of int and size.
	gets from user natural number as size of the array.
	gets from user array elements.
	executes ex1 implementation function with given array and size.
	prints the results.
	frees the dinamicly allocated array.
	*/
	int *list, size;
	do
	{
		size = 0;
		printf( "Enter size of array: " );
		scanf( "%d", &size );
		getchar();
	} while( size <= 0 );
	input_array_dyn( &list, ( unsigned int )size );
	Ex1_Implementation( list, size );
	printf( "The new array is:\n" );
	print_array( list, size );
	free( list );
}
void Ex1_Implementation( int *list, unsigned int size )
{
	// set pointer 'element'
	// and initialize it to the second position in the array.
	int *element = list + 1;
	// if the array contains more than one element compute.
	if( size > 1 )
		for(; element < list + size; element++ )
			// starting from the second element add to current element the value of the previous element.
			*element += *( element - 1 );
}
void input_array_dyn( int **pa, unsigned int size )
{
	/*
	allocates dynamic array with given size
	with input from user.
	updeting the pointer pa to new array.
	*/
	unsigned int index;
	*pa = ( int * )malloc( size * sizeof( int ) );
	if( pa )
	{
		printf( "Enter the array of length %u:\n", size );
		for( index = 0; index < size; index++ )
		{
			do
			{
				printf( "Enter element (%u of %u): ", index + 1, size );
			} while( ( ( scanf( "%d", (*pa) + index ) ) != 1 ) && getchar() );
		}
	}
}
void print_array( int *list, unsigned int size )
{
	// helper function to print array of type int.
	unsigned int index;
	for( index = 0; index < size; index++ )
		printf( "%d ", *( list + index ) );
	printf( "\n" );
}
void Ex2()
{
	// gets a and b while a > b, executes ex2 implementation and prints the result.
	int a, b, result;
	do
	{
		printf( "Enter two number a, b while a > b: " );
	} while( ( scanf( "%d%d", &a, &b ) != 2 ) && getchar() || ( a > b ) );
	result = Ex2_Implementation( a, b );
	printf( "The result is: %d.\n", result );
}
int Ex2_Implementation( int a, int b )
{
	/*
	gets a, b: a>b to calculate lower and upper limit of two lines.
	initialize summation of each line valueA/B.
	interactivly gets elemetns from user until -1 is entered.
	on each element input the value is checked with both lines limits is matched
	the value added to coressponded summation.
	returns the difference between lines summations.
	*/
	int valueA = 0, valueB = 0;
	int left_lim_a = ( a + b ) / 2, right_lim_b = ( a + b ) / 2;
	int right_lim_a = b, left_lim_b = a;
	int input;
	printf( "Enter integer series (-1 to end):\n" );
	do
	{
		printf( "Enter integer: ");
	} while( ( scanf( "%d", &input ) != 1 ) && getchar() );
	while( input != -1 )
	{
		if( ( input > left_lim_a ) && ( input < right_lim_a ) )
			valueA += input;
		if( ( input > left_lim_b ) && ( input < right_lim_b ) )
			valueB += input;
		do
		{
			printf( "Enter integer: ");
		} while( ( scanf( "%d", &input ) != 1 ) && getchar() );
	}
	return valueA - valueB;
}
void Ex3()
{
	// gets 0 or natural number and executes ex3 implementation.
	int pascal_level;
	printf( "Enter n-th level of pascal triangle:\n" );
	do
	{
		printf( "Enter netural number: " );
	} while( ( scanf( "%d", &pascal_level ) != 1 ) && getchar() || ( pascal_level < 0 ) );
	Ex3_Implementation( ( unsigned int )pascal_level );
}
void Ex3_Implementation( unsigned int pascal_level )
{
	// gets pascal level and executes from 0 up to pascal level
	// print spaces and print pascal line.
	unsigned int line;
	for( line = 0; line <= pascal_level; line++ )
	{
		print_space( line, pascal_level );
		print_pascal_line( line );
	}
}
void print_space( unsigned int line, unsigned int pascal_level )
{
	// print spaces for pascal line 
	for(; line < pascal_level; line++ )
		printf( "\t" );
}
void print_pascal_line( unsigned int pascal_line )
{
	/*
	gets pascal line number to print.
	calculates each element in line based on the next algorithem
	first element = 1
	denominator initialised with pascal line.
	numirator initialised with 1.
	next element = value of previous element times num divided by den
	on each step den increases by 1 while num decreases by 1.
	until den = 1 and num = given pascal line.
	print the element with double tab spaces at the end of the line brake line.
	*/
	unsigned int previous, numerator, denominator;
	printf( "1" );
	if( pascal_line == 1 )
		printf( "\t\t1");
	else
		for( denominator = previous = 1, numerator = pascal_line; ( numerator >= 1 ) && ( denominator <= pascal_line ); numerator--, denominator++ )
		{
			previous = previous * numerator / denominator;
			printf( "\t\t%u", previous);
		}
	printf( "\n" );
}
void Ex4()
{
	// gets positive number and executes betrothed numbers function with given upper limit.
	int upper_limit;
	printf( "Enter upper limit to search betrothed numbers:\n" );
	do
	{
		printf( "Enter positive number: ");
	} while( ( scanf( "%d", &upper_limit ) != 1 ) && getchar() || ( upper_limit <= 0 ) );
	betrothed_numbers( ( unsigned int )upper_limit );
}
void betrothed_numbers( unsigned int upper_limit )
{
	/*
	gets upper limit to seek up to for betrothed numbers.
	lower limit initialized to 48 first known betrothed number.
	sum_of_divisors holds the sum of all divisors of current number to seek.
	betrothed_pair holdes pairs suspacted as betrothed number.
	count for visualisation of the output, number of pairs found.
	if pair found and current number is lower than its pair print the pair to eliminate duplicate paris.
	if count is 0 no pairs found up to given limit, prints coresponded message.
	*/
	unsigned int lower_limit, sum_of_divisors, betrothed_pair, count = 0;
	for( lower_limit = 48; lower_limit <= upper_limit; lower_limit++ )
	{
		sum_of_divisors = sum_divisors_2( lower_limit );
		betrothed_pair = sum_of_divisors - lower_limit - 1;
		if( ( lower_limit < betrothed_pair ) && ( sum_divisors_2( betrothed_pair ) == sum_of_divisors ) )
			printf( "%u. ( %4u, %4u )\n", ++count, lower_limit, betrothed_pair );
	}
	if( !count )
		printf( "No betrothed numbers found in given range.\n" );
}
int sum_divisors_2( int num )
{
	// helper function to sum all divisors on num.
	int index, limit, sq, sum = 1;
	double s;
	if( num == 1 )
		return 1;
	s = sqrt( num );
	sq = round( s );
	if( num == sq * sq )
	{
		sum += sq;
		limit = sq - 1;
	}
	else
		limit = ( int )( s );
	for( index = 2; index <= limit; index++ )
		if( !( num % index ) )
			sum += index + num / index;
	return sum + num;
}
int round( double num )
{
	// helper function to round double to int.
	return num >= 0 ? ( int )( num + 0.5 ): ( int )( num - 0.5 );
}
void Ex5()
{
	// gets n, real number from user, prints the execution of Newton-Raphson alg' (square root of n).
	// x should be initialized to 1 on first run.
	double n;
	do
	{
		printf( "Enter number: " );
	} while( ( scanf( "%lf", &n ) != 1 ) && getchar() );
	printf( "%g\n", Newton_Raphson( 1, n ) );
}
double Newton_Raphson( double x, double n )
{
	// x is the previous element, n is the number to seek square root for.
	// calculates the next element by Newton-Raphson alg'
	// if difference of previous number and current in absolute value is in given error range defined by EPSILON.
	// return the current element (x_m). otherwise recursivly call with curren element.
	double x_m;
	x_m = x - ( ( x * x ) - n ) / ( 2 * x );
	if( fabs( x_m - x ) <= EPSILON )
		return x_m;
	return Newton_Raphson( x_m, n );
}
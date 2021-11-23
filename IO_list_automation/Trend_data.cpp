#include "config.h"
#include "Trend_data.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "MainWindow.h"
#include "config.h"
#include "Global_Functions.h"


#include <complex>
#include <valarray>

const double PI = 3.141592653589793238460;


using namespace std;
using namespace IOlistautomation;

struct Trend_str Trend_data;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

// get data from memory to wstring
std::wstring Trend_data_get_data_switch(int iCol, int index)
{
	switch (iCol)
	{
	case 0:	return Trend_data.data[index].Time;
		break;
	case 1:	return Trend_data.data[index].PV;
		break;
	case 2:	return Trend_data.data[index].OUTs;
		break;
	case 3:	return Trend_data.data[index].Disturb;
		break;
	case 4:	return Trend_data.data[index].PV_pol;
		break;
	case 5:	return Trend_data.data[index].Out_pol;
		break;
	default:return LPWSTR(L"");
		break;
	}
}
// put data from wstring to memory
void Trend_data_put_data_switch(int iCol, int index, wstring cell_text)
{
	switch (iCol)
	{
	case 0:	Trend_data.data[index].Time = cell_text;
		break;
	case 1:	Trend_data.data[index].PV = cell_text;
		break;
	case 2:	Trend_data.data[index].OUTs = cell_text;
		break;
	case 3:	Trend_data.data[index].Disturb = cell_text;
		break;
	case 4:	Trend_data.data[index].PV_pol = cell_text;
		break;
	case 5:	Trend_data.data[index].Out_pol = cell_text;
		break;
	}
}


//check if there is data in any variable
int Trend_data_valid_row_check(int row)
{
	if (Trend_data.data[row].PV.empty() == 0)
	{
		return 1;
	}
	if (Trend_data.data[row].OUTs.empty() == 0)
	{
		return 1;
	}
	if (Trend_data.data[row].Time.empty() == 0)
	{
		return 1;
	}

	return 0;
}


/*Function to evaluate Li(x)*/

double Li(int i, int n, double x[], double X, int step) {
	int j;
	double prod = 1;
	double prod1 = 1;
	double a = 1;
	double b = 1;
	for (j = 0; j <= n; j+= step) {
		if (j != i)
		{
			a = x[1];
			b = x[j];
			prod1 = prod * (X - x[j]) / (x[i] - x[j]);
			if (isnan(prod1) || isinf(prod1))
			{
				int c = 0;
			}
			prod = prod1;
		}
		
	}
	return prod;
}

/*Function to evaluate Pn(x) where Pn is the Lagrange interpolating polynomial of degree n*/
double Pn(int n, double x[], double y[], double X, int step) {
	double sum = 0;
	int i;
	for (i = 0; i <= n; i+= step) {
		sum = sum + Li(i, n, x, X, step)*y[i];
	}
	return sum;
}

double x_pol[Max_Trend_data] = {0};

double Li_poly(int n, double x[], double y[], int step) {

	int max_poly = 1;
	double divider = 0;

	double a = 1;
	double b = 1;
	for (int i = 0; i <= n; i += step)
	{
		max_poly = 1;
		double tmp_x[Max_Trend_data] = { 0 };
		double tmp_x1[Max_Trend_data] = { 0 };
		double tmp_x2[Max_Trend_data] = { 0 };
		
		for (int j = 0; j <= n; j += step)
		{
			if (j != i)
			{
				divider = (x[i] - x[j]);
				a = 1 / divider;
				b = -x[j] / divider;

				if (max_poly == 1)
				{
					tmp_x1[1] = a;
					tmp_x2[0] =b;
				}
				else
				{
					for (int z = max_poly; z >= 0; z--)
					{
						tmp_x1[z + 1] = tmp_x[z] * a;
						tmp_x2[z] = tmp_x[z] * b;
					}
				}
				max_poly++;
				for (int z = 0; z <= max_poly; z++)
				{
					tmp_x[z] = tmp_x1[z] + tmp_x2[z];
					tmp_x1[z] = 0;
					tmp_x2[z] = 0;
				}
				int zz = 0;
			}
		}
		for (int z = 0; z <= max_poly; z++)
		{
			tmp_x[z] = tmp_x[z] * y[i];
			x_pol[z] += tmp_x[z];
		}

	}
	return 0;
}

// Cooley-Tukey FFT (in-place, breadth-first, decimation-in-frequency)
// Better optimized but less intuitive
// !!! Warning : in some cases this code make result different from not optimased version above (need to fix bug)
// The bug is now fixed @2017/05/30 
void fft_calc(CArray &x)
{
	// DFT
	unsigned int N = x.size(), k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
	Complex phiT = Complex(cos(thetaT), -sin(thetaT)), T;
	while (k > 1)
	{
		n = k;
		k >>= 1;
		phiT = phiT * phiT;
		T = 1.0L;
		for (unsigned int l = 0; l < k; l++)
		{
			for (unsigned int a = l; a < N; a += n)
			{
				unsigned int b = a + k;
				Complex t = x[a] - x[b];
				x[a] += x[b];
				x[b] = t * T;
			}
			T *= phiT;
		}
	}
	// Decimate
	unsigned int m = (unsigned int)log2(N);
	for (unsigned int a = 0; a < N; a++)
	{
		unsigned int b = a;
		// Reverse bits
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		if (b > a)
		{
			Complex t = x[a];
			x[a] = x[b];
			x[b] = t;
		}
	}
	//// Normalize (This section make it not working correctly)
	//Complex f = 1.0 / sqrt(N);
	//for (unsigned int i = 0; i < N; i++)
	//	x[i] *= f;
}

void fft(CArray& x)
{
	const size_t N = x.size();
	if (N <= 1) return;

	// divide
	CArray even = x[std::slice(0, N / 2, 2)];
	CArray  odd = x[std::slice(1, N / 2, 2)];

	// conquer
	fft_calc(even);
	fft_calc(odd);

	// combine
	for (size_t k = 0; k < N / 2; ++k)
	{
		Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
		x[k] = even[k] + t;
		x[k + N / 2] = even[k] - t;
	}
}



// inverse fft (in-place)
void ifft(CArray& x)
{
	// conjugate the complex numbers
	x = x.apply(std::conj);

	// forward fft
	fft(x);

	// conjugate the complex numbers again
	x = x.apply(std::conj);

	// scale the numbers
	x /= x.size();
}
/*
Output:

fft
(4,0)
(1,-2.41421)
(0,0)
(1,-0.414214)
(0,0)
(1,0.414214)
(0,0)
(1,2.41421)

ifft
(1,-0)
(1,-5.55112e-017)
(1,2.4895e-017)
(1,-5.55112e-017)
(5.55112e-017,0)
(5.55112e-017,5.55112e-017)
(0,-2.4895e-017)
(5.55112e-017,5.55112e-017)
*/
int fourie_calc()
{
	const Complex test[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
	CArray data(test, 8);

	// forward fft
	fft(data);

	// inverse fft
	ifft(data);

	return 0;
}


void Global_Polynom_calc()
{
	fourie_calc();
	int n;  // n/step is the degree
	int step = 100;
	n = 2000;   // optimal degree is <100, later a lot of error is generated
	//Arrays to store the (n+1) x and y data-points of size n+1
	double x[Max_Trend_data] = { 0 };
	double y[Max_Trend_data] = { 0 };
	//	x_pol[Max_Trend_data][Max_Trend_data] = {};


	Global_get_data_listview(Trend_data_grid_index, Trend_data.valid_entries, Trend_data.number_collums, Trend_data.collumn_with, true);
	int maximum = Trend_data.valid_entries;
	if (maximum > Max_Trend_data)
	{
		maximum = Max_Trend_data;
	}

	double ats_y = 0;
	double scaling = 200;


	for (int i = 0; i <= (maximum - step); i += step)
	{
		ats_y = 0;
		for (int j = 0; j < step; j++)
		{
			ats_y += wstring_to_double(Trend_data.data[i + j].PV);
		}
		ats_y = ats_y / step;
		for (int j = 0; j < step; j++)
		{
			x[i + j] = i + j + 1;
			y[i + j] = ats_y/ scaling;
		}
	}

	for (int i = 0; i <= (maximum); i ++)
	{
		x_pol[i] = 0;
	}

	Show_progress(str.Progress.trend_polynom.s[lang], maximum);
/*
	x[0] = 1;
	x[1] = 2;
	x[2] = 3;
	x[3] = 4;

	y[0] = 1;
	y[1] = 4;
	y[2] = 5;
	y[3] = 13;

	step = 1;

	maximum = 3;
*/
	Li_poly(maximum, x, y, step);


	double tmp = 0;
	for (int i = 0; i <= maximum; i += step)
	{
		ats_y = 0;
		for (int j = 0; j <= maximum; j ++)
		{
			if (x_pol[j] != 0)
			{
				tmp = pow(x[i], double(j));
				ats_y += tmp * x_pol[j];
			}
		}
		Trend_data.data[i].Out_pol = double_to_wstring(ats_y* scaling);
		set_progress_value(i);
	}

	ats_y = 0;
	for (int i = 0; i <= maximum; i+= step)
	{
		ats_y = Pn(n, x, y, i, step);
		Trend_data.data[i].PV_pol = double_to_wstring(ats_y * scaling);
		set_progress_value(i);
	}
	
	
	Hide_progress();
	
	Global_put_data_listview(Trend_data_grid_index, Trend_data.valid_entries, Trend_data.number_collums, Trend_data.column_name_EN, Trend_data.column_name_LT, Trend_data.collumn_with);

	int b = 0;
}


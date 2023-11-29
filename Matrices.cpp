#include "Matrices.h"

//using namespace Matrices;
namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		this->a.resize(_rows, vector<double>(_cols, 0));
		rows = _rows;
		cols = _cols;
	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getCols() != b.getCols() || a.getRows() != b.getRows())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		else 
		{

			int mSize = a.getRows();
			int colSize = a.getCols();
			Matrix result(mSize, colSize);
			//for (int k = 0; k < mSize; k++)
			//{
			for (int i = 0; i < mSize; i++)
			{
				for (int j = 0; j < colSize; j++)
				{
					result(i, j) = a(i, j) + b(i, j);
					//cout << result(i, k);
				}
			}
			//cout << endl;
		//}

			return result;
		}
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		if (a.getCols() != b.getRows())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		Matrix c(a.getRows(), b.getCols());
		for (int k = 0; k < b.getCols(); k++)
		{
			for (int i = 0; i < a.getRows(); i++)
			{
				double sum = 0;
				for (int j = 0; j < a.getCols(); j++)
				{
					sum += a(i, j) * b(j, k);
				}
				c(i, k) = sum;
			}
		}
		return c;
	}
	
	bool operator==(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || b.getCols() != a.getCols())
			return false;
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				if (abs(a(i, j) - b(i, j)) < 0.001)
					return true;
			}
		}
		return false;
	}
	
	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return (!(a == b));
	}

	ostream& operator<<(ostream& os, const Matrix& a) 
	{
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				os << setw(12) << right << a(i, j)
					;
			}
			cout << endl;
		}
		return os;
	}
	
}
// << fixed << setprecision(6) << << setw(6)
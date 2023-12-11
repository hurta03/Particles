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
	
	RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
	{
		//RotationMatrix M();
		//RotationMatrix M(2, 2);
		a.at(0).at(0) = cos(theta); a.at(0).at(1) = -sin(theta);
		a.at(1).at(0) = sin(theta); a.at(1).at(1) = cos(theta);
		//*this = M;
	}

	ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
	{
		a.at(0).at(0) = scale; a.at(0).at(1) = 0;
		a.at(1).at(0) = 0; a.at(1).at(1) = scale;
	}

	TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
	{
		//2xn matrix, where n is the total number of stored points
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				a.at(i).at(j) = (i == 0 ? xShift : yShift);
			}
		}
	}

}

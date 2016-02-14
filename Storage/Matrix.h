#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

class Vector : public vector<double>
{
public:
	Vector(int n = 0){ (*this).resize(n); }
	Vector(int n, istream& f) //¬вод передаем им€ файла, формат n v(0)...v(n) - размерность, далее элементы
	{
		(*this).resize(n);
		for (int i = 0; i < n; i++)
		{
			f >> (*this)[i];
		}
		//if (!f)throw exception("End of file read");
	}
	double operator*(const Vector &vec)const
	{
		double sum = 0;
		for (unsigned int i = 0; i < size(); i++)sum += (*this)[i] * vec[i];
		return sum;
	}
	void operator*=(double n){ for (auto& i : (*this))i *= n; }
	void operator+=(const Vector &vec){ for (unsigned int i = 0; i < size(); i++)(*this)[i] += vec[i]; }
	void operator-=(const Vector &vec){ for (unsigned int i = 0; i < size(); i++)(*this)[i] -= vec[i]; }
	Vector operator-(Vector &vec)const
	{
		Vector result;
		result.resize(vec.size());
		for (unsigned int i = 0; i < size(); i++)result[i] = (*this)[i] - vec[i];
		return result;
	}
	Vector operator+(Vector &vec)const
	{
		Vector result;
		result.resize(vec.size());
		for (unsigned int i = 0; i < size(); i++)result[i] = (*this)[i] + vec[i];
		return result;
	}
	Vector operator*(double n)const
	{
		Vector result;
		result.resize((*this).size());
		for (unsigned int i = 0; i < size(); i++)result[i] = (*this)[i] * n;
		return result;
	}

	inline friend static ostream& operator << (ostream& out, Vector& v)
	{
		for (auto i : v)out << i << " ";
		out << endl;
		return out;
	}
};

class Matrix
{

};

class ColumnFormat :public Matrix
{
	public:

		void MultTransMatrixVector(const Vector& vec, Vector& res) const override
	{
		res.resize(Size());
		for (auto& r : res)r = 0;

		Run([&](int j, int i, double d)
		{
			res[i] += vec[j] * d;
		});
	}

	void MultMatrixVector(const Vector& vec, Vector& res) const
	{
		res.resize(Size());
		for (auto& r : res)r = 0;

		Run([&](int j, int i, double d)
		{
			res[j] += vec[i] * d;
		});
	}

	void multLowTriagnle(bool withDiag, const Vector& vec, Vector& res) const override
	{
		res.resize(Size());
		for (auto& r : res)r = 0;

		Run([&](int i, int j, double d)
		{
			if (i == j && withDiag) res[i] += vec[i] * d;
			else
			{
				if (i>j)
					res[i] += vec[j] * d;
			}
		});
	}

	void multUpperTriagnle(bool withDiag, const Vector& vec, Vector& res) const override
	{
		res.resize(Size());
		for (auto& r : res)r = 0;

		Run([&](int i, int j, double d)
		{
			if (i == j && withDiag) res[i] += vec[i] * d;
			else
			{
				if (i<j)
					res[i] += vec[j] * d;
			}
		});
	}

	void SetElement(int i, int j, double d)
	{
		supermatrix[j][i] = d;
	}

	void multUInvToVector(bool withDiag, const Vector& in, Vector& out) const override // (U [+D])^-1^ * vector
	{
		out.resize(Size());
		vector<double> temp;
		temp.resize(Size());

		for (int i = Size() - 1; i >= 0; i--)
		{
			out[i] = in[i] - temp[i];
			if (withDiag) out[i] /= supermatrix[i][i];

			for (const auto& pair : supermatrix[i])
			{
				if (pair.first < i)
				{
					temp[pair.first] += out[i] * pair.second;
				}
			}
		}
	}

	void multLInvToVector(bool withDiag, const Vector& in, Vector& out) const override // (L [+D])^-1^ * vector
	{
		out.resize(Size());
		vector<double> temp;
		temp.resize(Size());

		for (int i = 0; i < Size(); i++)
		{
			out[i] = in[i] - temp[i];
			if (withDiag) out[i] /= supermatrix[i][i];

			for (const auto& pair : supermatrix[i])
			{
				if (pair.first > i)
				{
					temp[pair.first] += out[i] * pair.second;
				}
			}
		}
	}

	void getDiag(Vector& vec) const override
	{
		vec.resize(Size());
		for (unsigned int i = 0; i < supermatrix.size(); i++)
		{
			auto &temp = supermatrix[i].find(i);
			if (temp != supermatrix[i].end())
				vec[i] = temp->second;
			else vec[i] = 0;
		}
	}

	int Size() const override
	{
		return supermatrix.size();
	}

};
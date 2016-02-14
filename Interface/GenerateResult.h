#include "../Storage/MATRIX.h"



class MatrixTest : public Matrix {

public:
	//Нужен специальный класс для инпута
	/*static shared_ptr<MatrixTest> CreateInstance(shared_ptr<InputClass> matr) {
		return 0;
	}*/
	void Run(function<void(int, int, double)>)const {
		return;
	}
	void MultMatrixVector(const Vector& vec, Vector& res)const  //Матрица на вектор
	{
		return;
	}
	void MultTransMatrixVector(const Vector& vec, Vector& res)const   //Транспонированная матрица на вектор
	{
		return;
	}
	void multUpperTriagnle(bool withDiag, const Vector& vec, Vector& res)const  //Верхний треугольник на вектор
	{
		return;
	}
	void multLowTriagnle(bool withDiag, const Vector& vec, Vector& res)const  //Нижний треугольник на вектор
	{
		return;
	}

	void multLInvToVector(bool withDiag, const Vector& in, Vector& out)const     // (L [+D])^-1^ * vector
	{
		return;
	}
	void getDiag(Vector& vec)const{
		return;
	}
	int Size()const{
		return 0;
	}

};
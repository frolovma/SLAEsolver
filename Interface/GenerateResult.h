#include "../Storage/MATRIX.h"



class MatrixTest : public Matrix {

public:
	//����� ����������� ����� ��� ������
	/*static shared_ptr<MatrixTest> CreateInstance(shared_ptr<InputClass> matr) {
		return 0;
	}*/
	void Run(function<void(int, int, double)>)const {
		return;
	}
	void MultMatrixVector(const Vector& vec, Vector& res)const  //������� �� ������
	{
		return;
	}
	void MultTransMatrixVector(const Vector& vec, Vector& res)const   //����������������� ������� �� ������
	{
		return;
	}
	void multUpperTriagnle(bool withDiag, const Vector& vec, Vector& res)const  //������� ����������� �� ������
	{
		return;
	}
	void multLowTriagnle(bool withDiag, const Vector& vec, Vector& res)const  //������ ����������� �� ������
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
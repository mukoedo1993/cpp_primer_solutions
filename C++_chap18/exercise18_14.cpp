#include<iostream>
#include<vector>
#include<functional>
class matrix{
    public:
    matrix(){std::cout<<"::matrix::matrix()\n";}
};
namespace mathLib{
    namespace MatrixLib{
        class matrix{/*...*/};
         matrix operator*
         (const matrix&,const matrix&);
    }
}
mathLib::MatrixLib::matrix mathLib::MatrixLib::operator* 
(const matrix&, const matrix&);

mathLib::MatrixLib::matrix 
mathLib::MatrixLib::operator* 
(const matrix&, const matrix&)//Its okay because this operator could see the matrix
{
    std::cout<<"MatrixLib::operator*\n";
    return mathLib::MatrixLib::matrix();
}
mathLib::MatrixLib::matrix 
operator* 
(const matrix&, const mathLib::MatrixLib::matrix&)//Its okay because this operator could see the matrix
{
    std::cout<<"global operator*\n";
    return mathLib::MatrixLib::matrix();
}

int main()
{
    std::function
    <mathLib::MatrixLib::matrix(mathLib::MatrixLib::matrix,mathLib::MatrixLib::matrix )>fcn
    =  mathLib::MatrixLib::operator*;
    mathLib::MatrixLib::matrix mtr1,mtr2;
    mathLib::MatrixLib::operator*(mtr1,mtr2);
    fcn(mtr1,mtr2);
    matrix mtr3;
    mtr3*mtr2;
}

/*
MatrixLib::operator*
MatrixLib::operator*
::matrix::matrix()
global operator*
*/
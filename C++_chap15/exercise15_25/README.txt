Q1: Why did we define a default constructor for Disc_quote?
soln1:If not, Bulk_quote::Bulk_quote() will be defined as deleted.
code:
https://github.com/mukoedo1993/All_files/blob/master/C%2B%2B_chap15/exercise15_25/exercise15_25Q1.cpp
error:
https://github.com/mukoedo1993/All_files/blob/master/C%2B%2B_chap15/exercise15_25/Screenshot%20from%202020-10-09%2020-16-06.png


Q2: What effect, if any, would removing that constructor have on the behavior of Bulk_quote?
soln2:
1: If the base class has an inaccessible or deleted destructor, then the synthezied default and copy constructors in the derived classes are defined as
deleted, because there is no way to destroy the base part of the derived object.
2: If the base class's default constructor is deleted or inaccessible, then the corresponding member in the derived class is defined as deleted.
As soon as a construtor that takes several parameters (non-copy constructor)is defined, we need to explicitly declare its existence.(=default)


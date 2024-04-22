clc
%X is a vector of differentiable funcs
%A is the situation matix
global t;
function solution = solve_situation(A,X)
numOfRows = size(A,1);
numOfColoms = size(1,A);
if(numOfColoms == numOfRows && numOfRows == size(X)) %checking if A is a square matrix and if x is viable
    [Vec,Val] = eig(A);
    inv_Vec = inv(Vec);
    temp = Vec*exp(Val.*t)*inv_Vec;
    solution = temp*X;
else % if the matrix is not a square or X isnt viable returns zero
    solution = 0;
end
end

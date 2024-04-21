clc
%X is a vector of differentiable funcs
%A is the situation matix
function solution = solve_situation(A,X)
numOfRows = size(A,1);
numOfColoms = size(1,A);
if(numOfColoms == numOfRows && numOfRows == size(X)) %checking if A is a square matrix
    I = eye(numOfRows)*a;
    B = A-I;
    C = cgs(det(B),0,1e-6);
    solution = 1;
else % if the matrix is not a square returns zero
    solution = 0;
end
end

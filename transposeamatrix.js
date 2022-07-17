//! Leetcode 867. Transpose Matrix

// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

let matrix = [[1,2,3],[4,5,6]]
const transpose = arr => {
    for (let i = 0; i < arr.length; i++) {
       for (let j = 0; j < i; j++) {
          const tmp = arr[i][j];
          arr[i][j] = arr[j][i];
          arr[j][i] = tmp;
       };
    }
 }
 transpose(matrix);
 console.log(matrix);

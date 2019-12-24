void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int R = 1;
    int C = 1;
    int rowSize = A.size();
    if(rowSize == 0)return;

    int colSize = A[0].size();
    if(colSize == 0)return;
    
    
    //setting R,C values to identify if the top row will be whole 0 or top column will be whole 0
    for(int i=0; i<colSize; i++){
        if(A[0][i] == 0){R = 0; break;}
    }
    for(int i=0; i<rowSize; i++){
        if(A[i][0] == 0){C = 0; break;}
    }
    
    //Setting the information about rows in the first column
    for(int i=0; i<rowSize; i++){
        for(int k=0; k<colSize; k++){
            if(A[i][k] == 0){A[i][0] = 0; break;}
        }
    }
    
    //Setting the information about columns in the first row
    for(int i=0; i<colSize; i++){
        for(int k=0; k<rowSize; k++){
            if(A[k][i] == 0){A[0][i] = 0; break;}
        }
    }

    //Actually going through all the cells, and checking its corresponding
    //cell at the top or the very left, and then deciding its value
    for(int i=1; i<rowSize; i++){
        for(int j=1; j<colSize; j++){
            if(A[0][j] == 0 or A[i][0] == 0)A[i][j] = 0;
        }
    }

    //setting the 0,0 element and the top row and leftmost column
    if(R==0 or C==0)A[0][0] = 0;
    else A[0][0] = 1;
    
    if(R==0){
        for(int i=1; i<colSize; i++)A[0][i] = 0;
    }
    if(C==0){
        for(int i=1; i<rowSize; i++)A[i][0] = 0;
    }

}

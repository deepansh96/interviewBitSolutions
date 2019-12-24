struct eleCount{
    int element;
    int count;
};
int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int k = 3;
    vector<pair<int,int>> vec(k-1);
    for(int i=0; i<vec.size(); i++)vec[i].second = 0;

    for(int i=0; i<A.size(); i++){
        //if present in tetris block or not
        int k;
        for(k=0; k<vec.size(); k++)
            if(vec[k].first == A[i]){vec[k].second++; break;}
        
        //if not present and space present
        if(k == vec.size()){
            for(k=0; k<vec.size(); k++){
                if(vec[k].second == 0){
                    vec[k].first = A[i];
                    vec[k].second++;
                    break;
                }
            }

            if(k == vec.size())
                for(int l=0; l<vec.size(); l++)vec[l].second--;
        }
        
        
        //cout<<"vec0 - element-"<<vec[0].first<<" -count-"<<vec[0].second;
        //cout<<"vec1 - element-"<<vec[1].first<<" -count-"<<vec[1].second<<endl;
    }

    for(int i=0; i<vec.size(); i++)
        if(vec[i].second >= (A.size()/k))return vec[i].first;
    

    return -1;
}

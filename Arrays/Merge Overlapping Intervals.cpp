/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//compare function - to be used while sorting the vector of Intervals
bool cmp(const Interval &a,const Interval &b){
    if(a.start <= b.start)return true;
    return false;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // 
    //int n = A.size();
    vector<Interval> result;
    if(A.size() == 0 or A.size() == 1)return A;
    
    sort(A.begin(),A.end(), cmp);
    
    for(int i=0; i<A.size()-1; i++){
        	
        	//if two intervals overlap(assuming they are sorted), they will satisfy the below condition
            if(max(A[i].start, A[i+1].start) <= min(A[i].end, A[i+1].end)){
                int mn = min(A[i].start, A[i+1].start);
                int mx = max(A[i].end, A[i+1].end);
                A[i+1].start = mn; 	//
                A[i+1].end = mx;	//setting merged interval values into the i+1 th interval  
                if(i == A.size()-2) result.push_back(A[i+1]); //adding the i+1 th interval to result only when i == A.size()-2 
                											  //as the loop only goes till A.size()-2
            }
            else {
                result.push_back(A[i]);
                if(i == A.size()-2) result.push_back(A[i+1]);
            }    
    }
    
    return result;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = intervals.size();
    bool overLapFound = false;
    int rightOfInd = -1;

    vector<Interval> result;
    if(n==0){
    	result.push_back(newInterval);
    	return result;
    }
    int overLapStartInd = INT_MAX;
    int overLapEndInd = INT_MIN;

    for(int i=0; i<n; i++){
        if(overLapFound==false and (intervals[i].end < newInterval.start))rightOfInd = i;

        if(max(intervals[i].start, newInterval.start) <= min(intervals[i].end, newInterval.end)){
            //overlapping
            overLapStartInd = min(overLapStartInd, i);
            overLapEndInd = max(overLapEndInd, i);
            overLapFound = true;
        }
    }

    if(overLapFound){

        for(int i=0; i<overLapStartInd; i++)
            result.push_back(intervals[i]);
        
        newInterval.start = min(intervals[overLapStartInd].start, newInterval.start);
        newInterval.end = max(intervals[overLapEndInd].end, newInterval.end);
        result.push_back(newInterval);

        for(int i=overLapEndInd+1; i<n; i++)
            result.push_back(intervals[i]);

        return result;
        
    }
    else{    
        if(rightOfInd == -1){
            if(newInterval.end < intervals[0].start) result.push_back(newInterval);
            else if(newInterval.end == intervals[0].start) intervals[0].start = newInterval.start;

            for(int i=0; i<n; i++) result.push_back(intervals[i]);
        }
        else{
            for(int i=0; i<=rightOfInd; i++) result.push_back(intervals[i]);
            result.push_back(newInterval);
            for(int i=rightOfInd+1; i<n; i++) result.push_back(intervals[i]);
        }

        return result;
    }
}

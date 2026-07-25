class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int largRec = 0;
        stack<int> st;
        vector<int>r(n);
        vector<int>l(n);

        for(int i = n - 1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            r[i]= st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            l[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }
        

        for(int i = 0; i<n;i++){
            int area = heights[i]*(r[i]-l[i]-1);
            largRec = max(largRec,area);
        }

        return largRec;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<int> row (n,0);
        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '0'){
                    row[j] = 0;
                }else{
                    row[j]++;
                }
            }

            ans = max(ans,largestRectangleArea(row));
        }

        return ans;
    }
};
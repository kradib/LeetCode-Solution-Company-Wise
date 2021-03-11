//957. Prison Cells After N Days
//https://leetcode.com/problems/prison-cells-after-n-days/
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        if(n==0)
            return cells;
        string cell="";
        int temp=n;
        for(auto i:cells)
            if(i==1)
                cell+=string(1,'1');
            else
                cell+=string(1,'0');
        
        //cout<<cell<<endl;
        vector<string> myset;
        
        string cur="0";
        for(int i=1;i<7;i++)
            if(cells[i-1]==cells[i+1])
                    cur+="1";
                else
                    cur+="0";
        cur+="0";
        //cout<<cur<<endl;
        myset.push_back(cur);
        cell=cur;
        n--;
        while(n--){
            cur="0";
            for(int i=1;i<7;i++){
                if(cell[i-1]==cell[i+1])
                    cur+="1";
                else
                    cur+="0";
            }
            cur+="0";
            if(find(myset.begin(),myset.end(),cur)!=myset.end())
                break;
            else
                myset.push_back(cur);
            
            cell=cur;
        }
        if(n==0){
            vector<int> result(8);
            cout<<cur<<endl;
            for(int i=0;i<8;i++)
                result[i]=cur[i]-'0';
            return result;
        }
       
        else{
            //cout<<"hi\n";
            int index=(temp-1)%myset.size() ;
//             for(auto it=myset.begin();it!=myset.end();it++)
//                 cout<<*it<<endl;
            
            cur=myset[index];
            //cout<<cur<<endl;
            vector<int> result(8);
            for(int i=0;i<8;i++)
                result[i]=cur[i]-'0';
            return result;
        }
    }
};
#include<iostream>
#include<string>
#include<vector>
using std::string; using std::vector;
using std::cout; using std::endl;
class solution {
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        vector<int>num_char = {}; vector<char>sort_char = {};
        string new_s = {}, new_s1 = {};
        if (k > 0)
        {
            char strt = s[0]; int cnt = 0, cnt1=0,cnt2=0;
            for (int k1 = 0; k1 < s.size(); k1++)
            {
                if (s[k1] == strt)
                {
                    cnt++;
                }else
                {
                    num_char.push_back(cnt);
                    sort_char.push_back(s[k1]);
                    cnt = 1;
                } 
                
            }
            cnt1 = num_char[0];
            num_char.push_back(cnt); sort_char.push_back(s[s.size()-1]);
            for (int k2 = 0; k2 < num_char.size(); k2++)
            {
                if (num_char[k2] == 1)
                {
                    num_char.erase(num_char.begin() + k2-1);
                    sort_char.erase(sort_char.begin() + k2-1); break;
                }
                else if (num_char[k2] < cnt1)
                {
                    cnt1 = num_char[k2];
                    cnt2 = k2;
                }
                else;
            }
            if(num_char[cnt2]>1)
            num_char[cnt2] = cnt1 - 1;
            for (int k3 = 0; k3 < num_char.size(); k3++)
            {
                new_s1 = (num_char[k3], sort_char[k3]);
                new_s = new_s + new_s1;
                //if(num_char[k3]!=1)
                //new_s = new_s + std::to_string(num_char[k3]);
                cout << num_char[k3]<<"; "<<sort_char[k3] << endl;
            }
            cout << "!!" << endl << new_s << endl;
            return getLengthOfOptimalCompression(new_s, k-1);
        }
        else
        {
            return 2;
        }
    }
    
};
int main()
{
    string k1 = "aaabcccd";
    int k = 2, t;
    solution soln;
    t = soln.getLengthOfOptimalCompression(k1, k);
    std::cout << t << std::endl;

}
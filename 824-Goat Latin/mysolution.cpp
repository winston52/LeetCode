class Solution {
public:
    string toGoatLatin(string S) {
        
        string res,idx,tem1,tem2;
        
        for(int i=0;i<S.length();i++)
        {
            
            if(S[i]>='A'&&S[i]<='Z'||S[i]>='a'&&S[i]<='z')
            {
                tem1+=S[i];
            }
            
            else if(S[i]==' ')
            {
                idx+='a';
                
                if(tem1[0]=='a'||tem1[0]=='A'||tem1[0]=='e'||tem1[0]=='E'||tem1[0]=='i'||tem1[0]=='I'
                   ||tem1[0]=='o'||tem1[0]=='O'||tem1[0]=='u'||tem1[0]=='U')
                {
                    tem1+="ma";
                    res+=tem1;
                    res+=idx;
                    res+=' ';
                    tem1="";
                }
                
                else
                {
                    tem2=tem1.substr(1,tem1.length()-1);
                    tem2+=tem1[0];
                    tem2+="ma";
                    res+=tem2;
                    res+=idx;
                    res+=' ';
                    tem1="";
                    tem2="";
                }
                
            }
            
            if(i==S.length()-1)
            {
                idx+='a';
                if(tem1[0]=='a'||tem1[0]=='A'||tem1[0]=='e'||tem1[0]=='E'||tem1[0]=='i'||tem1[0]=='I'
                   ||tem1[0]=='o'||tem1[0]=='O'||tem1[0]=='u'||tem1[0]=='U')
                {
                    tem1+="ma";
                    res+=tem1;
                    res+=idx;
                }                
                else
                {
                    tem2=tem1.substr(1,tem1.length()-1);
                    tem2+=tem1[0];
                    tem2+="ma";
                    res+=tem2;
                    res+=idx;
                }
            }
            
        }        
        return res;        
    }
};
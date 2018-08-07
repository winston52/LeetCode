class Solution {
public:
    int judge(int k){
        int flag=0;
        if(k==1||k==8||k==10)
            return 0;
        while(k){
            if(k%10==3||k%10==4||k%10==7)
                return 0;
            if(k%10==2||k%10==5||k%10==6||k%10==9)
                flag = 1;
            k=k/10;
        }
        return flag;
    }
    
    int incrementIFNeeded(int i){
        int inc=1;
        while(i>=10){
            inc *=10;
            i=i/10;
        }
        if(i==3||i==4||i==7){
            return inc-1;
        }
        else
            return 0;
    }
    
    int rotatedDigits(int N) {
        int res=0;
        for(int i=1;i<=N;i++){
            if(judge(i))
                res++;
            i+=incrementIFNeeded(i);
        }
        return res;
    }
};
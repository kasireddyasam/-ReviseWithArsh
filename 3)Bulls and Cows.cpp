class Solution {
public:
        string getHint(string secret, string guess) {
        int B=0;
        int C=0;
        unordered_map<char,int>mp;
        for(int i=0;i<secret.size();i++)
        mp[secret[i]]++;

        /*for(auto it:mp)
        cout<<endl<<it.first<<" "<<it.second;
        cout<<endl<<" after changrs";*/

        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                mp[secret[i]]--;
                B++;
                if(mp[secret[i]]<0 && C>0)
                  C--;
            }
            
            else{
                if(mp[guess[i]]>0){
                   mp[guess[i]]--;
                   C++;
                }

            }
        }
        if(C<0)
        C=0;
       /* for(auto it:mp)
        cout<<endl<<it.first<<" "<<it.second;*/

        return  to_string(B)+"A"+to_string(C)+"B";
        
    }
};

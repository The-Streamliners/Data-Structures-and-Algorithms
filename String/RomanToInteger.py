def romanToInt(self, s: str) -> int:
        var={
                "I":1,
                "V":5,
                "X":10,
                "L":50,
                "C":100,
                "D":500,
                "M":1000
            }
        
        ans=0
        for i in range(0,len(s)-1):
            if(var[s[i]]<var[s[i+1]]):
                ans-=var[s[i]]
                
            else:
                ans+=var[s[i]]
        ans+=var[s[-1]]
        return ans
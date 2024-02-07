class Solution:
    def frequencySort(self, s: str) -> str:
        l=[]
        c=Counter(s)
        for k,v in c.items():
            l.append(k*v)
        l.sort(key=len)
        l=l[::-1]
        return "".join(l)
    
    
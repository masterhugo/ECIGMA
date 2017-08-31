class dforest(object):
    def __init__(self, cap=100):
        self.__parent=[i for i in range(cap)]
        self.__n=cap
        self.__rank=[0 for i in range(cap)]
        self.__size=cap
        self.__cont=[1 for i in range(cap)]
    def find(self,x):
        ans=self.__parent[x]
        if ans != x:
            ans=self.__parent[x]=self.find(ans)
        return ans
    def union(self,x,y):
        r1,r2=self.find(x),self.find(y)
        if r1!=r2:
            if self.__rank[r1]<self.__rank[r2]:
                self.__parent[r1]=r2
                self.__cont[r2]+=self.__cont[r1]
            else:
                self.__parent[r2]=r1
                self.__cont[r1]+=self.__cont[r2]
                if self.__rank[r1]==self.__rank[r2]:
                    self.__rank[r1]+=1
            self.__n-=1
    def cmp_cnt(self,x):
        return self.__cont[self.find(x)]
    def size(self):
        return self.__n
    def krank(self,i):
        ans = self.find(i)
        return self.__rank[ans]
    def __str__(self):
        cad = ""
        for i in range(self.__size):
            cad += str(i)+"->"+str(self.__parent[i])+"\n"
        return cad

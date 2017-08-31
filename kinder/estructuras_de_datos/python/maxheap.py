class maxheap(object):

    __a,__n=None,None 

    def __init__(self,tam=100):
        self.__a=[ None for i in range(tam) ]
        self.__n=0

    def capacity(self):
        return len(self.__a)

    def __len__(self):
        return self.__n

    def __str__(self):
        return str(self.__a[:self.__n])

    def __root(self,i):
        assert i>=0 and i<len(self)
        return i==0

    def __left(self,i):
        return (i<<1)+1

    def __right(self,i):
        return (i+1)<<1

    def __parent(self,i):
        assert i>0 and i<len(self.__a)
        return (i-1)>>1

    def get_max(self):
        assert self.__n>0
        return self.__a[0]
        
    def insert(self,x):
        assert self.__n<len(self.__a)
        self.__a[self.__n]=x
        self.__n += 1
        self.__heapifyup(self.__n-1)

    def __heapifyup(self,i):
        if i>0:
            p=self.__parent(i)
            if self.__a[p]<self.__a[i]:
                self.__a[p],self.__a[i]=self.__a[i],self.__a[p]
                self.__heapifyup(p)

    def remove_max(self):
        assert self.__n>0
        ans = self.__a[0]
        self.__a[0] = self.__a[self.__n-1]
        self.__n -= 1
        if self.__n>1:
            self.__heapifydown(0)
        return ans
    def __heapifydown(self,i):
        ileft,iright,ibest=self.__left(i),self.__right(i),i
        if ileft < self.__n:
            if self.__a[i]< self.__a[ileft]:
                ibest = ileft
            if iright < self.__n and self.__a[ibest] < self.__a[iright]:
                ibest = iright
            if ibest != i:
                self.__a[i],self.__a[ibest] = self.__a[ibest],self.__a[i]
                self.__heapifydown(ibest)
            

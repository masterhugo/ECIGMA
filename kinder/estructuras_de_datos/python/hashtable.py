import hashlib
class hashtable(object):
    def __init__(self,size=100):
        self.__size = size
        self.__a = [ [] for i in range(size)]
        self.__n = 0
        self.__P = 961748941
        self.__A = 492876863
        self.__B = 5273
    def __str__(self):
        return '\n'.join(['{0} : {1}'.format(i,str(self.__a[i])) for i in range(len(self.__a))])
    def put(self,key,value):
        pos = self.__pos(self.__hash(key))
        found,i=None,0
        while(found==None and i < len(self.__a[pos])):
            if self.__a[pos][i][0]==key:
                found= i
            i+= 1
        if found==None:
            self.__a[pos].append((key,value))
            self.__n+=1
            self.__enlarge()
        else:
            self.__a[pos][found] = (key,value)
    def __enlarge(self):
        n,N=self.__n,len(self.__a)
        if 4*n > 3*N:
            tmp = self.__a
            self.__a = [[] for i in range(N<<1)]
            for l in tmp:
                for k,v in l:
                    pos = self.__pos[self.__hash(k)]
                    self.__a[pos].append((k,v))
            
    def get(self,key):
        found,pos,i=None,self.__pos(self.__hash(key)),0
        while found==None and i<len(self.__a[pos]):
            if self.__a[pos][i][0]==key:
                found = i
            i+=1
        if found==None:
            raise Exception("Try Again")
        return self.__a[pos][found][1]
    def __contains__(self,key):
        found,pos,i=None,self.__pos(self.__hash(key)),0
        while found==None and i<len(self.__a[pos]):
            if self.__a[pos][i][0]==key:
                found = i
            i+=1
        return found!=None
    def max_collision(self):
        return max(len(i) for i in self.__a)
    def remove(self,key):
        assert self.__n > 0
        found, i,ans = None,0,None
        pos = self.__pos(self.__hash(key))
        while(found == None and i < len(self.__a[pos])):
            if self.__a[pos][i][0]==key:
                found=i
            i+=1
        if found != None:
            ans=self.__a[pos][found][1]
            self.__a[pos].pop(found)
            self.__n-=1
            self.__shrink()
        return ans
    def __shrink(self):
        n,N,size=self.__n,len(self.__a),self.__size
        if n*4 < N and N != size:
            tmp = self.__a
            self.__a = [[] for i in range(N>>1)]
            for l in tmp:
                for k,v in l:
                    pos = self.__pos[self.__hash(k)]
                    self.__a[pos].append((k,v))
    def __len__(self):
        return self.__n
    def __hash(self,key):
        return int(hashlib.md5(str(key).encode('utf-8')).hexdigest(),16)
    def __pos(self,hashkey):
        return ((hashkey*self.__A+self.__B) % self.__P) % len(self.__a)

class deque(object):
    __a, __n, __back, __front = None, None, None, None
    def __init__(self,tam=100):
        self.__a = [ None for i in range(tam) ]
        self.__n = 0
        self.__front = 0
        self.__back = 0
    def __len__(self):
        return self.__n
    def __str__(self):
        cad = "[ "
        x = self.__front
        ct = 0
        for ct in range(self.__n):
            cad = cad + str(self.__a[x]) + " "
            x += 1
            if x== len(self.__a):
                x = 0
        cad += "]"
        return cad
            
    def insert_front(self,x):
        assert self.__n < len(self.__a)
        self.__front -= 1
        if (self.__front < 0):
            self.__front += len(self.__a)
        self.__a[self.__front] = x
        self.__n += 1
    def insert_back(self,x):
        assert self.__n < len(self.__a)
        self.__a[self.__back] = x
        self.__back += 1
        self.__n += 1
        if (self.__back == len(self.__a)):
            self.__back -= len(self.__a)
    def remove_front(self):
        assert self.__n > 0
        ans = self.__a[self.__front]
        self.__a[self.__front] = None
        self.__front += 1
        if (self.__front == len(self.__a)):
            self.__front -= len(self.__a)
        self.__n -= 1
        return ans
    def remove_back(self):
        assert self.__n > 0
        self.__back -= 1
        if (self.__back < 0):
            self.__back += len(self.__a)
        ans = self.__a[self.__back]
        self.__a[self.__back] = None
        self.__n -= 1
        return ans
    def get_front(self):
        return self.__a[self.__front]
    def get_back(self):
        return self.__a[self.__back-1]
    

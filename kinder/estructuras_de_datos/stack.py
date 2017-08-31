class stack(object):

    __array,__N=None,None
    def __init__(self,tam = 100000):
        self.__array = [None for i in range(tam)]
	self.__N = 0
        
    def size(self):
        return self.__N
    
    def push(self, x):
	assert self.__N < len(self.__array)
        self.__array[self.__N] = x
	self.__N += 1
	
    def pop(self):
	assert self.__N > 0
        ans = self.__array[self.__N-1]
	self.__N -= 1
	return ans
    
    def top(self):
        return self.__array[self.__N - 1]
    
    def isEmpty(self):
        return self.__N == 0

    def show(self):
        return str(self.__array[:self.__N])
    

class node(object):
    def __init__(self,value=None,prev=None,nextt=None):
        self.value=value
        self.prev=prev
        self.next=nextt
class olist(object):
    def __init__(self):
        self.sentinal=node()
        self.n=0
        self.sentinal.prev=self.sentinal.next=self.sentinal
    def insert_front(self,x):
        new=node(x,self.sentinal,self.sentinal.next)
        self.sentinal.next=new
        new.next.prev=new
        self.n+=1
    def remove_front(self):
        ans=self.sentinal.next.value
        second=self.sentinal.next.next
        self.sentinal.next.next=self.sentinal.next.prev=None
        self.sentinal.next=second
        second.prev=self.sentinal
        self.n-=1
        return ans
    def front(self):
        return self.sentinal.next.value
    def back(self):
        return self.sentinal.prev.value
    def insert_back(self,x):
        new=node(x,self.sentinal.prev,self.sentinal)
        self.sentinal.prev=new
        new.prev.next=new
        self.n+=1
    def remove_back(self):
        ans=self.sentinal.prev.value
        second=self.sentinal.prev.prev
        self.sentinal.prev.next=self.sentinal.prev.prev=None
        self.sentinal.prev=second
        second.next=self.sentinal
        self.n-=1
        return ans

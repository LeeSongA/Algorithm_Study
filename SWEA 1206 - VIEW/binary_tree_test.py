class Node:
    def __init__(self,node):
        self.l=None
        self.r = None
        self.v = node
class Tree:
    def __init__(self):
        self.root = None
    def getroot(self):
        return self.root
    def add(self,val):
        if self.root == None:
            self.root = Node(val)
        else:
            self._add(val, self.root)
    def _add(self,val,node):
        if (val < node.v):
            if node.l == None:
                node.l = Node(val)
            else:
                self._add(val,node.l)
        elif (val > node.v):
            if node.r == None:
                node.r = Node(val)
            else:
                self._add(val,node.r)
    def printTree(self):
        if self.root == None:
            return None
        else:
            self._printTree(self.root)
    def _printTree(self,node):
        if node != None:
            self._printTree(node.l)
            print(node.v)
            self._printTree(node.r)
tree = Tree()
tree.add(3)
tree.add(4)
tree.add(0)
tree.add(8)
tree.add(2)
tree.printTree()

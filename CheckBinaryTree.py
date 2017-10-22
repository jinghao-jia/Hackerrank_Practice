""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

# Do an inorder traversal to see if the data is in ascent order

def checkBST(root):
    global data_list
    data_list = []
    if(root != None):
        inorder_traversal(root)

    if(len(data_list) != 0):
        previous = data_list[0]
        for i in range(1, len(data_list)):
            if previous >= data_list[i]:
                return False;
            previous = data_list[i];
    return True

def inorder_traversal(root):
    if(root.left != None):
        inorder_traversal(root.left)
    data_list.append(root.data)
    if(root.right != None):
        inorder_traversal(root.right)

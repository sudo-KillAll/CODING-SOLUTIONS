# Python program to find Largest Sum Contiguous 
# Subarray in a given range with updates 
from sys import maxsize 

INT_MIN = -maxsize 

# Structure to store 
# 4 values that are to be stored 
# in the nodes 
class node: 
	def __init__(self): 
		self.sum = 0
		self.prefixsum = 0
		self.suffixsum = 0
		self.maxsum = 0

# array to store the segment tree 
tree = [0] * (4 * 100) 
for i in range(4 * 100): 
	tree[i] = node() 

def build(arr: list, low: int, high: int, index: int): 
	global tree 

	# the leaf node 
	if low == high: 
		tree[index].sum = arr[low] 
		tree[index].prefixsum = arr[low] 
		tree[index].suffixsum = arr[low] 
		tree[index].maxsum = arr[low] 
	else: 
		mid = (low + high) >> 1

		# left subtree 
		build(arr, low, mid, 2 * index + 1) 

		# right subtree 
		build(arr, mid + 1, high, 2 * index + 2) 

		# parent node's sum is the summation 
		# of left and right child 
		tree[index].sum = tree[2 * index + 1].sum +tree[2 * index + 2].sum

		# parent node's prefix sum will be equivalent 
		# to maximum of left child's prefix sum or left 
		# child sum + right child prefix sum. 
		tree[index].prefixsum = max( 
			tree[2 * index + 1].prefixsum, 
			tree[2 * index + 1].sum + tree[2 * index + 2].prefixsum) 

		# parent node's suffix sum will be equal to right 
		# child suffix sum or right child sum + suffix 
		# sum of left child 
		tree[index].suffixsum = max( 
			tree[2 * index + 2].suffixsum, 
			tree[2 * index + 2].sum + tree[2 * index + 1].suffixsum) 

		# maxum will be the maximum of prefix, suffix of 
		# parent or maximum of left child or right child 
		# and summation of left child's suffix and right 
		# child's prefix. 
		tree[index].maxsum = max(tree[index].prefixsum, 
			max(tree[index].suffixsum, 
				max(tree[2 * index + 1].maxsum, 
					max(tree[2 * index + 2].maxsum, 
						tree[2 * index + 1].suffixsum +
						tree[2 * index + 2].prefixsum)))) 


# function to update the tree 
def update(arr: list, index: int, low: int, 
			high: int, idx: int, value: int): 
	global tree 

	# the node to be updated 
	if low == high: 
		tree[index].sum = value 
		tree[index].prefixsum = value 
		tree[index].suffixsum = value 
		tree[index].maxsum = value 
	else: 
		mid = (low + high) >> 1

		# if node to be updated is in left subtree 
		if idx <= mid: 
			update(arr, 2 * index + 1, 
					low, mid, idx, value) 

		# if node to be updated is in right subtree 
		else: 
			update(arr, 2 * index + 2, 
					mid + 1, high, idx, value) 

		# parent node's sum is the summation of left 
		# and right child 
		tree[index].sum = tree[2 * index + 1].sum +tree[2 * index + 2].sum

		# parent node's prefix sum will be equivalent 
		# to maximum of left child's prefix sum or left 
		# child sum + right child prefix sum. 
		tree[index].prefixsum = max(tree[2 * index + 1].prefixsum, 
			tree[2 * index + 1].sum + tree[2 * index + 2].prefixsum) 

		# parent node's suffix sum will be equal to right 
		# child suffix sum or right child sum + suffix 
		# sum of left child 
		tree[index].suffixsum = max(tree[2 * index + 2].suffixsum, 
			tree[2 * index + 2].sum + tree[2 * index + 1].suffixsum) 

		# maxum will be the maximum of prefix, suffix of 
		# parent or maximum of left child or right child 
		# and summation of left child's suffix and 
		# right child's prefix. 
		tree[index].maxsum = max(tree[index].prefixsum, 
			max(tree[index].suffixsum, 
				max(tree[2 * index + 1].maxsum, 
					max(tree[2 * index + 2].maxsum, 
						tree[2 * index + 1].suffixsum +
						tree[2 * index + 2].prefixsum)))) 

# function to return answer to every type-1 query 
def query(arr: list, index: int, low: int, 
		high: int, l: int, r: int) -> node: 

	# initially all the values are INT_MIN 
	result = node() 
	result.sum = result.prefixsum = result.suffixsum = result.maxsum = INT_MIN 

	# range does not lies in this subtree 
	if r < low or high < l: 
		return result 

	# complete overlap of range 
	if l <= low and high <= r: 
		return tree[index] 

	mid = (low + high) >> 1

	# right subtree 
	if l > mid: 
		return query(arr, 2 * index + 2, 
						mid + 1, high, l, r) 

	# left subtree 
	if r <= mid: 
		return query(arr, 2 * index + 1, low, mid, l, r) 

	left = query(arr, 2 * index + 1, low, mid, l, r) 
	right = query(arr, 2 * index + 2, mid + 1, high, l, r) 

	# finding the maximum and returning it 
	result.sum = left.sum + right.sum
	result.prefixsum = max(left.prefixsum, 
					left.sum + right.prefixsum) 

	result.suffixsum = max(right.suffixsum, 
						right.sum + left.suffixsum) 
	result.maxsum = max(result.prefixsum, 
		max(result.suffixsum, 
			max(left.maxsum, max(right.maxsum, 
			left.suffixsum + right.prefixsum)))) 

	return result 

# Driver Code 
if __name__ == "__main__": 
    for _ in range(int(input())):
        N=int(input())
        arr=[int(i) for i in input().split()]
        a=[]
        i,j=0,0
        while(i<N):
            cur=0
            if(arr[i]<0):
                while(j<N and arr[i]<0):
                    cur+=arr[j]
                    j+=1
            else:
                while(j<N and arr[i]>=0):
                    cur+=arr[j]
                    j+=1
            a.append(cur)
            i=j
        
        n = len(a) 

        # build the tree 
        build(a, 0, n - 1, 0) 

        # 1st query type-1 
        ans=-1000000000
        if(n==1):
            if(a[0]<0):
                print("0")
                continue
            else:
                print(sum(a)-min(a))
                continue
        
        for id in range(n):
            if(a[id]<0):
                tmp = a[id]
                update(a,0,0,n-1,id,0)
                ans = max(ans,query(a,0,0,n-1,0,n-1).maxsum)
                update(a,0,0,n-1,id,tmp)
        print(ans)
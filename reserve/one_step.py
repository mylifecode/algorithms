from functools import lru_cache

@lru_cache(maxsize=None) 
def fn(n):
	if n==1:
		return 1
	elif n==2:
		return 2
	else:
		return fn(n-1)+fn(n-2)


def main():
	result=fn(40)
	print('reslut:',result)

if __name__=='__main__':
	main()

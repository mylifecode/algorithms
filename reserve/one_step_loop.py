def fn(n):
    if n==1:
    	return 1
    elif n==2:
    	return 2
    	
    else:
    	a,b=1,2
    	for i in range(3,n+1):
    		a,b=b,a+b  
    return	b

def main():
	result=fn(40)
	print('result:',result)

if __name__=='__main__':
	main()

def isPrime(n): 
  
    # Corner case 
    if n <= 1: 
        return False
  
    # Check from 2 to n-1 
    for i in range(2, n): 
        if n % i == 0: 
            return False; 
  
    return True
  
i = isPrime(479001599)
if(i):
    print("true") 
else:
    print("false")
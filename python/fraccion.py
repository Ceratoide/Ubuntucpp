
def fm(n):
    k=(10**(len(str(n))-2))
    a=[]

    if 0<n<1:
        for i in range (1,int(n*k/2)):
            for j in range (i+1,int(k)):
                if i/j==n:
                   return i,j
        return n*k, k 

    else:
         return 'El numero no esta en el rango indicado.'
               
 
n=float(input("digite un numero: "))    
print('La fracción irreducible del decimal se muestra a continuación, en el orden, numerador y denominador, respectivamente')
print(fm(n))



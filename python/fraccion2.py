def funfracirr():
  

  n=input()
  a= float (n)

#Condición rango 
  if (a>=0.0001) and (a<=0.9999):
    l=(len(n))

#Condición número de cifras
    if (l<=6):
       d=10**(len(n))
       b=a*d
       print(b)
       i=b/2
       while (i>1):
         g=b%i
         u=d%i

         while (g==0) and (u==0):
           
           b=b/i
           d=d/i
           
         i=i-1
       
       

       print(b)
       print(d)

         
    else:
       print("El número no tiene el número de 
def funfracirr():
  

  n=input()
  a= float (n)

#Condición rango 
  if (a>=0.0001) and (a<=0.9999):
    l=(len(n))

#Condición número de cifras
    if (l<=6):
       d=10**(len(n))
       b=a*d
       print(b)
       i=b/2
       while (i>1):
         g=b%i
         u=d%i

         while (g==0) and (u==0):
           
           b=b/i
           d=d/i
           
         i=i-1
       
       

       print(b)
       print(d)

         
    else:
       print("El número no tiene el número de decimales")

#recibimos una lista
#ordenar
#sacar las frecuencias
#quitar los repetidos

b=[1,3,2,3,3,2,3,4,2,3,2,3,3,3,1,1,2]

def frecuencias(a):
    frec=[]
    a.sort()
    numeros=set(a)
    
    contador=0;
    for jj in numeros:
        for ii in a:
            if ii==jj:
                contador+=1
        frec.append(contador)
        contador=0;
    return list(numeros),frec

print(frecuencias(b))
            
        



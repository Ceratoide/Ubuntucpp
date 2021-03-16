def primo(n):
    for ii in range(2,int(n/2)+1):
        if n/ii == int(n/ii):
            return False
    return True

for jj in range(1,50):
    print(jj," ", primo(jj))

devices=["R1","R2","R3","S1","S2","S3"]
switches=[]

for i in devices :
    if "S" in i:
        switches.append(i)
print(switches)
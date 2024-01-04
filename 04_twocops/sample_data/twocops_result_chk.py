import subprocess

for i in range(1,7):
    file=open(".\\sample_data\\0"+str(i)+".inp", "r")
    mkchk=file.readlines()
    file.close()
    chk=str()
    for j in mkchk:
        chk+=j
    result=subprocess.Popen(['.\\twocops.exe'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, encoding='utf-8', text=True)
    result_chk=list(result.communicate(input=chk, timeout=3))
    file=open(".\\sample_data\\0"+str(i)+".out", "r")
    mkout=file.readlines()
    out=str()
    for j in mkout:
        out+=j
    out+="\n"
    # print(result_chk[0])
    # print(out)
    print(result_chk[0].split("\n")==out.split("\n")) 
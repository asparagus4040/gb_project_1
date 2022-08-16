import os

def main():
    os.remove("gen/genheader.h")
    h_list = []
    dir_list = os.listdir("gen")
    for i in range(len(dir_list)):
        file = dir_list[i]
        if file[len(file)-1] == "h":
            h_list.append(file)
    f = open("gen/genheader.h", "w")
    f.write("#ifndef GENHEADER_H_\n")
    f.write("#define GENHEADER_H_\n")
    f.write("\n")
    for i in range(len(h_list)):
        print("adding " + h_list[i] + " to genheader.h")
        f.write("#include \"")
        f.write(h_list[i])
        f.write("\"\n")
    f.write("#endif")

main()

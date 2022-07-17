import os

def main():
    os.remove("gen/KingHeader.h")
    h_list = []
    dir_list = os.listdir("gen")
    for i in range(len(dir_list)):
        file = dir_list[i]
        if file[len(file)-1] == "h":
            h_list.append(file)
    f = open("gen/KingHeader.h", "w")
    f.write("#ifndef KINGHEADER_H_\n")
    f.write("#define KINGHEADER_H_\n")
    f.write("\n")
    for i in range(len(h_list)):
        print(h_list[i])
        f.write("#include \"")
        f.write(h_list[i])
        f.write("\"\n")
    f.write("#endif")

main()

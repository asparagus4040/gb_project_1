import os

def main():
    png_list = []
    c_list = []
    dir_list = os.listdir("png")
    for i in range(len(dir_list)):
        subdir_str = "png/" + dir_list[i]
        subdir = os.listdir(subdir_str)
        for j in range(len(subdir)):
            png_list.append(subdir_str + "/" + subdir[j])
            c_list.append(subdir[j])
    for i in range(len(png_list)):
        cfile = c_list[i]
        cfile = cfile[:(len(cfile))-3]
        cfile = cfile + "c"
        command = "C:/gbdk/bin/png2asset " + png_list[i] + " -c gen/" + cfile + " -spr8x8 -noflip"
        print(command)
        os.system(command)

main()

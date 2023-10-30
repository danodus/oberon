import os
import sys

vertices = []
texcoords = []
colors = []
faces = []


def puts(s):
    print(s, end='')


def process_line(line):
    global vertices, texcoords, faces
    words = line.split()
    if len(words) < 1:
        return
    if words[0] == "v":
        vertices.append([float(words[1]), float(words[2]), float(words[3])])
        # vertex color hack
        if len(words) > 4:
            if len(words) > 7:
                alpha = float(words[7])
            else:
                alpha = 1.0
            colors.append(
                [float(words[4]), float(words[5]), float(words[6]), alpha])
    elif words[0] == "vt":
        texcoords.append([float(words[1]), float(words[2])])
    elif words[0] == "f":
        w1 = words[1].split('/')
        w2 = words[2].split('/')
        w3 = words[3].split('/')
        faces.append([int(w1[0]), int(w2[0]), int(w3[0]),
                     int(w1[1]), int(w2[1]), int(w3[1])])


def print_vertices(array):
    puts("vec3_t vertices[] = {\n")
    for i, v in enumerate(array):
        puts("{{.x={}, .y={}, .z={}}}".format(
            v[0], v[1], v[2]))
        if (i < len(array) - 1):
            puts(",")
        puts("\n")
    puts("};\n")


def print_texcoords(array):
    puts("vec2d texcoords[] = {\n")
    for i, v in enumerate(array):
        puts("{{FX({}f), FX({}f)}}".format(v[0], v[1]))
        if (i < len(array) - 1):
            puts(",")
        puts("\n")
    puts("};\n")


def print_colors(array):
    puts("vec3d colors[] = {\n")
    for i, v in enumerate(array):
        puts("{{FX({}f), FX({}f), FX({}f), FX({}})}}".format(
            v[0], v[1], v[2], v[3]))
        if (i < len(array) - 1):
            puts(",")
        puts("\n")
    puts("};\n")


def print_faces(array):
    puts("face_t faces[] = {\n")
    for i, v in enumerate(array):
        puts("{{.a={}, .b={}, .c={}}}".format(
            v[0], v[1], v[2]))
        if (i < len(array) - 1):
            puts(",")
        puts("\n")
    puts("};\n")


def print_all():
    puts("#define N_VERTICES (sizeof(vertices)/sizeof(vertices[0]))\n")
    puts("#define N_FACES (sizeof(faces)/sizeof(faces[0]))\n")
    print_vertices(vertices)
    #print_texcoords(texcoords)
    #if len(colors) > 0:
    #    print_colors(colors)
    print_faces(faces)


def main(argv):
    if (len(argv) == 0):
        print("Usage: obj2c.rb <objfile>")
        exit(0)
    else:
        if (not os.path.exists(argv[0])):
            print("{} does not exist".format(argv[0]))
            exit(-1)

        f = open(argv[0], 'r')
        lines = f.readlines()

        for line in lines:
            process_line(line)

        print_all()
    exit(0)


if __name__ == "__main__":
    main(sys.argv[1:])

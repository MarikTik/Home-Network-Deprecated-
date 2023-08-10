from os import path

Import("env")

configurations = list()

project_dir = env["PROJECT_DIR"]

with open(path.join(project_dir, ".env"), "r") as config:
    for line in config.readlines():  
        split = line.strip().split("=")
        if len(split) != 2:
            continue
        name = split[0]
        value = split[1]
        if (value.replace('.','',1).isdigit()):
            configurations.append((name, value))
        else:
            configurations.append((name, env.StringifyMacro(value)))

 
env.Append(CPPDEFINES=configurations)
 
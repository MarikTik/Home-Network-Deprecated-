from os import path
Import("env")


project_dir = env["PROJECT_DIR"]

with open(path.join(project_dir, '.env'), 'r') as from_file:
    with open(path.join(project_dir, 'public.env'), 'w') as to_file:
        for line in from_file.readlines():
            split = line.split('=')
            if len(split) == 2:
                to_file.write(split[0] + '=\n')

    
 
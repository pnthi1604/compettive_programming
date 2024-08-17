import random

def random_integer(l, r):
    return random.randint(l, r)
for i in range(0, 20):
    file_path = "/home/phamngocthi/cp/test/test/{0}.inp".format(i)
    a = random_integer(1, 100)
    b = random_integer(101, 200)
    with open(file_path, "w") as f:
        f.write(f"{a} {b}\n")        
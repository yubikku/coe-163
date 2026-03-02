import time
import random

def find_min_combi(num_dials, start_str, end_str):
    # Calculates minimum turns. 
    # Using strings directly to handle N up to 100 easily.
    total_turns = 0
    for i in range(num_dials):
        s_digit = int(start_str[i])
        e_digit = int(end_str[i])
        diff = abs(s_digit - e_digit)
        total_turns += min(diff, 10 - diff)
    return total_turns

def generate_test_case(n):
    #Generates two random strings of length n.
    start = "".join([str(random.randint(0, 9)) for _ in range(n)])
    end = "".join([str(random.randint(0, 9)) for _ in range(n)])
    return start, end

if __name__ == "__main__":
    # Test cases for N = 10, 20, 30, ..., 100
    n_values = range(10, 101, 10)
    iterations = 1000

    print(f"{'N':<5} | {'Avg Time (s)':<15} | {'Min Time (s)':<15} | {'Max Time (s)':<15}")
    print("-" * 60)

    for n in n_values:
        start_val, end_val = generate_test_case(n)
        runtimes = []
        
        # Requirement: Loop at least 1000 times
        for _ in range(iterations):
            t0 = time.perf_counter()
            find_min_combi(n, start_val, end_val)
            t1 = time.perf_counter()
            runtimes.append(t1 - t0)
        
        avg_run = sum(runtimes) / iterations
        max_run = max(runtimes)
        min_run = min(runtimes)
        
        print(f"{n:<5} | {avg_run:<15.8f} | {min_run:<15.8f} | {max_run:<15.8f}")


    n_values = range(10, 101, 10)
   iterations = 1000
...
   for n in n_values:
   	... 
       for _ in range(iterations):
           t0 = time.perf_counter()
           total_turns = 0
   		for i in range(n): #O(n)
       		s_digit = int(start_val[i]) # O(1)
       		e_digit = int(end_val[i]) # O(1)
       		diff = abs(s_digit - e_digit) # O(1)
       		total_turns += min(diff, 10 - diff) # O(1)
			print(total_turns) # O(1)
           t1 = time.perf_counter()
           runtimes.append(t1 - t0)
...

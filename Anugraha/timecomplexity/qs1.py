import random
import time
import matplotlib.pyplot as plt

# 1. Bubble Sort function
def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


# 2. Function to create an array of random numbers
def create_array(n):
    return [random.randint(1, 1000) for _ in range(n)]


# Lists to store input sizes and execution times
sizes = []
times = []

# 3. Run bubble sort for different input sizes
for n in range(1, 20000):
    arr = create_array(n)

    start_time = time.time()

    bubble_sort(arr)

    end_time = time.time()

    execution_time = end_time - start_time

    sizes.append(n)
    times.append(execution_time)


# 4. Plot the execution time
plt.plot(sizes, times)

plt.xlabel("Array Size (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Execution Time of Bubble Sort")
plt.grid(True)

plt.show()
import threading
import time

counter = 0

def worker():
    global counter

    for _ in range(10000):
        temp = counter          # Read shared variable
        time.sleep(0.00001)     # Force thread switching
        temp += 1               # Increment
        counter = temp          # Write back

threads = []

for i in range(3):
    t = threading.Thread(target=worker)
    threads.append(t)
    t.start()

for t in threads:
    t.join()

print("\nExpected Counter Value : 30000")
print("Actual Counter Value   :", counter)

if counter == 30000:
    print("No race condition occurred in this run.")
else:
    print("Race condition detected!")

import threading
import time

counter = 0
lock = threading.Lock()


def worker(name):
    global counter

    for i in range(5):
        with lock:
            counter += 1
            print(f"{name} increased counter to {counter}")

        time.sleep(1)


t1 = threading.Thread(target=worker, args=("Thread-1",))
t2 = threading.Thread(target=worker, args=("Thread-2",))
t3 = threading.Thread(target=worker, args=("Thread-3",))

t1.start()
t2.start()
t3.start()

t1.join()
t2.join()
t3.join()

print("\nAll threads finished.")
print("Final Counter:", counter)

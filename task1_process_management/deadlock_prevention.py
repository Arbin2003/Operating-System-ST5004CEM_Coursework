import threading
import time

# Create two shared locks
lock1 = threading.Lock()
lock2 = threading.Lock()


def worker1():
    print("Worker 1 is waiting for Lock 1")

    with lock1:
        print("Worker 1 acquired Lock 1")
        time.sleep(1)

        print("Worker 1 is waiting for Lock 2")

        with lock2:
            print("Worker 1 acquired Lock 2")
            print("Worker 1 completed its work")


def worker2():
    print("Worker 2 is waiting for Lock 1")

    # Notice: Worker 2 also acquires Lock 1 first.
    # Using the same lock order prevents deadlocks.
    with lock1:
        print("Worker 2 acquired Lock 1")
        time.sleep(1)

        print("Worker 2 is waiting for Lock 2")

        with lock2:
            print("Worker 2 acquired Lock 2")
            print("Worker 2 completed its work")


t1 = threading.Thread(target=worker1)
t2 = threading.Thread(target=worker2)

t1.start()
t2.start()

t1.join()
t2.join()

print("\nProgram finished successfully.")
print("Deadlock was prevented by acquiring locks in the same order.")

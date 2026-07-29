from worker import Worker
from shared_resource import SharedCounter
from scheduler import round_robin


def main():
    # Create one shared counter
    shared_counter = SharedCounter()

    # Create three worker threads
    worker1 = Worker("Worker-1", shared_counter)
    worker2 = Worker("Worker-2", shared_counter)
    worker3 = Worker("Worker-3", shared_counter)

    # Start the threads
    worker1.start()
    worker2.start()
    worker3.start()

    # Wait for all threads to finish
    worker1.join()
    worker2.join()
    worker3.join()

    print("\nAll threads have finished.")
    print(f"Final Counter Value: {shared_counter.get_value()}")

    # Round Robin Scheduler
    processes = ["Process-1", "Process-2", "Process-3"]
    round_robin(processes, 3)


if __name__ == "__main__":
    main()

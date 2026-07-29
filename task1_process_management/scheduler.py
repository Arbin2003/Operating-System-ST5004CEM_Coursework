import time


def round_robin(processes, rounds):
    print("\n========== Round Robin Scheduler ==========\n")

    for round_no in range(rounds):
        print(f"Round {round_no + 1}")

        for process in processes:
            print(f"Running {process}")
            time.sleep(1)

        print()

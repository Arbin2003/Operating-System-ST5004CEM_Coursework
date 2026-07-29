import threading
import time


class Worker(threading.Thread):
    def __init__(self, name, shared_counter):
        super().__init__()
        self.name = name
        self.shared_counter = shared_counter

    def run(self):
        for i in range(5):
            print(f"{self.name} is running...")
            self.shared_counter.increment(self.name)
            time.sleep(1)

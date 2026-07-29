import threading


class SharedCounter:
    def __init__(self):
        self.value = 0
        self.lock = threading.Lock()

    def increment(self, worker_name):
        with self.lock:
            self.value += 1
            print(f"{worker_name} incremented counter -> {self.value}")

    def get_value(self):
        return self.value

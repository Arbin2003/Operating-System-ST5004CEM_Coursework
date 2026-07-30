from datetime import datetime


def log_action(action):
    with open("audit_log.txt", "a") as log:
        time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log.write(f"[{time}] {action}\n")

import os
from logger import log_action


def create_file(filename):
    with open(filename, "w") as file:
        file.write("")
    print(f"\nFile '{filename}' created successfully.")
    log_action(f"Created file: {filename}")


def write_file(filename):
    if os.path.exists(filename):
        text = input("Enter text to write: ")
        with open(filename, "a") as file:
            file.write(text + "\n")
        print("Data written successfully.")
        log_action(f"Wrote to file: {filename}")
    else:
        print("File does not exist.")


def read_file(filename):
    if os.path.exists(filename):
        with open(filename, "r") as file:
            print("\n----- File Content -----")
            print(file.read())
        log_action(f"Read file: {filename}")
    else:
        print("File does not exist.")


def delete_file(filename):
    if os.path.exists(filename):
        os.remove(filename)
        print(f"File '{filename}' deleted.")
        log_action(f"Deleted file: {filename}")
    else:
        print("File does not exist.")


def make_read_only(filename):
    if os.path.exists(filename):
        os.chmod(filename, 0o444)
        print(f"'{filename}' is now read-only.")
        log_action(f"Changed to read-only: {filename}")
    else:
        print("File does not exist.")


def make_read_write(filename):
    if os.path.exists(filename):
        os.chmod(filename, 0o666)
        print(f"'{filename}' is now read/write.")
        log_action(f"Changed to read/write: {filename}")
    else:
        print("File does not exist.")

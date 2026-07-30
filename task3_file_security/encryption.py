import base64
from logger import log_action


def encrypt_file(filename):
    try:
        with open(filename, "rb") as file:
            data = file.read()

        encrypted = base64.b64encode(data)

        with open(filename, "wb") as file:
            file.write(encrypted)

        print("File encrypted successfully.")
        log_action(f"Encrypted file: {filename}")

    except FileNotFoundError:
        print("File not found.")


def decrypt_file(filename):
    try:
        with open(filename, "rb") as file:
            data = file.read()

        decrypted = base64.b64decode(data)

        with open(filename, "wb") as file:
            file.write(decrypted)

        print("File decrypted successfully.")
        log_action(f"Decrypted file: {filename}")

    except FileNotFoundError:
        print("File not found.")

    except Exception:
        print("Unable to decrypt file.")

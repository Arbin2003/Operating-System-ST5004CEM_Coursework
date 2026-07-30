import socket

HOST = "127.0.0.1"
PORT = 5000


def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        client.connect((HOST, PORT))

        print("=" * 50)
        print("Connected to TCP Server")
        print("=" * 50)

        # Login
        username = input("Username: ")
        password = input("Password: ")

        login_message = f"LOGIN {username} {password}"
        client.send(login_message.encode())

        response = client.recv(1024).decode()

        if response != "LOGIN_SUCCESS":
            print("Login failed!")
            client.close()
            return

        print("\nLogin successful!")
        print("Type messages to send to the server.")
        print("Type EXIT to disconnect.\n")

        while True:
            message = input("You: ").strip()

            if message == "":
                print("Message cannot be empty.")
                continue

            client.send(message.encode())

            reply = client.recv(1024).decode()
            print("Server:", reply)

            if message.upper() == "EXIT":
                break

    except ConnectionRefusedError:
        print("Unable to connect to the server.")

    except Exception as e:
        print("Error:", e)

    finally:
        client.close()
        print("Connection closed.")


if __name__ == "__main__":
    main()
